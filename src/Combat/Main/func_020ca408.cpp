#include <globaldefs.h>

// USA: func_020ca408
// PROVENANCE: pokeheartgold/lib/NitroSDK/asm/mi_memory.s — MIi_CpuCopy32. Word-granularity memcpy
// loop (raw NitroSDK .s routine, ported as mwcc inline asm).
extern "C" ARM asm void func_020ca408(const unsigned int* src, unsigned int* dst, unsigned int size) {
    add ip, r1, r2
top:
    cmp r1, ip
    blt load
    b after_load
load:
    ldmia r0!, {r2}
after_load:
    blt store
    b after_store
store:
    stmia r1!, {r2}
after_store:
    blt top
    bx lr
}
