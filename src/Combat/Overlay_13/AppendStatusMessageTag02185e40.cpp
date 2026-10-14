#include <globaldefs.h>

#if defined(jpn)
#define func_ov013_02185e40 func_ov013_02186f4c
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

struct SkillPointMenu {
    char unknown0[0x1e];
    short nameEndX;
#if defined(jpn)
    char unknown20[0x5ac - 0x20];
#else
    char unknown20[0x620 - 0x20];
#endif
    char texts[0x18];
#if defined(jpn)
    char unknownAfterTexts[0x62c - 0x5c4];
#else
    char unknownAfterTexts[0x6a4 - 0x638];
#endif
    const char* name;
    unsigned char vocation;
    unsigned char skillIds[5];
    char unknownAfterSkillIds[2];
    int level;
    unsigned char hasVocationMarker;
    char unknownAfterMarker[3];
    int vocationMarker;
    unsigned char flags;
    unsigned char unknownAfterFlags;
    unsigned short currentHP;
    unsigned short maxHP;
    unsigned short currentMP;
    unsigned short maxMP;
    unsigned short attack;
    unsigned short defence;
    unsigned short agility;
};

struct Container020e0310;
ARM int GetFieldByKey020e0434(struct Container020e0310* c, int key);
ARM int AppendYTag_02041a5c(char* dst, int y);
ARM int AppendXTag_02041a28(char* dst, int x);
ARM int AppendWidthTag_02041acc(char* dst, int levelWidth);
ARM int AppendPaletteTag_02041e70(char* dst, int palette);
ARM int AppendString02042058(char* dst, const char* src);
ARM int CallFunc020e0434With02153694_020e51cc(int value);
ARM int AppendFormatted02041fac(char* buf, int a, int b);
void* GetGlobalField0x1c020421a0(void);

struct StoreStruct;
ARM void SetByteAtIndex_020465d8(unsigned char* base, int index, unsigned char value);
ARM void SetByteInRange_020465f0(unsigned char* base, int index, unsigned char value);
ARM void StoreInArray0x8b0_020465c0(struct StoreStruct* base, int index, int value);

extern char data_ov013_02187e3c;
extern char data_ov013_02187e3f;
extern char data_ov013_02187e44;
extern char data_ov013_02187e45;
extern short data_ov013_02187dac[];

// USA: func_ov013_02185e40  (semantic: AppendStatusMessageTag02185e40)
extern "C" ARM void func_ov013_02185e40(SkillPointMenu* menu, char* dst) {
    if (dst == 0) return;

    GameState::GetInstance();

    short labelKey = 0x190;
    short valueKey = 0x1f4;
#if defined(jpn)
    int headingByteLength = strlen(menu->name) + 6;
    int marker;
    int markerSpacing;
    int palette;
    int markerIndex = menu->vocationMarker;
    marker = 0;
    markerSpacing = 2;
    if (menu->hasVocationMarker != 0) {
        markerSpacing = 0;
        headingByteLength++;
        marker = 1;
    }
    palette = 5;
    if (markerIndex == 0xa) palette = 0xd;
    int x = 0x31 - (int)(((float)headingByteLength / 4.0f) * 10.0f);
    int vocationMarkerText = GetFieldByKey020e0434((Container020e0310*)menu->texts, (short)(markerIndex + 0x12c));
    int vocationText = GetFieldByKey020e0434((Container020e0310*)menu->texts, (short)(menu->vocation + 0xc8));
    sprintf(dst, data_ov013_02188d4c, x, menu->name, vocationText, marker, palette, vocationMarkerText, markerSpacing, menu->level);
#else
    char heading[0x200];
    __clear(heading, 0x200);

    int nameWidth = func_020420e8((void*)menu->name, 0);
    if (menu->vocationMarker != 0) {
        int key = (short)(menu->vocationMarker + 0x12c);
        int vocationMarkerText = GetFieldByKey020e0434((Container020e0310*)menu->texts, key);
        int paletteId = 5;
        if (menu->vocationMarker == 0xa) paletteId = 0xd;

        AppendYTag_02041a5c(heading, 4);
        AppendString02042058(heading, menu->name);
        AppendWidthTag_02041acc(heading, 0x10);
        AppendPaletteTag_02041e70(heading, paletteId);
        AppendString02042058(heading, (const char*)vocationMarkerText);
        AppendWidthTag_02041acc(heading, 4);
        AppendPaletteTag_02041e70(heading, 0xf);
        int v = CallFunc020e0434With02153694_020e51cc(0x3f3);
        AppendString02042058(heading, (const char*)v);

        char levelText[0x10];
        __clear(levelText, 0x10);
        sprintf(levelText, &data_ov013_02187e3c, menu->level);
        AppendString02042058(heading, levelText);
    } else {
        AppendYTag_02041a5c(heading, 4);
        AppendString02042058(heading, menu->name);
        AppendWidthTag_02041acc(heading, 0x12);
        int v = CallFunc020e0434With02153694_020e51cc(0x3f3);
        AppendString02042058(heading, (const char*)v);

        char levelText[0x10];
        __clear(levelText, 0x10);
        sprintf(levelText, &data_ov013_02187e3c, menu->level);
        AppendString02042058(heading, levelText);
    }

    char levelLabel[0x100];
    __clear(levelLabel, 0x100);
    int v2 = CallFunc020e0434With02153694_020e51cc(0x3f3);
    sprintf(levelLabel, &data_ov013_02187e3f, v2, menu->level);
    int levelWidth = func_020420e8(levelLabel, 0);

    int headingSpace = nameWidth + 0x12 + levelWidth;
    if (menu->vocationMarker != 0) headingSpace += 9;
    headingSpace = 0x78 - headingSpace;

    menu->nameEndX = (short)(nameWidth + (headingSpace >> 1) + 1);
    AppendXTag_02041a28(dst, headingSpace >> 1);

    AppendString02042058(dst, heading);
#endif
#if defined(jpn)
    func_02042638(dst, &data_ov013_02187e44, 0x10);
#else
    AppendFormatted02041fac(dst, (int)&data_ov013_02187e44, 0x10);
#endif

    void* textVariables = GetGlobalField0x1c020421a0();
#if defined(jpn)
    func_02046380(textVariables);
#else
    func_02046380();
#endif

    int stats[7] = {
        menu->currentHP, menu->maxHP, menu->currentMP, menu->maxMP,
        menu->attack, menu->defence, menu->agility
    };

    for (int i = 0; i < 7; i++) {
        SetByteAtIndex_020465d8((unsigned char*)textVariables, i, 1);
        SetByteInRange_020465f0((unsigned char*)textVariables, i, 3);
        StoreInArray0x8b0_020465c0((struct StoreStruct*)textVariables, i, stats[i]);
    }

    for (int i = 0; i < 5; i++) {
        int fieldA = GetFieldByKey020e0434((Container020e0310*)menu->texts, labelKey++);
        AppendString02042058(dst, (const char*)fieldA);

        short xtag = data_ov013_02187dac[i];
        AppendXTag_02041a28(dst, xtag);

        int fieldB = GetFieldByKey020e0434((Container020e0310*)menu->texts, valueKey++);
        AppendString02042058(dst, (const char*)fieldB);

        if (i != 4) {
            AppendString02042058(dst, &data_ov013_02187e45);
        }
    }
}
