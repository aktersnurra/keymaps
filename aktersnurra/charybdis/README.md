# Charybdis Nano

Keymap for the Bastard KB Charybdis Nano (3x5 with a trackball on the right
half). Layers and home-row mod behaviour are described in the
[main README](../../README.md).

## Board-specific settings

- **Trackball:** default DPI starts at 500 (step 200). Sniping DPI starts at
  100 (step 100) and turns on while the Nav layer is held. Hold **Drg** on Nav
  to scroll with the ball.
- **Thumbs:** three keys on the left, two on the right.

## Building

```sh
qmk compile -kb bastardkb/charybdis/3x5 -km aktersnurra
```

This writes `bastardkb_charybdis_3x5_aktersnurra.uf2` to `qmk_userspace/`. See
the [main README](../../README.md#building) for the one-time setup.

## Flashing

Flash both halves: connect each half by USB in turn and repeat these steps.

1. Enter the bootloader: press **Boot** on the Fun layer (hold Tab, then
   Space, then press Q), or double-tap the reset button.
2. Mount the controller, which shows up as a USB drive named `RPI-RP2`.
3. Copy the firmware over:

   ```sh
   doas cp bastardkb_charybdis_3x5_aktersnurra.uf2 /mnt/usb
   ```

The half reboots by itself once the copy finishes.
