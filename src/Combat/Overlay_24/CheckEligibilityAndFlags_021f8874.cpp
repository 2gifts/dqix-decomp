#include <globaldefs.h>

struct InnerStats_021f8874 {
    char pad0[0x2];
    unsigned short field2;
    char pad1[0x14 - 0x4];
    int flags14;
};
struct CombatantLike_021f8874 {
    char pad0[0x4];
    short field4;
    char pad1[0x138 - 0x6];
    struct InnerStats_021f8874* inner;
};
struct Obj_021f8874 { char pad0[0x8]; struct CombatantLike_021f8874* field8; };
struct Arg1_021f8874 {
    char pad0[0x8];
    volatile unsigned int field8;
    char pad1[0x10 - 0xc];
    unsigned int field10;
};

extern "C" int func_ov024_021f87dc(struct CombatantLike_021f8874* a0, struct Arg1_021f8874* a1, int* a2);

// USA: func_ov024_021f8874  (semantic: CheckEligibilityAndFlags_021f8874)
extern "C" ARM int func_ov024_021f8874(struct Obj_021f8874* obj, struct Arg1_021f8874* target, struct CombatantLike_021f8874* combatant, int* extra) {
    if (!target) return 0;
    if (((target->field8 << 4) >> 31) == 0) return 0;
    int inRange = 0;
    short category = combatant->field4;
    if (category >= 0 && category <= 3) {
        inRange = 1;
    }
    int value;
    if (inRange) {
        value = func_ov024_021f87dc(combatant, target, extra);
    } else {
        value = (target->field8 << 24) >> 24;
    }
    unsigned short threshold = obj->field8->inner->field2;
    if (value > threshold) return 0;
    if (target->field10 & 1) {
        if (combatant->inner->flags14 & 0x100) return 0;
    }
    if (target->field10 & 2) {
        if (combatant->inner->flags14 & 0x80) return 0;
    }
    return 1;
}
