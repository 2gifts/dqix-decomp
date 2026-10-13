#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define SetFieldFromLookup464_021e9818 func_ov023_021e977c
#endif

struct BattleCommandArgument {
    int type;
    union {
        int integer;
        float real;
        BattleCommandArgument* reference;
    } value;
};

struct PartyMemberRecordView {
    char unknown000[0x464];
    unsigned char skillProgress[32];
    char unknown484[4];
    short models[10];
    unsigned char female : 1;
};

struct PartyRecordOwnerView {
#if defined(jpn)
    char unknown000[0x144];
#else
    char unknown000[0x150];
#endif
    PartyMemberRecordView* record;
};

extern "C" int func_ov017_021d60f4(BattleCommandArgument* argument);
extern "C" void func_ov017_021d6134(BattleCommandArgument* output, int value);
extern "C" GameObject* func_ov023_021e8f28(int partyIndex);

#if defined(jpn)
extern "C"
#endif
ARM int SetFieldFromLookup464_021e9818(void* command) {
    BattleCommandArgument* arguments = (BattleCommandArgument*)command;
    GameState::GetInstance();
    int partyIndex = func_ov017_021d60f4(&arguments[0]);
    GameObject* member = func_ov023_021e8f28(partyIndex);
    if (member == NULL) return 0;
    int index = func_ov017_021d60f4(&arguments[1]);
    PartyMemberRecordView* record = ((PartyRecordOwnerView*)member)->record;
    unsigned char value = record->skillProgress[(unsigned char)index];
    func_ov017_021d6134(&arguments[2], value);
    return 1;
}
