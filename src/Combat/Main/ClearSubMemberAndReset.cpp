#include <globaldefs.h>

void ClearFirstThreeWords(unsigned int*);
#if defined(jpn)
#define func_0200f3a4 func_0200f268
#endif
extern "C" void func_0200f3a4(void*);

// KEEP-NAME
// USA: func_02012200
ARM char* ClearSubMemberAndReset(char* obj) {
    ClearFirstThreeWords((unsigned int*)(obj + 0x468));
    func_0200f3a4(obj);
    return obj;
}
