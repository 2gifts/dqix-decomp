#include <globaldefs.h>
extern "C" void LoadToSubBGExtendedPalette(int, unsigned int, int);

extern "C" void MemoryMapSubBGExtendedPalette(void);
extern "C" void MemoryUnmapSubBGExtendedPalette(void);

// USA: func_020bbbf4
ARM void RunField0ScopedOperation_020bbbf4(int a, int b, int c) {
    MemoryMapSubBGExtendedPalette();
    LoadToSubBGExtendedPalette((int)(a), (unsigned int)(b), (int)(c));
    MemoryUnmapSubBGExtendedPalette();
}
