#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "Memory/SignedAllocator.h"
#include "GameState/GameState.h"

struct Container020dedd0;
struct Element020de650;
struct Obj02061bd8;
struct Obj0207d200;

extern "C" extern struct Element020de650* _Z24FindElementByKey020dedd0P17Container020dedd0i(struct Container020dedd0* c, int key);
extern "C" extern void* _Z35InitAllocatorAndLoadGp2File0207d6dcP13SafeAllocatorii(SafeAllocator* self, int param1, int param2);
GameObject* GetCombatantWithFlag0x100(GameState* gs, int flags);
int CheckField0x56bLowNibble(struct Obj02061bd8* obj);
unsigned char* GetFieldAt0x150(unsigned char* combatant);
extern "C" int func_0207cf30(void* self, short key, int amount, unsigned char flag);
extern "C" void func_0207cc18(void* self, struct Element020de650* elem);
extern "C" int func_0207d134(void* self, short key, int amount);
extern "C" int _Z22UpdateKeyValue0207d200P11Obj0207d200si(struct Obj0207d200* self, short key, int amount);
extern "C" extern void _Z19TailForward02012da4P14AllocatorUnionPv(AllocatorUnion* alloc, void* data);
extern AllocatorUnion data_02114e20;

struct Obj0207ccf0 {
    char pad[0x2c];
    struct Container020dedd0* container;
    void* field30;
    int field34;
};

struct Entry0207ccf0 {
    char pad[4];
    void* field4;
    unsigned int type : 4, unused4 : 21, flag25 : 1, rest : 6;
};

struct Combatant0207ccf0 {
    char pad[0x134];
    int field134;
};

static inline int IsType0207ccf0(unsigned int type) { return type <= 7; }

// USA: func_0207ccf0
extern "C" ARM int func_0207ccf0(struct Obj0207ccf0* self, short key, int amount, int flags, unsigned char a, unsigned char b, unsigned char c) {
    int fresh = 0;
    if (self->container == NULL) {
        _Z35InitAllocatorAndLoadGp2File0207d6dcP13SafeAllocatorii((SafeAllocator*)self, (int)&key, 1);
        fresh = 1;
    }
    int ret = -1;
    struct Entry0207ccf0* elem = (struct Entry0207ccf0*)_Z24FindElementByKey020dedd0P17Container020dedd0i(self->container, key);
    if (elem != NULL) {
        struct Combatant0207ccf0* combatant = (struct Combatant0207ccf0*)GetCombatantWithFlag0x100(GameState::GetInstance(), flags);
        if (combatant == NULL) return -1;
        if (CheckField0x56bLowNibble((struct Obj02061bd8*)combatant)) return -1;
        short* slots = (short*)(GetFieldAt0x150((unsigned char*)combatant) + 0x454);
        int count = 0;
        if (a && c && elem->flag25) {
            if (func_0207cf30(self, key, amount, b)) {
                count = amount;
                ret = 1;
            }
        } else if (elem->type == 8) {
            for (int i = 0; i < 8; i++) {
                if (slots[i] <= 0) {
                    slots[i] = key;
                    count = (short)(count + 1);
                    ret = 0;
                    func_0207cc18(self, (struct Element020de650*)elem);
                    self->field30 = elem->field4;
                    self->field34 = combatant->field134;
                    if (count == amount) break;
                }
            }
        }
        if ((ret == 0 && count < amount) || a) {
            short delta = (short)(amount - count);
            if (IsType0207ccf0(elem->type)) {
                if (func_0207d134(self, key, (signed char)delta)) ret = 1;
            } else if (elem->type == 9) {
                if (_Z22UpdateKeyValue0207d200P11Obj0207d200si((struct Obj0207d200*)self, key, (signed char)delta)) ret = 1;
            } else {
                if (func_0207cf30(self, key, delta, b)) ret = 1;
            }
        }
    } else {
        ret = -2;
    }
    if (fresh) {
        SafeAllocator* alloc = (SafeAllocator*)self;
        SignedAllocatorHeader* sig = alloc->GetSignedAllocator();
        alloc->Destroy();
        _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, sig);
        self->container = NULL;
    }
    return ret;
}
