#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

extern "C" void MemoryMapTexturePalette(void);
extern "C" void LoadToTexturePalette(void* ptr, int a, unsigned int b);
extern "C" void MemoryUnmapTexturePalette(void);
void LockStagedTextureVRAMCopying(void);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
void UnlockStagedTextureVRAMCopying(void);

struct S0217ca84 {
    SafeAllocator* allocator;
    char pad4[0x88 - 4];
    void* field88;
};

struct Inner0217ca84 {
    char pad0[0x2c];
    int field2c;
    char pad30[0x30 - 0x30];
    unsigned short field30;
};

// USA: func_ov003_0217ca84  (semantic: AllocateAndFillBuffer_0217ca84)
extern "C" ARM void func_ov003_0217ca84(S0217ca84* obj, unsigned short fillValue) {
    GameState::GetInstance();
    LockStagedTextureVRAMCopying();
    MemoryMapTexturePalette();

    void* p88 = obj->field88;
    if (p88 != NULL) {
        Inner0217ca84* inner = (Inner0217ca84*)((Model3D*)p88)->GetTEX0();
        if (inner != NULL) {
            int size = inner->field2c;
            if (((Object3D*)((unsigned char*)obj + 0x80))->GetTexturePaletteOffset()) {
                size = ((Object3D*)((unsigned char*)obj + 0x80))->GetTexturePaletteOffset();
            }

            void* buf;
            unsigned int allocSize = (unsigned int)inner->field30 << 3;
            int scaledSize = (unsigned short)size << 3;

            buf = obj->allocator->Allocate(allocSize);
            if (buf != NULL) {
                unsigned int i;
                for (i = 0; i < allocSize / 2; i++) {
                    ((unsigned short*)buf)[i] = fillValue;
                }
                CleanInvalidateCacheRange(buf, allocSize);
                LoadToTexturePalette(buf, scaledSize, allocSize);
            }
        }
    }

    MemoryUnmapTexturePalette();
    UnlockStagedTextureVRAMCopying();
}
