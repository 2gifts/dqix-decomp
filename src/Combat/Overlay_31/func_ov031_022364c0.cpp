#include <globaldefs.h>
#include "System/Memory.h"

extern "C" void func_020ca390(int, void*, unsigned int);
extern "C" void func_ov031_0221bfe8(void*);
extern "C" void* func_ov031_0221b8e4(void*);
extern "C" void func_ov031_02236570(int);

struct SaveSlot { unsigned char pad[0xe7]; unsigned char valid; unsigned char padE8[8]; unsigned char key[14]; unsigned char padFE[2]; };
struct SaveSlots { SaveSlot slots[4]; };
extern SaveSlots* data_ov031_02290cfc;

// USA: func_ov031_022364c0
extern "C" ARM void func_ov031_022364c0() {
    func_020ca390(0, data_ov031_02290cfc, 0x400);
    int validIndex = 0;
    do {
        data_ov031_02290cfc->slots[validIndex].valid = 0xff;
        validIndex++;
    } while (validIndex < 3);
    unsigned char buffer[20];
    func_ov031_0221bfe8(buffer);
    void* key = func_ov031_0221b8e4(buffer);
    unsigned int offset;
    int i = 0;
    offset = 0;
    do {
        SaveSlot* slot = (SaveSlot*)((char*)data_ov031_02290cfc + offset);
        VectorizedInvertedMemcpy(key, slot->key, 14);
        i++;
        offset += 0x100;
    } while (i < 2);
    int j = 0;
    do {
        func_ov031_02236570(j);
        j++;
    } while (j < 4);
}
