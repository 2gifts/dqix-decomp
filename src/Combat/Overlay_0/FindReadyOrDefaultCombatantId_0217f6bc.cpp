#include <globaldefs.h>
#include "GameState/GameState.h"

int HasAnyFlags_021719f8_021719f8(int* obj);
void* GetFieldAt0x150(unsigned char* obj);

struct Entry0217f6bc {
    char pad0[0x18];
    signed char field18;
    char pad2[0x24 - 0x19];
    unsigned char field24;
    char pad3[0x4c - 0x25];
    int field4c;
#if defined(jpn)
    char pad4[0xc7 - 0x50];
#else
    char pad4[0x87 - 0x50];
#endif
    unsigned char field87;
    char pad5[0x445 - 0x88];
    unsigned char field445;
    char pad6[0x448 - 0x446];
};

// USA: func_ov000_0217f6bc  (semantic: FindReadyOrDefaultCombatantId_0217f6bc)
extern "C" ARM int func_ov000_0217f6bc(char* obj) {
    GameState* bs = GameState::GetInstance();
    struct Entry0217f6bc* entry;
    int i;
    for (i = 0; i < 4; i++) {
        signed char idx = *(signed char*)(obj + 0x6c + i);
        entry = (struct Entry0217f6bc*)(obj + 0x958) + idx;
        if (entry->field4c < 0) continue;
        if (entry->field87 == 0) continue;
        if (entry->field24 & 4) continue;
        signed char v = *(signed char*)((char*)entry + entry->field18 + 0x10);
        if (v == 0x64) continue;
        if (HasAnyFlags_021719f8_021719f8((int*)entry)) continue;
        if (entry->field445 == 0) continue;
        GameObject* c = bs->GetPartyMemberByIndex(*(signed char*)(obj + 0x6c + i));
#if defined(jpn)
        enum { statusOffset = 0x8b4 };
#else
        enum { statusOffset = 0x94c };
#endif
        if (c == 0 || (signed char)(*(int*)((char*)GetFieldAt0x150((unsigned char*)c) + statusOffset)) == 5) {
            return entry->field4c;
        }
    }
    return -1;
}
