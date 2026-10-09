#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/EntryGetterTypes.h"
#include "World/Object3D.h"
#include "Memory/SafeAllocator.h"
#include "Graphics/VRAMStaging.h"
#include "System/LoadToVRAM.h"
#include "System/Cache.h"

struct Entry0203db44 {
    S02040538 getter;
    char padding[8];
    Object3D* object;
};

struct Tint0203db44 {
    char padding[0x20];
    unsigned short color;
};

// USA: func_0203db44
extern "C" ARM void func_0203db44(void*, Entry0203db44* entry, SafeAllocator* allocator) {
    unsigned short* output;
    unsigned short* source;
    unsigned int length;
    unsigned int offset;
    if (entry->object == NULL) return;
    GameState::GetInstance();
    Object3D* object = entry->object;
    Tint0203db44* tint = (Tint0203db44*)GetField0xc02040538(&entry->getter);
    if (tint == NULL) return;
    unsigned short color = tint->color;
    unsigned short red = color & 31;
    unsigned short green = (color & 0x3e0) >> 5;
    unsigned short blue = (color & 0x7c00) >> 10;
    LockStagedTextureVRAMCopying();
    MemoryMapTexturePalette();
    if (object->pModel_ != NULL) {
        NSBXXTex* texture = object->pModel_->GetTEX0();
        if (texture != NULL) {
            if (color == 0 && object->GetTexturePaletteOffset() == 0) {
                NSBXX_Tex_LoadPaletteToVRAM(texture, false);
            } else {
                offset = texture->block4VRAMLoadOffset_;
                if (object->GetTexturePaletteOffset() != 0)
                    offset = object->GetTexturePaletteOffset();
                length = texture->block4NumEightBytes_ << 3;
                offset = (offset & 0xffff) << 3;
                source = (unsigned short*)((char*)texture + texture->block4Offset_);
                output = (unsigned short*)allocator->Allocate(length);
                if (output != NULL) {
                    for (unsigned int i = 0; i < length / 2; i++) {
                        unsigned short r = source[i] & 31;
                        unsigned short g = (source[i] & 0x3e0) >> 5;
                        unsigned short b = (source[i] & 0x7c00) >> 10;
                        r += red;
                        g += green;
                        b += blue;
                        if (r > 31) r = 31;
                        if (g > 31) g = 31;
                        if (b > 31) b = 31;
                        output[i] = r | (g << 5) | (b << 10);
                    }
                    CleanInvalidateCacheRange(output, length);
                    LoadToTexturePalette(output, offset, length);
                }
            }
        }
    }
    MemoryUnmapTexturePalette();
    UnlockStagedTextureVRAMCopying();
}
