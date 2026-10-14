#include <globaldefs.h>

extern "C" int func_0205ec34(int obj);
void SetOrClearBitInArray_0206df6c(void* unused, unsigned char* array, int bit, int value);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c508(void* obj);
extern "C" void func_ov017_021d0924(int, int, unsigned short, int);
extern unsigned short data_ov017_021d6638[18];

// USA: func_ov017_0219e290
ARM void SetBitIfValueInTable_0219e290(void* obj, unsigned short val) {
    int base = func_0205ec34((int)obj);
    int idx = -1;
    for (unsigned int i = 0; i < 0x12; i++) {
        if (val == data_ov017_021d6638[i]) idx = i;
    }
    if (idx < 0) return;
    SetOrClearBitInArray_0206df6c((void*)base, (unsigned char*)base + 0x8c, idx + 0x200, 1);
    if (func_0202c508(func_0202ae18()) == 0) return;
    func_ov017_021d0924(1, 0, (unsigned short)idx, 1);
}
