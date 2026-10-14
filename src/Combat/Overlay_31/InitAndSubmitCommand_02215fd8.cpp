#include <globaldefs.h>
#include "System/Memory.h"

extern void* data_ov031_0224e5d8;

int GetBufferSize1da0_02215fcc(void);
void GenCrc16Table_020d1ba0(unsigned short* table, unsigned short poly);
int CallFunc020d4fa4Flag_020d4f8c(int a, int b, int c, int d);

// USA: func_ov031_02215fd8  (semantic: InitAndSubmitCommand_02215fd8)
extern "C" ARM int func_ov031_02215fd8(void* buf, int b, int c, int d) {
	if (b == 0) return -1;
	data_ov031_0224e5d8 = buf;
	int size = GetBufferSize1da0_02215fcc();
	VectorizedMemset(data_ov031_0224e5d8, 0, size);
	*(int*)((char*)data_ov031_0224e5d8 + 0x1000 + 0xa90) = 0;
	*(unsigned short*)((char*)data_ov031_0224e5d8 + 0x1a00 + 0x94) = 0;
	GenCrc16Table_020d1ba0((unsigned short*)((char*)data_ov031_0224e5d8 + 0x1a00 + 0x96), 0xa001);
	int r = CallFunc020d4fa4Flag_020d4f8c((int)data_ov031_0224e5d8, b, c, d);
	return (r == 2) ? 0 : r;
}
