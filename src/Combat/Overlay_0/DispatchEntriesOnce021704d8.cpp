#include <globaldefs.h>

struct Struct0203c1c8 {
#if defined(jpn)
    short textSlots[10];
#endif
    int x;
    int y;
#if defined(jpn)
    int lineHeight;
    int characterAdvance;
#endif
    int paletteOffset;
    int alignment;
    int priority;
#if defined(jpn)
    signed int affineIndex : 16;
    unsigned int unknown32 : 8;
    unsigned int unknown33 : 8;
    int affineMode;
#else
    short entryIndex;
#endif
};

#if defined(jpn)
void AdjustAndDispatchEntry0203c1c8(Struct0203c1c8* obj, int count);
#define REGION_COUNT 2
#else
void AdjustAndDispatchEntry0203c1c8(Struct0203c1c8* obj);
#define REGION_COUNT 1
#endif

// USA: func_ov000_021704d8
ARM void DispatchEntriesOnce021704d8(Struct0203c1c8* obj, int* arr1, int* arr2, int* arr3) {
    obj->alignment = 2;
    obj->priority = 1;
    int i;
    for (i = 0; i < REGION_COUNT; i++) {
        int v0 = arr1[i];
        int v4 = arr2[i];
        obj->x = v0;
        obj->y = v4;
        obj->paletteOffset = arr3[i];
#if defined(jpn)
        AdjustAndDispatchEntry0203c1c8(obj, 10);
#else
        AdjustAndDispatchEntry0203c1c8(obj);
#endif
    }
    obj->paletteOffset = 0;
}
