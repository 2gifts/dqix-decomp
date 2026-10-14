#include <globaldefs.h>
#include "System/Matrix.h"

class VObj0216b390 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06();
    virtual void Method1c(Vector3i* arg);
    virtual Vector3i Method20();
};

extern "C" int func_ov004_0216af24(void* a, int key);
extern "C" void* func_ov011_021849c8(void* a);
extern "C" VObj0216b390* func_ov023_021f6880(void* obj, int key);

// USA: func_ov004_0216b390  (semantic: OffsetPositionAndNotify_0216b390)
extern "C" ARM void func_ov004_0216b390(void* a, int rawKey, int axis) {
    Vector3i v2;
    Vector3i v4;

    int delta = func_ov004_0216af24(a, (short)rawKey);
    VObj0216b390* node1 = func_ov023_021f6880(func_ov011_021849c8(a), rawKey);
    if (!node1) return;

    const Vector3i& v1 = node1->Method20();
    v2 = v1;
    v2.x = v2.x + ((delta + 0xa) << 12);

    VObj0216b390* node2 = func_ov023_021f6880(func_ov011_021849c8(a), 0xc);
    if (!node2) return;

    const Vector3i& v3 = node2->Method20();
    v4 = v3;
    v4.x = v2.x;

    if (axis == 0) v4.y = 0x24000;
    else if (axis == 1) v4.y = 0x34000;
    else if (axis == 2) v4.y = 0x42000;
    else if (axis == 3) v4.y = 0x1b000;

    node2->Method1c(&v4);
    *((unsigned char*)node2 + 0x3a) = 0;
}
