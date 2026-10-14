#include <globaldefs.h>

int TestFlagMask_02012430(unsigned short* obj, int mask);

extern unsigned short data_02114e30;

struct Obj0202aa94 {
    unsigned char pad[0x40];
    int state;
};

// USA: func_0202aa94  (semantic: CheckFlagStateGroupB_0202aa94)
extern "C" ARM int func_0202aa94(struct Obj0202aa94* obj) {
    switch (obj->state) {
    case 0:
        if (TestFlagMask_02012430(&data_02114e30, 0x80)) return 1;
    case 1:
        if (TestFlagMask_02012430(&data_02114e30, 0x80)) {
            if (TestFlagMask_02012430(&data_02114e30, 0x400)) return 1;
        }
    case 2:
        if (TestFlagMask_02012430(&data_02114e30, 0x80)) {
            if (TestFlagMask_02012430(&data_02114e30, 0x800)) return 1;
        }
    }
    return 0;
}
