#include <globaldefs.h>


extern "C" int func_ov017_021d60f4(void* obj);
extern "C" void _ZN8Object3D11DisableFlagEi(unsigned char* obj, unsigned int mask);
extern "C" void _ZN8Object3D10EnableFlagEi(unsigned char* obj, unsigned int mask);

struct Obj02161524 { int field0; unsigned char pad0[0x18 - 4]; void* field18; };
struct Entry_02161524 { int type; unsigned char pad1[0xc - 4]; struct Obj02161524* child; };
struct DataTable_02161524 { char pad[4]; struct Entry_02161524* table; };
extern struct DataTable_02161524 data_ov001_02165880;

// USA: func_ov001_02161524
// JPN: func_ov001_02162b38
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
                _ZN8Object3D11DisableFlagEi((unsigned char*)child, 0x10);
            } else {
                _ZN8Object3D10EnableFlagEi((unsigned char*)child, 0x10);
            }
            break;
        }
        case 6: {
            struct Obj02161524* child = data_ov001_02165880.table[idx].child;
            if (child == 0 || child->field18 == 0) return 0;
            void* grandchild = child->field18;
            if (flag != 0) {
                _ZN8Object3D11DisableFlagEi((unsigned char*)grandchild, 0x10);
                data_ov001_02165880.table[idx].child->field0 &= ~0x40;
            } else {
                _ZN8Object3D10EnableFlagEi((unsigned char*)grandchild, 0x10);
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
