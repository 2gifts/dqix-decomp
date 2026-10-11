#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue9A0_870 = 0x870 };
enum { kRegionValue9AE_7DE = 0x7de };
enum { kRegionValue4EC_4E8 = 0x4e8 };
#else
enum { kRegionValue9A0_870 = 0x9a0 };
enum { kRegionValue9AE_7DE = 0x9ae };
enum { kRegionValue4EC_4E8 = 0x4ec };
#endif


int GetGlobalField0x1c020421a0();
extern "C" int func_ov003_02169b30(void* obj);

// USA: func_ov003_02168cc8
// JPN: func_ov003_02168b48
ARM void SwitchSetField4ec_02168cc8(void* obj) {
    int g = GetGlobalField0x1c020421a0();
    if (*(int*)(g + kRegionValue9A0_870) == 3) {
        *(unsigned char*)(g + 0x1000 + kRegionValue9AE_7DE) = 0;
    }
    int ret = func_ov003_02169b30(obj);
    switch (ret) {
        case -1:
            return;
        case 0:
            *((unsigned char*)obj + kRegionValue4EC_4E8) = 3;
            break;
        case 1:
            *((unsigned char*)obj + kRegionValue4EC_4E8) = 4;
            break;
        case -2:
        case 2:
            *((unsigned char*)obj + kRegionValue4EC_4E8) = 5;
            break;
    }
}
