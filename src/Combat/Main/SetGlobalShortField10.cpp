#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;
extern void* data_02108efc;

// USA: func_020899dc
ARM int SetGlobalShortField10_020899dc(struct Variant02030b0c* p) {
    *(short*)((char*)data_02108efc + 0x10) = ((Script::Parameter*)p)->ToInt();
    return 1;
}
