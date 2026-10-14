#include <globaldefs.h>

int CountEntriesType1WithId_020bc0a4(int);

// USA: func_0209c6bc
ARM int IsHandleB8Active0209c6bc(void* obj) {
    return CountEntriesType1WithId_020bc0a4(*(short*)((char*)obj + 0xb8)) != 0;
}
