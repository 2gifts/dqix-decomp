#include <globaldefs.h>

struct Actor0209c678;
struct Actor0209c3b4;

void DispatchContextByState0209c678(struct Actor0209c678* actor, int arg);
int IsMissingFromTable0209c0f4(int value, int type);
void SetStateAndDispatch0209c3b4(struct Actor0209c3b4* actor, int val);
void Forward0203aa80(void* obj, int arg2);
extern "C" int _Z26SetContextAndQuery0203ab6cPvS_(void* obj, short arg1);
int IsBattleActiveAndCombatantsBit0Set();
extern "C" void* _Z24CallFunc020bc594OnField0Pv(void* obj, int unused);
int IsHandleB8Active0209c6bc(void* obj);
extern "C" void func_0209c5e8(void* actor);

struct Actor0209c530 {
    char pad0[0xb0];
    int state;
    int field_b4;
    short field_b8;
    short field_ba;
    void* fieldBC;
    void* fieldC0;
    void* fieldC4;
    unsigned char field_c8;
    unsigned char field_c9;
    short field_ca;
    unsigned char field_cc;
    unsigned char field_cd;
    short field_ce;
};

// USA: func_0209c530
extern "C" ARM void func_0209c530(struct Actor0209c530* a) {
    if (a->state != 2) return;

    DispatchContextByState0209c678((struct Actor0209c678*)a, 0);
    a->state = 1;

    if (IsMissingFromTable0209c0f4(a->field_b8, a->field_ba) != 0) {
        short v = a->field_b8;
        a->field_b8 = -1;
        SetStateAndDispatch0209c3b4((struct Actor0209c3b4*)a, v);
    } else {
        if (a->field_b4 > 0) {
            Forward0203aa80(a, a->field_b4);
        }
        _Z26SetContextAndQuery0203ab6cPvS_(a, a->field_b8);
        if (IsBattleActiveAndCombatantsBit0Set() != 0) {
            DispatchContextByState0209c678((struct Actor0209c678*)a, 0);
        } else {
            _Z24CallFunc020bc594OnField0Pv(&a->fieldBC, 0);
            if (IsHandleB8Active0209c6bc(a) == 0) {
                func_0209c5e8(a);
            }
        }
    }

    a->field_ce = -1;
}