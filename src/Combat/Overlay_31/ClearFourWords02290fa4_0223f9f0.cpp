#include <globaldefs.h>

struct FourWords;
struct Mutex;
void ZeroInitializeMutex(Mutex*);
extern struct FourWords data_ov031_02290fa4;

// USA: func_ov031_0223f9f0
ARM int ClearFourWords02290fa4_0223f9f0(void) {
	ZeroInitializeMutex((Mutex*)&data_ov031_02290fa4);
	return 1;
}
