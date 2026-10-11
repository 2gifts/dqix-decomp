#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void __clear(void* buf, int n);
extern unsigned char CopyOutRegion0x5718(char* obj, void* dst);
extern "C" void func_ov017_021d6134(void*, int);

#if defined(jpn)
struct Obj150_021ea46c { char pad[0x144]; char* ptr150; };
#else
struct Obj150_021ea46c { char pad[0x150]; char* ptr150; };
#endif

// JPN: func_ov023_021ea3d0
// USA: func_ov023_021ea46c
ARM int CountCombatantsByStatus1_021ea46c(void* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x8b8};
#else
 enum {regionalOffset0=0x950};
#endif
	GameState* bs = GameState::GetInstance();
	unsigned char buf[4];
	__clear(buf, 4);
	unsigned char len = CopyOutRegion0x5718((char*)bs, buf);
	int count = 0;
	for (int i = 0; i < len; i++) {
		unsigned char id = buf[i];
		struct Obj150_021ea46c* c = (struct Obj150_021ea46c*)GetCombatantWithFlag0x100(bs, id);
		if (c) {
			int val = *(int*)(c->ptr150 + regionalOffset0);
			if ((unsigned int)val <= 9) {
				switch (val) {
					case 1:
					case 4:
					case 7:
					case 9:
						count++;
						break;
				}
			}
		}
	}
	func_ov017_021d6134(obj, count);
	return 1;
}
