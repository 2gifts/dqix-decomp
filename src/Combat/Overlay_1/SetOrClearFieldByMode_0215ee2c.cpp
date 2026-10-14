#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
extern "C" int func_ov017_021d60f4(void*);
void SetBitsInField4_0203b4d8(unsigned int*, unsigned int);
void ClearBitsInField4_0203b4e8(unsigned int*, unsigned int);

// USA: func_ov001_0215ee2c
ARM int SetOrClearFieldByMode_0215ee2c(void* self) {
	int obj = func_ov017_0218b5b0();
	if (obj == 0) {
		return 0;
	}
	int a = func_ov017_021d60f4(self);
	int b = func_ov017_021d60f4((char*)self + 0x8);
	switch (a) {
	case 0:
		if (b != 0) {
			ClearBitsInField4_0203b4e8((unsigned int*)obj, 8);
		} else {
			SetBitsInField4_0203b4d8((unsigned int*)obj, 8);
		}
		break;
	case 1:
		if (b != 0) {
			ClearBitsInField4_0203b4e8((unsigned int*)obj, 0x400);
		} else {
			SetBitsInField4_0203b4d8((unsigned int*)obj, 0x400);
		}
		break;
	}
	return 1;
}
