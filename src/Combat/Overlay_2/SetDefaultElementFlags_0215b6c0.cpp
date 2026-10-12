#if defined(jpn)
#define func_ov002_0215b9a4 func_ov002_0215cb1c
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

#if defined(jpn)
#define func_ov002_0215b6c0 func_ov002_0215c914
#endif

extern "C" void func_ov002_0215b9a4(unsigned char* obj, int key, int flag);

// USA: func_ov002_0215b6c0  (semantic: SetDefaultElementFlags_0215b6c0)
extern "C" ARM void func_ov002_0215b6c0(unsigned char* obj) {
    *(int*)(obj + LOW_REGION(0x1a94, 0x1bcc)) = 1;
    func_ov002_0215b9a4(obj, LOW_REGION(0x11, 0x10), 1);
    func_ov002_0215b9a4(obj, LOW_REGION(0x14, 0x13), 0);
    func_ov002_0215b9a4(obj, LOW_REGION(8, 7), 1);
    func_ov002_0215b9a4(obj, LOW_REGION(9, 8), 0);
    func_ov002_0215b9a4(obj, 4, 1);
}
