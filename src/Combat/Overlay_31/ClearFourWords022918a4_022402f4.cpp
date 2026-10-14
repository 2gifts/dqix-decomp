#include <globaldefs.h>

struct FourWords;
struct Mutex;
void ZeroInitializeMutex(Mutex*);
extern struct FourWords data_ov031_022918a4;

// USA: func_ov031_022402f4
ARM int ClearFourWords022918a4_022402f4(void) {
	ZeroInitializeMutex((Mutex*)&data_ov031_022918a4);
	return 1;
}
