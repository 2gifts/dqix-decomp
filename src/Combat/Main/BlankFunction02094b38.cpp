#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

#if defined(jpn)
extern "C" void* memset(void*, int, unsigned int);
#endif

// USA: func_02094b38
ARM void BlankFunction02094b38(FontBankLoader* loader, int fontBankId) {
#if defined(jpn)
    if (fontBankId < 0) return;
    if (loader->primaryBank == fontBankId) {
        loader->primaryBank = -1;
        loader->primaryValue = 0;
        loader->primaryLoaded = 0;
        return;
    }
    if (loader->supplementalBank == fontBankId) {
        loader->supplementalBank = -1;
        loader->supplementalValue = 0;
        if (fontBankId == 1000) memset(loader->customFontName, 0, sizeof(loader->customFontName));
        if (fontBankId == 5000) memset(loader->cachedLocationSuffix, 0, sizeof(loader->cachedLocationSuffix));
        loader->supplementalLoaded = 0;
    }
#endif
}
