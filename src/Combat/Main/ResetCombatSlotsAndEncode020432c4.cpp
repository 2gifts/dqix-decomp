#include <globaldefs.h>
#include "Graphics/VRAMStaging.h"

struct State0204166c;
void Forward020416c0(struct State0204166c* s);

extern "C" void func_020439b0(void* self, int flag);

#if defined(jpn)
extern int data_0210773c;
extern int data_020e846c;
extern const char data_020efd90[];
#define data_021077fc data_0210773c
#define data_020e7af8 data_020e846c
extern "C" void func_02041bbc(void*);
extern "C" int func_02043014(int, unsigned short*);
extern "C" void func_02046530(void*, unsigned short*, int, int);
#else
extern int data_021077fc;
#endif
extern int data_020e7af8;

struct Target020432c4 {
    char pad0[0x68];
    unsigned int field68 : 16;
};

// USA: func_020432c4  (semantic: ResetCombatSlotsAndEncode020432c4)
extern "C" ARM void func_020432c4(char* obj) {
    struct Target020432c4* ptrField = *(struct Target020432c4**)(obj + (
#if defined(jpn)
0x1c4c
#else
0x1e28
#endif
));
    int i;

    if (ptrField != 0) {
        data_021077fc = ptrField->field68 << 3;
    }

    StageMemoryToVRAM(VRAMSubregion_TexturePalette, &data_020e7af8, data_021077fc, 0x20, true, true);

    for (i = 0; i < 0x80; i++) {
#if defined(jpn)
        func_02041bbc(obj + 0x888 + i * 0x1c);
        *(unsigned char*)(obj + i + 0x1688) = 0;
#else
        Forward020416c0((struct State0204166c*)(obj + 0x9b8 + i * 0x1c));
        *(unsigned char*)(obj + i + 0x17b8) = 0;
#endif
    }

#if defined(jpn)
    if (*(void**)(obj + 0x1c4c)) {
        *(unsigned char*)(obj + 0x1789) = 0;
        unsigned short* entry = *(unsigned short**)(data_020efd90 + 0x64);
        for (int j = 0; j < 14; j++, entry++) {
            func_02046530(obj, entry, func_02043014(12, entry), 12);
            *(unsigned char*)(obj + 0x1688 + j) = 1;
        }
    }
#endif
    func_020439b0(obj, 0);
}
