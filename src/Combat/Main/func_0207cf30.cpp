#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "Memory/SignedAllocator.h"
#include "GameState/GameState.h"

struct Container020dedd0;
struct Element020de650;
struct KeyMap020a0b3c;
struct KeyMap020a095c;
struct Obj02061bd8;
struct Obj0207cf30Field;

extern struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);
extern void* InitAllocatorAndLoadGp2File0207d6dc(SafeAllocator* self, int param1, int param2);
extern void* GetPtrField0x2a04_02010828(GameState* battleStruct);
extern int LookupValueByKey020a0b3c(struct KeyMap020a0b3c* map, int key);
extern int AddKeyValueClamped020a095c(struct KeyMap020a095c* map, int key, int amount);
extern int CheckField0x56bLowNibble(struct Obj02061bd8* obj);
extern struct Obj0207cf30Field* GetFieldAt0x150_02053c6c(unsigned char* obj);
extern GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* gs, int id);

extern "C" void func_0207cc18(void* self, struct Element020de650* elem);

extern void TailForward02012da4(AllocatorUnion* alloc, void* data);

extern AllocatorUnion data_02114e20 __attribute__((aligned(4)));

struct Obj0207cf30Field {
    char pad[0x454];
    short slot[8];
};

struct Obj0207cf30 {
    char pad[0x2c];
    struct Container020dedd0* container;
    void* field30;
    void* field34;
};

// USA: func_0207cf30
extern "C" ARM int func_0207cf30(struct Obj0207cf30* self, short key, int max, int enable) {
    int flag = 0;
    if (self->container == NULL) {
        InitAllocatorAndLoadGp2File0207d6dc((SafeAllocator*)self, (int)&key, 1);
        flag = 1;
    }
    int ret = 0;
    struct Element020de650* elem = FindElementByKey020dedd0(self->container, key);
    if (elem != NULL) {
        GameState* gs = GameState::GetInstance();
        char* p = (char*)GetPtrField0x2a04_02010828(gs);
        int n = max;
        short i = 0;
        if (enable) {
            int v = LookupValueByKey020a0b3c((struct KeyMap020a0b3c*)GetPtrField0x2a04_02010828(gs), key);
            v = 99 - v;
            if (v > max)
                v = max;
            n = (short)v;
        }
        ret = AddKeyValueClamped020a095c((struct KeyMap020a095c*)p, key, (signed char)n);
        i += n;
        if (ret) {
            func_0207cc18(self, elem);
            self->field30 = *(void**)((char*)elem + 4);
            self->field34 = gs->GetProtagonist()->baseStats_;
        }
        if (i < max && enable) {
            char* q = (char*)GetPtrField0x2a04_02010828(gs);
            for (int j = 0; j < *(unsigned char*)(q + 0xf7c); j++) {
                GameObject* c = GetCombatantWithFlag0x100_0200ff1c(gs, *(unsigned char*)(q + j + 0xf78));
                if (c == NULL)
                    continue;
                if (CheckField0x56bLowNibble((struct Obj02061bd8*)c) != 0)
                    continue;
                struct Obj0207cf30Field* f = GetFieldAt0x150_02053c6c((unsigned char*)c);
                if (f == NULL)
                    continue;
                for (int k = 0; k < 8; k++) {
                    if (f->slot[k] > 0)
                        continue;
                    f->slot[k] = key;
                    func_0207cc18(self, elem);
                    i++;
                    if (i == max)
                        break;
                }
                if (i == max)
                    break;
            }
        }
    }
    if (flag) {
        SafeAllocator* alloc = (SafeAllocator*)self;
        SignedAllocatorHeader* sig = alloc->GetSignedAllocator();
        alloc->Destroy();
        TailForward02012da4(&data_02114e20, sig);
        self->container = NULL;
    }
    return ret;
}
