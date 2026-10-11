#include <globaldefs.h>

extern unsigned short __attribute__((aligned(4))) data_020e8a84[];
extern unsigned short data_02114e30[];

int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
int TestFlagMask(unsigned short* pad, int mask);

struct Sub0208203c {
    unsigned short field_0;
    unsigned char field_2;
};

struct Obj0208203c {
    struct Sub0208203c *field_0;
    unsigned short field_4;
    signed char field_6;
    signed char field_7;
    signed char field_8;
};

extern "C" void _Z20ResetWithSub0208203cP11Obj0208203c(struct Obj0208203c* obj);

// USA: func_02081f20
extern "C" ARM unsigned short func_02081f20(struct Obj0208203c* obj, int ticks) {
    if (obj->field_0 == NULL) return 0;
    obj->field_0->field_2 = 0;
    if (obj->field_0->field_0 == 0) {
        unsigned short ids[4];
        {
            const unsigned short* src = data_020e8a84;
            unsigned short* dst = ids;
            int n = 4;
            do {
                *dst++ = *src++;
            } while (--n);
        }
        int i;
        for (i = 0; i < 4; i++) {
            unsigned short id = ids[i];
            if (TestFlag0SetAndFlag1Clear(data_02114e30, id)) {
                obj->field_0->field_0 = id;
                obj->field_8 = obj->field_6;
                obj->field_0->field_2 = 1;
                goto end;
            }
        }
        goto end;
    }
    if (obj->field_0->field_0 != 0) {
        if (TestFlagMask(data_02114e30, obj->field_0->field_0)) {
            obj->field_8 -= (signed char)ticks;
            if (obj->field_8 < 0) {
                obj->field_8 += obj->field_7;
                obj->field_0->field_2 = 2;
            }
            goto end;
        }
        _Z20ResetWithSub0208203cP11Obj0208203c(obj);
    }
end:
    return obj->field_0->field_2;
}
