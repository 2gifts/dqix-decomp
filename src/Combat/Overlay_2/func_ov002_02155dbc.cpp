#if defined(jpn)
#define func_ov002_0215aaa4 func_ov002_0215be94
#define func_ov002_0215ab60 func_ov002_0215bf4c
#define func_ov002_0215ad70 func_ov002_0215c0d8
#define func_ov002_0215afb8 func_ov002_0215c318
#define func_ov002_0215b0a8 func_ov002_0215c404
#define func_ov002_0215b138 func_ov002_0215c494
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

#if defined(jpn)
#define func_ov002_02155dbc func_ov002_021574fc
#endif

struct Cont0205d1e0;
struct Cont0205d228;
struct Cont0205d274;
struct Outer020e28dc;
struct Struct020e2794;
#if defined(jpn)
extern "C" void func_ov023_021e7868(void *p);
#else
void InitBuffersAndConfigureEntry_021e761c(void *p);
#endif
void InitBuffersIfFlag431_021eb4b8(void *p);
void ResetCombatEntry02184a58(void *p);
void ClearBuffers0204b010OverList0x98(struct Cont0205d1e0 *c);
void CallFunc0204c8f0OverList0x9c(struct Cont0205d228 *c);
void CallFunc0204b04cOverList0x98(struct Cont0205d274 *c);
int GetInnerFlagBit0020e28dc(struct Outer020e28dc *o);
void UpdateEntryIfActive020e2794(struct Struct020e2794 *s, void *p);
extern "C" void func_0205da88(void *c, int a, int b, int d);
extern "C" void func_ov002_0215aaa4(void *base);
#if !defined(jpn)
extern "C" void func_ov002_0215b9a4(void *base, int a, int b);
#endif
#if !defined(jpn)
extern "C" void func_ov002_021619b4(int a, int b, int c);
#endif
extern "C" void func_ov002_0215ab60(void *base);
extern "C" void func_ov002_0215ad70(void *base);
extern "C" void func_ov002_0215afb8(void *base);
extern "C" void func_ov002_0215b0a8(void *base);
extern "C" void func_ov002_0215b138(void *base);

// USA: func_ov002_02155dbc
extern "C" ARM void func_ov002_02155dbc(char *base) {
    if (*(unsigned char *) (base + 0x1000 + LOW_REGION(0xb87, 0xcc3)) != 0) {
#if defined(jpn)
        func_ov023_021e7868(base + 0x18 + 0x800);
#else
        InitBuffersAndConfigureEntry_021e761c(base + 0xb4 + 0x800);
#endif
    }
    if (*(void **) (base + 0x2000 + LOW_REGION(0x298, 0x468)) != NULL) {
        InitBuffersIfFlag431_021eb4b8(*(void **) (base + 0x2000 + LOW_REGION(0x298, 0x468)));
    }
    if (*(int *) (base + 0x1000 + LOW_REGION(0xa80, 0xbb8)) == LOW_REGION(0x1f, 0x1e) && *(int *) (base + 0x1000 + LOW_REGION(0xa88, 0xbc0)) > 4) {
        ResetCombatEntry02184a58(base + LOW_REGION(0xc20, 0xd70) + 0x1000);
    } else {
        char *list = base + LOW_REGION(0x220, 0x2c8);
        ClearBuffers0204b010OverList0x98((struct Cont0205d1e0 *) (list + 0xc00));
        CallFunc0204c8f0OverList0x9c((struct Cont0205d228 *) (list + 0xc00));
        func_0205da88(list + 0xc00, 1, 2, 1);
        func_0205da88(list + 0xc00, 1, 3, 1);
        func_0205da88(list + 0xc00, 2, 3, 0);
        CallFunc0204b04cOverList0x98((struct Cont0205d274 *) (list + 0xc00));
        func_ov002_0215aaa4(base);
#if !defined(jpn)
        if (*(unsigned char *) (base + 0x1000 + 0xc34) != 0) {
            func_ov002_0215b9a4(base, 0x1b, 0);
            func_ov002_0215b9a4(base, 0x1a, 0);
            func_ov002_021619b4(*(signed char *) (base + 0x1c00 + 0x20), *(int *) (base + 0x1000 + LOW_REGION(0x9c0, 0xa68)),
                                *(int *) (base + 0x1000 + 0xbd8));
            *(unsigned char *) (base + 0x1000 + 0xc34) = 0;
        }

#endif
        func_ov002_0215ab60(base);
        func_ov002_0215ad70(base);
        func_ov002_0215afb8(base);
        func_ov002_0215b0a8(base);
        func_ov002_0215b138(base);
    }
    if (*(struct Outer020e28dc **) base != NULL && GetInnerFlagBit0020e28dc(*(struct Outer020e28dc **) base)) {
        UpdateEntryIfActive020e2794(*(struct Struct020e2794 **) base, NULL);
    }
    if (*(struct Outer020e28dc **) (base + 4) != NULL && GetInnerFlagBit0020e28dc(*(struct Outer020e28dc **) (base + 4))) {
        UpdateEntryIfActive020e2794(*(struct Struct020e2794 **) (base + 4), *(void **) (base + 0x1000 + LOW_REGION(0x9c0, 0xa68)));
    }
}
