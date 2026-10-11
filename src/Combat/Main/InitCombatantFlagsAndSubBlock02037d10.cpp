#include <globaldefs.h>
#if defined(jpn)
#define _Z35InitCombatantExtendedFields02052a4cPv func_02053e28
#define COMBAT_FIELD(x) ((x) - 12)
#else
#define COMBAT_FIELD(x) (x)
#endif

extern "C" void _Z35InitCombatantExtendedFields02052a4cPv(void*);
struct SubBlock02038508;
extern "C" void _Z17InitBlock02038508P16SubBlock02038508(struct SubBlock02038508*);

// USA: func_02037d10  (semantic: InitCombatantFlagsAndSubBlock02037d10)
extern "C" ARM void func_02037d10(void* obj) {
    signed char* base = (signed char*)obj;
    _Z35InitCombatantExtendedFields02052a4cPv(obj);
    *(unsigned short*)(base + 0x0) |= 0x800;
    base[COMBAT_FIELD(0x1cb)] = -1;
    base[COMBAT_FIELD(0x1cc)] = 0;
    base[COMBAT_FIELD(0x1c8)] = -1;
    base[COMBAT_FIELD(0x1c9)] = 0;
    base[COMBAT_FIELD(0x1ca)] = -1;
    base[COMBAT_FIELD(0x1cd)] = 0;
    base[COMBAT_FIELD(0x1ce)] = 0;
    base[COMBAT_FIELD(0x250)] = 1;
    base[COMBAT_FIELD(0x251)] = 0;
    base[COMBAT_FIELD(0x252)] = 1;
    base[COMBAT_FIELD(0x253)] = 1;
    base[COMBAT_FIELD(0x254)] = 0;
    *(int*)(base + COMBAT_FIELD(0x264)) = 0;
    *(int*)(base + COMBAT_FIELD(0x260)) = -1;
    base[COMBAT_FIELD(0x255)] = -1;
    *(unsigned short*)(base + COMBAT_FIELD(0x256)) = 0;
    struct SubBlock02038508* blk = (struct SubBlock02038508*)(base + COMBAT_FIELD(0x26c));
    *(int*)(base + COMBAT_FIELD(0x268)) = 0;
    _Z17InitBlock02038508P16SubBlock02038508(blk);
}

// JPN: 0x0203776c
