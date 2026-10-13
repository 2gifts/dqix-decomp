#include <globaldefs.h>

#if defined(jpn)
#include "GameState/GameState.h"

struct FontBankLoader {
    char unknown0[0x14];
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
    unsigned char useBaseArchive;
};

enum FontBankId {
    VariantFontBank = 1000,
    LocationFontBank = 5000
};

extern "C" int func_020952f4(char* locationSuffix);
extern "C" int func_02001aec(const void*, const void*, unsigned int);
int GetField5cb0Value(char* gameState);
extern "C" void func_02094ab0(FontBankLoader* loader);

// USA: func_02094b30

extern "C" ARM void _Z21BlankFunction02094b30v(FontBankLoader* loader, int fontBankId, int useBaseArchive) {
    if (fontBankId < 0 || loader->requestedBank >= 0 || loader->primaryBank == fontBankId) return;
    if (loader->supplementalBank == fontBankId) {
        int unchanged = 1;
        char locationSuffix[8] = {};
        switch (loader->supplementalBank) {
        case LocationFontBank:
            if (func_02001aec(locationSuffix, loader->cachedLocationSuffix, func_020952f4(locationSuffix)) != 0) {
                unchanged = 0;
            }
            break;
        case VariantFontBank: {
            int fontVariant = GetField5cb0Value((char*)GameState::GetInstance());
            fontVariant &= 0xff;
            if (fontVariant != loader->cachedFontVariant) {
                unchanged = 0;
            }
            break;
        }
        }
        if (unchanged) return;
    }
    func_02094ab0(loader);
    loader->requestedBank = fontBankId;
    loader->dispatchStage = 0;
    loader->loadStage = 0;
    loader->useBaseArchive = useBaseArchive;
}
#else
// USA: func_02094b30
ARM void BlankFunction02094b30(void) {
}
#endif
