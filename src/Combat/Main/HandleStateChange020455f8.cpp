#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);

extern int data_02108760;
extern int data_02107820;

struct State020455f8 {
    unsigned char pad0[IS_JPN ? 0x86c : 0x99c];
    int state99c;
    unsigned char pad1[IS_JPN ? 0xf72 : 0x1012];
    unsigned char f19b2;
    unsigned char f19b3;
};

// JPN: 0x02046268
// USA: func_020455f8
ARM void HandleStateChange020455f8(struct State020455f8* obj) {
    if (obj->f19b3 == 1 || obj->f19b2 == 0) {
        return;
    }
    switch (obj->state99c) {
        case 0:
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 0xa, (int)&data_02107820);
            break;
        case 1:
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 0xc, (int)&data_02107820);
            break;
        case 2:
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 0xb, (int)&data_02107820);
            break;
    }
    obj->f19b3 = 1;
}
