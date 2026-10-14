#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

int GetGlobal02109400(void);
extern "C" void func_02094ab0(void);
void SetByteField0x253(void* obj);
void* GetDataPtr02114e04_020d6c00(void);

struct FlagWord020466f4;
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);

int GetFieldIfFlag4(char* obj);
void SetField0x23cTrue(void* obj);
void InitContext020e1154(void* obj);

struct Flags0xc1_020e455c {
    unsigned char a : 2;
    unsigned char rest : 6;
};

struct MainStruct020e455c {
    char pad0[0x1];
    unsigned char f1;
    char pad2[0xc - 0x2];
    short fc;
};

// USA: func_020e455c
ARM void ProcessBattleTick020e455c(struct MainStruct020e455c* obj) {
    GameState* battleStruct = GameState::GetInstance();
    GetGlobal02109400();
    func_02094ab0();
    GameObject* c = battleStruct->GetUnknownGameObject();
    if (c != 0) {
        SetByteField0x253(c);
    }
    ClearFlags020466f4((struct FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 2);

    unsigned int mask = 0x1000000;
    int i;
    for (i = 0; i < 4; i++) {
        GameObject* cc = battleStruct->GetPartyMemberByIndex(i);
        if (cc != 0) {
            ((Object3D*)((unsigned char*)cc))->DisableFlag(mask);
            ((struct Flags0xc1_020e455c*)((char*)cc + 0xc1))->a &= ~2;
        }
    }

    if (obj->fc >= 0) {
        int val = (int)BackgroundLoader::GetInstance();
        ((BackgroundLoader*)(val))->RemoveTask((int)(obj->fc));
        obj->fc = -1;
    }

    SetField0x23cTrue((void*)GetFieldIfFlag4((char*)battleStruct));
    InitContext020e1154((void*)0x3e8);
    obj->f1 = 1;
}
