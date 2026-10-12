#include <globaldefs.h>
#include "System/Memory.h"

extern "C" void func_020ca390(int value, void* destination, unsigned int size);
extern "C" int func_ov031_0221bfe8(void* buffer);
extern "C" void* func_ov031_0221b8e4(void* buffer);
extern "C" void func_ov031_02236570(int slot);
extern char* data_ov031_02290cfc;

// USA: func_ov031_022364c0
extern "C" ARM void func_ov031_022364c0(void) {
    char buffer[0x14];
    func_020ca390(0, data_ov031_02290cfc, 0x400);
    int i = 0;
    do {
        ((unsigned char*)data_ov031_02290cfc + (i << 8))[0xe7] = 0xff;
        ++i;
    } while (i < 3);
    func_ov031_0221bfe8(buffer);
    void* key = func_ov031_0221b8e4(buffer);
    int offset;
    int k = 0;
    offset = k;
    do {
        VectorizedInvertedMemcpy(key, data_ov031_02290cfc + offset + 0xf0, 0xe);
        ++k;
        offset += 0x100;
    } while (k < 2);
    int slot = 0;
    do {
        func_ov031_02236570(slot);
        ++slot;
    } while (slot < 4);
}
