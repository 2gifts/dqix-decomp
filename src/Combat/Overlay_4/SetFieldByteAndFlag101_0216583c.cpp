#include <globaldefs.h>

#if defined(jpn)
#define func_ov004_0216583c func_ov004_021660cc
#endif

#if defined(jpn)
enum { flagOffset = 0x9fd };
#else
enum { flagOffset = 0x8fd };
#endif


extern char* data_ov004_02171010;
extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_0216583c  (semantic: SetFieldByteAndFlag101_0216583c)
extern "C" ARM int func_ov004_0216583c(void* obj) {
	*(unsigned char*)(data_ov004_02171010 + 0x1000 + flagOffset) = 1;
	func_ov011_021848a0(obj, 0x65);
	return 0;
}
