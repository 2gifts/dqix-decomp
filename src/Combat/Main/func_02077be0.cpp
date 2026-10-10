#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3 {
    int x;
    int y;
    int z;
};

struct Outer02077a20;
extern "C" int _Z28GetField0x8OrDefault02077a20P13Outer02077a20(struct Outer02077a20* p);

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);

struct BitFlag02033f44;
extern "C" int* _Z22GetField0xe4IfFlag0x40P15BitFlag02033f44(struct BitFlag02033f44* self);

extern "C" void _Z18TrySetMode02076cccPvi(void* self, int mode);
extern "C" void func_020794f8(void* self, int a, int b);

int CheckField0NonZero(int* obj);

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c508(void* obj);
extern "C" int func_020322c0(void* p, int* v);
extern "C" struct Vec3 func_02034104(GameObject* combatant);

struct Obj02033834;
extern "C" void _Z21SetVecYByMode02033834P11Obj02033834i(struct Obj02033834* obj, int arg);

struct Obj02033b68;
extern "C" void _Z24SetByteIfChanged02033b68P11Obj02033b68i(struct Obj02033b68* obj, int newVal);

struct Entity02077be0 {
    char pad0[0x44];
    struct Vec3 f44;
    char pad50[0xae - 0x50];
    short fae;
    char padb0[0xb2 - 0xb0];
    short fb2;
    short fb4;
    char padb6[0x154 - 0xb6];
    int f154;
    struct Vec3 f158;
    char pad164[0x166 - 0x164];
    unsigned short f166;
    char pad168[0x17b - 0x168];
    unsigned char f17b;
};

// USA: func_02077be0
extern "C" ARM void func_02077be0(struct Entity02077be0* self) {
    GameState* battleStruct = GameState::GetInstance();
    void* mgr = func_0202ae18();
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(self->f166);
    if (combatant == NULL) {
        return;
    }

    struct Vec3 pos44 = self->f44;
    pos44.y = 0;
    int flag = 0;
    struct Vec3 pos158 = self->f158;
    pos158.y = 0;
    struct Vec3 delta;
    Vector3fix_Subtract((const Vector3fix*)&pos158, (const Vector3fix*)&pos44, (Vector3fix*)&delta);
    Vector3fix_Normalize((const Vector3fix*)&delta, (Vector3fix*)&delta);
    int angle = fix32_Atan2(delta.x, delta.z);
    _Z21SetVecYByMode02033834P11Obj02033834i((struct Obj02033834*)self, angle);
    self->fb4 = 0x1c2;
    self->fb2 = 0x1c2;
    _Z24SetByteIfChanged02033b68P11Obj02033b68i((struct Obj02033b68*)self, 1);

    int* p = _Z22GetField0xe4IfFlag0x40P15BitFlag02033f44((struct BitFlag02033f44*)self);
    if (p != NULL) {
        int v = self->fae;
        if (func_020322c0(p, &v) < 0x199) {
            flag = 1;
        }
    }

    if (flag != 0) {
        _Z18TrySetMode02076cccPvi(self, 1);
        self->f154 = 0;
        if (CheckField0NonZero((int*)mgr) == 0) {
            return;
        }
        func_020794f8(self, 0, 0);
        return;
    }

    int dist = Vector3fix_Distance((const Vector3fix*)&pos44, (const Vector3fix*)&pos158);
    unsigned short id = self->f166;
    if (combatant->obj3D_.unknown_0_ & 0x1000) {
        id = 0;
    }

    if (CheckField0NonZero((int*)mgr) == 0 ||
        id == GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)mgr)) {
        struct Vec3 posCopy = func_02034104(combatant);
        int radius = combatant->obj3D_.GetRadius();
        int scale15 = ((Object3D*)self)->GetScale().x * 15;
        int half = _Z28GetField0x8OrDefault02077a20P13Outer02077a20((struct Outer02077a20*)self) >> 1;
        int threshold = (int)(((long long)half * scale15 + 0x800) >> 12) + (radius >> 1);
        int d = Vector3fix_Distance((const Vector3fix*)&posCopy, (const Vector3fix*)&self->f44);
        if (d != 0 && threshold > d) {
            _Z18TrySetMode02076cccPvi(self, 1);
            self->f154 = 0;
            self->f17b = 1;
            if (CheckField0NonZero((int*)mgr) != 0) {
                func_020794f8(self, 1, 0);
            }
            return;
        }
    }

    if (CheckField0NonZero((int*)mgr) != 0 &&
        GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)mgr) != 0) {
        return;
    }
    if (dist >= 0x1800 && self->f17b == 0) {
        return;
    }
    _Z18TrySetMode02076cccPvi(self, 1);
    self->f154 = 0;
    if (CheckField0NonZero((int*)mgr) == 0) {
        return;
    }
    if (func_0202c508(mgr) == 0) {
        return;
    }
    func_020794f8(self, 0, 0);
}
