#include <globaldefs.h>
unsigned short* GetField0x8_02040528(int*);

struct Slots0203df78 { char pad0[0xc]; void* items[0x20]; };

// USA: func_0203df78
ARM void* FindEntryPointerByKey0203df78(void* base, int key) {
    int i;
    for (i = 0; i < 0x20; i++) {
        void* p = ((struct Slots0203df78*)base)->items[i];
        if (p == NULL) continue;
        if (*(int*)p & 0x8000) continue;
        {
            unsigned short* q = GetField0x8_02040528((int*)(p));
            if (q == NULL) continue;
            if (*q == key) return ((struct Slots0203df78*)base)->items[i];
        }
    }
    return NULL;
}
