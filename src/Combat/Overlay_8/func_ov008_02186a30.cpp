#include <globaldefs.h>

extern "C" int func_ov008_02186b18(void* obj, int a, int b);

struct SelfBB04;
extern "C" void func_0205bb04(struct SelfBB04*, int);
extern "C" int func_0205bf58(void*, void*);

extern unsigned char data_02114e54;
void SelectCoordsByFlag0x24_02012a84(unsigned char* obj, int* out1, int* out2);

// USA: func_ov008_02186a30
extern "C" ARM int func_ov008_02186a30(void* self, void* param1) {
    int state = 0;
    int idx = -1;
    int a, b;
    SelectCoordsByFlag0x24_02012a84(&data_02114e54, &a, &b);

    if (*(&data_02114e54 + 0x55) != 0) {
        state = 1;
        idx = func_ov008_02186b18(self, a, b);
        if (idx != -1) {
            func_0205bb04((struct SelfBB04*)((char*)self + 0x750), idx);
        }
    } else {
        if (*(&data_02114e54 + 0x5f) != 0 && *(unsigned short*)(&data_02114e54 + 0x24) != 0) {
            state = 1;
        } else if (*(&data_02114e54 + 0x54) != 0) {
            state = 1;
        }
    }

    if (state == 0) {
        func_0205bf58((char*)self + 0x750, param1);
    }
    if (state != 0) {
        if (idx == -1) return 0;
        if (idx == -2) return -2;
        if (idx >= 0) return 1;
    }
    return 0;
}
