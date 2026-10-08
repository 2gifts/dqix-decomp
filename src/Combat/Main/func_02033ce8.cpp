#include <globaldefs.h>

struct Obj02033b68 {
    char pad0[4];
    short f04;
    char pad[0xbe - 6];
    unsigned char fbe;
    unsigned char fbf;
    unsigned char fc0;
    unsigned char fc1 : 4;
    unsigned char fc1h : 4;
    unsigned char fc2a : 4;
    unsigned char fc2b : 1;
    unsigned char fc2c : 3;
    char pad2[0xe0 - 0xc3];
    unsigned char fe0;
};

extern "C" void func_02057924(void);
extern "C" void _Z28ApplyStateTableValue02033dd4Ph(unsigned char* obj);
extern "C" void _Z24SetByteIfChanged02033b68P11Obj02033b68i(struct Obj02033b68* obj, int newVal);
extern "C" int _ZNK8Object3D17GetInheritedAlphaEv(struct Obj02033b68* obj);
extern "C" void _ZN8Object3D10MakeHiddenEv(struct Obj02033b68* obj);
extern "C" void _ZN8Object3D17SetInheritedAlphaEi(struct Obj02033b68* obj, int val);
extern "C" void _ZN8Object3D24TransitionInheritedAlphaEii(struct Obj02033b68* obj, int a, int b);

// USA: func_02033ce8
extern "C" ARM void func_02033ce8(struct Obj02033b68* p) {
    int b;
    func_02057924();
    _Z28ApplyStateTableValue02033dd4Ph((unsigned char*)p);

    if (p->fbe == 3 || p->fbe == 4) {
        if (p->fc0 == 7 || p->fc0 == 8) {
            if (p->fc0 != 7) return;
            if (p->fc1h == 0) return;
            _Z24SetByteIfChanged02033b68P11Obj02033b68i(p, 0);
        }
        return;
    }

    if (p->fbe == 6) {
        if (p->fbf != 6) {
            b = (p->f04 >= 0 && p->f04 <= 3);
            if (!b) {
                if (p->fc2b == 0) {
                    p->fe0 |= 8;
                }
            }
        }
        if (_ZNK8Object3D17GetInheritedAlphaEv(p) > 0) return;
        _ZN8Object3D10MakeHiddenEv(p);
        return;
    }

    if (p->fbe == 5) {
        _ZN8Object3D17SetInheritedAlphaEi(p, 1);
        _ZN8Object3D24TransitionInheritedAlphaEii(p, 0x1f, 0xfa);
    }
}