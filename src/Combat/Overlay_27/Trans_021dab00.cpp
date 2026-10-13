#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

void DrainWriteBuffer();
int DispatchEvent_021dcf44(int p0, int p1, int p2);
void CleanInvalidateCacheRange(const void* where, unsigned int len);

// USA: func_ov027_021dab00  (semantic: Trans_021dab00)
extern "C" ARM int func_ov027_021dab00(int a, int b, void* c) {
    CleanInvalidateCacheRange(c, (a + 0x1f) & ~0x1f);
    DrainWriteBuffer();
    return DispatchEvent_021dcf44((int)c, a, b);
}
