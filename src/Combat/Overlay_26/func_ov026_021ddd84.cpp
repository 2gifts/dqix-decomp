#include <globaldefs.h>
#include "Resource/GameResources.h"

struct GameState;
struct BattleWork;
struct BattleState;
struct PartyState;

extern "C" GameState* _ZN9GameState11GetInstanceEv();
extern "C" void* func_0202ae18(GameState* gs);
void* GetData02108ea8();
extern "C" int func_ov017_02195658(GameResources* res);
extern "C" void func_ov026_021dbd1c(BattleWork* self, int index, unsigned char flag);

// USA: func_ov026_021ddd84
extern "C" ARM int func_ov026_021ddd84(GameResources* res, BattleWork* self, BattleState* battle, PartyState* party, void* list, unsigned char* turnFlag, unsigned char flag) {
    func_0202ae18(_ZN9GameState11GetInstanceEv());
    GetData02108ea8();
    int index = func_ov017_02195658(res);
    if (index <= -1) {
        return 0;
    }
    func_ov026_021dbd1c(self, index, flag);
    return 1;
}
