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
int CheckFlag0x14Bit0x10Set(unsigned char*);
void ClearBattleFlag0x14Bit4(void*);
extern "C" int _Z22IsFlagBit5Set_021de25cP16FlagObj_021de25c(FlagObj_021de25c*);
void ClearFlag0x20AndBytes(void*);
extern "C" int _Z22IsFlagBit8Set_021da9b0P16FlagObj_021da9b0(FlagObj_021da9b0*);
void ClearFlag0x14Bit0x8AndBytes(void*);
extern "C" int _Z23IsFlagBit19Set_021da9c8P16FlagObj_021da9c8(FlagObj_021da9c8*);
void ClearFlag0x80000AndBits0x3c(unsigned char*);
int CheckFlag0x2AndKind1(Combatant_20885b4*);
void ClearFlag0x2AndKind(Combatant_2088644*);
int CheckFlag0x2AndState2(S88514*);
void ClearFlag0x2AndBits0x3(unsigned char*);
extern "C" int _Z22IsFlagBit6Set_021df6ecP16FlagObj_021df6ec(FlagObj_021df6ec*);
extern "C" void _Z29ClearFlag0x40AndBytes02088874Ph(unsigned char*);
extern "C" int _Z22IsFlagBit8Set_021dd010P16FlagObj_021dd010(FlagObj_021dd010*);
void ClearFlag0x100AndBytes(unsigned char*);
extern "C" int _Z29IsFlagBit4Field18Set_021df704P16FlagObj_021df704(FlagObj_021df704*);
void ClearFlag0x10AndBytes(unsigned char*);
extern "C" void _Z35ClearBattleFlags0x14And0x5802087838Pv(void*);
extern "C" void _Z35ClearBattleFlags0x14And0x580208792cPv(void*);
extern "C" void _Z35ClearBattleFlags0x14And0x5802087a20Pv(void*);
extern "C" void _Z35ClearBattleFlags0x14And0x5802087b14Pv(void*);
extern "C" void _Z35ClearBattleFlags0x14And0x5802087c08Pv(void*);
void ClearBattleFlags0x14And0x58(void*);
void ClearFlagsAndBytes(void*);
void ClearFlags0x14And0x58AndBytes(unsigned char*);
void ClearFlags0x14And0x58(void*);
void ClearBattleFlags0x18And0x58(void*);
void ApplyCombatantBuffs(int, int);

// USA: func_ov024_021eae14
extern "C" ARM int func_ov024_021eae14(BattleContext* context, int id) {
    GameObject* combatant = GetCombatantByID(context->battle, id);
    if (!combatant) return 0;
    int count = 0;
    int refresh = 0;
    if (CheckFlag0x14Bit0x10Set((unsigned char*)combatant->currentStats_)) {
        ClearBattleFlag0x14Bit4(combatant->currentStats_); count++; refresh = 1;
    }
    if (_Z22IsFlagBit5Set_021de25cP16FlagObj_021de25c((FlagObj_021de25c*)combatant)) {
        ClearFlag0x20AndBytes(combatant->currentStats_); count++; refresh = 1;
    }
    if (_Z22IsFlagBit8Set_021da9b0P16FlagObj_021da9b0((FlagObj_021da9b0*)combatant)) {
        ClearFlag0x14Bit0x8AndBytes(combatant->currentStats_); count++; refresh = 1;
    }
    if (_Z23IsFlagBit19Set_021da9c8P16FlagObj_021da9c8((FlagObj_021da9c8*)combatant)) {
        ClearFlag0x80000AndBits0x3c((unsigned char*)combatant->currentStats_); count++; refresh = 1;
    }
    if (CheckFlag0x2AndKind1((Combatant_20885b4*)combatant->currentStats_)) {
        ClearFlag0x2AndKind((Combatant_2088644*)combatant->currentStats_); count++;
    }
    if (CheckFlag0x2AndState2((S88514*)combatant->currentStats_)) {
        ClearFlag0x2AndBits0x3((unsigned char*)combatant->currentStats_); count++;
    }
    if (_Z22IsFlagBit6Set_021df6ecP16FlagObj_021df6ec((FlagObj_021df6ec*)combatant)) {
        _Z29ClearFlag0x40AndBytes02088874Ph((unsigned char*)combatant->currentStats_); count++;
    }
    if (_Z22IsFlagBit8Set_021dd010P16FlagObj_021dd010((FlagObj_021dd010*)combatant)) {
        ClearFlag0x100AndBytes((unsigned char*)combatant->currentStats_); count++;
    }
    if (_Z29IsFlagBit4Field18Set_021df704P16FlagObj_021df704((FlagObj_021df704*)combatant)) {
        ClearFlag0x10AndBytes((unsigned char*)combatant->currentStats_); count++;
    }
    if (combatant->currentStats_->attackBuff < 0) { _Z35ClearBattleFlags0x14And0x5802087838Pv(combatant->currentStats_); count++; }
    if (combatant->currentStats_->defenseBuff < 0) { _Z35ClearBattleFlags0x14And0x580208792cPv(combatant->currentStats_); count++; }
    if (combatant->currentStats_->agilityBuff < 0) { _Z35ClearBattleFlags0x14And0x5802087a20Pv(combatant->currentStats_); count++; }
    if (combatant->currentStats_->charmBuff < 0) { _Z35ClearBattleFlags0x14And0x5802087b14Pv(combatant->currentStats_); count++; }
    if (combatant->currentStats_->magicalMightBuff < 0) { _Z35ClearBattleFlags0x14And0x5802087c08Pv(combatant->currentStats_); count++; }
    if (combatant->currentStats_->magicalMendingBuff < 0) { ClearBattleFlags0x14And0x58(combatant->currentStats_); count++; }
    if (combatant->currentStats_->unkBuff18 < 0) { ClearFlagsAndBytes(combatant->currentStats_); count++; }
    if (((BattleStatus*)combatant->currentStats_)->field21 < 0) { ClearFlags0x14And0x58AndBytes((unsigned char*)combatant->currentStats_); count++; }
    if (((BattleStatus*)combatant->currentStats_)->field27 < 0) { ClearFlags0x14And0x58(combatant->currentStats_); count++; }
    if (((BattleStatus*)combatant->currentStats_)->field24 < 0) { ClearBattleFlags0x18And0x58(combatant->currentStats_); count++; }
    if (refresh) ((BattleStatus*)combatant->currentStats_)->refresh = 1;
    ApplyCombatantBuffs(context->battle, id);
    return count;
}
