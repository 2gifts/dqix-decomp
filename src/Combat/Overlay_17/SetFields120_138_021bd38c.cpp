#include <globaldefs.h>

#if defined(jpn)
enum { kFirstPointerOffset = 0x11c, kSecondPointerOffset = 0x134 };
#else
enum { kFirstPointerOffset = 0x120, kSecondPointerOffset = 0x138 };
#endif


#if defined(jpn)
#define SetFields120_138_021bd38c func_ov017_021bd984
#endif

// USA: func_ov017_021bd38c
#if defined(jpn)
extern "C"
#endif
ARM void SetFields120_138_021bd38c(void* obj, int a, int b) {
    *(int*)((char*)obj + kFirstPointerOffset) = a;
    *(int*)((char*)obj + kSecondPointerOffset) = b;
}
