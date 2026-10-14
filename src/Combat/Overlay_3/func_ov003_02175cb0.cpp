#include <globaldefs.h>
#if defined(jpn)
enum { kRegion103a = 0xfb6 };
enum { kRegion104f = 0xfcb };
enum { kRegion874 = 0x7f0 };
enum { kRegion103c = 0xfb8 };
#else
enum { kRegion103a = 0x103a };
enum { kRegion104f = 0x104f };
enum { kRegion874 = 0x874 };
enum { kRegion103c = 0x103c };
#endif

#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

struct Container020dedd0;
struct Element020de650 {
    char pad0[8];
    unsigned int kind : 4;
    char pad[0x18 - 0xc];
    short key;
};

struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);
void* GetPtrField0x2a04(GameState* battleStruct);
void ZeroInitReturn020de824(void* obj);
void InitStruct0207cbe8(char* obj);
void InitStruct0207cc0c(char* obj);
extern "C" void func_0207d134(void* buf, int key, int amount);
extern "C" void func_0207cf30(void* buf, int key, int amount, int arg);

// USA: func_ov003_02175cb0
extern "C" ARM int func_ov003_02175cb0(char* self, int arg) {
    *(unsigned char*)(self + kRegion104f) = 0;
    struct Element020de650* elem =
        FindElementByKey020dedd0((struct Container020dedd0*)(self + kRegion874), *(short*)(self + kRegion103a));
    if (elem == NULL) {
        return 0;
    }

    GetPtrField0x2a04(GameState::GetInstance());

    char buf[0x38];
    ((SafeAllocator*)buf)->ResetAllocatorPointer();
    ZeroInitReturn020de824(buf + 0x14);
    InitStruct0207cbe8(buf);
    InitStruct0207cbe8(buf);
    *(void**)(buf + 0x2c) = self + kRegion874;
    int ok = elem->kind <= 7;
    if (ok) {
        func_0207d134(buf, elem->key, *(signed char*)(self + kRegion103c));
    } else {
        func_0207cf30(buf, elem->key, *(unsigned char*)(self + kRegion103c), arg);
    }
    InitStruct0207cc0c(buf);
    return 0;
}
