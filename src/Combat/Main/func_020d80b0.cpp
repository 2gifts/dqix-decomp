#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "World/Zone3D.h"
#include "Resource/Brightness.h"

struct EntryA68;
struct TableA68 { EntryA68* entries; short count; short field6; };
struct Obj020d8484 {
    unsigned char header[4];
    int field4;
    int state;
    TableA68 table;
    SafeAllocator allocator;
    int task;
};
struct Obj020397cc;
struct Obj0205eaa0;
extern Obj0205eaa0 data_02108760;
extern AllocatorUnion data_02114e20;
extern char data_020f235c[];
extern char data_020f2371[];
extern "C" void func_0202ae18(GameState*);
extern "C" Zone3D* func_02012fe4();
extern "C" void* func_0205ec34();
extern "C" int _Z26GetGlobalField0x1c020421a0v();
int GetFieldIfFlag4(char*);
extern "C" void _Z22ShutdownObject020d8484P11Obj020d8484(Obj020d8484*);
extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(Obj020397cc*, int);
void ClearIntAt0x23c(unsigned char*);
void* AllocateAligned4(AllocatorUnion*, unsigned int);
extern "C" void func_020728ac(TableA68*, SafeAllocator*, void*, unsigned int, int, int, int);
extern "C" void func_02046380(void*);
int GetGlobal02109400();
extern "C" void _Z21BlankFunction02094b30v();
extern "C" int _Z18AlwaysTrue02094b4cv();
extern "C" void _Z21BlankFunction02094b38v();
typedef void (*LegacyStart020d80b0)(int, int, int);
typedef int (*LegacyPoll020d80b0)(int);
typedef void (*LegacyFinish020d80b0)(int, int);
int TestBitInByteArray(int, unsigned char*, int);
void SetOrClearBitInArray(void*, unsigned char*, int, int);
void* FindEntryByKey(TableA68*, int);
extern "C" void func_0204500c(void*, char*, int, int);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0*, int, int);
void SetByteField0x253(void*);
extern "C" void func_02094ab0(int);
extern "C" void _Z29SetCombatModeFromCase020dc2d0i(int);
struct Dialog020d80b0 {
    unsigned char field0[0x5c];
    char* text;
    unsigned char field60[0x998-0x60];
    int busy;
    unsigned char field99c[0x19b2-0x99c];
    unsigned char flag;
};
struct Bits020d80b0 { unsigned char field0[0x8c]; unsigned char flags[1]; };

// USA: func_020d80b0
extern "C" ARM void func_020d80b0(Obj020d8484* self) {
    GameState* state = GameState::GetInstance();
    func_0202ae18(state);
    GameResources* resources = func_ov017_0218b5b0();
    Dialog020d80b0* dialog = (Dialog020d80b0*)_Z26GetGlobalField0x1c020421a0v();
    GameObject* object;
    Bits020d80b0* bits;
    Zone3D_StructPtr_8* zone = func_02012fe4()->pUnknownStruct_8_;
    GrottoStruct* grotto = state->GetGrottoStruct();
    object = state->GetUnknownGameObject();
    bits = (Bits020d80b0*)func_0205ec34();
    unsigned char* field = (unsigned char*)GetFieldIfFlag4((char*)state);
    if (grotto->activeMapData.GetDiscoveryState() != 1) {
        self->state = 7;
        _Z22ShutdownObject020d8484P11Obj020d8484(self);
    }
    if (self->state == 0) {
        _Z27CancelPendingAction020397ccP11Obj020397cci((Obj020397cc*)object, 1);
        ClearIntAt0x23c(field);
        self->allocator.CreateTypeA(AllocateAligned4(&data_02114e20, 0x300), 0x300);
        self->task = BackgroundLoader::GetInstance()->QueueLoadFileInGP2(data_020f235c, data_020f2371, 0);
        self->state = 1;
    } else if (self->state == 1) {
        if (BackgroundLoader::GetInstance()->GetTaskStatus(self->task)) {
            void* data;
            unsigned int length;
            BackgroundLoader::GetInstance()->GetLoadedFileByID(self->task, &data, &length);
            self->allocator.Reset();
            func_020728ac(&self->table, &self->allocator, data, length, 0, 0, 0);
            BackgroundLoader::GetInstance()->RemoveTask(self->task);
            self->task = -1;
            func_02046380(dialog);
            ((LegacyStart020d80b0)_Z21BlankFunction02094b30v)(GetGlobal02109400(), 0x203, 0);
            self->state = 2;
        }
    } else if (self->state == 2) {
        if (((LegacyPoll020d80b0)_Z18AlwaysTrue02094b4cv)(GetGlobal02109400())) {
            if (TestBitInByteArray((int)bits, bits->flags, 0x119e)) self->state = 5;
            else {
                self->state = 3;
                SetOrClearBitInArray(bits, bits->flags, 0x119e, 1);
            }
        }
    } else if (self->state == 3) {
        char* text = dialog->text;
        strcpy(text, (char*)FindEntryByKey(&self->table, 2));
        func_0204500c(dialog, text, 0, 0xe3);
        dialog->flag = 0;
        dialog->busy = 1;
        self->state = 4;
    } else if (self->state == 4) {
        if (!dialog->busy) {
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
            self->state = 5;
        }
    } else if (self->state == 5) {
        char* text = dialog->text;
        strcpy(text, (char*)FindEntryByKey(&self->table, 1));
        func_0204500c(dialog, text, 0, 0xe3);
        dialog->flag = 0;
        dialog->busy = 1;
        self->state = 6;
    } else if (self->state == 6) {
        if (!dialog->busy) {
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
            self->state = 7;
        }
    } else if (self->state == 7) {
        SetByteField0x253(object);
        int global = GetGlobal02109400();
        ((LegacyFinish020d80b0)_Z21BlankFunction02094b38v)(global, 0x203);
        func_02094ab0(global);
        if (zone && !zone->unknown_c_low_) _Z22ShutdownObject020d8484P11Obj020d8484(self);
        else {
            SetSubBrightness(resources, -16, 15);
            self->state = 8;
        }
    } else if (self->state == 8) {
        if (!IsBrightnessTransitionActive(resources)) {
            _Z29SetCombatModeFromCase020dc2d0i(2);
            self->state = 9;
        }
    } else if (self->state == 9) _Z22ShutdownObject020d8484P11Obj020d8484(self);
}
