// _ll_sdiv at 0x0200cd2c is hand-written library assembly, transcribed
// instruction-for-instruction from the ROM. It is not un-decompiled C.
//
// PROVENANCE: sm64ds-decomp src/_ll_sdiv.c -- asm there too; MSL runtime
//
// Assembly rather than an mwccarm `asm` block because the inline assembler cannot
// express this one. Mnemonics are the canonical ARM spellings mwasmarm accepts.

	.section .text
	.arm
	.extern _s32_div_f

	.global _ll_mod
	.global _ll_sdiv

_ll_mod:
	stmdb sp!, {r4, r5, r6, r7, r11, ip, lr}
	mov r4, r1
	orr r4, r4, #1
	b _ll_sdiv_body

_ll_sdiv:
	stmdb sp!, {r4, r5, r6, r7, r11, ip, lr}
	eor r4, r1, r3
	mov r4, r4, asr #1
	mov r4, r4, lsl #1
_ll_sdiv_body:
	orrs r5, r3, r2
	bne _L20
	ldmia sp!, {r4, r5, r6, r7, r11, ip, lr}
	bx lr
_L20:
	mov r5, r0, lsr #0x1f
	add r5, r5, r1
	mov r6, r2, lsr #0x1f
	add r6, r6, r3
	orrs r6, r5, r6
	bne _L54
	mov r1, r2
	bl _s32_div_f
	ands r4, r4, #1
	movne r0, r1
	mov r1, r0, asr #0x1f
	ldmia sp!, {r4, r5, r6, r7, r11, ip, lr}
	bx lr
_L54:
	cmp r1, #0
	bge _L64
	rsbs r0, r0, #0
	rsc r1, r1, #0
_L64:
	cmp r3, #0
	bge _L74
	rsbs r2, r2, #0
	rsc r3, r3, #0
_L74:
	orrs r5, r1, r0
	beq _L198
	mov r5, #0
	mov r6, #1
	cmp r3, #0
	bmi _La0
_L8c:
	add r5, r5, #1
	adds r2, r2, r2
	adcs r3, r3, r3
	bpl _L8c
	add r6, r6, r5
_La0:
	cmp r1, #0
	blt _Lc0
_La8:
	cmp r6, #1
	beq _Lc0
	sub r6, r6, #1
	adds r0, r0, r0
	adcs r1, r1, r1
	bpl _La8
_Lc0:
	mov r7, #0
	mov ip, #0
	mov r11, #0
	b _Le8
_Ld0:
	orr ip, ip, #1
	subs r6, r6, #1
	beq _L140
	adds r0, r0, r0
	adcs r1, r1, r1
	adcs r7, r7, r7
_Le8:
	subs r0, r0, r2
	sbcs r1, r1, r3
	sbcs r7, r7, #0
	adds ip, ip, ip
	adc r11, r11, r11
	cmp r7, #0
	bge _Ld0
_L104:
	subs r6, r6, #1
	beq _L138
	adds r0, r0, r0
	adcs r1, r1, r1
	adc r7, r7, r7
	adds r0, r0, r2
	adcs r1, r1, r3
	adc r7, r7, #0
	adds ip, ip, ip
	adc r11, r11, r11
	cmp r7, #0
	bge _Ld0
	b _L104
_L138:
	adds r0, r0, r2
	adc r1, r1, r3
_L140:
	ands r7, r4, #1
	moveq r0, ip
	moveq r1, r11
	beq _L178
	subs r7, r5, #0x20
	movge r0, r1, lsr r7
	bge _L19c
	rsb r7, r5, #0x20
	mov r0, r0, lsr r5
	orr r0, r0, r1, lsl r7
	mov r1, r1, lsr r5
	b _L178
	mov r0, r1, lsr r7
	mov r1, #0
_L178:
	cmp r4, #0
	blt _L188
	ldmia sp!, {r4, r5, r6, r7, r11, ip, lr}
	bx lr
_L188:
	rsbs r0, r0, #0
	rsc r1, r1, #0
	ldmia sp!, {r4, r5, r6, r7, r11, ip, lr}
	bx lr
_L198:
	mov r0, #0
_L19c:
	mov r1, #0
	cmp r4, #0
	blt _L188
	ldmia sp!, {r4, r5, r6, r7, r11, ip, lr}
	bx lr
