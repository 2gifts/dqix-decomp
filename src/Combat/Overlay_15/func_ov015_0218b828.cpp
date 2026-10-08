#include <globaldefs.h>
#include "Memory/AllocatorUnion.h"

struct ViewerEntry
{
    char* name_;
    char* file_;
    unsigned short id_;
    unsigned char page_;
    unsigned char link_;
};

struct ViewerPresetItem
{
    char* file_;
    unsigned short id_;
    unsigned char kind_;
    ViewerPresetItem* next_;
};

struct ViewerPreset
{
    char* name_;
    ViewerPresetItem* items_;
};

struct Struct0218b810
{
    ViewerEntry* entries_;
    ViewerPreset* presets_;
    int entryCount_;
    int presetCount_;
};

extern "C" void _Z19TailForward02012da4P14AllocatorUnionPv(AllocatorUnion* alloc, void* data);
extern "C" void _Z22ZeroFourFields0218b810P14Struct0218b810(Struct0218b810* s);

extern AllocatorUnion data_02114e20;

// USA: func_ov015_0218b828
extern "C" ARM void func_ov015_0218b828(Struct0218b810* self)
{
    for (int i = 0; i < self->entryCount_; i++)
    {
        if (self->entries_[i].name_ != NULL)
        {
            _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, self->entries_[i].name_);
            self->entries_[i].name_ = NULL;
        }
        if (self->entries_[i].file_ != NULL)
        {
            _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, self->entries_[i].file_);
            self->entries_[i].file_ = NULL;
        }
    }
    for (int i = 0; i < self->presetCount_; i++)
    {
        if (self->presets_[i].name_ != NULL)
        {
            _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, self->presets_[i].name_);
            self->presets_[i].name_ = NULL;
        }
        ViewerPresetItem* item = self->presets_[i].items_;
        while (item != NULL)
        {
            ViewerPresetItem* next = item->next_;
            if (item->file_ != NULL)
            {
                _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, item->file_);
                item->file_ = NULL;
            }
            _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, item);
            item = next;
        }
    }
    if (self->entries_ != NULL)
    {
        _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, self->entries_);
        self->entries_ = NULL;
    }
    if (self->presets_ != NULL)
    {
        _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, self->presets_);
        self->presets_ = NULL;
    }
    _Z22ZeroFourFields0218b810P14Struct0218b810(self);
}
