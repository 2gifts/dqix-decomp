#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

#if defined(jpn)
extern "C" void* _Z27GetDataPtr02114e04_020d6c00v(void);
extern "C" int _Z17TestFlags02046708P16FlagWord02046708j(void*, unsigned int);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*, int);

typedef void (FontBankLoader::*FontBankHandler)(void);
extern unsigned int data_02109400;
extern FontBankHandler data_020e6d5c;
extern FontBankHandler data_020f148c[2];
extern FontBankHandler data_020f148c_dup[2];
#endif

// USA: func_02094b4c
ARM int AlwaysTrue02094b4c(FontBankLoader* loader) {
#if defined(jpn)
    if (loader->requestedBank < 0) return 1;
    if (_Z17TestFlags02046708P16FlagWord02046708j(_Z27GetDataPtr02114e04_020d6c00v(), 0x10)) {
        void* backgroundLoader = _ZN16BackgroundLoader11GetInstanceEv();
        for (unsigned char i = 0; i < 8; ++i) {
            if (loader->loadTasks[i] >= 0) {
                _ZN16BackgroundLoader10RemoveTaskEi(backgroundLoader, loader->loadTasks[i]);
                loader->loadTasks[i] = -1;
            }
        }
        loader->dispatchStage = 0;
        loader->loadStage = 0;
        return 0;
    }
    if (!(data_02109400 & 1)) {
        data_020f148c[1] = data_020e6d5c;
        data_02109400 |= 1;
    }
    if (!data_020f148c_dup[loader->dispatchStage]) return 1;
    (loader->*data_020f148c_dup[loader->dispatchStage])();
    return 0;
#else
    return 1;
#endif
}
