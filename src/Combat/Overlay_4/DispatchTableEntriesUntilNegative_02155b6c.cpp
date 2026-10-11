#if defined(jpn)
#define R(j,u) (j)
#define data_ov004_0216fae0 data_ov004_0217026c
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void func_ov004_02155a3c(void* a);
int DispatchNodeIfState6_021f6680(void* obj, int id);
struct Arr3_02155b6c { int v[3]; };
extern struct Arr3_02155b6c data_ov004_0216fae0;

// USA: func_ov004_02155b6c  (semantic: DispatchTableEntriesUntilNegative_02155b6c)
extern "C" ARM int func_ov004_02155b6c(void* a) {
    func_ov004_02155a3c(a);
    struct Arr3_02155b6c local = data_ov004_0216fae0;
    for (int i = 0; local.v[i] >= 0; i++) {
        DispatchNodeIfState6_021f6680(a, local.v[i]);
    }
    return 0;
}
