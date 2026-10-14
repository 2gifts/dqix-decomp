#if defined(jpn)
enum { RegionOffset424 = 0x444 };
#else
enum { RegionOffset424 = 0x424 };
#endif

#include <globaldefs.h>
#include "System/Matrix.h"

extern "C" int func_ov017_021d446c(void* obj, void* out, int flags);
extern "C" int func_02012fe4(void);
extern "C" int func_02018fbc(int seed, Vector3i* v);
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

    Vector3i v;
    v.x = evt->fieldC;
    v.y = evt->fieldA << 4;
    v.z = evt->field10;
    short y = evt->field8;
    int mode = evt->field6;

    int g = func_02012fe4();
    if (evt->field4 == *(unsigned short*)g && *(int*)((char*)g + RegionOffset424) == 0) {
        v.y = func_02018fbc(g, &v);
    }

    *(short*)((char*)local[2] + 0x100 + 0x66) = evt->field7;
    *(Vector3i*)((char*)local[2] + 0x158) = v;
    SetVecYByMode02033834((struct Obj02033834*)local[2], y);
    TrySetMode02076ccc((void*)local[2], mode);
}
