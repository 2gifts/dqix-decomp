#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetData02108ea8_0207d78c(void);
struct Entry0207d9bc;
struct Entry0207d9bc* FindEntryByHalfword(struct Entry0207d9bc* arr, unsigned short key);

extern unsigned char data_ov017_021d7654[4];

// USA: func_ov017_021a1944  (semantic: AssignUniqueEventId_021a1944)
extern "C" ARM unsigned short func_ov017_021a1944(void) {
    GameState* bs = GameState::GetInstance();
    void* table = GetData02108ea8_0207d78c();
    int i, j;
retry:
    if (*(unsigned short*)(data_ov017_021d7654) > 0x7ff7) {
        *(unsigned short*)(data_ov017_021d7654) = 1;
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 0xc; j++) {
            GameObject* c = bs->GetMaybeFieldMonsterByIndex(i * 0xc + 0x70 + j);
            if (c != NULL) {
                unsigned short field = *(unsigned short*)((char*)c + 0x16a);
                if (*(unsigned short*)(data_ov017_021d7654) == field) {
                    *(unsigned short*)(data_ov017_021d7654) = *(unsigned short*)(data_ov017_021d7654) + 1;
                    goto retry;
                }
            }
        }
    }
    if (FindEntryByHalfword((struct Entry0207d9bc*)table, *(unsigned short*)(data_ov017_021d7654)) != NULL) {
        *(unsigned short*)(data_ov017_021d7654) = *(unsigned short*)(data_ov017_021d7654) + 1;
        goto retry;
    }
    unsigned short result = *(unsigned short*)(data_ov017_021d7654);
    *(unsigned short*)(data_ov017_021d7654) = result + 1;
    return result;
}
