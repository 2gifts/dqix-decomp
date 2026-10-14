#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "GameState/GameState.h"

int GetField5cb0Value_0201079c(char* obj);
int GetField5cb4Value_020107d0(char* obj);
int GetField5cb8Value_02010804(char* obj);
void SetBrightness(GameResources*, int, int);
void InitFieldsFromCombatant_0219bcac(unsigned char flag);
void SetField5cb0AndRecordByte0_02010774(char* obj, int v);
void SetField5cb4AndRecordByte1_020107a8(char* obj, int v);
void SetSlotByte020107dc(char* base, int val);

struct Obj021aa41c {
    unsigned char unk0;
    unsigned char flag1;
    unsigned char pad2[6];
    unsigned short f8;
    unsigned short fa;
    unsigned short fc;
};

// USA: func_ov017_021aa41c  (semantic: RecordPositionAndSyncCounters_021aa41c)
extern "C" ARM void func_ov017_021aa41c(Obj021aa41c* p) {
    GameState* battleStruct = GameState::GetInstance();
    char* obj = (char*)battleStruct;
    int v0 = GetField5cb0Value_0201079c(obj);
    int v4 = GetField5cb4Value_020107d0(obj);
    int v8 = GetField5cb8Value_02010804(obj);
    if (v0 * 10000 + v4 * 100 + v8 != p->f8 * 10000 + p->fa * 100 + p->fc) {
        InitFieldsFromCombatant_0219bcac(0);
    } else {
        GameResources* ov = func_ov017_0218b5b0();
        SetBrightness((GameResources*)ov, 0, 30);
    }
    SetField5cb0AndRecordByte0_02010774(obj, p->f8);
    SetField5cb4AndRecordByte1_020107a8(obj, p->fa);
    SetSlotByte020107dc(obj, p->fc);
    p->flag1 = 1;
}
