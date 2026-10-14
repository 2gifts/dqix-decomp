#include <globaldefs.h>

void ClearFirstThreeWords_02099898(unsigned int*);
#if defined(jpn)
#define func_0200f3a4 func_0200f268
#endif
extern "C" void func_0200f3a4(void*);

// KEEP-NAME
// USA: func_02012200
ARM char* ClearSubMemberAndReset_02012200(char* obj) {
    ClearFirstThreeWords_02099898((unsigned int*)(obj + 0x468));
    func_0200f3a4(obj);
    return obj;
}
