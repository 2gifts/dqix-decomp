#include <globaldefs.h>
#if defined(jpn)
#define func_0208b610 func_0208bf04
#endif

struct Vec4_0208b5b4 { int x, y, z, w; };
struct Vec3_0208b5b4 { int x, y, z; };

extern "C" void func_0208b610(struct Vec3_0208b5b4 v, unsigned short p, int a, int b, int c, short d);

// USA: func_0208b5b4
ARM void ForwardCenteredY0208b5b4(struct Vec4_0208b5b4 v, int height, int a5, short a6, unsigned short a7) {
    v.y += ((int)(height + ((unsigned int)height >> 31))) >> 1;   // v.y += height / 2 (toward zero)
    func_0208b610(*(struct Vec3_0208b5b4*)&v, a7, v.w, height, a5, a6);
}
