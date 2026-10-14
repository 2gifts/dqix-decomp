#include <globaldefs.h>

extern "C" int func_020d1f0c(int a0, int a1, int a2, int a3);
int GetInterruptSafeQueueField_020d26ec(void);
extern "C" void func_020d24c4(int a);
void ProcessQueueUntilValueCommitted020d2680(unsigned int a);

extern char data_0210fd74;
extern char data_0210fdbc;

// USA: func_020bd02c  (semantic: RunTweenQueueTick020bd02c)
extern "C" ARM void func_020bd02c(void) {
    char* fd74 = &data_0210fd74;
    char* base = &data_0210fdbc;
    if (*(int*)(fd74 + 0x48) == 0) return;
    int shift = *(int*)(base + 0x2c);
    int mask = (shift >= 0) ? (1 << shift) : 0;
    int a = *(int*)(base + 0x24);
    int b = *(int*)(base + 0x28);
    func_020d1f0c(a, b, mask, 0);
    int x = GetInterruptSafeQueueField_020d26ec();
    func_020d24c4(1);
    ProcessQueueUntilValueCommitted020d2680((unsigned int)x);
}
