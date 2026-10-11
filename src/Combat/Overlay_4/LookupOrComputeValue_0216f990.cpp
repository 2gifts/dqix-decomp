#if defined(jpn)
#define R(j,u) (j)
#define data_ov004_021702bc data_ov004_021709f0
#define data_ov004_021702c0 data_ov004_021709f4
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern int data_ov004_021702bc;
extern int data_ov004_021702c0;

// USA: func_ov004_0216f990  (semantic: LookupOrComputeValue_0216f990)
extern "C" ARM int func_ov004_0216f990(int mode, int key, int flag) {
    if (mode == 1) {
        for (int i = 0; i < 0xc; i++) {
            int k = *(int*)((char*)&data_ov004_021702bc + (i << 3));
            if (key == k) {
                return *(int*)((char*)&data_ov004_021702c0 + (i << 3));
            }
        }
    } else if (mode == 2) {
        if ((unsigned int)key < 1) {
            goto fail;
        }
        if ((unsigned int)key > 0xd) {
            goto fail;
        }
        if (flag != 0) {
            return (flag - 1) * 0xd + (key + 0x2d);
        }
    }
fail:
    return 0;
}
