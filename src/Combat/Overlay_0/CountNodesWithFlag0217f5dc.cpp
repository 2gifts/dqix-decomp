#include <globaldefs.h>

extern "C" void* func_ov000_02161318(void*, int);
extern "C" int func_ov000_0217f5dc(void*);

// USA: func_ov000_0217608c
ARM int CountNodesWithFlag0217f5dc_ov000_0217608c(void* obj) {
    int count = 0;
    for (int i = 0; i < 4; i++) {
        void* node = func_ov000_02161318(obj, i);
        if (node) {
            if (func_ov000_0217f5dc(node)) count++;
        }
    }
    return count;
}
