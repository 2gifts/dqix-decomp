#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

#if defined(jpn)
#include "GameState/GameState.h"

enum FontBankId {
    VariantFontBank = 1000,
    LocationFontBank = 5000
};

extern "C" int func_020952f4(char* locationSuffix);
extern "C" int func_02001aec(const void*, const void*, unsigned int);
int GetField5cb0Value_0201079c(char* gameState);
#endif

// USA: func_02094b30
ARM void BlankFunction02094b30(FontBankLoader* loader, int fontBankId, int useBaseArchive) {
#if defined(jpn)
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
            int fontVariant = GetField5cb0Value_0201079c((char*)GameState::GetInstance());
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
    loader->primaryMode = useBaseArchive;
#endif
}
