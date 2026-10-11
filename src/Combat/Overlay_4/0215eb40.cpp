#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

struct PageEntry {
    unsigned char bytes[0x15];
    unsigned char count;
};

struct Page {
    struct PageEntry entries[26];
    unsigned char pad;
    unsigned char total;
    unsigned char maxIdx;
    unsigned char odd;
};

struct Ctx0209a348 { void* field0; void* field4; };
struct Pair0209a338 { int a; int b; };
struct IntField0x4_0209a670 { char pad[4]; int field; };

struct ListEntry {
    unsigned short key : 11;
    unsigned short pad0 : 5;
    unsigned short mode;
    unsigned int flags;
    unsigned int pad;
};

struct GetList0209a654 { struct ListEntry* entries; int count; };

struct Element020de650 {
    unsigned int v[3];
    unsigned char pad[8];
    unsigned short v5;
};

struct Container020dedd0;

struct Slots020d { unsigned char pad[0x454]; short slots[8]; };
struct Field150 { unsigned char pad[0x464]; unsigned char key[0x20]; };

extern struct Page data_ov004_02170b90[] __attribute__((aligned(4)));
extern unsigned char data_ov004_021707e8;
extern unsigned char data_ov004_0216fdd0[];
extern char data_0212633c[];

extern "C" void _Z26ClearFirstTwoWords0209a338P12Pair0209a338(struct Pair0209a338*);
extern "C" void _Z33SetupAndRunBufferedScript0209a348P11Ctx0209a348Pv(struct Ctx0209a348*, void*);
extern "C" int _Z11GetIntAt0x4P20IntField0x4_0209a670(struct IntField0x4_0209a670*);
extern "C" struct ListEntry* _Z23GetEntryByIndex0209a654P15GetList0209a654j(struct GetList0209a654*, unsigned int);
extern "C" void _Z18SetBitInArray0x8ecPhi(unsigned char*, int);
extern "C" void _Z20ClearBitInArray0x8ecPhi(unsigned char*, int);
extern "C" int _Z19TestBitInArray0x8ecPhi(unsigned char*, int);
extern "C" void _Z17GetPtrField0x2a04P9GameState(GameState*);
extern "C" void* _Z25GetCombatantWithFlag0x100P9GameStatei(GameState*, int);
extern "C" void* _Z15GetFieldAt0x150Ph(unsigned char*);
extern "C" struct Element020de650* _Z24FindElementByKey020dedd0P17Container020dedd0i(struct Container020dedd0*, int);
extern "C" void* func_ov004_0215e47c(void*, int);
extern "C" void func_ov004_0215ee90(void*);

// USA: func_ov004_0215eb40
extern "C" ARM void func_ov004_0215eb40(void* self) {
    struct Ctx0209a348 ctx;
    GameState* gs;
    unsigned char* combatant;
    unsigned char* field150;
    BackgroundLoader* loader;
    struct Container020dedd0* container;
    int k;
    int found;
    short* slots;
    int j;
    int total;
    int count;
    struct ListEntry* entry;
    unsigned char mark[2];

    func_ov004_0215ee90(data_ov004_02170b90);
    gs = GameState::GetInstance();
    combatant = (unsigned char*)_Z25GetCombatantWithFlag0x100P9GameStatei(gs, *(int*)((char*)&data_ov004_021707e8 + 0x1c));
    field150 = (unsigned char*)_Z15GetFieldAt0x150Ph(combatant);
    if (combatant == 0 || field150 == 0) {
        return;
    }
    loader = BackgroundLoader::GetInstance();
    loader->MaybeWaitIdle();
    char* script = data_0212633c;
    _Z26ClearFirstTwoWords0209a338P12Pair0209a338((struct Pair0209a338*)&ctx);
    _Z33SetupAndRunBufferedScript0209a348P11Ctx0209a348Pv(&ctx, script);
    _Z17GetPtrField0x2a04P9GameState(gs);

    container = 0;
    {
        void* node = func_ov004_0215e47c(self, 0x8d);
        if (node != 0) {
            container = (struct Container020dedd0*)(*(void*(*)(void*))(*(char***)node)[0x3a])(node);
        }
    }
    if (container == 0) {
        goto afterSlots;
    }

    for (k = 0x56f9; k <= 0x5712; k++) {
        found = 0;
        slots = ((struct Slots020d*)*(void**)((char*)combatant + 0x150))->slots;
        for (j = 0; j < 8; j++) {
            if (slots[j] == k) {
                found = 1;
                break;
            }
        }
        struct Element020de650* elem = _Z24FindElementByKey020dedd0P17Container020dedd0i(container, (short)k);
        if (elem == 0) {
            continue;
        }
        if (((elem->v[2] << 23) >> 27) != 0x1f) {
            continue;
        }
        if (found) {
            _Z18SetBitInArray0x8ecPhi(field150, elem->v5);
        } else {
            _Z20ClearBitInArray0x8ecPhi(field150, elem->v5);
        }
    }

afterSlots:
    mark[0] = data_ov004_0216fdd0[0];
    mark[1] = data_ov004_0216fdd0[1];
    total = _Z11GetIntAt0x4P20IntField0x4_0209a670((struct IntField0x4_0209a670*)&ctx);
    entry = _Z23GetEntryByIndex0209a654P15GetList0209a654j((struct GetList0209a654*)&ctx, 0);
    for (count = 0; count < total; entry++, count++) {
        int idx = (signed char)((entry->flags << 27) >> 27);
        int slot = (signed char)(idx - 1);
        if (slot < 0) {
            continue;
        }
        unsigned short save = entry->key;
        bool ok = _Z19TestBitInArray0x8ecPhi(field150, save);
        if (!ok) {
            continue;
        }
        unsigned char v = (unsigned char)((entry->flags << 20) >> 25);
        unsigned char curKey = ((struct Field150*)field150)->key[idx];
        int which = -1;
        if ((int)entry->mode > 0) {
            which = 0;
        } else if (entry->mode == 0) {
            if (curKey >= v) {
                which = 1;
            }
        }
        if (which == -1) {
            continue;
        }

        struct Page* page = &data_ov004_02170b90[which];
        unsigned char val = v ? v : 0x6e;
        struct PageEntry* base = &page->entries[slot];
        char* cur = (char*)base;
        unsigned char* p = (unsigned char*)base + 0xe;
        unsigned char n = base->count;
        int i = 0;
        while (i < n) {
            if (val < *p) {
                break;
            }
            i++;
            cur += 2;
            p++;
        }
        int rest = n - i;
        if (rest > 0) {
            memmove(cur + 2, cur, rest * 2);
            memmove(p + 1, p, rest);
        }
        *(unsigned short*)cur = save;
        *p = val;
        base->count = base->count + 1;
        if ((signed char)mark[which] == slot) {
            continue;
        }
        mark[which] = slot;
        page->total = page->total + 1;
        if (page->total & 1) {
            page->odd = page->odd + 1;
        }
        if (page->maxIdx < idx) {
            page->maxIdx = idx;
        }
    }

    loader->RemoveLock();
}
