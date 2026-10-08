#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

extern char data_0211e33c[];

extern "C" int func_020aaf84(void* buf, int a, int b, int c);
extern "C" void func_020a93e0(char* param0);
extern "C" void* func_0205ec34(void);
extern "C" int func_020a9a50(void* ctx, char* dst, int flag);
extern "C" void func_02042764(unsigned char* src, char* dst, int n);
extern "C" void __clear(void* buf, int n);

struct Struct020865b0;
int GetFieldAt0x50(struct Struct020865b0* p);

extern "C" void* _Z27GetDataPtr02114e04_020d6c00v();
void OrBitsIntoField0(unsigned int* word, unsigned int bits);
struct FlagWord020466f4;
extern "C" void _Z18ClearFlags020466f4P16FlagWord020466f4j(struct FlagWord020466f4* word, unsigned int bits);
int TestBitInByteArray(int unused, unsigned char* arr, int index);
int VerifyAndApplySaveBuffer(int flag);

struct Elem020ab5d4 {
    char data[0x30];
    unsigned char f30;
    unsigned char f31;
    unsigned short f32;
};

struct Local020ab5d4 {
    struct Elem020ab5d4 elems[4];
    int f104;
    unsigned char f108;
    unsigned char f109;
    unsigned char f10a;
    unsigned char f10b;
};

struct Sz3c00_020ab5d4 {
    char pad[0x3c00];
};

// USA: func_020ab5d4
extern "C" ARM int func_020ab5d4(void* param0, int param1, int param2, void* param3) {
    if (func_020aaf84(param0, 0, 0, 1) == 0) {
        return 0;
    }
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    unsigned int* flags = (unsigned int*)_Z27GetDataPtr02114e04_020d6c00v();
    OrBitsIntoField0(flags, 0x2000000);
    unsigned char* base = (unsigned char*)&data_0211e33c[0] + 0x28000;
    GameState* gs = GameState::GetInstance();
    unsigned char* arr = base + 4;
    func_020a93e0((char*)arr);
    char buf[0x30];
    struct Local020ab5d4 loc;
    loc.f108 = arr[0x1d11];
    loc.f104 = *(unsigned short*)(arr + 0x2c4c);
    int i;
    for (i = 0; i < loc.f108; i++) {
        unsigned char* e = arr + (arr[0x1d0c] + i) * 0x23c;
        if (e != 0) {
            struct Elem020ab5d4* el = &loc.elems[i];
            int v = GetFieldAt0x50((struct Struct020865b0*)e);
            el->f30 = v;
            unsigned char* p = e + v;
            el->f31 = p[0xf];
            el->f32 = p[2];
            __clear(buf, 0x30);
            func_02042764(e + 0x140, buf, 1);
            memcpy(el->data, buf, 0x30);
        }
    }
    unsigned char* caddr = base + 0x2cac;
    void* ctx = func_0205ec34();
    func_020a9a50(caddr, (char*)ctx, 0);
    loc.f109 = TestBitInByteArray((int)ctx, (unsigned char*)ctx + 0x8c, 0x796);
    loc.f10a = *(int*)caddr;
    loc.f10b = TestBitInByteArray((int)ctx, (unsigned char*)ctx + 0x8c, 0x1142) != 0;
    memcpy((char*)gs + 0x7e80, &loc, 0xd8);
    memcpy(param3, (char*)(((struct Sz3c00_020ab5d4*)(base + 0x1d8)) + 1) + 0x3c, 4);
    if (VerifyAndApplySaveBuffer(0) == 0) {
        BackgroundLoader::RemoveLockGlobal();
        _Z18ClearFlags020466f4P16FlagWord020466f4j((struct FlagWord020466f4*)flags, 0x2000000);
        return 0;
    }
    BackgroundLoader::RemoveLockGlobal();
    _Z18ClearFlags020466f4P16FlagWord020466f4j((struct FlagWord020466f4*)flags, 0x2000000);
    return 1;
}