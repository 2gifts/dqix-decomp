#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

struct Container020dedd0;
struct Element020de650 {
    char pad0[8];
    unsigned int kind : 4;
    char pad[0x18 - 0xc];
    short key;
};

extern "C" struct Element020de650* _Z24FindElementByKey020dedd0P17Container020dedd0i(struct Container020dedd0* c, int key);
void* GetPtrField0x2a04(GameState* battleStruct);
extern "C" void _Z22ZeroInitReturn020de824Pv(void* obj);
extern "C" void _Z18InitStruct0207cbe8Pc(char* obj);
extern "C" void _Z18InitStruct0207cc0cPc(char* obj);
extern "C" void func_0207d134(void* buf, int key, int amount);
extern "C" void func_0207cf30(void* buf, int key, int amount, int arg);

// USA: func_ov003_02175cb0
extern "C" ARM int func_ov003_02175cb0(char* self, int arg) {
    *(unsigned char*)(self + 0x1000 + 0x4f) = 0;
    struct Element020de650* elem =
        _Z24FindElementByKey020dedd0P17Container020dedd0i((struct Container020dedd0*)(self + 0x74 + 0x800), *(short*)(self + 0x1000 + 0x3a));
    if (elem == NULL) {
        return 0;
    }

    GetPtrField0x2a04(GameState::GetInstance());

    char buf[0x38];
    ((SafeAllocator*)buf)->ResetAllocatorPointer();
    _Z22ZeroInitReturn020de824Pv(buf + 0x14);
    _Z18InitStruct0207cbe8Pc(buf);
    _Z18InitStruct0207cbe8Pc(buf);
    *(void**)(buf + 0x2c) = self + 0x74 + 0x800;
    int ok = elem->kind <= 7;
    if (ok) {
        func_0207d134(buf, elem->key, *(signed char*)(self + 0x1000 + 0x3c));
    } else {
        func_0207cf30(buf, elem->key, *(unsigned char*)(self + 0x1000 + 0x3c), arg);
    }
    _Z18InitStruct0207cc0cPc(buf);
    return 0;
}
