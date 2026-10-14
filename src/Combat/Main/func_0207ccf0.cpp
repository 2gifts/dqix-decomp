#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "Memory/SignedAllocator.h"
#include "GameState/GameState.h"

struct Container020dedd0;
struct Element020de650;
struct Obj02061bd8;
struct Obj0207d200;

extern struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);
extern void* InitAllocatorAndLoadGp2File0207d6dc(SafeAllocator* self, int param1, int param2);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* gs, int flags);
int CheckField0x56bLowNibble(struct Obj02061bd8* obj);
unsigned char* GetFieldAt0x150_02053c6c(unsigned char* combatant);
extern "C" int func_0207cf30(void* self, short key, int amount, unsigned char flag);
extern "C" void func_0207cc18(void* self, struct Element020de650* elem);
extern "C" int func_0207d134(void* self, short key, int amount);
int UpdateKeyValue0207d200(struct Obj0207d200* self, short key, int amount);
extern void TailForward02012da4(AllocatorUnion* alloc, void* data);
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
        InitAllocatorAndLoadGp2File0207d6dc((SafeAllocator*)self, (int)&key, 1);
        fresh = 1;
    }
    int ret = -1;
    struct Entry0207ccf0* elem = (struct Entry0207ccf0*)FindElementByKey020dedd0(self->container, key);
    if (elem != NULL) {
        struct Combatant0207ccf0* combatant = (struct Combatant0207ccf0*)GetCombatantWithFlag0x100_0200ff1c(GameState::GetInstance(), flags);
        if (combatant == NULL) return -1;
        if (CheckField0x56bLowNibble((struct Obj02061bd8*)combatant)) return -1;
        short* slots = (short*)(GetFieldAt0x150_02053c6c((unsigned char*)combatant) + 0x454);
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
                if (UpdateKeyValue0207d200((struct Obj0207d200*)self, key, (signed char)delta)) ret = 1;
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
        TailForward02012da4(&data_02114e20, sig);
        self->container = NULL;
    }
    return ret;
}
