#include <globaldefs.h>
#include <System/Graphics.h>

// USA: func_ov023_021ec3c8  (semantic: Trans_021ec3c8)
extern "C" ARM void func_ov023_021ec3c8(int screenSize, int colorMode, int screenBase, int charBase) {
    BG3CNTSUB = (unsigned short)((BG3CNTSUB & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2));
}
