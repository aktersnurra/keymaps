# Charybdis Nano

## Requirements

The basterdkb qmk [fork](https://github.com/Bastardkb/bastardkb-qmk) and this repo 
linked inside the keymap folder of the nano.

## Flashing

To flash the splinky:

1. Disconnect the keyboard
2. Reconnect one side
3. Trigger boot mode
4. Mount the controller
5. Compile the keymap with:
```sh
qmk compile -c -kb bastardkb/charybdis/3x5/v2/splinky_3 -km aktersnurra
```
6. Copy over the new keymap to the controller:
```sh
doas cp bastardkb_charybdis_3x5_v2_splinky_3_aktersnurra.uf2 /mnt/usb
```
7. Repeat the step for the other side.
