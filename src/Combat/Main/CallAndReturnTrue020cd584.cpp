#include <globaldefs.h>

extern "C" void func_020cd494(void);
struct OverlayMetadata;

// USA: func_020cd584
ARM int CallAndReturnTrue020cd584(OverlayMetadata*) {
    func_020cd494();
    return 1;
}
