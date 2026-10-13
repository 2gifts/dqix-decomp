#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "std_library_functions.h"

struct State021c1af0 { unsigned char pad0, done; char pad2[6]; int step, alternate; };
struct Context021c1af0 {
    char pad0[0x2774];
    Vector3i primaryPosition;
    int primaryField;
    char pad2784[0x30];
    unsigned short kind;
    char pad27b6[2];
    Vector3i alternatePosition;
    int alternateField;
    char pad27c8[0x57];
    unsigned char field_281f;
};
struct Action021c1af0 {
    unsigned short kind;
    unsigned char field_2;
    char pad3[4];
    unsigned char field_7;
    char pad8[8];
    Vector3i position;
    unsigned short field_1c;
};
struct TailNode020469b4 { char pad[8]; unsigned short kind; };
struct TailList020469b4;
struct Resource021c1af0 {
    char pad[0x36fc];
    TailList020469b4* list;
    char pad3700[0x34];
    TailNode020469b4* node;
};
struct Obj02046574 {
    char pad0[0x5c];
    char* buffer;
    char pad60[0x938];
    int active;
    char pad99c[4];
    int busy;
    char pad9a4[0x100a];
    unsigned char field_19ae;
    char pad19af[3];
    unsigned char field_19b2;
};
struct Obj020397cc;
struct SearchStruct0202c1a4;
extern "C" Context021c1af0* func_02012fe4();
extern "C" int* func_0202ae18();
Obj02046574* GetGlobalField0x1c020421a0();
void CancelPendingAction020397cc(Obj020397cc*, int);
void* GetGlobal02109400();
void BlankFunction02094b30();
int AlwaysTrue02094b4c();
void BlankFunction02094b38();
extern "C" void func_02094ab0(void*);
int CheckField0NonZero(int*);
void* GetSearchStructCurrentArrEntry(SearchStruct0202c1a4*);
extern "C" int func_ov017_0219ff58(GameResources*, int, int, int);
Action021c1af0* GetField0x3f8Address(GameState*);
void InitStruct02070378(char*);
extern "C" void func_ov017_021baedc(TailNode020469b4*, int);
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);
void SetHalfFieldsAndEnqueueIfActive_021d1c2c(unsigned short, unsigned short);
void EnqueueEventTagB5_021d1dc0(short, short, int*, short, int);
const char* CallFunc020e0434With02153694(int);
void SetIndexedName02046574(Obj02046574*, int, char*);
extern "C" void func_0204500c(void*, const char*, int, int);
int CheckBitsInField0x63dc(void*, int);
extern "C" void func_ov017_0219c520();
void ReinitController02043204(char*);
void SetByteField0x253(void*);

// USA: func_ov017_021c1af0
extern "C" ARM void func_ov017_021c1af0(State021c1af0* state) {
    GameState* game = GameState::GetInstance();
    Context021c1af0* context = func_02012fe4();
    if (state->step == 0) {
        CancelPendingAction020397cc((Obj020397cc*)game->GetProtagonist(), 1);
        void* global = GetGlobal02109400();
        ((void (*)(void*, int, int))BlankFunction02094b30)(global, 0x204, 0);
        if (((int (*)(void*))AlwaysTrue02094b4c)(global)) state->step = 1;
    } else if (state->step == 1) {
        Obj02046574* controller = GetGlobalField0x1c020421a0();
        int* search = func_0202ae18();
        if (!CheckField0NonZero(search) || (CheckField0NonZero(search) && GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search) == 0)) {
            GameResources* resources = func_ov017_0218b5b0();
            Resource021c1af0* resource = (Resource021c1af0*)resources;
            TailList020469b4* list = resource->list;
            TailNode020469b4* node = resource->node;
            if (func_ov017_0219ff58(resources, 1, 0, 0)) {
                state->step = 2;
                return;
            }
            game->GetProtagonist();
            Action021c1af0* action = GetField0x3f8Address(game);
            if (state->alternate == 0) {
                InitStruct02070378((char*)action);
                action->field_2 = 1;
                action->field_7 = 1;
                action->kind = 0x2710;
                action->position = context->primaryPosition;
                action->field_1c = context->primaryField;
            } else if (context->kind == 3) {
                func_ov017_021baedc(node, 1);
                node->kind = 0x7345;
                context->field_281f = 1;
                AppendNodeToTail(list, node);
                SetHalfFieldsAndEnqueueIfActive_021d1c2c(0, 1);
                int position[3];
                EnqueueEventTagB5_021d1dc0(0, 0, position, 0x7345, 0);
            } else {
                InitStruct02070378((char*)action);
                action->field_2 = 1;
                action->field_7 = 1;
                action->kind = 0x2774;
                action->position = context->alternatePosition;
                action->field_1c = context->alternateField;
            }
            state->step = 2;
        } else {
            char* buffer = controller->buffer;
            if (state->alternate == 0) sprintf(buffer, CallFunc020e0434With02153694(0x3c));
            else sprintf(buffer, CallFunc020e0434With02153694(0x3d));
            SetIndexedName02046574(controller, 0, (char*)game->GetUnknownGameObject()->baseStats_);
            func_0204500c(controller, buffer, 0, 0xe3);
            controller->field_19b2 = 0;
            controller->active = 1;
            state->step = 3;
        }
    } else if (state->step == 2) {
        if (CheckBitsInField0x63dc(game, 1)) {
            func_ov017_0219c520();
        }
        void* global = GetGlobal02109400();
        ((void (*)(void*, int))BlankFunction02094b38)(global, 0x1f9);
        func_02094ab0(global);
        state->done = 1;
    } else if (state->step == 3) {
        Obj02046574* controller = GetGlobalField0x1c020421a0();
        controller->field_19ae = 0;
        if (!controller->busy) {
            ReinitController02043204((char*)controller);
            SetByteField0x253(game->GetProtagonist());
            void* global = GetGlobal02109400();
            ((void (*)(void*, int))BlankFunction02094b38)(global, 0x204);
            func_02094ab0(global);
            state->done = 1;
        }
    }
}
