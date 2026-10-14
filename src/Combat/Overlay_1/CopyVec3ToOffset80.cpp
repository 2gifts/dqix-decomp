#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_ov001_021594ac
ARM int CopyVec3ToOffset80_ov001_021594ac(void* a, void* b) {
	memcpy((char*)b + 0x80, (char*)a + 4, 0xc);
	return 0;
}
