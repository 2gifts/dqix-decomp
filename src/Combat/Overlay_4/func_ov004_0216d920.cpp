#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

unsigned char GetByte0x4(char* obj);
void SetByte0x4(char* obj, unsigned char value);
void SetWord0x7f6c(void* obj, int value);
unsigned char GetByte0x7f70(void* obj);
void SetByte0x7f70(void* obj, unsigned char value);
void ClearBitsInWord(unsigned int* obj, unsigned int mask);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);
void ClearBitsInField8(unsigned int* obj, unsigned int mask);
void SetFieldFlag17188_0218d258(void* obj);
void SetModeClamped0209ca70(void* obj, int val);

struct Actor0209c678;
void DispatchContextByState0209c678(struct Actor0209c678* actor, int arg);
struct Actor0209c20c;
void InitActorContext0209c20c(struct Actor0209c20c* actor);
struct Obj_0205e8ec;
void RefreshDisplayState0205e8ec(struct Obj_0205e8ec* a);
struct Obj0205e9f4;
void SetStateAndDispatch0205e9f4(struct Obj0205e9f4* obj, int state);
struct StateBits5ccc_11544;
void SetFlag0x5cccBit0(struct StateBits5ccc_11544* state);

extern int data_02109bf4;
extern int data_02108760;
extern unsigned char data_ov004_02171034[];

#if defined(jpn)
enum { kStateIndex = 6, kVariantIndex = 0, kModeIndex = 5, kContextIndex = 7, kFlagIndex = 3 };
#else
enum { kStateIndex = 1, kVariantIndex = 2, kModeIndex = 3, kContextIndex = 4, kFlagIndex = 5 };
#endif

// USA: func_ov004_0216d920
extern "C" ARM int func_ov004_0216d920() {
    GameState* bs = GameState::GetInstance();
    GameResources* obj = func_ov017_0218b5b0();
    if (GetByte0x4((char*)bs) != 2) {
        DispatchContextByState0209c678((struct Actor0209c678*)&data_02109bf4, 0);
        InitActorContext0209c20c((struct Actor0209c20c*)&data_02109bf4);
        RefreshDisplayState0205e8ec((struct Obj_0205e8ec*)&data_02108760);
    }
    SetModeClamped0209ca70((void*)&data_02109bf4, data_ov004_02171034[kContextIndex]);
    SetStateAndDispatch0205e9f4((struct Obj0205e9f4*)&data_02108760, data_ov004_02171034[kStateIndex]);
    ClearBitsInWord((unsigned int*)obj, -1);
    ClearBitsInField4((unsigned int*)obj, -1);
    ClearBitsInField8((unsigned int*)obj, -1);
    SetFieldFlag17188_0218d258(obj);
    SetWord0x7f6c(bs, 5);
    if (data_ov004_02171034[kVariantIndex] == 1 && data_ov004_02171034[kModeIndex] != 4) {
        SetByte0x4((char*)bs, 6);
        SetWord0x7f6c(bs, 2);
    }
    if (GetByte0x7f70(bs) == 1) {
        SetByte0x4((char*)bs, 6);
        SetWord0x7f6c(bs, 0);
        SetByte0x7f70(bs, 0);
    }
    if (data_ov004_02171034[kFlagIndex] != 0) {
        SetFlag0x5cccBit0((struct StateBits5ccc_11544*)bs);
        data_ov004_02171034[kFlagIndex] = 0;
    }
    return 0;
}
