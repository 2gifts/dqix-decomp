#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Combat/Overlay_0/GetCombatantByID.h>

struct BattleContext { char pad[0x10]; int battle; };
struct BattleStatus {
    char pad0[0x3b];
    unsigned char refresh : 1;
    unsigned char otherFlags : 7;
    char pad1[0x1c];
    unsigned int knownBuffs : 21;
    signed int field21 : 3;
    signed int field24 : 3;
    signed int field27 : 3;
};
struct FlagObj_021de25c;
struct FlagObj_021da9b0;
struct FlagObj_021da9c8;
struct FlagObj_021df6ec;
struct FlagObj_021dd010;
struct FlagObj_021df704;
struct Combatant_20885b4;
struct Combatant_2088644;
struct S88514;
int CheckFlag0x14Bit0x10Set_020882f8(unsigned char*);
void ClearBattleFlag0x14Bit4_02088390(void*);
int IsFlagBit5Set_021de25c(FlagObj_021de25c*);
void ClearFlag0x20AndBytes_020883fc(void*);
int IsFlagBit8Set_021da9b0(FlagObj_021da9b0*);
void ClearFlag0x14Bit0x8AndBytes_020882dc(void*);
int IsFlagBit19Set_021da9c8(FlagObj_021da9c8*);
void ClearFlag0x80000AndBits0x3c_020884f8(unsigned char*);
int CheckFlag0x2AndKind1_020885b4(Combatant_20885b4*);
void ClearFlag0x2AndKind_02088644(Combatant_2088644*);
int CheckFlag0x2AndState2_02088514(S88514*);
void ClearFlag0x2AndBits0x3_02088598(unsigned char*);
int IsFlagBit6Set_021df6ec(FlagObj_021df6ec*);
void ClearFlag0x40AndBytes02088874(unsigned char*);
int IsFlagBit8Set_021dd010(FlagObj_021dd010*);
void ClearFlag0x100AndBytes_020888c4(unsigned char*);
int IsFlagBit4Field18Set_021df704(FlagObj_021df704*);
void ClearFlag0x10AndBytes_02088d4c(unsigned char*);
void ClearBattleFlags0x14And0x5802087838(void*);
void ClearBattleFlags0x14And0x580208792c(void*);
void ClearBattleFlags0x14And0x5802087a20(void*);
void ClearBattleFlags0x14And0x5802087b14(void*);
void ClearBattleFlags0x14And0x5802087c08(void*);
void ClearBattleFlags0x14And0x58_02087cfc(void*);
void ClearFlagsAndBytes_02087df0(void*);
void ClearFlags0x14And0x58AndBytes_02087efc(unsigned char*);
void ClearFlags0x14And0x58_02087ff0(void*);
void ClearBattleFlags0x18And0x58_020880e4(void*);
void ApplyCombatantBuffs(int, int);

// USA: func_ov024_021eae14
extern "C" ARM int func_ov024_021eae14(BattleContext* context, int id) {
    GameObject* combatant = GetCombatantByID(context->battle, id);
    if (!combatant) return 0;
    int count = 0;
    int refresh = 0;
    if (CheckFlag0x14Bit0x10Set_020882f8((unsigned char*)combatant->currentStats_)) {
        ClearBattleFlag0x14Bit4_02088390(combatant->currentStats_); count++; refresh = 1;
    }
    if (IsFlagBit5Set_021de25c((FlagObj_021de25c*)combatant)) {
        ClearFlag0x20AndBytes_020883fc(combatant->currentStats_); count++; refresh = 1;
    }
    if (IsFlagBit8Set_021da9b0((FlagObj_021da9b0*)combatant)) {
        ClearFlag0x14Bit0x8AndBytes_020882dc(combatant->currentStats_); count++; refresh = 1;
    }
    if (IsFlagBit19Set_021da9c8((FlagObj_021da9c8*)combatant)) {
        ClearFlag0x80000AndBits0x3c_020884f8((unsigned char*)combatant->currentStats_); count++; refresh = 1;
    }
    if (CheckFlag0x2AndKind1_020885b4((Combatant_20885b4*)combatant->currentStats_)) {
        ClearFlag0x2AndKind_02088644((Combatant_2088644*)combatant->currentStats_); count++;
    }
    if (CheckFlag0x2AndState2_02088514((S88514*)combatant->currentStats_)) {
        ClearFlag0x2AndBits0x3_02088598((unsigned char*)combatant->currentStats_); count++;
    }
    if (IsFlagBit6Set_021df6ec((FlagObj_021df6ec*)combatant)) {
        ClearFlag0x40AndBytes02088874((unsigned char*)combatant->currentStats_); count++;
    }
    if (IsFlagBit8Set_021dd010((FlagObj_021dd010*)combatant)) {
        ClearFlag0x100AndBytes_020888c4((unsigned char*)combatant->currentStats_); count++;
    }
    if (IsFlagBit4Field18Set_021df704((FlagObj_021df704*)combatant)) {
        ClearFlag0x10AndBytes_02088d4c((unsigned char*)combatant->currentStats_); count++;
    }
    if (combatant->currentStats_->attackBuff < 0) { ClearBattleFlags0x14And0x5802087838(combatant->currentStats_); count++; }
    if (combatant->currentStats_->defenseBuff < 0) { ClearBattleFlags0x14And0x580208792c(combatant->currentStats_); count++; }
    if (combatant->currentStats_->agilityBuff < 0) { ClearBattleFlags0x14And0x5802087a20(combatant->currentStats_); count++; }
    if (combatant->currentStats_->charmBuff < 0) { ClearBattleFlags0x14And0x5802087b14(combatant->currentStats_); count++; }
    if (combatant->currentStats_->magicalMightBuff < 0) { ClearBattleFlags0x14And0x5802087c08(combatant->currentStats_); count++; }
    if (combatant->currentStats_->magicalMendingBuff < 0) { ClearBattleFlags0x14And0x58_02087cfc(combatant->currentStats_); count++; }
    if (combatant->currentStats_->unkBuff18 < 0) { ClearFlagsAndBytes_02087df0(combatant->currentStats_); count++; }
    if (((BattleStatus*)combatant->currentStats_)->field21 < 0) { ClearFlags0x14And0x58AndBytes_02087efc((unsigned char*)combatant->currentStats_); count++; }
    if (((BattleStatus*)combatant->currentStats_)->field27 < 0) { ClearFlags0x14And0x58_02087ff0(combatant->currentStats_); count++; }
    if (((BattleStatus*)combatant->currentStats_)->field24 < 0) { ClearBattleFlags0x18And0x58_020880e4(combatant->currentStats_); count++; }
    if (refresh) ((BattleStatus*)combatant->currentStats_)->refresh = 1;
    ApplyCombatantBuffs(context->battle, id);
    return count;
}
