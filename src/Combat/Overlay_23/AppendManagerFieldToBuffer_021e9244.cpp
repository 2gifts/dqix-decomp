#include <globaldefs.h>

void* GetGlobalInstance02109d8c(void);
extern "C" int func_ov017_021d60f4(void*);

struct S_9ffe0_9244 {
	char pad[0x68];
	short count;
	unsigned short items[0x32];
};
extern "C" void _Z28AppendHalfwordCapped0209ffe0P7S_9ffe0t(struct S_9ffe0_9244*, short);

// USA: func_ov023_021e9244  (semantic: AppendManagerFieldToBuffer_021e9244)
extern "C" ARM int func_ov023_021e9244(void* arg) {
	struct S_9ffe0_9244* s = (struct S_9ffe0_9244*)GetGlobalInstance02109d8c();
	if (s != NULL) {
		_Z28AppendHalfwordCapped0209ffe0P7S_9ffe0t(s, func_ov017_021d60f4(arg));
	}
	return 1;
}
