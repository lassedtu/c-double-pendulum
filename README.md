# Double Pendulum Simulation in c

## Overview

This project simulates a double pendulum, using differential equations to model the system's angular momentum over time, and renders the motion in real time with raylib.

[Showcase]: https://github.com/lassedtu/c-double-pendulum/images/showcase.gif "Gif showing the double pendulum simulation"

# raylib C setup

## Installation by operating system

### macOS (Apple Silicon and Intel)

1. Install Homebrew if needed.
2. Install dependencies:

```bash
brew update
brew install raylib pkg-config
```

### Linux (Debian/Ubuntu)

1. Update package lists.
2. Install compiler, make, pkg-config, and raylib development files:

```bash
sudo apt update
sudo apt install -y build-essential clang pkg-config libraylib-dev
```

### Windows

The easiest path is WSL2 with Ubuntu.

1. Open your Ubuntu (WSL2) terminal in the project folder.
2. Install dependencies:

```bash
sudo apt update
sudo apt install -y build-essential clang pkg-config libraylib-dev
```

Alternative (native Windows): use MSYS2 UCRT64 and install equivalent packages for clang, make, pkg-config, and raylib.

## Build and run

After installing dependencies on your platform:

### Build

```bash
make
```

### Run

```bash
make run
```

### Clean

```bash
make clean
```

## Inspiration

Special thanks to Daniel Hirsch for sparking the idea for this project through his video on the same topic. 
> *Though this project is strongly inspired by that work, no code has been copied*