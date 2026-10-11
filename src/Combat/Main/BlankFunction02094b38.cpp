#include <globaldefs.h>

#if defined(jpn)
extern "C" void* memset(void*, int, unsigned int);

struct RegionalState02094b38 {
    char pad00[0xc];
    int firstValue;
    int secondValue;
    char pad14[0x28];
    int firstIndex;
    int secondIndex;
    unsigned char entries[0x10];
    char pad54[5];
    unsigned char secondaryEntries[8];
    char pad61[2];
    unsigned char firstFlag;
    unsigned char secondFlag;
};
#endif

// USA: func_02094b38
// JPN: func_02095a38
extern "C" ARM void _Z21BlankFunction02094b38v(
#if defined(jpn)
    RegionalState02094b38* self, int index
#else
    void
#endif
) {
#if defined(jpn)
    if (index < 0) return;
    if (self->firstIndex == index) {
        self->firstIndex = -1;
        self->firstValue = 0;
        self->firstFlag = 0;
        return;
    }
    if (self->secondIndex == index) {
        self->secondIndex = -1;
        self->secondValue = 0;
        if (index == 1000) memset(self->entries, 0, sizeof(self->entries));
        if (index == 5000) memset(self->secondaryEntries, 0, sizeof(self->secondaryEntries));
        self->secondFlag = 0;
    }
#endif
}
