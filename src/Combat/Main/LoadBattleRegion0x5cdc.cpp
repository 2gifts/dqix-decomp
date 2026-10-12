#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

void SetByte0x5cdaAndClearField0xa(unsigned char*, unsigned char);

#if defined(jpn)
#define LoadBattleRegion0x5cdc func_020ab74c
extern "C" ARM int func_020ab74c(unsigned char* arg);
enum { kBattleRegionOffset = 0x5a7c };
#else
enum { kBattleRegionOffset = 0x5cdc };
#endif

// USA: func_020a9af8
ARM int LoadBattleRegion0x5cdc(unsigned char* arg) {
    GameState* bs = GameState::GetInstance();
    SetByte0x5cdaAndClearField0xa((unsigned char*)bs, arg[0]);
    memcpy((char*)bs + kBattleRegionOffset, arg + 4, 0x190);
    return 1;
}
