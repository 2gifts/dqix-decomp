#include <globaldefs.h>

#if defined(jpn)
#define func_020ab314 func_020ace34
#endif
#include "GameState/GameState.h"
#include "System/Timing.h"
#include "System/GamecardBusOwnership.h"
#include "System/NetworkIdentity.h"
#include "Filesystem/FileIO.h"
#include "std_library_functions.h"

struct BigFlagObj022114fc;
struct S02211658;
struct SessionSave02244660 {
    int unknown00;
    NetworkIdentity identity;
    unsigned int unknown44;
    unsigned long long checksum;
    unsigned int flags;
};
struct Struct_02245528;
struct FlagWord020466f4;
extern NetworkIdentity data_ov031_02291e68;
extern unsigned char data_ov031_02291e04[];
#if defined(jpn)
static const int kSessionSaveOffset = 0x6120;
static const int kIdentityValueOffset = 0x34;
static const int kTransferDoneOffset = 0x20;
#else
static const int kSessionSaveOffset = 0x6380;
static const int kIdentityValueOffset = 0x10;
static const int kTransferDoneOffset = 0x30;
#endif
extern "C" int func_ov031_02211764(int*, int*);
void ClearGlobal0224e598IfNotNine_02211820();
extern "C" int func_ov031_0221156c(void*);
void InitFlagObjFromPair_022114fc(BigFlagObj022114fc*, int);
int CompareField10PairOrZero_02211608(void*);
int GetField1c_022115d0(void*);
extern "C" void func_ov031_02211020(int, int);
extern "C" void func_ov031_022110f0(void (*)(int));
extern "C" int func_ov031_022111e0();
extern "C" int func_020ab314(int*, int, int);
extern "C" void func_ov031_022120f8();
void* GetDataPtr02114e04_020d6c00();
void ClearFlags020466f4(FlagWord020466f4*, unsigned int);
extern "C" int func_ov031_02211310(int, void*, unsigned int, void (*)(), int);
void* GetFieldIfOtherFieldZero_022112e4();
int ResetIfInactive_0221126c();
extern "C" int func_ov031_02212184();
int IsFieldit0Set_02211644_02211644(void*);
void SelectBattleContextMode2_020d0040(int);
int DispatchCartridgeReadToArm7_020d06fc(void*);
void PrepareAndCommit020d0050(int);
void ClearFlag1AndUpdateChecksum_02211658(S02211658*);
void SetField34AndClear35_37_02245528(Struct_02245528*, int);
extern "C" void func_ov031_0224342c(int);
void SetField48_02243418();

// USA: func_ov031_02244660
// KEEP-NAME: func_ov031_02244660
extern "C" ARM void func_ov031_02244660(Struct_02245528* session) {
    GameState* game = GameState::GetInstance();
    unsigned char* state = (unsigned char*)session;
    if ((*(unsigned char*)(state + 0x35)) == 3 || (*(unsigned char*)(state + 0x35)) == 4) {
        int error, category;
        if (func_ov031_02211764(&error, &category)) {
            (*(unsigned char*)(state + 0x35)) = 7;
            (*(unsigned char*)(state + 0x399)) = 1;
            (*(int*)(state + 0x394)) = -error;
            if (category == 6) {
                (*(unsigned char*)(state + 0x35)) = 8;
            }
            ClearGlobal0224e598IfNotNine_02211820();
        }
    }
    switch ((*(unsigned char*)(state + 0x35))) {
    case 0:
        memcpy(&data_ov031_02291e68, &((SessionSave02244660*)((unsigned char*)game + kSessionSaveOffset))->identity, sizeof(NetworkIdentity));
        if (!func_ov031_0221156c(&data_ov031_02291e68)) {
            InitFlagObjFromPair_022114fc((BigFlagObj022114fc*)&data_ov031_02291e68, 0x5944514a);
        } else if (!CompareField10PairOrZero_02211608(&data_ov031_02291e68)) {
            InitFlagObjFromPair_022114fc((BigFlagObj022114fc*)&data_ov031_02291e68, 0x5944514a);
        }
        int identityValue = GetField1c_022115d0(&data_ov031_02291e68);
        (*(int*)(data_ov031_02291e04 + kIdentityValueOffset)) = identityValue;
        func_ov031_02211020(0x3f6, identityValue);
        func_ov031_022110f0(func_ov031_0224342c);
        if (func_ov031_022111e0()) {
            (*(unsigned char*)(state + 0x35)) = 3;
        } else {
            (*(unsigned char*)(state + 0x35)) = 7;
        }
        break;
    case 3: {
        memset((*(unsigned char**)(state + 0x37c)), 0, 0x6f60);
        int result[2];
        if (!func_020ab314(result, 0, 0)) {
            func_ov031_022120f8();
            ClearFlags020466f4((FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0x80);
            (*(unsigned char*)(state + 0x35)) = 7;
            break;
        }
        (*(unsigned char**)(state + 0x37c)) = (unsigned char*)&data_0211e33c + 0x28000;
        (*(int*)(data_ov031_02291e04 + kTransferDoneOffset)) = 0;
        if (!func_ov031_02211310(1, (*(unsigned char**)(state + 0x37c)), 0x8000, SetField48_02243418, 0)) {
            (*(unsigned char*)(state + 0x35)) = 7;
            break;
        }
        (*(unsigned long long*)(state + 0x3a8)) = GetCurrentTimestamp() + 0xefb5f7;
        (*(unsigned char*)(state + 0x35)) = 4;
        break;
    }
    case 4:
        if ((*(int*)(data_ov031_02291e04 + kTransferDoneOffset))) {
            (*(unsigned long long*)(state + 0x3a8)) = GetCurrentTimestamp() + 0xefb5f7;
            (*(unsigned char*)(state + 0x35)) = 5;
            ((SessionSave02244660*)((unsigned char*)GameState::GetInstance() + kSessionSaveOffset))->flags |= 2;
        } else {
            void* progress = GetFieldIfOtherFieldZero_022112e4();
            unsigned long long now = GetCurrentTimestamp();
            if ((*(void**)(state + 0x3a4)) != progress) {
                (*(void**)(state + 0x3a4)) = progress;
                (*(unsigned long long*)(state + 0x3a8)) = now + 0xefb5f7;
            }
        }
        break;
    case 5:
        if (ResetIfInactive_0221126c()) {
            (*(unsigned char*)(state + 0x35)) = 6;
        } else {
            void* progress = GetFieldIfOtherFieldZero_022112e4();
            unsigned long long now = GetCurrentTimestamp();
            if ((*(void**)(state + 0x3a4)) != progress) {
                (*(void**)(state + 0x3a4)) = progress;
                (*(unsigned long long*)(state + 0x3a8)) = now + 0xefb5f7;
            }
        }
        break;
    case 6:
        if (func_ov031_02212184()) {
            SessionSave02244660* completedSave = ((SessionSave02244660*)((unsigned char*)GameState::GetInstance() + kSessionSaveOffset));
            (*(unsigned char*)(state + 0x44)) |= 2;
            if (IsFieldit0Set_02211644_02211644(&data_ov031_02291e68)) {
                unsigned int owner = GenerateLockOwnerID();
                int success;
                if (owner == (unsigned int)-3) {
                    success = 0;
                } else {
                    (*(unsigned short*)(data_ov031_02291e04 + 0xa)) = owner;
                    SelectBattleContextMode2_020d0040((*(unsigned short*)(data_ov031_02291e04 + 0xa)));
                    success = DispatchCartridgeReadToArm7_020d06fc((void*)0x1001);
                    PrepareAndCommit020d0050((*(unsigned short*)(data_ov031_02291e04 + 0xa)));
                }
                if (success) {
                    ClearFlag1AndUpdateChecksum_02211658((S02211658*)&data_ov031_02291e68);
                    memcpy(&completedSave->identity, &data_ov031_02291e68, sizeof(NetworkIdentity));
                }
            }
            NetworkIdentity identity = data_ov031_02291e68;
            completedSave->checksum = func_ov031_022457e0((int)session, identity);
            (*(unsigned char*)(state + 0x3d0)) = 0;
            SetField34AndClear35_37_02245528(session, 0);
        }
        break;
    case 8:
        if (ResetIfInactive_0221126c()) {
            (*(unsigned char*)(state + 0x35)) = 7;
        }
        break;
    case 7:
        if (func_ov031_02212184()) {
            if (!(*(unsigned char*)(state + 0x399))) {
                int error, category;
                func_ov031_02211764(&error, &category);
                (*(int*)(state + 0x394)) = -error;
            }
            if ((*(int*)(state + 0x394)) == 0x2711 || (*(int*)(state + 0x394)) == 0x2712 ||
                (*(int*)(state + 0x394)) == 0x271a || (*(int*)(state + 0x394)) == 0x2724 ||
                (*(int*)(state + 0x394)) == 0x272e || (*(int*)(state + 0x394)) == 0x2738 ||
                (*(int*)(state + 0x394)) == 0x2742 || (*(int*)(state + 0x394)) == 0x274c) {
                (*(int*)(state + 0x394)) += 0x44c;
            }
            if ((*(int*)(state + 0x394)) == 0) {
                (*(int*)(state + 0x394)) = 0x2b5c;
            }
            (*(unsigned char*)(state + 0x3d0)) = 0;
            (*(unsigned char*)(state + 0x399)) = 1;
            SetField34AndClear35_37_02245528(session, 0);
        }
        break;
    }
}
