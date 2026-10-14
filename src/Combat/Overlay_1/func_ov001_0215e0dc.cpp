#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

extern "C" void _Z42SetField0x7cClearFields0x1ec0x1ee_0202e874Pht(unsigned char* obj, short val);
extern "C" float func_ov017_021d6110(void*);

// USA: func_ov001_0215e0dc
extern "C" ARM int func_ov001_0215e0dc(void* self) {
	unsigned char* obj = (unsigned char*)GetField0x3b0Value_020100bc(GameState::GetInstance());
	int degrees = (int)(4096.0f * func_ov017_021d6110(self));
	fix32_t angle = fix32ReduceAngle0To2Pi(FIX32_MULTIPLY(degrees, 0x47));
	_Z42SetField0x7cClearFields0x1ec0x1ee_0202e874Pht(obj, angle);
	return 1;
}
