# Metheon's layout

## Used in the following keyboards

* Planck EZ
* Ergodox EZ
* Kyria

## Description

My layout is a simple one, with five layers; base, lower, raise, adjust and extend. Despite using different keyboards my layout is based around a Planck 48 key layout with two additional encoders. I create everything here, in the users folder and simply parse the layout to the specific keymap using a keyboard adapter (which is simply a define, with some keys set and others not, depending on the actual keyboard).

Order matters when making a layout such as this. The two `rules.mk` files are the first to be loaded, first that in the keymap folder, if it exists, then that in the user folder. After that the keyboard specific keymap is loaded. The first part of this file is the define which defines the layout adapter. After that the user file `metheon.c` is loaded which then utilizes this layout adapter. This makes it very easy to adapt to new keyboards as long as they support 48 keys or more. Actually, 47 keys as I have written my layout such that in case of a 2U spacebar on a Planck (like on the Planck EZ) the lower function of space is simply enter which would have been two separate keys on a 48 key Planck.

## Base layer

The layout is based off a Planck plus two encoders.

* Space: Space on tap, `Extend` layer on hold.
* Enter: Enter on tap, `Extend` layout on hold.
* Ctrl is ctrl on tap, ctrl+shift on double tap.
* Alt is alt on tap, `Numpad` on double tap (toggle).
* Gui is gui on tap, `Funpad` on double tap (toggle).
* Dyn1/2: Dynamic macro play 1/2.
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

* Enter: Just regular old enter. The presence on `Lower` means that the only difference between split space/enter and 2U space is having to press `Lower` with your left thumb. Right thumb is always enter.

```
.-----------------------------------------------------------------------------------.
| ~    | !    | @    | #    | $    | %    | ^    | &    | *    | (    | )    | Del  |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      | F1   | F2   | F3   | F4   | F5   | F6   | _    | +    | {    | }    |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      | F7   | F8   | F9   | F10  | F11  | F12  |      |      |      | |    |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      | Lwr  |Enter |Enter | Rse  |      |      |      |      |
'-----------------------------------------------------------------------------------'
```

## Raise

* Space: Regular space. Not actually useful but kept here to match the location of enter.
* É, Æ, Ø, Å, £, €: These all require [EurKey](https://eurkey.steffen.bruentjen.eu/)installed and set as current language.

```
.-----------------------------------------------------------------------------------.
| `    | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    | 0    | Del  |
|------+------+------+------+------+------+------+------+------+------+------+------|
| Caps | É    | Æ    | Ø    | Å    | £    | €    | -    | =    | [    | ]    |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      | Undo | Cut  | Copy | Pste | Redo |      |      |      |      | \    |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      | Lwr  |Space |Space | Rse  |      |      |      |      |
'-----------------------------------------------------------------------------------'
```

## Adjust

* Lots of standard RGB functions
* Hibrnt: Hibernates the computer
* Sleep: Sleeps the computer
* BL3: Toggles on the `Borderlands 3 - Base` layer

```
.-----------------------------------------------------------------------------------.
|      |      |      |      |      |      |      |      |      |      |      |Reset |
|------+------+------+------+------+------+------+------+------+------+------+------|
|Hibrnt|RgbVai|RgbSai|RgbHui|RgbMod|RgbTog|      | BL3  |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|Sleep |RgbVad|RgbSad|RgbHud|RgbRmd|      |      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      | Lwr  |Reset |Reset | Rse  |      |      |      |      |
'-----------------------------------------------------------------------------------'
```

## Extend

* Spaces: Show Windows Desktops
* L_Mon/R_Mon: Move window to left/right monitor
* L_Spc/R_Spc: Move window to left/right space/desktop
* DelWrd: Delete last word (ctrl+backspace)
* W_Menu: Show the windows menu
* Dsktop: Show the windows desktop
* L_Algn/R_Algn: Align window to the left/right of the desktop (half of screen)
* Maxim: Maximize the window
* VidOff/MicOff: Shortcuts for turning video and microphone on and off in MS Teams
* Lock: Lock the PC

```
.-----------------------------------------------------------------------------------.
|Spaces|L_Mon |R_Mon |L_Spc |R_Spc |      | PgUp | Home | Up   | End  |      |DelWrd|
|------+------+------+------+------+------+------+------+------+------+------+------|
|W_Menu| LGui | LAlt | LSft | LCtl |Dsktop| PgDn | Left | DOWN | Rght |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
I LSft |L_Algn|R_Algn|Maxim |VidOff|      |Files |MicOff|      |      |      | RSft |
|------+------+------+------+------+------+------+------+------+------+------+------|
| Lock |Dm_Stp| Mprv | Mply | Mnxt |      |      | Volu | Vold | Mute |Dm_Rc1|Dm_Rc2|
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

## Borderlands 3 - Base

* Base: Toggles back to `Base`.
* W: Shifted W for running
* Space: Hold to activate `Borderlands 3 - Upper`.

```
.-----------------------------------------------------------------------------------.
|      | Tab  | Q    | W    | E    | R    |      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      | Esc  | A    | S    | D    | F    |      | Base |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      | LSft | Z    | X    | C    |      |      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      | G    | V    | Spc  | Spc  |      |      |      |      |      |
'-----------------------------------------------------------------------------------'
```

## Borderlands 3 - Upper

* Base: Toggles back to `Base` layer
* W: Shifted W for running

```
.-----------------------------------------------------------------------------------.
|      | Tab  | 1    | W    | 2    | 3    |      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      | Esc  | A    | S    | D    | 4    |      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      | LSft | M    | I    | L    | K    |      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      | [    | ]    | Spc  | Spc  |      |      |      |      |      |
'-----------------------------------------------------------------------------------'
```
