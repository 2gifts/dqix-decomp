#include <globaldefs.h>

#if defined(jpn)
extern "C" void* memset(void*, int, unsigned int);

struct RegionalState02094b40 {
    char pad00[0xc];
    int firstValue;
    int secondValue;
    char pad14[0x28];
    int firstIndex;
    int secondIndex;
    unsigned char entries[0x10];
    char pad54[0xf];
    unsigned char firstFlag;
    unsigned char secondFlag;
};
#endif

// USA: func_02094b40
// JPN: func_02095b0c
extern "C" ARM void _Z21BlankFunction02094b40v(
#if defined(jpn)
    RegionalState02094b40* self
#else
    void
#endif
) {
#if defined(jpn)
    self->firstIndex = -1;
    self->firstValue = 0;
    self->firstFlag = 0;
    self->secondIndex = -1;
    self->secondValue = 0;
    self->secondFlag = 0;
    memset(self->entries, 0, sizeof(self->entries));
#endif
}
