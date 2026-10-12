#include <globaldefs.h>

#if defined(jpn)
#define func_ov004_0216df7c func_ov004_0216e63c
enum { kStateByte = 5 };
#else
enum { kStateByte = 3 };
#endif



extern "C" void func_ov011_021848a0(int a1, int a2);

extern unsigned char data_ov004_02171034[];

// USA: func_ov004_0216df7c  (semantic: SetDataByteAndFlag_0216df7c)
extern "C" ARM int func_ov004_0216df7c(int a1) {
	data_ov004_02171034[kStateByte] = 5;
	func_ov011_021848a0(a1, 5 + 0x128);
	return 0;
}
