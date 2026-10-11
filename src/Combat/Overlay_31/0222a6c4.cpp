#include <globaldefs.h>

extern "C" void* func_ov031_0223c560(int a, int b);
extern "C" void func_ov031_0222a794(void);
extern "C" void func_020ca390(int a, void* buf, unsigned int size);
extern "C" int func_020ca3b8(int dst, int src, int size);
extern "C" void func_ov031_0223c980(void* obj, int a, int b, int c, int d, int e, int f, void* g);
extern "C" void func_ov031_02237b2c(int, int, int, int, int);
extern "C" void func_ov031_0222a814(void);
extern "C" ARM void _Z24SetFlag02290c78_0222aa88v();
extern unsigned char data_ov031_02290c78[2];
extern "C" extern void _Z26SetField_022274c0_022274c0i(int v);
extern "C" extern void _Z23SetOffset1e298_0222785ci(int v);
extern "C" ARM char* _Z23GetOffset1e280_02227880v(void);
extern "C" ARM void _Z30SetFlagIfMatchesElem0_0223caecPv(void* ptr);

// USA: func_ov031_0222a6c4  (semantic: InitUiRowAndSetHandler_0222a6c4)
// KEEP-NAME: func_ov031_0222a6c4 == symbols.txt func_ov031_0222a6c4 addr:0x0222a6c4
extern "C" ARM void func_ov031_0222a6c4(void) {
	char* base = _Z23GetOffset1e280_02227880v();
	void* obj = func_ov031_0223c560(0, 0);
	data_ov031_02290c78[1] = 0;
	data_ov031_02290c78[0] = 0;
	func_ov031_0222a794();
	unsigned char buf[0x16];
	func_020ca390(0, &buf[0], 0x16);
	unsigned int n = *(unsigned char*)&base[1];
	func_020ca3b8((int)&base[2], (int)&buf[0], n * 2);
	func_ov031_0223c980(obj, 8, 0x35, 0xf0, 0x1c, 2, 0x480, &buf[0]);
	_Z30SetFlagIfMatchesElem0_0223caecPv(obj);
	_Z23SetOffset1e298_0222785ci((int)_Z24SetFlag02290c78_0222aa88v);
	func_ov031_02237b2c(0x1d, 4, 0, -1, 0);
	_Z26SetField_022274c0_022274c0i((int)func_ov031_0222a814);
}
