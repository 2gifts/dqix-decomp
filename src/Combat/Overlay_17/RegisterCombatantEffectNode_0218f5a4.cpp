// JPN: func_ov017_02190188
#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Field734 = 0x524, Field150 = 0x144, Field18c = 0x180, Field700 = 0x4f0 };
#else
enum { Field734 = 0x734, Field150 = 0x150, Field18c = 0x18c, Field700 = 0x700 };
#endif

extern "C" void func_0202ae18(void);
extern "C" int func_ov017_021925e0(void* p);
extern "C" void _Z34ClearFlagAndZeroVec3Field_021bd440Pvi(void* obj, int arg);
GameObject* GetCombatantWithFlag0x100(GameState* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);
struct Obj02061bd8;
int CheckField0x56bLowNibble(struct Obj02061bd8* obj);
extern "C" void func_02072afc(int id, int* arr, short* arr2);
extern "C" void* func_ov017_021a4658(void* p0, int p1);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov017_0218f5a4  (semantic: RegisterCombatantEffectNode_0218f5a4)
extern "C" ARM int func_ov017_0218f5a4(char* self, int combatantId, int flag2, int flag3, int flag4) {
    GameState* bs = GameState::GetInstance();
    func_0202ae18();
    void* base = *(void**)(self + 0x3000 + Field734);

    if (func_ov017_021925e0(self + 0x3000) != 0) {
        GameObject* c = bs->GetPartyMemberByIndex(combatantId);
        if (c != 0) {
            unsigned short w = *(unsigned short*)c;
            if (w & 0x1000) {
                _Z34ClearFlagAndZeroVec3Field_021bd440Pvi(base, combatantId & 0xff);
                return 0;
            }
        }
    }

    GameObject* c2 = GetCombatantWithFlag0x100(bs, combatantId);
    if (c2 == 0) return 0;
    if (GetFieldAt0x150((unsigned char*)c2) == 0) return 0;

    if (flag4 == 0) {
        unsigned char* ptr = *(unsigned char**)((char*)c2 + Field150);
        int byteVal = ptr ? ptr[0x56e] : 0;
        if (byteVal == 0 && flag2 == 0) {
            if (CheckField0x56bLowNibble((struct Obj02061bd8*)c2) == 0) {
                int arr[0xb];
                short arr2[0xb];
                func_02072afc(combatantId, arr, arr2);
                int matched = 0;
                int i;
                for (i = 0; i < 0xb; i++) {
                    if (i == 0xa) continue;
                    GameObject* c3 = bs->GetGameObjectByIndex(arr[i]);
                    if (c3 != 0) {
                        short v1 = arr2[i];
                        short v2 = *(short*)((char*)c3 + 2);
                        if (v1 != v2) matched = 1;
                    }
                }
                if (matched == 0) return 0;
            }
        }
    }

    void* node = func_ov017_021a4658(self, combatantId);
    if (node != 0) {
        *(short*)((char*)node + 8) = (short)combatantId;
        if (flag2 != 0) {
            ((unsigned char*)node)[0xb] |= 0x2;
        }
        if (flag3 != 0 || (*(int*)((char*)c2 + Field18c) & 0x40)) {
            ((unsigned char*)node)[0xb] |= 0x4;
        }
        if (flag4 != 0) {
            ((unsigned char*)node)[0xb] |= 0x1;
        }
        if (((unsigned char*)node)[2] == 0) {
            AppendNodeToTail((struct TailList020469b4*)*(void**)(self + 0x3000 + Field700), (struct TailNode020469b4*)node);
        }
    }
    return 1;
}
