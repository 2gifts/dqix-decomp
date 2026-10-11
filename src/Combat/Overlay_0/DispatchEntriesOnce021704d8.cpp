#include <globaldefs.h>

struct Struct0203c1c8 {
#if defined(jpn)
    char pad0[0x14];
#endif
    int field0;
    int field4;
#if defined(jpn)
    char pad1c[8];
#endif
    int field8;
    int fieldc;
    int field10;
    short field14;
};

#if defined(jpn)
extern "C" void _Z30AdjustAndDispatchEntry0203c1c8P14Struct0203c1c8(struct Struct0203c1c8* obj, int mode);
#define REGION_COUNT 2
#else
void AdjustAndDispatchEntry0203c1c8(struct Struct0203c1c8* obj);
#define REGION_COUNT 1
#endif

// USA: func_ov000_021704d8
ARM void DispatchEntriesOnce021704d8(struct Struct0203c1c8* obj, int* arr1, int* arr2, int* arr3) {
    obj->fieldc = 2;
    obj->field10 = 1;
    int i;
    for (i = 0; i < REGION_COUNT; i++) {
        int v0 = arr1[i];
        int v4 = arr2[i];
        obj->field0 = v0;
        obj->field4 = v4;
        obj->field8 = arr3[i];
#if defined(jpn)
        _Z30AdjustAndDispatchEntry0203c1c8P14Struct0203c1c8(obj, 10);
#else
        AdjustAndDispatchEntry0203c1c8(obj);
#endif
    }
    obj->field8 = 0;
}
