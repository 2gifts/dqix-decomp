#include <globaldefs.h>

#if defined(jpn)
enum { taskHandleOffset = 0x4c0 };
#else
enum { taskHandleOffset = 0x6d0 };
#endif

extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_02020720(int);
extern "C" int func_02012fe4(void);
extern "C" int sprintf(char* dst, const char* fmt, ...);

struct Obj020e063c;
void RestartTaskHandle020e063c(Obj020e063c* self, int b, int c);

struct Struct020dc3d4 {
    char pad[taskHandleOffset];
    int field6d0;
};

extern char data_020f2948;
extern char data_020f294f;

// USA: func_020dc3d4
ARM void RestartTaskWithDebugLog020dc3d4(void) {
    char buf[0x18];
    int base = func_ov017_0218b5b0();
    int handle = ((Struct020dc3d4*)(base + 0x3000))->field6d0;
    func_02020720(handle);
    sprintf(buf, &data_020f2948, func_02012fe4() + 0x26);
    RestartTaskHandle020e063c((Obj020e063c*)handle, (int)&data_020f294f, (int)buf);
}
