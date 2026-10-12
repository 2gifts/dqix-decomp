#include <globaldefs.h>

#if defined(jpn)
#define func_0209e8cc func_020a0644
#endif


void* GetGlobalManager0209dccc();
extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_0209e8cc(void*, int, int);

#if defined(jpn)
#define TryProcessObjectPair0209e8cc func_0209ecbc
extern "C" ARM int func_0209ecbc(void* obj);
#endif

// USA: func_0209cf44
ARM int TryProcessObjectPair0209e8cc(void* obj) {
    void* mgr = GetGlobalManager0209dccc();
    if (mgr == NULL) return 0;
    int a = func_ov017_021d60f4(obj);
    int b = func_ov017_021d60f4((char*)obj + 8);
    func_0209e8cc(mgr, a, b);
    return 1;
}
