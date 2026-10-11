#if defined(jpn)
#define R(j,u) (j)
#define data_ov015_02193d14 data_ov015_02194844
#define data_ov015_02193d2c data_ov015_0219485c
#define data_ov015_02193d38 data_ov015_02194868
#define data_ov027_021dd8e0 data_ov027_021de1a0
#define func_ov003_021594c4 func_ov003_0215a990
#define func_ov003_0215a740 func_ov003_0215bbc0
#define func_ov014_0218854c func_ov014_0218942c
#define func_ov014_021885bc func_ov014_0218948c
#define func_ov015_0219050c func_ov015_021910b0
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <System/Graphics.h>

struct Struct020dfc40;
struct List0204af64;
struct InitTarget0205cfd4;
struct Struct020a9ea4;

struct ScreenState02158bb8 {
    char registers[0x10];
    unsigned char initialized;
    unsigned char field_0x11;
    char pad12[2];
};

extern "C" void func_02074af4(ScreenState02158bb8* state);
extern "C" void func_0204c684(void* canvas);
extern "C" void _Z18InitStruct0205a444Pc(char* obj);
extern "C" void _Z18InitStruct0205cfd4P18InitTarget0205cfd4(InitTarget0205cfd4* window);
extern "C" void _Z17ResetList0204af64P12List0204af64(List0204af64* background);
extern "C" void _Z19ResetStruct020dfc40P14Struct020dfc40(Struct020dfc40* texts);
extern "C" void _Z19ClearStruct020a9ea4P14Struct020a9ea4(Struct020a9ea4* p);

struct Obj02158bb8 {
    SafeAllocator alloc0;
    SafeAllocator alloc14;
    SafeAllocator alloc28;
    SafeAllocator alloc3c;
    SafeAllocator alloc50;
    char texts[0x80 - 0x64];
    ScreenState02158bb8 screenState;
    int layers;
    char field_0x98[0xec - 0x98];
    void* entries;
    void* clearTarget;
    char window[0x1b0 - 0xf4];
    char backgrounds[2][0x20];
    char canvases[4][0xe0];
    void* entryManager;
    char pad574[0x580 - 0x574];
    unsigned char field_0x580;
    unsigned char field_0x581;
    unsigned char field_0x582;
    unsigned char field_0x583;
    unsigned char field_0x584;
    signed char field_0x585;
    unsigned char field_0x586;
    unsigned char field_0x587;
    unsigned char field_0x588;
    unsigned char field_0x589;
    signed char field_0x58a[6];
    unsigned char field_0x590;
    unsigned char field_0x591[4];
    char pad595[0x598 - 0x595];
    int field_0x598;
    unsigned char field_0x59c;
    unsigned char field_0x59d;
    unsigned char field_0x59e;
    unsigned char field_0x59f;
    unsigned char field_0x5a0;
    signed char field_0x5a1;
    char pad5a2[2];
    int field_0x5a4;
    int field_0x5a8;
    int field_0x5ac;
    unsigned char field_0x5b0;
    unsigned char field_0x5b1;
    unsigned char field_0x5b2;
    unsigned char field_0x5b3;
    unsigned char field_0x5b4;
    char pad5b5[3];
    char field_0x5b8[4];
};

// USA: func_ov003_02158bb8
extern "C" ARM void func_ov003_02158bb8(Obj02158bb8* self)
{
    self->screenState.initialized = 0;
    self->screenState.field_0x11 = 0;
    func_02074af4(&self->screenState);
    self->layers = (DISPCNT & 0x1f00) >> 8;
    DISPCNT = (DISPCNT & ~0x1f00) | 0x100;
    _Z18InitStruct0205a444Pc(self->field_0x98);
    self->entries = NULL;
    self->clearTarget = NULL;
    self->alloc3c.ResetAllocatorPointer();
    self->alloc28.ResetAllocatorPointer();
    self->alloc14.ResetAllocatorPointer();
    self->alloc0.ResetAllocatorPointer();
    _Z18InitStruct0205cfd4P18InitTarget0205cfd4((InitTarget0205cfd4*)self->window);
    for (int i = 0; i < 2; i++) {
        _Z17ResetList0204af64P12List0204af64((List0204af64*)self->backgrounds[i]);
    }
    for (int i = 0; i < 4; i++) {
        func_0204c684(self->canvases[i]);
    }
    _Z19ResetStruct020dfc40P14Struct020dfc40((Struct020dfc40*)self->texts);
    self->field_0x587 = 0;
    self->field_0x588 = 0;
    self->field_0x580 = 0;
    self->field_0x581 = 0;
    self->field_0x589 = 0;
    for (int i = 0; i < 6; i++) {
        self->field_0x58a[i] = -1;
    }
    self->field_0x590 = 0;
    for (int i = 0; i < 4; i++) {
        self->field_0x591[i] = 0xff;
    }
    self->field_0x584 = 0;
    self->field_0x585 = -1;
    self->field_0x586 = 0;
    self->field_0x5a1 = -1;
    self->field_0x5a4 = 0;
    self->field_0x5a8 = 0;
    self->field_0x5ac = 0;
    self->field_0x59c = 0;
    self->field_0x582 = 0;
    self->field_0x583 = 0;
    self->field_0x59d = 0;
    self->field_0x59e = 0;
    self->entryManager = NULL;
    self->field_0x59f = 0;
    self->field_0x5a0 = 0;
    self->field_0x5b0 = 0;
    self->field_0x5b1 = 0;
    self->field_0x5b2 = 1;
    self->field_0x5b3 = 0;
    self->field_0x5b4 = 0;
    _Z19ClearStruct020a9ea4P14Struct020a9ea4((Struct020a9ea4*)self->field_0x5b8);
    self->field_0x598 = 0;
}
