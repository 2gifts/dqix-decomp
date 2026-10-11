#include <globaldefs.h>

#if defined(jpn)
enum { matrixFlagOffset = 0x494, matrixOffset = 0x464 };
#else
enum { matrixFlagOffset = 0x474, matrixOffset = 0x444 };
#endif

void IssueCommand0x19(int cmd);  // _Z16IssueCommand0x19i
extern "C" void func_02016e14(void* a, void* b, void* c, int d);

// USA: func_02016db4
ARM void PushMatrixAndRender02016db4(void* obj, void* node) {
    *(int*)0x4000444 = 0;
    if (*(short*)((char*)obj + matrixFlagOffset) != 0) {
        IssueCommand0x19((int)((char*)obj + matrixOffset));
    }
    func_02016e14(obj, node, *(void**)((char*)node + 0x44), 0);
    *(int*)0x4000448 = 1;
}
