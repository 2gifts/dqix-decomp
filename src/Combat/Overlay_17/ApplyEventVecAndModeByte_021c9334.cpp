// JPN: func_ov017_021c97e4
#if defined(jpn)
enum { RegionOffset424 = 0x444 };
#else
enum { RegionOffset424 = 0x424 };
#endif

#include <globaldefs.h>
#include "Combat/Overlay_1/EventArgs.h"

extern "C" int func_ov017_021d446c(void* obj, void* out, int flags);
extern "C" int func_02012fe4(void);
extern "C" int func_02018fbc(int seed, EventVec3* v);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
struct Obj02033834;
void SetVecYByMode02033834(struct Obj02033834* obj, int arg);
void TrySetMode02076ccc(void*, int);

struct LocalEvt021c9334 {
    unsigned char pad0[4];
    unsigned short field4;
    unsigned char field6 : 6;
    unsigned char pad6b : 2;
    signed char pad7a : 4;
    signed char field7 : 4;
    short field8;
    short fieldA;
    int fieldC;
    int field10;
};

// USA: func_ov017_021c9334  (semantic: ApplyEventVecAndModeByte_021c9334)
extern "C" ARM void func_ov017_021c9334(int unused0, LocalEvt021c9334* evt) {
    int local[3];
    if (!func_ov017_021d446c((char*)evt + 4, local, -1)) return;
    if (*(int*)((char*)local[2] + 0x130) == 9) return;

    EventVec3 v;
    v.a = evt->fieldC;
    v.b = evt->fieldA << 4;
    v.c = evt->field10;
    short y = evt->field8;
    int mode = evt->field6;

    int g = func_02012fe4();
    if (evt->field4 == *(unsigned short*)g && *(int*)((char*)g + RegionOffset424) == 0) {
        v.b = func_02018fbc(g, &v);
    }

    *(short*)((char*)local[2] + 0x100 + 0x66) = evt->field7;
    _ZN8Vector3iaSERKS_((int*)((char*)local[2] + 0x158), (int*)&v);
    SetVecYByMode02033834((struct Obj02033834*)local[2], y);
    TrySetMode02076ccc((void*)local[2], mode);
}
