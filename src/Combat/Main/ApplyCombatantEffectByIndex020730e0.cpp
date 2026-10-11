#if defined(jpn)
enum { RegionalOffset = 0x148 };
#else
enum { RegionalOffset = 0x154 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

int GetField0x3acValue(GameState* battleStruct);
int GetFieldAt0x150(unsigned char* obj);

struct Field150Holder02052e2c;
short* GetField150Ptr0x488_02052e2c(struct Field150Holder02052e2c* obj);

unsigned short (*GetVariantShortTable02109928(void))[2];

struct Container02083554;
void* FindEntryByShortField02083554(struct Container02083554* c, int id);

struct Obj020de2a4;
int GetNibbleField020de2a4(struct Obj020de2a4* obj, int a, int b);


extern "C" void func_02072afc(int id, int* arr, short* arr2);
extern "C" void func_02099d34(void* obj, int a, int b, int c);
extern "C" void func_02099e18(void* obj, int a, int b, int c);

struct Byte14Bits020730e0 {
    unsigned char bit0 : 1;
    unsigned char threeBit : 3;
    unsigned char highNibble : 4;
};
struct Byte15Bits020730e0 {
    unsigned char fourBit : 4;
    unsigned char rest : 4;
};
struct TableEntry020730e0 {
    unsigned char pad[0x14];
    struct Byte14Bits020730e0 b14;
    struct Byte15Bits020730e0 b15;
};

// USA: func_020730e0
// JPN: func_020730e0
ARM void ApplyCombatantEffectByIndex020730e0(int id, int index) {
    GameState* bs = GameState::GetInstance();
    GameObject* combatant;
    int val150;
    struct TableEntry020730e0* table;
    int nibble;
    GameObject* combatant2;
    void* subPtr;
    int bufA[11];
    short bufB[12];

    if (id < 0) {
        id = GetField0x3acValue(bs);
    }

    combatant = GetCombatantWithFlag0x100(bs, id);
    if (!combatant || *(int*)((char*)combatant + RegionalOffset) == 0) {
        return;
    }

    val150 = GetFieldAt0x150((unsigned char*)combatant);
    if (val150 == 0) {
        return;
    }

    table = (struct TableEntry020730e0*)GetField150Ptr0x488_02052e2c((struct Field150Holder02052e2c*)combatant);
    GetVariantShortTable02109928();

    func_02072afc(id, bufA, bufB);
    if (bufB[index] < 0) {
        return;
    }

    {
        void* entry = FindEntryByShortField02083554((struct Container02083554*)val150, bufB[index]);
        if (!entry) {
            return;
        }
        nibble = GetNibbleField020de2a4((struct Obj020de2a4*)entry, 1, table->b14.bit0);
    }

    combatant2 = bs->GetGameObjectByIndex(bufA[index]);
    if (!combatant2) {
        return;
    }

    switch (index) {
        case 0:
        case 1:
        case 5:
        case 6:
        case 7:
            subPtr = *(void**)((char*)combatant2 + 8);
            func_02099d34(subPtr, nibble, table->b14.threeBit, 4);
            break;
        case 4:
            subPtr = *(void**)((char*)combatant2 + 8);
            func_02099d34(subPtr, nibble, table->b14.threeBit, 0x10);
            break;
        case 2:
            subPtr = *(void**)((char*)combatant2 + 8);
            func_02099e18(subPtr, table->b14.threeBit, table->b15.fourBit, table->b14.highNibble);
            break;
        default:
            break;
    }
}
