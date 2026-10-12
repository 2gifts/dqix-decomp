#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Timing.h"
#include "System/GamecardBusOwnership.h"
#include "std_library_functions.h"

struct BigFlagObj022114fc {
    unsigned int words[16];
};
struct S02211658 {
    unsigned int words[16];
};
struct BigStruct022457e0 {
    unsigned int words[16];
};
struct SessionGlobals02244660 {
    unsigned char padding[0xa];
    unsigned short lockOwner;
    unsigned int unknown_0xc;
    int field_0x10;
    unsigned char padding14[0x30 - 0x14];
    int field_0x30;
    unsigned char padding34[4];
};
struct SessionSave02244660 {
    int field_0x0;
    BigFlagObj022114fc identity;
    unsigned char padding44[4];
    unsigned long long checksum;
    unsigned int flags;
    BigFlagObj022114fc* GetIdentity() {
        return &identity;
    }
};
struct SessionGame02244660 {
    unsigned char padding[0x6380];
    SessionSave02244660 save;
    SessionSave02244660* GetSave() {
        return &save;
    }
};
struct Struct_02245528 {
    unsigned char padding[0x34];
    unsigned char category;
    unsigned char phase;
    unsigned char field36;
    unsigned char field37;
    unsigned char padding38[0x44 - 0x38];
    unsigned char flags;
    unsigned char padding45[0x37c - 0x45];
    unsigned char* buffer;
    unsigned char padding380[0x394 - 0x380];
    int error;
    unsigned char padding398;
    unsigned char errorCaptured;
    unsigned char padding39a[0x3a4 - 0x39a];
    void* progress;
    unsigned long long deadline;
    unsigned char padding3b0[0x3d0 - 0x3b0];
    unsigned char pending;
};
struct FlagWord020466f4;
extern BigFlagObj022114fc data_ov031_02291e68;
extern SessionGlobals02244660 data_ov031_02291e04;
struct SaveRegion02244660 {
    unsigned char bytes[0x28000];
};
struct SessionRegion02244660 {
    unsigned char bytes[0x8000];
};
struct SessionBlob02244660 : SaveRegion02244660, SessionRegion02244660 {
};
extern SessionBlob02244660 data_0211e33c;
inline SessionRegion02244660* GetSessionRegion02244660(SessionBlob02244660* storage) {
    return storage;
}
extern "C" int func_ov031_02211764(int*, int*);
extern "C" void _Z37ClearGlobal0224e598IfNotNine_02211820v();
extern "C" int func_ov031_0221156c(void*);
extern "C" void _Z28InitFlagObjFromPair_022114fcP18BigFlagObj022114fci(BigFlagObj022114fc*, int);
extern "C" int _Z33CompareField10PairOrZero_02211608Pv(void*);
extern "C" int _Z19GetField1c_022115d0Pv(void*);
extern "C" void func_ov031_02211020(int, int);
extern "C" void func_ov031_022110f0(void (*)(int));
extern "C" int func_ov031_022111e0();
extern "C" int func_020ab314(int*, int, int);
extern "C" void func_ov031_022120f8();
extern "C" void* _Z27GetDataPtr02114e04_020d6c00v();
extern "C" void _Z18ClearFlags020466f4P16FlagWord020466f4j(FlagWord020466f4*, unsigned int);
extern "C" int func_ov031_02211310(int, void*, unsigned int, void (*)(), int);
extern "C" void* _Z33GetFieldIfOtherFieldZero_022112e4v();
extern "C" int _Z24ResetIfInactive_0221126cv();
extern "C" int func_ov031_02212184();
extern "C" int _Z31IsFieldit0Set_02211644_02211644Pv(void*);
void SelectBattleContextMode2(int);
int DispatchCartridgeReadToArm7(void*);
extern "C" void _Z24PrepareAndCommit020d0050i(int);
extern "C" void _Z36ClearFlag1AndUpdateChecksum_02211658P9S02211658(S02211658*);
extern "C" unsigned long long func_ov031_022457e0(Struct_02245528*, BigStruct022457e0);
extern "C" void _Z32SetField34AndClear35_37_02245528P15Struct_02245528i(Struct_02245528*, int);
extern "C" void func_ov031_0224342c(int);
extern "C" void _Z19SetField48_02243418v();

// USA: func_ov031_02244660
extern "C" ARM void func_ov031_02244660(Struct_02245528* session) {
    SessionGame02244660* game = (SessionGame02244660*)GameState::GetInstance();
    if (session->phase == 3 || session->phase == 4) {
        int error, category;
        if (func_ov031_02211764(&error, &category)) {
            session->phase = 7;
            session->errorCaptured = 1;
            session->error = -error;
            if (category == 6) {
                session->phase = 8;
            }
            _Z37ClearGlobal0224e598IfNotNine_02211820v();
        }
    }
    switch (session->phase) {
    case 0:
        memcpy(&data_ov031_02291e68, game->GetSave()->GetIdentity(), 0x40);
        if (!func_ov031_0221156c(&data_ov031_02291e68)) {
            _Z28InitFlagObjFromPair_022114fcP18BigFlagObj022114fci(&data_ov031_02291e68, 0x5944514a);
        } else if (!_Z33CompareField10PairOrZero_02211608Pv(&data_ov031_02291e68)) {
            _Z28InitFlagObjFromPair_022114fcP18BigFlagObj022114fci(&data_ov031_02291e68, 0x5944514a);
        }
        int identityValue = _Z19GetField1c_022115d0Pv(&data_ov031_02291e68);
        data_ov031_02291e04.field_0x10 = identityValue;
        func_ov031_02211020(0x3f6, identityValue);
        func_ov031_022110f0(func_ov031_0224342c);
        if (func_ov031_022111e0()) {
            session->phase = 3;
        } else {
            session->phase = 7;
        }
        break;
    case 3: {
        memset(session->buffer, 0, 0x6f60);
        int result[2];
        if (!func_020ab314(result, 0, 0)) {
            func_ov031_022120f8();
            _Z18ClearFlags020466f4P16FlagWord020466f4j((FlagWord020466f4*)_Z27GetDataPtr02114e04_020d6c00v(), 0x80);
            session->phase = 7;
            break;
        }
        session->buffer = GetSessionRegion02244660(&data_0211e33c)->bytes;
        data_ov031_02291e04.field_0x30 = 0;
        if (!func_ov031_02211310(1, session->buffer, 0x8000, _Z19SetField48_02243418v, 0)) {
            session->phase = 7;
            break;
        }
        session->deadline = GetCurrentTimestamp() + 0xefb5f7;
        session->phase = 4;
        break;
    }
    case 4:
        if (data_ov031_02291e04.field_0x30) {
            session->deadline = GetCurrentTimestamp() + 0xefb5f7;
            session->phase = 5;
            ((SessionGame02244660*)GameState::GetInstance())->GetSave()->flags |= 2;
        } else {
            void* progress = _Z33GetFieldIfOtherFieldZero_022112e4v();
            unsigned long long now = GetCurrentTimestamp();
            if (session->progress != progress) {
                session->progress = progress;
                session->deadline = now + 0xefb5f7;
            }
        }
        break;
    case 5:
        if (_Z24ResetIfInactive_0221126cv()) {
            session->phase = 6;
        } else {
            void* progress = _Z33GetFieldIfOtherFieldZero_022112e4v();
            unsigned long long now = GetCurrentTimestamp();
            if (session->progress != progress) {
                session->progress = progress;
                session->deadline = now + 0xefb5f7;
            }
        }
        break;
    case 6:
        if (func_ov031_02212184()) {
            SessionSave02244660* completedSave = ((SessionGame02244660*)GameState::GetInstance())->GetSave();
            session->flags |= 2;
            if (_Z31IsFieldit0Set_02211644_02211644Pv(&data_ov031_02291e68)) {
                unsigned int owner = GenerateLockOwnerID();
                int success;
                if (owner == (unsigned int)-3) {
                    success = 0;
                } else {
                    data_ov031_02291e04.lockOwner = owner;
                    SelectBattleContextMode2(data_ov031_02291e04.lockOwner);
                    success = DispatchCartridgeReadToArm7((void*)0x1001);
                    _Z24PrepareAndCommit020d0050i(data_ov031_02291e04.lockOwner);
                }
                if (success) {
                    _Z36ClearFlag1AndUpdateChecksum_02211658P9S02211658((S02211658*)&data_ov031_02291e68);
                    memcpy(completedSave->GetIdentity(), &data_ov031_02291e68, 0x40);
                }
            }
            BigStruct022457e0 identity = *(BigStruct022457e0*)&data_ov031_02291e68;
            completedSave->checksum = func_ov031_022457e0(session, identity);
            session->pending = 0;
            _Z32SetField34AndClear35_37_02245528P15Struct_02245528i(session, 0);
        }
        break;
    case 8:
        if (_Z24ResetIfInactive_0221126cv()) {
            session->phase = 7;
        }
        break;
    case 7:
        if (func_ov031_02212184()) {
            if (!session->errorCaptured) {
                int error, category;
                func_ov031_02211764(&error, &category);
                session->error = -error;
            }
            if (session->error == 0x2711 || session->error == 0x2712 ||
                session->error == 0x271a || session->error == 0x2724 ||
                session->error == 0x272e || session->error == 0x2738 ||
                session->error == 0x2742 || session->error == 0x274c) {
                session->error += 0x44c;
            }
            if (session->error == 0) {
                session->error = 0x2b5c;
            }
            session->pending = 0;
            session->errorCaptured = 1;
            _Z32SetField34AndClear35_37_02245528P15Struct_02245528i(session, 0);
        }
        break;
    }
}
