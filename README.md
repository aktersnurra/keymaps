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
 `    #    (    )    -          =    [    ]    '    |
 ~    ·    <    >    _          +    {    }    "    \
           ·   Spc   ·          ·    ·
```

Shifted symbols sit on the bottom row, mostly right below their unshifted
pair (`` ` `` → `~`, `-` → `_`, `=` → `+`, `[` → `{`, `'` → `"`).

### Nav (hold Space)

```
 ·    ·   WhDn WhUp  ·         Home PgDn PgUp End   ·
 ·   Btn3 Btn2 Btn1  ·          ←    ↓    ↑    →    ·
 ·    ·    ·   Drg⁴  ·          ·    ·    ·    ·    ·
           ·    ·    ·         Bspc Del
```

- The pointer switches to sniping (slow, precise) while Nav is held.
- Btn1/Btn2/Btn3 are left, right and middle click.
- ⁴ Charybdis only: hold to scroll with the trackball.

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
 Boot   ·    Rgb³  Rgb³  Rgb³       ·     F4    F5    F6    F7
  ·     ·     ·    CtAl   ·        F12    F1    F2    F3    F11
 EeClr  ·    TT-   TT+   TT?        ·     F8    F9    F10   ·
```

- **Boot** reboots into the bootloader, **EeClr** clears the EEPROM.
- The most used F-keys are on the home row: F1–F3 (with **CtAl** for
  Ctrl+Alt+F1–F3), F11 and F12.
- **TT-/TT+/TT?** lower, raise and type the tapping term (see below).
- ³ Dilemma only: RGB toggle, previous effect, next effect.

## Home-row mods

Tuned to avoid accidental modifiers while typing:

- **Chordal Hold:** a home-row key is only a modifier when the next key is on
  the other hand. Thumb keys count as either hand, so Gui+Enter or Ctrl+Esc
  work from the left hand too.
- **Flow Tap (150 ms):** while typing quickly, home-row keys always tap. Shift
  is exempt so capitals mid-sentence still work.
- **Permissive Hold:** a deliberate mod+key press registers without waiting.
- **Tapping term:** 250 ms for home-row keys, 180 ms for thumb keys.
- **Caps Word:** hold both Shift keys (T and N) to type in capitals until the
  end of the word.

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
└── sftrp.c      ")" / Shift tap dance, used only by the Ferris keymap
```
