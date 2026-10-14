#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Memory.h"
#include "Resource/Script.h"

struct Param0201d638 {
    int tag;
    union { int i; float f; } u;
};

struct Vector3i;

struct Vec4fix0201d638 { int v[3]; int w; };
extern "C" extern void _ZN15MaybeVector4fix17CopyFrom_0201d474ERKS_(struct Vec4fix0201d638* dst, struct Vec4fix0201d638* src);

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
extern struct Elem0209998c* FindElementByName0209998c(struct List0209998c* list, const char* name);

void* GetPtrField0x468_02011584(void* obj);

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
extern "C" ARM int _Z29WarpScript_Opcode_74_0201d638PN6Script9ParameterEi(unsigned char* src, int count) {
    if (data_020fdc20.lastEntry == 0) return 0;

    void* nameList = GetPtrField0x468_02011584((void*)GameState::GetInstance());

    switch (W(4)) {
    case 0:
        B(0x2c) = 0;
        if (count != 0) {
            H(0) = ((Script::Parameter*)((struct Param0201d638*)src))->ToInt();
        }
        goto ret1;

    case 6:
        W(4) = 0;
        B(0x2c) = 1;
        if (count != 0) {
            H(0) = ((Script::Parameter*)((struct Param0201d638*)src))->ToInt();
        }
        goto ret1;

    case 1:
        if (count != 0) {
            H(0) = ((Script::Parameter*)((struct Param0201d638*)src))->ToInt();
        }
        goto ret1;

    case 2: {
        if (count == 3) {
            B(0x2c) = ((Script::Parameter*)((struct Param0201d638*)src))->ToInt();
            B(0x2d) = ((Script::Parameter*)((struct Param0201d638*)(src + 8)))->ToInt();
            BITS2E.high12 = ((Script::Parameter*)((struct Param0201d638*)(src + 0x10)))->ToInt();
            BITS2E.low4 = 0;
            goto ret1;
        }

        int rem = 0;
        B(0x2c) = ((Script::Parameter*)((struct Param0201d638*)src))->ToInt();
        B(0x2d) = ((Script::Parameter*)((struct Param0201d638*)(src + 8)))->ToInt();
        BITS2E.high12 = ((Script::Parameter*)((struct Param0201d638*)(src + 0x10)))->ToInt();
        struct Param0201d638* flags = (struct Param0201d638*)(src + 0x18);
        src += 0x20;
        BITS2E.low4 = ((Script::Parameter*)flags)->ToInt();
        rem += 4;

        if (BITS2E.high12 & 8) {
            if (((struct Param0201d638*)src)->tag == 0) {
                char* name = (extern char*)((Script::Parameter*)((struct Param0201d638*)src))->ToString();
                src += 8;
                rem += 1;
                struct Elem0209998c* e = FindElementByName0209998c((struct List0209998c*)nameList, name);
                if (e == 0) return 0;
                H(0x30) = e->f0;
            } else {
                H(0x30) = ((Script::Parameter*)((struct Param0201d638*)src))->ToInt();
                src += 8;
                rem += 1;
            }

            H(0x32) = ((Script::Parameter*)((struct Param0201d638*)src))->ToInt();
            H(0x34) = ((Script::Parameter*)((struct Param0201d638*)(src + 8)))->ToInt();

            int tmp[3];
            struct Param0201d638* p = (extern Param0201d638*)((Script::Parameter*)((struct Param0201d638*)(src + 0x10)))->ToVec3fix((Vector3i*)tmp);
            *(Vector3i*)((int*)(REC + 0x38)) = *(Vector3i const*)tmp;
            int y1 = (int)(4096.0f * ((Script::Parameter*)p)->ToFloat());
            src = (unsigned char*)p + 0x10;
            H(0x68) = y1;
            int y2 = (int)(4096.0f * ((Script::Parameter*)((struct Param0201d638*)((char*)p + 8)))->ToFloat());
            H(0x6a) = y2;
            rem += 7;

            int i;
            for (i = 1; i < 4; i++) {
                p = (extern Param0201d638*)((Script::Parameter*)((struct Param0201d638*)src))->ToVec3fix((Vector3i*)tmp);
                src = (unsigned char*)p;
                rem += 3;
                *(Vector3i*)((int*)(REC + 0x38 + i * 0xc)) = *(Vector3i const*)tmp;
            }
        }

        if (rem < count) {
            ((Script::Parameter*)((struct Param0201d638*)src))->ToFloat();
            src += 8;
            rem += 1;
        }
        if (rem < count) {
            ((Script::Parameter*)((struct Param0201d638*)src))->ToInt();
            src += 8;
        }
        if (BITS2E.high12 & 0x20) {
            W(0x6c) = (int)(4096.0f * ((Script::Parameter*)((struct Param0201d638*)src))->ToFloat());
        }
        goto ret1;
    }

    case 3:
        B(0x2c) = ((Script::Parameter*)((struct Param0201d638*)src))->ToInt();
        goto ret1;

    case 4: {
        unsigned char v1 = ((Script::Parameter*)((struct Param0201d638*)src))->ToInt();
        BITS2C.low7 = v1;
        B(0x2d) = ((Script::Parameter*)((struct Param0201d638*)(src + 8)))->ToInt();
        unsigned char v3 = ((Script::Parameter*)((struct Param0201d638*)(src + 0x10)))->ToInt();
        BITS2C.flag = v3;

        int vecA[3], vecB[3];
        struct Param0201d638* p = (extern Param0201d638*)((Script::Parameter*)((struct Param0201d638*)(src + 0x18)))->ToVec3fix((Vector3i*)vecA);
        p = (extern Param0201d638*)((Script::Parameter*)p)->ToVec3fix((Vector3i*)vecB);
        src = (unsigned char*)p;

        struct Vec4fix0201d638 diffAndDot;
        Vector3fix_Subtract((const Vector3fix*)((struct Vec3fix0201d638*)vecB), (const Vector3fix*)((struct Vec3fix0201d638*)vecA), (Vector3fix*)((struct Vec3fix0201d638*)diffAndDot.v));
        int len = Vector3fix_Length((const Vector3fix*)diffAndDot.v);
        Vector3fix_Normalize((const Vector3fix*)diffAndDot.v, (Vector3fix*)diffAndDot.v);
        diffAndDot.w = Vector3fix_InnerProduct((const Vector3fix*)diffAndDot.v, (const Vector3fix*)vecA);

        int vecC[3];
        __clear(vecC, 0xc);
        if (BITS2C.low7 == 4) {
            p = (extern Param0201d638*)((Script::Parameter*)((struct Param0201d638*)src))->ToVec3fix((Vector3i*)vecC);
            src = (unsigned char*)p;
        } else {
            vecC[1] = (int)(4096.0f * ((Script::Parameter*)((struct Param0201d638*)src))->ToFloat());
            struct Param0201d638* nxt = (struct Param0201d638*)(src + 8);
            src += 0x10;
            vecC[2] = (int)(4096.0f * ((Script::Parameter*)nxt)->ToFloat());
        }

        int vecD[3];
        p = (extern Param0201d638*)((Script::Parameter*)((struct Param0201d638*)src))->ToVec3fix((Vector3i*)vecD);

        _ZN15MaybeVector4fix17CopyFrom_0201d474ERKS_((struct Vec4fix0201d638*)(REC + 0x30), &diffAndDot);
        W(0x40) = len;
        *(Vector3i*)((int*)(REC + 0x44)) = *(Vector3i const*)vecC;
        *(Vector3i*)((int*)(REC + 0x50)) = *(Vector3i const*)vecD;
        goto ret1;
    }

    case 5:
        H(0x2c) = ((Script::Parameter*)((struct Param0201d638*)src))->ToInt();
        H(0x2e) = ((Script::Parameter*)((struct Param0201d638*)(src + 8)))->ToInt();
        if (count <= 2) goto ret1;
        H(0) = ((Script::Parameter*)((struct Param0201d638*)(src + 0x10)))->ToInt();
        goto ret1;

    case 8:
        if (count != 0) {
            H(0) = ((Script::Parameter*)((struct Param0201d638*)src))->ToInt();
        }
        goto ret1;

    case 9: {
        H(0x2c) = ((Script::Parameter*)((struct Param0201d638*)src))->ToInt();
        H(0x2e) = ((Script::Parameter*)((struct Param0201d638*)(src + 8)))->ToInt();
        B(0x30) = ((Script::Parameter*)((struct Param0201d638*)(src + 0x10)))->ToInt();
        B(0x31) = ((Script::Parameter*)((struct Param0201d638*)(src + 0x18)))->ToInt();
        if ((B(0x31) & 2) == 0) goto ret1;

        if (((struct Param0201d638*)(src + 0x20))->tag == 0) {
            struct Param0201d638* vp = (struct Param0201d638*)(src + 0x20);
            src += 0x28;
            char* name = (extern char*)((Script::Parameter*)vp)->ToString();
            struct Elem0209998c* e = FindElementByName0209998c((struct List0209998c*)nameList, name);
            if (e == 0) return 0;
            H(0x32) = e->f0;
        } else {
            struct Param0201d638* vp = (struct Param0201d638*)(src + 0x20);
            src += 0x28;
            H(0x32) = ((Script::Parameter*)vp)->ToInt();
        }

        H(0x34) = ((Script::Parameter*)((struct Param0201d638*)src))->ToInt();
        H(0x36) = ((Script::Parameter*)((struct Param0201d638*)(src + 8)))->ToInt();

        struct Param0201d638* p = (extern Param0201d638*)((Script::Parameter*)((struct Param0201d638*)(src + 0x10)))->ToVec3fix((Vector3i*)(REC + 0x38));
        H(0x68) = (int)(4096.0f * ((Script::Parameter*)p)->ToFloat());
        H(0x6a) = (int)(4096.0f * ((Script::Parameter*)((struct Param0201d638*)((char*)p + 8)))->ToFloat());
        p = (extern Param0201d638*)((Script::Parameter*)((struct Param0201d638*)((char*)p + 0x10)))->ToVec3fix((Vector3i*)(REC + 0x44));
        p = (extern Param0201d638*)((Script::Parameter*)p)->ToVec3fix((Vector3i*)(REC + 0x50));
        p = (extern Param0201d638*)((Script::Parameter*)p)->ToVec3fix((Vector3i*)(REC + 0x5c));
        H(0x6c) = (int)(4096.0f * ((Script::Parameter*)p)->ToFloat());
        H(0x6e) = ((Script::Parameter*)((struct Param0201d638*)((char*)p + 8)))->ToInt();
        goto ret1;
    }

    case 10: {
        H(0x2c) = ((Script::Parameter*)((struct Param0201d638*)src))->ToInt();
        struct Param0201d638* p = (extern Param0201d638*)((Script::Parameter*)((struct Param0201d638*)(src + 8)))->ToVec3fix((Vector3i*)(REC + 0x30));
        H(0x2e) = (int)(4096.0f * ((Script::Parameter*)p)->ToFloat());
        W(0x3c) = (int)(4096.0f * ((Script::Parameter*)((struct Param0201d638*)((char*)p + 8)))->ToFloat());
        if (count <= 6) goto ret1;
        p = (extern Param0201d638*)((Script::Parameter*)((struct Param0201d638*)((char*)p + 0x10)))->ToVec3fix((Vector3i*)(REC + 0x40));
        H(0x4c) = (int)(4096.0f * ((Script::Parameter*)p)->ToFloat());
        goto ret1;
    }

    case 12: {
        VectorizedMemset(REC + 0x2c, 0, 0x18);
        B(0x2c) = ((Script::Parameter*)((struct Param0201d638*)src))->ToInt();
        B(0x2d) = ((Script::Parameter*)((struct Param0201d638*)(src + 8)))->ToInt();
        B(0x2e) = ((Script::Parameter*)((struct Param0201d638*)(src + 0x10)))->ToInt();

        unsigned char* rec = REC;
        switch (rec[0x2c]) {
        case 1:
            rec[0x30] = 0;
            rec[0x31] = 0;
            rec[0x33] = 0;
            rec[0x34] = ((Script::Parameter*)((struct Param0201d638*)(src + 0x18)))->ToInt();
            rec[0x35] = ((Script::Parameter*)((struct Param0201d638*)(src + 0x20)))->ToInt();
            rec[0x32] = ((Script::Parameter*)((struct Param0201d638*)(src + 0x28)))->ToInt();
            goto ret1;

        case 2:
            rec[0x30] = 0;
            *(int*)(rec + 0x34) = 0;
            *(int*)(rec + 0x38) = (int)(4096.0f * ((Script::Parameter*)((struct Param0201d638*)(src + 0x18)))->ToFloat());
            *(int*)(rec + 0x3c) = (int)(4096.0f * ((Script::Parameter*)((struct Param0201d638*)(src + 0x20)))->ToFloat());
            rec[0x40] = 0x19;
            goto ret1;

        case 3:
            rec[0x30] = 0;
            rec[0x31] = 0;
            *(int*)(rec + 0x34) = 0x733;
            *(int*)(rec + 0x38) = (int)(4096.0f * ((Script::Parameter*)((struct Param0201d638*)(src + 0x18)))->ToFloat());
            *(int*)(rec + 0x3c) = (int)(4096.0f * ((Script::Parameter*)((struct Param0201d638*)(src + 0x20)))->ToFloat());
            *(int*)(rec + 0x40) = (int)(4096.0f * ((Script::Parameter*)((struct Param0201d638*)(src + 0x28)))->ToFloat());
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
