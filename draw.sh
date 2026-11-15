#!/bin/sh
# Draw the layer images in images/ from the keymaps, using keymap-drawer.
#
# Usage: ./draw.sh
#
# Rerun after changing a keymap and commit the updated images.
set -eu

repo=$(cd "$(dirname "$0")" && pwd)
config="$repo/keymap-drawer.yaml"
keymap="uvx --from keymap-drawer==0.21.0 keymap"
out=$(mktemp -d)
trap 'rm -rf "$out"' EXIT
mkdir -p "$repo/images"

draw() {
	board=$1 kb=$2
	echo "Drawing $board..."
	qmk c2json -kb "$kb" -km aktersnurra "$repo/aktersnurra/$board/keymap.c" \
		-o "$out/$board.json" >/dev/null 2>&1
	qmk info -kb "$kb" -f json >"$out/$board.info.json" 2>/dev/null

	# The export keeps layer references by name (LT(_NAV, ...)) and lists the
	# layers in source order; keymap-drawer needs layer numbers in that order.
	names=$(python3 - "$repo/aktersnurra/$board/keymap.c" "$out/$board.json" <<'EOF'
import json, re, sys
source, path = sys.argv[1], sys.argv[2]
order = re.findall(r"\[(_\w+)\]\s*=\s*LAYOUT", open(source).read())
keymap = json.load(open(path))
assert len(order) == len(keymap["layers"]), "layer count mismatch"
def number(key):
    return re.sub(r"\((_\w+)(?=[,)])", lambda m: f"({order.index(m[1])}", key)
keymap["layers"] = [[number(k) for k in layer] for layer in keymap["layers"]]
json.dump(keymap, open(path, "w"))
print(" ".join("Base" if n == "_COLEMAK_DH" else n[1:].title() for n in order))
EOF
)
	# shellcheck disable=SC2086 # layer names are single words
	$keymap -c "$config" parse -q "$out/$board.json" -c 10 -l $names \
		-o "$out/$board.yaml"
	sed -i 's/h: GUI}/h: Gui}/; s/h: ALT}/h: Alt}/; s/h: CTL}/h: Ctrl}/; s/h: R\{0,1\}SFT}/h: Shift}/' \
		"$out/$board.yaml"
	$keymap -c "$config" draw -j "$out/$board.info.json" "$out/$board.yaml" \
		-o "$repo/images/$board.svg"
}

draw charybdis bastardkb/charybdis/3x5
draw dilemma bastardkb/dilemma/3x5_3
echo "Wrote images/charybdis.svg and images/dilemma.svg"
