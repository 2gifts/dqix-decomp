#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
void ClearBitsInWord_0203b4b0(unsigned int* obj, unsigned int mask);
extern "C" void func_ov028_021d9714(void);
void PopStack1AndTrigger_020a1f4c(int flag);

// USA: func_ov001_0216227c  (semantic: Something_0216227c)
extern "C" ARM int func_ov001_0216227c(void) {
    ClearBitsInWord_0203b4b0((unsigned int*)func_ov017_0218b5b0(), 0x1000);
    func_ov028_021d9714();
    PopStack1AndTrigger_020a1f4c(1);
    return 1;
}
