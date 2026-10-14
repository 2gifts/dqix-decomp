#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_0202eab8(void* obj);
extern "C" void func_0202e5d8(void* obj, int a, int b, int c);
extern "C" void Mat3x3_WriteIdentity(void* obj);
void Clear0x28Bytes_020a0d58(void* p);

struct AngleTrig0202e9a4;
void SetAngleAndTrigTable0202e9a4(struct AngleTrig0202e9a4* obj, int angle);

// USA: func_0202df68  (semantic: InitField3b0Struct_0202df68)
extern "C" ARM void func_0202df68(void* obj) {
    *(int*)((char*)obj + 0x0) = 1;
    *(int*)((char*)obj + 0x64) = 0x1555;
    *(int*)((char*)obj + 0x68) = 0x1000;
    *(int*)((char*)obj + 0x6c) = 0x190000;
    SetAngleAndTrigTable0202e9a4((struct AngleTrig0202e9a4*)obj, 0xf000);

    *(int*)((char*)obj + 0x4) = 0;
    *(int*)((char*)obj + 0x8) = 0x4000;
    *(int*)((char*)obj + 0xc) = 0x8000;
    *(int*)((char*)obj + 0x10) = 0;
    *(int*)((char*)obj + 0x14) = 0x800;
    *(int*)((char*)obj + 0x18) = 0;
    *(int*)((char*)obj + 0x1c) = 0;
    *(int*)((char*)obj + 0x20) = 0x1000;
    *(int*)((char*)obj + 0x24) = 0;
    func_0202eab8(obj);

    func_0202e5d8(obj, 0, 0x6000, 0xb000);

    memset((char*)obj + 0xf0, 0, 0x30);

    *(unsigned short*)((char*)obj + 0x7c) = 0;
    *(int*)((char*)obj + 0x1e4) = 0;
    *(int*)((char*)obj + 0x1e8) = 0;
    *(int*)((char*)obj + 0x168) = 0;

    Mat3x3_WriteIdentity((char*)obj + 0x144);
    Clear0x28Bytes_020a0d58((char*)obj + 0x16c);
    Clear0x28Bytes_020a0d58((char*)obj + 0x194);
    Clear0x28Bytes_020a0d58((char*)obj + 0x1bc);

    *(int*)((char*)obj + 0x1f0) = *(int*)((char*)obj + 0x58);
    *(int*)((char*)obj + 0x1f4) = 0;
    *(unsigned char*)((char*)obj + 0x1f8) = 0;

    *(unsigned short*)((char*)obj + 0x1fa) = 0;
    *(int*)((char*)obj + 0x1fc) = 0;
    *(int*)((char*)obj + 0x200) = 0x3f800000;
    *(int*)((char*)obj + 0x204) = 0x1000;
    *(unsigned short*)((char*)obj + 0x1ec) = 0;
    *(unsigned short*)((char*)obj + 0x1ee) = 0;
    *(unsigned char*)((char*)obj + 0x20c) = 0;

    char* half2 = (char*)obj + 0x200;
    *(unsigned short*)(half2 + 0xe) = 0;
    *(unsigned short*)(half2 + 0x10) = 0;
    *(unsigned short*)(half2 + 0x12) = 0;
    *(unsigned short*)(half2 + 0x14) = 0;
    *(unsigned short*)(half2 + 0x16) = 0;
}
