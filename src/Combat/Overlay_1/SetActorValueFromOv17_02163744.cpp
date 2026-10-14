#include <globaldefs.h>

extern "C" unsigned short func_ov017_021d60f4(int a);

struct Struct0209c830 {
	char pad[0xc9];
	unsigned char active;
	char pad2[4];
	unsigned short value;
};
void SetValueAndActivate0209c830(Struct0209c830* p, int value);

extern struct Struct0209c830 data_02109bf4;

// USA: func_ov001_02163744
ARM int SetActorValueFromOv17_02163744(int a) {
	SetValueAndActivate0209c830(&data_02109bf4, func_ov017_021d60f4(a));
	return 1;
}
