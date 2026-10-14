#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

extern "C" void func_0204719c(void* obj, int flag);
extern "C" void* __clear(void* dst, int count);
extern "C" void func_02047b40(void* obj, void* handle, void* extra);

int GetData02107800Word0_020429d4(void);
void* LoadFileIntoMemory(const char* path, void* dst, unsigned int* outCount);

extern int data_020f0118;

struct Obj02047a78 {
    char pad0[0x84];
    unsigned char flag0 : 1;
    unsigned char flagRest : 7;
};

// USA: func_02047a78
extern "C" ARM void func_02047a78(struct Obj02047a78* obj, const char* path, void* extra) {
    char buf[0x80];
    int flag;
    void* handle;

    if (path == 0) {
        return;
    }
    flag = obj->flag0;
    if (flag) {
        if (flag) {
            func_0204719c(obj, flag);
        }
        obj->flag0 = 0;
    }
    if ((path + strlen(path))[-1] != 'r') {
        return;
    }
    __clear(buf, 0x80);
    sprintf(buf, (const char*)&data_020f0118, path);
    handle = (void*)GetData02107800Word0_020429d4();
    BackgroundLoader::AddLockGlobal();
    if (LoadFileIntoMemory(buf, handle, 0) != 0) {
        func_02047b40(obj, handle, extra);
    }
    BackgroundLoader::RemoveLockGlobal();
}
