#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Brightness.h"
struct Obj020397cc { char padding[0xb2]; short field_b2; };
struct Struct02046f84 { char padding[0xf0]; };
struct BattleLoad021b6290 {
    unsigned char type, complete;
    char padding2[6];
    unsigned char flag8;
    char padding9[3];
    Struct02046f84 action;
    unsigned char state, delay;
    short streamID, task;
};
struct StreamHeader { char padding[0xe]; unsigned short id; char tail[4]; };
struct StreamOwner021b6290 { char padding[0x10]; StreamHeader header; };
struct Actor0209c678;
struct RootEntries;
struct ListHead02046b60;
struct AxisFloats0203b57c;
extern "C" void* func_02012fe4();
extern "C" unsigned char* func_020704fc();
extern "C" void func_02017c58(void*);
extern "C" int func_02046cc8(Struct02046f84*);
extern "C" int func_0204700c(Struct02046f84*);
extern "C" StreamOwner021b6290* func_ov017_021b8478(void*);
extern "C" void func_0209c480(Actor0209c678*, int);
extern "C" void func_0209c2e0(Actor0209c678*, int, int);
extern "C" void func_0205e944(void*, int);
extern "C" void func_02043124(void*);
extern "C" int abs(int);
extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(Obj020397cc*, int);
extern "C" void _Z30DispatchContextByState0209c678P13Actor0209c678i(Actor0209c678*, int);
int ListContainsId(ListHead02046b60*, int);
extern "C" int _Z25RunBufferedStream0207416ciiP12StreamHeaderi(int, int, StreamHeader*, int);
void SetBitsInField4(unsigned int*, unsigned int);
void SetBitsInWord(unsigned int*, unsigned int);
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
RootEntries* GetGlobalPtr021075f4();
void SetOrClearBit0x10OnEntries(RootEntries*, int);
float GetIntAt0xc(unsigned char*);
int GetAxisIntValue(AxisFloats0203b57c*, int);
extern "C" unsigned int* _Z27GetDataPtr02114e04_020d6c00v();
void OrBitsIntoField0(unsigned int*, unsigned int);
void EmptyStub02047198(Struct02046f84*);
extern "C" void _Z31ResetObjectAndAllocator02046f84P14Struct02046f84(Struct02046f84*);
extern "C" void _Z37ConfigureModeByByte_0218d274_0218d274v();
extern "C" void _Z35ProcessCombatantsIfFlagged_0218f79cPv(void*);
void ProcessSlotField58_021a2840(GameResources*);
extern char data_ov017_021d7c10[];
extern Actor0209c678 data_02109bf4;
extern char data_02108760[];
// USA: func_ov017_021b6290
extern "C" ARM void func_ov017_021b6290(BattleLoad021b6290* self) {
    GameState* game = GameState::GetInstance();
    GameResources* resources = func_ov017_0218b5b0();
    func_02012fe4();
    Obj020397cc* actor = (Obj020397cc*)game->GetUnknownGameObject();
    unsigned char* timing = func_020704fc();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* streamOwner = resources->unknown_ptr_3718;
    if (self->state == 0) {
        _Z27CancelPendingAction020397ccP11Obj020397cci(actor, 1);
        actor->field_b2 = 0;
        if (self->streamID >= 0) {
            self->task = loader->QueueLoadFile(data_ov017_021d7c10, 0);
            _Z30DispatchContextByState0209c678P13Actor0209c678i(&data_02109bf4, 10);
        }
        if (self->streamID <= 0) self->delay = 0;
        if (self->flag8) func_02017c58(func_02012fe4());
        self->state = 1;
    }
    if (self->delay) --self->delay;
    if (self->state == 1) {
        if (func_02046cc8(&self->action)) self->state = 2;
    } else if (self->state == 2) {
        if (self->delay == 0) {
            int id = 23;
            if (self->task > -1) {
                if (!loader->GetTaskStatus(self->task)) return;
                void* data;
                unsigned int length;
                loader->GetLoadedFileByID(self->task, &data, &length);
                StreamHeader temporary;
                StreamHeader* header = &temporary;
                if (ListContainsId((ListHead02046b60*)resources->unknown_ptr_array_36fc[0], 10)) {
                    StreamOwner021b6290* owner = func_ov017_021b8478(streamOwner);
                    if (owner) header = &owner->header;
                }
                if (_Z25RunBufferedStream0207416ciiP12StreamHeaderi((int)header, self->streamID, (StreamHeader*)data, length)) id = header->id;
                loader->RemoveTask(self->task);
                self->task = -1;
            }
            func_0209c480(&data_02109bf4, id);
            func_0209c2e0(&data_02109bf4, 127, 0);
            func_0205e944(data_02108760, 127);
            SetBitsInField4(&resources->brightnessFlags_0, 0x40);
            func_02043124(_Z26GetGlobalField0x1c020421a0v());
            SetOrClearBit0x10OnEntries(GetGlobalPtr021075f4(), 0);
            if ((int)GetIntAt0xc(timing) > 30 || abs(GetAxisIntValue((AxisFloats0203b57c*)resources, 0)) == 16) {
                SetMainBrightness(resources, -16, 0);
                if (GetAxisIntValue((AxisFloats0203b57c*)resources, 1) == 0) {
                    SetSubBrightness(resources, -16, 15);
                }
                self->state = 4;
            } else self->state = 3;
        }
    } else if (self->state == 3) {
        if (func_0204700c(&self->action)) self->state = 4;
    } else if (self->state == 4) {
        if (!IsBrightnessTransitionActive(resources)) {
            SetBitsInField4(&resources->brightnessFlags_0, 4);
            SetBitsInField4(&resources->brightnessFlags_0, 16);
            SetBitsInField4(&resources->brightnessFlags_0, 2);
            SetBitsInWord(&resources->brightnessFlags_0, 4);
            OrBitsIntoField0(_Z27GetDataPtr02114e04_020d6c00v(), 1);
            EmptyStub02047198(&self->action);
            _Z31ResetObjectAndAllocator02046f84P14Struct02046f84(&self->action);
            ((void (*)(GameResources*))_Z37ConfigureModeByByte_0218d274_0218d274v)(resources);
            _Z35ProcessCombatantsIfFlagged_0218f79cPv(resources);
            ProcessSlotField58_021a2840(resources);
            SetOrClearBit0x10OnEntries(GetGlobalPtr021075f4(), 1);
            self->complete = 1;
        }
    }
}
