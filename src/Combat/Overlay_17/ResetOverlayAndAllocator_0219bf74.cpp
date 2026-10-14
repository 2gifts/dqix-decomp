#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void* func_ov017_0218b5b0(void);
extern "C" void* func_02012fe4(void);
void ResetBigStruct02013750(void* obj, int flag);
void SetBitsInField4_0203b4d8(unsigned int* obj, unsigned int mask);
void SetBitsInWord_0203b4a0(unsigned int* obj, unsigned int mask);

// USA: func_ov017_0219bf74
ARM void* ResetOverlayAndAllocator_0219bf74(void) {
	unsigned char* self = (unsigned char*)func_ov017_0218b5b0();
	ResetBigStruct02013750(func_02012fe4(), 1);
	((SafeAllocator*)(self + 0x38))->Reset();
	SetBitsInField4_0203b4d8((unsigned int*)self, 2);
	SetBitsInWord_0203b4a0((unsigned int*)self, 4);
	return self + 0x38;
}
