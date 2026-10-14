#include <globaldefs.h>

int EnqueueEvent0x6Sub6_020d1e70(int a, int b);
int SubmitCommandType1_020d1de8(int a);
extern "C" void func_020bc79c(void*);

struct Obj020bc6fc {
    char pad0[0x2c];
    unsigned char field2c;
    char pad2d[0x3c - 0x2d];
    unsigned char field3c;
};

// USA: func_020bc6fc
ARM void DispatchType2Command020bc6fc(struct Obj020bc6fc* obj) {
    if (obj->field2c == 2) {
        EnqueueEvent0x6Sub6_020d1e70(obj->field3c, 0xfffffd2d);
    }
    SubmitCommandType1_020d1de8(obj->field3c);
    func_020bc79c(obj);
}
