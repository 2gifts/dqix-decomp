#include <globaldefs.h>

// USA: func_020ca390
// PROVENANCE: pokeheartgold/lib/NitroSDK/asm/mi_memory.s — MIi_CpuClear16. Halfword-granularity
// memset loop (raw NitroSDK .s routine, ported as mwcc inline asm).
extern "C" ARM asm void func_020ca390(unsigned short value, unsigned short* dst, unsigned int size) {
    mov r3, #0
top:
    cmp r3, r2
    blt store
    b after_store
store:
    strh r0, [r1, r3]
after_store:
    blt incr
    b after_incr
incr:
    add r3, r3, #2
after_incr:
    blt top
    bx lr
}
