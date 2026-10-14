#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

int CheckFlag0x14Bit0x10Set_020882f8(unsigned char* obj);
struct FlagObj_021de25c;
int IsFlagBit5Set_021de25c(struct FlagObj_021de25c* obj);
struct FlagObj_021da9b0;
int IsFlagBit8Set_021da9b0(struct FlagObj_021da9b0* obj);
struct FlagObj_021da9c8;
int IsFlagBit19Set_021da9c8(struct FlagObj_021da9c8* obj);
struct Combatant_20885b4;
int CheckFlag0x2AndKind1_020885b4(struct Combatant_20885b4* obj);
struct S88514;
int CheckFlag0x2AndState2_02088514(struct S88514* obj);
struct FlagObj_021df6ec;
int IsFlagBit6Set_021df6ec(struct FlagObj_021df6ec* obj);
struct FlagObj_021dd010;
int IsFlagBit8Set_021dd010(struct FlagObj_021dd010* obj);

struct StatStages_021edcc8 {
	char pad0[0x58];
	signed int attack : 3;
	signed int defense : 3;
	signed int agility : 3;
	signed int charm : 3;
	signed int magicalMight : 3;
	signed int magicalMending : 3;
	signed int stage18 : 3;
	signed int stage21 : 3;
	signed int stage24 : 3;
	signed int stage27 : 3;
};

struct Ctx_021edcc8 { int battle; };

// USA: func_ov024_021edcc8
extern "C" ARM int func_ov024_021edcc8(struct Ctx_021edcc8* ctx, int id) {
	GameObject* c = GetCombatantByID(ctx->battle, id);
	if (!c) return 0;
	if (CheckFlag0x14Bit0x10Set_020882f8((unsigned char*)c->currentStats_)) return 1;
	if (IsFlagBit5Set_021de25c((struct FlagObj_021de25c*)c)) return 1;
	if (IsFlagBit8Set_021da9b0((struct FlagObj_021da9b0*)c)) return 1;
	if (IsFlagBit19Set_021da9c8((struct FlagObj_021da9c8*)c)) return 1;
	if (CheckFlag0x2AndKind1_020885b4((struct Combatant_20885b4*)c->currentStats_)) return 1;
	if (CheckFlag0x2AndState2_02088514((struct S88514*)c->currentStats_)) return 1;
	if (IsFlagBit6Set_021df6ec((struct FlagObj_021df6ec*)c)) return 1;
	if (IsFlagBit8Set_021dd010((struct FlagObj_021dd010*)c)) return 1;
	struct StatStages_021edcc8* s = (struct StatStages_021edcc8*)c->currentStats_;
	if (s->attack < 0) return 1;
	if (s->defense < 0) return 1;
	if (s->agility < 0) return 1;
	if (s->charm < 0) return 1;
	if (s->magicalMight < 0) return 1;
	if (s->magicalMending < 0) return 1;
	if (s->stage18 < 0) return 1;
	if (s->stage21 < 0) return 1;
	if (s->stage27 < 0) return 1;
	return s->stage24 < 0;
}
