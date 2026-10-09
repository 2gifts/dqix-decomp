#include <globaldefs.h>
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>

struct BattleValueCommand {
    unsigned int opcode;
    BattleValueCommand* next;
    short id;
    short subId;
    int fixedValues[1];
    short intValues[2];
};
struct BattleCommandQueueView {
    void* unknown00;
    void* queue;
    SafeAllocator* allocator;
};
extern "C" {
    extern BattleCommandQueueView data_ov000_02184264;
    void func_ov000_02169b78(BattleValueCommand*);
}

// USA: func_ov000_0216a208
extern "C" ARM int func_ov000_0216a208(Script::Parameter* parameters, int count)
{
    BattleValueCommand* command = static_cast<BattleValueCommand*>(
        data_ov000_02184264.allocator->Allocate(sizeof(BattleValueCommand)));
    command->opcode = 9;
    command->id = parameters[0].ToInt();
    if (count > 1) {
        Script::Parameter* second = &parameters[1];
        parameters += 2;
        command->subId = second->ToInt();
        int i;
        int numInts;
        int numFixed;
        numFixed = 0;
        numInts = 0;
        for (i = 0; i < count - 2; i++) {
            if (parameters->type == 1) {
                command->intValues[numInts] = parameters->ToInt();
                parameters++;
                numInts++;
            } else if (parameters->type == 2) {
                float value = parameters->ToFloat();
                parameters++;
                command->fixedValues[numFixed] = 4096.0f * value;
                numFixed++;
            } else if (parameters->type == 0) {
                parameters++;
            }
        }
    } else {
        command->subId = 0;
    }
    func_ov000_02169b78(command);
    return 1;
}
