#include <globaldefs.h>
#include "World/Object3D.h"
#include "Graphics/VRAMStaging.h"
#include "System/Cache.h"
#include "System/LoadToVRAM.h"

struct Container020dedd0;
struct Obj020de2a4;

struct PartEntry
{
    void* model_;
};

struct VRAMManagerState
{
    char unk_0[0x68];
    unsigned int unk_68;
    char unk_6c[4];
};

struct ViewerSlot
{
    VRAMManagerState* states_;
};

struct Viewer0218c3a4
{
    char unk_0[0x4c];
    char parts_[0x18];
};

struct CharacterColors
{
    unsigned short hair_[10][2];
    unsigned short colors2_[8][2];
    unsigned short colors4_[8][4];
    unsigned short colors8_[8][8];
    unsigned short skin_[8][2];
    unsigned short edge_;
};

struct ViewObject
{
    Viewer0218c3a4* viewer_;
    ViewerSlot* slot_;
    char unk_8[0x1c - 0x8];
    unsigned char kind_;
    char unk_1d[3];
    int* parts_;
    Object3D* objects_;
    char unk_28[0x3b - 0x28];
    unsigned char female_;
    unsigned char hairColor_;
    unsigned char skinColor_;
    unsigned char eyeColor_;
};

extern "C" PartEntry* _Z24FindElementByKey020dedd0P17Container020dedd0i(Container020dedd0* c, int key);
extern "C" int _Z22GetNibbleField020de2a4P11Obj020de2a4ii(Obj020de2a4* obj, int a, int b);
CharacterColors* GetVariantShortTable02109928();
extern "C" void func_02099d34(void* obj, int a, int b, int c);

// USA: func_ov015_0218c3a4
extern "C" ARM void func_ov015_0218c3a4(ViewObject* self, int part)
{
    PartEntry* entry = _Z24FindElementByKey020dedd0P17Container020dedd0i((Container020dedd0*)&self->viewer_->parts_, (short)self->parts_[part]);
    if (entry == NULL || entry->model_ == NULL)
        return;
    VRAMManagerState* state = &self->slot_->states_[part];
    if (self->kind_ == 1)
    {
        int count = _Z22GetNibbleField020de2a4P11Obj020de2a4ii((Obj020de2a4*)entry, 0, self->female_);
        if (count == 0)
            return;
        count *= 2;
        NSBXXTex* texture = self->objects_[part].pModel_->GetTEX0();
        if (texture == NULL)
            return;
        int position = 0x30;
        unsigned short size = ((unsigned short)(texture->block4NumEightBytes_ << 3) + 0x1f) & ~0x1f;
        int start = 0x20;
        if (part == 0)
            start = 0x200;
        position -= size - start;
        CharacterColors* colors = GetVariantShortTable02109928();
        const void* source = NULL;
        int length = count * 2;
        switch (count)
        {
        case 2:
            source = colors->colors2_[self->eyeColor_];
            break;
        case 4:
            source = colors->colors4_[self->eyeColor_];
            break;
        case 8:
            source = colors->colors8_[self->eyeColor_];
            break;
        }
        unsigned int offset = (state->unk_68 & 0xffff) << 3;
        if (offset != 0 && length != 0)
        {
            LockStagedTextureVRAMCopying();
            CleanInvalidateCacheRange(source, length);
            MemoryMapTexturePalette();
            LoadToTexturePalette(source, offset + position, length);
            MemoryUnmapTexturePalette();
            CleanCacheRange(source, length);
            UnlockStagedTextureVRAMCopying();
        }
        return;
    }
    int colors = _Z22GetNibbleField020de2a4P11Obj020de2a4ii((Obj020de2a4*)entry, 1, self->female_);
    Model3D* model = self->objects_[part].pModel_;
    unsigned char color = self->eyeColor_;
    if (part == 4)
        func_02099d34(model, colors, color, 0x10);
    else
        func_02099d34(model, colors, color, 4);
}
