#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
int GetState0209ca68(char* obj);
extern "C" void func_0209c530(void* p);
extern "C" void* func_02012fe4(void);
void ClearBitsInField4_0203b4e8(unsigned int* obj, unsigned int mask);
void ClearBitsInWord_0203b4b0(unsigned int* obj, unsigned int mask);

extern char data_02109bf4;

// USA: func_ov001_02156b20
ARM void ClearMultipleFieldBits_02156b20(void*) {
	unsigned int* obj = (unsigned int*)func_ov017_0218b5b0();
	if (GetState0209ca68(&data_02109bf4) == 2) {
		func_0209c530(&data_02109bf4);
	}
	unsigned short v = *(unsigned short*)func_02012fe4();
	if (v != 0x2710) {
		ClearBitsInField4_0203b4e8(obj, 0x4);
	}
	ClearBitsInField4_0203b4e8(obj, 0x40);
	ClearBitsInField4_0203b4e8(obj, 0x10);
	ClearBitsInField4_0203b4e8(obj, 0x2);
	ClearBitsInWord_0203b4b0(obj, 0x4);
}
