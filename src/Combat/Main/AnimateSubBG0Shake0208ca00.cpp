#include <globaldefs.h>

extern "C" double func_02009424(double v);

struct ShakeState0208ca00 {
    char pad0[0xc8];
    float angle;
    char pad1[0xd7 - 0xcc];
    unsigned char counter;
    char pad2[0xda - 0xd8];
    unsigned short flags;
};

// USA: func_0208ca00
ARM int AnimateSubBG0Shake0208ca00(struct ShakeState0208ca00* obj, int delta) {
    unsigned short flags = obj->flags;
    if (!(flags & 0x80)) goto ret_zero;
    if (obj->counter > 10) {
        obj->flags = flags & ~0x80;
        *(volatile int*)0x4001010 = 0;
        obj->counter = 0;
        goto ret_zero;
    }
    {
        float speed = 5.0f - 0.3f * (float)(unsigned int)obj->counter;
        obj->angle = obj->angle + 1.8f * (float)delta;
        obj->counter = obj->counter + delta;
        if (3.14f < obj->angle) {
            obj->angle = obj->angle - 6.28f;
        }
        int val = (int)(speed * (float)func_02009424((double)(obj->angle)));
        *(volatile int*)0x4001010 = val & 0x1ff;
        return val;
    }
ret_zero:
    return 0;
}
