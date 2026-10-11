#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
void* GetField6b0_021b8470(void* obj);
void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Mid021cbdcc {
	unsigned short field4;
	unsigned char bytes[8];
};

struct LocalEvt021cbdcc {
	unsigned char tag;
	unsigned char pad0[3];
	Mid021cbdcc mid;
	unsigned char pad1[6];
};

// JPN: func_ov017_021cc27c
// USA: func_ov017_021cbdcc  (semantic: EnqueueEventFromWordArray_021cbdcc)
extern "C" ARM void func_ov017_021cbdcc(void) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
	void* evtBuf = GetData02100044();
	unsigned char* base = (unsigned char*)func_ov017_0218b5b0() + 0x3000;
	void* h = *(void**)(base + regionalOffset0);
	void* r = GetField6b0_021b8470(h);
	if (!r) return;

	LocalEvt021cbdcc buf;
	buf.tag = 0x7e;
	void* ptr2 = *(void**)((char*)r + 0x8000 + 0xe18);
	unsigned short val = *(unsigned short*)((char*)ptr2 + 8);

	Mid021cbdcc* mid = &buf.mid;
	unsigned char* p = mid->bytes;
	int i = 0;
	mid->field4 = val;
	for (; i < 8; p++) {
		*p = *(unsigned int*)((char*)r + 0x8000 + 0xde0 + i * 4);
		i++;
	}
	func_0205e330(evtBuf, &buf, 0);
}
