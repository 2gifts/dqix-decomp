#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
#include "Util/Random.h"

void* GetActiveCombatWork(void);
extern "C" int func_ov000_0215e9fc(int battle, short* ids, int max, int flags);
extern "C" int func_ov000_0215eb1c(int battle, short* ids, int count, int flag);
unsigned short GetTableValue(void* obj);
extern "C" void func_ov000_021620f0(void* work, int tier, int flag);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Buf8_021e20c0 { short v[8]; };
extern struct Buf8_021e20c0 data_ov024_021fe728;
extern unsigned char data_ov024_021fe758[4][4];

struct Flag_021e20c0 {
    unsigned char pad : 7;
    unsigned char flag : 1;
};

struct Msg_021e20c0 {
    char pad0[0x1a];
    short messageId;
};

struct Obj_021e20c0 {
    char pad0[4];
    struct Msg_021e20c0* msg;
    char pad8[0xc - 8];
    void* field0xc;
    void* field0x10;
    char pad14[0x6e - 0x14];
    unsigned char field0x6e;
};

// USA: func_ov024_021e20c0
extern "C" ARM void* func_ov024_021e20c0(struct Obj_021e20c0* obj, int unused, int id) {
    GameObject* c = GetCombatantByID((int)obj->field0x10, id);
    if (!c) return 0;
    void* work = GetActiveCombatWork();
    struct Buf8_021e20c0 buf = data_ov024_021fe728;
    int count = func_ov000_0215e9fc((int)obj->field0x10, buf.v, 4, 0);
    if (count <= 0) return 0;
    GameState* gs = GameState::GetInstance();
    unsigned short total = 0;
    for (int i = 0; i < count; i++) {
        GameObject* member = GetCombatantWithFlag0x100(gs, buf.v[i]);
        if (member) {
            total += GetTableValue(member);
        }
    }
    int tier = 0;
    if (total >= 0xc9) {
        tier = 3;
    } else if (total >= 0x79) {
        tier = 2;
    } else if (total >= 0x3d) {
        tier = 1;
    }
    unsigned char roll = NextRandomMax((struct Random*)obj->field0x10, 100);
    unsigned char* weights = data_ov024_021fe758[tier];
    unsigned char k;
    for (k = 0; k < 4; k++) {
        if (weights[k] > roll) break;
        roll -= weights[k];
    }
    if (k >= 4) k = 3;
    int found = func_ov000_0215eb1c((int)obj->field0x10, buf.v, 8, 1);
    func_ov000_021620f0(work, k, 1);
    if (found > 0) {
        if (found > 1) {
            obj->msg->messageId = 0x221;
        } else {
            obj->msg->messageId = 0x220;
        }
        obj->field0x6e = 1;
    }
    void* entry = func_ov000_0215e958(obj->field0x10);
    if (!entry) return 0;
    struct Flag_021e20c0* fl = (struct Flag_021e20c0*)((char*)obj->field0xc + 0x1c);
    func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, fl->flag != 0);
    return entry;
}
