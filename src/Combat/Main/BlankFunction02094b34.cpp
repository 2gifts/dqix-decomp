#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

#if defined(jpn)
extern "C" int func_020965c0(FontBankLoader*, int);
#endif

// USA: func_02094b34
ARM void BlankFunction02094b34(FontBankLoader* loader, int first, int second, unsigned char primaryMode,
                               const volatile unsigned char supplementalModeArgument) {
#if defined(jpn)
    if (loader->requestedBank >= 0) return;
    volatile int indices[2];
    indices[1] = second;
    indices[0] = first;
    unsigned char supplementalMode = supplementalModeArgument;
    if (func_020965c0(loader, first)) {
        indices[0] = -1;
        primaryMode = 1;
    }
    if (func_020965c0(loader, indices[1])) {
        indices[1] = -1;
        supplementalMode = 1;
    }
    for (unsigned char i = 0; i < 2; ++i) {
        if (indices[0] < 0) {
            indices[0] = indices[1];
            primaryMode = supplementalMode;
            indices[1] = -1;
            supplementalMode = 1;
        }
    }
    if (indices[0] < 0 && indices[1] < 0) return;
    func_02094ab0(loader);
    loader->requestedBank = indices[0];
    loader->requestedSupplement = indices[1];
    loader->dispatchStage = 0;
    loader->loadStage = 0;
    loader->primaryMode = primaryMode;
    loader->supplementalMode = supplementalMode;
#endif
}
