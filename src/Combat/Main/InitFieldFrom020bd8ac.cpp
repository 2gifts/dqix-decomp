#include <globaldefs.h>
#include "System/Memory.h"

void* GetListEntryWord8020bd8ac(unsigned int);

// USA: func_020c0110
ARM int InitFieldFrom020bd8ac_020c0110(char* obj, void* arg) {
    void* p = GetListEntryWord8020bd8ac((unsigned int)arg);
    *(void**)(obj + 0xa4) = p;
    VectorizedInvertedMemcpy(p, obj + 0xa8, 0x40);
    return 1;
}
