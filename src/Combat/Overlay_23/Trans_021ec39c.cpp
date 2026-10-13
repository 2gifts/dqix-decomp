#include <globaldefs.h>

// USA: func_ov023_021ec39c  (semantic: Trans_021ec39c)
extern "C" ARM void func_ov023_021ec39c(int screenSize, int colorMode, int screenBase, int charBase) {
    *(volatile unsigned short*)0x400100c = (unsigned short)((*(volatile unsigned short*)0x400100c & 0x43) |
        (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2));
}
