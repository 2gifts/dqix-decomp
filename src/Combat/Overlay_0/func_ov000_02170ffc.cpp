#include <globaldefs.h>
#include "GameState/GameState.h"

struct CombatantExt02170ffc {
    char pad0[0x94c];
    int field94c;
};

struct Container020e0310;
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);
struct CombatantExt02170ffc* GetFieldAt0x150(unsigned char* obj);

struct Obj0203c108 {
    char pad[0x14];
    short idx;
};
extern "C" void _Z23SwapGlobalEntry0203c108P11Obj0203c108Pc(struct Obj0203c108* obj, char* fmt);

extern "C" void __clear(void* buf, int count);

struct Obj02170ffc {
    char pad0[4];
    struct Container020e0310* container;
    char pad8[0x24 - 0x8];
    unsigned char flags;
    char pad25[0x4c - 0x25];
    int combatantId;
    struct Obj0203c108 label;
    char pad66[0x87 - 0x66];
    unsigned char visible;
};

extern "C" int _Z29HasAnyFlags_021719f8_021719f8Pi(int* obj);
extern "C" int func_ov000_02171a74(struct Obj02170ffc* obj, char* buf);

// USA: func_ov000_02170ffc
extern "C" ARM void func_ov000_02170ffc(struct Obj02170ffc* obj) {
    char buf[0x80];
    if (obj->flags & 2) {
        return;
    }
    if (obj->visible == 0) {
        return;
    }
    if (_Z29HasAnyFlags_021719f8_021719f8Pi((int*)obj)) {
        __clear(buf, sizeof(buf));
        if (func_ov000_02171a74(obj, buf) >= 0) {
            _Z23SwapGlobalEntry0203c108P11Obj0203c108Pc(&obj->label, buf);
            return;
        }
    }
    short key = 0x753e;
    GameObject* member = GameState::GetInstance()->GetPartyMemberByIndex(obj->combatantId);
    if (member == NULL) {
        return;
    }
    struct CombatantExt02170ffc* ext = GetFieldAt0x150((unsigned char*)member);
    key += (signed char)ext->field94c;
    _Z23SwapGlobalEntry0203c108P11Obj0203c108Pc(&obj->label, (char*)_Z21GetFieldByKey020e0434P17Container020e0310i(obj->container, key));
}
