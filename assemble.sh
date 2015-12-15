#!/bin/bash

/home/aepstein/devkitPro/devkitPPC/bin/powerpc-eabi-gcc -S $1
#sed -i "/.file\|.section\|.align\|.globl\|.type\|.size\|.ident/d" test.s

