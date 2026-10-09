#include <globaldefs.h>
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>

struct BattleCommand05 {
    unsigned int opcode;
    BattleCommand05* next;
    short first;
    short second;
    int third;
};
struct BattleCommandQueueView {
    void* unknown00;
    void* queue;
    SafeAllocator* allocator;
};
extern "C" {
    extern BattleCommandQueueView data_ov000_02184264;
    void func_ov000_02169b78(BattleCommand05*);
}

// USA: func_ov000_02169e80
extern "C" ARM int func_ov000_02169e80(Script::Parameter* parameters, int count)
{
    BattleCommand05* command = static_cast<BattleCommand05*>(
        data_ov000_02184264.allocator->Allocate(sizeof(BattleCommand05)));
    command->opcode = 5;
    if (parameters->type == 2) {
        float value = parameters->ToFloat();
        parameters++;
        command->first = 4096.0f * value;
    } else if (parameters->type == 1) {
        int value = parameters->ToInt();
        parameters++;
        command->first = 4096.0f * (value / 1000.0f);
    }
    if (parameters->type == 2) {
        float value = parameters->ToFloat();
        parameters++;
        command->second = 4096.0f * value;
    } else if (parameters->type == 1) {
        int value = parameters->ToInt();
        parameters++;
        command->second = 4096.0f * (value / 1000.0f);
    }
    command->third = 4096.0f * parameters->ToFloat();
    func_ov000_02169b78(command);
    return 1;
}
