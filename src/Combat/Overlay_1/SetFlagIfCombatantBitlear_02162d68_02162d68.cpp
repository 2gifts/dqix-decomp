#include <globaldefs.h>
#include "GameState/GameState.h"

int GetFieldAt0x150_02053c6c(unsigned char* obj);
extern "C" void func_ov017_021d6134(void*, int);

struct Sub0x150_02162d68 {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

// USA: func_ov001_02162d68
ARM int SetFlagIfCombatantBitlear_02162d68_02162d68(void* ctx) {
    GameObject* c = GameState::GetInstance()->GetPartyMemberByIndex(0);
    if (c == NULL) {
        return 0;
    }
    struct Sub0x150_02162d68* sub = (struct Sub0x150_02162d68*)GetFieldAt0x150_02053c6c((unsigned char*)c);
    func_ov017_021d6134(ctx, sub->bit0 == 0);
    return 1;
}
