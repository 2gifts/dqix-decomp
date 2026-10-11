#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Source021dffac { char field_0[0x20]; unsigned short actorIndex; };
struct Target021dffac { char field_0[0xe]; short actorIndex; };
struct Action021dffac {
    unsigned short id; char field_2[0xe]; Source021dffac* source; Target021dffac* target; char field_18[0x10];
};
struct Battle021dffac { char field_0[0x821c]; Action021dffac actions[77]; int count; };
#if defined(jpn)
struct Context021dffac { char field_0[0x218]; Battle021dffac* battle; char field_2a0[0x57c8-0x21c]; int actionIndex; };
#else
struct Context021dffac { char field_0[0x29c]; Battle021dffac* battle; char field_2a0[0x5338]; int actionIndex; };
#endif
union Position021dffac { Vector3fix vector; int coordinates[3]; };
struct Entry021dffac { unsigned char index; char field_1[3]; int flag; GameObject* actor; };
struct Cell021dffac { int x, z; };
extern "C" int _Z20IsMatchingID02163690i(int);
char* GetData02108e10();
extern "C" void* _Z24SearchBothTables02079e2cPci(char*, int);
extern "C" int _Z26CheckSlotEntryKind021627fcPv(void*);
extern "C" int func_ov025_021e1048(Battle021dffac*, Entry021dffac*);
unsigned char GetSubstructByte0x1c(unsigned char*);
unsigned char GetSubstructByte0x1d(unsigned char*);
unsigned char GetSubstructByte0x1e(unsigned char*);
void SetSubstructByte0x1c(unsigned char*, unsigned char);
void SetSubstructByte0x1d(unsigned char*, unsigned char);
void SetSubstructByte0x1e(unsigned char*, unsigned char);
void SetSubstructByte0x1f(unsigned char*, unsigned char);
extern "C" int func_ov025_021e1540(int);
extern "C" Entry021dffac* _Z22FindByteMatch_021e1010Phii(unsigned char*, int, int);
extern "C" void func_ov025_021e110c(unsigned char*, Entry021dffac*, int);
int CheckSubstructFlag0x80(unsigned char*);
extern "C" Cell021dffac func_ov000_0216f74c(int*);
extern "C" void __clear(void*, int);
extern "C" int func_02031468(const Vector3fix*, const Vector3fix*, const Vector3fix*, Vector3fix*);
extern "C" void func_ov025_021e1ff4(unsigned char*, unsigned char, unsigned char*, GameObject*, GameObject*, Entry021dffac*, int);
extern "C" int func_ov025_021e1f40(GameObject*, int);
extern "C" void func_ov025_021e16c8(Entry021dffac*, Entry021dffac*, unsigned char*, Action021dffac*, void*, Entry021dffac*, int);
extern "C" void func_ov025_021e1d54(Entry021dffac*, unsigned char*);
extern "C" int _Z29GetSubByteOrFallback_021e1f08PhS_(unsigned char*, unsigned char*);
extern "C" int _Z25CollectListShorts021628c8PviPi(void*, int, int*);
extern "C" int _Z20AdjustIndex_021dfbd4i(int);

inline int IsSpecialGameObject(unsigned char index) {
    return index >= 0xc0 && index <= 0xc7;
}
inline int IsOccupied021dffac(unsigned char cell) {
    return cell >= 0xf2;
}

inline Action021dffac* SelectAction021dffac(Battle021dffac* battle, int index) {
    Action021dffac* action = &battle->actions[index];
    return action;
}

// JPN: func_ov025_021e08bc
// USA: func_ov025_021dffac
extern "C" ARM int func_ov025_021dffac(Context021dffac* context) {
    GameState* game = GameState::GetInstance();
    Battle021dffac* battle = context->battle;
    int sourceIndex;
    Action021dffac* selected = SelectAction021dffac(battle, context->actionIndex);
    int id = selected->id;
    if (_Z20IsMatchingID02163690i(id)) id = 1;
    void* actionData = _Z24SearchBothTables02079e2cPci(GetData02108e10(), (short)id);
    if (!actionData) return 0;
    if (!_Z26CheckSlotEntryKind021627fcPv(context)) return 0;
    Entry021dffac entries[12];
    int count = func_ov025_021e1048(battle, entries);
    Action021dffac* actions = battle->actions;
    int actionCount = battle->count;
    int selectedIndex = context->actionIndex;
    for (int i = 0; i < count; ++i) {
        SetSubstructByte0x1d((unsigned char*)entries[i].actor, GetSubstructByte0x1c((unsigned char*)entries[i].actor));
        SetSubstructByte0x1f((unsigned char*)entries[i].actor, 0xff);
    }
    for (int i = 0; i < count; ++i) {
        GameObject* actor = entries[i].actor;
        int current = GetSubstructByte0x1c((unsigned char*)actor);
        if (current == GetSubstructByte0x1e((unsigned char*)actor))
            SetSubstructByte0x1c((unsigned char*)actor, (unsigned char)func_ov025_021e1540(actor->obj3D_.unknown_4_));
    }
    sourceIndex = 0;
    if (selected->source) sourceIndex = selected->source->actorIndex;
    Entry021dffac* sourceEntry = _Z22FindByteMatch_021e1010Phii((unsigned char*)entries, count, sourceIndex);
    if (!sourceEntry) return 0;
    int targetIndex = -1;
    if (selected->target) targetIndex = selected->target->actorIndex;
    Entry021dffac* targetEntry = _Z22FindByteMatch_021e1010Phii((unsigned char*)entries, count, targetIndex);
    if (!targetEntry) return 0;
    if (sourceIndex == targetIndex) return 1;
    unsigned char occupied[81];
    unsigned char candidates[81];
    unsigned char processed[12];
    int indices[12];
    Position021dffac position;
    Position021dffac projected;
    Position021dffac targetPosition;
    Position021dffac sourcePosition;
    memset(occupied, 0, sizeof(occupied));
    memset(processed, 0, sizeof(processed));
    Action021dffac* action;
    Action021dffac* previousAction;
    int indexCount;
    Entry021dffac* previousEntry;
    Source021dffac* source;
    for (int i = selectedIndex; i < actionCount; ++i) {
        func_ov025_021e110c(occupied, entries, count);
        action = &actions[i];
        source = action->source;
        if (!source || !action->target) continue;
        int actorIndex = source->actorIndex;
        unsigned char compactIndex = actorIndex;
        if (IsSpecialGameObject(compactIndex)) compactIndex -= 0xbc;
        if (compactIndex < 12) {
            if (processed[compactIndex]) continue;
            processed[compactIndex] = 1;
        }
        GameObject* actor = game->GetCombatantByIndex(actorIndex);
        if (!actor) continue;
        if (selectedIndex == i) {
            GameObject* target = game->GetCombatantByIndex(targetIndex);
            unsigned short actionID = action->id;
            if (actor && target && CheckSubstructFlag0x80((unsigned char*)actor) && (unsigned int)(actionID - 9) <= 2) {
                COPY_ARRAY(sourcePosition.coordinates, ((const Position021dffac*)&actor->obj3D_.position_)->coordinates);
                COPY_ARRAY(targetPosition.coordinates, ((const Position021dffac*)&target->obj3D_.position_)->coordinates);
                int candidateCount = 0;
                for (int cellIndex = 0; cellIndex < 81; ++cellIndex) {
                    if (cellIndex % 18 == 17) continue;
                    Cell021dffac cell = func_ov000_0216f74c(&cellIndex);
                    __clear(&position, 12);
                    position.vector.x = cell.x;
                    position.vector.z = cell.z;
                    if (func_02031468(&sourcePosition.vector, &targetPosition.vector, &position.vector, &projected.vector) < 0x1800)
                        candidates[candidateCount++] = cellIndex;
                }
                func_ov025_021e1ff4(candidates, (unsigned char)candidateCount, occupied, actor, target, entries, count);
            }
        }
        if (!func_ov025_021e1f40(actor, targetIndex)) continue;
        if (selectedIndex == i) {
            func_ov025_021e16c8(sourceEntry, targetEntry, occupied, &actions[selectedIndex], actionData, entries, count);
            SetSubstructByte0x1f((unsigned char*)sourceEntry->actor, GetSubstructByte0x1d((unsigned char*)targetEntry->actor));
        } else {
            Entry021dffac* entry = _Z22FindByteMatch_021e1010Phii((unsigned char*)entries, count, source->actorIndex);
            if (entry && entry->flag) func_ov025_021e1d54(entry, occupied);
            else if (entry && GetSubstructByte0x1c((unsigned char*)entry->actor) != 0xff) {
                int fallback = _Z29GetSubByteOrFallback_021e1f08PhS_((unsigned char*)entry->actor, (unsigned char*)action);
                Entry021dffac* other = _Z22FindByteMatch_021e1010Phii((unsigned char*)entries, count, fallback);
                if (!other) continue;
                func_ov025_021e16c8(entry, other, occupied, &actions[selectedIndex], actionData, entries, count);
                SetSubstructByte0x1f((unsigned char*)entry->actor, GetSubstructByte0x1d((unsigned char*)other->actor));
            }
        }
    }
    for (int i = 0; i < selectedIndex; ++i) {
        func_ov025_021e110c(occupied, entries, count);
        previousAction = &actions[i];
        if (!previousAction->source || !previousAction->target) continue;
        indexCount = _Z25CollectListShorts021628c8PviPi(context, i, indices);
        for (int j = 0; j < indexCount; ++j) {
            int actorIndex = indices[j];
            unsigned char compactIndex = actorIndex;
            if (IsSpecialGameObject(compactIndex)) compactIndex -= 0xbc;
            if (compactIndex < 12) {
                if (processed[compactIndex]) continue;
                processed[compactIndex] = 1;
            }
            previousEntry = _Z22FindByteMatch_021e1010Phii((unsigned char*)entries, count, actorIndex);
            GameObject* actor = game->GetCombatantByIndex(actorIndex);
            if (!actor || !previousEntry || !func_ov025_021e1f40(actor, targetIndex)) continue;
            unsigned char cell = GetSubstructByte0x1e((unsigned char*)actor);
            if (cell < 81 && (!IsOccupied021dffac(occupied[cell]) || occupied[cell] == _Z20AdjustIndex_021dfbd4i(actor->obj3D_.unknown_4_)))
                SetSubstructByte0x1d((unsigned char*)actor, cell);
            else func_ov025_021e1d54(previousEntry, occupied);
            SetSubstructByte0x1e((unsigned char*)actor, 0xff);
            int fallback = _Z29GetSubByteOrFallback_021e1f08PhS_((unsigned char*)actor, (unsigned char*)previousAction);
            GameObject* other = game->GetCombatantByIndex(fallback);
            if (other) SetSubstructByte0x1f((unsigned char*)actor, GetSubstructByte0x1d((unsigned char*)other));
        }
    }
    return 1;
}
