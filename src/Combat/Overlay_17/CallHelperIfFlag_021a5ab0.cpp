#include <globaldefs.h>

extern void* data_ov017_021d83ac;
#if defined(jpn)
#define func_ov002_0215b6c0 func_ov002_0215c914
#endif
extern "C" void func_ov002_0215b6c0(void*);

// USA: func_ov017_021a5ab0
ARM void CallHelperIfFlag_021a5ab0(void*) {
	if (data_ov017_021d83ac != 0) {
		func_ov002_0215b6c0(data_ov017_021d83ac);
	}
}
