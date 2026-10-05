#include <globaldefs.h>
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>

// Tentative script command fields; bit widths follow the original access masks.
struct BattleSelectionCommand {
    unsigned int opcode;
    BattleSelectionCommand* next;
    unsigned int hasPrimary : 1;
    unsigned int primary : 15;
    unsigned int useDefaultSecondary : 1;
    unsigned int hasSecondary : 1;
    unsigned int unknownFlags : 14;
    unsigned int secondary : 15;
    unsigned int unknownSecondary : 17;
};
struct BattleCommandQueueView {
    void* unknown00;
    void* queue;
    SafeAllocator* allocator;
};
extern "C" {
    extern BattleCommandQueueView data_ov000_02184264;
    void func_ov000_02169b78(BattleSelectionCommand*);
}

extern "C" ARM int func_ov000_0216b564(Script::Parameter* parameters, int count)
{
    BattleSelectionCommand* command = static_cast<BattleSelectionCommand*>(
        data_ov000_02184264.allocator->Allocate(sizeof(BattleSelectionCommand)));
    if (!command)
        return 0;
    command->opcode = 0;
    command->next = NULL;
    command->opcode = 0x37;
    int primary = parameters[0].ToInt();
    if (primary < 0) {
        command->hasPrimary = 0;
    } else if (primary == 0) {
        command->hasPrimary = 1;
        command->primary = 1;
    } else {
        command->hasPrimary = 1;
        command->primary = primary;
    }
    command->useDefaultSecondary = 1;
    command->hasSecondary = 0;
    command->secondary = 0;
    if (count >= 2) {
        int secondary = parameters[1].ToInt();
        if (secondary >= 0) {
            command->useDefaultSecondary = 0;
            command->hasSecondary = 1;
            command->secondary = secondary;
        } else if (secondary != -2) {
            command->useDefaultSecondary = 0;
            command->hasSecondary = 0;
            command->secondary = 0;
        }
    }
    func_ov000_02169b78(command);
    return 1;
}
