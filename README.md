# Goodsoup 2.0.0

Written by [Robin Southern](https://github.com/betajaen)

## About

This is a game interpreter and player for the Lucasarts game "Curse of Monkey Island" (COMI)
for the Commodore Amiga (CBM Amiga) range of computers. This allows you to play the
Curse of Monkey Island game, natively without emulation on the Commodore Amiga using its
software APIs using a copy of the COMI PC data files only.

In laymans terms; Goodsoup is "COMI.exe" for the Amiga.

Goodsoup is a partial fork and reimplementation of the following codebases:

	- ScummVM 0.9.1 (SCUMM V8) Code by the ScummVM Team.
	- NScumm (NScumm.Scumm) Code by Valéry Sablonnière.

## Copying

Goodsoup is licensed under the GNU General Public License version 3. Please refer to the
COPYING file, which is included in this source code distribution.

## Supported Games

    The Curse of Monkey Island					[comi]
        - English: GOG.com

## Current Requirements

An CBM Amiga (or CBM Amiga Emulator) with the following features:-

* Workbench Release 3.1 or higher
* At least 2 MiBs of RAM
* At least a Motorola 68020 Processor
* A Harddrive partition with 940 MiB free of space

**Please note:** These may change based on development of Goodsoup.

## Status (30-April-2023)

Goodsoup 2.0.0 is having a complete rewrite from scratch, from the previous version.

Current efforts are the following:

1. A develop stable C++11 based framework for AmigaOS 3.1+
2. Resource file (*.LA files) loading
3. AGA and RTG graphics interfaces.
4. Script parsing and execution.

Current milestone:

1. Displaying of Difficulty selection screen on AGA and RTG.

## Development Instructions

### MacOS/Unix with CLion with CMake and Docker amigadev/crosstools

#### Setup Instructions

1. Install Docker
2. Install the [amigadev/crosstools:m68k-amigaos](https://hub.docker.com/layers/amigadev/crosstools/m68k-amigaos/images/sha256-a959e6678a8c41e663adf51bd253dc924347e9a611188c5d00078cbfef67c22a?context=explore) image
3. Ensure CLion has the following Toolchain added
   1. Name: `docker-crosstools-m68k-amigaos`
   2. Server: `Docker`
   3. Image: `amigadev/crosstools:m68k-amigaos`
   4. Container Settings: `--entrypoint -rm`
   5. CMake: `/usr/bin/cmake`
   6. Build Tool: *Blank*
   7. C Compiler: `m68k-amigaos-gcc`
   8. C++ Compiler: `m68k-amigaos-gcc`
4. Install FS-UAE

#### Build instructions

Build normally through CLion for the `docker-crosstools-m68k-amigaos` profile.

#### Testing instructions

From the main gs directory run:

~~~sh
sh tests/gs-fs-uae.sh
~~~

