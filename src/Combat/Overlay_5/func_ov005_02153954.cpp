#if defined(jpn)
#define R(j,u) (j)
#define func_ov005_02158560 func_ov005_02159b58
#define func_ov005_021585fc func_ov005_02159bf4
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <Memory/SafeAllocator.h>

struct EquipmentMenu {
    SafeAllocator allocator_;
    SafeAllocator modelAllocator_;
    SafeAllocator equippedAllocators_[8];
    SafeAllocator itemAllocators_[16];
    SafeAllocator dragAllocator_;
    SafeAllocator textAllocator_;
    SafeAllocator unk_230;
    SafeAllocator infoAllocator_;
    SafeAllocator sortAllocator_;
    SafeAllocator modelTableAllocator_;
    SafeAllocator unk_280;
    char unk_294[R(0x3d00, 0x3d88) - 0x294];
    char* pageFiles_;
    char* dragFile_;
    char* equippedFiles_;
    char* itemFile_;
};

// USA: func_ov005_02153954
extern "C" ARM void func_ov005_02153954(EquipmentMenu* self, SafeAllocator* allocator, SafeAllocator* allocator2) {
    if (allocator == NULL || allocator2 == NULL)
        return;
    self->modelAllocator_.CreateTypeA(allocator2->Allocate(0x1300), 0x1300);
    for (int i = 0; i < 8; i++)
        self->equippedAllocators_[i].CreateTypeA(allocator2->Allocate(R(0x100, 0xe0)), R(0x100, 0xe0));
    for (int i = 0; i < 16; i++)
        self->itemAllocators_[i].CreateTypeA(allocator2->Allocate(R(0x100, 0xe0)), R(0x100, 0xe0));
    self->dragAllocator_.CreateTypeA(allocator2->Allocate(R(0x100, 0xe0)), R(0x100, 0xe0));
    self->textAllocator_.CreateTypeA(allocator2->Allocate(R(0x600, 0xc00)), R(0x600, 0xc00));
    self->infoAllocator_.CreateTypeA(allocator->Allocate(0x1e00), 0x1e00);
    self->allocator_.CreateTypeA(allocator->Allocate(0x4b00), 0x4b00);
    self->sortAllocator_.CreateTypeA(allocator->Allocate(0x4a00), 0x4a00);
    self->modelTableAllocator_.CreateTypeA(allocator->Allocate(0x1e00), 0x1e00);
    self->unk_280.CreateTypeA(allocator2->Allocate(0x200), 0x200);
    self->pageFiles_ = (char*)allocator->Allocate(0x800);
    self->dragFile_ = (char*)allocator2->Allocate(0x200);
    self->equippedFiles_ = (char*)allocator->Allocate(0x800);
    self->itemFile_ = (char*)allocator2->Allocate(0x200);
}
