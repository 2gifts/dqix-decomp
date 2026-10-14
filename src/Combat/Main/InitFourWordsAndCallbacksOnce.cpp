#include <globaldefs.h>

struct FourWords;
struct Mutex;
void ZeroInitializeMutex(Mutex*);
void ClearCallbackTable_020d2930();

extern "C" void func_020d2220(void);

extern int data_02112750;
extern FourWords data_02112754;

// USA: func_020d21c0
ARM void InitFourWordsAndCallbacksOnce_020d21c0(void) {
    if (data_02112750 != 0) {
        return;
    }
    data_02112750 = 1;
    ZeroInitializeMutex((Mutex*)&data_02112754);
    func_020d2220();
    ClearCallbackTable_020d2930();
}
