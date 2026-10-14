#include <globaldefs.h>
#include "Graphics/NSBXX/RenderConfig.h"

struct Vec3_0208b5b4 { int x, y, z; };

extern "C" void _Z24ForwardCenteredY0208b5b413Vec4_0208b5b4iist(struct Vec3_0208b5b4 pos, struct Vec3_0208b5b4 size, short a3, unsigned short a4);
extern "C" void _ZN8Object3D4DrawEb(void* p);

// USA: func_ov015_0218ecd8
extern "C" ARM void func_ov015_0218ecd8(void* obj) {
    if (*(void**)((char*)obj + 0x10) != 0 && *(unsigned char*)((char*)*(void**)obj + 0x19e) != 0) {
        struct Vec3_0208b5b4 pos = *(struct Vec3_0208b5b4*)((char*)*(void**)((char*)obj + 0x24) + 0x44);
        struct Vec3_0208b5b4 size;
        size.x = *(short*)((char*)*(void**)((char*)obj + 0x10) + 0xc) * 4;
        size.y = *(short*)((char*)*(void**)((char*)obj + 0x10) + 0xe);
        size.z = size.x;
        RenderConfig::SubmitToFifo();
        _Z24ForwardCenteredY0208b5b413Vec4_0208b5b4iist(pos, size, 0, 0x7fff);
    }
    *(volatile unsigned int*)0x04000444 = 0;
    _ZN8Object3D4DrawEb(*(void**)((char*)obj + 0x24));
    RenderConfig::SubmitToFifo();
    *(volatile unsigned int*)0x04000448 = 1;
    *(unsigned short*)((char*)obj + 0x34) = *(unsigned short*)((char*)obj + 0x36) = 0;
    void* p1 = *(void**)((char*)obj + 0x24);
    p1 = *(void**)((char*)p1 + 8);
    p1 = *(void**)((char*)p1 + 0x54);
    *(unsigned short*)((char*)obj + 0x34) = *(unsigned short*)((char*)p1 + 0x28);
    void* p2 = *(void**)((char*)obj + 0x24);
    p2 = *(void**)((char*)p2 + 8);
    p2 = *(void**)((char*)p2 + 0x54);
    *(unsigned short*)((char*)obj + 0x36) = *(unsigned short*)((char*)p2 + 0x2a);
}
