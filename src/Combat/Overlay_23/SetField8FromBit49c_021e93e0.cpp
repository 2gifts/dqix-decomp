#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define SetField8FromBit49c_021e93e0 func_ov023_021e9344
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
extern "C" GameObject* func_ov023_021e8f28(int partyIndex);
extern "C" void func_ov017_021d6134(BattleCommandArgument* output, int value);

#if defined(jpn)
extern "C"
#endif
ARM int SetField8FromBit49c_021e93e0(void* command) {
    BattleCommandArgument* arguments = (BattleCommandArgument*)command;
    GameState::GetInstance();
    GameObject* member = func_ov023_021e8f28(func_ov017_021d60f4(&arguments[0]));
    if (member == NULL) return 0;
    PartyMemberRecordView* record = ((PartyRecordOwnerView*)member)->record;
    func_ov017_021d6134(&arguments[1], record->female);
    return 1;
}
