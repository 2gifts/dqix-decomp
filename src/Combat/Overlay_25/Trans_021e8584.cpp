#include <globaldefs.h>

struct TargetHalfwords0202e95c;

struct Obj021e8584 {
    char pad[0x8];
    short a;
    unsigned short b;
};

void* GetActiveCombatWork(void);
extern "C" void* func_ov000_02160f14(void* w);
extern "C" void _Z26SetTargetHalfwords0202e95cP23TargetHalfwords0202e95css(struct TargetHalfwords0202e95c* obj, short a, unsigned short b);

// USA: func_ov025_021e8584  (semantic: Trans_021e8584)
extern "C" ARM int func_ov025_021e8584(struct Obj021e8584* obj) {
    void* w = GetActiveCombatWork();
    _Z26SetTargetHalfwords0202e95cP23TargetHalfwords0202e95css((struct TargetHalfwords0202e95c*)func_ov000_02160f14(w), obj->a, obj->b);
    return 1;
}
