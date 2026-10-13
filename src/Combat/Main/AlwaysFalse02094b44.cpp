#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

// USA: func_02094b44
ARM void* AlwaysFalse02094b44(FontBankLoader* loader, int event) {
    void* table = 0;
#if defined(jpn)
    switch (event) {
    case 8:
        if (loader->supplementalBank >= 0) table = loader->supplementalTable;
        break;
    case 10:
        if (loader->primaryBank >= 0) table = loader->primaryTable;
        break;
    case 12:
        if (loader->supplementalBank >= 0) table = loader->supplementalTable;
        break;
    }
#endif
    return table;
}
