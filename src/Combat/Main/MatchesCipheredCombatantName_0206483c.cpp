#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

int GetFieldAt0x150_02053c6c(unsigned char* obj);

// USA: func_0206483c  (semantic: MatchesCipheredCombatantName_0206483c)
extern "C" ARM int func_0206483c(void* unused0, char* name) {
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(battleStruct, 0);
    char* subject = (char*)GetFieldAt0x150_02053c6c((unsigned char*)combatant) + 0x3c;
    int len = strlen(subject);
    int i;
    int evenMatch;

    for (i = 0; i < len; name++, subject++, i++) {
        if ((i % 2) == 0) {
            if (*name == *subject) {
                evenMatch = 1;
            } else {
                evenMatch = 0;
            }
        } else if (evenMatch) {
            if (*name != *subject) {
                return 0;
            }
        } else {
            unsigned char c1 = *(unsigned char*)name;
            unsigned char c2 = *(unsigned char*)subject;
            int shift = 0x5f;
            if (c1 > 0x7f) {
                shift = 0x5e;
            }
            int shifted = (c1 + shift) & 0xff;
            if (shifted != c2) {
                return 0;
            }
        }
    }
    return 1;
}
