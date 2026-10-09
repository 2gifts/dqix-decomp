#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"
#include "std_library_functions.h"

struct Foo02048004;
extern "C" void func_02047a78(struct Foo02048004* obj, char* name, int flag);

extern char data_020f14d0[];

// USA: func_02096604
ARM void InitFourNamedSubStructs(char* base, int flag) {
    int i;
    char buf[0x40];
    for (i = 0; i < 4; i++) {
        sprintf(buf, data_020f14d0, i);
        func_0204719c((struct Foo02048004*)(base + i * 0x88));
        func_02047a78((struct Foo02048004*)(base + i * 0x88), buf, flag);
    }
    *(unsigned char*)(base + 0x220) = 0;
    *(unsigned char*)(base + 0x221) = 0;
    *(unsigned char*)(base + 0x222) = 0;
    *(unsigned char*)(base + 0x223) = 0;
    *(unsigned char*)(base + 0x224) = 0;
    *(unsigned char*)(base + 0x225) = 0;
    *(unsigned short*)(base + 0x228) = 0;
    *(unsigned short*)(base + 0x22a) = 0;
    *(unsigned short*)(base + 0x22c) = 0;
    *(unsigned char*)(base + 0x230) = 0;
    *(unsigned char*)(base + 0x226) = 0;
}
