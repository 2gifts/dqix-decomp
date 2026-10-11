#include <globaldefs.h>
#if defined(jpn)
#define data_020f057c data_020f05e4
#define data_ov031_02257180 data_ov031_02257960
#define data_020f0594 data_020f05fc
#endif

extern int data_020f057c;
extern int data_020f0594;
extern int data_ov031_02257180;

extern "C" void func_0203a974(void* obj, int addr, void* ovAddr, int size, int flag);

int GetFromField00203aa64(void* obj);
int DispatchIndexedCommand0203aa98(void* obj, int index);

// USA: func_0205ea20
ARM void SetupContextForMode0205ea20(void* objRaw, int mode) {
    char* obj = (char*)objRaw;
    int addr = 0;
    if (mode == 0x64) {
        addr = (int)&data_020f057c;
    } else if (mode == 0x65) {
        addr = (int)&data_020f0594;
    }
    if (addr != 0) {
        func_0203a974(obj, addr, &data_ov031_02257180, 0x4b000, 0);
    }
    *(int*)(obj + 0xb0) = GetFromField00203aa64(obj);
    *(short*)(obj + 0xb4) = (short)mode;
    DispatchIndexedCommand0203aa98(obj, mode);
    int r = GetFromField00203aa64(obj);
    *(int*)(obj + 0xc0) = r;
    *(int*)(obj + 0xb8) = r;
}
