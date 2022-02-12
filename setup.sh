#!/bin/bash

cwd=$(pwd)

ln -sf "$cwd/users/metheon/" "$cwd/../qmk_firmware/users/"
ln -sf "$cwd/keyboards/splitkb/kyria/keymaps/metheon/" "$cwd/../qmk_firmware/keyboards/splitkb/kyria/keymaps/"
ln -sf "$cwd/keyboards/planck/keymaps/metheon/" "$cwd/../qmk_firmware/keyboards/planck/keymaps/"
ln -sf "$cwd/keyboards/ferris/keymaps/metheon/" "$cwd/../qmk_firmware/keyboards/ferris/keymaps/"
