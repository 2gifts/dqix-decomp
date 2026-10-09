#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct FormationFlags { char pad0[0x10]; unsigned int flags_; };
struct FormationActor : GameObject { char pad13C[0xc]; FormationFlags* formation_; };
struct FormationEntry { unsigned char id_, value_; char pad2[6]; FormationActor* actor_; };
struct SourceNode { char pad0[0x20]; unsigned short actor_; char pad22[0xe]; SourceNode* next_; };
struct ActionLists { short id_; char pad2[0xe]; SourceNode* source_; };
struct ActionRecord { char pad0[0x18]; unsigned int flags_; };
struct SixCells { unsigned char cells_[6]; };
struct TimerState { int fields_[3]; int adjacent_; };
extern TimerState _ZZ16GetTimer021ef974vE1s __attribute__((aligned(4)));
extern "C" void _Z27ClearMatchingBytes_021e169cPhi(unsigned char*, int);
unsigned char GetSubstructByte0x1c(unsigned char*);
unsigned int GetSubstructByte0x1d(unsigned char*);
unsigned int GetSubstructByte0x1e(unsigned char*);
void SetSubstructByte0x1d(unsigned char*, unsigned char);
void SetSubstructByte0x1e(unsigned char*, unsigned char);
void SetSubstructByte0x4c(unsigned char*, unsigned char);
extern "C" int func_ov025_021e1540(int);
extern "C" void func_ov000_0216f82c(SixCells*, const int*);
extern "C" void func_ov025_021e1ff4(SixCells*, int, unsigned char*, FormationActor*, FormationActor*, void*, void*);
extern "C" void func_ov025_021e120c(unsigned char*, int, unsigned char, unsigned char, int);
extern "C" void func_ov025_021e12f8(unsigned char*, int, int, unsigned char, int, int);
extern "C" void func_ov025_021e13e0(unsigned char*, FormationEntry*);
extern "C" unsigned int func_ov025_021e161c(int, int, unsigned char*, int);
extern "C" void func_ov025_021e1c20(int, unsigned char*, unsigned char*, int, void*, void*, FormationEntry*);
extern "C" unsigned char func_ov025_021e1480(int, unsigned char*, int);
char* GetData02108e10();
extern "C" ActionRecord* _Z24SearchBothTables02079e2cPci(char*, int);

static inline void SetCell(unsigned char* cells, unsigned int index, unsigned char value) {
    if (index < 81) cells[index] = value;
}
static inline int ActorID(FormationEntry* entry) { int id = entry->actor_->obj3D_.unknown_4_; return id; }
static inline int* FlagAddress(int* flag) { int* result = flag; return result; }

// USA: func_ov025_021e16c8
extern "C" ARM void func_ov025_021e16c8(FormationEntry* self, FormationEntry* target, unsigned char* cells,
    ActionLists* lists, ActionRecord* action, void* work, void* context) {
    unsigned char distances[81];
    unsigned char occupied[81];
    unsigned char nearby[81];
    unsigned char fullCandidates[12];
    SixCells range;
    unsigned char nearCandidates[6];
    SixCells temporary;
    _Z27ClearMatchingBytes_021e169cPhi(cells, self->value_);
    memcpy(distances, cells, 81);
    memset(occupied, 0, 81);
    int participating = 0;
    for (SourceNode* node = lists->source_; node; node = node->next_) {
        if (node->actor_ == ActorID(self)) { participating = 1; break; }
    }
    unsigned int position = GetSubstructByte0x1c((unsigned char*)target->actor_);
    if (!participating) {
        position = GetSubstructByte0x1e((unsigned char*)target->actor_);
        if (position == 255) position = GetSubstructByte0x1d((unsigned char*)target->actor_);
        if (position == 255) position = GetSubstructByte0x1c((unsigned char*)target->actor_);
    } else {
        int packed = func_ov025_021e1540(target->id_);
        func_ov000_0216f82c(&temporary, &packed);
        range = temporary;
        func_ov025_021e1ff4(&range, 6, cells, self->actor_, target->actor_, work, context);
    }
    FormationFlags* formation = 0;
    int distance = 2;
    int radius = 1;
    if (target->actor_->obj3D_.unknown_0_ & 0x400) formation = target->actor_->formation_;
    if (formation) {
        unsigned int extension = (formation->flags_ << 1) >> 30;
        if (extension) { distance += extension; radius += extension; }
    }
    func_ov025_021e120c(distances, position, distance, radius, 0);
    if (participating) {
        func_ov025_021e120c(occupied, position, distance, radius, 0);
        SetCell(occupied, position, target->value_);
        unsigned int extension = 0;
        if (formation) {
            unsigned int value = (formation->flags_ << 1) >> 30;
            if (value) extension = value;
        }
        func_ov025_021e12f8(occupied, position, target->value_, extension, (unsigned char)radius, 0);
    }
    if (formation) {
        unsigned int extension = (formation->flags_ << 1) >> 30;
        if (extension) func_ov025_021e12f8(distances, position, self->value_, extension, 0, 0);
    }
    int reachable = 0;
    if (participating) {
        int cost = distances[GetSubstructByte0x1c((unsigned char*)self->actor_)];
        if ((action->flags_ << 16) >> 28 == 2) {
            if (distance == cost) reachable = 1;
        } else if (cost > 0 && cost <= distance) {
            reachable = 1;
            if (distance - 1 == distances[GetSubstructByte0x1c((unsigned char*)self->actor_)]) {
                int value = 1;
                int* adjacent = FlagAddress(&_ZZ16GetTimer021ef974vE1s.adjacent_);
                *adjacent = value;
            }
        }
    } else if (distance == distances[GetSubstructByte0x1c((unsigned char*)self->actor_)]) reachable = 1;
    if (reachable) {
        func_ov025_021e13e0(cells, self);
        if (participating) {
            unsigned int alternate = func_ov025_021e161c(GetSubstructByte0x1c((unsigned char*)self->actor_), position, distances, distance);
            if (alternate != 255) {
                SetSubstructByte0x1e((unsigned char*)self->actor_, alternate);
                SetCell(cells, (unsigned char)alternate, self->value_);
            }
            func_ov025_021e1c20(GetSubstructByte0x1c((unsigned char*)self->actor_), cells, occupied, distance, work, context, self);
        }
        return;
    }
    unsigned char nearCount = 0;
    unsigned char fullCount = 0;
    for (int i = 0; i < 81; ++i) {
        if (distances[i] == distance - 1) nearCandidates[nearCount++] = i;
        else if (distances[i] == distance) fullCandidates[fullCount++] = i;
    }
    unsigned char selected = 255;
    if (fullCount == 1) selected = fullCandidates[0];
    else if (fullCount > 1) selected = func_ov025_021e1480(GetSubstructByte0x1c((unsigned char*)self->actor_), fullCandidates, fullCount);
    else if (nearCount == 1) selected = nearCandidates[0];
    else if (nearCount > 1) selected = func_ov025_021e1480(GetSubstructByte0x1c((unsigned char*)self->actor_), nearCandidates, nearCount);
    if (participating) {
        ActionRecord* record = _Z24SearchBothTables02079e2cPci(GetData02108e10(), lists->id_);
        if (record && (record->flags_ << 16) >> 28 != 2) {
            memset(nearby, 0, 81);
            func_ov025_021e120c(nearby, position, 1, radius, 0);
            int current = GetSubstructByte0x1c((unsigned char*)self->actor_);
            if ((current < 81 && nearby[current] == 1) || position == current) selected = (unsigned char)current;
        }
    }
    if (selected >= 81) selected = GetSubstructByte0x1c((unsigned char*)self->actor_);
    SetSubstructByte0x1d((unsigned char*)self->actor_, selected);
    if (selected < 81) SetCell(cells, selected, self->value_);
    if (participating) {
        unsigned int alternate = func_ov025_021e161c(selected, position, distances, distance);
        if (alternate != 255) {
            SetSubstructByte0x1e((unsigned char*)self->actor_, alternate);
            SetCell(cells, (unsigned char)alternate, self->value_);
        }
    }
    if (participating) func_ov025_021e1c20(selected, cells, occupied, distance, work, context, self);
    SetSubstructByte0x4c((unsigned char*)self->actor_, target->id_);
}
