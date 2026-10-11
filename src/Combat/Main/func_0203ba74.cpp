#include <globaldefs.h>

extern "C" void LoadToSubBG0ScreenData(int data, int offset, unsigned int length);
extern "C" void LoadToSubBG1ScreenData(int data, int offset, unsigned int length);

extern char data_02105fd8[] __attribute__((aligned(4)));
extern char data_021065d8[];

// USA: func_0203ba74
extern "C" ARM void func_0203ba74(void* objPtr) {
    char* obj = (char*)objPtr;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            unsigned char zero = 0;
            zero = zero + 0;
            int* flag = (int*)(obj + (j + i * 4) * 4 + 0x40);
            if (*flag != 0) {
                *flag = zero;
                if (i == 1) {
                    switch (j) {
                    case 0: LoadToSubBG0ScreenData((int)data_021065d8, zero, 0x1000); break;
                    case 1: LoadToSubBG1ScreenData((int)data_02105fd8, zero, 0x600); break;
                    }
                }
            }
        }
    }
}
