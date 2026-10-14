#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetPtrField0x2a04(GameState* battleStruct);
struct Vector3i;
struct Obj02033874;
void SetVecYFromValue02033874(struct Obj02033874* obj, int arg);
struct Bytes02033b88;
int SetByte0xbeShiftPrev(struct Bytes02033b88* p, int val);
void ClearBytesAndZeroBlock02039d24(unsigned char* obj);
unsigned char GetField0x397cValue(GameState* battleStruct);
void SetFlag0x1ceBit0x4(unsigned char* obj);

// USA: func_ov017_021921fc  (semantic: SyncFlaggedCombatantVecs_021921fc)
extern "C" ARM void func_ov017_021921fc(int* vec, int angle, int resetFlag) {
    unsigned char* keys;
    GameState* bs = GameState::GetInstance();
    unsigned char* base = (unsigned char*)GetPtrField0x2a04(bs);
    keys = base + 0x378;
    int i = 0;
    keys = keys + 0xc00;
    for (; i < base[0xf7c]; i++) {
        GameObject* c = bs->GetPartyMemberByIndex(keys[i]);
        if (c != NULL) {
            *(Vector3i*)((int*)((char*)c + 0x44)) = *(Vector3i const*)vec;
            SetVecYFromValue02033874((struct Obj02033874*)c, angle);
            if (resetFlag != 0) {
                SetByte0xbeShiftPrev((struct Bytes02033b88*)c, 0);
                *(unsigned short*)((char*)c + 0xb2) = 0;
                ClearBytesAndZeroBlock02039d24((unsigned char*)c);
            }
            if (keys[i] != GetField0x397cValue(bs)) {
                SetFlag0x1ceBit0x4((unsigned char*)c);
            }
        }
    }
}
