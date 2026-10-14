#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);

struct MsgQueue020d26ec {
    int _pad0;
    int slot4;
    void* head;
    int _pad1[5];
    int slot20;
};
extern MsgQueue020d26ec data_02112780;

// USA: func_020d26ec
ARM int GetInterruptSafeQueueField_020d26ec(void) {
    unsigned int mask = DisableIRQInterrupts();
    int result;
    if (data_02112780.head == 0)
        result = data_02112780.slot4;
    else
        result = data_02112780.slot20;
    SetIRQInterruptState(mask);
    return result;
}
