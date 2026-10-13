#include <globaldefs.h>
#include "System/Graphics.h"

// USA: func_ov023_021ec454  (semantic: Trans_021ec454)
extern "C" ARM void func_ov023_021ec454(int scrSize, int colMode, int scrBase, int charBase) {
    BG2CNT = (unsigned short)((BG2CNT & 0x43) | (scrSize << 14) | (colMode << 7) | (scrBase << 8) | (charBase << 2));
}
