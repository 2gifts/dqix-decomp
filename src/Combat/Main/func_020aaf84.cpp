#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Graphics/LightingManager.h"
#include "std_library_functions.h"

struct Buf020a94f8 {
    int checksum;
    unsigned char resumed;
    unsigned char version;
    unsigned char unk6[2];
    char signature[8];
    float dayTimer;
};

struct Entry02087574 {
    unsigned char data[0x14];
};

struct EntrySave {
    unsigned short valid;
    short count;
    Entry02087574 entries[3];
};

struct SaveBody020aaf84 {
    int checksum;
    char actorData[0x2ca8];
    char context[0x344];
    char globalData[0xa0];
    char globalExtra[0x330];
    unsigned char region[0x194];
    char state75f0[0x4d0];
    char state7ac0[0x3b4];
    char state7504[0xec];
    char load3ec4[0x1b40];
    char battle5a04[0x404];
    char battle5e08[0xad8];
    char state569c[0x7c];
    char extra695c[0x1c];
    char state71fc[0x2c4];
    char state5e6c[0x110];
    EntrySave entries;
};

struct SaveScratch020aaf84 {
    char pad_0[0x28000];
    SaveBody020aaf84 body;
};

struct SaveState020aaf84 {
    char pad_0[0x569c];
    char state569c[0x7c];
    char pad_5718[0x5cc8 - 0x5718];
    unsigned char error;
    char pad_5cc9[0x5e6c - 0x5cc9];
    char state5e6c[0x110];
    char pad_5f7c[0x71fc - 0x5f7c];
    char state71fc[0x2c4];
    char pad_74c0[0x44];
    char state7504[0xec];
    char state75f0[0x4d0];
    char state7ac0[0x3b4];
};

struct BattleEntries020aaf84 {
    char pad_0[0xf2c];
    Entry02087574 entries[3];
};

struct Context020aaf84 {
    char pad_0[0x8c];
    unsigned char bits[1];
};

struct Globals020aaf84 { char data[0xa0]; char pad_a0[0xd8]; char extra[0x330]; };
struct StateBits5ccc_11544;
struct FlagWord020466f4;

extern unsigned char data_0211e33c[0x30000] __attribute__((aligned(4)));
extern const char data_020f1bf0[];
extern "C" int func_02075910(int, void*, unsigned int, int);
extern "C" int func_01ff85b8(void*, int);
extern "C" Context020aaf84* func_0205ec34();
extern "C" void func_020a95a4(void*, void*, unsigned char*);
extern "C" int func_020a9a50(void*, void*, int);
extern "C" void func_020a9b2c(void*);
extern "C" void func_020a9c14(void*);
extern "C" void func_020a9e30(void*);
extern "C" Zone3D* func_02012fe4();
int VerifyBuffer020a94f8(Buf020a94f8*, int);
void* GetDataPtr02114e04_020d6c00();
void OrBitsIntoField0_020466e4(unsigned int*, unsigned int);
void ClearFlags020466f4(FlagWord020466f4*, unsigned int);
void SetFlag0x5cccBit0_02011544(StateBits5ccc_11544*);
Globals020aaf84* GetGlobal02109418_02094d6c();
void* GetSlotEntry020108d8(char*, int);
void LoadBattleRegion0x5cdc_020a9af8(unsigned char*);
void CopyBlobIntoBattleStruct020a9ba4(void*);
void CopyBlobIntoBattleStruct020a9d78(void*);
void* GetPtrField0x2a04_02010828(GameState*);
void ClearRegion020865ec(char*);
void SetOrClearBitInArray_0206df6c(void*, unsigned char*, int, int);

// USA: func_020aaf84
extern "C" ARM int func_020aaf84(int* output, int unused, int alternate, int quiet) {
    GameState* state;
    Buf020a94f8 header;
    int valid;
    SaveState020aaf84* saveState;
    unsigned int* flags;
    unsigned char status;
    LightingManager* lighting;
    Globals020aaf84* globals;
    int id;
    int j;
    int i;
    BattleEntries020aaf84* battle;
    EntrySave* entries;
    Context020aaf84* context;
    SaveBody020aaf84* body;
    state = GameState::GetInstance();
    saveState = (SaveState020aaf84*)state;
    saveState->error = 0;
    valid = 1;
    if (!VerifyBuffer020a94f8(&header, alternate != 0)) valid = 0;
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    flags = (unsigned int*)GetDataPtr02114e04_020d6c00();
    OrBitsIntoField0_020466e4(flags, 0x2000000);
    if (alternate) id = 0x8084;
    else id = 0x84;
    body = &((SaveScratch020aaf84*)data_0211e33c)->body;
    if (!func_02075910(id, body, 0x6f60, 0)) valid = 0;
    if (!strcmp(header.signature, data_020f1bf0) && valid) {
        if (func_01ff85b8(body->actorData, 0x6f5c) != body->checksum) {
            saveState->error = alternate ? 3 : 2;
            valid = 0;
        }
    }
    if (quiet) {
        ClearFlags020466f4((FlagWord020466f4*)flags, 0x2000000);
        BackgroundLoader::RemoveLockGlobal();
        return valid;
    }
    if (!valid) {
        SetFlag0x5cccBit0_02011544((StateBits5ccc_11544*)state);
        ClearFlags020466f4((FlagWord020466f4*)flags, 0x2000000);
        BackgroundLoader::RemoveLockGlobal();
        return 0;
    }
    context = func_0205ec34();
    globals = GetGlobal02109418_02094d6c();
    status = 0;
    func_020a95a4(body->actorData, GetSlotEntry020108d8((char*)state, 0), &status);
    func_020a9a50(body->context, context, 0);
    memcpy(globals, body->globalData, 0xa0);
    memcpy(GetGlobal02109418_02094d6c()->extra, body->globalExtra, 0x330);
    LoadBattleRegion0x5cdc_020a9af8(body->region);
    memcpy(saveState->state75f0, body->state75f0, 0x4d0);
    memcpy(saveState->state7ac0, body->state7ac0, 0x3b4);
    memcpy(saveState->state7504, body->state7504, 0xec);
    func_020a9b2c(body->load3ec4);
    CopyBlobIntoBattleStruct020a9ba4(body->battle5a04);
    func_020a9c14(body->battle5e08);
    memcpy(((SaveState020aaf84*)GameState::GetInstance())->state569c, body->state569c, 0x7c);
    if (alternate) {
        CopyBlobIntoBattleStruct020a9d78(body->extra695c);
        func_020a9e30(&body->entries);
    } else if (status) {
        entries = &body->entries;
        battle = (BattleEntries020aaf84*)GetPtrField0x2a04_02010828(GameState::GetInstance());
        for (i = 0; i < 3; i++) {
            ClearRegion020865ec((char*)&battle->entries[i]);
        }
        if (entries->valid && entries->count) {
            for (j = 0; j < entries->count; j++) {
                memcpy(&battle->entries[j], &entries->entries[j], sizeof(Entry02087574));
            }
        }
    }
    memcpy(((SaveState020aaf84*)GameState::GetInstance())->state71fc, body->state71fc, 0x2c4);
    memcpy(((SaveState020aaf84*)GameState::GetInstance())->state5e6c, body->state5e6c, 0x110);
    lighting = LightingManager::GetInstance();
    state->SetDayTimer(header.dayTimer);
    lighting->dayNightTimer_ = header.dayTimer;
    lighting->timeOfDayIndex_ = state->GetTimeOfDay();
    lighting->SetZone(func_02012fe4());
    lighting->RecomputeAdvancedLighting();
    SetOrClearBitInArray_0206df6c(context, context->bits, 3, 0);
    ClearFlags020466f4((FlagWord020466f4*)flags, 0x2000000);
    BackgroundLoader::RemoveLockGlobal();
    return 1;
}
