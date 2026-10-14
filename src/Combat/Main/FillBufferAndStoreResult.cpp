#include <globaldefs.h>

extern "C" void CpuSet(const void*, void*, unsigned int);
int GenerateLockOwnerID(void);

extern int data_0211214c;
extern char data_02112148;

// USA: func_020d12e4
ARM void FillBufferAndStoreResult_020d12e4(void) {
    int zero = 0;
    CpuSet(&zero, &data_0211214c, 0x5000001);
    int result = GenerateLockOwnerID();
    *(short*)(&data_02112148 + 0x6) = (short)result;
}
