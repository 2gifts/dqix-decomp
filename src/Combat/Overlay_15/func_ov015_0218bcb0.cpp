#include <globaldefs.h>
#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Combat/Overlay15ViewerContext.h"

struct ViewerSlot
{
    void* states_;
    unsigned char used_;
    char unk_5[3];
};

struct Struct205563c;


struct ObjectSizes
{
    unsigned int sizes_[7];
};

struct PartSizes
{
    unsigned int sizes_[11][2];
};

void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern "C" ViewerSlot* _Z20FindFreeSlot021931f8Pc(char* viewer);
extern "C" ViewerSlot* _Z20FindFreeSlot0219322cPc(char* viewer);
extern "C" ViewerSlot* _Z20FindFreeSlot02193260Pc(char* viewer);
void ClearSevenWords(Struct205563c* obj);

extern AllocatorUnion data_02114e20;
extern const ObjectSizes data_ov015_02193d80;
extern const PartSizes data_ov015_02193df0;

// USA: func_ov015_0218bcb0
extern "C" ARM int func_ov015_0218bcb0(void* context)
{
    Obj0218c274* self = static_cast<Obj0218c274*>(context);
    if (self->kind_ == 0 || self->kind_ == 1)
    {
        PartSizes sizes = data_ov015_02193df0;
        self->allocators_ = (SafeAllocator*)AllocateAligned4(&data_02114e20, 10 * sizeof(SafeAllocator));
        if (self->allocators_ == NULL)
        {
            func_ov015_0218f0c4(self);
            return 0;
        }
        self->objects_ = (Object3D*)AllocateAligned4(&data_02114e20, 10 * sizeof(Object3D));
        if (self->objects_ == NULL)
        {
            func_ov015_0218f0c4(self);
            return 0;
        }
        for (int i = 0; i < 10; i++)
        {
            self->allocators_[i].ResetAllocatorPointer();
            void* buffer = AllocateAligned4(&data_02114e20, sizes.sizes_[i][self->kind_]);
            if (buffer == NULL)
                return 0;
            self->allocators_[i].CreateTypeA(buffer, sizes.sizes_[i][self->kind_]);
            self->allocators_[i].Reset();
            self->objects_[i].Initialize();
        }
        self->parts_ = (int*)AllocateAligned4(&data_02114e20, 10 * sizeof(int));
        if (self->parts_ == NULL)
        {
            func_ov015_0218f0c4(self);
            return 0;
        }
        memset(self->parts_, -1, 10 * sizeof(int));
        self->parts_[0] = 0x32cf;
        self->parts_[1] = 0x3f57;
        self->parts_[2] = 0x233c;
        self->parts_[3] = 0x2328;
        self->parts_[4] = 0x2328;
        self->parts_[5] = 0x36b7;
        self->parts_[6] = 0x42e0;
        if (self->kind_ == 0)
            self->slot_ = _Z20FindFreeSlot021931f8Pc(self->viewer_);
        else
            self->slot_ = _Z20FindFreeSlot0219322cPc(self->viewer_);
        if (self->slot_ == NULL)
        {
            func_ov015_0218f0c4(self);
            return 0;
        }
        self->slot_->used_ = 1;
        self->bufferSize_ = sizes.sizes_[10][self->kind_];
        self->buffer_ = AllocateAligned4(&data_02114e20, self->bufferSize_);
        if (self->buffer_ == NULL)
        {
            func_ov015_0218f0c4(self);
            return 0;
        }
    }
    else
    {
        ObjectSizes sizes = data_ov015_02193d80;
        self->allocators_ = (SafeAllocator*)AllocateAligned4(&data_02114e20, sizeof(SafeAllocator));
        if (self->allocators_ == NULL)
        {
            func_ov015_0218f0c4(self);
            return 0;
        }
        self->allocators_->ResetAllocatorPointer();
        void* buffer = AllocateAligned4(&data_02114e20, sizes.sizes_[self->kind_]);
        if (buffer == NULL)
            return 0;
        self->allocators_->CreateTypeA(buffer, sizes.sizes_[self->kind_]);
        self->allocators_->Reset();
        self->slot_ = _Z20FindFreeSlot02193260Pc(self->viewer_);
        if (self->slot_ == NULL)
        {
            func_ov015_0218f0c4(self);
            return 0;
        }
        self->slot_->used_ = 1;
        if (self->kind_ == 2 || self->kind_ == 3)
        {
            self->bufferSize_ = 0xc000;
            self->buffer_ = AllocateAligned4(&data_02114e20, self->bufferSize_);
            if (self->buffer_ == NULL)
            {
                func_ov015_0218f0c4(self);
                return 0;
            }
        }
        self->objects_ = (Object3D*)AllocateAligned4(&data_02114e20, sizeof(Object3D));
        if (self->objects_ == NULL)
        {
            func_ov015_0218f0c4(self);
            return 0;
        }
        self->objects_->Initialize();
        if (self->kind_ == 4)
        {
            self->effect_ = (Struct205563c*)AllocateAligned4(&data_02114e20, 0x1c);
            if (self->effect_ == NULL)
            {
                func_ov015_0218f0c4(self);
                return 0;
            }
            ClearSevenWords(self->effect_);
        }
    }
    return 1;
}
