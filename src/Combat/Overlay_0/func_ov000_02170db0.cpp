#include <globaldefs.h>
#include "GameState/GameState.h"

struct CombatantExt02170db0 {
    char pad0[0x94c];
    int field94c;
};

struct Container020e0310;
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);
struct CombatantExt02170db0* GetFieldAt0x150(unsigned char* obj);

struct Obj0203c108 {
    char pad0[0x10];
    int dirty;
    short idx;
};
extern "C" void _Z23SwapGlobalEntry0203c108P11Obj0203c108Pc(struct Obj0203c108* obj, char* fmt);

extern "C" void __clear(void* buf, int count);

struct Obj02170db0 {
    char pad0[4];
    struct Container020e0310* container;
    char pad8[0x1c - 0x8];
    signed char kind;
    char pad1d[0x26 - 0x1d];
    unsigned short entryKey;
    char pad28[0x2c - 0x28];
    short itemId;
    char pad2e[0x4c - 0x2e];
    int combatantId;
    struct Obj0203c108 label;
};

struct Entry02170cf8 {
    void* text;
};

struct Equipment02171d90 {
    char pad0[4];
    void* text;
    char pad8[0x18 - 0x8];
    short count;
};

extern "C" struct Entry02170cf8* func_ov000_02170cf8(struct Obj02170db0* obj, int val);
extern "C" struct Equipment02171d90* func_ov000_02171d90(struct Obj02170db0* obj, int itemId);
extern "C" int _Z29HasAnyFlags_021719f8_021719f8Pi(int* obj);
extern "C" int func_ov000_02171a74(struct Obj02170db0* obj, char* buf);
extern "C" void func_020e4864(void* src, char* dst, int a, int b, int c, int d);
void CopyTextAndUppercaseIfFlagged0206819c(const char* src, char* dst, int flag);
int GetGlobalField0x1c020421a0(void);
extern "C" void func_02046608(int messages, int mode, char* input, char* output, int size, int a, int b);
extern "C" void func_ov000_0217616c(struct Obj02170db0* obj);

extern char data_ov000_02183ff4[];

// USA: func_ov000_02170db0
extern "C" ARM void func_ov000_02170db0(struct Obj02170db0* obj) {
    struct Entry02170cf8* entry = func_ov000_02170cf8(obj, obj->entryKey);
    struct Equipment02171d90* equip = func_ov000_02171d90(obj, obj->itemId);
    GameObject* c = GetCombatantWithFlag0x100(GameState::GetInstance(), obj->combatantId);
    if (c == NULL) {
        return;
    }
    struct CombatantExt02170db0* ext = GetFieldAt0x150((unsigned char*)c);
    obj->label.dirty = 1;
    if (_Z29HasAnyFlags_021719f8_021719f8Pi((int*)obj)) {
        char buf[0x80];
        __clear(buf, sizeof(buf));
        if (func_ov000_02171a74(obj, buf) >= 0) {
            _Z23SwapGlobalEntry0203c108P11Obj0203c108Pc(&obj->label, buf);
        }
    } else if (ext != NULL && (signed char)ext->field94c != 5 && obj->kind != 6) {
        char* text = (char*)_Z21GetFieldByKey020e0434P17Container020e0310i(obj->container, (short)((signed char)ext->field94c + 0x753e));
        if (text != NULL) {
            _Z23SwapGlobalEntry0203c108P11Obj0203c108Pc(&obj->label, text);
        } else {
            _Z23SwapGlobalEntry0203c108P11Obj0203c108Pc(&obj->label, data_ov000_02183ff4);
        }
    } else if (entry != NULL) {
        char raw[0x80];
        char name[0x80];
        __clear(raw, sizeof(raw));
        __clear(name, sizeof(name));
        func_020e4864(entry->text, raw, 1, 0, 0, 0);
        CopyTextAndUppercaseIfFlagged0206819c(raw, name, 0);
        _Z23SwapGlobalEntry0203c108P11Obj0203c108Pc(&obj->label, name);
    } else if (equip != NULL) {
        if (equip->count > 0) {
            char raw[0x80];
            char name[0x80];
            __clear(raw, sizeof(raw));
            __clear(name, sizeof(name));
            func_020e4864(equip->text, raw, 1, 0, 0, 0);
            CopyTextAndUppercaseIfFlagged0206819c(raw, name, 0);
            func_02046608(GetGlobalField0x1c020421a0(), 10, name, raw, 0x100, 0, 0);
            _Z23SwapGlobalEntry0203c108P11Obj0203c108Pc(&obj->label, raw);
        }
    } else if (obj->kind == 6) {
        _Z23SwapGlobalEntry0203c108P11Obj0203c108Pc(&obj->label, (char*)_Z21GetFieldByKey020e0434P17Container020e0310i(obj->container, 0x7531));
    } else {
        _Z23SwapGlobalEntry0203c108P11Obj0203c108Pc(&obj->label, data_ov000_02183ff4);
    }
    func_ov000_0217616c(obj);
}
