#!/bin/bash

# Command-line argument is filename to assemble
/home/aepstein/devkitPro/devkitPPC/bin/powerpc-eabi-gcc -S $1 -o test.s
# remove the unneeded lines from the assembly
sed -i "/.file\|.section\|.align\|.globl\|.type\|.size\|.ident/d" test.s


text="begin:
	subi sp,sp,4
	stw r3,0(sp)
	bl _main
cleanup:
	lwz r3,0(sp)
	addi sp,sp,4
	b exit"

exec 3<> test.s && awk -v TEXT="$text" 'BEGIN {print TEXT}{print}' test.s >&3

