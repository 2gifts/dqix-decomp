#include <globaldefs.h>
#if defined(jpn)
#define func_02050100 func_020515ec
#endif

struct Canvas0204e998;
void FillIndexBuffer0204e998(struct Canvas0204e998* s);
extern "C" void func_02050100(void* obj, int flag);

// USA: func_0204c87c  (semantic: UpdateCanvasState0204c87c)
extern "C" ARM void func_0204c87c(unsigned char* self) {
    if (!(self[0xc5] & 1)) return;
    int state = *(int*)(self + 0x9c);
    switch (state) {
        case 0:
        case 3:
        default:
            break;
        case 1:
            *(short*)(self + 0xc0) = *(short*)(self + 0xaa);
            *(int*)(self + 0x9c) = *(int*)(self + 0x9c) + 1;
            FillIndexBuffer0204e998((struct Canvas0204e998*)self);
            break;
        case 2:
            FillIndexBuffer0204e998((struct Canvas0204e998*)self);
            break;
        case 4:
            *(int*)(self + 0x9c) = 3;
            break;
    }
    func_02050100(self, 1);
}
