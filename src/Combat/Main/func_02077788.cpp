#include <globaldefs.h>
#include "GameState/GameState.h"

struct Entity02077788 {
    char pad0[0x44];
    Vector3fix f44;
    char pad50[0xae - 0x50];
    short fae;
    char padb0[0xb2 - 0xb0];
    unsigned short fb2;
    unsigned short fb4;
    char padb6[0x154 - 0xb6];
    int f154;
    char pad158[0x166 - 0x158];
    unsigned short f166;
    char pad168[0x17b - 0x168];
    unsigned char f17b;
};

struct CombatantLayout02077788 {
    unsigned short flags;
    char pad2[0xc0 - 2];
    unsigned char kind;
};

extern "C" void* func_0202ae18(void);
extern "C" Vector3fix func_020341e0(void* obj);
extern "C" int func_020322c0(int a, int* b, int c);
extern "C" void func_020794f8(void* obj, int a, int b);
int CheckField0NonZero(int* obj);
struct SearchStruct0202c1a4;
struct BitFlag02033f44;
struct Obj02033834;
struct Obj02033b68;
struct Outer02077a20;
int GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
int GetField0xe4IfFlag0x40(struct BitFlag02033f44* obj);
extern "C" void _Z21SetVecYByMode02033834P11Obj02033834i(struct Obj02033834* obj, int angle);
extern "C" void _Z24SetByteIfChanged02033b68P11Obj02033b68i(struct Obj02033b68* obj, int value);
extern "C" void _Z18TrySetMode02076cccPvi(void* obj, int mode);
extern "C" int _Z28GetField0x8OrDefault02077a20P13Outer02077a20(struct Outer02077a20* obj);
int GetIntField0x264(void* obj);

// USA: func_02077788
extern "C" ARM void func_02077788(struct Entity02077788* self) {
    GameState* battleStruct = GameState::GetInstance();
    void* g = func_0202ae18();
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(self->f166);
    if (combatant == 0) {
        return;
    }

    Vector3fix pos = func_020341e0(combatant);
    Vector3fix delta;
    Vector3fix_Subtract((const Vector3fix*)&pos, (const Vector3fix*)&self->f44, (Vector3fix*)&delta);
    Vector3fix_Normalize((const Vector3fix*)&delta, (Vector3fix*)&delta);
    int angle = fix32_Atan2(delta.x, delta.z);
    _Z21SetVecYByMode02033834P11Obj02033834i((struct Obj02033834*)self, angle);

    self->fb4 = 0x1c2;
    self->fb2 = 0x1c2;
    _Z24SetByteIfChanged02033b68P11Obj02033b68i((struct Obj02033b68*)self, 1);

    int flag = GetField0xe4IfFlag0x40((struct BitFlag02033f44*)self);
    int inRange = 0;
    if (flag != 0) {
        int v = self->fae;
        if (func_020322c0(flag, &v, v) < 0x199) {
            inRange = 1;
        }
    }
    if (inRange) {
        _Z18TrySetMode02076cccPvi(self, 1);
        self->f154 = 0;
        if (CheckField0NonZero((int*)g)) {
            func_020794f8(self, 0, 0);
        }
        return;
    }

    unsigned short index = self->f166;
    if (((struct CombatantLayout02077788*)combatant)->flags & 0x1000) {
        index = 0;
    }
    if (CheckField0NonZero((int*)g) && index != GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)g)) {
        goto L204;
    }

    Vector3fix pos2 = func_020341e0(combatant);
    int radius = ((Object3D*)combatant)->GetRadius();
    int sb = ((Object3D*)self)->GetScale().x * 15;
    int v2 = _Z28GetField0x8OrDefault02077a20P13Outer02077a20((struct Outer02077a20*)self) >> 1;
    long long prod = (long long)v2 * sb;
    int r4 = (radius >> 1) + (int)((prod + 0x800) >> 12);
    int dist = Vector3fix_Distance((const Vector3fix*)&pos2, (const Vector3fix*)&self->f44);
    if ((dist != 0 && r4 > dist) || dist > 0x7800) {
        _Z18TrySetMode02076cccPvi(self, 1);
        self->f154 = 0;
        self->f17b = 1;
        if (CheckField0NonZero((int*)g)) {
            func_020794f8(self, 1, 0);
        }
        return;
    }

L204:
    if (CheckField0NonZero((int*)g) && GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)g) != 0) {
        return;
    }
    if (((struct CombatantLayout02077788*)combatant)->kind == 6 ||
        GetIntField0x264(battleStruct->GetProtagonist()) == 2) {
        _Z18TrySetMode02076cccPvi(self, 1);
        self->f154 = 0;
        if (CheckField0NonZero((int*)g) && GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)g) == 0) {
            func_020794f8(self, 0, 0);
        }
    }
}
