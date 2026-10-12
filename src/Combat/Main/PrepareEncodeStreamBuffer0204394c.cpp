#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int _Z25AllocateVRAMStagingMemoryj(int value);
extern "C" int _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(int a, int b, int c, int d, unsigned char e, unsigned char f);
extern "C" int _Z21FreeVRAMStagingMemoryPKv(int value);

struct Struct0204394c {
    unsigned char pad[0x50];
    unsigned int count : 16;
    unsigned int unused50 : 16;
};

#if defined(jpn)
#define PrepareEncodeStreamBuffer0204394c func_02044104
extern "C" ARM int func_02044104(struct Struct0204394c* obj);
enum { kStagingOffset = 0x700 };
#else
enum { kStagingOffset = 0 };
#endif

// USA: func_0204394c
ARM int PrepareEncodeStreamBuffer0204394c(struct Struct0204394c* obj) {
    void* buf = (void*)_Z25AllocateVRAMStagingMemoryj(0x3000);
    if (buf == NULL) {
        return (int)buf;
    }
    int count8 = obj->count * 8;
    memset(buf, 0, 0x3000);
    _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(1, (int)buf, count8 + kStagingOffset, 0x3000, 1, 0);
    return _Z21FreeVRAMStagingMemoryPKv((int)buf);
}
