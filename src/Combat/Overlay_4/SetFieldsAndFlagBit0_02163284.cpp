#include <globaldefs.h>

extern "C" void* func_ov004_0215e47c(void* a, int key);
extern unsigned char data_ov004_021707e8;

// USA: func_ov004_02163284
ARM int SetFieldsAndFlagBit0_02163284(void* a) {
#if defined(jpn)
    enum { firstOffset = 0x10, secondOffset = 0x20 };
#else
    enum { firstOffset = 0x20, secondOffset = 0x24 };
#endif
    *(int*)((char*)&data_ov004_021707e8 + firstOffset) = -1;
    *(int*)((char*)&data_ov004_021707e8 + secondOffset) = 0;
    unsigned char* node = (unsigned char*)func_ov004_0215e47c(a, 9);
    node[0xc] |= 1;
    return 0;
}
