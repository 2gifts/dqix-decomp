#include <globaldefs.h>

#if defined(jpn)
#endif

extern "C" void func_0203ac40(void* obj, int x, int y, int z);

// USA: func_0203aa08
ARM void ResetXYField0203aa08(void* obj) {
    short x;
    if (*(void**)obj == NULL) return;
    x = *(short*)((char*)obj + 0xac);
    if (x < 0) return;
    func_0203ac40(obj, x, *(short*)((char*)obj + 0xae), 0);
    *(short*)((char*)obj + 0xac) = -1;
    *(short*)((char*)obj + 0xae) = -1;
}
