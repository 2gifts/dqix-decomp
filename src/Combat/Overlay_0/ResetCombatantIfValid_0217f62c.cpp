#include <globaldefs.h>
#if defined(jpn)
enum { flagsOffset = 0x1faa };
#else
enum { flagsOffset = 0x1d72 };
#endif

extern "C" int func_ov000_0217f6bc(void* obj);
extern "C" void* func_ov000_02161318(void* obj, int id);
struct Struct02170fd0;
void CallHandlerIfF38Set02170fd0(struct Struct02170fd0* obj, int b);
extern "C" void func_ov000_02175258(void* obj);
extern "C" void func_ov000_0217a8f4(void* obj);

// USA: func_ov000_0217f62c  (semantic: ResetCombatantIfValid_0217f62c)
extern "C" ARM int func_ov000_0217f62c(void* objRaw) {
    char* obj = (char*)objRaw;
    int n = func_ov000_0217f6bc(obj);
    int valid = (n >= 0 && n <= 3) ? 1 : 0;
    if (valid) {
        struct Struct02170fd0* entry = (struct Struct02170fd0*)func_ov000_02161318(obj, n);
        if (entry != 0) {
            *(int*)(obj + 0x17c) = *(int*)((char*)entry + 0x4c);
            CallHandlerIfF38Set02170fd0(entry, 0);
            *(int*)(obj + 0x910) = 0;
            *(int*)(obj + 0x914) = 0;
            *(int*)(obj + 0x918) = 0;
            *(int*)(obj + 0x91c) = 0;
            unsigned short field72 = *(unsigned short*)(obj + flagsOffset);
            field72 = field72 & ~0x38;
            *(unsigned short*)(obj + flagsOffset) = field72;
            func_ov000_02175258(obj);
            func_ov000_0217a8f4(obj);
            return 0;
        }
    }
    return 1;
}
