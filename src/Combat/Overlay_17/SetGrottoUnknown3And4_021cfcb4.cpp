#include <globaldefs.h>

#if defined(jpn)
#define SetGrottoUnknown3And4_021cfcb4 func_ov017_021d0164
#endif
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"

struct SomeObj021cfcb4 {
	unsigned char pad[4];
	unsigned char field4;
};

// USA: func_ov017_021cfcb4
#if defined(jpn)
extern "C"
#endif
ARM void SetGrottoUnknown3And4_021cfcb4(int unused, SomeObj021cfcb4* obj) {
	GrottoStruct* grotto = GameState::GetInstance()->GetGrottoStruct();
	grotto->unknown_0[3] = (obj->field4 != 0) ? 1 : 0;
	if (obj->field4 != 0) {
		grotto->unknown_0[4] = 0;
	}
}
