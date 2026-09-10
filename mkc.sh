#!/bin/zsh

makec() {
    rm -rf build/
    export PREFIX=${PREFIX:-/data/data/com.termux/files/usr}
    cmake -B build/
    cmake --build build/ -j12 && ./bush
}
makec
