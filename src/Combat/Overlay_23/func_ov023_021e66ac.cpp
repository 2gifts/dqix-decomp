#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

int GetField5cb0Value(char* obj);
extern "C" void func_0202ae18(void);

struct TableA68 { struct EntryA68* entries; short count; };
void* FindEntryByKey(struct TableA68* table, int key);

struct Sub0x150_021e66ac {
    char pad0[0x49c];
    unsigned char bit0 : 1;
    char pad1[0x950 - 0x49d];
    int field950;
};

struct Flags69c_021e66ac {
    unsigned int lowBits : 29;
    unsigned int bit29 : 1;
    unsigned int bit30 : 1;
    unsigned int bit31 : 1;
};

// USA: func_ov023_021e66ac  (semantic: BuildOrCopyKeyStringField_021e66ac)
extern "C" ARM void func_ov023_021e66ac(void* obj) {
    GameState* battleStruct = GameState::GetInstance();
    struct Flags69c_021e66ac* flags = (struct Flags69c_021e66ac*)((char*)battleStruct + 0x5000 + 0x69c);
    char* subPtr = (char*)battleStruct + 0x569c;

    if (!flags->bit29) {
        memset((char*)obj + 0x1400, 0, 0x40);
        void* entry = FindEntryByKey((struct TableA68*)((char*)obj + 0x133c), 0x6d);
        memcpy((char*)obj + 0x1400, entry, 7);
    } else if (flags->bit30) {
        func_0202ae18();
        GameObject* combatant = battleStruct->GetProtagonist();
        struct Sub0x150_021e66ac* sub = *(struct Sub0x150_021e66ac**)((char*)combatant + 0x150);
        int result = sub->field950;
        if (GetField5cb0Value((char*)battleStruct) == 1) {
            result = 0xd;
        }
        struct Sub0x150_021e66ac* sub2 = *(struct Sub0x150_021e66ac**)((char*)combatant + 0x150);

        int base = 0x50dc;
        if (sub2->bit0 == 1) {
            base += 0x32;
        }

        short key = (short)(base + result);
        void* entry = FindEntryByKey((struct TableA68*)((char*)obj + 0x133c), key);
        memset((char*)obj + 0x1400, 0, 0x40);
        unsigned int len = strlen((char*)entry);
        memcpy((char*)obj + 0x1400, entry, len);
    }

    int field56a0Val = *(int*)(subPtr + 4);
    int extracted = (field56a0Val << 13) >> 22;
    if (extracted != 0x12c) {
        return;
    }

    memset((char*)obj + 0x1440, 0, 0x40);
    void* entry2 = FindEntryByKey((struct TableA68*)((char*)obj + 0x133c), 0x6d);
    unsigned int len2 = strlen((char*)entry2);
    memcpy((char*)obj + 0x1440, entry2, len2);
}
