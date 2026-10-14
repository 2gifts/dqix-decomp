// SaveDivSqrtState at 0x020cd594 is hand-written library assembly, transcribed
// instruction-for-instruction from the ROM. It is not un-decompiled C.
//
// PROVENANCE: SonicRushAdventure-Decomp lib/NitroSDK/src/cp/cp_context.c CP_SaveContext -- asm there too
//
// Assembly rather than an mwccarm `asm` block because the inline assembler cannot
// express this one. Mnemonics are the canonical ARM spellings mwasmarm accepts.

	.section .text
	.arm

	.global _Z16SaveDivSqrtStatePv

_Z16SaveDivSqrtStatePv:
	ldr r1, _P3c
	stmdb sp!, {r4}
	ldmia r1, {r2, r3, r4, ip}
	stmia r0!, {r2, r3, r4, ip}
	ldrh ip, [r1, #-0x10]
	add r1, r1, #0x28
	ldmia r1, {r2, r3}
	stmia r0!, {r2, r3}
	and ip, ip, #3
	ldrh r2, [r1, #-8]
	strh ip, [r0]
	and r2, r2, #1
	strh r2, [r0, #2]
	ldmia sp!, {r4}
	bx lr
_P3c:
	.word 0x04000290
