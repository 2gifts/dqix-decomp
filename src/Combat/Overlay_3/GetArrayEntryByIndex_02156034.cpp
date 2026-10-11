#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

// USA: func_ov003_02156034
ARM void* GetArrayEntryByIndex_02156034(void* obj) {
    short val = *(short*)((char*)obj + R(0x1e0,0x1e4));
    void** arr = *(void***)((char*)obj + 0x20);
    short idx = (short)(val - 0x13);
    return arr[idx];
}
