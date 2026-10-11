#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "GameState/GameState.h"


void* GetField0x3f8Address(GameState* battleStruct);
void InitFieldsFromCombatant_0219bcac(unsigned char flag);
int* GetGlobal02109030(void);
extern "C" void func_02094030(int*, short, short, signed char);

// JPN: func_ov017_0219c9f4
// USA: func_ov017_0219bf04  (semantic: InitAndDispatchField67_0219bf04)
extern "C" ARM void func_ov017_0219bf04(unsigned char flag, int mode) {
#if defined(jpn)
 enum {regionalOffset0=0x4200, regionalOffset1=0x2};
#else
 enum {regionalOffset0=0x4400, regionalOffset1=0xb2};
#endif
	GameState* battleStruct = GameState::GetInstance();
	GameResources* ov = func_ov017_0218b5b0();
	InitFieldsFromCombatant_0219bcac(flag);
	char* obj = (char*)GetField0x3f8Address(battleStruct);
	obj[0x6e] = 1;
	obj[0xa] = 0;
	obj[0x67] = 1;
	if (mode == 0) {
		*(short*)((char*)ov + regionalOffset0 + regionalOffset1) = 0x4e23;
		return;
	}
	int* g = GetGlobal02109030();
	func_02094030(g, 0x4e23, -1, 0);
}
