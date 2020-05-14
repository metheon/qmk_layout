# Metheon's layout

## Used in the following keyboards

* Planck EZ
* Ergodox EZ
* Kyria

## Description

My layout is a simple one, with five layers; base, lower, raise, adjust and extend. Despite using different keyboards my layout is based around a Planck 48 key layout with two additional encoders. I create everything here, in the users folder and simply parse the layout to the specific keymap using a keyboard adapter (which is simply a define, with some keys set and others not, depending on the actual keyboard).

Order matters when making a layout such as this. The two `rules.mk` files are the first to be loaded, first that in the keymap folder, if it exists, then that in the user folder. After that the keyboard specific keymap is loaded. The first part of this file is the define which defines the layout adapter. After that the user file `metheon.c` is loaded which then utilizes this layout adapter. This makes it very easy to adapt to new keyboards as long as they support 48 keys or more. Actually, 47 keys as I have written my layout such that in case of a 2U spacebar on a Planck (like on the Planck EZ) the lower function of space is simply enter which would have been two separate keys on a 48 key Planck.

## Base layer

The layout is based off a Planck.

* Space: Space on tap, Extend layer on hold.
* Enter: Enter on tap, Extend layout on hold.
* Ctrl is ctrl on tap, ctrl+shift on double tap.
* Currently the two left bottom row keys are not in use.

```
.-----------------------------------------------------------------------------------.
| Tab  | Q    | W    | F    | P    | G    | J    | L    | U    | Y    | ;    | Bksp |
|------+------+------+------+------+------+------+------+------+------+------+------|
| Esc  | A    | R    | S    | T    | D    | H    | N    | E    | I    | O    | '    |
|------+------+------+------+------+------+------+------+------+------+------+------|
| Shft | Z    | X    | C    | V    | B    | K    | M    | ,    | .    | /    | Shft |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      | Alt  | Ctrl | Lwr  |Space |Enter | Rse  | Ctrl | Gui  | Dyn1 | Dyn2 |
'-----------------------------------------------------------------------------------'
```

## Lower

* Enter: Just regular old enter. The presence on lower means that the only difference between split space/enter and 2U space is having to press lower with your left thumb. Right thumb is always enter.

```
.-----------------------------------------------------------------------------------.
| ~    | !    | @    | #    | $    | %    | ^    | &    | *    | (    | )    | Del  |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      | F1   | F2   | F3   | F4   | F5   | F6   | _    | +    | {    | }    | |    |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      | F7   | F8   | F9   | F10  | F11  | F12  |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      | Lwr  |Enter |Enter | Rse  |      |      |      |      |
'-----------------------------------------------------------------------------------'
```

## Raise

* Space: Regular space. Not actually useful but kept here to match the location of enter.

```
.-----------------------------------------------------------------------------------.
| `    | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    | 0    | Del  |
|------+------+------+------+------+------+------+------+------+------+------+------|
| Caps | É    | Æ    | Ø    | Å    | £    | €    | -    | =    | [    | ]    | \    |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      | Undo | Cut  | Copy | Pste | Redo |      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      | Lwr  |Space |Space | Rse  |      |      |      |      |
'-----------------------------------------------------------------------------------'
```

## Adjust

Rather empty right now, but there is some media keys, reset and OS toggle.

```
.-----------------------------------------------------------------------------------.
|      |      |      |      |      |      |      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|Hibrnt|RgbVai|RgbSai|RgbHui|RgbMod|RgbTog|      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|Sleep |RgbVad|RgbSad|RgbHud|RgbRmd|      |      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      | Lwr  |Reset |Reset | Rse  |      |      |      | TgOS |
'-----------------------------------------------------------------------------------'
```

## Move

```
.-----------------------------------------------------------------------------------.
|      |      |      |      |      |      | PgUp | Home | Up   | End  |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      | Shft | Ctrl | Gui  | Alt  | PgDn | Left | Down | Rght |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      |      |      |      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      |      |   SpaceFn   |      |      |      |      |      |
'-----------------------------------------------------------------------------------'
```

## Numpad

* Base: Toggles back to base layer

```
.-----------------------------------------------------------------------------------.
|      |      | #    | (    | )    |      |      | 7    | 8    | 9    |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      | /    | *    | -    | +    |      |      | 4    | 5    | 6    |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      |      |      |      | 1    | 2    | 3    |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
| Base |      |      |      | =    |    Enter    | 0    | ,    | .    |      |      |
'-----------------------------------------------------------------------------------'
```

## Todo

* Consider removing support for MacOS, not a primary OS anymore.
* Consider moving the arrow cluster into base layer, lower right corner.
* 
