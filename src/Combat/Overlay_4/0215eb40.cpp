#include <globaldefs.h>
#if defined(jpn)
#define _Z33SetupAndRunBufferedScript0209a348P11Ctx0209a348Pv func_0209c09c
#define _Z20ClearBitInArray0x8ecPhi func_02084434
#define _Z11GetIntAt0x4P20IntField0x4_0209a670 func_0209c3c4
#define data_0212633c data_02127b64
#define data_ov004_0216fdd0 data_ov004_02170554
#endif
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

struct PageEntry {
    unsigned short keys[7];
    unsigned char values[7];
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
#if defined(jpn)
    unsigned short key : 12;
    unsigned short pad0 : 4;
#else
    unsigned short key : 11;
    unsigned short pad0 : 5;
#endif
    unsigned short mode;
    unsigned int category : 5;
    unsigned int threshold : 7;
    unsigned int remainingFlags : 20;
    unsigned int pad;
};

struct GetList0209a654 { struct ListEntry* entries; int count; };

struct Element020de650 {
    unsigned int word0;
    unsigned int word4;
    unsigned int lowFlags : 4;
    unsigned int kind : 5;
    unsigned int highFlags : 23;
    unsigned char pad[8];
    unsigned short v5;
};

struct Container020dedd0;

class ScriptContainerNode {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57();
    virtual Container020dedd0* GetContainer();
};

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
        ScriptContainerNode* node = (ScriptContainerNode*)func_ov004_0215e47c(self, 0x8d);
        if (node != 0) {
            container = node->GetContainer();
        }
    }
    if (container == 0) {
        goto afterSlots;
    }

    for (k = 0x56f9; k <= 0x5712; k++) {
        found = 0;
        slots = ((struct Slots020d*)*(void**)((char*)combatant
#if defined(jpn)
            + 0x144))->slots;
#else
            + 0x150))->slots;
#endif
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
        if (elem->kind != 0x1f) {
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
        signed char idx = entry->category;
        int slot = (signed char)(idx - 1);
        if (slot < 0) {
            continue;
        }
        unsigned short save = entry->key;
        bool ok = _Z19TestBitInArray0x8ecPhi(field150, save);
        if (!ok) {
            continue;
        }
        unsigned char v = entry->threshold;
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
        unsigned short* keys = base->keys;
        unsigned char* values = base->values;
        unsigned char n = base->count;
        int i = 0;
        while (i < n) {
            if (val < *values) {
                break;
            }
            i++;
            keys++;
            values++;
        }
        int rest = n - i;
        if (rest > 0) {
            memmove(keys + 1, keys, rest * sizeof(*keys));
            memmove(values + 1, values, rest);
        }
        *keys = save;
        *values = val;
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
