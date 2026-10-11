#include <globaldefs.h>
#if defined(jpn)
enum { kIntrinsicOffset = 0x144 };
#else
enum { kIntrinsicOffset = 0x150 };
#endif
#include "GameState/GameState.h"
struct Intrinsic020dd8b4 { unsigned int field_0; unsigned int agility : 10; unsigned int field_4 : 22; };
struct Combatant020dd8b4 { char pad[0x134]; BaseCombatStats* stats; char pad_0x138[kIntrinsicOffset - 0x138]; Intrinsic020dd8b4* intrinsic; };
struct Details020dd8b4 { int arg; char fields[0x30]; };
struct Summary020dd8b4 {
    int id;
    Details020dd8b4 details;
    unsigned char flag;
    char pad_0x39[3];
    unsigned short attack; short field_0x3e;
    unsigned short defense; short field_0x42;
    int slotBonus; int field_0x48;
    int charmBonus; int field_0x50;
    int mightBonus; int field_0x58;
    int mendingBonus; int field_0x60;
    unsigned short intrinsicAgility; short field_0x66;
    unsigned short agility; short field_0x6a;
    unsigned short might; short field_0x6e;
    unsigned short mending; short field_0x72;
    unsigned short hp; short field_0x76;
    unsigned short mp;
};
char* GetFieldAt0x150(unsigned char*);
int AccumulateSlotBits20To29AsTenths(char*);
extern "C" int _Z23AccumulateCharm02084ee8Pv(void*);
extern "C" int _Z30AccumulateMagicalMight02084f58Pv(void*);
extern "C" int _Z32AccumulateMagicalMending02084e78Pv(void*);
extern "C" void func_02083e28(char*, Details020dd8b4*);
static inline int IsPartyMember020dd8b4(int id) { return id >= 0 && id <= 3; }
// USA: func_020dd8b4
extern "C" ARM void func_020dd8b4(Summary020dd8b4* obj, int id, int arg, unsigned char flag) {
    if (!IsPartyMember020dd8b4(id)) return;
    obj->id = id;
    obj->details.arg = arg;
    obj->flag = flag;
    Combatant020dd8b4* combatant = (Combatant020dd8b4*)GetCombatantWithFlag0x100(GameState::GetInstance(), obj->id);
    if (!combatant) return;
    char* data = GetFieldAt0x150((unsigned char*)combatant);
    obj->attack = combatant->stats->primaryStats.attack;
    obj->defense = combatant->stats->primaryStats.defense;
    obj->slotBonus = AccumulateSlotBits20To29AsTenths(data);
    obj->charmBonus = _Z23AccumulateCharm02084ee8Pv(data);
    obj->mightBonus = _Z30AccumulateMagicalMight02084f58Pv(data);
    obj->mendingBonus = _Z32AccumulateMagicalMending02084e78Pv(data);
    obj->intrinsicAgility = combatant->intrinsic->agility;
    obj->agility = combatant->stats->primaryStats.agility;
    obj->might = combatant->stats->primaryStats.magicalMight;
    obj->mending = combatant->stats->primaryStats.magicalMending;
    obj->hp = combatant->stats->primaryStats.maxHP;
    obj->mp = combatant->stats->primaryStats.maxMP;
    func_02083e28(data, &obj->details);
}
