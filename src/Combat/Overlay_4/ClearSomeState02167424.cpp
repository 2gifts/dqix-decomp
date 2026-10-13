#include <globaldefs.h>

extern "C" void func_ov004_02166bd8(void);

// USA: func_ov004_02167424
#if defined(jpn)
extern "C" ARM int func_ov004_02167a30(void)
#else
ARM int ClearSomeState02167424(void)
#endif
{
	func_ov004_02166bd8();
	return 0;
}
