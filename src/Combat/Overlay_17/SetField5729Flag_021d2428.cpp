#include <globaldefs.h>
#include "GameState/GameState.h"

void SetField0x5729Value_0201075c(char* obj, unsigned char value);

// USA: func_ov017_021d2428
ARM void SetField5729Flag_021d2428() {
	SetField0x5729Value_0201075c((char*)GameState::GetInstance(), 1);
}
