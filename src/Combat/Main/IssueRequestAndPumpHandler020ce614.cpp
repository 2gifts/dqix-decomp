#include <globaldefs.h>
void StoreValueIfPtrNotNull(int, int*);

extern "C" void func_020ce234(void);
int RemapRequestTypeAndRunHandler_020ce5b0(int, void(*)(void), int*);
extern void (*data_020f2298)(void);

// USA: func_020ce614
ARM int IssueRequestAndPumpHandler020ce614(int a) {
    int out;
    int r = RemapRequestTypeAndRunHandler_020ce5b0(a, func_020ce234, &out);
    if (r != 0) return r;
    data_020f2298();
    return out;
}
