#include <globaldefs.h>

struct Tween020c0260 { int f0; int f4; int f8; int fc; };
void RetargetTween020c0204(struct Tween020c0260* t, int end, int duration);
extern "C" void func_020bf1a0(void* obj);

// USA: func_020bf148
ARM void RetargetTweenIfFlag2Enabled_020bf148(void* obj, int arg1) {
    char* p = (char*)obj;
    if (((*(int*)(p + 0x110) << 30) >> 31) == 0) { func_020bf1a0(obj); return; }
    if (arg1 == 0) { func_020bf1a0(obj); return; }
    RetargetTween020c0204((struct Tween020c0260*)(p + 0xe8), 0, arg1);
    *(int*)(p + 0x110) |= 0x8;
    *(int*)(p + 0x150) = 0;
}
