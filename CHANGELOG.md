# Changelog

## 2026-11-18

Charybdis Nano and Dilemma:

- Mouse layer turns on by itself when the pointer moves and repeats Nav's
  mouse keys (plus Scroll on G, Charybdis); any other key types and turns it
  off, 800 ms timeout.
- Sniping no longer turns on with Nav; hold **Snipe** (Nav, left pinky).

## 2026-11-16

Charybdis Nano and Dilemma:

- Home-row mods tuned against misfires: Chordal Hold (thumbs count as either
  hand), Flow Tap, Permissive Hold, per-key tapping term (250 ms home row,
  180 ms thumbs) and live tuning keys on Fun.
- Sniping while Nav is held now works.
- Sym: shifted symbols on the bottom row; `)` tap dance removed.
- Nav: Home/End/PgUp/PgDn, Del, mouse buttons on R/S/T, drag scroll
  (Charybdis), å/ä/ö via OS detection.
- Caps Word with both Shifts; F1–F12 on Fun with the most used on the home
  row; Boot and EeClr in the left corners.
- Dilemma: RGB matrix keycodes fixed; Repeat key on the outer right thumb.
- `flash.sh` builds and flashes both halves without a second keyboard; each
  Charybdis half is built with its side so the layout no longer flips.
- `draw.sh` generates the layer images with keymap-drawer; READMEs rewritten.
