#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_ov017_021d6134(void*, int);
void* GetGlobalPtr021075f4_0203cf4c(void);
int FindEntryByKey0203dfdc(void* base, int key);

// USA: func_ov001_0215fa10
ARM int SetFieldFromEntryIndex_0215fa10(char* obj) {
    int key = func_ov017_021d60f4(obj);
    void* base = GetGlobalPtr021075f4_0203cf4c();
    int idx = FindEntryByKey0203dfdc(base, key);
    func_ov017_021d6134(obj + 8, idx);
    return 1;
}
