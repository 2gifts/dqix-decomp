#if defined(jpn)
#define R(j,u) (j)
#define func_ov013_021846a0 func_ov013_021856dc
#define func_ov013_02184d80 func_ov013_02185db4
#define func_ov013_02186160 func_ov013_02187178
#define func_ov013_021864f0 func_ov013_02187820
#define func_ov013_02186590 func_ov013_021878c0
#define func_ov013_0218678c func_ov013_02187ab8
#define func_ov013_0218683c func_ov013_02187b68
#define func_ov013_02186bd4 func_ov013_02187f00
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <Memory/SafeAllocator.h>

struct Unk020421a0 {
    char pad_0[R(0x28,0x5c)];
    void* unk_5c;
};

extern "C" Unk020421a0* _Z26GetGlobalField0x1c020421a0v();

struct BattleRecords {
    SafeAllocator allocator_;
    SafeAllocator backgroundAllocator_;
    SafeAllocator textAllocator_;
    SafeAllocator spriteAllocator_;
    SafeAllocator iconAllocator_;
    SafeAllocator modelAllocator_;
    SafeAllocator titleAllocator_;
    SafeAllocator guideAllocator_;
    char texts_[0x18];
    char* text_;
    char pad_bc[0x72c - 0xbc];
    void* pixels_;
    void* renderer_;
    void* sprites_;
    void* animations_;
    char pad_73c[0xb24 - 0x73c];
    int mode_;
};

// USA: func_ov008_021842a0
extern "C" ARM void func_ov008_021842a0(BattleRecords* self, SafeAllocator* allocator)
{
    if (allocator == NULL)
        return;
    self->backgroundAllocator_.CreateTypeA(allocator->Allocate(0x2400), 0x2400);
    self->textAllocator_.CreateTypeA(allocator->Allocate(0x800), 0x800);
    if (self->mode_ == 0)
    {
        self->allocator_.CreateTypeA(allocator->Allocate(0x1000), 0x1000);
        self->spriteAllocator_.CreateTypeA(allocator->Allocate(0x200), 0x200);
        self->iconAllocator_.CreateTypeA(allocator->Allocate(0x400), 0x400);
        self->modelAllocator_.CreateTypeA(allocator->Allocate(0x8800), 0x8800);
        self->titleAllocator_.CreateTypeA(allocator->Allocate(R(0xa000,0x8000)), R(0xa000,0x8000));
        self->guideAllocator_.CreateTypeA(allocator->Allocate(R(0x6000,0x8000)), R(0x6000,0x8000));
        self->renderer_ = allocator->Allocate(0x54);
        self->sprites_ = allocator->Allocate(0x2d0);
        self->animations_ = allocator->Allocate(8);
        self->text_ = (char*)_Z26GetGlobalField0x1c020421a0v()->unk_5c;
    }
    else
    {
        self->text_ = (char*)allocator->Allocate(R(0x800,0x960));
    }
    self->pixels_ = self->backgroundAllocator_.Allocate(0x1c00);
}
