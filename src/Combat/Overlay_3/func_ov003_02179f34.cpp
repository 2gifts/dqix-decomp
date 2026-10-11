#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue1000_F7C = 0xf7c };
enum { kRegionValue89C_818 = 0x818 };
#else
enum { kRegionValue1000_F7C = 0x1000 };
enum { kRegionValue89C_818 = 0x89c };
#endif


void* GetPtrField0x2a04(GameState* battleStruct);
short FindMappedMemberId02080468(void* obj, int id);
unsigned char GetTableByte0207ca94(int index);
short CountPositiveEntries0207c638(void* base, unsigned int index);
int GetFieldAt0x150(unsigned char* obj);
struct Slots02083960;
int CountPositiveSlots02083960(struct Slots02083960* s);
struct S_a0b8c;
int CountNonZeroValues020a0b8c(struct S_a0b8c* p);

// USA: func_ov003_02179f34
// JPN: func_ov003_02178d64
extern "C" ARM int func_ov003_02179f34(char* obj) {
    int result = 0;
    GameState* battle = GameState::GetInstance();
    void* ptr = GetPtrField0x2a04(battle);
    short val = *(short*)(obj + kRegionValue1000_F7C + 0xc);
    void* field89c = *(void**)(obj + kRegionValue89C_818);

    if (val == 0x77) {
        short id = FindMappedMemberId02080468(field89c, 0x1d);
        short idx = (short)(*(short*)(obj + kRegionValue1000_F7C + 0x12) - id);
        unsigned char tableVal = GetTableByte0207ca94(idx);
        result = CountPositiveEntries0207c638((char*)ptr + 0x1d4, tableVal);
    } else {
        signed char field43 = *(signed char*)(obj + kRegionValue1000_F7C + 0x43);
        int flag = result;
        if (field43 >= 0) {
            flag = (field43 <= 3) ? 1 : 0;
        }
        if (flag) {
            GameObject* combatant = battle->GetPartyMemberByIndex(field43);
            if (combatant != 0) {
                int f150 = GetFieldAt0x150((unsigned char*)combatant);
                result = (short)CountPositiveSlots02083960((struct Slots02083960*)f150);
            }
        } else {
            result = CountNonZeroValues020a0b8c((struct S_a0b8c*)ptr);
        }
    }
    return result;
}
