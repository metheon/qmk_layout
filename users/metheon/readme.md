# Metheon's layout

## Introduction

I am standing on the shoulders of giants with this keymap. My main inspiration is [*Drashna*](https://github.com/qmk/qmk_firmware/tree/master/users/drashna) and [*manna-harbour_miryoku*](https://github.com/qmk/qmk_firmware/tree/master/users/manna-harbour_miryoku).

My approach to keyboards and keymaps is to mentally settle on a form factor which simple, effective and intuitive. For me that is the basic Planck keyboard with its four rows by twelve columns. I then select keyboards which are physically able to map to this mental model. Right now I use these two; the [*Kyria*](https://blog.splitkb.com/blog/introducing-the-kyria) and the [*Planck EZ*](https://ergodox-ez.com/pages/planck). A Kyria is really just a reshuffled Planck with two additional encoders, and the Planck EZ is just a Planck with a 2U spacebar. I accomodate for the 2U spacebar by having the alternative functions mapped on my Lower and Raise layers.

For the actual keymap, I recommend reading through [`metheon.c`](metheon.c). For how that keymap is mapped to each read through [`keymap.c` of the Kyria](../../keyboards/kyria/keymaps/metheon/keymap.c) and [`keymap.c` of the Planck EZ](../../keyboards/planck/keymaps/metheon/keymap.c).
This approach ensures that it is quite easy to add support for a new keyboard aslong as it fits the mental model of a 48 key Planck. All you have to do is write an adapter. Note that the order of the `#define` and the `#include` in the keymaps matter. The layout to use must be defined as it is called from within the `metheon.c` file.

In the following I will dive into different aspects of my keymap.

## Tap Dance

I try to minimize same finger bigrams, as such I only have a few tap dances defined:

* Ctrl > Ctrl+Shift
* Alt > Win
* Win > Alt

Files:

* [`tap_dance.c`](tap_dance.c)
* [`tap_dance.h`](tap_dance.h)

## Leader

I use my leader key mainly to input relevant data that I otherwise find too cumbersome to input, this is stuff such as usernames and emails. To avoid having those details pushed to [GitHub](https://github.com/) I have a file called `secrets.h` which is never pushed to GitHub. To avoid having that file being pushed by accident I do two things:

* Add the file to `.gitignore`
* Add the file to `.git/info/exclude`

The `secrets.h` file simply contains the following content:

```c
static const char * const secrets[] = {
  "no secrets to be found",
  "no secrets to be found",
  // Add all your secrets here
};
```

This array is duplicated as a dummy array within the `leader.c` file, such that the keymap would still compile on another machine even without `secrets.h` present. The feature can also be turned off by compiling with: `make keyboard:name NO_SECRETS=yes`, which can be handy if I take my keyboard outside of my home.

## Encoders

The encoder logic is split in two parts. In the header file, [`encoders.h`](encoders.h), the _on tap_ function can be found while the rotary logic can be found in [`encoders.c`](encoders.c). The encoder functionality is disabled by default, but can be enabled for a keyboard if it has encoders, like I do in the [`rules.mk`](../../keyboards/kyria/keymaps/metheon/rules.mk) file of my Kyria. The only other thing to note for my encoders is that I feel that the alt-tab logic is improved compared to what I have found elsewhere.

## Process Records

TODO

# OLD README, will be removed

## Description

Despite using different keyboards my layout is based around a Planck 48 key layout with two additional encoders. I create everything here, in the users folder and simply parse the layout to the specific keymap using a keyboard adapter (which is simply a define, with some keys set and others not, depending on the actual keyboard).

Order matters when making a layout such as this. The two `rules.mk` files are the first to be loaded, first that in the keymap folder, if it exists, then that in the user folder. After that the keyboard specific keymap is loaded. The first part of this file is the define which defines the layout adapter. After that the user file `metheon.c` is loaded which then utilizes this layout adapter. This makes it very easy to adapt to new keyboards as long as they support 48 keys or more. Actually, 47 keys as I have written my layout such that in case of a 2U spacebar on a Planck (like on the Planck EZ) the lower function of space is simply enter which would have been two separate keys on a 48 key Planck.

For all layers it goes that:

* `xxxx`: KC_NO
* `____`: KC_TRNS

TODO: Improve description.

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
| xxxx | xxxx | Alt  | Ctrl | Lwr  |Space |Enter | Rse  | Ctrl | Gui  | Dyn1 | Dyn2 |
'-----------------------------------------------------------------------------------'
```

## Lower

* Enter: Just regular old enter. The presence on `Lower` means that the only difference between split space/enter and 2U space is having to press `Lower` with your left thumb. Right thumb is always enter.

```
.-----------------------------------------------------------------------------------.
| ~    | !    | @    | #    | $    | %    | ^    | &    | *    | (    | )    | Del  |
|------+------+------+------+------+------+------+------+------+------+------+------|
| xxxx | F1   | F2   | F3   | F4   | F5   | F6   | _    | +    | {    | }    | xxxx |
|------+------+------+------+------+------+------+------+------+------+------+------|
| xxxx | F7   | F8   | F9   | F10  | F11  | F12  | xxxx | xxxx | xxxx | |    | xxxx |
|------+------+------+------+------+------+------+------+------+------+------+------|
| xxxx | xxxx | ____ | ____ | Lwr  |Enter |Enter | Rse  | ____ | ____ | xxxx | xxxx |
'-----------------------------------------------------------------------------------'
```

## Raise

* Space: Regular space. Not actually useful but kept here completeness sake.
* É, Æ, Ø, Å, £, €: These all require [EurKey](https://eurkey.steffen.bruentjen.eu/) installed and set as current language.

```
.-----------------------------------------------------------------------------------.
| `    | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    | 0    | Del  |
|------+------+------+------+------+------+------+------+------+------+------+------|
| Caps | É    | Æ    | Ø    | Å    | £    | €    | -    | =    | [    | ]    | xxxx |
|------+------+------+------+------+------+------+------+------+------+------+------|
| xxxx | Undo | Cut  | Copy | Pste | Redo | xxxx | xxxx | xxxx | xxxx | \    | xxxx |
|------+------+------+------+------+------+------+------+------+------+------+------|
| xxxx | xxxx | ____ | ____ | ____ |Space |Space | ____ | ____ | ____ | xxxx | xxxx |
'-----------------------------------------------------------------------------------'
```

## Adjust

* Lots of standard RGB functions
* Hibrnt: Hibernates the computer
* Sleep: Sleeps the computer
* BL3: Toggles on the `Borderlands 3 - Base` layer

```
.-----------------------------------------------------------------------------------.
| xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx |Reset |
|------+------+------+------+------+------+------+------+------+------+------+------|
|Hibrnt|RgbVai|RgbSai|RgbHui|RgbMod|RgbTog| xxxx | BL3  | xxxx | xxxx | xxxx | xxxx |
|------+------+------+------+------+------+------+------+------+------+------+------|
|Sleep |RgbVad|RgbSad|RgbHud|RgbRmd| xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx |
|------+------+------+------+------+------+------+------+------+------+------+------|
| xxxx | xxxx | xxxx | xxxx | Lwr  |Reset |Reset | Rse  | xxxx | xxxx | xxxx | xxxx |
'-----------------------------------------------------------------------------------'
```

## Funpad

* Gui: Double tap to get back to `Base`.

```
.-----------------------------------------------------------------------------------.
| xxxx | F9   | F10  | F11  | F12  | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx |
|------+------+------+------+------+------+------+------+------+------+------+------|
| xxxx | F5   | F6   | F7   | F8   | xxxx | xxxx | LCtl | LSft | LAlt | LGui | xxxx |
|------+------+------+------+------+------+------+------+------+------+------+------|
| xxxx | F1   | F2   | F3   | F4   | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx |
|------+------+------+------+------+------+------+------+------+------+------+------|
| xxxx | xxxx | ____ | ____ | xxxx | xxxx | xxxx | xxxx | ____ | ____ | xxxx | xxxx |
'-----------------------------------------------------------------------------------'
```

## Numpad

* Alt: Double tap to get back to `Base`.

```
.-----------------------------------------------------------------------------------.
| Tab  | xxxx |KC_F2 | (    | )    | xxxx | xxxx | 7    | 8    | 9    | xxxx | Bspc |
|------+------+------+------+------+------+------+------+------+------+------+------|
| ____ | /    | *    | -    | +    | xxxx | xxxx | 4    | 5    | 6    | xxxx | xxxx |
|------+------+------+------+------+------+------+------+------+------+------+------|
| ____ | xxxx | xxxx | xxxx | =    | xxxx | xxxx | 1    | 2    | 3    | xxxx | xxxx |
|------+------+------+------+------+------+------+------+------+------+------+------|
| xxxx | xxxx | ____ | ____ | xxxx | Entr | Entr | 0    | ,    | .    | xxxx | xxxx |
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
|Spaces|L_Mon |R_Mon |L_Spc |R_Spc | xxxx | PgUp | Home | Up   | End  | xxxx |DelWrd|
|------+------+------+------+------+------+------+------+------+------+------+------|
|W_Menu| LGui | LAlt | LSft | LCtl |Dsktop| PgDn | Left | DOWN | Rght | xxxx | xxxx |
|------+------+------+------+------+------+------+------+------+------+------+------|
I ____ |L_Algn|R_Algn|Maxim |VidOff| xxxx |Files |MicOff| xxxx | xxxx | xxxx | ____ |
|------+------+------+------+------+------+------+------+------+------+------+------|
| Lock |Dm_Stp| Mprv | Mply | Mnxt | ____ | ____ | Volu | Vold | Mute |Dm_Rc1|Dm_Rc2|
'-----------------------------------------------------------------------------------'
```

## Borderlands 3 - Base

* Base: Toggles back to `Base`.
* S_W: Shifted W for running.
* Space: Hold to activate `Borderlands 3 - Upper`.

```
.-----------------------------------------------------------------------------------.
| xxxx | Tab  | Q    | S_W  | E    | R    | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx |
|------+------+------+------+------+------+------+------+------+------+------+------|
| xxxx | Esc  | A    | S    | D    | F    | xxxx | Base | xxxx | xxxx | xxxx | xxxx |
|------+------+------+------+------+------+------+------+------+------+------+------|
| xxxx | LSft | Z    | X    | C    | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx |
|------+------+------+------+------+------+------+------+------+------+------+------|
| xxxx | xxxx | xxxx | G    | V    | Spc  | Spc  | xxxx | xxxx | xxxx | xxxx | xxxx |
'-----------------------------------------------------------------------------------'
```

## Borderlands 3 - Upper

* Base: Toggles back to `Base` layer
* W: Shifted W for running

```
.-----------------------------------------------------------------------------------.
| xxxx | Tab  | 1    | W    | 2    | 3    | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx |
|------+------+------+------+------+------+------+------+------+------+------+------|
| xxxx | Esc  | A    | S    | D    | 4    | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx |
|------+------+------+------+------+------+------+------+------+------+------+------|
| xxxx | LSft | M    | I    | L    | K    | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx |
|------+------+------+------+------+------+------+------+------+------+------+------|
| xxxx | xxxx | xxxx | [    | ]    | Spc  | Spc  | xxxx | xxxx | xxxx | xxxx | xxxx |
'-----------------------------------------------------------------------------------'
```

## Rotary encoder functions

```
.-------------.
|      |      |
'-------------'
```
