#include <globaldefs.h>

#if defined(jpn)
#define CallHelperIfFlag_021b2f2c func_ov017_021b363c
extern "C" void CallHelperIfFlag_021b2f2c(void);
#define func_ov003_02174890 func_ov003_021739b8
#endif

struct Screen_021b2ce8;
extern Screen_021b2ce8* data_ov017_021d840c;
extern "C" void func_ov003_02174890(char* obj);

// USA: func_ov017_021b2f2c
ARM void CallHelperIfFlag_021b2f2c(void) {
	if (data_ov017_021d840c != 0) {
		func_ov003_02174890((char*)data_ov017_021d840c);
	}
}
