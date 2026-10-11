#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
struct FieldPtrObj_021ea6bc { char pad[0x144]; unsigned char *tbl; };
#else
struct FieldPtrObj_021ea6bc { char pad[0x150]; unsigned char *tbl; };
#endif

extern "C" int func_ov017_021d60f4(void*);
extern "C" int func_ov023_021e8f28(int);
extern "C" void func_ov017_021d6134(void*, int);

// JPN: func_ov023_021ea620
// USA: func_ov023_021ea6bc
ARM int SumTableBytes_021ea6bc(void *obj) {
	GameState::GetInstance();
	struct FieldPtrObj_021ea6bc *p = (struct FieldPtrObj_021ea6bc*)func_ov023_021e8f28(func_ov017_021d60f4(obj));
	if (!p) return 0;
	int sum = 0;
	for (int i = 0; i < 13; i++) {
		unsigned char *base = p->tbl + (i & 0xff);
		sum += base[0x186];
	}
	func_ov017_021d6134((char*)obj + 8, sum);
	return 1;
}
