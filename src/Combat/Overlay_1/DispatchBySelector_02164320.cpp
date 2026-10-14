#include <globaldefs.h>

struct Obj0204085c;
struct Obj02040b2c;
void StoreVec3AtField0x50_0203db34(unsigned char* obj, int a, int b, int c);
void HandleObjEvent0204085c(struct Obj0204085c* obj, int a, int b, int c);
void PropagateValueToActiveSlot02040b2c(struct Obj02040b2c* self, int value);

struct DispatchEntry02164320 {
    int selector;
    char pad[8];
    unsigned char* target;
};

// USA: func_ov001_02164320  (semantic: DispatchBySelector_02164320)
extern "C" ARM int func_ov001_02164320(struct DispatchEntry02164320* arr, int index, int argA, int argB, int argC) {
    struct DispatchEntry02164320* e;
    unsigned char* t;

    if (index < 0 || index >= 0x20) {
        return 0;
    }
    e = &arr[index];
    switch (e->selector) {
    case 4:
    case 5:
        t = e->target;
        if (t == NULL) return 0;
        StoreVec3AtField0x50_0203db34(t, argA, argB, argC);
        return 1;
    case 0:
        t = e->target;
        if (t == NULL) return 0;
        StoreVec3AtField0x50_0203db34(t, argA, argB, argC);
        return 1;
    case 1:
        t = e->target;
        if (t == NULL) return 0;
        StoreVec3AtField0x50_0203db34(t, argA, argB, argC);
        return 1;
    case 2:
    case 6:
        t = e->target;
        if (t == NULL) return 0;
        HandleObjEvent0204085c((struct Obj0204085c*)t, argA, argB, argC);
        PropagateValueToActiveSlot02040b2c((struct Obj02040b2c*)e->target, argB);
        return 1;
    }
    return 0;
}
