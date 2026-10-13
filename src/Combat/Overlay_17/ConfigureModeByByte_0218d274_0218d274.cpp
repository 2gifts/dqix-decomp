#include <globaldefs.h>
#include "GameState/GameState.h"

unsigned char GetByte0x4(char* obj);
extern "C" void MapVRAMBanksToTextureImage(int a);
void ConfigurePairMode020bb48c(unsigned int mode, int installHandlers);
void InitGlobalStateAndInstallHandlers020bb780(void* value, int installHandlers);

// USA: func_ov017_0218d274
ARM void ConfigureModeByByte_0218d274_0218d274(void* controller) {
	if (GetByte0x4((char*)GameState::GetInstance()) == 6) {
		MapVRAMBanksToTextureImage(3);
		ConfigurePairMode020bb48c(2, 1);
	} else {
		MapVRAMBanksToTextureImage(0xf);
		ConfigurePairMode020bb48c(4, 1);
	}
	InitGlobalStateAndInstallHandlers020bb780((void*)0x4000, 1);
}
