#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Graphics/VRAMStaging.h"

extern "C" int func_020bb7cc(unsigned int size, int a, int b);

struct Obj02047f70 {
    char pad0[0x10];
    int field10;
    char pad14[0x84 - 0x14];
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char bit3 : 1;
    unsigned char bit4 : 1;
    unsigned char bit5 : 1;
    unsigned char bit6 : 1;
    unsigned char bit7 : 1;
};

// USA: func_02047f70  (semantic: EncodeAndMaybeDuplicateBuffer_02047f70)
extern "C" ARM void func_02047f70(struct Obj02047f70* obj, void* buf, unsigned int size, SafeAllocator* allocator) {
    unsigned int computedSize = ((unsigned int)func_020bb7cc(size, 0, 0) << 16) >> 13;
    bool usedOriginal = true;
    if (obj->bit2 && allocator != NULL) {
        void* newBuf = allocator->Allocate(size);
        if (newBuf != NULL) {
            memcpy(newBuf, buf, size);
            buf = newBuf;
            usedOriginal = false;
        }
    }
    StageMemoryToVRAM(VRAMSubregion_TexturePalette, buf, computedSize, size, false, usedOriginal);
    obj->field10 = (int)computedSize;
}
