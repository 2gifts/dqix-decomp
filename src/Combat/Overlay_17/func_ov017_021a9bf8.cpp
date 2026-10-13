#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/TreasureMapMetadata.h"
#include "System/Memory.h"
#include "std_library_functions.h"

struct Obj020397cc;
struct Obj02046574;
struct Src02011818 {
    unsigned char type;
    unsigned char quality;
    unsigned char legacyLevel;
    char pad_3;
    unsigned short seed;
    unsigned char field_6;
    signed char discoveredBy;
    char pad_8[0xb];
    signed char clearedBy;
    char pad_14[0xc];
    unsigned int location;
    unsigned char field_24;
    char pad_25;
    unsigned short field_26;
};
struct MapHistory021a9bf8 { unsigned char count; unsigned char field_1; TreasureMapMetadata maps[99]; };
struct Frame021a9bf8 { unsigned char nodes[0x34]; Src02011818 names; MapHistory021a9bf8 history; };
struct Window021a9bf8 {
    char pad_0[0x60];
    char* text;
    char pad_64[0x2c8 - 0x64];
    int field_2c8;
    char pad_2cc[0x998 - 0x2cc];
    int busy;
    char pad_99c[0x19b2 - 0x99c];
    unsigned char field_19b2;
};
struct MapTask021a9bf8 {
    unsigned char field_0;
    unsigned char complete;
    char pad_2[6];
    unsigned char stage;
    char pad_9;
    TreasureMapMetadata metadata;
    char pad_26[0x1ec - 0x26];
    char name[0x40];
    char description[0x40];
    unsigned char error;
    unsigned char type;
    unsigned char quality;
    char pad_26f;
    unsigned short seed;
};
unsigned char* GetFieldIfFlag4(char*);
extern "C" int func_ov017_021959b4();
void Something_021a9f58(int);
void* GetGlobal02109400();
extern "C" void func_02094ab0();
void BlankFunction02094b3c();
void BlankFunction02094b30();
void ClearIntAt0x23c(unsigned char*);
int AlwaysTrue02094b4c();
void CancelPendingAction020397cc(Obj020397cc*, int);
void ResetElapsedState020e11a4();
Window021a9bf8* GetGlobalField0x1c020421a0();
void SetIndexedName02046574(Obj02046574*, int, char*);
const char* CallFunc020e0434With02153694(int);
unsigned char ReadBattleField0x64f4Byte();
void CopyOutBattleRegion0x64f4(void*);
void CopyToBattleRegion0x64f4(void*);
extern "C" void func_0204500c(Window021a9bf8*, char*, int, int);
extern "C" int func_020457e0(Window021a9bf8*);
void SetNameEntries02011818(void*, Src02011818*);
void ClearRegion0x649e(char*);
void CopyStringToField0x649e(char*, unsigned int, const char*);
extern "C" void func_ov017_021a9ff0(int);
extern "C" void* func_0205ec34();
int LookupAndForEachNode020649b0(void*, int, void*);
extern "C" void func_0206f81c(void*);
void SetByteField0x253(void*);
extern "C" void func_ov017_021a9fa0(MapTask021a9bf8*);
extern const char data_ov017_021d781f[];
extern const char data_ov017_021d782b[];

// USA: func_ov017_021a9bf8
extern "C" ARM void func_ov017_021a9bf8(MapTask021a9bf8* self) {
    GameState* state = GameState::GetInstance();
    unsigned char* field = GetFieldIfFlag4((char*)state);
    Frame021a9bf8 frame __attribute__((aligned(4)));
    if (func_ov017_021959b4()) { Something_021a9f58((int)self); return; }
    GameObject* object = state->GetUnknownGameObject();
    if (!object) { self->complete = 1; return; }
    if (self->stage == 0) {
        void* global = GetGlobal02109400();
        func_02094ab0();
        ((void (*)(void*, int))BlankFunction02094b3c)(global, 12);
        ((void (*)(void*, int, int))BlankFunction02094b30)(global, 0x203, 0);
        ClearIntAt0x23c(field);
        self->stage = 1;
    } else if (self->stage == 1) {
        GetGlobal02109400();
        if (!AlwaysTrue02094b4c()) return;
        CancelPendingAction020397cc((Obj020397cc*)object, 1);
        ResetElapsedState020e11a4();
        Window021a9bf8* window = GetGlobalField0x1c020421a0();
        char* text = window->text;
        SetIndexedName02046574((Obj02046574*)window, 1, self->description);
        sprintf(text, CallFunc020e0434With02153694(0x40));
        if (((unsigned char (*)(GameState*))ReadBattleField0x64f4Byte)(state) >= 99) {
            self->error = 1;
            strcat(text, data_ov017_021d781f);
            self->stage = 2;
        } else {
            CopyOutBattleRegion0x64f4(&frame.history);
            VectorizedMemset(&frame.history.maps[frame.history.count], 0, 0x1c);
            VectorizedInvertedMemcpy(&self->metadata, &frame.history.maps[frame.history.count], 0x1c);
            frame.history.count++;
            CopyToBattleRegion0x64f4(&frame.history);
            strcat(text, data_ov017_021d782b);
            self->stage = 4;
        }
        func_0204500c(window, text, 0, 0xe3);
        window->busy = 1;
        window->field_19b2 = 0;
    } else if (self->stage == 2) {
        Window021a9bf8* window = GetGlobalField0x1c020421a0();
        if (window->busy) return;
        char* text = window->text;
        SetIndexedName02046574((Obj02046574*)window, 0, self->description);
        sprintf(text, CallFunc020e0434With02153694(0x41));
        window->field_2c8 = 1;
        func_0204500c(window, text, 0, 0xe3);
        window->busy = 1;
        window->field_19b2 = 1;
        self->stage = 3;
    } else if (self->stage == 3) {
        Window021a9bf8* window = GetGlobalField0x1c020421a0();
        if (window->busy) return;
        int choice = func_020457e0(window);
        if (choice == 0) self->stage = 4;
        else if (choice == 1) {
            VectorizedMemset(&frame.names, 0, 0x28);
            frame.names.discoveredBy = 0;
            frame.names.clearedBy = 0;
            frame.names.field_6 = 0;
            frame.names.location = -1;
            frame.names.type = self->type;
            frame.names.quality = self->quality;
            frame.names.legacyLevel = self->seed;
            frame.names.seed = self->seed;
            frame.names.field_6 = 0;
            frame.names.location = self->metadata.Location;
            SetNameEntries02011818(state, &frame.names);
            ClearRegion0x649e((char*)state);
            CopyStringToField0x649e((char*)state, 0, self->name);
            func_ov017_021a9ff0(0);
            self->stage = 5;
        }
    } else if (self->stage == 4) {
        if (GetGlobalField0x1c020421a0()->busy) return;
        GetGlobal02109400();
        func_02094ab0();
        if (LookupAndForEachNode020649b0(func_0205ec34(), 0x1b, frame.nodes)) func_0206f81c(frame.nodes);
        self->stage = 5;
    }
    if (self->stage == 5) {
        SetByteField0x253(state->GetUnknownGameObject());
        func_ov017_021a9fa0(self);
    }
}
