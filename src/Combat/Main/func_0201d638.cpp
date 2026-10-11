#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Memory.h"

struct Param0201d638 {
    int tag;
    union { int i; float f; } u;
};

extern "C" extern int _ZNK6Script9Parameter5ToIntEv(struct Param0201d638* p);
extern "C" extern float _ZNK6Script9Parameter7ToFloatEv(struct Param0201d638* p);
extern "C" extern char* _ZNK6Script9Parameter8ToStringEv(struct Param0201d638* p);
extern "C" extern struct Param0201d638* _ZN6Script9Parameter9ToVec3fixEP8Vector3i(struct Param0201d638* p, int* outVec);
extern "C" extern void _ZN8Vector3iaSERKS_(int* dst, int* src);

struct Vec4fix0201d638 { int v[3]; int w; };
extern "C" extern void _ZN15MaybeVector4fix8CopyFromERKS_(struct Vec4fix0201d638* dst, struct Vec4fix0201d638* src);

struct Vec3fix0201d638 { int x, y, z; };
extern "C" void __clear(void* buf, int n);

struct Elem0209998c {
    unsigned short f0;
    unsigned short f2;
    unsigned char f4;
    char f5[7];
    unsigned char fc;
    unsigned char fd;
    unsigned char fe;
    unsigned char pad;
};
struct List0209998c { struct Elem0209998c* data; int count; int cap; };
extern "C" extern struct Elem0209998c* _Z25FindElementByName0209998cP12List0209998cPKc(struct List0209998c* list, const char* name);

void* GetPtrField0x468(void* obj);

struct GlobalCtx0201d638 { unsigned char* lastEntry; };
extern struct GlobalCtx0201d638 data_020fdc20;

#define REC ((unsigned char*)data_020fdc20.lastEntry)
#define B(off) (*(unsigned char*)(REC + (off)))
#define H(off) (*(short*)(REC + (off)))
#define W(off) (*(int*)(REC + (off)))

struct Bits2c { unsigned char low7 : 7; unsigned char flag : 1; };
#define BITS2C (*(struct Bits2c*)(REC + 0x2c))

struct Bits2e { unsigned short low4 : 4; unsigned short high12 : 12; };
#define BITS2E (*(struct Bits2e*)(REC + 0x2e))

// USA: func_0201d638
extern "C" ARM int _Z20WarpScript_Opcode_74PN6Script9ParameterEi(unsigned char* src, int count) {
    if (data_020fdc20.lastEntry == 0) return 0;

    void* nameList = GetPtrField0x468((void*)GameState::GetInstance());

    switch (W(4)) {
    case 0:
        B(0x2c) = 0;
        if (count != 0) {
            H(0) = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)src);
        }
        goto ret1;

    case 6:
        W(4) = 0;
        B(0x2c) = 1;
        if (count != 0) {
            H(0) = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)src);
        }
        goto ret1;

    case 1:
        if (count != 0) {
            H(0) = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)src);
        }
        goto ret1;

    case 2: {
        if (count == 3) {
            B(0x2c) = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)src);
            B(0x2d) = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)(src + 8));
            BITS2E.high12 = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)(src + 0x10));
            BITS2E.low4 = 0;
            goto ret1;
        }

        int rem = 0;
        B(0x2c) = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)src);
        B(0x2d) = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)(src + 8));
        BITS2E.high12 = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)(src + 0x10));
        struct Param0201d638* flags = (struct Param0201d638*)(src + 0x18);
        src += 0x20;
        BITS2E.low4 = _ZNK6Script9Parameter5ToIntEv(flags);
        rem += 4;

        if (BITS2E.high12 & 8) {
            if (((struct Param0201d638*)src)->tag == 0) {
                char* name = _ZNK6Script9Parameter8ToStringEv((struct Param0201d638*)src);
                src += 8;
                rem += 1;
                struct Elem0209998c* e = _Z25FindElementByName0209998cP12List0209998cPKc((struct List0209998c*)nameList, name);
                if (e == 0) return 0;
                H(0x30) = e->f0;
            } else {
                H(0x30) = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)src);
                src += 8;
                rem += 1;
            }

            H(0x32) = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)src);
            H(0x34) = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)(src + 8));

            int tmp[3];
            struct Param0201d638* p = _ZN6Script9Parameter9ToVec3fixEP8Vector3i((struct Param0201d638*)(src + 0x10), tmp);
            _ZN8Vector3iaSERKS_((int*)(REC + 0x38), tmp);
            int y1 = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv(p));
            src = (unsigned char*)p + 0x10;
            H(0x68) = y1;
            int y2 = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct Param0201d638*)((char*)p + 8)));
            H(0x6a) = y2;
            rem += 7;

            int i;
            for (i = 1; i < 4; i++) {
                p = _ZN6Script9Parameter9ToVec3fixEP8Vector3i((struct Param0201d638*)src, tmp);
                src = (unsigned char*)p;
                rem += 3;
                _ZN8Vector3iaSERKS_((int*)(REC + 0x38 + i * 0xc), tmp);
            }
        }

        if (rem < count) {
            _ZNK6Script9Parameter7ToFloatEv((struct Param0201d638*)src);
            src += 8;
            rem += 1;
        }
        if (rem < count) {
            _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)src);
            src += 8;
        }
        if (BITS2E.high12 & 0x20) {
            W(0x6c) = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct Param0201d638*)src));
        }
        goto ret1;
    }

    case 3:
        B(0x2c) = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)src);
        goto ret1;

    case 4: {
        unsigned char v1 = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)src);
        BITS2C.low7 = v1;
        B(0x2d) = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)(src + 8));
        unsigned char v3 = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)(src + 0x10));
        BITS2C.flag = v3;

        int vecA[3], vecB[3];
        struct Param0201d638* p = _ZN6Script9Parameter9ToVec3fixEP8Vector3i((struct Param0201d638*)(src + 0x18), vecA);
        p = _ZN6Script9Parameter9ToVec3fixEP8Vector3i(p, vecB);
        src = (unsigned char*)p;

        struct Vec4fix0201d638 diffAndDot;
        Vector3fix_Subtract((const Vector3fix*)((struct Vec3fix0201d638*)vecB), (const Vector3fix*)((struct Vec3fix0201d638*)vecA), (Vector3fix*)((struct Vec3fix0201d638*)diffAndDot.v));
        int len = Vector3fix_Length((const Vector3fix*)diffAndDot.v);
        Vector3fix_Normalize((const Vector3fix*)diffAndDot.v, (Vector3fix*)diffAndDot.v);
        diffAndDot.w = Vector3fix_InnerProduct((const Vector3fix*)diffAndDot.v, (const Vector3fix*)vecA);

        int vecC[3];
        __clear(vecC, 0xc);
        if (BITS2C.low7 == 4) {
            p = _ZN6Script9Parameter9ToVec3fixEP8Vector3i((struct Param0201d638*)src, vecC);
            src = (unsigned char*)p;
        } else {
            vecC[1] = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct Param0201d638*)src));
            struct Param0201d638* nxt = (struct Param0201d638*)(src + 8);
            src += 0x10;
            vecC[2] = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv(nxt));
        }

        int vecD[3];
        p = _ZN6Script9Parameter9ToVec3fixEP8Vector3i((struct Param0201d638*)src, vecD);

        _ZN15MaybeVector4fix8CopyFromERKS_((struct Vec4fix0201d638*)(REC + 0x30), &diffAndDot);
        W(0x40) = len;
        _ZN8Vector3iaSERKS_((int*)(REC + 0x44), vecC);
        _ZN8Vector3iaSERKS_((int*)(REC + 0x50), vecD);
        goto ret1;
    }

    case 5:
        H(0x2c) = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)src);
        H(0x2e) = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)(src + 8));
        if (count <= 2) goto ret1;
        H(0) = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)(src + 0x10));
        goto ret1;

    case 8:
        if (count != 0) {
            H(0) = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)src);
        }
        goto ret1;

    case 9: {
        H(0x2c) = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)src);
        H(0x2e) = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)(src + 8));
        B(0x30) = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)(src + 0x10));
        B(0x31) = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)(src + 0x18));
        if ((B(0x31) & 2) == 0) goto ret1;

        if (((struct Param0201d638*)(src + 0x20))->tag == 0) {
            struct Param0201d638* vp = (struct Param0201d638*)(src + 0x20);
            src += 0x28;
            char* name = _ZNK6Script9Parameter8ToStringEv(vp);
            struct Elem0209998c* e = _Z25FindElementByName0209998cP12List0209998cPKc((struct List0209998c*)nameList, name);
            if (e == 0) return 0;
            H(0x32) = e->f0;
        } else {
            struct Param0201d638* vp = (struct Param0201d638*)(src + 0x20);
            src += 0x28;
            H(0x32) = _ZNK6Script9Parameter5ToIntEv(vp);
        }

        H(0x34) = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)src);
        H(0x36) = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)(src + 8));

        struct Param0201d638* p = _ZN6Script9Parameter9ToVec3fixEP8Vector3i((struct Param0201d638*)(src + 0x10), (int*)(REC + 0x38));
        H(0x68) = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv(p));
        H(0x6a) = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct Param0201d638*)((char*)p + 8)));
        p = _ZN6Script9Parameter9ToVec3fixEP8Vector3i((struct Param0201d638*)((char*)p + 0x10), (int*)(REC + 0x44));
        p = _ZN6Script9Parameter9ToVec3fixEP8Vector3i(p, (int*)(REC + 0x50));
        p = _ZN6Script9Parameter9ToVec3fixEP8Vector3i(p, (int*)(REC + 0x5c));
        H(0x6c) = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv(p));
        H(0x6e) = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)((char*)p + 8));
        goto ret1;
    }

    case 10: {
        H(0x2c) = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)src);
        struct Param0201d638* p = _ZN6Script9Parameter9ToVec3fixEP8Vector3i((struct Param0201d638*)(src + 8), (int*)(REC + 0x30));
        H(0x2e) = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv(p));
        W(0x3c) = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct Param0201d638*)((char*)p + 8)));
        if (count <= 6) goto ret1;
        p = _ZN6Script9Parameter9ToVec3fixEP8Vector3i((struct Param0201d638*)((char*)p + 0x10), (int*)(REC + 0x40));
        H(0x4c) = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv(p));
        goto ret1;
    }

    case 12: {
        VectorizedMemset(REC + 0x2c, 0, 0x18);
        B(0x2c) = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)src);
        B(0x2d) = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)(src + 8));
        B(0x2e) = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)(src + 0x10));

        unsigned char* rec = REC;
        switch (rec[0x2c]) {
        case 1:
            rec[0x30] = 0;
            rec[0x31] = 0;
            rec[0x33] = 0;
            rec[0x34] = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)(src + 0x18));
            rec[0x35] = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)(src + 0x20));
            rec[0x32] = _ZNK6Script9Parameter5ToIntEv((struct Param0201d638*)(src + 0x28));
            goto ret1;

        case 2:
            rec[0x30] = 0;
            *(int*)(rec + 0x34) = 0;
            *(int*)(rec + 0x38) = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct Param0201d638*)(src + 0x18)));
            *(int*)(rec + 0x3c) = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct Param0201d638*)(src + 0x20)));
            rec[0x40] = 0x19;
            goto ret1;

        case 3:
            rec[0x30] = 0;
            rec[0x31] = 0;
            *(int*)(rec + 0x34) = 0x733;
            *(int*)(rec + 0x38) = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct Param0201d638*)(src + 0x18)));
            *(int*)(rec + 0x3c) = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct Param0201d638*)(src + 0x20)));
            *(int*)(rec + 0x40) = (int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct Param0201d638*)(src + 0x28)));
            *(int*)(rec + 0x38) = 0x733;
            *(int*)(rec + 0x40) = ~0x198;
            goto ret1;
        }
        goto ret1;
    }
    }

    goto ret1;
ret1:
    return 1;
}
