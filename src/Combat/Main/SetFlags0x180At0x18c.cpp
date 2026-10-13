#include <globaldefs.h>

#if defined(jpn)
enum { FLAGS_OFFSET = 0x180 };
#else
enum { FLAGS_OFFSET = 0x18c };
#endif

// USA: func_02054224
ARM void SetFlags0x180At0x18c(void* obj) {
    unsigned int* flags = (unsigned int*)((char*)obj + FLAGS_OFFSET);
    *flags |= 0x180;
}
