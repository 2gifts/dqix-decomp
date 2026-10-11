#include <globaldefs.h>
#if defined(jpn)
enum { kRegioncc = 0xc8 };
enum { kRegion19b2 = 0x17e2 };
enum { kRegion99c = 0x86c };
#else
enum { kRegioncc = 0xcc };
enum { kRegion19b2 = 0x19b2 };
enum { kRegion99c = 0x99c };
#endif

int GetGlobalField0x1c020421a0();
struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
extern "C" void func_0204500c(void*, int, int, int);
#if defined(jpn)
extern "C" void func_02045d88(void*, int, int);
#endif

// JPN: func_ov003_0217c994
// USA: func_ov003_0217dd10
ARM void SetupField0217dd10(char* obj, int key) {
    int g = GetGlobalField0x1c020421a0();
    int v = GetFieldByKey020e0434((struct Container020e0310*)(obj + kRegioncc), (short)key);
#if defined(jpn)
    func_02045d88((void*)g, v, 0);
#else
    func_0204500c((void*)g, v, 0, 0xe3);
#endif
    *(unsigned char*)(g + kRegion19b2) = 1;
    *(int*)(g + kRegion99c) = 2;
}
