#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/GameResources.h"

struct StateBits5ccc_11544;
struct FlagWord020466f4;

extern int data_0211e33c;
extern int data_02108e00;

extern "C" int func_02075910(int a0, void* out, int a1, int a2);
extern "C" void func_02075acc(int id, void* p, int a1, int a2);
extern "C" int func_020a9eb8(void* s, int a1, int a2, int a3);
void* GetDataPtr02114e04_020d6c00();
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int bits);
void OrBitsIntoField0_020466e4(unsigned int* word, unsigned int bits);
void SetBitsInWord_0203b4a0(unsigned int* word, unsigned int bits);
void ClearBitsInWord_0203b4b0(unsigned int* word, unsigned int bits);
void SetBrightness(struct GameResources* res, int a, int b);
void SetFlag0x5cccBit0_02011544(struct StateBits5ccc_11544* p);
int IsFunc020d0840NonZero_02075ca0();
void NotifyU16AndSetFlag02075cb8();

struct Struct020aad1c {
    unsigned char state;
    int field4;
};

// USA: func_020aad1c
extern "C" ARM int func_020aad1c(struct Struct020aad1c* s, int a1, int a2, int a3) {
    if (s->state == 0) {
        GameState* battle = GameState::GetInstance();
#if defined(jpn)
        *((unsigned char*)battle + 0x5a68) = 1;
#else
        *((unsigned char*)battle + 0x5cc8) = 1;
        GameResources* flagv = func_ov017_0218b5b0();
#endif
        unsigned int buf;
        if (func_02075910(0, &buf, 1, 0) == 0) {
#if defined(jpn)
            SetBrightness(func_ov017_0218b5b0(), -16, 10);
#else
            SetBrightness(flagv, -16, 10);
#endif
            SetFlag0x5cccBit0_02011544((struct StateBits5ccc_11544*)battle);
            s->state = 4;
            return 1;
        } else {
            BackgroundLoader::FreeAllocationsGlobal();
#if !defined(jpn)
            unsigned int* flags = (unsigned int*)GetDataPtr02114e04_020d6c00();
            OrBitsIntoField0_020466e4(flags, 0x2000000);
            SetBitsInWord_0203b4a0((unsigned int*)flagv, 0x10);
#endif
            int ptr = (int)&data_0211e33c + 0x1c + 0x29000;
            if (func_02075910(0x8000, (void*)(s->field4 = ptr), 0x6fe4, 1) == 0) {
#if !defined(jpn)
                flags = (unsigned int*)GetDataPtr02114e04_020d6c00();
                ClearFlags020466f4((struct FlagWord020466f4*)flags, 0x2000000);
                ClearBitsInWord_0203b4b0((unsigned int*)flagv, 0x10);
#endif
                s->state = 4;
                return 1;
            } else {
                s->state = 1;
            }
        }
    } else if (s->state == 1) {
        if (IsFunc020d0840NonZero_02075ca0() == 0) {
            return 0;
        }
        NotifyU16AndSetFlag02075cb8();
        data_02108e00 = s->field4;
        if (func_020a9eb8(s, a1, a2, a3) == 0) {
#if !defined(jpn)
            ClearFlags020466f4((struct FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0x2000000);
            ClearBitsInWord_0203b4b0((unsigned int*)func_ov017_0218b5b0(), 0x10);
#endif
            s->state = 4;
            return 1;
        } else {
            data_02108e00 = 0;
            func_02075acc(a3 ? 0x8010 : 0x10, (void*)(s->field4 + 0x10), 0x6fe4, 1);
            s->state = 2;
        }
    } else if (s->state == 2) {
        if (IsFunc020d0840NonZero_02075ca0() == 0) {
            return 0;
        }
        NotifyU16AndSetFlag02075cb8();
        if (a3 != 0) {
#if !defined(jpn)
            ClearFlags020466f4((struct FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0x2000000);
            ClearBitsInWord_0203b4b0((unsigned int*)func_ov017_0218b5b0(), 0x10);
#endif
            s->state = 4;
            return 1;
        } else {
            func_02075acc(0x8010, (void*)(s->field4 + 0x10), 0x6fe4, 1);
            s->state = 3;
        }
    } else if (s->state == 3) {
        if (IsFunc020d0840NonZero_02075ca0() == 0) {
            return 0;
        }
        NotifyU16AndSetFlag02075cb8();
#if !defined(jpn)
        ClearFlags020466f4((struct FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0x2000000);
        ClearBitsInWord_0203b4b0((unsigned int*)func_ov017_0218b5b0(), 0x10);
#endif
        s->state = 4;
        return 1;
    }
    return 0;
}
