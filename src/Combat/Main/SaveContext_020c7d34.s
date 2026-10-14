// SaveContext at 0x020c7d34 is hand-written library assembly, transcribed
// instruction-for-instruction from the ROM. It is not un-decompiled C.
//
// PROVENANCE: SonicRushAdventure-Decomp lib/NitroSDK/src/os/os_context.c OS_SaveContext -- asm there too
//
// Assembly rather than an mwccarm `asm` block because the inline assembler cannot
// express this one. Mnemonics are the canonical ARM spellings mwasmarm accepts.

	.section .text
	.arm

	.global SaveContext
	.extern _Z25SaveDivSqrtState_020cd594Pv

SaveContext:
	stmdb sp!, {r0, lr}
	add r0, r0, #0x48
	ldr r1, _P48
	blx r1
	ldmia sp!, {r0, lr}
	add r1, r0, #0
	mrs r2, cpsr
	str r2, [r1], #4
	mov r0, #0xd3
	msr cpsr_c, r0
	str sp, [r1, #0x40]
	msr cpsr_c, r2
	mov r0, #1
	stmia r1, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, ip, sp, lr}
	add r0, pc, #8
	str r0, [r1, #0x3c]
	mov r0, #0
	bx lr
_P48:
	.word _Z25SaveDivSqrtState_020cd594Pv
