#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_ov001_02157bfc
ARM int CopyVec3ToOffset4c_ov001_02157bfc(void* a, void* b) {
	memcpy((char*)b + 0x4c, (char*)a + 4, 0xc);
	return 0;
}
