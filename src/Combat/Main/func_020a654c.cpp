#include <globaldefs.h>

struct Res020a654c {
#if defined(jpn)
    char pad0[0x34ec];
#else
    char pad0[0x36fc];
#endif
    void* nodeList;
};

struct List020a654c {
    char pad0[3];
    unsigned char f3;
};

struct Out020a654c {
    int f0;
    int f4;
};

extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* func_02012fe4();
extern "C" void func_0202ae18();
extern "C" void* _Z17GetPointerAt0x32cP20PointerField32c_ffc0(void* p);
extern "C" void* _ZN9GameState20GetUnknownGameObjectEv(void* p);
extern "C" int _Z23GetHeadNodeIdOrMinusOnePP16HeadNode02046b24(void* p);
extern "C" void* _Z23GetField0x0List02046b1cP9S02046b1c(void* p);
extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(void* res);
extern "C" void func_020a75ec(void* p);
extern "C" int _Z15GetBitsInField0Pjj(void* p, unsigned int bits);
extern "C" void _Z31DispatchWithZeroExtras_02193428PvS_(void* p, short v);
extern "C" void func_020a7ce0(void* p);
extern "C" int func_020a7d74(void* p, int* out1, int* out2);
extern "C" int _Z12IsField0NullPPv(void* p);
extern "C" int func_ov017_021a93f0(void* res, int a, int b);

// USA: func_020a654c
// JPN: func_020a654c
extern "C" ARM void func_020a654c(struct Res020a654c* self) {
    void* gs = _ZN9GameState11GetInstanceEv();
    unsigned short* p;
    void* nodeList = self->nodeList;
    p = (unsigned short*)func_02012fe4();
    func_0202ae18();
    void* obj = _Z17GetPointerAt0x32cP20PointerField32c_ffc0(gs);
    _ZN9GameState20GetUnknownGameObjectEv(gs);
    int id = _Z23GetHeadNodeIdOrMinusOnePP16HeadNode02046b24(nodeList);
    void* lst = _Z23GetField0x0List02046b1cP9S02046b1c(nodeList);
    if (obj == 0) {
        return;
    }
    if (id == 10 && ((struct List020a654c*)lst)->f3 != 0) {
        return;
    }
    if (id == 3) {
        if (_Z28IsBrightnessTransitionActiveP13GameResources(self) == 0) {
            return;
        }
    }
    func_020a75ec(obj);
    if (_Z15GetBitsInField0Pjj(self, 0x2020) == 0) {
        _Z31DispatchWithZeroExtras_02193428PvS_(obj, 1);
    }
    if (*p == 0x2710) {
        func_020a7ce0(obj);
    }
    if (_Z15GetBitsInField0Pjj(self, 0x2020) != 0) {
        return;
    }
    struct Out020a654c out;
    out.f4 = 0;
    out.f0 = 0;
    if (func_020a7d74(obj, &out.f4, &out.f0) == 0) {
        return;
    }
    if (out.f0 != 0 && out.f0 == 1) {
        out.f4 = 0x76c;
    }
    if (out.f4 == 0) {
        return;
    }
    if (_Z12IsField0NullPPv(self->nodeList) == 0) {
        return;
    }
    func_ov017_021a93f0(self, out.f4, 0);
}
