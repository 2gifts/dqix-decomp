#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "System/OverlayId.h"

#if defined(jpn)
#define func_ov000_02160da0 func_ov000_02162508
#endif

extern int data_ov000_02184220;

// USA: func_ov000_02160da0
extern "C" ARM void func_ov000_02160da0(void* obj) {
#if defined(jpn)
    *(int*)((char*)obj + 0xe24) = 0x12;
    *(int*)((char*)obj + 0xe28) = 0;
#else
    *(int*)((char*)obj + 0xea8) = 0x12;
    *(int*)((char*)obj + 0xeac) = 0;
#endif
    data_ov000_02184220 = 1;
#if defined(jpn)
    *(short*)((char*)obj + 0x7900 + 0x20) = BackgroundLoader::GetInstance()->QueueLoadOverlay(OVERLAY_ID(24));
#else
    *(short*)((char*)obj + 0x7700 + 0x30) = BackgroundLoader::GetInstance()->QueueLoadOverlay(OVERLAY_ID(24));
#endif
}
