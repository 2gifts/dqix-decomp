#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" void _ZN12ZoneFeatures5ResetEv(void* obj);
extern "C" void _ZN20AtmosphericEffectSet5ResetEv(void* obj);
extern "C" void _ZN12LightingInfo10InitializeEv(void* obj);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void* obj);
extern "C" void _ZN7Model3D5ClearEv(void* obj);
extern "C" void _Z23ClearThreeWords02094d00P29ClearThreeWords02094d00Struct(void* obj);
extern "C" void _Z19ResetFourSubStructsPc(char* obj);
extern "C" void func_020982b4(void* obj);
extern "C" unsigned char _Z10GetByte0x4Pc(char* gs);
extern "C" int _Z13GetWord0x7f6cPv(void* gs);
extern "C" unsigned char _Z18GetByteField0x63d6P20FieldBlock63d6_115a8(void* gs);

// USA: func_020134e0
extern "C" ARM void func_020134e0(char* obj) {
    void* gs = _ZN9GameState11GetInstanceEv();

    *(short*)(obj + 0x0) = 0;
    *(short*)(obj + 0x2) = 0;
    *(short*)(obj + 0x4) = 0;
    *(int*)(obj + 0x424) = 0;
    *(int*)(obj + 0x8) = 0;
    *(int*)(obj + 0x4c) = 0;
    *(int*)(obj + 0x68) = 0;
    *(int*)(obj + 0x50) = 0;
    *(char*)(obj + 0x476) = 0;
    *(char*)(obj + 0x477) = 0;
    *(int*)(obj + 0x82c) = 0;
    *(char*)(obj + 0x830) = 0;
    *(int*)(obj + 0x428) = 1;
    *(int*)(obj + 0x838) = 0;
    *(int*)(obj + 0x83c) = 0;
    *(char*)(obj + 0x42c) = 0;
    *(int*)(obj + 0x41c) = 0;
    *(int*)(obj + 0x418) = 0;
    *(int*)(obj + 0x478) = 0;
    *(int*)(obj + 0x47c) = 0;
    *(char*)(obj + 0x834) = 0;
    *(char*)(obj + 0x23b8) = 0;
    *(char*)(obj + 0x23b9) = 0;
    *(int*)(obj + 0x420) = 0;
    *(char*)(obj + 0x23bc) = 0;
    *(int*)(obj + 0x276c) = -1;
    *(int*)(obj + 0x2770) = 0;
    *(char*)(obj + 0x831) = 0;
    *(char*)(obj + 0x832) = 0;
    *(char*)(obj + 0x833) = 0;
    *(char*)(obj + 0x281f) = 0;
    *(char*)(obj + 0x2820) = 0;
    *(short*)(obj + 0x27d6) = 0;
    *(char*)(obj + 0x23bb) = -1;

    _ZN12ZoneFeatures5ResetEv(obj + 0x6c);
    _ZN20AtmosphericEffectSet5ResetEv(obj + 0xf4);
    _ZN12LightingInfo10InitializeEv(obj + 0x10c);
    _ZN13SafeAllocator21ResetAllocatorPointerEv(obj + 0x54);
    _ZN13SafeAllocator21ResetAllocatorPointerEv(obj + 0x2730);
    _ZN7Model3D5ClearEv(obj + 0x498);
    _ZN7Model3D5ClearEv(obj + 0x544);
    _Z23ClearThreeWords02094d00P29ClearThreeWords02094d00Struct(obj + 0x2724);

    *(int*)(obj + 0x27c4) = 0;
    *(int*)(obj + 0x27b8) = 0;
    *(int*)(obj + 0x27bc) = 0xa000;
    *(int*)(obj + 0x27c0) = 0;
    *(int*)(obj + 0x820) = 0;
    _Z19ResetFourSubStructsPc(obj + 0x600);
    memset(obj + 0x27dc, 0, 0x40);

    *(char*)(obj + 0x281c) = 0;
    *(char*)(obj + 0x2744) = 0;
    *(char*)(obj + 0x2745) = 1;
    *(char*)(obj + 0x2746) = 0;
    *(short*)(obj + 0x2748) = 0;
    *(int*)(obj + 0x274c) = 1;
    *(int*)(obj + 0x2750) = 1;

    if (_Z10GetByte0x4Pc((char*)gs) != 5) {
        *(short*)(obj + 0x27d8) = 0;
        *(short*)(obj + 0x27da) = 0;
    }
    *(char*)(obj + 0x281d) = 0;
    *(char*)(obj + 0x281e) = 0;
    if (_Z18GetByteField0x63d6P20FieldBlock63d6_115a8(gs) != 0) {
        return;
    }

    if (_Z13GetWord0x7f6cPv(gs) == 5 || _Z10GetByte0x4Pc((char*)gs) == 4 ||
        _Z10GetByte0x4Pc((char*)gs) == 2) {
        func_020982b4(obj + 0x840);
        *(short*)(obj + 0x27b4) = 2;
        *(short*)(obj + 0x27b6) = 0;
        *(short*)(obj + 0x2784) = 0;
        *(short*)(obj + 0x2786) = 0x76c;
        *(char*)(obj + 0x2788) = 0;
        *(int*)(obj + 0x2780) = 0;
        *(int*)(obj + 0x2794) = 0x50;
        *(char*)(obj + 0x27d0) = 0;
        *(int*)(obj + 0x2774) = 0x19000;
        *(int*)(obj + 0x2778) = 0x199;
        *(int*)(obj + 0x277c) = 0x38ccc;
    }
}