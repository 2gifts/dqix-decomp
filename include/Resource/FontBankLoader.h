#pragma once

struct FontBankLoader {
    void* primaryTable;
    void* supplementalTable;
    char unknown08[4];
    int primaryValue;
    int supplementalValue;
    int loadTasks[8];
    int requestedBank;
    int requestedSupplement;
    int primaryBank;
    int supplementalBank;
    char customFontName[16];
    unsigned char primaryTaskCount;
    unsigned char supplementalTaskCount;
    unsigned char dispatchStage;
    unsigned char loadStage;
    unsigned char cachedFontVariant;
    char cachedLocationSuffix[8];
    unsigned char primaryMode;
    unsigned char supplementalMode;
    unsigned char primaryLoaded;
    unsigned char supplementalLoaded;
};

FontBankLoader* GetGlobal02109400_02094a00(void);
extern "C" void func_02094ab0(FontBankLoader* loader);
void BlankFunction02094b2c(FontBankLoader* loader, int index, const char* text, unsigned char primaryMode,
                           unsigned char supplementalMode);
void BlankFunction02094b30(FontBankLoader* loader, int fontBankId, int useBaseArchive);
void BlankFunction02094b34(FontBankLoader* loader, int first, int second, unsigned char primaryMode,
                           unsigned char supplementalMode);
void BlankFunction02094b38(FontBankLoader* loader, int fontBankId);
void BlankFunction02094b3c(FontBankLoader* loader, int event);
void BlankFunction02094b40(FontBankLoader* loader);
void* AlwaysFalse02094b44(FontBankLoader* loader, int event);
int AlwaysTrue02094b4c(FontBankLoader* loader);
