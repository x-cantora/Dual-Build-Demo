# Dual-Build-Demo
Demo for showing how embedded development can be done using a PC

# Set Up
## Environment
WSL2 in Windows 10

## X Server
Vcxsrv

Place the following in `~/.bashrc`:
```
export WSL_HOST=$(cat "/etc/resolv.conf" | grep nameserver | awk '{print $2}' )
export DISPLAY="${WSL_HOST}:0"
```

## Apt packages
```
sudo apt install -y \
git \
gcc \
binutils \
libsdl2-dev \
cmake \
make \
arduino \
gcc-avr \
avrdude \
avr-libc \
ninja-build
```

# Build Instructions
## PC
`make build_pc`

## Hardware Target
`make build_target`

## Clean Build
`make clean`
