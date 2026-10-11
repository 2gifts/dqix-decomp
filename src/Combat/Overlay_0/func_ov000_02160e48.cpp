#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "System/OverlayId.h"

extern int data_ov000_02184220;
extern "C" void _Z28StoreByteAtCountTail020a1fd4h(unsigned char value);

#if defined(jpn)
enum { stateOffset = 0xe24, loadTaskOffset = 0x7920 };
#else
enum { stateOffset = 0xea8, loadTaskOffset = 0x7730 };
#endif

// USA: func_ov000_02160e48
// JPN: func_ov000_021625b0
extern "C" ARM void func_ov000_02160e48(void* obj) {
    *(int*)((char*)obj + stateOffset) = 0x13;
    *(int*)((char*)obj + stateOffset + 4) = 0;
    data_ov000_02184220 = 1;
    *(short*)((char*)obj + loadTaskOffset) = BackgroundLoader::GetInstance()->QueueLoadOverlay(OVERLAY_ID(25));
    _Z28StoreByteAtCountTail020a1fd4h(4);
}
