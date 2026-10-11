#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "Memory/SignedAllocator.h"
#include "GameState/GameState.h"

struct Container020dedd0;
struct Element020de650;
struct Obj02061bd8;
struct Slots02083960;

struct Obj0207d200 {
    char pad[0x2c];
    struct Container020dedd0* container;
};

struct Element020de650 {
    char pad[8];
    unsigned int type : 4;
    unsigned int unk4 : 21;
    unsigned int flag25 : 1;
};

extern "C" extern struct Element020de650* _Z24FindElementByKey020dedd0P17Container020dedd0i(struct Container020dedd0* c, int key);
extern "C" extern void* _Z35InitAllocatorAndLoadGp2File0207d6dcP13SafeAllocatorii(SafeAllocator* self, int param1, int param2);
extern void* GetPtrField0x2a04(GameState* battleStruct);
extern GameObject* GetCombatantWithFlag0x100(GameState* gameState, int combatantId);
extern int CheckField0x56bLowNibble(struct Obj02061bd8* obj);
extern unsigned char* GetFieldAt0x150(unsigned char* obj);
extern "C" extern int _Z26CountPositiveSlots02083960P13Slots02083960(struct Slots02083960* slots);
extern "C" int func_0207ccf0(struct Obj0207d200* self, int key, int one, int id, int zero0, int zero1, int zero2);
extern "C" int func_0207cf30(struct Obj0207d200* self, int key, int count, int zero);
extern "C" void func_0207d134(struct Obj0207d200* self, int key, int count);
extern "C" extern int _Z22UpdateKeyValue0207d200P11Obj0207d200si(struct Obj0207d200* self, short key, int amount);
extern "C" extern void _Z19TailForward02012da4P14AllocatorUnionPv(AllocatorUnion* alloc, void* data);
extern AllocatorUnion data_02114e20;

static inline int IsLow(struct Element020de650* e) {
    return e->type <= 7;
}

// USA: func_0207d300
extern "C" ARM int func_0207d300(struct Obj0207d200* self, short key, short count, int flag) {
    int initDone = 0;
    if (self->container == NULL) {
        _Z35InitAllocatorAndLoadGp2File0207d6dcP13SafeAllocatorii((SafeAllocator*)self, (int)&key, 1);
        initDone = 1;
    }
    int result = -1;
    struct Element020de650* elem = _Z24FindElementByKey020dedd0P17Container020dedd0i(self->container, key);
    if (elem == NULL) {
        result = -2;
    } else if (IsLow(elem) != 0) {
        func_0207d134(self, key, count);
        result = 3;
    } else if (elem->type == 9) {
        _Z22UpdateKeyValue0207d200P11Obj0207d200si(self, key, count);
        result = 5;
    } else if (elem->flag25) {
        if (func_0207cf30(self, key, count, 0) != 0) {
            result = 2;
        }
    } else {
        GameState* bs = GameState::GetInstance();
        char* p = (char*)GetPtrField0x2a04(bs);
        unsigned char i;
        for (i = 0; i < *(unsigned char*)(p + 0xf7c); i++) {
            int id = *(signed char*)(p + i + 0xf78);
            GameObject* c = GetCombatantWithFlag0x100(bs, id);
            if (c == NULL) {
                continue;
            }
            if (CheckField0x56bLowNibble((struct Obj02061bd8*)c) != 0) {
                continue;
            }
            if (flag != 0) {
                if ((int)*(unsigned short*)(*(char**)((char*)c + 0x130) + 4) <= 0) {
                    continue;
                }
                char* f138 = *(char**)((char*)c + 0x138);
                if (f138 != NULL && *(unsigned short*)f138 == 0) {
                    continue;
                }
            }
            unsigned char* slots = GetFieldAt0x150((unsigned char*)c);
            if (slots == NULL) {
                continue;
            }
            while (count != 0) {
                if (_Z26CountPositiveSlots02083960P13Slots02083960((struct Slots02083960*)slots) == 8) {
                    break;
                }
                result = func_0207ccf0(self, key, 1, id, 0, 0, 0);
                if (result != 0) {
                    break;
                }
                count = (short)(count - 1);
            }
        }
        if (count > 0) {
            if (func_0207cf30(self, key, count, 0) != 0) {
                result = 2;
            }
        }
    }
    if (initDone) {
        SafeAllocator* alloc = (SafeAllocator*)self;
        SignedAllocatorHeader* sig = alloc->GetSignedAllocator();
        alloc->Destroy();
        _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, sig);
        self->container = NULL;
    }
    return result;
}
