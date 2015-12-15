	.file	"test.c"
	.section	".text"
	.align 2
	.globl getPlayerPercent
	.type	getPlayerPercent, @function
getPlayerPercent:
	stwu 1,-40(1)
	stw 31,36(1)
	mr 31,1
	stw 3,24(31)
	lis 9,0x8045
	ori 9,9,12512
	stw 9,8(31)
	lis 9,0x8045
	ori 9,9,16240
	stw 9,12(31)
	lis 9,0x8045
	ori 9,9,19968
	stw 9,16(31)
	lis 9,0x8045
	ori 9,9,23696
	stw 9,20(31)
	lwz 9,24(31)
	cmpwi 7,9,2
	beq 7,.L3
	cmpwi 7,9,2
	bgt 7,.L4
	cmpwi 7,9,1
	beq 7,.L5
	b .L2
.L4:
	cmpwi 7,9,3
	beq 7,.L6
	cmpwi 7,9,4
	beq 7,.L7
	b .L2
.L5:
	lwz 9,8(31)
	lwz 9,0(9)
	srwi 9,9,16
	b .L8
.L3:
	lwz 9,12(31)
	lwz 9,0(9)
	srwi 9,9,16
	b .L8
.L6:
	lwz 9,16(31)
	lwz 9,0(9)
	srwi 9,9,16
	b .L8
.L7:
	lwz 9,20(31)
	lwz 9,0(9)
	srwi 9,9,16
	b .L8
.L2:
	li 9,0
.L8:
	mr 3,9
	addi 11,31,40
	lwz 31,-4(11)
	mr 1,11
	blr
	.size	getPlayerPercent, .-getPlayerPercent
	.align 2
	.globl _main
	.type	_main, @function
_main:
	stwu 1,-32(1)
	mflr 0
	stw 0,36(1)
	stw 31,28(1)
	mr 31,1
	lis 9,0x8016
	ori 9,9,49280
	stw 9,8(31)
	li 3,1
	bl getPlayerPercent
	mr 9,3
	cmplwi 7,9,100
	ble 7,.L11
	lwz 9,8(31)
	mtctr 9
	bctrl
.L11:
	mr 3,9
	addi 11,31,32
	lwz 0,4(11)
	mtlr 0
	lwz 31,-4(11)
	mr 1,11
	blr
	.size	_main, .-_main
	.ident	"GCC: (devkitPPC release 27) 4.8.2"
