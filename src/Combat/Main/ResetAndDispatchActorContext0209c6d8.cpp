#include <globaldefs.h>
void TryAllocateOrAppend0203aaf8(void*, void*, int*);
void TryDispatchOrFallback0203aba8(struct Obj0203aba8*, void*, void*);

struct Actor0209c678;
void DispatchContextByState0209c678(struct Actor0209c678* actor, int arg);
void Forward0203aa80(void* obj, int arg2);
extern "C" void func_0209c2e0(void* obj, int a, int b);
extern "C" void func_020bbd9c(void);

// USA: func_0209c6d8
ARM void ResetAndDispatchActorContext0209c6d8(void* actor, int arg) {
    DispatchContextByState0209c678((struct Actor0209c678*)actor, 0);
    {
        int f = *(int*)((char*)actor + 0xb4);
        if (f > 0) {
            Forward0203aa80(actor, f);
        }
    }
    *(short*)((char*)actor + 0xce) = arg;
    TryAllocateOrAppend0203aaf8((void*)(actor), (void*)(arg), (int*)(0));
    TryDispatchOrFallback0203aba8((struct Obj0203aba8*)(actor), (void*)(arg), (void*)((char*)actor + 0xc4));
    func_0209c2e0(actor, *(unsigned char*)((char*)actor + 0xcd), 0);
    func_020bbd9c();
}
