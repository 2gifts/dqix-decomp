#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct InputDD638_021d96c4 {
	unsigned char type;
	unsigned short field2;
	unsigned short field4;
};

extern "C" void *func_ov027_021dd638(struct InputDD638_021d96c4 *in, void *out);
extern "C" void func_ov027_021dab00(int a, int b, void *c);

struct RootStruct021d96c4 {
	void *field0;
};

extern struct RootStruct021d96c4 data_ov027_021e33ec;

// USA: func_ov027_021d96c4
ARM void SerializeEventByte_021d96c4(unsigned char type, int value) {
	struct InputDD638_021d96c4 tmp;
	tmp.type = type;
	func_ov027_021dd638(&tmp, data_ov027_021e33ec.field0);
	func_ov027_021dab00(6, value, data_ov027_021e33ec.field0);
}
