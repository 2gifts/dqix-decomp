#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub8e18 {
	unsigned char pad[8];
	unsigned short val;
};

// USA: func_ov017_021c66e8
extern "C" ARM void func_ov017_021c66e8(char* self) {
	void* p = GetData02100044_0202ae24();
	unsigned char buf[0x14];
	buf[0] = 0x41;
	unsigned char* b = buf + 4;
	Sub8e18* sub = *(Sub8e18**)(self + 0x8e18);
	*(unsigned short*)(b + 4) = sub->val;
	unsigned char* base = (unsigned char*)(self + 0x81b0);
	for (int i = 0; i < (int)(((unsigned int)base[1] << 24) >> 30); i++) {
		unsigned char* entry = base + i * 8;
		b[0xa] = i;
		*(unsigned short*)(b + 6) = *(unsigned short*)(entry + 0x4e);
		b[8] = entry[0x4d];
		b[9] = entry[0x4c];
		*(int*)(b + 0) = *(int*)(entry + 0x50);
		func_0205e330(p, buf, 0);
	}
}
