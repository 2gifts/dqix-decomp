#include <globaldefs.h>

#if defined(jpn)
#define func_ov004_021547fc func_ov004_02155e84
#define func_ov004_02154748 func_ov004_02155de0
#endif


extern "C" void func_ov004_02154748(void* obj);
void* GetNodeIfKind6_02153944(void* a, int key);
extern "C" void func_ov023_021f809c(void* obj, void* param2);

// USA: func_ov004_021547fc  (semantic: DispatchIfKind6_021547fc)
extern "C" ARM void* func_ov004_021547fc(void* obj) {
    void* node;
    func_ov004_02154748(obj);
    node = GetNodeIfKind6_02153944(obj, 0x37);
    if (node) {
        func_ov023_021f809c(node, obj);
    }
    return 0;
}
