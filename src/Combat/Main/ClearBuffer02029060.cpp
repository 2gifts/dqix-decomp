#include <globaldefs.h>
#include "Graphics/GlyphBitmapContext.h"
#include "std_library_functions.h"


#if defined(jpn)
#define ClearBuffer02029060 func_020288b0
extern "C" ARM void func_020288b0();
#endif

// USA: func_02029060
ARM void ClearBuffer02029060() {
    if (glyphBitmapContext.buffer == NULL) return;
    memset(glyphBitmapContext.buffer, 0, 256 * 192 / 2);
}
