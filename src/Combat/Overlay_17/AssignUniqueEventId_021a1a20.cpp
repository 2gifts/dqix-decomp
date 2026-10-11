#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x100(GameState* battleStruct, int combatantId);
void* GetData02108ea8(void);
struct Entry0207d9bc;
struct Entry0207d9bc* FindEntryByHalfword(struct Entry0207d9bc* arr, unsigned short key);

extern unsigned char data_ov017_021d7654[4];

// JPN: func_ov017_021a24b0
// USA: func_ov017_021a1a20  (semantic: AssignUniqueEventId_021a1a20)
extern "C" ARM unsigned short func_ov017_021a1a20(void) {
#if defined(jpn)
 enum {regionalOffset0=0x1a6};
#else
 enum {regionalOffset0=0x1b2};
#endif
    GameState* bs = GameState::GetInstance();
    void* table = GetData02108ea8();
    int i;
retry:
    if (*(unsigned short*)(data_ov017_021d7654 + 2) > 0x7fff) {
        *(unsigned short*)(data_ov017_021d7654 + 2) = 0x7ff8;
    }
    for (i = 0; i < 4; i++) {
        GameObject* c = GetCombatantWithFlag0x100(bs, i);
        if (c != NULL) {
            unsigned short field = *(unsigned short*)((char*)c + regionalOffset0);
            if (*(unsigned short*)(data_ov017_021d7654 + 2) == field) {
                *(unsigned short*)(data_ov017_021d7654 + 2) = *(unsigned short*)(data_ov017_021d7654 + 2) + 1;
                goto retry;
            }
        }
    }
    if (FindEntryByHalfword((struct Entry0207d9bc*)table, *(unsigned short*)(data_ov017_021d7654 + 2)) != NULL) {
        *(unsigned short*)(data_ov017_021d7654 + 2) = *(unsigned short*)(data_ov017_021d7654 + 2) + 1;
        goto retry;
    }
    unsigned short result = *(unsigned short*)(data_ov017_021d7654 + 2);
    *(unsigned short*)(data_ov017_021d7654 + 2) = result + 1;
    return result;
}
