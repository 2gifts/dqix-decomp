#include <globaldefs.h>

void* GetGlobalInstance02109d8c(void);
extern "C" int func_ov017_021d60f4(void*);

struct S_9ffe0 {
	char pad[0x68];
	short count;
	unsigned short items[0x32];
};
extern "C" void _Z28AppendHalfwordCapped0209ffe0P7S_9ffe0t(struct S_9ffe0*, short);

// USA: func_ov023_021e915c
ARM int AppendManagerFieldToBuffer_021e915c(void* arg) {
	struct S_9ffe0* s = (struct S_9ffe0*)GetGlobalInstance02109d8c();
	if (s != NULL) {
		_Z28AppendHalfwordCapped0209ffe0P7S_9ffe0t(s, func_ov017_021d60f4(arg));
	}
	return 1;
}
