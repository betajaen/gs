#!/bin/bash

if [ ! -f "./include/gs/util/types.hpp" ]; then
  echo "Error: Please run this script from the main gs directory. i.e. > sh tests/gs-fs-uae.sh"
  exit 1
fi

# check for COMI media files.

if [[ -d "media/cds" ]]; then
  volumes_dir="$(pwd)/media/cds"
elif [[ -d "media/dvd" ]]; then
  volumes_dir="$(pwd)/media/dvd"
elif [[ -d "media/digital" ]]; then
  volumes_dir="$(pwd)/media/digital"
else
  echo "ERROR: Could not find 'cds', 'dvd', 'digital' directory in the media directory. Please refer to media/media.md for instructions."
  exit 1
fi

# OPENING.SAN -> MONKEY3_1:
# FINALE.SAN -> MONKEY3_2:
# OPENING.SAN and FINALE.SAN -> MONKEY3:
volume_1=""
volume_2=""
resource_dir="${volumes_dir}/RESOURCE"
if [[ -f "${resource_dir}/OPENING.SAN" && -f "${resource_dir}/FINALE.SAN" ]]; then
  volume_1="${volumes_dir}"
  volume_2="${volumes_dir}"
  if [[ "${resource_dir}/OPENING.SAN" -ef "${resource_dir}/FINALE.SAN" ]]; then
    volume_2="${volume_1}"
  fi
else
  for subdir in "${volumes_dir}"/*/; do
    resource_dir="${subdir}RESOURCE"
    if [[ -f "${resource_dir}/OPENING.SAN" && -f "${resource_dir}/FINALE.SAN" ]]; then
      if [[ -z "${volume_1}" ]]; then
        volume_1="${subdir}"
      fi
      volume_2="${subdir}"
    elif [[ -f "${resource_dir}/OPENING.SAN" ]]; then
      volume_1="${subdir}"
    elif [[ -f "${resource_dir}/FINALE.SAN" ]]; then
      volume_2="${subdir}"
      if [[ "${resource_dir}/OPENING.SAN" -ef "${resource_dir}/FINALE.SAN" ]]; then
        volume_2="${volume_1}"
      fi
    else
      echo "ERROR: Could not determine volume for ${subdir}"
      continue
    fi
  done
fi

if [[ "${volume_1}" == "${volume_2}" ]]; then
  MEDIA_ARGS=" --hard_drive_1=${volume_1} --hard_drive_1_label=MONKEY3"
else
  MEDIA_ARGS=" --hard_drive_1=${volume_1} --hard_drive_1_label=MONKEY3_1  --hard_drive_2=${volume_2} --hard_drive_2_label=MONKEY3_2"
fi

ROM_DEFAULT="./tests/kicka1200.rom"
FASTRAM_DEFAULT="4096"
MODEL_DEFAULT="a1200"
OTHER_ARGS="--hard-drive_0=./progdir  --automatic_input_grab=0 --floppy_drive_volume_empty=0 --stdout --console_debugger=1${MEDIA_ARGS}"

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
