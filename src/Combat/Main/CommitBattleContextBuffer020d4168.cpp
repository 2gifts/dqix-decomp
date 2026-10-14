#include <globaldefs.h>
#include "System/Memory.h"

void* TryAcquireLock021142e8_020d4064(void);
void CleanCacheRange(const void* addr, unsigned int size);
int SendCommandToArm7(int a, int p, bool c);
extern "C" int func_020c7e0c(void* a, void* p, int c);

extern int data_021142e8;

// USA: func_020d4168
ARM int CommitBattleContextBuffer020d4168(void* a, unsigned int b) {
    void* res = TryAcquireLock021142e8_020d4064();
    if (res == NULL) {
        return 8;
    }
    VectorizedInvertedMemcpy(a, res, b);
    CleanCacheRange((const void*)((int)res), b);
    int r = SendCommandToArm7(0xa, (int)res, 0);
    func_020c7e0c(&data_021142e8, res, 1);
    return (r < 0) ? 8 : 2;
}
