#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

#if defined(jpn)
extern "C" int _Z21StringLength_020d2ff0PKc(const char*);
extern "C" int func_02001aec(const void*, const void*, unsigned int);
extern "C" void* memset(void*, int, unsigned int);
extern "C" int sprintf(char*, const char*, ...);
#endif

// USA: func_02094b2c
ARM void BlankFunction02094b2c(FontBankLoader* loader, int index, const char* text, unsigned char primaryMode,
                               unsigned char supplementalMode) {
#if defined(jpn)
    if (loader->requestedBank >= 0) return;
    if (!text) return;
    int length = _Z21StringLength_020d2ff0PKc(text);
    if (!length) return;
    if (length >= 16) return;
    if (loader->supplementalBank == 1000) {
        int currentLength = _Z21StringLength_020d2ff0PKc(loader->customFontName);
        if (currentLength == length && func_02001aec(loader->customFontName, text, currentLength) == 0) return;
    }
    memset(loader->customFontName, 0, sizeof(loader->customFontName));
    sprintf(loader->customFontName, text);
    loader->cachedFontVariant = 0;
    func_02094ab0(loader);
    loader->requestedBank = index;
    loader->requestedSupplement = 1000;
    loader->dispatchStage = 0;
    loader->loadStage = 0;
    loader->primaryMode = primaryMode;
    loader->supplementalMode = supplementalMode;
#endif
}
