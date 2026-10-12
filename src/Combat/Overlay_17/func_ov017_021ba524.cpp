#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Script.h"

struct PackedNibbleArray0206e120;
struct PackedNibbleArray0206e260;
struct PackedNibbleArray0206e2dc;
int GetPackedNibbleField(PackedNibbleArray0206e120* obj, int index);
int GetPackedNibbleFlag0x4(PackedNibbleArray0206e260* obj, int index);
int GetPackedNibbleFlag0x8(PackedNibbleArray0206e2dc* obj, int index);

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* p);
extern "C" void* func_0205ec34(void);
extern "C" int func_ov017_021b9bcc(int id, const char* name);

static inline int NibbleIs(PackedNibbleArray0206e120* nibbles, int slot, int value) {
    return GetPackedNibbleField(nibbles, slot) == value;
}

struct Struct0130_021ba524 {
    char pad0[4];
    unsigned short half4;
};

struct Data_ov017_021d8438 {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char pad3;
    int field4;
    unsigned char pad8[8];
    int field10;
};
extern struct Data_ov017_021d8438 data_ov017_021d8438;

struct Data_ov017_021d7c54 {
    signed char byte0;
    signed char byte1;
};
extern struct Data_ov017_021d7c54 data_ov017_021d7c54;

// USA: func_ov017_021ba524
extern "C" ARM int func_ov017_021ba524(Script::Parameter* params, int count) {
    if (data_ov017_021d8438.field10 != 0) return 1;

    GameState* battle = GameState::GetInstance();
    if (func_0202c540(func_0202ae18()) != 0) return 1;

    GameObject* leader = battle->GetGameObjectByIndex(0);
    struct Struct0130_021ba524* p = *(struct Struct0130_021ba524**)((char*)leader + 0x130);
    int pending = p->half4;
    if (pending > 0) return 1;

    PackedNibbleArray0206e120* nibbles = (PackedNibbleArray0206e120*)func_0205ec34();
    int slot = params[0].ToInt();
    int cur = data_ov017_021d7c54.byte0;
    if (cur != slot && cur > -1) {
        if (NibbleIs(nibbles, slot, 1) || NibbleIs(nibbles, slot, 2) ||
            (NibbleIs(nibbles, data_ov017_021d7c54.byte0, 3) && NibbleIs(nibbles, slot, 3) &&
             data_ov017_021d7c54.byte0 <= slot)) {
        } else {
            return 1;
        }
    }

    Script::Parameter* modeParam = &params[1];
    params = &params[2];
    switch (modeParam->ToInt()) {
    case -1:
        if (!NibbleIs(nibbles, slot, 0)) return 1;
        break;
    case 0:
        if (!NibbleIs(nibbles, slot, 2)) return 1;
        break;
    case 1:
        if (!GetPackedNibbleFlag0x4((PackedNibbleArray0206e260*)nibbles, slot)) return 1;
        break;
    case 2:
        if (!NibbleIs(nibbles, slot, 3)) return 1;
        break;
    case 3:
        if (!NibbleIs(nibbles, slot, 1)) return 1;
        break;
    case 4:
        if (GetPackedNibbleFlag0x8((PackedNibbleArray0206e2dc*)nibbles, slot) && NibbleIs(nibbles, slot, 0)) {
        } else {
            return 1;
        }
        break;
    }

    if (count >= 5) {
        int daytimeOnly = params->ToInt();
        params++;
        if (daytimeOnly != 0) {
            if (GameState::GetInstance()->IsMorningDayOrEvening()) return 1;
            data_ov017_021d8438.byte2 = 1;
        }
    } else {
        if (data_ov017_021d8438.byte2 != 0) return 0;
    }

    int id = params[0].ToInt();
    const char* name = params[1].ToString();
    if (name == 0) return 0;
    if (func_ov017_021b9bcc(id, name) != 0) data_ov017_021d7c54.byte0 = slot;
    return 1;
}
