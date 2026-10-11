#include <globaldefs.h>

#if defined(jpn)
enum { matrixOffset = 0x464 };
#else
enum { matrixOffset = 0x444 };
#endif

struct Mtx43_02030d84;
extern "C" void _Z15RotationMatrixYi(struct Mtx43_02030d84*, int);

struct Buf02018f6c { unsigned int words[12]; };
struct Obj02018f6c {
    char pad0[matrixOffset];
    unsigned int block[12];
    short flag;
};

// USA: func_02018f6c
ARM void StoreAndMaybeCopy02018f6c(struct Obj02018f6c* obj, short arg) {
    struct Buf02018f6c buf;
    short flag;
    obj->flag = arg;
    flag = obj->flag;
    if (flag != 0) {
        _Z15RotationMatrixYi((struct Mtx43_02030d84*)&buf, flag);
        *(struct Buf02018f6c*)obj->block = buf;
    }
}
