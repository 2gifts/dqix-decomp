#include <globaldefs.h>

void* GetGlobalManager0209dccc();
extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_0209ed0c(void*, int, int);

// USA: func_0209d054
ARM int TryProcessObjectPair0209ed0c_0209d054(void* obj) {
    void* mgr = GetGlobalManager0209dccc();
    if (mgr == NULL) return 0;
    int a = func_ov017_021d60f4(obj);
    int b = func_ov017_021d60f4((char*)obj + 8);
    func_0209ed0c(mgr, a, b);
    return 1;
}
