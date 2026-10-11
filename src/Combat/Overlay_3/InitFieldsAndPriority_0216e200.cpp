#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue5C_28 = 0x28 };
#else
enum { kRegionValue5C_28 = 0x5c };
#endif


int GetGlobalField0x1c020421a0(void);
extern "C" void func_ov003_02170898(void* obj);
extern "C" void func_ov003_02170688(void* obj);
extern "C" void func_02074af4(void* p);
extern "C" int func_ov017_0218b5b0(void);
unsigned int GetField4(unsigned int* obj);
void Set3DClearColor(int color, int alpha, int depth, int polygonId, int fogEnable);

// USA: func_ov003_0216e200  (semantic: InitFieldsAndPriority_0216e200)
// JPN: func_ov003_0216da64
extern "C" ARM void func_ov003_0216e200(char* obj) {
	if (*(signed char*)(obj + 0x2) != 0) return;

	int baseAddr = GetGlobalField0x1c020421a0();
	*(int*)(obj + 0x18) = *(int*)(baseAddr + kRegionValue5C_28);
	func_ov003_02170898(obj);
	func_ov003_02170688(obj);
	func_02074af4(obj + 0x48);

	volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
	*(int*)(obj + 0x5c) = (*dispcnt & 0x1f00) >> 8;
	*dispcnt = (*dispcnt & ~0x1f00) | 0x700;

	*(int*)(obj + 0x174) = GetField4((unsigned int*)func_ov017_0218b5b0());
	Set3DClearColor(0, 0, 0x7fff, 0, 0);
	*(unsigned char*)(obj + 0x1) = 1;
	*(unsigned char*)(obj + 0x2) = 0;
	*(int*)(obj + 0x16c) = 0;
}
