#include <globaldefs.h>

extern "C" void* func_0202ae18(void);
void SetBitsInWord(unsigned int* obj, unsigned int mask);
struct SearchStruct;
void ClearSearchFlagBit0202c600(struct SearchStruct* obj, int value);
void* GetData02100044(void);
extern "C" void func_0205e22c(void);

struct S02195618 { unsigned char pad[
#if defined(jpn)
0x40c2
#else
0x42e2
#endif
]; unsigned char flag; };

// USA: func_ov017_02195618
ARM void SetFlagAndCleanup_02195618(unsigned char* obj) {
	void* p = func_0202ae18();
	SetBitsInWord((unsigned int*)obj, 2);
	((S02195618*)obj)->flag = 1;
	ClearSearchFlagBit0202c600((struct SearchStruct*)p, 0);
	GetData02100044();
	func_0205e22c();
}
