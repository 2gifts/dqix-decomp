#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;
extern void* data_02108efc;

// USA: func_02089aa0
ARM int SetGlobalShortField18(struct Variant02030b0c* p) {
    *(short*)((char*)data_02108efc + 0x18) = ((Script::Parameter*)p)->ToInt();
    return 1;
}
