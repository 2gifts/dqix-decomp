#include <globaldefs.h>
#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"

struct Struct0215efb8;
struct ResetLayout_0215e6d8;

extern "C" void _Z18InitStruct0215efb8P14Struct0215efb8(Struct0215efb8* keyboard);
extern "C" void _Z20ResetStruct_0215e6d8P20ResetLayout_0215e6d8(ResetLayout_0215e6d8* layout);

struct CharacterCreation {
    SafeAllocator allocators_[9];
    SafeAllocator* modelAllocator_;
    SafeAllocator* previewAllocators_;
    void* savedKey_;
    Struct0215efb8* keyboard_;
    ResetLayout_0215e6d8* layout_;
    char unk_c8[0x7d8 - 0xc8];
    void* renderer_;
    void* sprites_;
    void* unk_7e0;
    void* renderer2_;
    void* sprites2_;
    void* unk_7ec;
    char unk_7f0[0xd95 - 0x7f0];
    unsigned char mode_;
    char unk_d96[0xdb0 - 0xd96];
    char** names_;
};

// USA: func_ov009_021842a0
extern "C" ARM void func_ov009_021842a0(CharacterCreation* self, SafeAllocator* allocator)
{
    if (allocator == NULL)
        return;

    self->allocators_[0].CreateTypeA(allocator->Allocate(0x3800), 0x3800);
    self->allocators_[1].CreateTypeA(allocator->Allocate(0x3400), 0x3400);
    self->allocators_[2].CreateTypeA(allocator->Allocate(0x1000), 0x1000);
    self->allocators_[3].CreateTypeA(allocator->Allocate(0x2b240), 0x2b240);
    self->allocators_[4].CreateTypeA(allocator->Allocate(0xc00), 0xc00);
    self->allocators_[5].CreateTypeA(allocator->Allocate(0x2000), 0x2000);
    self->allocators_[6].CreateTypeA(allocator->Allocate(0x400), 0x400);
    self->allocators_[7].CreateTypeA(allocator->Allocate(0x800), 0x800);
    self->allocators_[8].CreateTypeA(allocator->Allocate(0x1800), 0x1800);
    self->names_ = (char**)allocator->Allocate(8);
    for (int i = 0; i < 2; i++)
    {
        self->names_[i] = (char*)allocator->Allocate(0x48);
        memset(self->names_[i], 0, 0x48);
    }
    self->keyboard_ = (Struct0215efb8*)allocator->Allocate(0x28);
    self->layout_ = (ResetLayout_0215e6d8*)allocator->Allocate(0x10);
    _Z18InitStruct0215efb8P14Struct0215efb8(self->keyboard_);
    _Z20ResetStruct_0215e6d8P20ResetLayout_0215e6d8(self->layout_);
    self->renderer_ = allocator->Allocate(0x54);
    self->sprites_ = allocator->Allocate(0xf0);
    self->unk_7e0 = allocator->Allocate(8);
    self->renderer2_ = allocator->Allocate(0x54);
    self->sprites2_ = allocator->Allocate(0x3e8);
    self->unk_7ec = allocator->Allocate(8);
    if (self->mode_ != 0)
        return;

    self->modelAllocator_ = (SafeAllocator*)allocator->Allocate(0x14);
    self->previewAllocators_ = (SafeAllocator*)allocator->Allocate(0x28);
    self->modelAllocator_->ResetAllocatorPointer();
    for (int i = 0; i < 2; i++)
        self->previewAllocators_[i].ResetAllocatorPointer();
    self->modelAllocator_->CreateTypeA(allocator->Allocate(0xc000), 0xc000);
    self->previewAllocators_[0].CreateTypeA(allocator->Allocate(0x3000), 0x3000);
    self->previewAllocators_[1].CreateTypeA(allocator->Allocate(0x1800), 0x1800);
}
