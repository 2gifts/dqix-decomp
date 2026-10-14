#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

void* GetDataPtr02114e04_020d6c00(void);
void OrBitsIntoField0_020466e4(unsigned int* p, unsigned int mask);
extern "C" int func_020aad1c(int a, int b, int c, int d);
extern "C" void func_ov017_021d6134(void* obj, int flag);
struct FlagWord020466f4;
void ClearFlags020466f4(FlagWord020466f4*, unsigned int);

struct S02163070 { char pad[0x4b4]; int field4B4; int field4B8; };
extern struct S02163070 data_ov001_021658b8;

// USA: func_ov001_02163070  (semantic: ApplyThreatOverrideAndFlag_02163070)
extern "C" ARM int func_ov001_02163070(void* obj) {
    if (data_ov001_021658b8.field4B4 == 0) {
        return 0;
    }
    unsigned int* p = (unsigned int*)GetDataPtr02114e04_020d6c00();
    OrBitsIntoField0_020466e4(p, 0x80);
    int r = func_020aad1c(data_ov001_021658b8.field4B4, data_ov001_021658b8.field4B8, 0xa, 0);
    int cond = (r != 0);
    func_ov017_021d6134(obj, cond == 0);
    if (cond != 0) {
        ClearFlags020466f4((FlagWord020466f4*)p, 0x80);
    }
    return 1;
}
