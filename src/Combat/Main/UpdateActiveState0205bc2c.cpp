#include <globaldefs.h>

extern unsigned char data_02114e54;
void SelectCoordsByFlag0x24_02012a84(unsigned char*, int*, int*);
extern "C" int func_0205bd78(void* p, int b, int c);

struct Struct_0205bc2c {
    int field0;
    char pad0[0x30 - 0x4];
    int field30;
    char pad1[0x4c - 0x34];
    unsigned char field4c;
    unsigned char field4d;
    unsigned char field4e;
};

// USA: func_0205bc2c
ARM int UpdateActiveState0205bc2c(Struct_0205bc2c* obj, int) {
    int v1, v2;

    if (obj->field0 == 0) return 0;

    SelectCoordsByFlag0x24_02012a84(&data_02114e54, &v1, &v2);

    if ((&data_02114e54)[0x55] != 0 && obj->field4e == 0) {
        int prevField30;

        obj->field4e = 1;
        prevField30 = obj->field30;
        obj->field30 = func_0205bd78(obj, v1, v2);
        if (obj->field30 < 0) {
            obj->field4e = 0;
            return 0;
        }
        obj->field4c = 1;
        if (prevField30 != obj->field30) obj->field4c = 0;
        return 1;
    }

    obj->field4c = 0;
    obj->field4e = 0;
    return 0;
}
