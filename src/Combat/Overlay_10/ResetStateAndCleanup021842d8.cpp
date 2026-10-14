#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

extern AllocatorUnion data_02114e20;

void TailForward02012da4(AllocatorUnion* alloc, void* data);
void SetByteField0x253_020397c0(void* obj);

extern "C" void* func_02057924();
extern "C" void func_02057f00(void* head, int value);
extern "C" void func_ov010_021842a0(void* param);

struct Struct021842d8 {
    unsigned char pad0[4];
    int field4;
    unsigned char pad8[0xc];
    SafeAllocator safeAlloc;
};

// USA: func_ov010_021842d8
ARM void ResetStateAndCleanup021842d8(struct Struct021842d8* obj) {
    func_02057f00(func_02057924(), 0x11);
    void* p = obj->safeAlloc.GetSignedAllocator();
    if (p != NULL) {
        obj->safeAlloc.Destroy();
        TailForward02012da4(&data_02114e20, p);
    }
    if (obj->field4 >= 0) {
        int x = (int)BackgroundLoader::GetInstance();
        ((BackgroundLoader*)(x))->RemoveTask((int)(obj->field4));
        obj->field4 = -1;
    }
    GameObject* c = GameState::GetInstance()->GetUnknownGameObject();
    if (c != NULL) {
        SetByteField0x253_020397c0(c);
    }
    func_ov010_021842a0(obj);
}
