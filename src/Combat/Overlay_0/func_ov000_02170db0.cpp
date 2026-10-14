#include <globaldefs.h>
#include "GameState/GameState.h"
#if defined(jpn)
#define data_ov000_02183ff4 data_ov000_02185118
#endif

struct CombatantExt02170db0 {
    #if defined(jpn)
    char pad0[0x8b4];
#else
    char pad0[0x94c];
#endif
    int field94c;
};

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
struct CombatantExt02170db0* GetFieldAt0x150(unsigned char* obj);

struct Obj0203c108 {
    #if defined(jpn)
    char pad0[0x2c];
#else
    char pad0[0x10];
#endif
    int dirty;
    short idx;
};
void SwapGlobalEntry0203c108(struct Obj0203c108* obj, char* fmt);

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
int HasAnyFlags_021719f8_021719f8(int* obj);
#if defined(jpn)
extern "C" int func_ov000_02171a74(struct Obj02170db0* obj);
#else
extern "C" int func_ov000_02171a74(struct Obj02170db0* obj, char* buf);
#endif
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
    if (HasAnyFlags_021719f8_021719f8((int*)obj)) {
#if defined(jpn)
        char* text = (char*)GetFieldByKey020e0434(obj->container, func_ov000_02171a74(obj));
        if (text != NULL) {
            SwapGlobalEntry0203c108(&obj->label, text);
        }
#else
        char buf[0x80];
        __clear(buf, sizeof(buf));
        if (func_ov000_02171a74(obj, buf) >= 0) {
            SwapGlobalEntry0203c108(&obj->label, buf);
        }
#endif
    } else if (ext != NULL && (signed char)ext->field94c != 5 && obj->kind != 6) {
        char* text = (char*)GetFieldByKey020e0434(obj->container, (short)((signed char)ext->field94c + 0x753e));
        if (text != NULL) {
            SwapGlobalEntry0203c108(&obj->label, text);
        } else {
            SwapGlobalEntry0203c108(&obj->label, data_ov000_02183ff4);
        }
    } else if (entry != NULL) {
#if defined(jpn)
        SwapGlobalEntry0203c108(&obj->label, (char*)entry->text);
#else
        char raw[0x80];
        char name[0x80];
        __clear(raw, sizeof(raw));
        __clear(name, sizeof(name));
        func_020e4864(entry->text, raw, 1, 0, 0, 0);
        CopyTextAndUppercaseIfFlagged0206819c(raw, name, 0);
        SwapGlobalEntry0203c108(&obj->label, name);
#endif
    } else if (equip != NULL) {
        if (equip->count > 0) {
#if defined(jpn)
            SwapGlobalEntry0203c108(&obj->label, (char*)equip->text);
#else
            char raw[0x80];
            char name[0x80];
            __clear(raw, sizeof(raw));
            __clear(name, sizeof(name));
            func_020e4864(equip->text, raw, 1, 0, 0, 0);
            CopyTextAndUppercaseIfFlagged0206819c(raw, name, 0);
            func_02046608(GetGlobalField0x1c020421a0(), 10, name, raw, 0x100, 0, 0);
            SwapGlobalEntry0203c108(&obj->label, raw);
#endif
        }
    } else if (obj->kind == 6) {
        SwapGlobalEntry0203c108(&obj->label, (char*)GetFieldByKey020e0434(obj->container, 0x7531));
    } else {
        SwapGlobalEntry0203c108(&obj->label, data_ov000_02183ff4);
    }
    func_ov000_0217616c(obj);
}
