#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include <std_library_functions.h>

struct List02070f98;
struct Struct02070fe4;
struct MonsterDefinition { unsigned short id : 15; unsigned short flag : 1; };
struct DefinitionTable { char pad0[0x400]; unsigned int data[3]; };
struct BattleSelection { char pad0[0x284]; DefinitionTable definitions; };
struct CameraState { char pad0[0x240]; Vector3i position; };
struct Obj02033874;
extern "C" BattleSelection* func_ov017_021b8478(void*);
extern "C" void* _Z34GetActiveCombatWork_ov000_02160130v();
extern "C" int func_ov000_0215eb1c(void*, short*, int, int);
extern "C" int func_ov000_0215ed34(void*, short*, int);
extern "C" int _Z32AppendMissingTableValues02167484Psi(short*, int);
extern "C" int _Z23GetElementCount02070fe4P14Struct02070fe4(Struct02070fe4*);
MonsterDefinition* GetElementIfInBounds(List02070f98*, int);
extern "C" void func_ov025_021e771c(short*, int, short*, int);
extern "C" void func_ov000_02161c0c(void*, int);
extern "C" void _Z27ClearCombatantSlot_0200fd48P9GameStatei(GameState*, int);
extern "C" void func_ov000_021677fc(void*);
extern "C" void _Z38RunFlaglearAndSetMode02167e6c_02167e6cPh(unsigned char*);
extern "C" CameraState* func_ov000_02160f14(void*);
extern "C" void _Z24SetVecYFromValue02033874P11Obj02033874i(Obj02033874*, int);
extern "C" unsigned char* _Z16GetField02163524Pv(void*);
extern "C" GameObject* _Z34GetCombatantWithFlag0x400_0200fea4P9GameStatei(GameState*, int);
extern "C" int _Z29GetSubstructByte0x1c_020493a4Ph(unsigned char*);
extern "C" void func_ov000_02167fb0(void*, GameObject*);
extern "C" void _Z26ResetCombatantSlot020d7334Phi(unsigned char*, int);

// USA: func_ov025_021e7b74
extern "C" ARM int func_ov025_021e7b74(void*, void*, void*, void* battle) {
    int retainedCount;
    DefinitionTable* definitions;
    GameResources* resources = func_ov017_0218b5b0();
    GameState* game = GameState::GetInstance();
    BattleSelection* selection = func_ov017_021b8478(resources->unknown_ptr_3718);
    void* work = _Z34GetActiveCombatWork_ov000_02160130v();
    short retainedIds[8];
    retainedCount = (unsigned char)func_ov000_0215eb1c(battle, retainedIds, 8, 0x10);
    short ids[12];
    unsigned char originalCount = func_ov000_0215ed34(battle, ids, 12);
    unsigned char count = _Z32AppendMissingTableValues02167484Psi(ids, originalCount);
    definitions = &selection->definitions;
    int size = _Z23GetElementCount02070fe4P14Struct02070fe4((Struct02070fe4*)definitions->data);
    for (int i = 0; i < size; ++i) {
        MonsterDefinition* definition = GetElementIfInBounds((List02070f98*)definitions->data, i);
        if (!definition) continue;
        int missing = 1;
        short* id = ids;
        for (int j = 0; j < count; ++j, ++id) {
            if (definition->id == *id) { missing = 0; break; }
        }
        if (missing) ids[count++] = definition->id;
    }
    func_ov025_021e771c(ids, originalCount, ids, count);
    unsigned char retained[8];
    memset(retained, 0, sizeof(retained));
    short* retainedId = retainedIds;
    for (int i = 0; i < retainedCount; ++i) {
        int id = *retainedId;
        retainedId++;
        retained[id - 0xc0] = 1;
        func_ov000_02161c0c(work, id);
    }
    unsigned char* retainedSlot = retained;
    for (short id = 0xc0; id <= 0xc7; ++id, ++retainedSlot) {
        if (!*retainedSlot) _Z27ClearCombatantSlot_0200fd48P9GameStatei(game, id);
    }
    func_ov000_021677fc(work);
    _Z38RunFlaglearAndSetMode02167e6c_02167e6cPh((unsigned char*)work);
    Vector3i cameraPosition = func_ov000_02160f14(work)->position;
    int cameraZ = cameraPosition.z;
    for (int id = 0xc0; id < 0xc8; ++id) {
        GameObject* actor = game->GetCombatantByIndex(id);
        if (!actor) continue;
        Vector3i target = {};
        target.z = cameraZ;
        Vector3i position = actor->obj3D_.position_;
        position.y = 0;
        Vector3i direction;
        Vector3fix_Subtract(&target, &position, &direction);
        direction.y = 0;
        Vector3fix_Normalize(&direction, &direction);
        _Z24SetVecYFromValue02033874P11Obj02033874i((Obj02033874*)actor, fix32_Atan2(direction.x, direction.z));
    }
    unsigned char* slots = _Z16GetField02163524Pv(work);
    short* slotId = retainedIds;
    for (int i = 0; i < retainedCount; ++slotId, ++i) {
        GameObject* actor = _Z34GetCombatantWithFlag0x400_0200fea4P9GameStatei(game, *slotId);
        if (actor && _Z29GetSubstructByte0x1c_020493a4Ph((unsigned char*)actor) == 0xff) {
            func_ov000_02167fb0(work, actor);
            _Z26ResetCombatantSlot020d7334Phi(slots, *slotId);
        }
    }
    return 1;
}
