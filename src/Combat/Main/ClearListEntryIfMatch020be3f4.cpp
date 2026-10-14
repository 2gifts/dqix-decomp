#include <globaldefs.h>

unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int mask);
void* SetGlobalContext02110370_020bd42c(void* value);
int GetListEntryWord8020bd8ac(unsigned int index);
void SetListEntryWord8020bd8d4(unsigned int index, int value);

// USA: func_020be3f4
ARM void ClearListEntryIfMatch020be3f4(int a0, void* a1, unsigned int a2) {
    if (a1 == NULL) return;
    void* prev;
    unsigned int mask = DisableIRQInterrupts();
    prev = SetGlobalContext02110370_020bd42c(a1);
    int val = GetListEntryWord8020bd8ac(a2);
    if (a0 == val) {
        SetListEntryWord8020bd8d4(a2, 0);
    }
    SetGlobalContext02110370_020bd42c(prev);
    SetIRQInterruptState(mask);
}
