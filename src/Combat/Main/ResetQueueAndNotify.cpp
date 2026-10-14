#include <globaldefs.h>
void ProcessQueueUntilValueCommitted020d2680(unsigned int);

int GetInterruptSafeQueueField_020d26ec(void);

extern "C" void func_020bd02c(void);
extern "C" void func_020d1f0c(int a, int b, int c, int d);
extern "C" void func_020d24c4(int a);

// USA: func_020bbdd8
ARM void ResetQueueAndNotify_020bbdd8(void) {
    func_020bd02c();
    func_020d1f0c(0, 0, 0, 0);
    int v = GetInterruptSafeQueueField_020d26ec();
    func_020d24c4(1);
    ProcessQueueUntilValueCommitted020d2680((unsigned int)(v));
}
