#include <globaldefs.h>

struct Entry021820fc;
void ClearEntry021820fc(struct Entry021820fc* obj);

// USA: func_ov000_02182a44
ARM void ZeroFieldsAt0x6e8_ov000_02182a44(void* obj) {
	ClearEntry021820fc((struct Entry021820fc*)((char*)obj + 0x2e8 + 0x400));
}
