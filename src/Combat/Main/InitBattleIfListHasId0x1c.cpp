#include <globaldefs.h>
#include "Resource/GameResources.h"

struct ListHead02046b60;
struct List02046a8c;
struct Node02046a8c;
int ListContainsId(struct ListHead02046b60* list, int id);
extern "C" void func_02046a8c(List02046a8c* list, Node02046a8c* node);
void InitBattleAndControllerState(void* param);

// USA: func_020d9a58
ARM void InitBattleIfListHasId0x1c(void* param) {
    GameResources* resources = func_ov017_0218b5b0();
    struct ListHead02046b60* list = static_cast<ListHead02046b60*>(resources->unknown_ptr_array_36fc[0]);
    if (ListContainsId(list, 0x1c)) {
        func_02046a8c(reinterpret_cast<List02046a8c*>(list), static_cast<Node02046a8c*>(resources->unknown_ptr_array_3afc[6]));
        func_02046a8c(reinterpret_cast<List02046a8c*>(list), static_cast<Node02046a8c*>(resources->unknown_ptr_array_36fc[4]));
    }
    InitBattleAndControllerState(param);
}
