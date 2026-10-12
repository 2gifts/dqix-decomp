#include <globaldefs.h>

#if defined(jpn)
#define func_ov004_02154718 func_ov004_02155db0
#define func_ov004_02154618 func_ov004_02155cc0
#endif


extern "C" void func_ov004_02154618(void* obj);
void* GetNodeIfKind6_02153944(void* a, int key);
extern "C" void func_ov023_021f809c(void* obj, void* param2);

// USA: func_ov004_02154718  (semantic: DispatchIfKind6_02154718)
extern "C" ARM void* func_ov004_02154718(void* obj) {
    void* node;
    func_ov004_02154618(obj);
    node = GetNodeIfKind6_02153944(obj, 0x37);
    if (node) {
        func_ov023_021f809c(node, obj);
    }
    return 0;
}
