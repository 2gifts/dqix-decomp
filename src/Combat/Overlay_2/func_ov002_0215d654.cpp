#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov002_0215be00(void* obj, int val, int a2, int a3);
extern "C" void func_ov002_0215d72c(void* obj, void* buf, int flag);
extern "C" void func_0205d304(void* ptr, int val, int a2, int a3, int s0, int s1, int s2, int s3);
extern "C" void func_ov002_0215ddbc(void* obj);

struct Obj0205dee8 {
    char pad0[0xb0];
    unsigned char fieldB0;
};
void SetFieldB0AndUpdate0205dee8(struct Obj0205dee8* obj, int val);

struct Struct_0205d81c;
void SetElementFieldC2_0205deb4(struct Struct_0205d81c* s, int key, int value);

// USA: func_ov002_0215d654
extern "C" ARM void func_ov002_0215d654(unsigned char* obj) {
    func_ov002_0215be00(obj, (*(int*)(obj + 0x1000 + 0xbb8)) & 0xff, 4, 1);

    memset(*(void**)(obj + 0x1000 + 0xbd0), 0, 0x960);

    func_ov002_0215d72c(obj, *(void**)(obj + 0x1000 + 0xbd0), 0);

    func_0205d304(obj + 0x2c8 + 0xc00, *(int*)(obj + 0x1000 + 0xbd0), 0, 1, 0, 1, 0, 0);

    func_ov002_0215ddbc(obj);

    func_ov002_0215be00(obj, (*(int*)(obj + 0x1000 + 0xbb8)) & 0xff, 7, 1);

    SetFieldB0AndUpdate0205dee8((struct Obj0205dee8*)(obj + 0x2c8 + 0xc00), (*(int*)(obj + 0x1000 + 0xbb8)) & 0xff);

    SetElementFieldC2_0205deb4((struct Struct_0205d81c*)(obj + 0x2c8 + 0xc00), (*(int*)(obj + 0x1000 + 0xbb8)) & 0xff, 0);
}
