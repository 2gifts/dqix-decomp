#include <globaldefs.h>

#if defined(jpn)
enum { FLAGS_OFFSET = 0x180 };
#else
enum { FLAGS_OFFSET = 0x18c };
#endif

#if defined(jpn)
#define SetFlags0x180At0x18c func_0205559c
extern "C" ARM void func_0205559c(void* obj);
#endif

// USA: func_02054224
ARM void SetFlags0x180At0x18c(void* obj) {
    unsigned int* flags = (unsigned int*)((char*)obj + FLAGS_OFFSET);
    *flags |= 0x180;
}
