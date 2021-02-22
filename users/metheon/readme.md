# Metheon's layout

## Introduction

I only use one type of keyboard, the Planck! To me this is peak effeciency. It's form factor is simple, effective, intuitive. I use various Planck-like keyboards and hence my keyboards layouts are created in the users folder and then shared among several Planck layouts.

For the actual keymap, I recommend reading through [`metheon.c`](metheon.c) or the diagram below. For how that keymap is then mapped to each keyboard I use, read through the config files of each keyboard listed below. Every config file contains a define which basically maps my layout to that particular keyboard.
This approach ensures that it is quite easy to add support for a new keyboard PCB as long as it fits the layout of a Planck. All you have to do is write the adapter configuration.

Right now I use these three keyboards:

* The [*Eon40*](https://anykeys.eu/product/eon40/) ([`config.h`](../../keyboards/evyd13/eon40/keymaps/metheon/config.h)):
* The [*Planck EZ*](https://ergodox-ez.com/pages/planck) ([`config.h`](../../keyboards/planck/keymaps/metheon/config.h)):

In the following sections I will dive into different aspects of my keymap.

### Special thanks

A lot of inspiration is drawn from [*Drashna*](https://github.com/qmk/qmk_firmware/tree/master/users/drashna) and [*manna-harbour_miryoku*](https://github.com/qmk/qmk_firmware/tree/master/users/manna-harbour_miryoku). Also a big shoutout to the very active community on the splitkb discord, Colemak discord and QMK discord.

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

Files:

* [`leader.c`](leader.c)
* [`leader.h`](leader.h)

## Encoders

The encoder logic is split in two parts. In the header file, [`encoders.h`](encoders.h), the _on tap_ function can be found while the rotary logic can be found in [`encoders.c`](encoders.c). The encoder functionality is disabled by default, but can be enabled for a keyboard if it has encoders, like I do in the [`rules.mk`](../../keyboards/kyria/keymaps/metheon/rules.mk) file of my Kyria. The only other thing to note for my encoders is that I feel that the alt-tab logic is improved compared to what I have found elsewhere.

* [`encoders.c`](encoders.c)
* [`encoders.h`](encoders.h)

## Process Records

My process records files are also pretty basic. The main purpose of splitting this into their own files is simply readability. The only unusual thing here is that the two make commands contain an argument which allows you to run the make in multiple threads. The command is `make -j n` with `-j` being equal to `--jobs` and `n` is some number of jobs (or threads) to run. This seem stable but the output is not too readable as QMK expects this to run in a single thread. Read the [documentation](https://www.gnu.org/software/make/manual/html_node/Parallel.html) for more. To see the difference on your machine prepend the make command with `time`, i.e `time make -j 4 ...`. After the compilation has finished `time` will output an output similar to this:

```c
real    0m14.293s
user    0m2.603s
sys     0m11.606s
```

Using multithreading makes the most sense when compiling a lot, like multiple keymaps at once, or if you changes rules or config files and especially on older hardware with slow processors.

Files:

* [`process_records.c`](process_records.c)
* [`process_records.h`](process_records.h)

## Keymap (out of date, scheduled to be removed)

Some explanations:

* I currently have seven layers: Base, Numpad, Funpad, Extend, Symbols, Adjust, Magnet. The following layer combinations active a third layer (tri layer combos):
  * Extend + Symbols = Adjust
  * Numpad + Funpad = Magnet
* `------` means transparent.
* Empty box means no mapping.
* All encoders are written as left/right/pres actions
* All dual function keys written as tap/hold actions

**Base**

* Enc 1: Cmd Shift Tab / Cmd Tab / Nothing
* Enc 2: Vol Down / Vol Up / Mute
* SpcExt: Space/Extend
* EntNum: Enter/Numpad
* DelFun: Delete/Funpad
* BspSym: Backspace/Symbols

```
.-------------------------------------------.                    .--------------------------------------------.
| Q      | W      | F     | P      | B      |                    | J      | L      | U      | Y      | '      |
|-------------------------------------------|                    |--------------------------------------------|
| A  Ctl | R Alt  | S Sft | T Gui  | G      |                    | M      | N Gui  | E Sft  | I Alt  | O Ctl  |
|-------------------------------------------|                    |--------------------------------------------|
| Z      | X      | C     | D      | V      |                    | K      | H      | ,      | .      | /      |
'-------------------------+--------+--------+--------.  .--------+--------+--------+--------+-----------------'
                          | Enc 1  | SpcExt | EntNum |  | DelFun | BspSym | Enc 2  |
                          '--------+--------+--------'  '--------+--------+--------'
```

**Numpad**

* Enc 1: Nothing
* Enc 2: Scroll Up / Scroll Down / Nothing

```
.-------------------------------------------.                    .--------------------------------------------.
|        |        |       |        |        |                    | =      | 7      | 8      | 9      | *      |
|-------------------------------------------|                    |--------------------------------------------|
| Ctrl   | Alt    | Shift | Gui    |        |                    | +      | 4      | 5      | 6      | 0      |
|-------------------------------------------|                    |--------------------------------------------|
|        |        |       |        |        |                    | -      | 1      | 2      | 3      | /      |
'-------------------------+--------+--------+--------.  .--------+--------+--------+--------+-----------------'
                          | Enc 1  | ------ | ------ |  | ------ | ------ | Enc 2  |
                          '--------+--------+--------'  '--------+--------+--------'
```

**Symbols**

* Enc 1: Ctrl Shift Tab / Ctrl Tab / Nothing
* Enc 2: Nothing
* EscExt: Escape/Extend

```
.--------------------------------------------.                    .--------------------------------------------.
| `      | ^      | #      | ~      | {      |                    | }      | $      | €      | £      |        |
|--------------------------------------------|                    |--------------------------------------------|
| @      | Æ      | Ø      | Å      | (      |                    | )      | =      | !      | &      | |      |
|--------------------------------------------|                    |--------------------------------------------|
| _      | -      | :      | ;      | [      |                    | ]      |        |        | %      | \      |
'--------------------------+--------+--------+--------.  .--------+--------+--------+--------+-----------------'
                           | Enc 1  | EscExt | ------ |  | ------ | ------ | Enc 2  |
                           '--------+--------+--------'  '--------+--------+--------'
```

**Extend**

* Paste: Put in Colemak-DH V, because appearently that is how my brain works.
* Enc 1: Nothing
* Enc 2: Prev / Next / Play
* StbFun: Shift Tab / Funpad
* TabSym: Tab/Symbols
* TxtMod: The mod used when moving around text, ctrl on windows, alt on mac

```
.--------------------------------------------.                    .--------------------------------------------.
| PrvTab | NxtTab | PrvWin | NxtWin |        |                    | PgUp   | Home   | Up     | End    |        |
|--------------------------------------------|                    |--------------------------------------------|
| Ctrl   | Alt    | Shift  | Gui    | Lead   |                    | PgDn   | Left   | Down   | Right  |        |
|--------------------------------------------|                    |--------------------------------------------|
| Undo   | Cut    | Copy   | TxtMod | Paste  |                    |        | PrvWrd | NxtWrd |        |        |
'--------------------------+--------+--------+--------.  .--------+--------+--------+--------+-----------------'
                           | Enc 1  | ------ | ------ |  | StbFun | TabSym | Enc 2  |
                           '--------+--------+--------'  '--------+--------+--------'
```

**Funpad**

* Enc 1: Zoom Out / Zoom In / Nothing
* Enc 2: Nothing

```
.--------------------------------------------.                    .--------------------------------------------.
| F9     | F10    | F11    | F12    |        |                    |        |        |        |        |        |
|--------------------------------------------|                    |--------------------------------------------|
| F5     | F6     | F7     | F8     |        |                    |        | Gui    | Shift  | Alt    | Ctrl   |
|--------------------------------------------|                    |--------------------------------------------|
| F1     | F2     | F3     | F4     |        |                    |        |        |        |        |        |
'--------------------------+--------+--------+--------.  .--------+--------+--------+--------+-----------------'
                           | Enc 1  | ------ | ------ |  | ------ | ------ | Enc 2  |
                           '--------+--------+--------'  '--------+--------+--------'
```

**Adjust**

* Enc 1: Nothing
* Enc 2: Nothing
* `Make` will type a make command for the keyboard
* `Flash` will type a make and flash command for the keyboard
* `Vrsn` will type the version the keyboard is running

```
.--------------------------------------------.                    .--------------------------------------------.
|        |        |        |        |        |                    |        | Flash  | Make   | Vrsn   |        |
|--------------------------------------------|                    |--------------------------------------------|
| Caps   | Prev   | Play   | Next   |        |                    | RgbTog | RgbMod | RgbHui | RgbSai | RgbVai |
|--------------------------------------------|                    |--------------------------------------------|
|        | Mute   | VolDn  | VolUp  |        |                    |        | RgbRMod| RgbHud | RgbSad | RgbVad |
'--------------------------+--------+--------+--------.  .--------+--------+--------+--------+-----------------'
                           | Enc 2  | Reset  | ------ |  | ------ | Reset  | Enc 2  |
                           '--------+--------+--------'  '--------+--------+--------'
```

**Magnet**

Shortcuts for the [Magnet app](https://magnet.crowdcafe.com/).

* `MgFscr` -> Fullscreen

* `MgLFHf` -> Left Half
* `MgRtHf` -> Right Half
* `MgUpHf` -> Upper Half
* `MgBtHf` -> Bottom Half

* `MgLfTd` -> Left Third
* `MgMdTd` -> Middle Third
* `MgRtTd` -> Right Third

* `MgL2Td` -> Right Two Thirds
* `MgR2Td` -> Right Two Thirds

* `MgUlQd` -> Upper Left Quadrant
* `MgUrQd` -> Upper Right Quadrant
* `MgBLQd` -> Bottom Left Quadrant
* `MgBrQd` -> Bottom Right Quadrant

* Enc 1: Nothing
* Enc 2: Nothing

```
.--------------------------------------------.                    .--------------------------------------------.
|        | MgUlQd | MgUpHf | MgUrQd |        |                    |        |        |        |        |        |
|--------------------------------------------|                    |--------------------------------------------|
|        | MgLFHf | MgFscr | MgRtHf |        |                    |        | MgLfTd | MgMdTd | MgRtTd |        |
|--------------------------------------------|                    |--------------------------------------------|
|        | MgBLQd | MgBtHf | MgBrQd |        |                    |        | MgL2Td | MgR2Td |        |        |
'--------------------------+--------+--------+--------.  .--------+--------+--------+--------+-----------------'
                           | Enc 1  | ------ | ------ |  | ------ | ------ | Enc 2  |
                           '--------+--------+--------'  '--------+--------+--------'
```
