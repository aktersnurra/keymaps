# Charybdis Nano

## Compiling

Follow the steps in this [tutorial](https://docs.bastardkb.com/fw/compile-firmware.html#compiling-your-firmware-using-the-local-command-line)

## Flashing

1. Trigger boot mode
2. Mount the controller
3. Copy over the new keymap to the controller:

```sh
doas cp bastardkb_charybdis_3x5_v2_aktersnurra.uf2 /mnt/usb
```

(If there is some issue flash the sides individually)
