#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct0200fb08;
struct EntryList0204af14;

unsigned char NormalizeField5_0200fb08(struct Struct0200fb08* obj);
void* GetEntryByIndexStride0x10(struct EntryList0204af14* list, unsigned int index);
void CallFunc0204b620IfField0x14_0204b938(void* a, void* b, int x, int y, unsigned short id);
extern "C" void func_0205ac40(void* dst, void* src);

// USA: func_ov000_0218124c
extern "C" ARM void func_ov000_0218124c(unsigned char* obj, int idx, void* target, int unused, short x, short y, short posX, short posY) {
    GameState* gs = GameState::GetInstance();
    unsigned int entryIdx = 5;
    switch (NormalizeField5_0200fb08((struct Struct0200fb08*)gs)) {
    case 2:
        entryIdx = 6;
        break;
    case 3:
        entryIdx = 8;
        break;
    case 4:
        entryIdx = 7;
        break;
    case 5:
        entryIdx = 9;
        break;
    }
    void* entry = GetEntryByIndexStride0x10((struct EntryList0204af14*)(obj + 0x8c4), entryIdx);
    CallFunc0204b620IfField0x14_0204b938(target, entry, (short)(x + 2), (short)(y + 1), idx + 2);
    GameObject* member = gs->GetPartyMemberByIndex(idx);
    if (member != 0 && *(int*)((char*)member + 0x1c4) == 0) {
        unsigned char* p = *(unsigned char**)(obj + 0x170) + (idx + 0x20) * 0x28;
        *(int*)(p + 0x14) = posX << 12;
        *(int*)(p + 0x18) = posY << 12;
        p[0x22] = idx + 0x5c;
        p[0x26] = 1;
        func_0205ac40(obj + 0x11c, p);
    }
}
