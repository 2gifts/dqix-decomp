#include <globaldefs.h>

void* LookupValue0220510c(int key);

struct Result02205134 {
	void* a;
	void* b;
	int zero;
	signed char byte0xc;
	unsigned char byte0xd;
};

// USA: func_ov031_02205134
ARM void* SetLookupFields_02205134(void* a, void* b, int c) {
	Result02205134* p = (Result02205134*)LookupValue0220510c(c);
	if (p == NULL) return p;
	p->a = a;
	p->b = b;
	p->zero = 0;
	p->byte0xc = *((signed char*)b + 0x73);
	p->byte0xd = (unsigned char)c;
	return p;
}
