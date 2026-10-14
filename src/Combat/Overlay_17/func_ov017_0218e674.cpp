#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"

struct SearchStruct;
struct Obj_021bd3a4;
struct Obj02052ae8;

struct Party2a04 {
    char unk_0[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

extern "C" struct SearchStruct* func_0202ae18(void);
extern "C" int func_0202c540(struct SearchStruct* obj);
extern "C" void __clear(void* buf, int n);
extern "C" void func_02037d88(GameObject* obj);
extern "C" void func_ov017_0218e210(int id, int flag);
unsigned int GetBitsInField0_0203b4c4(unsigned int* obj, unsigned int mask);
int TestFlagMask_02012430(unsigned short* flags, int mask);
int HasFlag3orFlag2And9a_021bd3a4(struct Obj_021bd3a4* obj);
void DispatchByFlag020d9834(int flag);
int GetSignedByte0x1c8_02039860(void* obj);
int GetSignedByte0x1c9_02039874(void* obj);
void DispatchWithZeroExtras_02193428(void* a, void* b);
void StepValueTowardTarget02052ae8(struct Obj02052ae8* obj);
Object3D* GetField4334_021bdbc0(unsigned char* ov);

extern unsigned short data_02114e30;

// USA: func_ov017_0218e674
extern "C" ARM void func_ov017_0218e674(unsigned char* ov) {
#if defined(jpn)
 enum {regionalOffset0=0x524, regionalOffset1=0x180};
#else
 enum {regionalOffset0=0x734, regionalOffset1=0x18c};
#endif
    GameState* battle = GameState::GetInstance();
    func_0202ae18();
    if (GetField0x3b0Value_020100bc(battle) == 0) return;

    struct Party2a04* party = (struct Party2a04*)GetPtrField0x2a04_02010828(battle);
    int handled[4];
    __clear(handled, sizeof(handled));
    battle->GetEffectiveDeltaTime();

    int flag = 1;
    if ((GetBitsInField0_0203b4c4((unsigned int*)ov, 0x20) != 0 && TestFlagMask_02012430(&data_02114e30, flag) != 0) ||
        GetBitsInField0_0203b4c4((unsigned int*)ov, 0x2000) != 0) {
        flag = 0;
    }
    if (HasFlag3orFlag2And9a_021bd3a4(*(struct Obj_021bd3a4**)(ov + 0x3000 + regionalOffset0)) != 0) {
        flag = 0;
    }
    int dispatch = 0;
    if (GetBitsInField0_0203b4c4((unsigned int*)ov, 0x4000) != 0) dispatch = 1;

    int count = 0;
    for (int i = 0; i < party->count; i++) {
        if (count != 0 && dispatch != 0) DispatchByFlag020d9834(1);
        int id = party->ids[i];
        count++;
        handled[id] = 1;
        func_ov017_0218e210(id, flag);
    }

    for (int i = 0; i < 4; i++) {
        if (handled[i] != 0) continue;
        GameObject* member = battle->GetPartyMemberByIndex(i);
        if (member == NULL) continue;
        if (count != 0 && dispatch != 0) DispatchByFlag020d9834(1);
        count++;
        if (func_0202c540(func_0202ae18()) != 0 &&
            member->obj3D_.GetField06() == battle->GetUnknownGameObject()->obj3D_.GetField06() &&
            ((member->obj3D_.unknown_0_ & 0x1000) != 0 ||
             (member->obj3D_.unknown_4_ == 0 && (*(unsigned int*)((char*)member + regionalOffset1) & 1) != 0)) &&
            GetSignedByte0x1c8_02039860(member) >= 0) {
            handled[i] = 1;
            func_02037d88(member);
            DispatchWithZeroExtras_02193428(member, NULL);
        } else if (GetSignedByte0x1c9_02039874(member) != 0) {
            func_02037d88(member);
        } else {
            StepValueTowardTarget02052ae8((struct Obj02052ae8*)member);
        }
    }

    Object3D* effects = GetField4334_021bdbc0(ov);
    if (effects != NULL) effects->AdvanceEffects();

    if (battle->GetPartyMemberByIndex(0xce) == NULL) return;
    if (count != 0 && dispatch != 0) DispatchByFlag020d9834(1);
    func_ov017_0218e210(0xce, flag);
}
