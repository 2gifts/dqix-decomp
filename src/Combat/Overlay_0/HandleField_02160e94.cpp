#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x7900
#define REGION_OFFSET_1 0x20
#define REGION_OFFSET_2 0xe24
#define REGION_OFFSET_3 0xe28
#else
#define REGION_OFFSET_0 0x7700
#define REGION_OFFSET_1 0x30
#define REGION_OFFSET_2 0xea8
#define REGION_OFFSET_3 0xeac
#endif

#include "Filesystem/BackgroundLoader.h"

extern int data_ov000_02184220;

// USA: func_ov000_02160e94
ARM void HandleField_02160e94(void* obj) {
    int dataVal = (int)BackgroundLoader::GetInstance();
    if (((BackgroundLoader*)(dataVal))->GetTaskStatus((int)(*(short*)((char*)obj + REGION_OFFSET_0 + REGION_OFFSET_1))) >= 0) {
        return;
    }
    ((BackgroundLoader*)(dataVal))->RemoveTask((int)(*(short*)((char*)obj + REGION_OFFSET_0 + REGION_OFFSET_1)));
    *(short*)((char*)obj + REGION_OFFSET_0 + REGION_OFFSET_1) = -1;
    *(int*)((char*)obj + REGION_OFFSET_2) = 0x8;
    *(int*)((char*)obj + REGION_OFFSET_3) = 0;
    data_ov000_02184220 = 1;
}
