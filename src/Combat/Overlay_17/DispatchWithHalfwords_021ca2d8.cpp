#include <globaldefs.h>
#include "Resource/GameResources.h"

struct SrcObj_021ca2d8 { unsigned char pad[4]; unsigned short h4; unsigned short h6; };

struct Battle_021b88d0;
extern "C" void func_ov017_021b88d0(Battle_021b88d0*, int combatantId, int key);

// USA: func_ov017_021ca2d8
ARM void DispatchWithHalfwords_021ca2d8(int unused0, SrcObj_021ca2d8* src, int unused2, unsigned char* ov) {
	Battle_021b88d0* battle = (Battle_021b88d0*)((GameResources*)ov)->unknown_ptr_3718;
	func_ov017_021b88d0(battle, src->h4, src->h6);
}
