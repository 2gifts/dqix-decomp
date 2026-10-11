#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* func_ov001_02159f94(int a);

// USA: func_ov001_0215a550
ARM void InitEntryFromArgs_0215a550(int a, char* name, int b, int c) {
    void* node = func_ov001_02159f94(a);
    if (node == NULL) return;
    *(int*)node = 10;
    strcpy((char*)node + 0x1c, name);
    *(int*)((char*)node + 0x10) = b;
    *(int*)((char*)node + 0x14) = c;
    *(int*)((char*)node + 0x18) = 0;
}
