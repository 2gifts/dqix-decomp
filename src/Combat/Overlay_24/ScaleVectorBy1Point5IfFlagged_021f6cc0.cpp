#include <globaldefs.h>

struct Combatant_20885b4;
int CheckFlag0x2AndKind1_020885b4(struct Combatant_20885b4* obj);
struct S88514;
int CheckFlag0x2AndState2_02088514(struct S88514* obj);

struct FlagInner_021da9b0 { char unk[0x14]; int flags; };
struct FlagObj_021da9b0 { char unk[0x138]; struct FlagInner_021da9b0* inner; };
int IsFlagBit8Set_021da9b0(struct FlagObj_021da9b0* obj);

struct ScaleVec3_021f6cc0 {
    int pad0;
    struct FlagObj_021da9b0* combatant;
    int pad2[3];
    float x;
    float y;
    float sx;
    float sy;
};

// USA: func_ov024_021f6cc0  (semantic: ScaleVectorBy1Point5IfFlagged_021f6cc0)
extern "C" ARM int func_ov024_021f6cc0(struct ScaleVec3_021f6cc0* obj) {
    struct FlagObj_021da9b0* combatant = obj->combatant;
    if (CheckFlag0x2AndKind1_020885b4((struct Combatant_20885b4*)combatant->inner) ||
        CheckFlag0x2AndState2_02088514((struct S88514*)combatant->inner) ||
        IsFlagBit8Set_021da9b0(combatant)) {
        obj->sx = obj->x * 1.5f;
        obj->sy = obj->y * 1.5f;
    }
    return 1;
}
