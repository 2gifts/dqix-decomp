#include <globaldefs.h>

int TestFlagMask_02012430(unsigned short* obj, int mask);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short* obj, int mask);

struct Obj0201248c {
    unsigned char pad[0x18];
    int f18;
};

// USA: func_0201248c  (semantic: UpdateFlagCountdown0201248c)
extern "C" ARM int func_0201248c(struct Obj0201248c* obj, int mask) {
    if (TestFlagMask_02012430((unsigned short*)obj, mask)) {
        int v = obj->f18;
        if (v == 0) {
            if (TestFlag0SetAndFlag1Clear_02012444((unsigned short*)obj, mask)) {
                obj->f18 = 8;
                return 1;
            } else {
                obj->f18 = 0;
                return 1;
            }
        }
        obj->f18 = v - 1;
    } else {
        if (TestFlagMask_02012430((unsigned short*)obj, 0xfff7) == 0) {
            obj->f18 = 0;
        }
    }
    return 0;
}
