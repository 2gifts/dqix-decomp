#include <globaldefs.h>
#include <System/Matrix.h>
#include <Graphics/NSBXX/RenderConfig.h>

extern "C" void _Z27ClearGlobalFlagBits02016d8cPv(void* rotation);
extern "C" fix32_t _Z8fix32cosi(int x);
extern "C" fix32_t _Z8fix32sini(int x);
extern "C" void _Z26WriteTexImageParam0208b548iiiiiiij(int a, int b, int c, int d, int e, int f, int g, unsigned int h);
ARM void WritePolygonAttr0208b588(unsigned int a0, unsigned int a1, unsigned int a2,
                                  unsigned int a3, unsigned int a4, unsigned int a5);

// USA: func_0208b610
extern "C" ARM void func_0208b610(Vector3fix v, unsigned short p, int a, int b, int c, short d) {
    RenderConfig::SetObjectPosition(&v);
    fix32_t cosine = _Z8fix32cosi(d);
    fix32_t sine = _Z8fix32sini(d);
    Matrix3x3 rot;
    Mat3x3_WriteRotationY(&rot, sine, cosine);
    _Z27ClearGlobalFlagBits02016d8cPv(&rot);
    Vector3fix scale;
    scale.x = a;
    scale.y = b;
    scale.z = c;
    RenderConfig::SetObjectScale(&scale);
    RenderConfig::SubmitToFifo();
    _Z26WriteTexImageParam0208b548iiiiiiij(0, 0, 1, 1, 0, 0, 0, 0);
    WritePolygonAttr0208b588(0, 0, 3, 0, 0, 0);
    *(volatile unsigned int*)0x04000500 = 1;
    *(volatile unsigned int*)0x04000480 = p;
    *(volatile unsigned int*)0x0400048c = 0x08000800;
    *(volatile unsigned int*)0x0400048c = 0x00000800;
    *(volatile unsigned int*)0x0400048c = 0xf8000800;
    *(volatile unsigned int*)0x0400048c = 0x00000800;
    *(volatile unsigned int*)0x0400048c = 0xf800f800;
    *(volatile unsigned int*)0x0400048c = 0x00000800;
    *(volatile unsigned int*)0x0400048c = 0x0800f800;
    *(volatile unsigned int*)0x0400048c = 0x00000800;
    *(volatile unsigned int*)0x0400048c = 0x08000800;
    *(volatile unsigned int*)0x0400048c = 0x0000f800;
    *(volatile unsigned int*)0x0400048c = 0xf8000800;
    *(volatile unsigned int*)0x0400048c = 0x0000f800;
    *(volatile unsigned int*)0x0400048c = 0xf800f800;
    *(volatile unsigned int*)0x0400048c = 0x0000f800;
    *(volatile unsigned int*)0x0400048c = 0x0800f800;
    *(volatile unsigned int*)0x0400048c = 0x0000f800;
    *(volatile unsigned int*)0x0400048c = 0x08000800;
    *(volatile unsigned int*)0x0400048c = 0x00000800;
    *(volatile unsigned int*)0x0400048c = 0x08000800;
    *(volatile unsigned int*)0x0400048c = 0x0000f800;
    *(volatile unsigned int*)0x0400048c = 0xf8000800;
    *(volatile unsigned int*)0x0400048c = 0x0000f800;
    *(volatile unsigned int*)0x0400048c = 0xf8000800;
    *(volatile unsigned int*)0x0400048c = 0x00000800;
    *(volatile unsigned int*)0x0400048c = 0x0800f800;
    *(volatile unsigned int*)0x0400048c = 0x00000800;
    *(volatile unsigned int*)0x0400048c = 0x0800f800;
    *(volatile unsigned int*)0x0400048c = 0x0000f800;
    *(volatile unsigned int*)0x0400048c = 0xf800f800;
    *(volatile unsigned int*)0x0400048c = 0x0000f800;
    *(volatile unsigned int*)0x0400048c = 0xf800f800;
    *(volatile unsigned int*)0x0400048c = 0x00000800;
    *(volatile unsigned int*)0x04000504 = 0;
}
