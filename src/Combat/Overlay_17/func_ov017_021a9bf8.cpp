#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Grotto/Main/TreasureMapMetadata.h"
#include "Grotto/Main/DetailedTreasureMapData.h"
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
#if defined(jpn)
enum { TextOffset = 0x2c, ChoiceOffset = 0x218, BusyOffset = 0x868, ChoiceFlagOffset = 0x17e2 };
extern const char data_ov017_021d7c96[];
extern const char data_ov017_021d7cbf[];
extern const char data_ov017_021d7ccb[];
extern const char data_ov017_021d7cd1[];
#else
enum { TextOffset = 0x60, ChoiceOffset = 0x2c8, BusyOffset = 0x998, ChoiceFlagOffset = 0x19b2 };
#endif
struct MapTask021a9bf8 {
    unsigned char field_0;
    unsigned char complete;
    char pad_2[6];
    unsigned char stage;
    char pad_9;
    TreasureMapMetadata metadata;
    DetailedTreasureMapData detailed;
#if defined(jpn)
    char name[4][0x20];
    char description[0x80];
#else
    char name[0x40];
    char description[0x40];
#endif
    unsigned char error;
    unsigned char type;
    unsigned char quality;
    char pad_26f;
    unsigned short seed;
};
unsigned char* GetFieldIfFlag4_020100f8(char*);
extern "C" int func_ov017_021959b4();
void Something_021a9f58(int);
void ClearIntAt0x23c_020a27b8(unsigned char*);
void CancelPendingAction020397cc(Obj020397cc*, int);
void ResetElapsedState020e11a4();
char* GetGlobalField0x1c020421a0();
void SetIndexedName02046574(Obj02046574*, int, char*);
const char* CallFunc020e0434With02153694_020e51cc(int);
unsigned char ReadBattleField0x64f4Byte_02011804(GameState* gameState);
void CopyOutBattleRegion0x64f4_020ac760(void*);
void CopyToBattleRegion0x64f4_020ac734(void*);
extern "C" void func_0204500c(char*, char*, int
#if !defined(jpn)
    , int
#endif
);
extern "C" int func_020457e0(char*);
void SetNameEntries02011818(void*, Src02011818*);
void ClearRegion0x649e_02011ab8(char*);
void CopyStringToField0x649e_02011a74(char*, unsigned int, const char*);
extern "C" void func_ov017_021a9ff0(int);
extern "C" void* func_0205ec34();
int LookupAndForEachNode020649b0(void*, int, void*);
extern "C" void func_0206f81c(void*);
void SetByteField0x253_020397c0(void*);
extern "C" void func_ov017_021a9fa0(MapTask021a9bf8*);
extern const char data_ov017_021d781f[];
extern const char data_ov017_021d782b[];

// USA: func_ov017_021a9bf8
extern "C" ARM void func_ov017_021a9bf8(MapTask021a9bf8* self) {
    GameState* state = GameState::GetInstance();
    unsigned char* field = GetFieldIfFlag4_020100f8((char*)state);
    MapHistory021a9bf8 history;
    Src02011818 names;
    unsigned char nodes[0x34];
    if (func_ov017_021959b4()) { Something_021a9f58((int)self); return; }
    GameObject* object = state->GetUnknownGameObject();
    if (!object) { self->complete = 1; return; }
    if (self->stage == 0) {
        FontBankLoader* global = GetGlobal02109400_02094a00();
        func_02094ab0(global);
        BlankFunction02094b3c(global, 12);
        BlankFunction02094b30(global, 0x203, 0);
        ClearIntAt0x23c_020a27b8(field);
        self->stage = 1;
    } else if (self->stage == 1) {
        if (!AlwaysTrue02094b4c(GetGlobal02109400_02094a00())) return;
        CancelPendingAction020397cc((Obj020397cc*)object, 1);
        ResetElapsedState020e11a4();
        char* window = GetGlobalField0x1c020421a0();
        char* text = (*reinterpret_cast<char**>(window + TextOffset));
#if defined(jpn)
        char* protagonistName = state->GetUnknownGameObject()->baseStats_->unk;
        sprintf(text, data_ov017_021d7c96, protagonistName, self->description);
#else
        SetIndexedName02046574((Obj02046574*)window, 1, self->description);
        sprintf(text, CallFunc020e0434With02153694_020e51cc(0x40));
#endif
        if (ReadBattleField0x64f4Byte_02011804(state) >= 99) {
            self->error = 1;
#if defined(jpn)
            strcat(text, data_ov017_021d7cbf);
#else
            strcat(text, data_ov017_021d781f);
#endif
            self->stage = 2;
        } else {
            CopyOutBattleRegion0x64f4_020ac760(&history);
            VectorizedMemset(&history.maps[history.count], 0, 0x1c);
            VectorizedInvertedMemcpy(&self->metadata, &history.maps[history.count], 0x1c);
            history.count++;
            CopyToBattleRegion0x64f4_020ac734(&history);
#if defined(jpn)
            strcat(text, data_ov017_021d7ccb);
#else
            strcat(text, data_ov017_021d782b);
#endif
            self->stage = 4;
        }
        func_0204500c(window, text, 0
#if !defined(jpn)
            , 0xe3
#endif
        );
        (*reinterpret_cast<int*>(window + BusyOffset)) = 1;
        (*reinterpret_cast<unsigned char*>(window + ChoiceFlagOffset)) = 0;
    } else if (self->stage == 2) {
        char* window = GetGlobalField0x1c020421a0();
        if ((*reinterpret_cast<int*>(window + BusyOffset))) return;
        char* text = (*reinterpret_cast<char**>(window + TextOffset));
#if defined(jpn)
        char* protagonistName = state->GetUnknownGameObject()->baseStats_->unk;
        sprintf(text, data_ov017_021d7cd1, self->description, protagonistName, self->description);
#else
        SetIndexedName02046574((Obj02046574*)window, 0, self->description);
        sprintf(text, CallFunc020e0434With02153694_020e51cc(0x41));
#endif
        (*reinterpret_cast<int*>(window + ChoiceOffset)) = 1;
        func_0204500c(window, text, 0
#if !defined(jpn)
            , 0xe3
#endif
        );
        (*reinterpret_cast<int*>(window + BusyOffset)) = 1;
        (*reinterpret_cast<unsigned char*>(window + ChoiceFlagOffset)) = 1;
        self->stage = 3;
    } else if (self->stage == 3) {
        char* window = GetGlobalField0x1c020421a0();
        if ((*reinterpret_cast<int*>(window + BusyOffset))) return;
        int choice = func_020457e0(window);
        if (choice == 0) self->stage = 4;
        else if (choice == 1) {
            VectorizedMemset(&names, 0, 0x28);
            names.discoveredBy = 0;
            names.clearedBy = 0;
            names.field_6 = 0;
            names.location = -1;
            names.type = self->type;
            names.quality = self->quality;
            names.legacyLevel = self->seed;
            names.seed = self->seed;
            names.field_6 = 0;
            names.location = self->metadata.Location;
            SetNameEntries02011818(state, &names);
            ClearRegion0x649e_02011ab8((char*)state);
#if defined(jpn)
            CopyStringToField0x649e_02011a74((char*)state, 0, self->name[0]);
            CopyStringToField0x649e_02011a74((char*)state, 1, self->name[1]);
            CopyStringToField0x649e_02011a74((char*)state, 2, self->name[2]);
            CopyStringToField0x649e_02011a74((char*)state, 3, self->name[3]);
#else
            CopyStringToField0x649e_02011a74((char*)state, 0, self->name);
#endif
            func_ov017_021a9ff0(0);
            self->stage = 5;
        }
    } else if (self->stage == 4) {
        if ((*reinterpret_cast<int*>(GetGlobalField0x1c020421a0() + BusyOffset))) return;
        func_02094ab0(GetGlobal02109400_02094a00());
        if (LookupAndForEachNode020649b0(func_0205ec34(), 0x1b, nodes)) func_0206f81c(nodes);
        self->stage = 5;
    }
    if (self->stage == 5) {
        SetByteField0x253_020397c0(state->GetUnknownGameObject());
        func_ov017_021a9fa0(self);
    }
}
