#!/bin/bash

if [ ! -f "./source/include/gs/gs.hpp" ]; then
  echo "Error: Please run this script from the main gs directory. i.e. > sh tests/gs-fs-uae.sh"
  exit 1
fi

ROM_DEFAULT="./tests/kicka1200.rom"
FASTRAM_DEFAULT="4096"
MODEL_DEFAULT="a1200"
OTHER_ARGS="--hard-drive_0=./progdir  --automatic_input_grab=0 --floppy_drive_volume_empty=0"

while getopts ":r:f:m:" opt; do
  case $opt in
    r) ROM="$OPTARG" ;;
    f) FASTRAM="$OPTARG" ;;
    m) MODEL="$OPTARG" ;;
    *) echo "Usage: $0 [-r ROM] [-f FASTRAM] [-m MODEL]" >&2
       exit 1
       ;;
  esac
done

ROM=${ROM:-$ROM_DEFAULT}
FASTRAM=${FASTRAM:-$FASTRAM_DEFAULT}
MODEL=${MODEL:-$MODEL_DEFAULT}

if ! [[ "$FASTRAM" =~ ^[0-9]+$ ]]; then
  echo "Error: FASTRAM must be an integer"
  exit 1
fi

UAE_ARGS="--kickstart_file=$ROM --amiga_model=$MODEL --fast_memory=$FASTRAM $OTHER_ARGS"

if [ "$(uname)" == "Darwin" ]; then
  # MacOS
  /Applications/FS-UAE.app/Contents/MacOS/fs-uae $UAE_ARGS
elif [ "$(uname)" == "Linux" ]; then
  # Linux/Unix
  fs-uae $UAE_ARGS
else
  echo "Unsupported OS"
  exit 1
fi
