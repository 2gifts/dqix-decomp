#include <globaldefs.h>
#include "World/Object3D.h"

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
void ApplyStateTableValue02033dd4(unsigned char* obj);
void SetByteIfChanged02033b68(struct Obj02033b68* obj, int newVal);

// USA: func_02033ce8
extern "C" ARM void func_02033ce8(struct Obj02033b68* p) {
    int b;
    func_02057924();
    ApplyStateTableValue02033dd4((unsigned char*)p);

    if (p->fbe == 3 || p->fbe == 4) {
        if (p->fc0 == 7 || p->fc0 == 8) {
            if (p->fc0 != 7) return;
            if (p->fc1h == 0) return;
            SetByteIfChanged02033b68(p, 0);
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
        if (((Object3D*)p)->GetInheritedAlpha() > 0) return;
        ((Object3D*)p)->MakeHidden();
        return;
    }

    if (p->fbe == 5) {
        ((Object3D*)p)->SetInheritedAlpha(1);
        ((Object3D*)p)->TransitionInheritedAlpha(0x1f, 0xfa);
    }
}
