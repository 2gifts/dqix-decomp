#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

void SetFlag0x2IfByte0xd4Not3(unsigned char* obj);
extern "C" void func_0208bb78(void* obj, int count);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
extern AllocatorUnion data_02114e20;
int GetGlobal02109400(void);
extern "C" void _Z21BlankFunction02094b40v(int val);
extern "C" void func_02094ab0(int val);
extern "C" void _Z21BlankFunction02094b2cv(int val, int f20, void* f24, unsigned char f28, unsigned char f29);

struct Obj02154e40 {
    char pad0[0xa];
    unsigned short field0xa;
    char pad1[0x13 - 0xc];
    unsigned char field0x13;
    char pad2[0x50 - 0x14];
    unsigned short flags0x50;
#if defined(jpn)
    char pad3[0x11c - 0x52];
#else
    char pad3[0x120 - 0x52];
#endif
    void* field0x120;
    char pad4[0x138 - 0x124];
    SafeAllocator* field0x138;
};

// USA: func_ov001_02154e40  (semantic: RescaleOrReleaseCombatantAlloc_02154e40)
extern "C" ARM int func_ov001_02154e40(struct Obj02154e40* self) {
    GameState* battle = GameState::GetInstance();

    if (!(self->flags0x50 & 0x8) && self->field0x138 != 0 && self->field0x120 != 0) {
        SetFlag0x2IfByte0xd4Not3((unsigned char*)self->field0x120);
        unsigned int scaleCount = battle->GetTickCount();
        func_0208bb78(self->field0x120, scaleCount);

        if (*(short*)((char*)self->field0x120 + 0xd2) >= 0) {
            return self->field0xa;
        }

        void* signedAlloc = (void*)self->field0x138->GetSignedAllocator();
        if (signedAlloc) {
            self->field0x138->Destroy();
            TailForward02012da4(&data_02114e20, signedAlloc);
            self->field0x138 = 0;
        }
        self->field0x120 = 0;
    }

    int val = GetGlobal02109400();
    unsigned char flag = 1;
    if (self->field0x13 != 0) {
        flag = 0;
    }
    _Z21BlankFunction02094b40v(val);
    func_02094ab0(val);
    _Z21BlankFunction02094b2cv(val, 0x6f, (char*)self + 0x62, 1, flag);
    return 0xd;
}
