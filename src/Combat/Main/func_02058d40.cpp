#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/SignedAllocator.h"
#include "World/Object3D.h"

extern "C" int rand(void);

struct S02055080;
void* GetSubField0x14_02055108(struct S02055080* p);
void* GetSubField0x18_02055120(struct S02055080* p);
void* GetSubField0xC_020550d8(struct S02055080* p);
void* GetField0x4Field0x1cOrNull_02055138(struct S02055080* obj);
void* GetField0x4Field0x20OrNull_02055150(struct S02055080* obj);

struct S02055080 {
    SafeAllocator* alloc;
    void* fieldSub;
    SignedAllocatorList listB[3];
    SignedAllocatorList listC[3];
    SignedAllocatorList listD[3];
    SignedAllocatorList listE;
    SignedAllocatorList listF[3];
    SignedAllocatorList listG;
    SignedAllocatorList listH[2];
    SignedAllocatorList listI[2];
    SignedAllocatorList listJ;
    SignedAllocatorList listK[4];
    SignedAllocatorList listA;
};

struct WeatherFlags14 {
    unsigned char field_0x0;
    unsigned char field_0x1;
    unsigned char field_0x2;
    unsigned char field_0x3;
    unsigned char field_0x4;
    unsigned char field_0x5;
    unsigned char field_0x6;
};

struct RArrCount2_02058d40 {
    void* arr[2];
    unsigned char count[2];
};

struct Cfg0xC_02058d40 {
    char pad0[0x17];
    unsigned char field_0x17;
};

struct Cfg0x20_02058d40 {
    short base;
    unsigned char jitterRange;
    char pad3;
    void* arr;
    unsigned char count;
};

struct Pair0xb0_02058d40 {
    unsigned int a;
    unsigned int b;
};
struct NodePair0xb0_02058d40 {
    Pair0xb0_02058d40* p;
};

struct PointRGA_02058d40 {
    unsigned int x;
    float r;
    float g;
    float amp;
};
struct NodeRGA_02058d40 {
    PointRGA_02058d40* p;
};

struct PointHue_02058d40 {
    int x;
    float val;
    float amp;
};
struct NodeHue_02058d40 {
    PointHue_02058d40* p;
};

struct Obj02058d40 {
    char pad0[0x4];
    int field_0x4;
    int field_0x8;
    unsigned char field_0xc;
    char pad1[0x28 - 0xd];
    S02055080* weatherList;
    char pad2[0x30 - 0x2c];
    float field_0x30;
    float field_0x34;
    float field_0x38;
    float field_0x3c;
    float field_0x40;
    float field_0x44;
    float field_0x48;
    float field_0x4c;
    float field_0x50;
    float field_0x54;
    float field_0x58;
    float field_0x5c;
    float field_0x60;
    unsigned short field_0x64;
    unsigned short field_0x66;
    unsigned short field_0x68;
    unsigned short field_0x6a;
    char pad4[0x78 - 0x6c];
    float field_0x78;
    Object3D object;
    unsigned int field_0x128;
    float field_0x12c;
    float field_0x130;
    float field_0x134;
    float field_0x138;
    float field_0x13c;
    float field_0x140;
    float field_0x144;
};

// USA: func_02058d40
extern "C" ARM void func_02058d40(struct Obj02058d40* self, struct S02055080* weatherList, Object3D* templateObj, unsigned int timeCursor) {
    self->weatherList = weatherList;
    self->object.Initialize();
    templateObj->ShallowCloneTo(&self->object);
    self->object.SetFlag16();

    struct WeatherFlags14* flags = (struct WeatherFlags14*)GetSubField0x14_02055108(self->weatherList);
    if (flags->field_0x3 != 0) {
        self->field_0xc = 1;
    } else {
        unsigned char baseValue = flags->field_0x0;
        int randVal = rand();
        float baseFloat = (float)baseValue;
        unsigned char randomRange = flags->field_0x1;
        int rem = randVal % randomRange;
        float fracF = (float)(-rem) / 100.0f;
        self->field_0x8 = baseValue + (int)(baseFloat * fracF);
        self->field_0x4 = 0;
        self->field_0x30 = (float)(unsigned int)self->field_0x8 / (float)flags->field_0x0;
    }

    struct RArrCount2_02058d40* pairCurveSettings = (struct RArrCount2_02058d40*)GetSubField0x18_02055120(self->weatherList);
    struct NodePair0xb0_02058d40* colorCurveFirstNode = (struct NodePair0xb0_02058d40*)self->weatherList->listH[0].ElementAfter(NULL);
    self->field_0x12c = (float)(colorCurveFirstNode->p->b & 0x1f);
    self->field_0x130 = (float)((colorCurveFirstNode->p->b & 0x3e0) >> 5);
    self->field_0x134 = (float)((colorCurveFirstNode->p->b & 0x7c00) >> 0xa);

    if (pairCurveSettings->count[0] > 1) {
        self->field_0x64 = 1;
        struct NodePair0xb0_02058d40* colorCurveSecondNode = (struct NodePair0xb0_02058d40*)self->weatherList->listH[0].GetNthElement(1);
        if (colorCurveSecondNode != NULL) {
            unsigned int secondGreen = (colorCurveSecondNode->p->b & 0x3e0) >> 5;
            unsigned int secondBlue = (colorCurveSecondNode->p->b & 0x7c00) >> 0xa;
            unsigned int secondRed = colorCurveSecondNode->p->b & 0x1f;
            self->field_0x34 = ((float)secondRed - self->field_0x12c) /
                             (float)((int)colorCurveSecondNode->p->a - (int)colorCurveFirstNode->p->a);
            self->field_0x38 = ((float)secondGreen - self->field_0x130) /
                             (float)((int)colorCurveSecondNode->p->a - (int)colorCurveFirstNode->p->a);
            self->field_0x3c = ((float)secondBlue - self->field_0x134) /
                             (float)((int)colorCurveSecondNode->p->a - (int)colorCurveFirstNode->p->a);
        }
    }

    struct NodePair0xb0_02058d40* scalarCurveFirstNode = (struct NodePair0xb0_02058d40*)self->weatherList->listH[1].ElementAfter(NULL);
    self->field_0x138 = (float)scalarCurveFirstNode->p->b;

    if (pairCurveSettings->count[1] > 1) {
        self->field_0x66 = 1;
        struct NodePair0xb0_02058d40* scalarCurveSecondNode = (struct NodePair0xb0_02058d40*)self->weatherList->listH[1].GetNthElement(1);
        if (scalarCurveSecondNode != NULL) {
            float firstPosition = (float)scalarCurveFirstNode->p->a * self->field_0x30;
            float secondPosition = (float)scalarCurveSecondNode->p->a * self->field_0x30;
            float valueDifference = (float)((int)scalarCurveSecondNode->p->b - (int)scalarCurveFirstNode->p->b);
            self->field_0x40 = valueDifference / (secondPosition - firstPosition);
        }
    }

    struct RArrCount2_02058d40* twoChannelCurveSettings = (struct RArrCount2_02058d40*)GetField0x4Field0x1cOrNull_02055138(self->weatherList);
    struct NodeRGA_02058d40* curveC8CurrentNode = (struct NodeRGA_02058d40*)self->weatherList->listI[0].ElementAfter(NULL);
    struct NodeRGA_02058d40* curveC8PreviousNode = NULL;
    if (curveC8CurrentNode != NULL) {
        unsigned int curveC8Index = 0;
        int curveC8Count = 0;
        goto checkCurveC8Count;
        for (;;) {
            if (curveC8CurrentNode->p->x >= timeCursor) break;
            curveC8Index = curveC8Index + 1;
            curveC8PreviousNode = curveC8CurrentNode;
            curveC8CurrentNode = (struct NodeRGA_02058d40*)self->weatherList->listI[0].GetNthElement((unsigned short)curveC8Index);
            if (curveC8CurrentNode == NULL) break;
            curveC8Count = curveC8Count + 1;
        checkCurveC8Count:
            if (curveC8Count >= twoChannelCurveSettings->count[0]) break;
        }

        float prevR, prevG, curR, curG;
        if (curveC8CurrentNode != NULL) {
            if (curveC8PreviousNode != NULL) {
                PointRGA_02058d40* prevPoint = curveC8PreviousNode->p;
                prevR = prevPoint->r;
                prevG = prevPoint->g;
                int rand1 = rand();
                int prevAmpFix1 = (int)prevPoint->amp;
                int prevAmpFix2 = (int)prevPoint->amp;
                int prevJr = (rand1 & (prevAmpFix1 << 1)) - prevAmpFix2;
                float prevJitter = (float)prevJr / 100.0f;

                PointRGA_02058d40* curPoint = curveC8CurrentNode->p;
                curR = curPoint->r;
                curG = curPoint->g;
                int rand2 = rand();
                int curAmpFix1 = (int)curPoint->amp;
                int curAmpFix2 = (int)curPoint->amp;
                int curJr = (rand2 & (curAmpFix1 << 1)) - curAmpFix2;
                float curJitter = (float)curJr / 100.0f;

                int prevX = (int)curveC8PreviousNode->p->x;
                int curX = (int)curPoint->x;
                int span = curX - prevX;
                int diffTime = (int)(timeCursor - (unsigned int)prevX);
                float timeFraction = (float)diffTime;
                float jitterSlope = (curJitter - prevJitter) / (float)span;
                float jitterAtTime = prevJitter + timeFraction * jitterSlope;

                float rTime = (float)diffTime;
                float rSlope = (curR - prevR) / (float)span;
                self->field_0x50 = prevR + rTime * rSlope;

                float gTime = (float)diffTime;
                float gSlope = (curG - prevG) / (float)span;
                self->field_0x54 = prevG + gTime * gSlope;

                self->field_0x50 = self->field_0x50 + self->field_0x50 * jitterAtTime;
                self->field_0x54 = self->field_0x54 + self->field_0x54 * jitterAtTime;
            } else {
                PointRGA_02058d40* point = curveC8CurrentNode->p;
                float rVal = point->r;
                float gVal = point->g;
                int random = rand();
                int ampInt = (int)point->amp;
                int ampInt2 = (int)point->amp;
                int jr = (random & (ampInt << 1)) - ampInt2;
                float jitter = (float)jr / 100.0f;
                self->field_0x50 = rVal + rVal * jitter;
                self->field_0x54 = gVal + gVal * jitter;
            }
        } else {
            PointRGA_02058d40* point = curveC8PreviousNode->p;
            float rVal = point->r;
            float gVal = point->g;
            int random = rand();
            int ampInt = (int)point->amp;
            int ampInt2 = (int)point->amp;
            int jr = (random & (ampInt << 1)) - ampInt2;
            float jitter = (float)jr / 100.0f;
            self->field_0x50 = rVal + rVal * jitter;
            self->field_0x54 = gVal + gVal * jitter;
        }
    }

    struct NodeRGA_02058d40* curveD4FirstNode = (struct NodeRGA_02058d40*)self->weatherList->listI[1].ElementAfter(NULL);
    if (curveD4FirstNode != NULL) {
        PointRGA_02058d40* firstPoint = curveD4FirstNode->p;
        int random = rand();
        float jitter1 = ((float)((int)(firstPoint->amp * 2.0f) & random) - firstPoint->amp) / 100.0f;
        self->field_0x13c = firstPoint->r + firstPoint->r * jitter1;
        self->field_0x140 = curveD4FirstNode->p->g + curveD4FirstNode->p->g * jitter1;

        if (twoChannelCurveSettings->count[1] > 1) {
            self->field_0x68 = 1;
            struct NodeRGA_02058d40* curveD4SecondNode = (struct NodeRGA_02058d40*)self->weatherList->listI[1].GetNthElement(1);
            if (curveD4SecondNode != NULL) {
                PointRGA_02058d40* secondPoint = curveD4SecondNode->p;
                int rand3 = rand();
                int ampFix1 = (int)secondPoint->amp;
                int ampFix2 = (int)secondPoint->amp;
                int jr2 = (rand3 & (ampFix1 << 1)) - ampFix2;
                float jitter2 = (float)jr2 / 100.0f;
                self->field_0x58 = secondPoint->r + secondPoint->r * jitter2;
                self->field_0x5c = curveD4SecondNode->p->g + curveD4SecondNode->p->g * jitter2;

                self->field_0x44 = (self->field_0x58 - self->field_0x13c) / (float)((int)curveD4SecondNode->p->x - (int)curveD4FirstNode->p->x);
                self->field_0x48 = (self->field_0x5c - self->field_0x140) / (float)((int)curveD4SecondNode->p->x - (int)curveD4FirstNode->p->x);
            }
        }
    }

    struct Cfg0x20_02058d40* hueCfg = (struct Cfg0x20_02058d40*)GetField0x4Field0x20OrNull_02055150(self->weatherList);
    struct SignedAllocatorHeader* hueCurveFirstHeader = self->weatherList->listJ.ElementAfter(NULL);
    {
        int jr = (rand() & (hueCfg->jitterRange << 1)) - hueCfg->jitterRange;
        float jitter = (float)jr / 100.0f;
        short baseHue = hueCfg->base;
        self->field_0x144 = (float)baseHue + (float)baseHue * jitter;
    }
    if (self->field_0x144 < 0.0f) self->field_0x144 += 360.0f;
    if (self->field_0x144 > 360.0f) self->field_0x144 = self->field_0x144 - 360.0f;

    if (hueCfg->count > 1) {
        self->field_0x6a = 1;
        struct SignedAllocatorHeader* hueCurveSecondHeader = self->weatherList->listJ.GetNthElement(1);
        if (hueCurveSecondHeader != NULL) {
            struct NodeHue_02058d40* hueCurveSecondNode = (struct NodeHue_02058d40*)hueCurveSecondHeader;
            PointHue_02058d40* huePoint = hueCurveSecondNode->p;
            int randVal2 = rand();
            int ampFix1 = (int)huePoint->amp;
            int ampFix2 = (int)huePoint->amp;
            int jr2 = (randVal2 & (ampFix1 << 1)) - ampFix2;
            float jitter2 = (float)jr2 / 100.0f;
            self->field_0x60 = huePoint->val + huePoint->val * jitter2;

            struct NodeHue_02058d40* hueCurveFirstNode = (struct NodeHue_02058d40*)hueCurveFirstHeader;
            int span3 = hueCurveSecondNode->p->x - hueCurveFirstNode->p->x;
            self->field_0x4c = self->field_0x60 / (float)span3;

            if (self->field_0x4c < 0.0f) self->field_0x4c += 360.0f;
            if (self->field_0x4c > 360.0f) self->field_0x4c = self->field_0x4c - 360.0f;
        }
    }

    struct WeatherFlags14* flags2 = (struct WeatherFlags14*)GetSubField0x14_02055108(self->weatherList);
    if (flags2->field_0x4 != 0) {
        self->object.MaybeSetBCFGAnimation(0, 0);
    } else {
        self->object.MaybeSetBCFGAnimation(0, 1);
    }

    if (flags2->field_0x6 != 0) {
        if (rand() % 2 != 0) {
            self->field_0x4c = 0.0f - self->field_0x4c;
        }
    }

    struct Cfg0xC_02058d40* cCfg = (struct Cfg0xC_02058d40*)GetSubField0xC_020550d8(self->weatherList);
    unsigned char scaleRandomRange = cCfg->field_0x17;
    int rem2 = rand() % scaleRandomRange;
    float scale = (float)(100 - rem2) * 0.01f;
    self->field_0x78 = self->field_0x78 * scale;
}
