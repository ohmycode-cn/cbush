#!/bin/zsh

makec() {
    rm -rf build/
    cmake -B build/
    cmake --build build/ -j12 && ./bush
}
makec
