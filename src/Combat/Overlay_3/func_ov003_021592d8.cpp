#include <globaldefs.h>
#if defined(jpn)
enum { kVocationEnd = 0x8b8 };
extern "C" void func_020474a8(void*, int, const char*, char*);
#else
enum { kVocationEnd = 0x950 };
#endif
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"

struct VocationData021592d8 {
    char pad0[0x138];
    int exp[0xd];
    unsigned short levels[0xd];
    char pad186[kVocationEnd - 0x186];
    int vocation;
};

struct Combatant021592d8 {
    char pad0[4];
    short id;
#if defined(jpn)
    char pad6[0x134 - 6];
    char* name;
#endif
};

struct MessageWork021592d8 {
    char pad0[0x10];
    void* subject;
};

struct LevelEntry021592d8 {
    int exp;
    char pad4[0x54 - 4];
};

struct UnitObj021592d8 {
    char data[0xc];
};

struct Container020e0310;
struct Obj02046574;
struct StoreStruct;

struct BattleMenu021592d8 {
    char pad0[0x64];
    char messages[0x18];
};

extern "C" struct MessageWork021592d8* _Z26GetGlobalField0x1c020421a0v();
struct VocationData021592d8* GetFieldAt0x150(unsigned char* obj);
extern "C" void func_02046380(void* obj);
extern "C" void _Z30InitObjFromCombatantId020e4bf4Pvi(void* obj, int combatantId);
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(struct Obj02046574* obj, int index, char* str);
extern "C" void* _Z22Clear0x54Bytes0208247cPv(void* obj);
extern "C" int func_02082490(void* output, void* resource, unsigned int size, int selection, int extra);
void StoreInArray0x8b0(struct StoreStruct* base, int index, int value);
void SetByteInRange(unsigned char* base, int index, unsigned char value);
extern "C" void func_02046608(void* messages, int a, const char* input, char* output, int b, int c, int d);

extern char data_ov003_0217fe18[];
extern unsigned char data_0211e33c[0x30000];

// JPN: func_ov003_0215a7c0
// USA: func_ov003_021592d8
extern "C" ARM void func_ov003_021592d8(struct BattleMenu021592d8* self, struct Combatant021592d8* combatant,
                                        char* out) {
    if (out == NULL || combatant == NULL) {
        return;
    }
    struct MessageWork021592d8* work = _Z26GetGlobalField0x1c020421a0v();
    struct VocationData021592d8* data = GetFieldAt0x150((unsigned char*)combatant);
    int vocation = data->vocation;
    func_02046380(work);
#if defined(jpn)
    _Z22SetIndexedName02046574P11Obj02046574iPc((struct Obj02046574*)work, 0, combatant->name);
#else
    struct UnitObj021592d8 unit;
    _Z30InitObjFromCombatantId020e4bf4Pvi(&unit, combatant->id);
    work->subject = &unit;
#endif
    int key;
    if (data->levels[vocation] == 99) {
        _Z22SetIndexedName02046574P11Obj02046574iPc((struct Obj02046574*)work, 1,
                               (char*)_Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)self->messages,
                                                            (short)(data->vocation + 0x1e)));
        key = 0x3fe;
    } else {
        char path[0x28];
        unsigned int size;
        sprintf(path, data_ov003_0217fe18, data->vocation);
        BackgroundLoader::AddLockGlobal();
        void* file = LoadFileIntoMemory(path, data_0211e33c, &size);
        struct LevelEntry021592d8 next;
        _Z22Clear0x54Bytes0208247cPv(&next);
        if (file != NULL) {
            func_02082490(&next, file, size, data->levels[vocation] + 1, 0);
        }
        struct LevelEntry021592d8* entry = &next;
        int remaining = 0;
        if (entry != NULL) {
            remaining = entry->exp - data->exp[vocation];
        }
        if (remaining > 0) {
            StoreInArray0x8b0((struct StoreStruct*)work, 0, remaining);
            SetByteInRange((unsigned char*)work, 0, 0);
            key = 0x3fd;
        } else {
            key = 0x3ff;
        }
        BackgroundLoader::RemoveLockGlobal();
    }
#if defined(jpn)
    func_020474a8(work, 0xc, (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)self->messages, key), out);
#else
    func_02046608(work, 0xc, (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)self->messages, key), out,
                  0xe3, 0, 1);
#endif
}
