#include <globaldefs.h>

struct TargetHalfwords0202e95c;

struct Obj021e8584 {
    char pad[0x8];
    short a;
    unsigned short b;
};

void* GetActiveCombatWork_ov000_02160130(void);
extern "C" void* func_ov000_02160f14(void* w);
void SetTargetHalfwords0202e95c(TargetHalfwords0202e95c*, short, unsigned short);

// USA: func_ov025_021e8584  (semantic: Trans_021e8584)
extern "C" ARM int func_ov025_021e8584(struct Obj021e8584* obj) {
    void* w = GetActiveCombatWork_ov000_02160130();
    SetTargetHalfwords0202e95c((struct TargetHalfwords0202e95c*)func_ov000_02160f14(w), obj->a, obj->b);
    return 1;
}
