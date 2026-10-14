#include <globaldefs.h>

extern "C" int func_ov031_0221b780(int a0, int a1, int a2);
int CheckAndCompare_0221b7fc(int a, int b, int c, int d);
extern "C" int func_ov031_0221b848(void);
unsigned short Crc16Compute_020d1cc8(const unsigned short* table, const unsigned char* data, unsigned int len);

struct Data0224e6a0 {
	unsigned char pad[8];
	int field8;
};
extern Data0224e6a0 data_ov031_0224e6a0;

// USA: func_ov031_0221b0ac  (semantic: VerifyAndRetryAll_0221b0ac)
extern "C" ARM int func_ov031_0221b0ac(int obj) {
	int i = 0;
	int base5 = data_ov031_0224e6a0.field8;
	int base8 = obj;

	do {
		unsigned short crc = Crc16Compute_020d1cc8((const unsigned short*)(obj + 0x500), (const unsigned char*)base8, 0xfe);
		*(unsigned short*)(obj + (i << 8) + 0xfe) = crc;
		do {
			func_ov031_0221b780(base5, 0x100, base8);
		} while (CheckAndCompare_0221b7fc(base8, base5, 0x100, obj + 0x400) == 0);
		i++;
		base8 += 0x100;
		base5 += 0x100;
	} while (i < 4);

	return func_ov031_0221b848() != 0;
}
