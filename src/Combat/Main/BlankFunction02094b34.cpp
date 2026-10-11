#include <globaldefs.h>

#if defined(jpn)
extern "C" int func_020965c0(void*, int);
extern "C" void func_02094ab0(void*);

struct RegionalState02094b34 {
    char pad00[0x34];
    int pendingFirst;
    int pendingSecond;
    char pad3c[0x1a];
    unsigned char firstFlag;
    unsigned char secondFlag;
    char pad58[9];
    unsigned char firstMode;
    unsigned char secondMode;
};
#endif

// USA: func_02094b34
// JPN: func_0209595c
extern "C" ARM void _Z21BlankFunction02094b34v(
#if defined(jpn)
    RegionalState02094b34* self, int first, int second,
    unsigned char firstMode, const volatile unsigned char secondModeArgument
#else
    void
#endif
) {
#if defined(jpn)
    if (self->pendingFirst >= 0) return;
    volatile int indices[2];
    indices[1] = second;
    indices[0] = first;
    unsigned char secondMode = secondModeArgument;
    if (func_020965c0(self, first)) {
        indices[0] = -1;
        firstMode = 1;
    }
    if (func_020965c0(self, indices[1])) {
        indices[1] = -1;
        secondMode = 1;
    }
    for (unsigned char i = 0; i < 2; ++i) {
        if (indices[0] < 0) {
            indices[0] = indices[1];
            firstMode = secondMode;
            indices[1] = -1;
            secondMode = 1;
        }
    }
    if (indices[0] < 0 && indices[1] < 0) return;
    func_02094ab0(self);
    self->pendingFirst = indices[0];
    self->pendingSecond = indices[1];
    self->firstFlag = 0;
    self->secondFlag = 0;
    self->firstMode = firstMode;
    self->secondMode = secondMode;
#endif
}
