# Ferris Sweep Keymap Configuration

My qmk keymap configuration for the Ferris Sweep keyboard.

# Usage

1. Clone the qmk firmware repository:

```
git clone git@github.com:qmk/qmk_firmware.git
```

2. Link this repository into the qmk ferris keyboards keymap configuration
directory:

```
cd keymaps
ln -sr aktersnurra ../qmk_firmware/keyboards/ferris/keymaps
```

3. Go to the `qmk_firmware` directory

4. Compile the keymap for each half by running these commands:

```
make ferris/sweep:aktersnurra:dfu-split-left
make ferris/sweep:aktersnurra:dfu-split-right
```

NB connect the each half with the usb cable by holding down the upper left
(right) key to start the microcontroller in boot mode.
