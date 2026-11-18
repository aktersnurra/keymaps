#!/bin/sh
# Build and flash both halves of a board, one half at a time.
#
# Usage: ./flash.sh charybdis|dilemma
#
# On Linux, enter your doas password when asked, while the keyboard still works.
# macOS needs no password. The script then waits for each half to show up in
# bootloader mode and flashes it, so no typing is needed once a half is in the
# bootloader.
set -eu

case "${1:-}" in
charybdis) kb=bastardkb/charybdis/3x5 sided=yes ;;
dilemma) kb=bastardkb/dilemma/3x5_3 sided=no ;;
*)
	echo "usage: $0 charybdis|dilemma" >&2
	exit 1
	;;
esac

userspace=$(qmk config -ro user.overlay_dir | sed 's/^[^=]*=//; s/ (.*)$//')
firmware="$userspace/$(echo "$kb" | tr / _)_aktersnurra.uf2"
out=$(mktemp -d)
trap 'rm -rf "$out"' EXIT

# Build quietly; show the output only if the build fails.
build() {
	qmk compile -kb "$kb" -km aktersnurra "$@" >"$out/build.log" 2>&1 || {
		cat "$out/build.log" >&2
		exit 1
	}
}

# The Charybdis stores which side each half is in its EEPROM. Building each
# half with its side baked in rewrites that on every boot, so the layout never
# flips, whichever half the USB cable is in, even after an EEPROM clear.
# The Dilemma reads its side from a pin, so one build serves both halves.
for side in right left; do
	if [ "$sided" = yes ]; then
		hand=$(echo "$side" | tr a-z A-Z)
		echo "Building the $side half..."
		build -c -e "EXTRAFLAGS=-DINIT_EE_HANDS_$hand"
	elif [ ! -f "$out/left.uf2" ] && [ ! -f "$out/right.uf2" ]; then
		echo "Building..."
		build
	fi
	cp "$firmware" "$out/$side.uf2"
done

case "$(uname -s)" in
Darwin)
	# macOS mounts the bootloader drive itself, so no root is needed.
	mnt=/Volumes/RPI-RP2

	for side in right left; do
		echo
		echo "Plug the USB cable into the $side half, then put it in bootloader mode:"
		echo "press Boot (hold Tab, then Space, then press Q) or double-tap reset."
		until [ -d "$mnt" ]; do sleep 0.2; done
		sleep 1
		cp "$out/$side.uf2" "$mnt"
		sync
		while [ -d "$mnt" ]; do sleep 0.2; done
		echo "Flashed the $side half."
	done
	;;
*)
	doas sh -s "$out" <<'EOF'
set -eu
dir=$1
dev=/dev/disk/by-label/RPI-RP2
mnt=/mnt/usb

if mountpoint -q "$mnt"; then
	echo "$mnt is already in use" >&2
	exit 1
fi

for side in right left; do
	echo
	echo "Plug the USB cable into the $side half, then put it in bootloader mode:"
	echo "press Boot (hold Tab, then Space, then press Q) or double-tap reset."
	until [ -e "$dev" ]; do sleep 0.2; done
	sleep 1
	mount "$dev" "$mnt"
	cp "$dir/$side.uf2" "$mnt"
	sync
	umount -l "$mnt"
	while [ -e "$dev" ]; do sleep 0.2; done
	echo "Flashed the $side half."
done
EOF
	;;
esac
