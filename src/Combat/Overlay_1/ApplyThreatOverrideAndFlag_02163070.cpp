#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void* _Z27GetDataPtr02114e04_020d6c00v(void);
extern "C" void _Z16OrBitsIntoField0Pjj(unsigned int* p, unsigned int mask);
extern "C" int func_020aad1c(int a, int b, int c, int d);
extern "C" void func_ov017_021d6134(void* obj, int flag);
extern "C" void _Z18ClearFlags020466f4P16FlagWord020466f4j(void* p, unsigned int mask);

struct S02163070 { char pad[0x4b4]; int field4B4; int field4B8; };
extern struct S02163070 data_ov001_021658b8;

// USA: func_ov001_02163070  (semantic: ApplyThreatOverrideAndFlag_02163070)
extern "C" ARM int func_ov001_02163070(void* obj) {
    if (data_ov001_021658b8.field4B4 == 0) {
        return 0;
    }
    unsigned int* p = (unsigned int*)_Z27GetDataPtr02114e04_020d6c00v();
    _Z16OrBitsIntoField0Pjj(p, 0x80);
    int r = func_020aad1c(data_ov001_021658b8.field4B4, data_ov001_021658b8.field4B8, 0xa, 0);
    int cond = (r != 0);
    func_ov017_021d6134(obj, cond == 0);
    if (cond != 0) {
        _Z18ClearFlags020466f4P16FlagWord020466f4j(p, 0x80);
    }
    return 1;
}
