#include <globaldefs.h>
unsigned short* GetField0x8_02040528(int*);

struct Slots0203dfdc { char pad0[0xc]; void* items[0x20]; };

// USA: func_0203dfdc
ARM int FindEntryByKey0203dfdc(void* base, int key) {
    int i;
    for (i = 0; i < 0x20; i++) {
        void* p = ((struct Slots0203dfdc*)base)->items[i];
        if (p == NULL) continue;
        if (*(int*)p & 0x8000) continue;
        {
            unsigned short* q = GetField0x8_02040528((int*)(p));
            if (q == NULL) continue;
            if (*q == key) return i;
        }
    }
    return -1;
}
