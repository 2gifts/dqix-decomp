#include <globaldefs.h>
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>

struct BattleVectorCommand {
    unsigned int opcode;
    BattleVectorCommand* next;
    unsigned char field_0x8;
    unsigned char mode;
    unsigned char value;
    unsigned char field_0xb;
    int field_0xc;
    int field_0x10;
    Vector3fix position;
    unsigned char field_0x20;
};
struct BattleCommandQueueView {
    void* unknown00;
    void* queue;
    SafeAllocator* allocator;
};
extern "C" {
    extern BattleCommandQueueView data_ov000_02184264;
    void func_ov000_02169b78(BattleVectorCommand*);
    void __clear(void* dst, unsigned int size);
}

// USA: func_ov000_0216aed0
extern "C" ARM int func_ov000_0216aed0(Script::Parameter* parameters, int count)
{
    BattleVectorCommand* command = static_cast<BattleVectorCommand*>(
        data_ov000_02184264.allocator->Allocate(sizeof(BattleVectorCommand)));
    command->opcode = 0;
    command->next = 0;
    command->opcode = 0x2a;
    command->field_0x8 = parameters[0].ToInt();
    Script::Parameter* second = &parameters[1];
    parameters += 2;
    command->mode = second->ToInt();
    Vector3fix position;
    __clear(&position, sizeof(position));
    int index = 0;
    command->field_0xb = 0;
    command->field_0x10 = 0x666;
    command->field_0xc = 0x1266;
    if (command->mode == 7) {
        index = parameters->ToInt();
    } else if (command->mode == 8) {
        if (count >= 3) {
            parameters = parameters->ToVec3fix(&position);
        }
        if (count >= 4) {
            index = parameters->ToInt();
        }
    } else if (command->mode == 9) {
        Script::Parameter* next = parameters->ToVec3fix(&position);
        command->field_0x20 = 0;
        if (count >= 6) {
            command->field_0x20 = next->ToInt() != 0;
        }
    } else if (command->mode == 11) {
        parameters = parameters->ToVec3fix(&position);
        if (count >= 6) {
            command->field_0xb = parameters->ToInt();
            if (count >= 7) {
                command->field_0x10 = 4096.0f * parameters[1].ToFloat();
                command->field_0xc = 4096.0f * parameters[2].ToFloat();
            }
        }
    } else if (count >= 3) {
        parameters->ToVec3fix(&position);
    }
    command->value = index;
    command->position = position;
    func_ov000_02169b78(command);
    return 1;
}
