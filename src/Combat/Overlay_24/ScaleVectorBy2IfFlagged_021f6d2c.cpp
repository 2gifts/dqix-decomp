#include <globaldefs.h>

int CheckFlag0x14Bit0x10Set_020882f8(unsigned char* obj);

struct FlagInner_021de25c { char unk[0x14]; int flags; };
struct FlagObj_021de25c { char unk[0x138]; struct FlagInner_021de25c* inner; };
int IsFlagBit5Set_021de25c(struct FlagObj_021de25c* obj);

struct ScaleVec2_021f6d2c {
    int pad0;
    struct FlagObj_021de25c* combatant;
    int pad2[3];
    float x;
    float y;
    float sx;
    float sy;
};

// USA: func_ov024_021f6d2c  (semantic: ScaleVectorBy2IfFlagged_021f6d2c)
extern "C" ARM int func_ov024_021f6d2c(struct ScaleVec2_021f6d2c* obj) {
    struct FlagObj_021de25c* combatant = obj->combatant;
    if (CheckFlag0x14Bit0x10Set_020882f8((unsigned char*)combatant->inner) || IsFlagBit5Set_021de25c(combatant)) {
        obj->sx = obj->x * 2.0f;
        obj->sy = obj->y * 2.0f;
    }
    return 1;
}
