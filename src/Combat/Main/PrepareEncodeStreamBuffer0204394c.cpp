#include <globaldefs.h>
#include "std_library_functions.h"
#include "Graphics/VRAMStaging.h"


struct Struct0204394c {
    unsigned char pad[0x50];
    unsigned int textureAddressUnits : 16;
    unsigned int unused50 : 16;
};

#if defined(jpn)
#define PrepareEncodeStreamBuffer0204394c func_02044104
extern "C" ARM void func_02044104(struct Struct0204394c* obj);
enum { kStagingOffset = 0x700 };
#else
enum { kStagingOffset = 0 };
#endif

// USA: func_0204394c
ARM void PrepareEncodeStreamBuffer0204394c(struct Struct0204394c* obj) {
    void* buf = AllocateVRAMStagingMemory(0x3000);
    if (buf == NULL) {
        return;
    }


    int textureByteOffset = obj->textureAddressUnits * 8;
    memset(buf, 0, 0x3000);
    StageMemoryToVRAM(VRAMSubregion_TextureImage, buf, textureByteOffset + kStagingOffset, 0x3000, true, false);
    FreeVRAMStagingMemory(buf);
}
