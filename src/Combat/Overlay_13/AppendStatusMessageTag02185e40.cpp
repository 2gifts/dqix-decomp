#include <globaldefs.h>

#if defined(jpn)
#define func_ov013_02185e40 func_ov013_02186f4c
#define data_ov013_02187e44 data_ov013_02188ddc
#define data_ov013_02187e45 data_ov013_02188ddd
#define data_ov013_02187dac data_ov013_02188cd4
#define LOW_REGION(j,u) (j)
#else
#define LOW_REGION(j,u) (u)
#endif
#include "GameState/GameState.h"

extern "C" void __clear(void* buf, int n);
extern "C" int func_020420e8(void* p, int flag);
extern "C" int sprintf(char* dst, const char* fmt, ...);
#if defined(jpn)
extern "C" void func_02046380(void*);
extern "C" unsigned int strlen(const char*);
extern "C" int func_02042638(char*, const char*, int);
extern char data_ov013_02188d4c[];
#else
extern "C" void func_02046380(void);
#endif

struct Container020e0310;
ARM int GetFieldByKey020e0434(struct Container020e0310* c, int key);
ARM int AppendYTag(char* dst, int y);
ARM int AppendXTag(char* dst, int x);
ARM int AppendWidthTag(char* dst, int w);
ARM int AppendPaletteTag(char* dst, int palette);
ARM int AppendString02042058(char* dst, const char* src);
ARM int CallFunc020e0434With02153694(int value);
ARM int AppendFormatted02041fac(char* buf, int a, int b);
void* GetGlobalField0x1c020421a0(void);

struct StoreStruct;
ARM void SetByteAtIndex(unsigned char* base, int index, unsigned char value);
ARM void SetByteInRange(unsigned char* base, int index, unsigned char value);
ARM void StoreInArray0x8b0(struct StoreStruct* base, int index, int value);

extern char data_ov013_02187e3c;
extern char data_ov013_02187e3f;
extern char data_ov013_02187e44;
extern char data_ov013_02187e45;
extern short data_ov013_02187dac[];

// USA: func_ov013_02185e40  (semantic: AppendStatusMessageTag02185e40)
extern "C" ARM void func_ov013_02185e40(void* self, char* dst) {
    unsigned char* obj = (unsigned char*)self;
    if (dst == 0) return;

    GameState::GetInstance();

    short keyA = 0x190;
    short keyB = 0x1f4;
#if defined(jpn)
    int length = strlen(*(const char**)(obj + 0x62c)) + 6;
    int marker;
    int spacing;
    int palette;
    int state = *(int*)(obj + 0x640);
    marker = 0;
    spacing = 2;
    if (obj[0x63c] != 0) {
        spacing = 0;
        length++;
        marker = 1;
    }
    palette = 5;
    if (state == 0xa) palette = 0xd;
    int x = 0x31 - (int)(((float)length / 4.0f) * 10.0f);
    int stateText = GetFieldByKey020e0434((Container020e0310*)(obj + 0x5ac), (short)(state + 0x12c));
    int kindText = GetFieldByKey020e0434((Container020e0310*)(obj + 0x5ac), (short)(obj[0x630] + 0xc8));
    sprintf(dst, data_ov013_02188d4c, x, *(const char**)(obj + 0x62c), kindText, marker, palette, stateText, spacing, *(int*)(obj + 0x638));
#else
    char buf13c[0x200];
    __clear(buf13c, 0x200);

    int nameWidth = func_020420e8(*(void**)(obj + 0x6a4), 0);
    if (*(int*)(obj + 0x6b8) != 0) {
        int key = (short)(*(int*)(obj + 0x6b8) + 0x12c);
        int r7 = GetFieldByKey020e0434((struct Container020e0310*)(obj + LOW_REGION(0x5ac,0x620)), key);
        int paletteId = 5;
        if (*(int*)(obj + 0x6b8) == 0xa) paletteId = 0xd;

        AppendYTag(buf13c, 4);
        AppendString02042058(buf13c, *(const char**)(obj + 0x6a4));
        AppendWidthTag(buf13c, 0x10);
        AppendPaletteTag(buf13c, paletteId);
        AppendString02042058(buf13c, (const char*)r7);
        AppendWidthTag(buf13c, 4);
        AppendPaletteTag(buf13c, 0xf);
        int v = CallFunc020e0434With02153694(0x3f3);
        AppendString02042058(buf13c, (const char*)v);

        char buf2c[0x10];
        __clear(buf2c, 0x10);
        sprintf(buf2c, &data_ov013_02187e3c, *(int*)(obj + 0x6b0));
        AppendString02042058(buf13c, buf2c);
    } else {
        AppendYTag(buf13c, 4);
        AppendString02042058(buf13c, *(const char**)(obj + 0x6a4));
        AppendWidthTag(buf13c, 0x12);
        int v = CallFunc020e0434With02153694(0x3f3);
        AppendString02042058(buf13c, (const char*)v);

        char buf1c[0x10];
        __clear(buf1c, 0x10);
        sprintf(buf1c, &data_ov013_02187e3c, *(int*)(obj + 0x6b0));
        AppendString02042058(buf13c, buf1c);
    }

    char buf3c[0x100];
    __clear(buf3c, 0x100);
    int v2 = CallFunc020e0434With02153694(0x3f3);
    sprintf(buf3c, &data_ov013_02187e3f, v2, *(int*)(obj + 0x6b0));
    int w = func_020420e8(buf3c, 0);

    int r1 = nameWidth + 0x12 + w;
    if (*(int*)(obj + 0x6b8) != 0) r1 += 9;
    r1 = 0x78 - r1;

    *(short*)(obj + 0x1e) = (short)(nameWidth + (r1 >> 1) + 1);
    AppendXTag(dst, r1 >> 1);

    AppendString02042058(dst, buf13c);
#endif
#if defined(jpn)
    func_02042638(dst, &data_ov013_02187e44, 0x10);
#else
    AppendFormatted02041fac(dst, (int)&data_ov013_02187e44, 0x10);
#endif

    void* g = GetGlobalField0x1c020421a0();
#if defined(jpn)
    func_02046380(g);
#else
    func_02046380();
#endif

    struct StatusCounters02185e40 {
        char pad[LOW_REGION(0x46,0xbe)];
        unsigned short c0, c1, c2, c3, c4, c5, c6;
    };
    int vals[7];
    vals[0] = ((struct StatusCounters02185e40*)(obj + 0x600))->c0;
    vals[1] = ((struct StatusCounters02185e40*)(obj + 0x600))->c1;
    vals[2] = ((struct StatusCounters02185e40*)(obj + 0x600))->c2;
    vals[3] = ((struct StatusCounters02185e40*)(obj + 0x600))->c3;
    vals[4] = ((struct StatusCounters02185e40*)(obj + 0x600))->c4;
    vals[5] = ((struct StatusCounters02185e40*)(obj + 0x600))->c5;
    vals[6] = ((struct StatusCounters02185e40*)(obj + 0x600))->c6;

    for (int i = 0; i < 7; i++) {
        SetByteAtIndex((unsigned char*)g, i, 1);
        SetByteInRange((unsigned char*)g, i, 3);
        StoreInArray0x8b0((struct StoreStruct*)g, i, vals[i]);
    }

    for (int i = 0; i < 5; i++) {
        int fieldA = GetFieldByKey020e0434((struct Container020e0310*)(obj + LOW_REGION(0x5ac,0x620)), keyA++);
        AppendString02042058(dst, (const char*)fieldA);

        short xtag = data_ov013_02187dac[i];
        AppendXTag(dst, xtag);

        int fieldB = GetFieldByKey020e0434((struct Container020e0310*)(obj + LOW_REGION(0x5ac,0x620)), keyB++);
        AppendString02042058(dst, (const char*)fieldB);

        if (i != 4) {
            AppendString02042058(dst, &data_ov013_02187e45);
        }
    }
}
