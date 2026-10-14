#include <globaldefs.h>
void SetAngleAndTrigTable0202e9a4(struct AngleTrig0202e9a4*, int);

// USA: func_0202f0c4
ARM void SetFields0x1f0And0x1f4_0202f0c4(void* obj, int a, int b) {
    *(int*)((char*)obj + 0x1f0) = a;
    *(int*)((char*)obj + 0x1f4) = b;
    if (b == 0) {
        SetAngleAndTrigTable0202e9a4((struct AngleTrig0202e9a4*)(obj), (int)(a));
    }
}
