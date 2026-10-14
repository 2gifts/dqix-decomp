#include <globaldefs.h>

extern "C" void func_020c976c(unsigned int id);
int IsPowcntBit0Set_020cede0(void);
int IssueCategorizedRequestAndPumpHandler020ce6d0(int a, int b);
int DispatchIfEquals1_020cedc0(int a);

// USA: func_020cef94  (semantic: PumpAndDispatchLoop_020cef94)
extern "C" ARM void func_020cef94(void) {
    func_020c976c(0x360000);
    if (IsPowcntBit0Set_020cede0() == 1) return;
    if (IssueCategorizedRequestAndPumpHandler020ce6d0(2, 0) != 0) {
        do {
            func_020c976c(0xa3a47);
        } while (IssueCategorizedRequestAndPumpHandler020ce6d0(2, 0) != 0);
    }
    if (DispatchIfEquals1_020cedc0(1) != 0) return;
    do {
        func_020c976c(0xa);
    } while (DispatchIfEquals1_020cedc0(1) == 0);
}
