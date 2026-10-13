#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

#if defined(jpn)
extern "C" void* memset(void*, int, unsigned int);
#endif

// USA: func_02094b40
ARM void BlankFunction02094b40(FontBankLoader* loader) {
#if defined(jpn)
    loader->primaryBank = -1;
    loader->primaryValue = 0;
    loader->primaryLoaded = 0;
    loader->supplementalBank = -1;
    loader->supplementalValue = 0;
    loader->supplementalLoaded = 0;
    memset(loader->customFontName, 0, sizeof(loader->customFontName));
#endif
}
