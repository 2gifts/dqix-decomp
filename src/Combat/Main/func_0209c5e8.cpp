#include <globaldefs.h>

struct Flags0209c5e8 {
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char rest : 5;
};

struct Actor0209c5e8 {
    char pad0[0xb0];
    int state;
    char pad_b4[0xb8 - 0xb4];
    short field_b8;
    short field_ba;
    void* fieldBC;
    void* fieldC0;
    char pad_c4[0xc8 - 0xc4];
    struct Flags0209c5e8 field_c8;
};

struct Actor0209c678;
struct Obj0203aba8;

int IsBattleActiveAndCombatantsBit0Set_0209c140();
void DispatchContextByState0209c678(struct Actor0209c678* actor, int arg);
void SetContextAndDispatch0203ac10(void* obj, void* a, int b);
int TryDispatchOrFallback0203aba8(struct Obj0203aba8* obj, void* key, void* target);

// USA: func_0209c5e8
extern "C" ARM void func_0209c5e8(struct Actor0209c5e8* actor) {
    if (actor->field_c8.bit2) return;
    if (IsBattleActiveAndCombatantsBit0Set_0209c140() != 0) {
        DispatchContextByState0209c678((struct Actor0209c678*)actor, 0);
        return;
    }
    if (actor->state == 1) {
        SetContextAndDispatch0203ac10(actor, &actor->fieldBC, 0);
        TryDispatchOrFallback0203aba8((struct Obj0203aba8*)actor, (void*)(int)actor->field_b8, &actor->fieldBC);
        return;
    }
    if (actor->state != 2) return;
    SetContextAndDispatch0203ac10(actor, &actor->fieldC0, 0);
    TryDispatchOrFallback0203aba8((struct Obj0203aba8*)actor, (void*)(int)actor->field_ba, &actor->fieldC0);
}
