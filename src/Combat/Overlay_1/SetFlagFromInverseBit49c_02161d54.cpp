#include <globaldefs.h>
#include "GameState/GameState.h"

int GetFieldAt0x150_02053c6c(unsigned char* obj);

struct Sub0x150_02161d54 {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

extern "C" int func_ov017_021d6134(void* obj, int flag);

// USA: func_ov001_02161d54
ARM int SetFlagFromInverseBit49c_02161d54(void* obj) {
    GameObject* combatant = GameState::GetInstance()->GetProtagonist();
    struct Sub0x150_02161d54* sub = (struct Sub0x150_02161d54*)GetFieldAt0x150_02053c6c((unsigned char*)combatant);
    int flag = sub->bit0 ? 0 : 1;
    func_ov017_021d6134(obj, flag);
    return 1;
}
