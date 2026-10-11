#include <globaldefs.h>

extern "C" void func_020ca390(int a, void* buf, unsigned int size);
int CallFunc020d4fa4Zero(int a, int b, int c);
extern "C" void func_ov031_022359e0(void* obj);
int CopyToBattleContextBuffer(void* src);
unsigned short GetOwnerDataFortuneValue020d4be8(void);
extern "C" int func_ov031_022358b4(void);

extern char* data_ov031_02290cf8;

struct Block022357e8 { unsigned int v[17]; };
extern Block022357e8 data_ov031_02249204;

// USA: func_ov031_022357e8  (semantic: ResetContextAndFinalize_022357e8)
extern "C" ARM int func_ov031_022357e8(void) {
	func_020ca390(0, data_ov031_02290cf8 + 0x1300, 0x348);

	int r = CallFunc020d4fa4Zero((int)data_ov031_02290cf8, (int)func_ov031_022359e0, 3);
	if (r != 2) return 0;

	char* ip;
	do {
		ip = data_ov031_02290cf8;
		CopyToBattleContextBuffer(ip + 0x28c + 0x1400);
		ip = data_ov031_02290cf8;
	} while (*(unsigned short*)(ip + 0x1600 + 0x8c) != 2);

	*(Block022357e8*)(ip + 0x1648) = data_ov031_02249204;
	*(unsigned int*)(ip + 0x1648) = (unsigned int)(ip + 0xf00);

	*(unsigned short*)(data_ov031_02290cf8 + 0x1600 + 0x50) = GetOwnerDataFortuneValue020d4be8();

	return func_ov031_022358b4() != 0;
}
