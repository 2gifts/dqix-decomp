#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

// USA: func_02094b3c
ARM void BlankFunction02094b3c(FontBankLoader* loader, int event) {
#if defined(jpn)
    switch (event) {
    case 8:
        BlankFunction02094b38(loader, loader->supplementalBank);
        break;
    case 10:
        BlankFunction02094b38(loader, loader->primaryBank);
        break;
    case 12:
        BlankFunction02094b38(loader, loader->supplementalBank);
        break;
    }
#endif
}
