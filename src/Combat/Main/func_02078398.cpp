#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" void func_02076a8c(unsigned char* p);

struct BitFlag02033f44 {
    char pad[0xe0];
    unsigned char bits0_5 : 6;
    unsigned char flag40 : 1;
    unsigned char bit7 : 1;
    char pad2[3];
    int field_e4;
};
int* GetField0xe4IfFlag0x40(struct BitFlag02033f44* p);

extern "C" void* func_02057924(void);

struct InitStruct02078484Struct {
    unsigned char f00;
    unsigned char pad01[0xf];
    unsigned char f10;
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
    short f12;
    short f14;
    short f16;
    short f18;
    short f1a;
    short f1c;
    short pad1e;
    int f20; int f24; int f28; Vector3i f2c;
    int f38; int f3c; int f40;
    Vector3i f44;
};
void InitStruct02078484(struct InitStruct02078484Struct* p);

void FindNodeAndProcess02057fb4(void* list, int id, int a3);

struct Actor02078398 : Object3D {
    char padac[0x6];
    unsigned short fb2;
    char padb4[0xa4];
    Vector3fix f158;
    char pad164[0x14];
    short f178;
};

// USA: func_02078398
extern "C" ARM void func_02078398(struct Actor02078398* obj) {
    if (obj->GetInheritedAlpha() == 0) {
        func_02076a8c((unsigned char*)obj);
        obj->MakeHidden();
        return;
    }

    if (obj->GetInheritedAlpha() == 0x1f) {
        int* fp = GetField0xe4IfFlag0x40((struct BitFlag02033f44*)obj);
        Vector3fix v = obj->position_;
        v.y = 0;
        if (Vector3fix_Distance(&v, &obj->f158) < 0x2000 || fp != 0) {
            obj->fb2 = 0;
            obj->TransitionInheritedAlpha(0, 0x7d);
            if (obj->f178 > 0) {
                void* list = func_02057924();
                struct InitStruct02078484Struct s;
                InitStruct02078484(&s);
                s.f2c = obj->position_;
                s.f44 = obj->GetScale();
                FindNodeAndProcess02057fb4(list, (int)obj->f178, (int)&s);
            }
        }
    }
}
