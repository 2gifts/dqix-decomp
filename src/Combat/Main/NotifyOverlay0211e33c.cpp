#include <globaldefs.h>
#include "Filesystem/Overlay_33/Ov33BackgroundLoader.h"
#include "System/OverlayId.h"

extern "C" void func_020a1940(unsigned int id);
extern char data_0211e33c;

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
#if defined(jpn)
#define NotifyOverlay0211e33c_020d6c0c func_020d8614
extern "C" ARM void NotifyOverlay0211e33c_020d6c0c(void);
#endif

// USA: func_020d6c0c
ARM void NotifyOverlay0211e33c_020d6c0c() {
    func_020a1940(OVERLAY_ID(34));
    PopulateOv33BackgroundLoader(&data_0211e33c, 0x30000, 0x14);
}
