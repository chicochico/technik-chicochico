# Technik-O Layout

QMK layout files for Boardsource Technik-O.

## Compiling with docker
Run the following to compile the firmware:
```
# clone QMK
git clone --recurse-submodules git@github.com:zsa/qmk_firmware.git

# clone the keymap inside the keymaps directory
git clone <THIS REPO> qmk_firmware/keyboards/boardsource/technik_o_chicochico

# finally run
util/docker_build.sh boardsource/technik_o:chico
```

A firmware file `planck_ez_glow_planck-chicochico.bin` will be created in the root of the project.\
Use [QMK Toolbox](https://github.com/qmk/qmk_toolbox) to flash the keyboard.
