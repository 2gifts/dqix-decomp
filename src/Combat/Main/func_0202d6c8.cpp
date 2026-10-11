#include <globaldefs.h>
void CopyFrom027ffcf4(void*);
void SetField0x48UnlessState9Or10(int);
extern "C" int func_0202d788(unsigned short);
extern char data_021015a0[];
// USA: 0202d6c8; JPN: 0202d238
static inline unsigned clockValue() { unsigned value=*(unsigned*)0x027ffc3c; return value; }
extern "C" ARM int func_0202d6c8() {
    unsigned short mac[3];
    CopyFrom027ffcf4(mac);
    *(unsigned*)(data_021015a0 + 0x20) = (mac[0] + clockValue() + mac[1] + mac[2]) * 0x00010dcd + 0x3039;
    *(unsigned short*)(data_021015a0 + 2) = 0;
    *(unsigned short*)(data_021015a0 + 6) = 0x65;
    *(int*)(data_021015a0 + 0x10) = 3;
    int result = func_0202d788(1);
    if (result == 0x18) { SetField0x48UnlessState9Or10(0x18); *(int*)(data_021015a0 + 0x10) = 9; return 0; }
    if (result == 2) return 1;
    SetField0x48UnlessState9Or10(result);
    *(int*)(data_021015a0 + 0x10) = 9;
    return 0;
}
