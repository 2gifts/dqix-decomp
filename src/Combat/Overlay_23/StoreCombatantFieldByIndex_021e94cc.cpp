#include <globaldefs.h>
#include "GameState/GameState.h"

union Value_021d60f4 { int i; float f; };
struct TaggedValue_021d60f4 { int type; Value_021d60f4 value; };
struct TaggedPtr_021d6134 { int type; int* ptr; };

extern "C" ARM int func_ov017_021d60f4(TaggedValue_021d60f4* a);
extern "C" ARM void func_ov017_021d6134(TaggedPtr_021d6134* a, int val);
extern "C" GameObject* func_ov023_021e8f28(int index);

struct TaggedTriple_021e94cc {
    TaggedValue_021d60f4 combatantIndexTag; // offset 0
    TaggedValue_021d60f4 fieldSelectorTag;  // offset 8
    TaggedPtr_021d6134 destTag;             // offset 0x10
};

struct PackedTriple10_021e94cc { unsigned int f0 : 10; unsigned int f1 : 10; unsigned int f2 : 10; };

struct Transform150_021e94cc {
    struct PackedTriple10_021e94cc pos;   // offset 0
    struct PackedTriple10_021e94cc rot;   // offset 4
    struct PackedTriple10_021e94cc word2; // offset 8
    struct PackedTriple10_021e94cc word3; // offset 0xc
};

// JPN: func_ov023_021e9430
// USA: func_ov023_021e94cc  (semantic: StoreCombatantFieldByIndex_021e94cc)
extern "C" ARM int func_ov023_021e94cc(TaggedTriple_021e94cc* args) {
#if defined(jpn)
 enum { regionalExtensionOffset=0x144 };
#else
 enum { regionalExtensionOffset=0x150 };
#endif
    GameState::GetInstance();
    int combatantIdx = func_ov017_021d60f4(&args->combatantIndexTag);
    GameObject* combatant = func_ov023_021e8f28(combatantIdx);
    if (combatant == 0) {
        return 0;
    }
    int fieldIdx = func_ov017_021d60f4(&args->fieldSelectorTag);
    switch (fieldIdx) {
    case 0: {
        unsigned short v = (*(struct Transform150_021e94cc**)((char*)combatant + regionalExtensionOffset))->pos.f0;
        func_ov017_021d6134(&args->destTag, v);
        break;
    }
    case 1: {
        unsigned short v = (*(struct Transform150_021e94cc**)((char*)combatant + regionalExtensionOffset))->pos.f1;
        func_ov017_021d6134(&args->destTag, v);
        break;
    }
    case 2: {
        unsigned short v = (*(struct Transform150_021e94cc**)((char*)combatant + regionalExtensionOffset))->pos.f2;
        func_ov017_021d6134(&args->destTag, v);
        break;
    }
    case 3: {
        unsigned short v = (*(struct Transform150_021e94cc**)((char*)combatant + regionalExtensionOffset))->rot.f0;
        func_ov017_021d6134(&args->destTag, v);
        break;
    }
    case 4: {
        unsigned short v = (*(struct Transform150_021e94cc**)((char*)combatant + regionalExtensionOffset))->rot.f1;
        func_ov017_021d6134(&args->destTag, v);
        break;
    }
    case 5: {
        unsigned short v = (*(struct Transform150_021e94cc**)((char*)combatant + regionalExtensionOffset))->rot.f2;
        func_ov017_021d6134(&args->destTag, v);
        break;
    }
    case 6: {
        unsigned short v = (*(struct Transform150_021e94cc**)((char*)combatant + regionalExtensionOffset))->word2.f0;
        func_ov017_021d6134(&args->destTag, v);
        break;
    }
    case 7: {
        unsigned short v = combatant->baseStats_->primaryStats.maxHP;
        func_ov017_021d6134(&args->destTag, v);
        break;
    }
    case 8: {
        unsigned short v = combatant->baseStats_->primaryStats.maxMP;
        func_ov017_021d6134(&args->destTag, v);
        break;
    }
    case 9: {
        unsigned short v = combatant->baseStats_->primaryStats.attack;
        func_ov017_021d6134(&args->destTag, v);
        break;
    }
    case 10: {
        unsigned short v = combatant->baseStats_->primaryStats.defense;
        func_ov017_021d6134(&args->destTag, v);
        break;
    }
    case 11: {
        unsigned short v = (*(struct Transform150_021e94cc**)((char*)combatant + regionalExtensionOffset))->word3.f0;
        func_ov017_021d6134(&args->destTag, v);
        break;
    }
    }
    return 1;
}
