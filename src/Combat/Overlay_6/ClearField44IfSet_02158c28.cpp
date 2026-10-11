#if defined(jpn)
#define R(j,u) (j)
#define data_ov006_0215fffe data_ov006_02161350
#define func_ov006_0215f3d8 func_ov006_021607f8
#define func_ov006_0215f4dc func_ov006_021608fc
#define func_ov006_0215f740 func_ov006_02160b08
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern unsigned short data_02114e30;

struct StructC28 {
    char pad0[R(0x3c, 0x44)];
    short* field44;
    char pad48[0x38f - R(0x40, 0x48)];
    unsigned char field38f;
    unsigned char field390;
};

// USA: func_ov006_02158c28
ARM void ClearField44IfSet_02158c28(struct StructC28* obj) {
    if (!TestFlag0SetAndFlag1Clear(&data_02114e30, 0x800)) {
        return;
    }
    if (obj->field44 != 0) {
        *obj->field44 = -1;
    }
    obj->field44 = 0;
    obj->field38f = 0xc;
    obj->field390 = 0;
}
