#include <globaldefs.h>

void GenCrc32Table_020d1c24(unsigned int* table, unsigned int poly);
unsigned int Crc32Compute_020d1cf0(const unsigned int* table, const unsigned char* data, unsigned int len);

// USA: func_ov031_02211720  (semantic: ComputeCrc32_02211720)
extern "C" ARM unsigned int func_ov031_02211720(const unsigned char* data) {
	unsigned int table[0x100];
	GenCrc32Table_020d1c24(table, 0xedb88320);
	return Crc32Compute_020d1cf0(table, data, 0x3c);
}
