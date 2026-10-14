#include <globaldefs.h>
void ProcessQueueUntilValueCommitted020d2680(unsigned int);

extern "C" void func_020d1f0c(void*, int, int, int);
extern "C" void func_020d24c4(int);
int GetInterruptSafeQueueField_020d26ec(void);

struct Obj020bcde0 {
    char pad0[0x24];
    int bit0 : 1;
    int bit1 : 1;
    int bitrest : 30;
    char pad28[0x40 - 0x28];
    int field40;
    void* field44;
};

// USA: func_020bcde0
ARM void NotifyMaskedEvent020bcde0(struct Obj020bcde0* obj) {
    if (!obj->bit1) return;
    func_020d1f0c(obj->field44, 0, 1 << obj->field40, 0);
    int x = GetInterruptSafeQueueField_020d26ec();
    func_020d24c4(1);
    ProcessQueueUntilValueCommitted020d2680((unsigned int)(x));
}
