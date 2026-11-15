# Keymaps

My Colemak Mod-DH QMK keymaps for two 34/36-key split boards from Bastard KB:

- [Charybdis Nano](aktersnurra/charybdis) (3x5, trackball)
- [Dilemma](aktersnurra/dilemma) (3x5_3, touchpad)

Both share the same layers. The [Ferris Sweep](aktersnurra/ferris) keymap is
retired and no longer maintained.

## Layers

`·` is transparent. Home-row keys are modifiers when held, letters when tapped.

### Base (Colemak Mod-DH)

```
 Q    W    F    P    B          J    L    U    Y    ;
 A    R    S    T    G          M    N    E    I    O
 Z    X    C    D    V          K    H    ,    .    /
          Ent  Spc  Esc        Bspc Tab  Gui¹
```

| Hold      | Left | Right |
|-----------|------|-------|
| Gui       | A    | O     |
| Alt       | R    | I     |
| Ctrl      | S    | E     |
| Shift     | T    | N     |

Thumbs: hold Space for **Nav**, Backspace for **Sym**, Tab for **Num**.
¹ Dilemma only (third right thumb key).

### Sym (hold Backspace)

```
 ·    !    %    $    &          @    *    ^    ·    ·
 `    #    (    )²   -          =    [²   ]    '    |
 ·    ·    ·    ·    ·          ·    ·    ·    ·    \
           ·   Spc   ·          ·    ·
```

² `)` and `[` act as Shift when held, so `{`, `}` and other shifted symbols
stay on this layer.

### Nav (hold Space)

```
 ·    ·   WhDn WhUp  ·          ·    ·    ·    ·    ·
 ·    ·   Btn1 Btn2  ·          ←    ↓    ↑    →    ·
 ·    ·    ·    ·    ·          ·    ·    ·    ·    ·
           ·    ·    ·         Bspc  ·
```

The pointer switches to sniping (slow, precise) while Nav is held.

### Num (hold Tab)

```
 ·    4    5    6    ·          ·    ·    ·    ·    ·
 ·    1    2    3    0          ·    7    8    9    ·
 ·    ·    ·    ·    ·          ·    ·    ·    ·    ·
         Media  Fun  ·          ·    ·
```

### Media (Num + Enter thumb)

```
 ·    ·    ·    ·    ·          ·    ·    ·    ·    ·
 ·   Prev Play Next  ·          ·   Vol- Vol+ Mute  ·
 ·    ·    ·    ·    ·          ·    ·    ·    ·    ·
```

### Fun (Num + Space thumb)

```
 ·    ·   Rgb³ Rgb³ Rgb³        ·   Boot  ·    ·   EeClr
 ·    ·    ·  CtlAlt ·          ·    F1   F2   F3   ·
 ·    ·   TT-  TT+  TT?         ·    ·    ·    ·    ·
```

- **Boot** reboots into the bootloader, **EeClr** clears the EEPROM.
- **TT-/TT+/TT?** lower, raise and type the tapping term (see below).
- ³ Dilemma only: RGB toggle, previous effect, next effect.

## Home-row mods

Tuned to avoid accidental modifiers while typing:

- **Chordal Hold:** a home-row key is only a modifier when the next key is on
  the other hand. Thumb layer keys are exempt.
- **Flow Tap (150 ms):** while typing quickly, home-row keys always tap. Shift
  is exempt so capitals mid-sentence still work.
- **Permissive Hold:** a deliberate mod+key press registers without waiting.
- **Tapping term:** 250 ms for home-row keys, 180 ms for thumb keys.

### Tuning the tapping term

`TT-` and `TT+` change the home-row term by 5 ms, and `TT?` types the current
value. Changes are lost on unplug. Once you settle on a value, set
`TAPPING_TERM` in each board's `config.h`.

## Building

The keymaps build against the [Bastard KB QMK fork](https://github.com/Bastardkb/bastardkb-qmk)
on the `bkb-master` branch, with [Bastard KB's userspace](https://github.com/Bastardkb/qmk_userspace)
as the overlay. Stay on `bkb-master`: `main` removes the Dilemma's sniping and
DPI code.

One-time setup, from the directory that holds the three repositories:

```sh
git clone -b bkb-master https://github.com/Bastardkb/bastardkb-qmk
git clone https://github.com/Bastardkb/qmk_userspace
uv tool install qmk   # or: doas pacman -S qmk
qmk config user.qmk_home=$PWD/bastardkb-qmk user.overlay_dir=$PWD/qmk_userspace
(cd bastardkb-qmk && qmk git-submodule)

ln -s $PWD/keymaps/aktersnurra/charybdis \
  qmk_userspace/keyboards/bastardkb/charybdis/3x5/keymaps/aktersnurra
ln -s $PWD/keymaps/aktersnurra/dilemma \
  qmk_userspace/keyboards/bastardkb/dilemma/3x5_3/keymaps/aktersnurra
```

Then build with:

```sh
qmk compile -kb bastardkb/charybdis/3x5 -km aktersnurra
qmk compile -kb bastardkb/dilemma/3x5_3 -km aktersnurra
```

The `.uf2` files land in `qmk_userspace/`. Don't use `qmk userspace-compile`:
it builds the `vendor` keymaps listed in `qmk_userspace/qmk.json`, not these.

See each board's README for flashing.

## Layout of this repository

```
aktersnurra/
├── charybdis/   keymap.c, config.h, rules.mk
├── dilemma/     keymap.c, config.h, rules.mk
├── ferris/      retired
└── sftrp.c      tap dance for ")" / Shift, shared by all keymaps
```
