#include <globaldefs.h>

extern "C" void func_ov011_021848a0(int a1, int a2);

// USA: func_ov004_02167678
#if defined(jpn)
extern "C" ARM int func_ov004_02167c84(int a1)
#else
ARM int SetFlag108_02167678(int a1)
#endif
{
	func_ov011_021848a0(a1, 0x6c);
	return 0;
}
