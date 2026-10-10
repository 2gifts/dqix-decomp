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

extern "C" extern struct Element020de650* _Z24FindElementByKey020dedd0P17Container020dedd0i(struct Container020dedd0* c, int key);
extern "C" extern void* _Z35InitAllocatorAndLoadGp2File0207d6dcP13SafeAllocatorii(SafeAllocator* self, int param1, int param2);
extern void* GetPtrField0x2a04(GameState* battleStruct);
extern "C" extern int _Z24LookupValueByKey020a0b3cP14KeyMap020a0b3ci(struct KeyMap020a0b3c* map, int key);
extern "C" extern int _Z26AddKeyValueClamped020a095cP14KeyMap020a095cii(struct KeyMap020a095c* map, int key, int amount);
extern int CheckField0x56bLowNibble(struct Obj02061bd8* obj);
extern struct Obj0207cf30Field* GetFieldAt0x150(unsigned char* obj);
extern GameObject* GetCombatantWithFlag0x100(GameState* gs, int id);

extern "C" void func_0207cc18(void* self, struct Element020de650* elem);

extern "C" extern void _Z19TailForward02012da4P14AllocatorUnionPv(AllocatorUnion* alloc, void* data);

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
        _Z35InitAllocatorAndLoadGp2File0207d6dcP13SafeAllocatorii((SafeAllocator*)self, (int)&key, 1);
        flag = 1;
    }
    int ret = 0;
    struct Element020de650* elem = _Z24FindElementByKey020dedd0P17Container020dedd0i(self->container, key);
    if (elem != NULL) {
        GameState* gs = GameState::GetInstance();
        char* p = (char*)GetPtrField0x2a04(gs);
        int n = max;
        short i = 0;
        if (enable) {
            int v = _Z24LookupValueByKey020a0b3cP14KeyMap020a0b3ci((struct KeyMap020a0b3c*)GetPtrField0x2a04(gs), key);
            v = 99 - v;
            if (v > max)
                v = max;
            n = (short)v;
        }
        ret = _Z26AddKeyValueClamped020a095cP14KeyMap020a095cii((struct KeyMap020a095c*)p, key, (signed char)n);
        i += n;
        if (ret) {
            func_0207cc18(self, elem);
            self->field30 = *(void**)((char*)elem + 4);
            self->field34 = gs->GetProtagonist()->baseStats_;
        }
        if (i < max && enable) {
            char* q = (char*)GetPtrField0x2a04(gs);
            for (int j = 0; j < *(unsigned char*)(q + 0xf7c); j++) {
                GameObject* c = GetCombatantWithFlag0x100(gs, *(unsigned char*)(q + j + 0xf78));
                if (c == NULL)
                    continue;
                if (CheckField0x56bLowNibble((struct Obj02061bd8*)c) != 0)
                    continue;
                struct Obj0207cf30Field* f = GetFieldAt0x150((unsigned char*)c);
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
        _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, sig);
        self->container = NULL;
    }
    return ret;
}
