#include <globaldefs.h>
#include <GameState/GameState.h>

struct Obj02086aec;
struct CombatantInfo { char pad0[8]; short key_; };
struct Combatant : GameObject { char pad13C[8]; CombatantInfo* info_; };
struct ConditionStats { char pad0[0x22]; unsigned short unused : 2; unsigned short condition_ : 4; unsigned short rest : 10; };
struct GlobalEntry {
    unsigned int id_ : 9;
    unsigned int pad9 : 5;
    unsigned int disabled_ : 1;
    unsigned int removed_ : 1;
    unsigned int rest : 16;
    int fields_[3];
};
struct GlobalEntries { unsigned char count_; char pad1[3]; GlobalEntry entries_[1]; };
struct ActionRule {
    unsigned short entryID_;
    unsigned short combatantKey_;
    unsigned short condition_;
    unsigned short category_;
    unsigned short actionID_;
    unsigned short resultID_;
    unsigned char alternate_;
    unsigned char padD;
};
extern ActionRule data_ov024_021fe9b8[];
int* GetGlobal02109418();
extern "C" int _Z30SumCombatantKeyMatches02086aecP11Obj02086aeci(Obj02086aec*, int);
int CheckFlag0x14Bit0x10Set(unsigned char*);

// USA: func_ov024_021df71c
extern "C" ARM int func_ov024_021df71c(Combatant* self, unsigned int actionID, int alternate, unsigned short* resultID, unsigned short* combatantKey, unsigned short* entryID) {
    GlobalEntries* global = (GlobalEntries*)GetGlobal02109418();
    if (!global->count_) return 0;
    Obj02086aec* battle = (Obj02086aec*)GetPtrField0x2a04(GameState::GetInstance());
    int key = 0;
    if (self->info_) key = self->info_->key_;
    for (int i = 0; i < global->count_; ++i) {
        GlobalEntry* entries = global->entries_;
        if (entries[i].removed_) continue;
        if (entries[i].disabled_) continue;
        for (int j = 0; j < 7; ++j) {
            ActionRule* rule = &data_ov024_021fe9b8[j];
            if (rule->entryID_ != entries[i].id_ || key != rule->combatantKey_) continue;
            if (alternate != 0 && rule->alternate_ == 0) continue;
            if (alternate == 0 && rule->alternate_ != 0) continue;
            if (_Z30SumCombatantKeyMatches02086aecP11Obj02086aeci(battle, (short)rule->resultID_) > 0) continue;
            if (rule->condition_ != 0) {
                if (rule->condition_ == 1) {
                    if (!CheckFlag0x14Bit0x10Set((unsigned char*)self->currentStats_)) continue;
                } else if (rule->condition_ == 2) {
                    if (self->currentStats_->primaryStats.currHP > 700) continue;
                } else if (rule->condition_ == 3) {
                    if (((ConditionStats*)self->currentStats_)->condition_ != 3) continue;
                }
            }
            unsigned int category = rule->category_;
            if (category) {
                if (category >= 40000) {
                    category = 40000;
                    if (actionID < category) continue;
                } else if ((int)category / 100 != (int)actionID / 100) continue;
            }
            if (rule->actionID_ != 0 && rule->actionID_ != actionID) continue;
            *resultID = rule->resultID_;
            *combatantKey = rule->combatantKey_;
            *entryID = rule->entryID_;
            return 1;
        }
    }
    return 0;
}
