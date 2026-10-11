#include <globaldefs.h>

#if defined(jpn)
extern "C" int _Z12StringLengthPKc(const char*);
extern "C" int func_02001aec(const void*, const void*, unsigned int);
extern "C" void* memset(void*, int, unsigned int);
extern "C" int sprintf(char*, const char*, ...);
extern "C" void func_02094ab0(void*);

struct RegionalState02094b2c {
    char pad00[0x34];
    int pendingFirst;
    int pendingSecond;
    int firstIndex;
    int secondIndex;
    char entries[0x10];
    char pad54[2];
    unsigned char firstFlag;
    unsigned char secondFlag;
    unsigned char textFlag;
    char pad59[8];
    unsigned char firstMode;
    unsigned char secondMode;
};
#endif

// USA: func_02094b2c
// JPN: func_020957c4
extern "C" ARM void _Z21BlankFunction02094b2cv(
#if defined(jpn)
    RegionalState02094b2c* self, int index, const char* text,
    unsigned char firstMode, unsigned char secondMode
#else
    void
#endif
) {
#if defined(jpn)
    if (self->pendingFirst >= 0) return;
    if (!text) return;
    int length = _Z12StringLengthPKc(text);
    if (!length) return;
    if (length >= 16) return;
    if (self->secondIndex == 1000) {
        int currentLength = _Z12StringLengthPKc(self->entries);
        if (currentLength == length && func_02001aec(self->entries, text, currentLength) == 0) return;
    }
    memset(self->entries, 0, sizeof(self->entries));
    sprintf(self->entries, text);
    self->textFlag = 0;
    func_02094ab0(self);
    self->pendingFirst = index;
    self->pendingSecond = 1000;
    self->firstFlag = 0;
    self->secondFlag = 0;
    self->firstMode = firstMode;
    self->secondMode = secondMode;
#endif
}
