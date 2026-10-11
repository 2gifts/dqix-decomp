#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include <globaldefs.h>

struct S020a13c4;
struct Array020a15bc;
struct Struct020dfc40;
struct Foo02168c38;
struct Flags02168 {
    unsigned char pad[0x49c];
    unsigned char bit0 : 1;
};
struct Container020e0310;
extern "C" int _Z35AreFields60And64BothNegOne_02168c00Ph(unsigned char *p);
extern "C" void _Z19ClearStruct020a13c4P9S020a13c4(struct S020a13c4 *s);
extern "C" void _Z31SetupGlobalAndRunScript020a13e4PvS_ith(void *p, void *alloc, int a, unsigned short b, unsigned char c);
extern "C" void *_Z26FindElementByField020a15bcP13Array020a15bci(struct Array020a15bc *arr, int key);
extern "C" void *_Z26ResetAndReturnSelf020dfc2cPv(void *p);
extern "C" void _Z19ResetStruct020dfc40P14Struct020dfc40(struct Struct020dfc40 *s);
extern "C" void _Z13Reset02168c38P11Foo02168c38(struct Foo02168c38 *f);
extern "C" void _Z29AppendFormattedValue_02168d10Phi(unsigned char *rec, int v);
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310 *c, int key);
extern "C" void *ExtractFileFromGP2(const char *gp2Path, const char *innerFilePath, unsigned int *outSize);
extern "C" int func_ov023_021ed724(void *p, short *keys, int n);
extern "C" void func_020e0028(void *c, void *alloc, void *data, unsigned int size, short *keys, unsigned short n);
extern "C" void func_ov002_02168ca8(unsigned char *rec, void *elem);
extern "C" int sprintf(char *dst, const char *fmt, ...);
extern "C" void *__clear(void *dst, int count);
extern "C" char data_ov002_0216d326[];
extern "C" char data_ov002_0216d33d[];

// USA: func_ov002_021688f8
extern "C" ARM void func_ov002_021688f8(char *base) {
    char ctr[0x18];
    char path[0x40];
    char name[0x20];
    unsigned int size;
    short *keys;
    unsigned char *tmp;
    int j;
    int n;
    GameState *gs = GameState::GetInstance();
    BackgroundLoader::GetInstance();
    if (!_Z35AreFields60And64BothNegOne_02168c00Ph(*(unsigned char **) (base + 0x2000 + 0x460))) return;
    n = *(short *) (*(char **) (base + 0x2000 + 0x460) + 0x68);
    if (n > 0) {
        keys = (short *) ((SafeAllocator *) (base + 0x64 + 0x800))->Allocate(n * 2);
        for (int i = 0; i < n; i++) {
            keys[i] = *(short *) (*(char **) (base + 0x2000 + 0x460) + i * 2 + 0x6a);
        }
        *(void **) (base + 0x2000 + 0x460) = NULL;
        ((SafeAllocator *) (base + 0x28 + 0x800))->Reset();
        *(void **) (base + 0x2000 + 0x464) = ((SafeAllocator *) (base + 0x28 + 0x800))->Allocate(0x14);
        _Z19ClearStruct020a13c4P9S020a13c4((struct S020a13c4 *) *(void **) (base + 0x2000 + 0x464));
        _Z31SetupGlobalAndRunScript020a13e4PvS_ith(*(void **) (base + 0x2000 + 0x464), base + 0x28 + 0x800, 0, 0, 4);
        *(unsigned char *) (base + 0x2000 + 0x471) =
            (func_ov023_021ed724(*(void **) (base + 0x2000 + 0x464), keys, n) & 1) ? 1 : 0;
        char *hero = (char *) gs->GetProtagonist();
        _Z26ResetAndReturnSelf020dfc2cPv(ctr);
        _Z19ResetStruct020dfc40P14Struct020dfc40((struct Struct020dfc40 *) ctr);
        BackgroundLoader::AddLockGlobal();
        size = 0;
        __clear(path, 0x40);
        __clear(name, 0x20);
        sprintf(path, data_ov002_0216d326, (*(struct Flags02168 **) (hero + 0x150))->bit0);
        sprintf(name, data_ov002_0216d33d, (*(struct Flags02168 **) (hero + 0x150))->bit0);
        void *data = ExtractFileFromGP2(path, name, &size);
        if (data != NULL) {
            func_020e0028(ctr, base + 0x28 + 0x800, data, size, keys, n);
        }
        BackgroundLoader::RemoveLockGlobal();
        tmp = (unsigned char *) ((SafeAllocator *) (base + 0x64 + 0x800))->Allocate(0x7148);
        for (j = 0; j < n; j++) {
            _Z13Reset02168c38P11Foo02168c38((struct Foo02168c38 *) (tmp + j * 0x244));
            void *elem =
                _Z26FindElementByField020a15bcP13Array020a15bci(*(struct Array020a15bc **) (base + 0x2000 + 0x464), keys[j]);
            if (elem == NULL) continue;
            int text = _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310 *) ctr, keys[j]);
            if (text == 0) continue;
            func_ov002_02168ca8(tmp + j * 0x244, elem);
            _Z29AppendFormattedValue_02168d10Phi(tmp + j * 0x244, text);
        }
        *(void **) (base + 0x2000 + 0x464) = NULL;
        ((SafeAllocator *) (base + 0x28 + 0x800))->Reset();
        *(void **) (base + 0x2000 + 0x46c) = ((SafeAllocator *) (base + 0x28 + 0x800))->Allocate(n * 0x244);
        for (int i = 0; i < n; i++) {
            _Z13Reset02168c38P11Foo02168c38((struct Foo02168c38 *) (*(unsigned char **) (base + 0x2000 + 0x46c) + i * 0x244));
            func_ov002_02168ca8(*(unsigned char **) (base + 0x2000 + 0x46c) + i * 0x244, tmp + i * 0x244);
            _Z29AppendFormattedValue_02168d10Phi(*(unsigned char **) (base + 0x2000 + 0x46c) + i * 0x244,
                                                 (int) (tmp + i * 0x244 + 0xc));
        }
        *(unsigned char *) (base + 0x2000 + 0x470) = n;
        *(int *) (base + 0x1000 + 0xbc0) += 1;
    } else {
        *(void **) (base + 0x2000 + 0x460) = NULL;
        *(int *) (base + 0x1000 + 0xbc0)   = 100;
    }
}
