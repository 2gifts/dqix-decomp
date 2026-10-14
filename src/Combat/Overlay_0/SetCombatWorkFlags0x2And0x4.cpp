#include <globaldefs.h>

void SetCombatWorkFlags0x55f4_ov000_02160fa8(void* work, int mask);

// USA: func_ov000_02166e3c
ARM void SetCombatWorkFlags0x2And0x4_ov000_02166e3c(void* work) {
	SetCombatWorkFlags0x55f4_ov000_02160fa8(work, 2);
	SetCombatWorkFlags0x55f4_ov000_02160fa8(work, 4);
}
