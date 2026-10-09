#include <globaldefs.h>
#include <GameState/GameState.h>

struct SearchStruct0202c1a4;
struct TailList020469b4;
struct TailNode020469b4;
struct Obj_021bd3a4;
struct TransitionEvent {
    char pad_0[4];
    unsigned short firstArea;
    unsigned short fallbackDestination;
    unsigned short destination;
    unsigned short secondArea;
    unsigned short field_c;
    unsigned char enabled;
    signed char recipient;
    float parameter;
};
struct TransitionState {
    char pad_0[2];
    unsigned char queued;
    unsigned char active;
    char pad_4[4];
    unsigned short destination;
    char pad_a[0xc];
    unsigned short firstDestination;
    unsigned short secondDestination;
    char pad_1a[0x36];
    unsigned short field_50;
    char pad_52[0xc4];
    signed char sender;
    char field_117;
    unsigned short currentDestination;
    char pad_11a[0x5e];
    unsigned char valid : 1;
    unsigned char flags : 7;
    unsigned char field_179;
    unsigned char field_17a;
    unsigned char field_17b;
    float parameter;
    char pad_180[0x48];
};
struct AreaState { unsigned short area; char pad_2[0x27d4]; unsigned short destination; };
struct AlternateArea { unsigned short area; };
struct AlternateMode { char pad_0[3]; unsigned char enabled; };
struct GameStatus { char pad_0[0x5cac]; unsigned char blocked; };
struct ResourceStatus { char pad_0[0x44ac]; unsigned short destination; };
struct Get28ByteElementAt0x334Elem { unsigned char field_0; unsigned char field_1; unsigned char field_2; char pad_3[25]; };
struct Get28ByteElementAt0x334Struct { char pad_0[0x332]; unsigned char index; char field_333; };
extern "C" Get28ByteElementAt0x334Struct* func_0205ec34();
extern "C" AreaState* func_02012fe4();
extern "C" int func_0202c540(SearchStruct0202c1a4*);
signed char GetSearchStructCurrentArrEntry(SearchStruct0202c1a4*);
void* GetField0x3f8Address(GameState*);
int IsField0Null(void**);
extern "C" void func_ov017_021baedc(void*, int);
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);
Get28ByteElementAt0x334Elem* Get28ByteElementAt0x334(Get28ByteElementAt0x334Struct*, int);
extern "C" int _Z29HasFlag3orFlag2And9a_021bd3a4P12Obj_021bd3a4(Obj_021bd3a4*);
extern "C" int func_0202c508(SearchStruct0202c1a4*);
extern "C" void func_ov017_021bc6e0(TransitionState*, int, int);

// USA: func_ov017_021cd748
extern "C" ARM void func_ov017_021cd748(int sender, TransitionEvent* event, GameState* game, GameResources* resources, SearchStruct0202c1a4* search) {
    int matches;
    GameState* instance;
    TransitionState* state;
    unsigned short area;
    instance = GameState::GetInstance();
    TailList020469b4* list = (TailList020469b4*)resources->unknown_ptr_array_36fc[0];
    state = (TransitionState*)resources->unknown_ptr_array_371c[6];
    func_0205ec34();
    AreaState* areaState = func_02012fe4();
    area = areaState->area;
    if ((func_0202c540(search) && sender == 0) || event->enabled) {
        if (event->recipient >= 0 && event->recipient != GetSearchStructCurrentArrEntry(search)) return;
        if (((GameStatus*)instance)->blocked) return;
        matches = 0;
        if (area == event->firstArea) matches = 1;
        if (area == event->secondArea) matches = 1;
        if (!matches && ((AlternateMode*)resources->unknown_ptr_array_36fc[4])->enabled) {
            unsigned short alternate = ((AlternateArea*)GetField0x3f8Address(game))->area;
            if (alternate == event->firstArea) matches = 1;
            if (alternate == event->secondArea) matches = 1;
        }
        if (!matches) return;
        unsigned short destination = event->destination;
        if (!destination) destination = event->fallbackDestination;
        if (!destination) return;
        if (IsField0Null((void**)list) || event->enabled) {
            int changed = 0;
            if (!state->active) {
                if (state->queued) {
                    if (event->destination == state->currentDestination) return;
                    state->destination = destination;
                    if (event->enabled) state->sender = sender;
                    changed = 1;
                } else {
                    if (destination == areaState->destination) return;
                    func_ov017_021baedc(state, 1);
                    state->destination = destination;
                    if (event->enabled) state->sender = sender;
                    AppendNodeToTail(list, (TailNode020469b4*)state);
                    changed = 1;
                }
            }
            if (changed && func_0202c540(search)) {
                Get28ByteElementAt0x334Struct* party = func_0205ec34();
                Get28ByteElementAt0x334Elem* entry = Get28ByteElementAt0x334(party, party->index);
                state->valid = 0;
                state->flags = 0;
                state->field_179 = 0;
                state->field_17a = 0;
                state->field_17b = 0;
                state->parameter = -1.0f;
                state->valid = 1;
                state->field_179 = entry->field_0;
                state->field_17a = entry->field_1;
                state->field_17b = entry->field_2;
                state->parameter = event->parameter;
            }
        } else {
            if (!_Z29HasFlag3orFlag2And9a_021bd3a4P12Obj_021bd3a4((Obj_021bd3a4*)state)) ((ResourceStatus*)resources)->destination = destination;
        }
    } else {
        if (func_0202c508(search) && _Z29HasFlag3orFlag2And9a_021bd3a4P12Obj_021bd3a4((Obj_021bd3a4*)state)) {
            unsigned short requested = event->fallbackDestination;
            unsigned short second = state->secondDestination;
            unsigned short first = state->firstDestination;
            if (requested == second || requested == first) func_ov017_021bc6e0(state, sender, state->field_50);
        }
    }
}
