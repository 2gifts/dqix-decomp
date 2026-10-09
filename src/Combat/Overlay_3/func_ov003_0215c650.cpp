#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "System/Graphics.h"

struct MainBgControlBackup02074af4 {
    volatile unsigned short savedBg0Cnt;
    char pad2[2];
    volatile unsigned short savedBg1Cnt;
    char pad6[2];
    volatile unsigned short savedBg2Cnt;
    char padA[2];
    volatile unsigned short savedBg3Cnt;
    char padE[2];
    unsigned char initialized;
    unsigned char field11;
};

struct Struct020dfc40 {
    char data[0x18];
};

struct InitTarget0205cfd4 {
    char data[0xbc];
};

struct List0204af64 {
    char data[0x20];
};

struct Elem0204c684 {
    char data[0xe0];
};

struct Panel0215c650 {
    SafeAllocator alloc0;
    SafeAllocator alloc14;
    SafeAllocator alloc28;
    SafeAllocator alloc3c;
    SafeAllocator alloc50;
    struct Struct020dfc40 sub64;
    void* textBuf;
    struct MainBgControlBackup02074af4 bgBackup;
    int savedBgPlanes;
    struct InitTarget0205cfd4 sub98;
    struct List0204af64 lists[2];
    struct Elem0204c684 elems[2];
    int field354;
    char sub358[0x3ac - 0x358];
    int field3ac;
    int field3b0;
    int field3b4;
    unsigned char field3b8;
    unsigned char field3b9;
    unsigned char field3ba;
    unsigned char field3bb;
    unsigned char field3bc;
    unsigned char field3bd[3];
    unsigned char field3c0;
    signed char field3c1;
    unsigned char field3c2;
    unsigned char field3c3;
    unsigned char field3c4[4];
    int field3c8;
    int field3cc;
    int timeOfDay;
    float nightToMorning;
    float morningToDay;
    float dayToEvening;
    float eveningToNight;
    float transitionTime;
    int field3e8;
    unsigned char field3ec;
    unsigned char field3ed;
    unsigned char field3ee;
    unsigned char field3ef;
    unsigned char field3f0;
    unsigned char field3f1;
    unsigned char field3f2;
    unsigned char field3f3;
    unsigned char field3f4;
    unsigned char field3f5;
    int field3f8;
};

extern "C" void func_02074af4(struct MainBgControlBackup02074af4* obj);
extern "C" void _Z19ResetStruct020dfc40P14Struct020dfc40(struct Struct020dfc40* p);
extern "C" void _Z18InitStruct0205cfd4P18InitTarget0205cfd4(struct InitTarget0205cfd4* s);
extern "C" void _Z17ResetList0204af64P12List0204af64(struct List0204af64* obj);
extern "C" void func_0204c684(struct Elem0204c684* obj);
extern "C" void _Z18InitStruct0205a444Pc(char* obj);

// USA: func_ov003_0215c650
extern "C" ARM void func_ov003_0215c650(struct Panel0215c650* self) {
    self->bgBackup.initialized = 0;
    self->bgBackup.field11 = 0;
    func_02074af4(&self->bgBackup);
    self->savedBgPlanes = (DISPCNT & 0x1f00) >> 8;
    DISPCNT = (DISPCNT & ~0x1f00) | 0x100;

    self->alloc0.ResetAllocatorPointer();
    self->alloc28.ResetAllocatorPointer();
    self->alloc3c.ResetAllocatorPointer();
    self->alloc50.ResetAllocatorPointer();
    _Z19ResetStruct020dfc40P14Struct020dfc40(&self->sub64);
    self->textBuf = 0;
    _Z18InitStruct0205cfd4P18InitTarget0205cfd4(&self->sub98);

    for (int i = 0; i < 2; i++) {
        _Z17ResetList0204af64P12List0204af64(&self->lists[i]);
    }
    for (int j = 0; j < 2; j++) {
        func_0204c684(&self->elems[j]);
    }

    self->field354 = 0;
    _Z18InitStruct0205a444Pc(self->sub358);
    self->field3ac = 0;
    self->field3b0 = 0;
    self->field3b4 = 0;
    self->field3b8 = 0;
    self->field3b9 = 0;
    self->field3bc = 0;
    self->field3ba = 0;
    self->field3bb = 0;
    for (int k = 0; k < 3; k++) {
        self->field3bd[k] = 0xff;
    }
    self->field3c0 = 0;
    self->field3c1 = -1;
    self->field3c2 = 0;
    self->field3c3 = 0;
    for (int m = 0; m < 4; m++) {
        self->field3c4[m] = 0xff;
    }
    self->field3c8 = -1;
    self->field3cc = -1;
    GetDayThresholds(&self->nightToMorning, &self->morningToDay, &self->dayToEvening,
                     &self->eveningToNight, &self->transitionTime);
    self->timeOfDay = GameState::GetInstance()->IsMorningDayOrEvening();
    self->field3ec = 0;
    self->field3ed = 0;
    self->field3ee = 0;
    self->field3ef = 1;
    self->field3f0 = 0;
    self->field3f1 = 0;
    self->field3f2 = 0;
    self->field3f3 = 0;
    self->field3f8 = 0;
    self->field3f4 = 0;
    self->field3f5 = 0;
    self->field3e8 = 0;
}
