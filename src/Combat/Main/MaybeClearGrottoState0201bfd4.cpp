#include <globaldefs.h>
#include "World/ZoneLifecycle.h"
int IsInRange0201b588(int);
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"

extern unsigned short data_020fb3f0;

// USA: func_0201bfd4
ARM void MaybeClearGrottoState0201bfd4(Zone3D* zone) {
    GrottoStruct* grotto = GameState::GetInstance()->GetGrottoStruct();
    if (IsInRange0201b588((int)(data_020fb3f0)) != 0) return;
    if (grotto->unknown_0[4] != 0) {
        grotto->unknown_0[3] = 0;
        grotto->unknown_0[4] = 0;
    }
}
