# Dilemma

Keymap for the Bastard KB Dilemma (3x5_3 with a Cirque touchpad on the right
half). Layers and home-row mod behaviour are described in the
[main README](../../README.md).

## Board-specific settings

- **Touchpad:** default DPI starts at 256 (step 32). Sniping turns on while the
  Nav layer is held. Circular scrolling is enabled: trace a circle along the
  edge of the pad to scroll.
- **Thumbs:** three keys on each side. The third right thumb key is Gui.
- **RGB:** toggle and cycle effects from the Fun layer.
- **Encoders (if fitted):** the board's defaults apply: scroll on the left,
  volume on the right.

## Building

```sh
qmk compile -kb bastardkb/dilemma/3x5_3 -km aktersnurra
```

This writes `bastardkb_dilemma_3x5_3_aktersnurra.uf2` to `qmk_userspace/`. See
the [main README](../../README.md#building) for the one-time setup.

## Flashing

Flash both halves: connect each half by USB in turn and repeat these steps.

1. Enter the bootloader: press **Boot** on the Fun layer (hold Tab, then
   Space, then press Q), or double-tap the reset button.
2. Mount the controller, which shows up as a USB drive named `RPI-RP2`.
3. Copy the firmware over:

   ```sh
   doas cp bastardkb_dilemma_3x5_3_aktersnurra.uf2 /mnt/usb
   ```

The half reboots by itself once the copy finishes.
