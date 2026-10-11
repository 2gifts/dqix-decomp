#include <globaldefs.h>
#if defined(jpn)
enum { kRegion731 = 0x62d };
enum { kRegion733 = 0x62f };
enum { kRegion738 = 0x634 };
#else
enum { kRegion731 = 0x731 };
enum { kRegion733 = 0x733 };
enum { kRegion738 = 0x738 };
#endif
#include "GameState/GameState.h"

struct Element0202bad4;
struct ElementArray0202bad4;

extern "C" void* func_0202ae18(void);
extern "C" void func_0202b0f4(void* ptr);
extern "C" int func_ov003_02171d78(void* list, unsigned char* key);
int GetField0xc(void* obj);
struct Element0202bad4* GetElementAt0x10Stride0xc0(struct ElementArray0202bad4* base, int index);
extern "C" int _Z29StartBattleTransition0202b840Pii(int* state, int id);

struct Name0217193c { unsigned char data[0x14]; };
struct Key0217193c { unsigned char data[6]; };

struct Flags0217193c {
    unsigned char low : 3;
    unsigned char available : 1;
    unsigned char remember : 1;
    unsigned char bit5 : 1;
    unsigned char team : 1;
    unsigned char bit7 : 1;
};

struct Entry0217193c {
    char pad0[0x50];
    Name0217193c name;
    unsigned char field64;
    Flags0217193c flags;
    unsigned short field66;
    Key0217193c key;
    char pad6e[2];
    int field70;
};

struct Obj0217193c {
    unsigned char state;
    char pad1[3];
    unsigned int timer;
    char pad8[0x199 - 8];
    signed char selected;
    char pad19a[2];
    Name0217193c name;
    unsigned char field1b0;
    Flags0217193c flags;
    unsigned short field1b2;
    Key0217193c key;
    char pad1ba[2];
    int field1bc;
    char pad1c0[kRegion731 - 0x1c0];
    signed char retries;
    signed char attempts;
    char pad733[kRegion738 - kRegion733];
    int field738;
};

// JPN: func_ov003_02170c88
// USA: func_ov003_0217193c
extern "C" ARM void func_ov003_0217193c(struct Obj0217193c* obj) {
    Entry0217193c* entry;
    GameState* battle;
    void* search;
    unsigned int dt;
    unsigned int count;
    int found;
    unsigned int i;

    battle = GameState::GetInstance();
    search = func_0202ae18();
    dt = battle->GetEffectiveDeltaTime();

    if (dt < obj->timer && obj->attempts > 0) {
        obj->timer -= dt;
        count = GetField0xc(search);
        if (count == 0) return;
        found = 0;
        for (i = 0; i < count; i++) {
            entry = (Entry0217193c*)GetElementAt0x10Stride0xc0((struct ElementArray0202bad4*)search, i);
            if (func_ov003_02171d78(obj, entry->key.data) == 0 && entry->flags.available) {
#if !defined(jpn)
                if (found > 0 && obj->flags.team != entry->flags.team) break;
#endif
                _Z29StartBattleTransition0202b840Pii((int*)search, i);
                obj->selected = 0;
#if !defined(jpn)
                obj->name = entry->name;
                obj->field1b0 = entry->field64;
                obj->flags = entry->flags;
                obj->field1b2 = entry->field66;
                obj->key = entry->key;
                obj->field1bc = entry->field70;
#endif
                obj->state = 6;
                found++;
            } else if (entry->flags.remember) {
                obj->field738 = entry->field70;
            }
        }
        if (found <= 0) return;
        obj->timer = 0;
        obj->attempts = obj->attempts - 1;
    } else {
        obj->timer = 0;
        func_0202b0f4(search);
        obj->retries--;
        if (obj->retries > 0) {
            obj->state = 0;
        } else {
            obj->state = 8;
        }
    }
}
