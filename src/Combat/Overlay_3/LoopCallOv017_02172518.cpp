#include <globaldefs.h>

#if defined(jpn)
#define LoopCallOv017_02172518 func_ov003_021714f0
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

extern "C" void func_ov017_021d0ef8(int a, void* b, int c, int d, int* out);

struct Obj_02172518 {
    char pad0[0x199];
    unsigned char f199;
};

// USA: func_ov003_02172518
#if defined(jpn)
extern "C"
#endif
ARM void LoopCallOv017_02172518(struct Obj_02172518* obj, int flag) {
    unsigned int accum = 0;
    char* base = LOW_REGION((char*)obj + 0x19c, (flag != 0) ? (char*)obj + 0x1c0 : (char*)obj + 0x380);
    int outVal;

    while (accum < 0xe0) {
        func_ov017_021d0ef8(obj->f199, base, 0xe0, accum, &outVal);
        accum += outVal;
    }
}
