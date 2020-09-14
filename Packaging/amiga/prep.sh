#!/usr/bin/env bash

# exit when any command fails
set -euo pipefail

#set compiler params
export TARGET='m68k-amigaos'
export SYSROOT=/d/amiga-gcc2/
export M68K_CPU=68040
export M68K_FPU=hard
export M68K_CPU_FPU="-m${M68K_CPU}  -m${M68K_FPU}-float"
export M68K_COMMON="-s -ffast-math -fomit-frame-pointer -Ofast"
export M68K_CFLAGS="${M68K_CPU_FPU} ${M68K_COMMON}"
export M68K_CXXFLAGS="${M68K_CPU_FPU} ${M68K_COMMON}"

mkdir -p deps
mkdir -p ${SYSROOT}/usr/lib
mkdir -p ${SYSROOT}/usr/include
cd deps


# SDL1.2
wget https://github.com/AmigaPorts/libSDL12/archive/master.tar.gz -O SDL-1.2.tar.gz
tar -xvf SDL-1.2.tar.gz
cd libSDL12-master
make PREFX=${SYSROOT} PREF=${SYSROOT} -j$(getconf _NPROCESSORS_ONLN)
mkdir -p ${SYSROOT}/usr/lib
mkdir -p ${SYSROOT}/usr/include
cp -fvr libSDL.a ${SYSROOT}/usr/lib/
cp -fvr include/* ${SYSROOT}/usr/include/
cd ..
