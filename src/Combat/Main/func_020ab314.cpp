#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "System/Memory.h"
#include "std_library_functions.h"

struct Buf020a94f8 { int checksum; char field_4[4]; char signature[12]; };
struct SaveBody020ab314 {
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
    char extra6d4c[0x214];
};
struct SaveBuffer020ab314 {
    char prefix[0x10];
    Buf020a94f8 header;
    char globals[0x54];
    char pad_78[0xc];
    SaveBody020ab314 body;
    char pad_6fe4[0x101c];
};
struct SaveScratch020ab314 { char pad_0[0x28000]; SaveBuffer020ab314 buffer; };
struct SaveState020ab314 {
    char pad_0[0x569c];
    char state569c[0x7c];
    char pad_5718[0x5cc8 - 0x5718];
    unsigned char error;
    char pad_5cc9[0x5e6c - 0x5cc9];
    char state5e6c[0x110];
    char pad_5f7c[0x6380 - 0x5f7c];
    char globals[0x54];
    char pad_63d4[0x71fc - 0x63d4];
    char state71fc[0x2c4];
    char pad_74c0[0x44];
    char state7504[0xec];
    char state75f0[0x4d0];
    char state7ac0[0x3b4];
};
struct Globals020ab314 { char data[0xa0]; char pad_a0[0xd8]; char extra[0x330]; };
struct StateBits5ccc_11544;
extern unsigned char data_0211e33c[0x30000] __attribute__((aligned(4)));
extern const char data_020f1bf0[];
extern "C" int func_02075910(int, void*, unsigned int, int);
extern "C" int _Z20VerifyBuffer020a94f8P11Buf020a94f8i(Buf020a94f8*, int);
int VerifyAndApplySaveBuffer(int);
void SetFlag0x5cccBit0(StateBits5ccc_11544*);
extern "C" int func_01ff85b8(void*, int);
extern "C" void* func_0205ec34();
Globals020ab314* GetGlobal02109418();
extern "C" void* _Z20GetSlotEntry020108d8Pci(char*, int);
extern "C" void func_020a95a4(void*, void*, unsigned char*);
extern "C" int func_020a9a50(void*, void*, int);
void LoadBattleRegion0x5cdc(unsigned char*);
extern "C" void func_020a9b2c(void*);
extern "C" void _Z32CopyBlobIntoBattleStruct020a9ba4Pv(void*);
extern "C" void func_020a9c14(void*);
extern "C" void _Z32CopyBlobIntoBattleStruct020a9d78Pv(void*);
extern "C" void func_020a9e30(void*);

// USA: func_020ab314
extern "C" ARM int func_020ab314(int* output, int unused, int alternate) {
    GameState* state = GameState::GetInstance();
    SaveState020ab314* saveState = (SaveState020ab314*)state;
    saveState->error = 0;
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    int valid;
    int id;
    SaveBuffer020ab314* buffer;
    valid = 1;
    if (alternate) id = 0x8084;
    else id = 0x84;
    buffer = &((SaveScratch020ab314*)data_0211e33c)->buffer;
    VectorizedMemset(buffer, 0, 0x8000);
    if (!func_02075910(0, buffer, 0x10, 0)) valid = 0;
    Buf020a94f8 header;
    if (!_Z20VerifyBuffer020a94f8P11Buf020a94f8i(&header, alternate != 0)) valid = 0;
    VectorizedInvertedMemcpy(&header, &buffer->header, 0x14);
    VerifyAndApplySaveBuffer(alternate ? 1 : 0);
    VectorizedInvertedMemcpy(saveState->globals, buffer->globals, 0x54);
    if (!func_02075910(id, &buffer->body, 0x6f60, 0)) valid = 0;
    SaveBody020ab314* body = &buffer->body;
    if (!strcmp(header.signature, data_020f1bf0) && valid) {
        if (func_01ff85b8(body->actorData, 0x6f5c) != body->checksum) {
            saveState->error = alternate ? 3 : 2;
            valid = 0;
        }
    }
    if (!valid) {
        SetFlag0x5cccBit0((StateBits5ccc_11544*)state);
        BackgroundLoader::RemoveLockGlobal();
        return 0;
    }
    void* context = func_0205ec34();
    Globals020ab314* globals = GetGlobal02109418();
    unsigned char status = 0;
    func_020a95a4(body->actorData, _Z20GetSlotEntry020108d8Pci((char*)state, 0), &status);
    func_020a9a50(body->context, context, 0);
    memcpy(globals, body->globalData, 0xa0);
    memcpy(GetGlobal02109418()->extra, body->globalExtra, 0x330);
    LoadBattleRegion0x5cdc(body->region);
    memcpy(saveState->state75f0, body->state75f0, 0x4d0);
    memcpy(saveState->state7ac0, body->state7ac0, 0x3b4);
    memcpy(saveState->state7504, body->state7504, 0xec);
    func_020a9b2c(body->load3ec4);
    _Z32CopyBlobIntoBattleStruct020a9ba4Pv(body->battle5a04);
    func_020a9c14(body->battle5e08);
    memcpy(((SaveState020ab314*)GameState::GetInstance())->state569c, body->state569c, 0x7c);
    if (alternate) {
        _Z32CopyBlobIntoBattleStruct020a9d78Pv(body->extra695c);
        func_020a9e30(body->extra6d4c);
    }
    memcpy(((SaveState020ab314*)GameState::GetInstance())->state71fc, body->state71fc, 0x2c4);
    memcpy(((SaveState020ab314*)GameState::GetInstance())->state5e6c, body->state5e6c, 0x110);
    BackgroundLoader::RemoveLockGlobal();
    return 1;
}

