#include <globaldefs.h>

// USA: func_020ca430
// PROVENANCE: pokeheartgold/lib/NitroSDK/asm/mi_memory.s — MIi_CpuSend32. Word-granularity copy
// into a fixed FIFO-style destination register (raw NitroSDK .s routine, ported as mwcc inline asm).
extern "C" ARM asm void func_020ca430(const void* src, volatile void* dst, unsigned int size) {
    add ip, r0, r2
top:
    cmp r0, ip
    blt load
    b after_load
load:
    ldmia r0!, {r2}
after_load:
    blt store
    b after_store
store:
    str r2, [r1]
after_store:
    blt top
    bx lr
}
