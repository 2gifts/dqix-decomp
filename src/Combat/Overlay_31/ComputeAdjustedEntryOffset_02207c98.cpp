#include <globaldefs.h>

int RegisterSlotA020cf0fc(int a);
int RegisterSlotB020cf1a8(int a);
long long ComputeEntryByteOffset_020cf990(int arg0, unsigned char* arg1);

// USA: func_ov031_02207c98  (semantic: ComputeAdjustedEntryOffset_02207c98)
#pragma optimize_for_size off
extern "C" ARM int func_ov031_02207c98(void) {
	char buf[0x1c];
	RegisterSlotA020cf0fc((int)(buf + 0xc));
	RegisterSlotB020cf1a8((int)buf);
	return (int)ComputeEntryByteOffset_020cf990((int)(buf + sizeof(buf) - 0x10), (unsigned char*)buf) + 0x386d4380;
}
