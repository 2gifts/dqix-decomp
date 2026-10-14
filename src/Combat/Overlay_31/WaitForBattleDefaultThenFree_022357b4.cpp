#include <globaldefs.h>

#if defined(jpn)
extern "C" char* data_ov031_02290cf8;
namespace DuplicatePool {
    extern "C" char* data_ov031_02290cf8;
}
#else
extern char* data_ov031_02290cf8;
#endif
int GetSharedHalfwordOrBattleDefault_020d4aa8(void);
extern "C" unsigned int func_ov031_0223cf70(void** a);

// USA: func_ov031_022357b4  (semantic: WaitForBattleDefaultThenFree_022357b4)
extern "C" ARM void func_ov031_022357b4(void) {
	if (data_ov031_02290cf8 == NULL) return;
	while (GetSharedHalfwordOrBattleDefault_020d4aa8() != 0x8000) {}
#if defined(jpn)
	func_ov031_0223cf70((void**)&DuplicatePool::data_ov031_02290cf8);
#else
	func_ov031_0223cf70((void**)0x02290cf8);
#endif
}
