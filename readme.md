# Configuration for my QMK keyboards

## Introduction

My layout is based on having just 34 keys. I might use keyboards larger than this, but not smaller. It is a form factor which is simple, effective and intuitive. I use various keyboards and hence my keyboards layouts are created in the users folder and then shared among several other keyboards.

For the actual keymap, I recommend reading through the keymap shown below. For how that keymap is then mapped to each keyboard I use, read through the config files of each keyboard listed below. Every config file contains a define which basically maps my layout to that particular keyboard. The `keymap.c` file itself is empty.
This approach ensures that it is quite easy to add support for a new keyboard PCB as long as it fits the 34-key layout. All you have to do is write the *adapter configuration*.

## Setup

* It is assumed that [`qmk_firmware/`](https://github.com/qmk/qmk_firmware) is located in `../` (so, same directory as this repo).
* Run the script [`setup.sh`](setup.sh) in order to symlink this directory into qmk.
* I might switch to [this way](https://medium.com/@patrick.elmquist/separate-keymap-repo-for-qmk-136ff5a419bd) of symlinking my repos.

## Keyboards

* [*Ferris Sweep*](https://github.com/davidphilipbarr/Sweep) ([`config.h`](keyboards/ferris/keymaps/metheon/config.h)):
  * `make ferris/sweep:metheon:flash` (or `:dfu-split-left` or `:dfu-split-right`)
* [*Kyria*](https://splitkb.com) ([`config.h`](keyboards/splitkb/kyria/keymaps/metheon/config.h)):
  * `make splitkb/kyria:metheon:flash`
* [*Planck EZ*](https://ergodox-ez.com/pages/planck) ([`config.h`](keyboards/planck/keymaps/metheon/config.h)):
  * `make planck/ez:metheon:flash`

## Keymap

![](images/keymap.svg)
