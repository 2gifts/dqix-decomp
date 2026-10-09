#include <globaldefs.h>

#include "Resource/UiArrayEntry.h"

// USA: func_ov031_022276b4
ARM int LookupArrayPlusBase_022276b4(struct ArrBasePair022276b4* p, unsigned int idx) {
    unsigned short i = (unsigned short)idx;
    return p->base + p->arr[i];
}
