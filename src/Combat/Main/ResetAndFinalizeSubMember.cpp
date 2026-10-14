#include <globaldefs.h>

#if defined(jpn)
#define func_0200f3a4 func_0200f268
#endif
extern "C" void func_0200f3a4(void*);
int ForwardFirstWord020998ac(int*);

// KEEP-NAME
// USA: func_02012224
ARM char* ResetAndFinalizeSubMember_02012224(char* obj) {
    func_0200f3a4(obj);
    ForwardFirstWord020998ac((int*)(obj + 0x468));
    return obj;
}
