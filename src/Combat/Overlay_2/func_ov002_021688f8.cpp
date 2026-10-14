#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include <globaldefs.h>

#if defined(jpn)
#define REGION_VALUE(j, u) (j)
#define func_ov002_02168ca8 func_ov002_0216952c
#else
#define REGION_VALUE(j, u) (u)
#endif

struct S020a13c4;
struct Array020a15bc;
struct Struct020dfc40;
struct Foo02168c38 {
    unsigned int a;
    void* ptr;
    unsigned int c;
    char pad[0x38];
    char buf[REGION_VALUE(0x118, 0x200)];
};
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

#if defined(jpn)
extern "C" const char data_ov002_0216dab4[];
extern "C" int func_020e1fc4(void* texts, SafeAllocator* allocator, const char* tablePath,
    short* ids, unsigned short count, short variant, bool lock);
#endif

// USA: func_ov002_021688f8; JPN: func_ov002_021691dc
extern "C" ARM void func_ov002_021688f8(char *base) {
    char ctr[0x18];
#if !defined(jpn)
    char path[0x40];
    char name[0x20];
    unsigned int size;
#endif
    short *keys;
    unsigned char *tmp;
    int j;
    int n;
    GameState *gs = GameState::GetInstance();
    BackgroundLoader::GetInstance();
    if (!_Z35AreFields60And64BothNegOne_02168c00Ph(*(unsigned char **) (base + 0x2000 + REGION_VALUE(0x290, 0x460)))) return;
    n = *(short *) (*(char **) (base + 0x2000 + REGION_VALUE(0x290, 0x460)) + 0x68);
    if (n > 0) {
        keys = (short *) ((SafeAllocator *) (base + REGION_VALUE(0x3c8, 0x64) + REGION_VALUE(0x400, 0x800)))->Allocate(n * 2);
        for (int i = 0; i < n; i++) {
            keys[i] = *(short *) (*(char **) (base + 0x2000 + REGION_VALUE(0x290, 0x460)) + i * 2 + 0x6a);
        }
        *(void **) (base + 0x2000 + REGION_VALUE(0x290, 0x460)) = NULL;
        ((SafeAllocator *) (base + REGION_VALUE(0x38c, 0x28) + REGION_VALUE(0x400, 0x800)))->Reset();
        *(void **) (base + 0x2000 + REGION_VALUE(0x294, 0x464)) = ((SafeAllocator *) (base + REGION_VALUE(0x38c, 0x28) + REGION_VALUE(0x400, 0x800)))->Allocate(0x14);
        _Z19ClearStruct020a13c4P9S020a13c4((struct S020a13c4 *) *(void **) (base + 0x2000 + REGION_VALUE(0x294, 0x464)));
        _Z31SetupGlobalAndRunScript020a13e4PvS_ith(*(void **) (base + 0x2000 + REGION_VALUE(0x294, 0x464)), base + REGION_VALUE(0x38c, 0x28) + REGION_VALUE(0x400, 0x800), 0, 0, 4);
        *(unsigned char *) (base + 0x2000 + REGION_VALUE(0x2a1, 0x471)) =
            (func_ov023_021ed724(*(void **) (base + 0x2000 + REGION_VALUE(0x294, 0x464)), keys, n) & 1) ? 1 : 0;
        char *hero = (char *) gs->GetProtagonist();
        _Z26ResetAndReturnSelf020dfc2cPv(ctr);
        _Z19ResetStruct020dfc40P14Struct020dfc40((struct Struct020dfc40 *) ctr);
#if defined(jpn)
        func_020e1fc4(ctr, (SafeAllocator*)(base + 0x78c), data_ov002_0216dab4, keys,
            (unsigned short)n, (*(struct Flags02168**)(hero + 0x144))->bit0, true);
#else
        BackgroundLoader::AddLockGlobal();
        size = 0;
        __clear(path, 0x40);
        __clear(name, 0x20);
        sprintf(path, data_ov002_0216d326, (*(struct Flags02168 **) (hero + 0x150))->bit0);
        sprintf(name, data_ov002_0216d33d, (*(struct Flags02168 **) (hero + 0x150))->bit0);
        void *data = ExtractFileFromGP2(path, name, &size);
        if (data != NULL) {
            func_020e0028(ctr, base + REGION_VALUE(0x38c, 0x28) + REGION_VALUE(0x400, 0x800), data, size, keys, n);
        }
        BackgroundLoader::RemoveLockGlobal();
#endif
        tmp = (unsigned char *) ((SafeAllocator *) (base + REGION_VALUE(0x3c8, 0x64) + REGION_VALUE(0x400, 0x800)))->Allocate(50 * sizeof(Foo02168c38));
        for (j = 0; j < n; j++) {
            _Z13Reset02168c38P11Foo02168c38((struct Foo02168c38 *) (tmp + j * sizeof(Foo02168c38)));
            void *elem =
                _Z26FindElementByField020a15bcP13Array020a15bci(*(struct Array020a15bc **) (base + 0x2000 + REGION_VALUE(0x294, 0x464)), keys[j]);
            if (elem == NULL) continue;
            int text = _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310 *) ctr, keys[j]);
            if (text == 0) continue;
            func_ov002_02168ca8(tmp + j * sizeof(Foo02168c38), elem);
            _Z29AppendFormattedValue_02168d10Phi(tmp + j * sizeof(Foo02168c38), text);
        }
        *(void **) (base + 0x2000 + REGION_VALUE(0x294, 0x464)) = NULL;
        ((SafeAllocator *) (base + REGION_VALUE(0x38c, 0x28) + REGION_VALUE(0x400, 0x800)))->Reset();
        *(void **) (base + 0x2000 + REGION_VALUE(0x29c, 0x46c)) = ((SafeAllocator *) (base + REGION_VALUE(0x38c, 0x28) + REGION_VALUE(0x400, 0x800)))->Allocate(n * sizeof(Foo02168c38));
        for (int i = 0; i < n; i++) {
            _Z13Reset02168c38P11Foo02168c38((struct Foo02168c38 *) (*(unsigned char **) (base + 0x2000 + REGION_VALUE(0x29c, 0x46c)) + i * sizeof(Foo02168c38)));
            func_ov002_02168ca8(*(unsigned char **) (base + 0x2000 + REGION_VALUE(0x29c, 0x46c)) + i * sizeof(Foo02168c38), tmp + i * sizeof(Foo02168c38));
            _Z29AppendFormattedValue_02168d10Phi(*(unsigned char **) (base + 0x2000 + REGION_VALUE(0x29c, 0x46c)) + i * sizeof(Foo02168c38),
                                                 (int) (tmp + i * sizeof(Foo02168c38) + 0xc));
        }
        *(unsigned char *) (base + 0x2000 + REGION_VALUE(0x2a0, 0x470)) = n;
        *(int *) (base + 0x1000 + REGION_VALUE(0xa88, 0xbc0)) += 1;
    } else {
        *(void **) (base + 0x2000 + REGION_VALUE(0x290, 0x460)) = NULL;
        *(int *) (base + 0x1000 + REGION_VALUE(0xa88, 0xbc0))   = 100;
    }
}
