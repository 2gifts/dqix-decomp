#include <globaldefs.h>
#if defined(jpn)
enum { kRegion19b2 = 0x17e2 };
enum { kRegion99c = 0x86c };
#else
enum { kRegion19b2 = 0x19b2 };
enum { kRegion99c = 0x99c };
#endif

int GetGlobalField0x1c020421a0();
extern "C" void func_0204500c(void*, int, int, int);
#if defined(jpn)
extern "C" void func_02045d88(void*, int, int);
#endif

// JPN: func_ov003_0215a73c
// USA: func_ov003_02159250  (semantic: SetGlobalFieldsFromObj_02159250)
extern "C" ARM void func_ov003_02159250(char* obj, int flag) {
    if (flag == 0) return;
    int g = GetGlobalField0x1c020421a0();
#if defined(jpn)
    func_02045d88((void*)g, flag, 0);
#else
    func_0204500c((void*)g, flag, 0, 0xe3);
#endif
    *(unsigned char*)(g + kRegion19b2) = (unsigned char)obj[0x5b2];
    *(int*)(g + kRegion99c) = (unsigned char)obj[0x5b1];
}
