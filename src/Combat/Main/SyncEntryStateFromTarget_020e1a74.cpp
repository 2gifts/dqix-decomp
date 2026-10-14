#include <globaldefs.h>

struct Entry020e2cc4;
ARM void SetEntryEnabled020e2cc4(struct Entry020e2cc4*, int);

struct Desc020e13dc;
ARM void Dispatch020e13dc(struct Desc020e13dc*);

ARM void SetByteAt0x1_020e2d4c(unsigned char*, unsigned char);

struct Rect020e2d2c;
ARM void SetRectFromPosAndSize(struct Rect020e2d2c*, int, int, int, int);

struct Entry020e2c34;
ARM void UpdateAndDrawEntry020e2c34(struct Entry020e2c34*);

struct Target020e1a74 {
    unsigned char pad[0x38];
    unsigned char b38;
    unsigned char b39;
    unsigned char b3a;
    unsigned char b3b;
    unsigned char pad3c[2];
    unsigned char b3e;
    union {
        unsigned char b3f;
        struct {
            unsigned char bit0 : 1;
            unsigned char bit1 : 1;
        };
    };
};

struct Self020e1a74 {
    char pad0[4];
    struct Target020e1a74* target;
};

// USA: func_020e1a74  (semantic: SyncEntryStateFromTarget_020e1a74)
extern "C" ARM void func_020e1a74(struct Self020e1a74* self) {
    if (self->target == 0) return;
    if (self->target->bit1) {
        SetEntryEnabled020e2cc4((struct Entry020e2cc4*)((char*)self + 0x28), 0);
        Dispatch020e13dc((struct Desc020e13dc*)((char*)self->target + 0xc));
        self->target->b3f &= ~2;
    }
    if (self->target->bit0) {
        SetByteAt0x1_020e2d4c((unsigned char*)((char*)self + 0x28), self->target->b3e);
        int a = self->target->b38 + 2;
        int b = self->target->b39 + 2;
        int c = self->target->b3a - 4;
        int d = self->target->b3b - 4;
        SetRectFromPosAndSize((struct Rect020e2d2c*)((char*)self + 0x28), a, b, c, d);
        UpdateAndDrawEntry020e2c34((struct Entry020e2c34*)((char*)self + 0x28));
    }
}
