#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue9A0_870 = 0x870 };
enum { kRegionValue9AE_7DE = 0x7de };
#else
enum { kRegionValue9A0_870 = 0x9a0 };
enum { kRegionValue9AE_7DE = 0x9ae };
#endif


extern "C" void* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void _Z17SetElementFieldC2P15Struct_0205d81cii(void*, int, int);

struct Obj0205dee8;
void SetFieldB0AndUpdate0205dee8(struct Obj0205dee8* obj, int val);

int StepStateMachine0215b7a4(void* p);

// USA: func_ov003_02159c04
// JPN: func_ov003_0215b084
extern "C" ARM void func_ov003_02159c04(void* self) {
    unsigned char* s = (unsigned char*)self;
    unsigned char* g = (unsigned char*)_Z26GetGlobalField0x1c020421a0v();

    if (*(int*)(g + kRegionValue9A0_870) == 3) {
        *(unsigned char*)(g + 0x1000 + kRegionValue9AE_7DE) = 0;
    }

    unsigned char state = *(unsigned char*)(s + 0x580);

    if (state == 0) {
        _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 0, 0);
        _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 1, 0);
        _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 2, 0);
        SetFieldB0AndUpdate0205dee8((struct Obj0205dee8*)(s + 0xf4), 1);
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (state != 1) return;

    int r = StepStateMachine0215b7a4(self);
    switch (r) {
    case -1:
        return;
    case 0:
        *(unsigned char*)(s + 0x588) = 3;
        break;
    case 1:
        *(unsigned char*)(s + 0x588) = 4;
        break;
    case 2:
        *(unsigned char*)(s + 0x588) = 5;
        break;
    case 3:
        *(unsigned char*)(s + 0x588) = 6;
        break;
    case 4:
        *(unsigned char*)(s + 0x588) = 7;
        break;
    case -2:
    case 5:
        *(unsigned char*)(s + 0x588) = 8;
        break;
    default:
        break;
    }
    *(unsigned char*)(s + 0x580) = 0;
}
