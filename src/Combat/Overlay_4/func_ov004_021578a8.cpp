#include <globaldefs.h>
#include "System/Matrix.h"

extern "C" void* func_ov004_02156fa0(void* obj, int key);

struct Struct021707d8_021578a8 { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_021578a8 data_ov004_021707d8;

class VObj021578a8 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06();
    virtual void SetPos(Vector3i* v);
    virtual Vector3i GetPos();
};

// USA: func_ov004_021578a8
extern "C" ARM void func_ov004_021578a8(void* obj) {
    Vector3i vec;

    VObj021578a8* node = (VObj021578a8*)func_ov004_02156fa0(obj, 0x517);
    if (node) {
        vec = node->GetPos();
        int x = (0xd1 - (data_ov004_021707d8.ptr[0x3e] << 3)) << 0xc;
        vec.x = x;
        vec.y = 0x26000;
        node->SetPos(&vec);
    }

    VObj021578a8* node2 = (VObj021578a8*)func_ov004_02156fa0(obj, 0x518);
    if (node2) {
        vec = node2->GetPos();
        int x2 = (0xd1 - (data_ov004_021707d8.ptr[0x3e] << 3)) << 0xc;
        vec.x = x2;
        vec.y = 0x34000;
        node2->SetPos(&vec);
    }
}
