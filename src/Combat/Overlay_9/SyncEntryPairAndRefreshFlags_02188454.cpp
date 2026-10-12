#include <globaldefs.h>

#if defined(jpn)
#define func_ov009_02188454 func_ov009_02189214
#define _Z20GetEntryPair02188bf8PhiPsS0_ func_ov009_021899b0
#define LOW_REGION(j,u) (j)
#else
#define LOW_REGION(j,u) (u)
#endif

struct Words021e60c4 { unsigned int a, b, c; };
extern "C" void _Z22InitWordsQuad_021e60e0Pvj(void* obj, unsigned int val);
extern "C" void func_ov023_021e613c(struct Words021e60c4* dst, char* src);
extern "C" void _Z26SetFourWordBlocks_021e6088PvP13Words021e60c4(void* obj, struct Words021e60c4* src);
extern "C" void* func_ov023_021e6194(void* p);
extern "C" void _ZN8Object3D24MaybeSetRegularAnimationEPKci(void* obj, void* member, int arg3);
struct S1a0;
extern "C" void _ZN8Object3D23SetCurrentAnimationTimeEi(struct S1a0* obj, unsigned int v);
extern "C" void _Z20GetEntryPair02188bf8PhiPsS0_(unsigned char* base, int idx, short* out0, short* out1);
extern "C" void func_ov023_021e5e68(void* obj, short a, short b);
int StringLength(const char* s);

// USA: func_ov009_02188454  (semantic: SyncEntryPairAndRefreshFlags_02188454)
extern "C" ARM void func_ov009_02188454(void* objRaw) {
    char* obj = (char*)objRaw;
    struct Words021e60c4 tmp;

    if (*(unsigned int*)(obj + LOW_REGION(0xd60,0xd9c)) & 4) {
        void* p = *(void**)(obj + LOW_REGION(0x7c0,0x7fc));
        if (p != 0 && *(unsigned char*)((char*)p + 0xc12) != 0) {
            return;
        }

        if (*(unsigned int*)(obj + LOW_REGION(0xd60,0xd9c)) & 0x40000) {
            _Z22InitWordsQuad_021e60e0Pvj(*(void**)(obj + LOW_REGION(0x7bc,0x7f8)), 0x1eb);
            *(unsigned int*)(obj + LOW_REGION(0xd60,0xd9c)) &= ~0x40000;
        }
        func_ov023_021e613c(&tmp, *(char**)(obj + LOW_REGION(0x7bc,0x7f8)));
        _Z26SetFourWordBlocks_021e6088PvP13Words021e60c4(*(void**)(obj + LOW_REGION(0x7c0,0x7fc)), &tmp);

        {
            void* ef8 = func_ov023_021e6194(*(void**)(obj + LOW_REGION(0x7bc,0x7f8)));
            void* efc = func_ov023_021e6194(*(void**)(obj + LOW_REGION(0x7c0,0x7fc)));
            const char* sMain = *(const char**)((char*)efc + 0x14);
            int lenMain = 0;
            int lenAlt = 0;
            const char* sAlt = *(const char**)((char*)ef8 + 0x14);
            if (sMain != 0) {
                lenMain = StringLength(sMain);
            }
            if (sAlt != 0) {
                lenAlt = StringLength(sAlt);
            }
            if (lenMain == lenAlt && sAlt != 0) {
                _ZN8Object3D24MaybeSetRegularAnimationEPKci(efc, (void*)sAlt, 0);
                _ZN8Object3D23SetCurrentAnimationTimeEi((struct S1a0*)efc, *(unsigned int*)((char*)ef8 + 0x1c));
            }
        }

        {
            void* t = *(void**)(obj + LOW_REGION(0x7bc,0x7f8));
            *(void**)(obj + LOW_REGION(0x7bc,0x7f8)) = *(void**)(obj + LOW_REGION(0x7c0,0x7fc));
            *(void**)(obj + LOW_REGION(0x7c0,0x7fc)) = t;
        }

        if (*(unsigned int*)(obj + LOW_REGION(0xd60,0xd9c)) & 0x20000) {
            unsigned char sel = *(unsigned char*)(obj + LOW_REGION(0xd67,0xda3));
            char* base = (char*)*(int*)(obj + LOW_REGION(0xd4c,0xd88)) + 0x488;
            unsigned char idx = *(unsigned char*)(obj + sel + LOW_REGION(0xd68,0xda4));
            _Z20GetEntryPair02188bf8PhiPsS0_((unsigned char*)obj, idx, (short*)(base + 0x18), (short*)(base + 0x1a));
            func_ov023_021e5e68(*(void**)(obj + LOW_REGION(0x7bc,0x7f8)), *(short*)(base + 0x18), *(short*)(base + 0x1a));
            func_ov023_021e5e68(*(void**)(obj + LOW_REGION(0x7c0,0x7fc)), *(short*)(base + 0x18), *(short*)(base + 0x1a));
            *(unsigned int*)(obj + LOW_REGION(0xd60,0xd9c)) &= ~0x20000;
        }

        *(unsigned int*)(obj + LOW_REGION(0xd60,0xd9c)) &= ~4;
    }
}
