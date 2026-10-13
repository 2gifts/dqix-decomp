#include <globaldefs.h>
#include "System/Graphics.h"

// USA: func_ov023_021ec3f4  (semantic: Trans_021ec3f4)
extern "C" ARM void func_ov023_021ec3f4(int screenSize, int colorMode, int screenBase, int charBase) {
    BG3CNT = (unsigned short)((BG3CNT & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2));
}
