#include <globaldefs.h>
#include "System/ProcessorContext.h"

#if defined(jpn)
extern "C" int func_ov031_0220afe0(char* self);
#define GetRemainingOrStatus_0220a800 func_ov031_0220afe0
#else
int GetRemainingOrStatus_0220a800(char* self);
#endif

// USA: func_ov031_02203b1c  (semantic: GetActiveContextRemainingOrStatus_02203b1c)
extern "C" ARM int func_ov031_02203b1c(void) {
	char* mgr = (char*)data_02111304.activeContext->unknown_A4;
	if (mgr == NULL) {
		goto ret_zero;
	}
	if (*(unsigned char*)(mgr + 9) != 0) {
		return GetRemainingOrStatus_0220a800(mgr);
	}
	{
		int f44 = *(int*)(mgr + 0x44);
		if (f44 != 0) {
			goto ret_f44;
		}
		if (*(unsigned char*)(mgr + 8) == 4) {
			goto ret_f44;
		}
		{
			unsigned char t = (unsigned char)(*(unsigned char*)(mgr + 8) + 0xf6);
			if (t > 1) {
				goto ret_neg1;
			}
		}
	ret_f44:
		return f44;
	}
ret_neg1:
	return -1;
ret_zero:
	return 0;
}
