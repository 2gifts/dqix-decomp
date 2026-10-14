#include <globaldefs.h>

void SaveAndClearDisplayMode_020c3898(void);
int TailCallDispatchType18_0223dffc(void);
int DispatchIfEquals1_020cedc0(int a);
extern "C" void func_ov031_0223d06c(void);
void DisableImeAndSetHandler_0223d7f4(void);
extern "C" void func_ov031_0223684c(void);
extern "C" void func_ov031_0223b870(void);
extern "C" void func_ov031_0223da0c(void);
extern "C" void func_ov031_0223c40c(void);
int TailCallFreeGlobal02290d34_0223c040(void);
extern "C" void func_ov031_0223b4d4(void);
extern "C" void func_ov031_0223e120(void);
void DestroyMainAllocator0223cedc(void);
extern "C" void func_ov031_0223de5c(void);

// USA: func_ov031_02227468  (semantic: ShutdownAndDispatchAll_02227468)
extern "C" ARM void func_ov031_02227468(void) {
	SaveAndClearDisplayMode_020c3898();
	volatile unsigned int* dispcntB = (volatile unsigned int*)0x4001000;
	*dispcntB &= ~0x10000;
	TailCallDispatchType18_0223dffc();
	DispatchIfEquals1_020cedc0(1);
	func_ov031_0223d06c();
	DisableImeAndSetHandler_0223d7f4();
	func_ov031_0223684c();
	func_ov031_0223b870();
	func_ov031_0223da0c();
	func_ov031_0223c40c();
	TailCallFreeGlobal02290d34_0223c040();
	func_ov031_0223b4d4();
	func_ov031_0223e120();
	DestroyMainAllocator0223cedc();
	func_ov031_0223de5c();
}
