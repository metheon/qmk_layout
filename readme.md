# Configuration for my QMK keyboards

## Keymap

![](images/keymap.svg)

## Setup

* It is assumed that [`qmk_firmware/`](https://github.com/qmk/qmk_firmware) is located in `../` (so, same directory as this repo).
* Run the script [`setup.sh`](setup.sh) in order to symlink this directory into qmk.
* I might switch to [this way](https://medium.com/@patrick.elmquist/separate-keymap-repo-for-qmk-136ff5a419bd) of symlinking my repos.

## Flashing

* [*Ferris Sweep*](https://github.com/davidphilipbarr/Sweep) ([`config.h`](keyboards/ferris/keymaps/metheon/config.h)):
  * `make ferris/sweep:metheon:flash` (or `:dfu-split-left` or `:dfu-split-right`)
* [*Kyria*](https://splitkb.com) ([`config.h`](keyboards/splitkb/kyria/keymaps/metheon/config.h)):
  * `make splitkb/kyria:metheon:flash`
* [*Planck EZ*](https://ergodox-ez.com/pages/planck) ([`config.h`](keyboards/planck/keymaps/metheon/config.h)):
  * `make planck/ez:metheon:flash`

## A note on my layout

I have mainly been a [Colemak](https://colemak.com/) user, but eventually decided to switch as it does not work too well with Danish which is my native language. I tried out [Hands Down Gold](https://sites.google.com/alanreiser.com/handsdown/home) briefly, but did not like the `R` on pinky. Alan (creator of Hands Down) then made a new version called Titanium with `R` on thumb (it is very lovely). After using that a bit I decided to make my own layout which took the best parts of Colemak and Hands Down Titanium with the aim to be optimized against Danish and English at the same time with minimal sacrifice for either language. Thus my own layout was born named `methane`. The chemical formular for `methane` is `CH₄` thus the name serves as homage to the one part Colemak and the four part Hands Down that served as inspiration for the layout. It has around 1% SFBs against a mixed corpus of Danish and English.
