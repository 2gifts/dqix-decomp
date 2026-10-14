#include <globaldefs.h>

#if defined(jpn)
#define func_0204f41c func_02050678
#endif

extern "C" void _Z29AccumulateFixedAngle_021d8a74P14Accum_021d8a74f(void* obj, float angle);
void FillCombatBuffer021d8ad4(void* obj, char* buf);

struct ElemFld4_021d9208 {
    unsigned int nibble0 : 4;
#if defined(jpn)
    unsigned int twoBit : 1;
#else
    unsigned int twoBit : 2;
#endif
    unsigned int gap : 1;
    unsigned int field3 : 4;
#if defined(jpn)
    unsigned int rest : 22;
#else
    unsigned int rest : 21;
#endif
};

struct Elem_021d9208 {
    short a;
    short b;
    ElemFld4_021d9208 c;
    unsigned int d;
};

extern "C" struct Elem_021d9208* _Z29GetElementIfInBounds_021d99f8P18ListHeader021d99f8j(void* list, unsigned int idx);
extern "C" void func_ov028_021d8a40(void* buf, unsigned int val);
extern "C" int func_020420e8(void* d, int flag);
#if defined(jpn)
extern "C" void func_0204f41c(void* buf, int scaled, int byteField, void* d, unsigned char nibble0, unsigned char field3, short* p1, short* p2);
extern "C" void func_0204c684(char* obj);
extern "C" int func_0204fc40(void* unused0, char** cursor, char* tag, short* out, int max);
extern char data_ov028_021da41d[];
#else
extern "C" void func_0204f41c(void* buf, int scaled, int byteField, void* d, unsigned char nibble0, unsigned char field3, short* p1, short* p2, int flagC);
#endif
extern "C" int _Z12TestFlagMaskPti(void* flagAddr, int mask);

extern int data_02114e30;

// USA: func_ov028_021d9208  (semantic: ApplyElementListEffects_021d9208)  (semantic: ApplyElementListEffects_021d9208)
extern "C" ARM void func_ov028_021d9208(char* self, int arg1) {
    float scale = *(float*)self;
    float angle = 0.5f * ((float)arg1 * scale);
    _Z29AccumulateFixedAngle_021d8a74P14Accum_021d8a74f(self + 0x60, angle);
    FillCombatBuffer021d8ad4(self + 0x60, *(char**)(self + 0x40));

    char* buf40 = *(char**)(self + 0x40);
    short prevIndex = -1;
#if defined(jpn)
    unsigned char advance;
    int scaled;
#else
    int scaled;
#endif
    int flagC;
#if defined(jpn)
    short byteField;
#else
    int byteField;
#endif
#if defined(jpn)
    char measure[0xe0];
    short amount;
    short local2;
    short local1;
    unsigned int localBuf[0x38];
#else
    short local2;
    short local1;
    unsigned int localBuf[0x38];
#endif
    int found;

    for (;;) {
        unsigned short idx = *(unsigned short*)(self + 0x6c);
        struct Elem_021d9208* elem = _Z29GetElementIfInBounds_021d99f8P18ListHeader021d99f8j(self, idx);
        if (elem == 0) {
            found = 1;
            goto exitLoop;
        }

#if defined(jpn)
        unsigned int lhs = (*(int*)(self + 0x60) >> 12) + 0xc0;
        short elemB = elem->b;
        unsigned int rhs = elemB + ((int)*(int*)(self + 0x64) >> 12);
        if (lhs < rhs) {
            goto fail;
        }
        *(int*)(self + 0x64) += (elemB << 12);
#else
        short elemIdx = elem->a;
        if (prevIndex != elemIdx) {
            unsigned int lhs = (*(int*)(self + 0x60) >> 12) + 0xc0;
            short elemB = elem->b;
            unsigned int rhs = elemB + (*(int*)(self + 0x64) >> 12);
            if (lhs < rhs) {
                goto fail;
            }
            *(unsigned int*)(self + 0x64) += (elemB << 12);
        }
#endif

        byteField = (*(int*)(self + 0x64) >> 12) & 0xff;
#if defined(jpn)
        scaled = 0;
        if (elem->c.twoBit != 0) {
            advance = (unsigned char)elem->c.nibble0;
            char* text = (char*)elem->d;
            if (text != NULL) {
                func_0204c684(measure);
                char* cursor = text;
                while (*cursor != 0) {
                    amount = 0;
                    if (func_0204fc40(measure, &cursor, data_ov028_021da41d, &amount, 1)) {
                        scaled += amount;
                    } else if (*cursor >= '0' && *cursor <= '9') {
                        ++cursor;
                        scaled += advance;
                    } else if (*cursor >= 'a' && *cursor <= 'z') {
                        scaled += advance;
                        ++cursor;
                    } else if (*cursor >= 'A' && *cursor <= 'Z') {
                        scaled += advance;
                        ++cursor;
                    } else {
                        unsigned char ch = *(unsigned char*)cursor;
                        if ((ch >= 0x81 && ch <= 0x9f) || (ch >= 0xe0 && ch <= 0xea)) {
                            ++cursor;
                        }
                        scaled += advance;
                        ++cursor;
                    }
                }
            }
            scaled = (0x100 - scaled) << 0xf >> 0x10;
        }
#else
        flagC = 0;
        if (elem->c.nibble0 == 0xc) {
            flagC = 1;
        }
        scaled = 0;
        if (elem->c.twoBit != 0) {
            int base = func_020420e8((void*)elem->d, flagC);
            scaled = 0x88;
            switch (elem->c.twoBit) {
                case 1:
                    scaled = (0x100 - base) << 0xf >> 0x10;
                    break;
                case 2:
                    scaled = (short)(0x78 - base);
                    break;
            }
        }
#endif

        func_ov028_021d8a40(localBuf, (unsigned int)buf40);

        short nib = elem->c.nibble0;
        *(short*)((char*)localBuf + 0xb4) = nib;
        *(short*)((char*)localBuf + 0xb6) = nib + 1;

#if defined(jpn)
        func_0204f41c(localBuf, scaled, byteField, (void*)elem->d, elem->c.nibble0, elem->c.field3, &local1, &local2);
#else
        func_0204f41c(localBuf, scaled, byteField, (void*)elem->d, elem->c.nibble0, elem->c.field3, &local1, &local2, flagC);
#endif

        if ((unsigned int)byteField + elem->c.nibble0 > 0x100) {
#if defined(jpn)
            func_0204f41c(localBuf, scaled, (short)(byteField - 0x100), (void*)elem->d, elem->c.nibble0, elem->c.field3, &local1, &local2);
#else
            func_0204f41c(localBuf, scaled, (short)(byteField - 0x100), (void*)elem->d, elem->c.nibble0, elem->c.field3, &local1, &local2, flagC);
#endif
        }

        *(unsigned short*)(self + 0x6c) = *(unsigned short*)(self + 0x6c) + 1;
        *(unsigned char*)(self + 0x6e) = 1;
#if defined(jpn)

#else
        prevIndex = elem->a;
#endif
    }
fail:
    found = 0;
exitLoop:
    _Z12TestFlagMaskPti(&data_02114e30, 0x2000);
    if (found != 0) {
        *(unsigned char*)(self + 0x80) = 2;
        *(unsigned char*)(self + 0x81) = 0;
    }
}
