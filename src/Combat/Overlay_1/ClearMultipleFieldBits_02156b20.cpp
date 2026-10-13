#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
int GetState0209ca68(char* obj);
extern "C" void func_0209c530(void* p);
extern "C" void* func_02012fe4(void);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);
void ClearBitsInWord(unsigned int* obj, unsigned int mask);

extern char data_02109bf4;

// USA: func_ov001_02156b20
ARM void ClearMultipleFieldBits_02156b20(void*) {
	unsigned int* obj = (unsigned int*)func_ov017_0218b5b0();
	if (GetState0209ca68(&data_02109bf4) == 2) {
		func_0209c530(&data_02109bf4);
	}
	unsigned short v = *(unsigned short*)func_02012fe4();
	if (v != 0x2710) {
		ClearBitsInField4(obj, 0x4);
	}
	ClearBitsInField4(obj, 0x40);
	ClearBitsInField4(obj, 0x10);
	ClearBitsInField4(obj, 0x2);
	ClearBitsInWord(obj, 0x4);
}
