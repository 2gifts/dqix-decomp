#include <globaldefs.h>

extern "C" void func_ov011_021848a0(int, int);

// USA: func_ov004_021650e4
#if defined(jpn)
extern "C" ARM int func_ov004_02165974(int a)
#else
ARM int SetMessageFlag021650e4(int a)
#endif
{
	func_ov011_021848a0(a, 0x6a);
	return 0;
}
