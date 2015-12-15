#!/bin/bash

# Command-line argument is filename to assemble
/home/aepstein/devkitPro/devkitPPC/bin/powerpc-eabi-gcc -S $1 -o test.s
# Remove the unneeded lines from the assembly
sed -i "/.file\|.section\|.align\|.globl\|.type\|.size\|.ident/d" test.s

# Prepend the required header. Here's what it does:
# 1. Back up the value in r3 on the stack
# 2. Branch and link to _main
# 3. Restore r3's value from the stack
# 4. Branch to our exit function
header="begin:
	subi sp,sp,4
	stw r3,0(sp)
	bl _main
cleanup:
	lwz r3,0(sp)
	addi sp,sp,4
	b exit"

exec 3<> test.s && awk -v TEXT="$header" 'BEGIN {print TEXT}{print}' test.s >&3

# Append the exit function. The instruction to be executed is
# the first instruction from the function we're injecting into (0x8008923C)
cat <<EOT >> test.s
exit:
	addi r31, r5, 0
EOT

