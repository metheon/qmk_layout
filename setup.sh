#!/bin/bash

cwd=$(pwd)

ln -sf "$cwd/users/metheon/" "$cwd/../qmk_firmware/users/"
ln -sf "$cwd/keyboards/splitkb/kyria/keymaps/metheon/" "$cwd/../qmk_firmware/keyboards/splitkb/kyria/keymaps/"