#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>

int LoadBattleBlock020ac4c0(void* dst);

extern "C" BattleRecordPlayClock func_ov023_021e8fe8(BattleRecordPlayClock v, int kind);
struct BattleCommandArgument {
    int type;
    union {
        int integer;
        float real;
        BattleCommandArgument* reference;
    } value;
};

extern "C" void func_ov017_021d6134(BattleCommandArgument* output, int val);

// USA: func_ov023_021e9c54
extern "C" ARM int func_ov023_021e9c54(void* obj) {
    BattleCommandArgument* outputs = (BattleCommandArgument*)obj;
    BattleRecordSnapshot record;
    LoadBattleBlock020ac4c0(&record);

    BattleRecordPlayClock result = func_ov023_021e8fe8(record.clocks.committed, 1);

    func_ov017_021d6134(&outputs[0], result.hours);
    func_ov017_021d6134(&outputs[1], result.minutes);
    return 1;
}
