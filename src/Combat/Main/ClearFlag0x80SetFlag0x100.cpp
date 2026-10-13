#include <globaldefs.h>

#if defined(jpn)
enum { FLAGS_OFFSET = 0x180 };
#else
enum { FLAGS_OFFSET = 0x18c };
#endif

// USA: func_02054234
ARM void ClearFlag0x80SetFlag0x100(void* obj) {
    unsigned int* flags = (unsigned int*)((char*)obj + FLAGS_OFFSET);
    *flags = (*flags & ~0x80) | 0x100;
}
