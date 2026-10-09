#include <globaldefs.h>

#include "Resource/UiArrayEntry.h"

// USA: func_ov031_022276cc
extern "C" ARM int func_ov031_022276cc(void *receiver, int a0, int a1, int a2) {
    ArrBasePair022276b4 *table = static_cast<ArrBasePair022276b4 *>(receiver);
    int entry                  = table->base + table->arr[static_cast<unsigned short>(a0)];

    if (a1 >= 0) {
        reinterpret_cast<unsigned short *>(entry)[a1] = static_cast<unsigned short>(static_cast<unsigned int>(a2) + 0x30);
    }
    return entry;
}
