#if defined(jpn)
#define R(j,u) (j)
#define data_ov015_02193d14 data_ov015_02194844
#define data_ov015_02193d2c data_ov015_0219485c
#define data_ov015_02193d38 data_ov015_02194868
#define data_ov027_021dd8e0 data_ov027_021de1a0
#define func_ov003_021594c4 func_ov003_0215a990
#define func_ov003_0215a740 func_ov003_0215bbc0
#define func_ov014_0218854c func_ov014_0218942c
#define func_ov014_021885bc func_ov014_0218948c
#define func_ov015_0219050c func_ov015_021910b0
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern void *data_ov027_021e33ec;
extern unsigned char data_ov027_021dd8e0;

extern "C" void VectorizedMemset(void *dst, int val, int size);
extern "C" void VectorizedInvertedMemcpy(const void *src, void *dst, int size);

struct InputDD638_021d9704 {
	unsigned char type;
	unsigned short field2;
	unsigned short field4;
};

extern "C" void *func_ov027_021dd638(struct InputDD638_021d9704 *in, void *out);
extern "C" int func_ov027_021dab00(int a, int b, void *c);

#pragma optimize_for_size off
// USA: func_ov027_021d9704  (semantic: PickAndRelayRandomSlot_021d9704)
extern "C" ARM int func_ov027_021d9704(void) {
	unsigned char buf[16];
	signed char found = -1;
	unsigned short mask = 0;
	unsigned char seed;
	unsigned short i;
	unsigned char attempts;
	char *base;

	VectorizedMemset(buf, 0, 16);

	base = (char *)data_ov027_021e33ec;

	i = 1;
	do {
		if (*(int *)(base + 0x1000 + i * 4 + 0x4e4) == 5) {
			signed char idx = *(signed char *)(base + 0x1500 + i + 0x25);
			buf[idx]++;
		}
		i++;
	} while (i <= 15);

	seed = data_ov027_021dd8e0;
	attempts = 0;
	do {
		seed = (seed + 1) % 16;
		if (*(unsigned char *)(base + seed * 0x5d4 + 0x1000 + 0xd52) != 0 && buf[seed] != 0) {
			found = (signed char)seed;
			break;
		}
		attempts++;
	} while (attempts < 16);

	if (found == -1) {
		return 0x15;
	}

	data_ov027_021dd8e0 = found;

	i = 1;
	do {
		if (*(int *)(base + 0x1000 + i * 4 + 0x4e4) == 5) {
			if (found == *(signed char *)(base + 0x1500 + i + 0x25)) {
				mask |= (1 << i);
			}
		}
		i++;
	} while (i <= 15);

	{
		struct InputDD638_021d9704 tmp;
		void *res;

		tmp.type = 3;
		tmp.field2 = (unsigned short)found;
		res = func_ov027_021dd638(&tmp, base);
		if (res != NULL) {
			VectorizedInvertedMemcpy((char *)data_ov027_021e33ec + 0x1400 + 0x388 + found * 0x5d4, res, 0xe4);
		}
	}

	return func_ov027_021dab00(0xea, mask, data_ov027_021e33ec);
}
