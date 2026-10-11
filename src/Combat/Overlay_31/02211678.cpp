#include <globaldefs.h>

extern "C" void func_020c9b10(unsigned int* buffer);

struct S02211678 {
	unsigned int field0;
	unsigned int field4;
	unsigned int field8;
};

// USA: func_ov031_02211678
extern "C" ARM void func_ov031_02211678(S02211678* p, unsigned int a, unsigned int b) {
	unsigned int buf[8];
	unsigned int i;
	unsigned long long v;

	func_020c9b10(buf);
	i = 1;
	do {
		buf[i] = buf[i] ^ *(unsigned int*)((char*)&buf[i] - 4);
	} while (++i < 8);
	v = (unsigned long long)buf[7];
	v *= 0x5d588b656c078965ULL;
	p->field4 = (unsigned int)(a & 0xFFFFFFFFull);
	p->field0 = (unsigned int)(b & 0xFFFFFFFFull);
	v += 0x00269ec3ULL;
	p->field8 = (unsigned int)(v >> 32);
}
