#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Memory.h"
#include "Resource/Script.h"
#include "World/ZoneFeatures.h"
#include "Combat/Main/ElementLookup.h"

struct Vector3i;

struct Vec3fix0201d638 { int x, y, z; };
extern "C" void __clear(void* buf, int n);

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
ARM int WarpScript_Opcode_74_0201d638(Script::Parameter* src, int count) {
    if (data_020fdc20.lastEntry == 0) return 0;

    void* nameList = GetPtrField0x468_02011584((void*)GameState::GetInstance());

    switch (W(4)) {
    case 0:
        B(0x2c) = 0;
        if (count != 0) {
            H(0) = src[0].ToInt();
        }
        goto ret1;

    case 6:
        W(4) = 0;
        B(0x2c) = 1;
        if (count != 0) {
            H(0) = src[0].ToInt();
        }
        goto ret1;

    case 1:
        if (count != 0) {
            H(0) = src[0].ToInt();
        }
        goto ret1;

    case 2: {
        if (count == 3) {
            B(0x2c) = src[0].ToInt();
            B(0x2d) = src[1].ToInt();
            BITS2E.high12 = src[2].ToInt();
            BITS2E.low4 = 0;
            goto ret1;
        }

        int rem = 0;
        B(0x2c) = src[0].ToInt();
        B(0x2d) = src[1].ToInt();
        BITS2E.high12 = src[2].ToInt();
        Script::Parameter* flags = src + 3;
        src += 4;
        BITS2E.low4 = flags->ToInt();
        rem += 4;

        if (BITS2E.high12 & 8) {
            if (src->type == 0) {
                const char* name = src->ToString();
                src += 1;
                rem += 1;
                struct Elem0209998c* e = FindElementByName0209998c((struct List0209998c*)nameList, name);
                if (e == 0) return 0;
                H(0x30) = e->f0;
            } else {
                H(0x30) = src->ToInt();
                src += 1;
                rem += 1;
            }

            H(0x32) = src[0].ToInt();
            H(0x34) = src[1].ToInt();

            int tmp[3];
            Script::Parameter* p = src[2].ToVec3fix((Vector3i*)tmp);
            *(Vector3i*)((int*)(REC + 0x38)) = *(Vector3i const*)tmp;
            int y1 = (int)(4096.0f * p[0].ToFloat());
            src = p + 2;
            H(0x68) = y1;
            int y2 = (int)(4096.0f * p[1].ToFloat());
            H(0x6a) = y2;
            rem += 7;

            int i;
            for (i = 1; i < 4; i++) {
                p = src->ToVec3fix((Vector3i*)tmp);
                src = p;
                rem += 3;
                *(Vector3i*)((int*)(REC + 0x38 + i * 0xc)) = *(Vector3i const*)tmp;
            }
        }

        if (rem < count) {
            src->ToFloat();
            src += 1;
            rem += 1;
        }
        if (rem < count) {
            src->ToInt();
            src += 1;
        }
        if (BITS2E.high12 & 0x20) {
            W(0x6c) = (int)(4096.0f * src->ToFloat());
        }
        goto ret1;
    }

    case 3:
        B(0x2c) = src[0].ToInt();
        goto ret1;

    case 4: {
        unsigned char v1 = src[0].ToInt();
        BITS2C.low7 = v1;
        B(0x2d) = src[1].ToInt();
        unsigned char v3 = src[2].ToInt();
        BITS2C.flag = v3;

        int vecA[3], vecB[3];
        Script::Parameter* p = src[3].ToVec3fix((Vector3i*)vecA);
        p = p->ToVec3fix((Vector3i*)vecB);
        src = p;

        MaybeVector4fix diffAndDot;
        Vector3fix_Subtract((const Vector3fix*)((struct Vec3fix0201d638*)vecB), (const Vector3fix*)((struct Vec3fix0201d638*)vecA), &diffAndDot.vec3.vec);
        int len = Vector3fix_Length(&diffAndDot.vec3.vec);
        Vector3fix_Normalize(&diffAndDot.vec3.vec, &diffAndDot.vec3.vec);
        diffAndDot.w = Vector3fix_InnerProduct(&diffAndDot.vec3.vec, (const Vector3fix*)vecA);

        int vecC[3];
        __clear(vecC, 0xc);
        if (BITS2C.low7 == 4) {
            p = src->ToVec3fix((Vector3i*)vecC);
            src = p;
        } else {
            vecC[1] = (int)(4096.0f * src->ToFloat());
            Script::Parameter* nxt = src + 1;
            src += 2;
            vecC[2] = (int)(4096.0f * nxt->ToFloat());
        }

        int vecD[3];
        p = src->ToVec3fix((Vector3i*)vecD);

        ((MaybeVector4fix*)(REC + 0x30))->CopyFrom_0201d474(diffAndDot);
        W(0x40) = len;
        *(Vector3i*)((int*)(REC + 0x44)) = *(Vector3i const*)vecC;
        *(Vector3i*)((int*)(REC + 0x50)) = *(Vector3i const*)vecD;
        goto ret1;
    }

    case 5:
        H(0x2c) = src[0].ToInt();
        H(0x2e) = src[1].ToInt();
        if (count <= 2) goto ret1;
        H(0) = src[2].ToInt();
        goto ret1;

    case 8:
        if (count != 0) {
            H(0) = src[0].ToInt();
        }
        goto ret1;

    case 9: {
        H(0x2c) = src[0].ToInt();
        H(0x2e) = src[1].ToInt();
        B(0x30) = src[2].ToInt();
        B(0x31) = src[3].ToInt();
        if ((B(0x31) & 2) == 0) goto ret1;

        if (src[4].type == 0) {
            Script::Parameter* vp = src + 4;
            src += 5;
            const char* name = vp->ToString();
            struct Elem0209998c* e = FindElementByName0209998c((struct List0209998c*)nameList, name);
            if (e == 0) return 0;
            H(0x32) = e->f0;
        } else {
            Script::Parameter* vp = src + 4;
            src += 5;
            H(0x32) = vp->ToInt();
        }

        H(0x34) = src[0].ToInt();
        H(0x36) = src[1].ToInt();

        Script::Parameter* p = src[2].ToVec3fix((Vector3i*)(REC + 0x38));
        H(0x68) = (int)(4096.0f * p[0].ToFloat());
        H(0x6a) = (int)(4096.0f * p[1].ToFloat());
        p = p[2].ToVec3fix((Vector3i*)(REC + 0x44));
        p = p->ToVec3fix((Vector3i*)(REC + 0x50));
        p = p->ToVec3fix((Vector3i*)(REC + 0x5c));
        H(0x6c) = (int)(4096.0f * p[0].ToFloat());
        H(0x6e) = p[1].ToInt();
        goto ret1;
    }

    case 10: {
        H(0x2c) = src[0].ToInt();
        Script::Parameter* p = src[1].ToVec3fix((Vector3i*)(REC + 0x30));
        H(0x2e) = (int)(4096.0f * p[0].ToFloat());
        W(0x3c) = (int)(4096.0f * p[1].ToFloat());
        if (count <= 6) goto ret1;
        p = p[2].ToVec3fix((Vector3i*)(REC + 0x40));
        H(0x4c) = (int)(4096.0f * p[0].ToFloat());
        goto ret1;
    }

    case 12: {
        VectorizedMemset(REC + 0x2c, 0, 0x18);
        B(0x2c) = src[0].ToInt();
        B(0x2d) = src[1].ToInt();
        B(0x2e) = src[2].ToInt();

        unsigned char* rec = REC;
        switch (rec[0x2c]) {
        case 1:
            rec[0x30] = 0;
            rec[0x31] = 0;
            rec[0x33] = 0;
            rec[0x34] = src[3].ToInt();
            rec[0x35] = src[4].ToInt();
            rec[0x32] = src[5].ToInt();
            goto ret1;

        case 2:
            rec[0x30] = 0;
            *(int*)(rec + 0x34) = 0;
            *(int*)(rec + 0x38) = (int)(4096.0f * src[3].ToFloat());
            *(int*)(rec + 0x3c) = (int)(4096.0f * src[4].ToFloat());
            rec[0x40] = 0x19;
            goto ret1;

        case 3:
            rec[0x30] = 0;
            rec[0x31] = 0;
            *(int*)(rec + 0x34) = 0x733;
            *(int*)(rec + 0x38) = (int)(4096.0f * src[3].ToFloat());
            *(int*)(rec + 0x3c) = (int)(4096.0f * src[4].ToFloat());
            *(int*)(rec + 0x40) = (int)(4096.0f * src[5].ToFloat());
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
