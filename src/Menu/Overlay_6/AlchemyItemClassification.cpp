#include <globaldefs.h>

extern "C" ARM void func_ov006_0215745c(unsigned int itemClass, unsigned char* category, signed char* index)
{
    *index = -1;
    switch (itemClass) {
    case 0x48: *index = 0; return;
    case 0x49: *index = 1; return;
    case 0x4a: *index = 2; return;
    case 0x4b: *index = 3; return;
    case 0x4c: *index = 4; return;
    case 0x4d: *index = 5; return;
    case 0x4e: *index = 6; return;
    case 0x4f: *index = 7; return;
    case 0x50: *index = 8; return;
    case 0x51: *index = 9; return;
    case 0x52: *index = 10; return;
    case 0x53: *index = 11; return;
    case 0x40: *index = 12; return;
    case 0x41: *category = 4; return;
    case 0x42: *category = 2; return;
    case 0x43: *category = 5; return;
    case 0x44: *category = 3; return;
    case 0x45: *category = 6; return;
    }
}
