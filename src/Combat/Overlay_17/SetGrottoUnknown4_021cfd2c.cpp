#include <globaldefs.h>
#include "World/ZoneLifecycle.h"
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"

struct SomeObj021cfd2c {
	unsigned char pad[4];
	unsigned char field4;
};

extern "C" void* func_02012fe4(void);

// USA: func_ov017_021cfd2c
ARM void SetGrottoUnknown4_021cfd2c(int unused, SomeObj021cfd2c* obj) {
	GrottoStruct* grotto = GameState::GetInstance()->GetGrottoStruct();
	grotto->unknown_0[4] = (obj->field4 != 0) ? 1 : 0;
	MaybeClearGrottoState0201bfd4(static_cast<Zone3D*>(func_02012fe4()));
}
