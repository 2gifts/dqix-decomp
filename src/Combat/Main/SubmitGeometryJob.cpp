#include <globaldefs.h>

extern "C" void Mat4x3_WriteViewMatrix(int, int, int, void*);
void IssueCommand0x17_020c5188(int cmd);

// USA: func_020c57d4
#pragma optimize_for_size off
ARM void SubmitGeometryJob_020c57d4(int a, int b, int c, int flag, void* buf) {
    unsigned char local[0x30];
    void* dst = buf ? buf : local;
    Mat4x3_WriteViewMatrix(a, b, c, dst);
    if (!flag) return;
    *(volatile int*)0x4000440 = 2;
    IssueCommand0x17_020c5188((int)dst);
}
