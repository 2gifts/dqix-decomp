#include <globaldefs.h>

struct Outer020bc158;
void SetInnerByte0x41(Outer020bc158*, unsigned char);
extern void* data_ov031_02290d00;

// USA: func_ov031_0223689c
extern "C" ARM void func_ov031_0223689c(unsigned char val) {
	SetInnerByte0x41((Outer020bc158*)((char*)data_ov031_02290d00 + 0x94), val);
}
