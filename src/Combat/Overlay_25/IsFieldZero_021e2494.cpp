#include <globaldefs.h>

// USA: func_ov025_021e2494
#if defined(jpn)
extern "C" ARM int func_ov000_021717e4(void* obj)
#else
ARM int IsFieldZero_021e2494(void* obj)
#endif
{
    return *(int*)obj == 0;
}
