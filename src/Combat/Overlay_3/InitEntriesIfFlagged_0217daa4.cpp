#include <globaldefs.h>
#if defined(jpn)
enum { kRegion90 = 0x8c };
#else
enum { kRegion90 = 0x90 };
#endif

int GetGlobalField0x1c020421a0(void);
void Forward0204359c(void* obj, int count);
extern "C" void func_020439b0(void* obj, int flag);
struct Obj0205d2bc;
void InitEntries0205d2bc(struct Obj0205d2bc* obj);

// JPN: func_ov003_0217c744
// USA: func_ov003_0217daa4  (semantic: InitEntriesIfFlagged_0217daa4)
extern "C" ARM void func_ov003_0217daa4(char* obj) {
    int g = GetGlobalField0x1c020421a0();
    Forward0204359c((void*)g, 2);
    func_020439b0((void*)g, 0);
    struct Obj0205d2bc* p = *(struct Obj0205d2bc**)(obj + kRegion90);
    if (p == 0) return;
    if (*(signed char*)(obj + 4) == 2 || *(signed char*)(obj + 5) == 0) {
        InitEntries0205d2bc(p);
    }
}
