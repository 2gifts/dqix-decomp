#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
enum { MiddleFieldDelta = 0x20, TailFieldDelta = 0x40 };
#else
enum { MiddleFieldDelta = 0, TailFieldDelta = 0 };
#endif

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
// JPN: func_020134e0
extern "C" ARM void func_020134e0(char* obj) {
    void* gs = _ZN9GameState11GetInstanceEv();

    *(short*)(obj + 0x0) = 0;
    *(short*)(obj + 0x2) = 0;
    *(short*)(obj + 0x4) = 0;
    *(int*)(obj + 0x424 + MiddleFieldDelta) = 0;
    *(int*)(obj + 0x8) = 0;
    *(int*)(obj + 0x4c + MiddleFieldDelta) = 0;
    *(int*)(obj + 0x68 + MiddleFieldDelta) = 0;
    *(int*)(obj + 0x50 + MiddleFieldDelta) = 0;
    *(char*)(obj + 0x476 + MiddleFieldDelta) = 0;
    *(char*)(obj + 0x477 + MiddleFieldDelta) = 0;
    *(int*)(obj + 0x82c + MiddleFieldDelta) = 0;
    *(char*)(obj + 0x830 + MiddleFieldDelta) = 0;
    *(int*)(obj + 0x428 + MiddleFieldDelta) = 1;
    *(int*)(obj + 0x838 + MiddleFieldDelta) = 0;
    *(int*)(obj + 0x83c + MiddleFieldDelta) = 0;
    *(char*)(obj + 0x42c + MiddleFieldDelta) = 0;
    *(int*)(obj + 0x41c + MiddleFieldDelta) = 0;
    *(int*)(obj + 0x418 + MiddleFieldDelta) = 0;
    *(int*)(obj + 0x478 + MiddleFieldDelta) = 0;
    *(int*)(obj + 0x47c + MiddleFieldDelta) = 0;
    *(char*)(obj + 0x834 + MiddleFieldDelta) = 0;
    *(char*)(obj + 0x23b8 + MiddleFieldDelta) = 0;
    *(char*)(obj + 0x23b9 + MiddleFieldDelta) = 0;
    *(int*)(obj + 0x420 + MiddleFieldDelta) = 0;
    *(char*)(obj + 0x23bc + MiddleFieldDelta) = 0;
    *(int*)(obj + 0x276c + TailFieldDelta) = -1;
    *(int*)(obj + 0x2770 + TailFieldDelta) = 0;
    *(char*)(obj + 0x831 + MiddleFieldDelta) = 0;
    *(char*)(obj + 0x832 + MiddleFieldDelta) = 0;
    *(char*)(obj + 0x833 + MiddleFieldDelta) = 0;
    *(char*)(obj + 0x281f + TailFieldDelta) = 0;
    *(char*)(obj + 0x2820 + TailFieldDelta) = 0;
    *(short*)(obj + 0x27d6 + TailFieldDelta) = 0;
    *(char*)(obj + 0x23bb + MiddleFieldDelta) = -1;

    _ZN12ZoneFeatures5ResetEv(obj + 0x6c + MiddleFieldDelta);
    _ZN20AtmosphericEffectSet5ResetEv(obj + 0xf4 + MiddleFieldDelta);
    _ZN12LightingInfo10InitializeEv(obj + 0x10c + MiddleFieldDelta);
    _ZN13SafeAllocator21ResetAllocatorPointerEv(obj + 0x54 + MiddleFieldDelta);
    _ZN13SafeAllocator21ResetAllocatorPointerEv(obj + 0x2730 + TailFieldDelta);
    _ZN7Model3D5ClearEv(obj + 0x498 + MiddleFieldDelta);
    _ZN7Model3D5ClearEv(obj + 0x544 + MiddleFieldDelta);
    _Z23ClearThreeWords02094d00P29ClearThreeWords02094d00Struct(obj + 0x2724 + TailFieldDelta);

    *(int*)(obj + 0x27c4 + TailFieldDelta) = 0;
    *(int*)(obj + 0x27b8 + TailFieldDelta) = 0;
    *(int*)(obj + 0x27bc + TailFieldDelta) = 0xa000;
    *(int*)(obj + 0x27c0 + TailFieldDelta) = 0;
    *(int*)(obj + 0x820 + MiddleFieldDelta) = 0;
    _Z19ResetFourSubStructsPc(obj + 0x600 + MiddleFieldDelta);
    memset(obj + 0x27dc + TailFieldDelta, 0, 0x40);

    *(char*)(obj + 0x281c + TailFieldDelta) = 0;
    *(char*)(obj + 0x2744 + TailFieldDelta) = 0;
    *(char*)(obj + 0x2745 + TailFieldDelta) = 1;
    *(char*)(obj + 0x2746 + TailFieldDelta) = 0;
    *(short*)(obj + 0x2748 + TailFieldDelta) = 0;
    *(int*)(obj + 0x274c + TailFieldDelta) = 1;
    *(int*)(obj + 0x2750 + TailFieldDelta) = 1;

    if (_Z10GetByte0x4Pc((char*)gs) != 5) {
        *(short*)(obj + 0x27d8 + TailFieldDelta) = 0;
        *(short*)(obj + 0x27da + TailFieldDelta) = 0;
    }
    *(char*)(obj + 0x281d + TailFieldDelta) = 0;
    *(char*)(obj + 0x281e + TailFieldDelta) = 0;
    if (_Z18GetByteField0x63d6P20FieldBlock63d6_115a8(gs) != 0) {
        return;
    }

    if (_Z13GetWord0x7f6cPv(gs) == 5 || _Z10GetByte0x4Pc((char*)gs) == 4 ||
        _Z10GetByte0x4Pc((char*)gs) == 2) {
        func_020982b4(obj + 0x840 + MiddleFieldDelta);
        *(short*)(obj + 0x27b4 + TailFieldDelta) = 2;
        *(short*)(obj + 0x27b6 + TailFieldDelta) = 0;
        *(short*)(obj + 0x2784 + TailFieldDelta) = 0;
        *(short*)(obj + 0x2786 + TailFieldDelta) = 0x76c;
        *(char*)(obj + 0x2788 + TailFieldDelta) = 0;
        *(int*)(obj + 0x2780 + TailFieldDelta) = 0;
        *(int*)(obj + 0x2794 + TailFieldDelta) = 0x50;
        *(char*)(obj + 0x27d0 + TailFieldDelta) = 0;
        *(int*)(obj + 0x2774 + TailFieldDelta) = 0x19000;
        *(int*)(obj + 0x2778 + TailFieldDelta) = 0x199;
        *(int*)(obj + 0x277c + TailFieldDelta) = 0x38ccc;
    }
}
