#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/FieldActorState.h"

typedef void (Obj02076b58::*PMF02076b58)();

extern PMF02076b58 data_020e892c[];

extern "C" void func_020332ac(void* obj);
extern "C" void func_020790ac(void* obj);

// USA: func_02076b58
ARM void TickActorAndDispatchPhase02076b58(Obj02076b58* obj) {
    GameState* battleStruct = GameState::GetInstance();
    func_020332ac(obj);
    obj->elapsedTime += battleStruct->GetEffectiveDeltaTime();
    if (obj->phase != 0) {
        obj->phaseElapsedTime += battleStruct->GetEffectiveDeltaTime();
    }
    obj->tickCount += 1;
    func_020790ac(obj);
    (obj->*data_020e892c[obj->phase])();
}
