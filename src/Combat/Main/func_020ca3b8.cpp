#include <globaldefs.h>

// USA: func_020ca3b8
// PROVENANCE: pokeheartgold/lib/NitroSDK/asm/mi_memory.s — MIi_CpuCopy16. Halfword-granularity
// memcpy loop (raw NitroSDK .s routine, ported as mwcc inline asm).
extern "C" ARM asm void func_020ca3b8(const unsigned short* src, unsigned short* dst, unsigned int size) {
    mov ip, #0
top:
    cmp ip, r2
    blt load
    b after_load
load:
    ldrh r3, [r0, ip]
after_load:
    blt store
    b after_store
store:
    strh r3, [r1, ip]
after_store:
    blt incr
    b after_incr
incr:
    add ip, ip, #2
after_incr:
    blt top
    bx lr
}
