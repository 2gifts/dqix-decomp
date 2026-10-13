#include <globaldefs.h>
#include "Graphics/GlyphBitmapContext.h"


#if defined(jpn)
#define SetField402028d58 func_020285a8
extern "C" ARM void func_020285a8(int value);
#endif

// USA: func_02028d58
ARM void SetField402028d58(int value) {
    glyphBitmapContext.colorSchemeIndex = value;
}
