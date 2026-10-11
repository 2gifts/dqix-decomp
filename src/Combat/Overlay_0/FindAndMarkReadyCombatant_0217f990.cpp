#include <globaldefs.h>
#include "GameState/GameState.h"

int HasAnyFlags_021719f8_021719f8(int* obj);
void* GetFieldAt0x150(unsigned char* obj);
extern "C" ARM void* func_ov000_02161318(void* obj, int id);

struct Entry0217f990 {
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

// USA: func_ov000_0217f990  (semantic: FindAndMarkReadyCombatant_0217f990)
extern "C" ARM int func_ov000_0217f990(char* obj) {
    GameState* bs = GameState::GetInstance();
    unsigned char* field2a04 = (unsigned char*)GetPtrField0x2a04(bs);
    unsigned char limit = field2a04[0xf7c];
    int result = 0;
    unsigned char i;
    for (i = 0; i < limit; i++) {
        signed char idx = *(signed char*)(obj + i + 0x70);
        struct Entry0217f990* entry = (struct Entry0217f990*)func_ov000_02161318(obj, idx);
        if (entry == 0) continue;
        if (entry->field4c < 0) continue;
        if (entry->field87 == 0) continue;
        signed char v = *(signed char*)((char*)entry + entry->field18 + 0x10);
        if (v == 0x64) continue;
        if (HasAnyFlags_021719f8_021719f8((int*)entry)) continue;
        if (entry->field445 == 0) continue;
        GameObject* c = bs->GetPartyMemberByIndex(idx);
#if defined(jpn)
        enum { statusOffset = 0x8b4 };
#else
        enum { statusOffset = 0x94c };
#endif
        if (c != 0 && (signed char)(*(int*)((char*)GetFieldAt0x150((unsigned char*)c) + statusOffset)) != 5) continue;
        *(int*)(obj + 0x17c) = idx;
        result = 1;
        break;
    }
    return result;
}
