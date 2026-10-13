#include <globaldefs.h>
#include "System/NetworkIdentity.h"

extern "C" int func_ov031_0221156c(void* p);
int GetField1c_022115d0(void* obj);
void GenerateCrc8Table(unsigned char* table, unsigned int poly);
unsigned char Crc8Compute(const unsigned char* table, const unsigned char* data, unsigned int len);


// USA: func_ov031_022457e0  (semantic: ComputeChecksumPair_022457e0)
// KEEP-NAME: func_ov031_022457e0
// JPN: func_ov031_022463a8
extern "C" ARM unsigned long long func_ov031_022457e0(int unused, NetworkIdentity s) {
	if (!func_ov031_0221156c(&s)) return 0;
	int val = GetField1c_022115d0(&s);
	unsigned char table[256];
	struct Data022457e0 { int val; unsigned int magic; } data;
	data.val = val;
	data.magic = 0x5944514a;
	GenerateCrc8Table(table, 7);
	unsigned char crc = Crc8Compute(table, (unsigned char*)&data, 8);
	return ((unsigned long long)(crc & 0x7f) << 32) | (unsigned int)val;
}
