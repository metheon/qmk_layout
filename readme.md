# Metheon's layout

## Setup

* It is assumed that [`qmk_firmware/`](https://github.com/qmk/qmk_firmware) is located in `../` (so, same directory as this repo).
* Run the script [`setup.sh`](setup.sh) in order to symlink this directory into qmk.

## Introduction

I mainly use one type of keyboard, the Ferris Sweep! To me this is peak effeciency. It's form factor is simple, effective, intuitive. I use various Sweep-like keyboards and hence my keyboards layouts are created in the users folder and then shared among several other keyboards.

For the actual keymap, I recommend reading through [`metheon.c`](users/metheon/metheon.c). For how that keymap is then mapped to each keyboard I use, read through the config files of each keyboard listed below. Every config file contains a define which basically maps my layout to that particular keyboard. The `keymap.c` file itself is empty.
This approach ensures that it is quite easy to add support for a new keyboard PCB as long as it fits the layout of a Sweep. All you have to do is write the *adapter configuration*.

Right now I have support for the following keyboards, with the Sweep being the primary:

* [*Ferris Sweep*](https://github.com/davidphilipbarr/Sweep) ([`config.h`](keyboards/ferris/keymaps/metheon/config.h)):
  * `make ferris/sweep:metheon:dfu-split-left`
  * `make ferris/sweep:metheon:dfu-split-right`
* [*Kyria*](https://splitkb.com) ([`config.h`](keyboards/splitkb/kyria/keymaps/metheon/config.h)):
  * `make splitkb/kyria:metheon`
* [*Planck EZ*](https://ergodox-ez.com/pages/planck) ([`config.h`](keyboards/planck/keymaps/metheon/config.h)):
  * `make planck/ez:metheon`

In the following sections I will dive into different aspects of my keymap.

### Special thanks

A lot of inspiration is drawn from [*Drashna*](https://github.com/qmk/qmk_firmware/tree/master/users/drashna) and [*manna-harbour_miryoku*](https://github.com/qmk/qmk_firmware/tree/master/users/manna-harbour_miryoku). Also a big shoutout to the very active community on the splitkb discord, Colemak discord and QMK discord.

My layout is [Hands Down Titanium (neu-rx) by Alan Reiser](https://sites.google.com/alanreiser.com/handsdown/home). A huge thanks to Alan who engineered the layout upon request when I wanted to move R to the thumb.

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

This array is duplicated as a dummy array within the `leader.c` file, such that the keymap would still compile on another machine even without `secrets.h` present. The feature can also be turned off by appending the make command with: `make ... NO_SECRETS=yes`, which can be handy if I take my keyboard outside of my home.

Files:

* [`leader.c`](users/metheon/leader.c)
* [`leader.h`](users/metheon/leader.h)

## Encoders

The encoder logic is split in two parts. In the header file, [`encoders.h`](users/metheon/encoders.h), the _on tap_ function can be found while the rotary logic can be found in [`encoders.c`](users/metheon/encoders.c). The encoder functionality is disabled by default, but can be enabled for a keyboard if it has encoders, like I do in the [`rules.mk`](keyboards/splitkb/kyria/keymaps/metheon/rules.mk) file of my Kyria. The only other thing to note for my encoders is that I feel that the alt-tab logic is improved compared to what I have found elsewhere.

* [`encoders.c`](users/metheon/encoders.c)
* [`encoders.h`](users/metheon/encoders.h)

## Process Records

My process records files are also pretty basic. The main purpose of splitting this into their own files is simply readability.

Files:

* [`process_records.c`](users/metheon/process_records.c)
* [`process_records.h`](users/metheon/process_records.h)

## Text

This is one of those things I want to use more but I just haven't had the time yet. In any case, this feature allows you to easily create a text string and a key for that text string. Then using any method you want your keyboard will type it. I am mainly thinking about using it for bigrams and trigrams together with combos. Right now I have this where I tap `ta` for `tha`, `te` for `the` and `ti` for `thi` as a test.

Files:

* [`text.def`](users/metheon/text.def)
* [`process_records.h`](users/metheon/process_records.h)
* [`process_records.c`](users/metheon/process_records.c)

## Key Overrides

Just a list of key+mod overrides which aims to improve mainly the shifted character of base layer symbols and shifted numpad. I do use it for one other thing which is easy access to gui+tab and friends on base layer, without having tab on base layer. So holding gui while tapping enter or space is exactly like holding gui(+shift)+tab. Same principle apply for shift for moving desktop and alt for changing tabs.

Files:

* [`key_overrides.def`](users/metheon/key_overrides.def)
* [`key_overrides.c`](users/metheon/key_overrides.c)
