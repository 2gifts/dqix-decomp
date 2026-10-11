#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "std_library_functions.h"

extern "C" int func_ov000_0215eb1c(int battle, unsigned short* table, int count, int flag);
struct S_bf3c_021f1440;
int IsBitfield2Set_021f1440(struct S_bf3c_021f1440* obj);
GameObject* GetCombatantWithFlag0x400ByID(int unused, int id);
int IsCombatantFlagMask512_021eda60(GameObject* combatant);

struct Obj_021f166c { int field0; };

struct BuffWord_021f166c {
    signed int attackBuff : 3;
    signed int defenseBuff : 3;
    signed int agilityBuff : 3;
    signed int charmBuff : 3;
    signed int magicalMightBuff : 3;
    signed int magicalMendingBuff : 3;
    signed int unkBuff18 : 3;
    signed int unkBuff21 : 3;
};

extern unsigned short data_ov024_021fef6c;

// USA: func_ov024_021f166c  (semantic: FindLowUnkBuff21Unflagged_021f166c)
extern "C" ARM int func_ov024_021f166c(struct Obj_021f166c* obj, short id, int unused2, int* outCount, void* outArr) {
    GameObject* c0 = GetCombatantWithFlag0x400ByID(obj->field0, id);
    if (!c0) return 0;
    if (!IsBitfield2Set_021f1440((struct S_bf3c_021f1440*)c0)) return 0;

    unsigned short buf[8];
    unsigned short* d = buf;
    unsigned short* s = &data_ov024_021fef6c;
    int n = 8;
    do {
        unsigned short* dd = d++;
        *dd = *s++;
    } while (--n);

    int count = func_ov000_0215eb1c(obj->field0, buf, 8, 1);
    if (count <= 0) return 0;

    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, *(short*)&buf[i]);
        if (!c) continue;
        if (IsCombatantFlagMask512_021eda60(c)) continue;
        struct BuffWord_021f166c* bw = (struct BuffWord_021f166c*)((char*)c->currentStats_ + 0x58);
        if (bw->unkBuff21 < 2) break;
    }
    if (*outCount <= 0) return 0;

    *outCount = count;
    memcpy(outArr, buf, 0x10);
    return 1;
}
