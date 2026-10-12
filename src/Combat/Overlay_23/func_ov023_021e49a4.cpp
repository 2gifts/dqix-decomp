#include <globaldefs.h>
#include "GameState/GameState.h"

struct CombatSlots02045cac;
struct Container020e0310 { unsigned char fields[0x18]; };
struct BattleTexts021e49a4 {
    unsigned char padding_0[0xc00];
    Container020e0310 dictionary;
};
struct BattleData021e49a4 {
    unsigned char padding_0[0x1f8];
    BattleTexts021e49a4 texts;
};
struct BattleSetup021e49a4 {
    BattleData021e49a4* battle;
    unsigned char padding_4[0x500 - 4];
    unsigned short names[4][16];
    int positions[4];
    unsigned short labels[4][10];
    unsigned short default_label[8];
    unsigned short suffixes[4][8];
    unsigned char padding_630[0x10];
    char* buffers[2];
};
struct CombatantCondition021e49a4 {
    unsigned int field_0;
    unsigned short value;
};
static inline int ConditionValue021e49a4(CombatantCondition021e49a4* condition) {
    int value = condition->value;
    return value;
}
struct CombatantData021e49a4 {
    unsigned char padding_0[0x49c];
    unsigned char selector : 1;
    unsigned char flags : 7;
    unsigned char padding_49d[0x950 - 0x49d];
    int label_id;
};
struct Combatant021e49a4 {
    unsigned char padding_0[0x130];
    CombatantCondition021e49a4* condition;
    char* name;
    unsigned char padding_138[0x18];
    CombatantData021e49a4* data;
};
CombatSlots02045cac* GetGlobalField0x1c020421a0();
void InitCombatSlots02045cac(CombatSlots02045cac*);
char* CallFunc020e0434With02153694(int);
int GetFieldByKey020e0434(Container020e0310*, int);
int GetByteViaFieldIndirectOffset_021e4250_021e4250(char*);
extern const char data_ov023_021fdcd8[];
extern "C" {
void func_02045d14(CombatSlots02045cac*, const char*, unsigned short*, int);
int func_020420e8(const char*, int);
GameResources* func_ov017_0218b5b0();
int func_ov017_021bdbcc(GameResources*);
void __clear(void*, unsigned int);
int sprintf(char*, const char*, ...);
void func_020439b0(CombatSlots02045cac*, int);
}

// USA: func_ov023_021e49a4
extern "C" ARM void func_ov023_021e49a4(BattleSetup021e49a4* self) {
    BattleTexts021e49a4* texts;
    GameState* game = GameState::GetInstance();
    unsigned short (*suffixes)[8];
    unsigned short (*labels)[10];
    unsigned short (*names)[16];
    CombatSlots02045cac* messages = GetGlobalField0x1c020421a0();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 16; j++) self->names[i][j] = 0xffff;
        for (int j = 0; j < 10; j++) self->labels[i][j] = 0xffff;
        for (int j = 0; j < 8; j++) self->suffixes[i][j] = 0xffff;
        self->positions[i] = 0;
    }
    for (int i = 0; i < 8; i++) self->default_label[i] = 0xffff;
    InitCombatSlots02045cac(messages);
    texts = &self->battle->texts;
    func_02045d14(messages, CallFunc020e0434With02153694(0x3f3), self->default_label, 0);
    for (int i = 0; i < 4; i++) {
        names = self->names;
        labels = self->labels;
        suffixes = self->suffixes;
        Combatant021e49a4* combatant = (Combatant021e49a4*)GetCombatantWithFlag0x100(game, i);
        if (combatant != 0) {
            char* name = combatant->name;
            func_02045d14(messages, name, names[i], 0);
            self->positions[i] = 35 - func_020420e8(name, 0) / 2;
            short label = combatant->data->label_id + 500;
            if (func_ov017_021bdbcc(func_ov017_0218b5b0())) label = 500;
            if (ConditionValue021e49a4(combatant->condition) <= 0) {
                func_02045d14(messages, self->buffers[combatant->data->selector], labels[i], 0);
            } else {
                func_02045d14(messages, (const char*)GetFieldByKey020e0434(&texts->dictionary, label), labels[i], 0);
            }
            unsigned char suffix = GetByteViaFieldIndirectOffset_021e4250_021e4250((char*)combatant);
            char buffer[16];
            __clear(buffer, 16);
            if (suffix != 0) {
                sprintf(buffer, data_ov023_021fdcd8, GetByteViaFieldIndirectOffset_021e4250_021e4250((char*)combatant));
            }
            func_02045d14(messages, buffer, suffixes[i], 0);
            func_020439b0(messages, 0);
        }
    }
}
