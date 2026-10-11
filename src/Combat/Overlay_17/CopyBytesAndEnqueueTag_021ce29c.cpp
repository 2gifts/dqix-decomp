#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021ce29c {
	unsigned char tag;
	char pad1[3];
	signed char data[4];
	char pad2[12];
};

// JPN: func_ov017_021ce744
// USA: func_ov017_021ce29c  (semantic: CopyBytesAndEnqueueTag_021ce29c)
extern "C" ARM void func_ov017_021ce29c(void) {
#if defined(jpn)
 enum {regionalOffset0=0x910};
#else
 enum {regionalOffset0=0xb30};
#endif
	void* p = GetData02100044();
	int raw = func_ov017_0218b5b0();
	unsigned char* src = *(unsigned char**)((char*)raw + 0x3000 + regionalOffset0);

	struct LocalEvt021ce29c buf;
	buf.tag = 0x2e;
	signed char* dst = buf.data;
	for (int i = 0; i < 4; i++) {
		dst[i] = *(unsigned char*)(src + i + 0x1b);
	}
	func_0205e330(p, &buf, 0);
}
