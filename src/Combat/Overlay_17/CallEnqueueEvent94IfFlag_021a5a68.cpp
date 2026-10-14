#include <globaldefs.h>

extern int data_ov017_021d83ac;
int EnqueueEvent0x5e_ov000_0216c28c(void);

// USA: func_ov017_021a5a68
ARM void CallEnqueueEvent94IfFlag_021a5a68(void) {
	if (data_ov017_021d83ac != 0) {
		EnqueueEvent0x5e_ov000_0216c28c();
	}
}
