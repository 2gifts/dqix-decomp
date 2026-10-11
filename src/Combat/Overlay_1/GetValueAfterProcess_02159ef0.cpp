#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct NodeStruct02159ef0 { char pad[0x3c]; int value; };
extern "C" void func_ov001_02159cfc(NodeStruct02159ef0* node);

// USA: func_ov001_02159ef0
ARM int GetValueAfterProcess_02159ef0(void* unused, NodeStruct02159ef0* node) {
    if (node == NULL) return 0;
    int val = node->value;
    func_ov001_02159cfc(node);
    return val;
}
