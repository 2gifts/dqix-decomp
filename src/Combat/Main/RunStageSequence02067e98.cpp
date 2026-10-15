#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_0206b104(void* obj, int b);
extern "C" void func_0206831c(void* obj, int b, unsigned int x);
extern "C" void func_02068418(void* obj, unsigned int a, unsigned int b, unsigned char flag);
extern "C" void func_02068f40(void* obj, unsigned int a, unsigned int b, unsigned char flag);
extern "C" void func_02069234(void* obj, unsigned int a, unsigned int b, unsigned char flag);
extern "C" void func_020695f4(void* obj, unsigned int a, unsigned int b, unsigned char flag);
extern "C" void func_02069fec(void* obj, unsigned int a, unsigned int b);

struct Ctx0206a974;
void InitContextString0206a974(struct Ctx0206a974* p, const char* src, int boxWidth);

// USA: func_02067e98
ARM void RunStageSequence02067e98(unsigned char* obj, int b) {
    func_0206b104(obj, b);
    memset(*(void**)(obj + 0x48), 0, 0x960);
    unsigned int x = *(unsigned int*)(obj + 0x60);
    unsigned int y = *(unsigned int*)(obj + 0x64);
    func_0206831c(obj, b, x);
    func_02068418(obj, x, y, (obj + 0x1000)[0x9dc]);
    func_02068f40(obj, y, x, (obj + 0x1000)[0x9dc]);
    func_02069234(obj, x, y, (obj + 0x1000)[0x9dc]);
    func_020695f4(obj, y, x, (obj + 0x1000)[0x9dc]);
    func_02069fec(obj, x, y);
    InitContextString0206a974((struct Ctx0206a974*)obj, (const char*)y, 0xe3);
    *(int*)(obj + 0x9a0) = 5;
}
