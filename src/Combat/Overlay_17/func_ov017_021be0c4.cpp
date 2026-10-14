#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "std_library_functions.h"

struct State021be0c4 { unsigned char pad0, done; char pad2[6]; int step, elapsed; };
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
struct Context021be0c4 { char pad[0x2664]; char map[4]; };
struct Obj020397cc;
extern "C" Context021be0c4* func_02012fe4();
extern "C" int* func_0202ae18();
Obj02046574* GetGlobalField0x1c020421a0();
void CancelPendingAction020397cc(Obj020397cc*, int);
void SetForwardAndStore0205ebc0(void*, int, int);
void DispatchIfField0xc4NonNeg_0205ebfc(void*, int, int);
void ForwardField0xc0_0205ebec(void*);
extern char data_02108760[];
extern "C" int func_0208f748(void*, int*);
extern "C" void __clear(void*, unsigned int);
extern "C" void func_020426bc(BaseCombatStats*, char*, int);
extern "C" void VectorizedInvertedMemcpy(const void*, void*, unsigned int);
extern "C" void func_02011744(GameState*);
const char* CallFunc020e0434With02153694(int);
void SetIndexedName02046574(Obj02046574*, int, char*);
extern "C" void func_0204500c(void*, const char*, int, int);
int CheckField0NonZero(int*);
extern "C" int func_0202c508(int*);
extern "C" void func_ov017_021cf730(int, int);
int GetField0x3acValue(GameState*);
void EnqueueEventTag173_021d1810(int, int, signed char);
void ClearBitArray(void*);
void EnqueueEventTag167_021d3ec8();
void ReinitController02043204(char*);
void SetByteField0x253(void*);

// USA: func_ov017_021be0c4
extern "C" ARM void func_ov017_021be0c4(State021be0c4* state) {
    GameState* game = GameState::GetInstance();
    func_0202ae18();
    GameResources* resources = func_ov017_0218b5b0();
    Obj02046574* controller = GetGlobalField0x1c020421a0();
    func_02012fe4();
    GrottoStruct* grotto = game->GetGrottoStruct();
    if (state->step == 0) {
        CancelPendingAction020397cc((Obj020397cc*)game->GetUnknownGameObject(), 1);
        FontBankLoader* global = GetGlobal02109400();
        BlankFunction02094b30(global, 0x203, 0);
        if (AlwaysTrue02094b4c(global)) state->step = 1;
    } else if (state->step == 1) {
        SetMainBrightness(resources, 0x10, 0xf);
        SetForwardAndStore0205ebc0(data_02108760, 0x83, 0x83);
        DispatchIfField0xc4NonNeg_0205ebfc(data_02108760, 0, 0);
        state->step = 2;
    } else if (state->step == 2) {
        if (!IsMainBrightnessTransitionActive(resources)) {
            if (func_0208f748(func_02012fe4()->map, &grotto->entranceX)) {
                grotto->activeMapData.SetDiscoveryState(DiscoveryState_Discovered);
                if (grotto->activeMapData.DiscoveredBy[0] == 0) {
                    char name[10];
                    __clear(name, 10);
                    func_020426bc(game->GetProtagonist()->baseStats_, name, 1);
                    VectorizedInvertedMemcpy(name, grotto->activeMapData.DiscoveredBy, 10);
                }
                func_02011744(game);
                state->step = 3;
            } else state->step = 5;
        }
    } else if (state->step == 3) {
        SetMainBrightness(resources, 0, 0xf);
        state->elapsed = 0;
        state->step = 4;
    } else if (state->step == 4) {
        state->elapsed += game->GetTickCount();
        if (!IsMainBrightnessTransitionActive(resources) && state->elapsed > 30) {
            char* buffer = controller->buffer;
            sprintf(buffer, CallFunc020e0434With02153694(0x3f));
            SetIndexedName02046574(controller, 0, (char*)game->GetUnknownGameObject()->baseStats_);
            func_0204500c(controller, buffer, 0, 0xe3);
            controller->field_19b2 = 0;
            controller->active = 1;
            int* field = func_0202ae18();
            if (CheckField0NonZero(field) && func_0202c508(field)) {
                func_ov017_021cf730(-1, 0);
                EnqueueEventTag173_021d1810(0x2713, -1, GetField0x3acValue(game));
            }
            ClearBitArray(game);
            EnqueueEventTag167_021d3ec8();
            state->step = 5;
        }
    } else if (state->step == 5) {
        controller->field_19ae = 0;
        if (!controller->busy) {
            ReinitController02043204((char*)controller);
            SetByteField0x253(game->GetUnknownGameObject());
            FontBankLoader* global = GetGlobal02109400();
            BlankFunction02094b38(global, 0x203);
            func_02094ab0(global);
            ForwardField0xc0_0205ebec(data_02108760);
            state->done = 1;
        }
    }
}
