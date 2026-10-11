#include <globaldefs.h>
#if defined(jpn)
enum { kManagerPrefix = 0x34ec };
#else
enum { kManagerPrefix = 0x36fc };
#endif
#include <GameState/GameState.h>
#include <std_library_functions.h>
struct Obj020a8b0c { char pad[4]; unsigned char mask; char pad2[3]; int progress, step, limit; signed char count; };
struct Actor020a8b0c { Object3D obj; short height, y; };
struct Field020a8b0c { char pad[0xc]; unsigned char flag; };
struct HeadNode02046b24;
struct Party020874bc;
struct Manager020a8b0c { char pad[kManagerPrefix]; HeadNode02046b24** head; };
struct Obj020397cc;
struct Obj02033874;
Field020a8b0c* GetField0x3f8Address(GameState*);
extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(Obj020397cc*, int);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24**);
extern "C" void _Z25ForwardField0xc0_0205eb80Pv(void*);
extern "C" void _Z26SetForwardAndStore0205eb54Pvii(void*, int, int);
extern "C" void _Z34DispatchIfField0xc4NonNeg_0205eb90Pvii(void*, int, int);
extern "C" void _Z24SetVecYFromValue02033874P11Obj02033874i(Obj02033874*, int);
extern "C" void _Z31ApplyToListedCombatants020874bcP13Party020874bci(Party020874bc*, int);
int fix32abs(int);
extern char data_02108760;
// USA: func_020a8b0c
extern "C" ARM void func_020a8b0c(Obj020a8b0c* self, int index) {
    if (!(self->mask & (1<<index))) return;
    GameState* state = GameState::GetInstance();
    Actor020a8b0c* actor = (Actor020a8b0c*)state->GetPartyMemberByIndex(index);
    Field020a8b0c* field = GetField0x3f8Address(state);
    Party020874bc* party;
    HeadNode02046b24** head = ((Manager020a8b0c*)func_ov017_0218b5b0())->head;
    party = (Party020874bc*)GetPtrField0x2a04(state);
    int height = actor->height;
    field->flag = 0;
    _Z27CancelPendingAction020397ccP11Obj020397cci((Obj020397cc*)actor, 1);
    self->progress+=self->step;
    if (self->limit < self->progress) self->progress = self->limit;
    int difference;
    if (GetHeadNodeIdOrMinusOne(head) == 3) { difference = -3686; actor->obj.DisableFlag(0x8000100); }
    else {
        difference = height-self->progress;
        if (fix32abs(difference) < 40) {
            _Z25ForwardField0xc0_0205eb80Pv(&data_02108760);
            _Z26SetForwardAndStore0205eb54Pvii(&data_02108760, 114, 114);
            _Z34DispatchIfField0xc4NonNeg_0205eb90Pvii(&data_02108760, 3, 0);
        }
    }
    actor->height = difference;
    if (difference < 0) {
        int y = actor->y;
        _Z24SetVecYFromValue02033874P11Obj02033874i((Obj02033874*)actor, y+labs(difference));
        _Z31ApplyToListedCombatants020874bcP13Party020874bci(party, self->count);
        int count = self->count;
        if (count > 0) count--;
        self->count = count;
    }
}
