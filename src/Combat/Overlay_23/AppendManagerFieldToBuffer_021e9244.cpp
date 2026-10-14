#include <globaldefs.h>

void* GetGlobalInstance02109d8c(void);
extern "C" int func_ov017_021d60f4(void*);

struct S_9ffe0_9244 {
	char pad[0x68];
	short count;
	unsigned short items[0x32];
};
struct S_9ffe0;
void AppendHalfwordCapped0209ffe0(S_9ffe0*, short);

// USA: func_ov023_021e9244  (semantic: AppendManagerFieldToBuffer_021e9244)
extern "C" ARM int func_ov023_021e9244(void* arg) {
	struct S_9ffe0_9244* s = (struct S_9ffe0_9244*)GetGlobalInstance02109d8c();
	if (s != NULL) {
		AppendHalfwordCapped0209ffe0((S_9ffe0*)s, func_ov017_021d60f4(arg));
	}
	return 1;
}
