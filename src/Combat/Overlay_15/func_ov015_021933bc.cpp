#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ViewObject;
struct VRAMManagerState;

struct ViewObjectNode
{
    ViewObject* object_;
    ViewObjectNode* next_;
};

struct ViewerSlot
{
    VRAMManagerState* states_;
    unsigned char used_;
    char unk_5[3];
};

struct ViewerConfig
{
    void* entries_;
    void* presets_;
    int entryCount_;
    int presetCount_;
};

struct S02190c2c
{
    char unk_0[0x2c];
    ViewObjectNode* objects_;
    char unk_30[0x3c - 0x30];
    ViewerConfig config_;
    char unk_4c[0x84 - 0x4c];
    void* buffer_;
    SafeAllocator partsAllocator_;
    SafeAllocator monstersAllocator_;
    SafeAllocator soundsAllocator_;
    ViewerSlot playerSlots_[4];
    ViewerSlot dollSlots_[4];
    ViewerSlot slots_[4];
    char unk_124[0x344 - 0x124];
    void* items_;
};

extern "C" void func_ov015_0218f0c4(ViewObject* object);
extern "C" void _Z19TailForward02012da4P14AllocatorUnionPv(AllocatorUnion* alloc, void* data);
extern "C" void func_ov015_0218b828(ViewerConfig* config);

extern AllocatorUnion data_02114e20;

// USA: func_ov015_021933bc
extern "C" ARM void func_ov015_021933bc(S02190c2c* self)
{
    ViewObjectNode* node = self->objects_;
    while (node != NULL)
    {
        func_ov015_0218f0c4(node->object_);
        _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, node->object_);
        ViewObjectNode* next = node;
        node = node->next_;
        _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, next);
    }
    for (int i = 0; i < 4; i++)
    {
        if (self->playerSlots_[i].states_ != NULL)
            _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, self->playerSlots_[i].states_);
        if (self->dollSlots_[i].states_ != NULL)
            _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, self->dollSlots_[i].states_);
        if (self->slots_[i].states_ != NULL)
            _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, self->slots_[i].states_);
    }
    _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, self->partsAllocator_.GetSignedAllocator());
    _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, self->monstersAllocator_.GetSignedAllocator());
    _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, self->soundsAllocator_.GetSignedAllocator());
    self->partsAllocator_.Destroy();
    self->monstersAllocator_.Destroy();
    self->soundsAllocator_.Destroy();
    func_ov015_0218b828(&self->config_);
    if (self->buffer_ != NULL)
    {
        _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, self->buffer_);
        self->buffer_ = NULL;
    }
    if (self->items_ == NULL)
        return;
    _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, self->items_);
    self->items_ = NULL;
}
