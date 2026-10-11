#include <globaldefs.h>
#include "GameState/GameState.h"

struct CombatantExt02170ffc {
#if defined(jpn)
    char pad0[0x8b4];
#else
    char pad0[0x94c];
#endif
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
#if defined(jpn)
    char pad66[0xc7 - 0x66];
#else
    char pad66[0x87 - 0x66];
#endif
    unsigned char visible;
};

extern "C" int _Z29HasAnyFlags_021719f8_021719f8Pi(int* obj);
#if defined(jpn)
extern "C" int func_ov000_02171a74(struct Obj02170ffc* obj);
#else
extern "C" int func_ov000_02171a74(struct Obj02170ffc* obj, char* buf);
#endif

// USA: func_ov000_02170ffc
extern "C" ARM void func_ov000_02170ffc(struct Obj02170ffc* obj) {
#if !defined(jpn)
    char buf[0x80];
#endif
    if (obj->flags & 2) {
        return;
    }
    if (obj->visible == 0) {
        return;
    }
    if (_Z29HasAnyFlags_021719f8_021719f8Pi((int*)obj)) {
#if defined(jpn)
        int key = func_ov000_02171a74(obj);
        struct Container020e0310* container = obj->container;
        if (container != NULL && key >= 0) {
            _Z23SwapGlobalEntry0203c108P11Obj0203c108Pc(&obj->label, (char*)_Z21GetFieldByKey020e0434P17Container020e0310i(container, key));
            return;
        }
#else
        __clear(buf, sizeof(buf));
        if (func_ov000_02171a74(obj, buf) >= 0) {
            _Z23SwapGlobalEntry0203c108P11Obj0203c108Pc(&obj->label, buf);
            return;
        }
#endif
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
