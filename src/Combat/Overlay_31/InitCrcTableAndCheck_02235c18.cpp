#include <globaldefs.h>

extern "C" void *func_ov031_0223cf4c(unsigned int len, int align);
void GenCrc16Table_020d1ba0(unsigned short *table, unsigned short poly);
int Check_0221aff8_0221aff8(int a);

extern void *data_ov031_02290cfc;

// USA: func_ov031_02235c18  (semantic: InitCrcTableAndCheck_02235c18)
extern "C" ARM void func_ov031_02235c18(void) {
	void *p = func_ov031_0223cf4c(0x6f8, 0x20);
	char *inner = (char*)p + 0xf8;
	data_ov031_02290cfc = p;
	GenCrc16Table_020d1ba0((unsigned short*)(inner + 0x400), 0xa001);
	Check_0221aff8_0221aff8((int)data_ov031_02290cfc);
}
