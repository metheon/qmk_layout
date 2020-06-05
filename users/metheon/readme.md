# Metheon's layout

## Introduction

My approach to keyboards and keymaps is to mentally settle on a form factor which is simple, effective and intuitive. For me that is the basic Planck keyboard with its four rows by twelve columns. I then select keyboards which are physically able to map to this mental model.

For the actual keymap, I recommend reading through [`metheon.c`](metheon.c). For how that keymap is then mapped to each keyboard I use, read through the actual keymaps of those keyboards.
This approach ensures that it is quite easy to add support for a new keyboard as long as it fits the mental model of a 48 key Planck. All you have to do is write an adapter. Note that the order of the `#define` and the `#include` in the keymaps matter. The layout to use must be defined as it is called from within the `metheon.c` file.

Right now I use these three keyboards:

* The [*Ergodox EZ*](https://ergodox-ez.com/) ([`keymap.c`](../../keyboards/ergodox_ez/keymaps/metheon/keymap.c)):
  * The Ergodox EZ is the archetype split keyboard, it is kinda like a Planck but with a number row and a lot of unreachable keys in the thumb area.
* The [*Kyria*](https://blog.splitkb.com/blog/introducing-the-kyria) ([`keymap.c`](../../keyboards/kyria/keymaps/metheon/keymap.c)):
  * A Kyria is really just a reshuffled split Planck with two additional encoders.
* The [*Planck EZ*](https://ergodox-ez.com/pages/planck) ([`keymap.c`](../../keyboards/planck/keymaps/metheon/keymap.c)):
  * The Planck EZ is of course just a Planck with a 2U spacebar. I accomodate for the 2U spacebar by having the alternative functions mapped on my Lower layer. So e.g. on the Kyria I have Space and Enter as those two functions but on my Planck EZ it is that same 2U key. So the 2U key is space, and Lower-Space is then Enter. My left thumb is always Space and my right thumb is always Enter. The only difference is my left thumb holding Lower. It makes sence, trust me.

In the following sections I will dive into different aspects of my keymap.

### Special thanks

A lot of inspiration is drawn from [*Drashna*](https://github.com/qmk/qmk_firmware/tree/master/users/drashna) and [*manna-harbour_miryoku*](https://github.com/qmk/qmk_firmware/tree/master/users/manna-harbour_miryoku).

## Tap Dance

I try to minimize same finger bigrams, as such I only have a few tap dances defined:

* `Ctrl > Ctrl+Shift`
* `Alt > Win`
* `Win > Alt`

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
