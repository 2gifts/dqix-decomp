#include <globaldefs.h>

int TestFlagMask_02012430(unsigned short* obj, int mask);

extern unsigned short data_02114e30;

struct Obj0202a9f4 {
    unsigned char pad[0x40];
    int state;
};

// USA: func_0202a9f4  (semantic: CheckFlagStateGroupA_0202a9f4)
extern "C" ARM int func_0202a9f4(struct Obj0202a9f4* obj) {
    switch (obj->state) {
    case 0:
        if (TestFlagMask_02012430(&data_02114e30, 0x40)) return 1;
    case 1:
        if (TestFlagMask_02012430(&data_02114e30, 0x40)) {
            if (TestFlagMask_02012430(&data_02114e30, 0x400)) return 1;
        }
    case 2:
        if (TestFlagMask_02012430(&data_02114e30, 0x40)) {
            if (TestFlagMask_02012430(&data_02114e30, 0x800)) return 1;
        }
    }
    return 0;
}
