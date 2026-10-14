#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" int func_ov017_021d60f4(void* obj);

struct Obj02161524 { int field0; unsigned char pad0[0x18 - 4]; void* field18; };
struct Entry_02161524 { int type; unsigned char pad1[0xc - 4]; struct Obj02161524* child; };
struct DataTable_02161524 { char pad[4]; struct Entry_02161524* table; };
extern struct DataTable_02161524 data_ov001_02165880;

// USA: func_ov001_02161524
extern "C" ARM int func_ov001_02161524(void* self) {
    int idx = func_ov017_021d60f4(self);
    int flag = func_ov017_021d60f4((char*)self + 0x8);
    switch (data_ov001_02165880.table[idx].type) {
        case 0:
        case 1:
        case 4:
        case 5: {
            struct Obj02161524* child = data_ov001_02165880.table[idx].child;
            if (child == 0) return 0;
            if (flag != 0) {
                ((Object3D*)((unsigned char*)child))->DisableFlag(0x10);
            } else {
                ((Object3D*)((unsigned char*)child))->EnableFlag(0x10);
            }
            break;
        }
        case 6: {
            struct Obj02161524* child = data_ov001_02165880.table[idx].child;
            if (child == 0 || child->field18 == 0) return 0;
            void* grandchild = child->field18;
            if (flag != 0) {
                ((Object3D*)((unsigned char*)grandchild))->DisableFlag(0x10);
                data_ov001_02165880.table[idx].child->field0 &= ~0x40;
            } else {
                ((Object3D*)((unsigned char*)grandchild))->EnableFlag(0x10);
                data_ov001_02165880.table[idx].child->field0 |= 0x40;
            }
            break;
        }
        case 2: {
            struct Obj02161524* child = data_ov001_02165880.table[idx].child;
            if (child == 0) return 0;
            if (flag != 0) {
                child->field0 &= ~0x40;
            } else {
                child->field0 |= 0x40;
            }
            break;
        }
        default:
            break;
    }
    return 1;
}
