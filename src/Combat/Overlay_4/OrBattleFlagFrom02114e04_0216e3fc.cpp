#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

void* GetDataPtr02114e04_020d6c00(void);
void OrBitsIntoField0(unsigned int* p, unsigned int mask);

// USA: func_ov004_0216e3fc  (semantic: OrBattleFlagFrom02114e04_0216e3fc)
extern "C" ARM int func_ov004_0216e3fc(void) {
    OrBitsIntoField0((unsigned int*)GetDataPtr02114e04_020d6c00(), 0x80);
    return 0;
}
