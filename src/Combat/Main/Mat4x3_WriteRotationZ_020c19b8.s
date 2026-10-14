// Mat4x3_WriteRotationZ at 0x020c19b8 is the NitroSDK MTX_RotZ family, hand-written assembly in
// the SDK itself: pret/pokediamond carries MTX_RotZ33_ and MTX_RotZ44_ as `asm void` in
// arm9/lib/NitroSDK/src/FX_mtx33.c and FX_mtx44.c.
//
// No C form reaches it. THUMB mwccarm never fuses consecutive ascending register stores into
// STMIA -- the plain field writes stay str/str/str at every optimisation level -- and this routine
// is nothing but six fused stores.
//
// Assembly rather than an mwccarm `asm` block because asmgen only emits ARM, and mwccarm's inline
// assembler does not accept THUMB register lists in this form. Mnemonics are the classic THUMB
// spellings mwasmarm accepts, not the UAL ones a disassembler prints: mov, lsl and neg, never
// movs, lsls or rsbs.

	.section .text
	.thumb

	.global Mat4x3_WriteRotationZ
Mat4x3_WriteRotationZ:
	stmia r0!, {r2}
	mov r3, #0
	stmia r0!, {r1, r3}
	neg r1, r1
	stmia r0!, {r1, r2, r3}
	mov r1, #0
	mov r2, #0
	mov r3, #1
	lsl r3, r3, #0xc
	stmia r0!, {r1, r2, r3}
	mov r3, #0
	stmia r0!, {r1, r2, r3}
	bx lr
	.short 0x0000
