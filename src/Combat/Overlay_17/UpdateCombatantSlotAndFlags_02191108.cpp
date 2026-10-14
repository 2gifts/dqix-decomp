#include <globaldefs.h>
#include "Combat/ActorAction.h"
#include "GameState/GameState.h"

unsigned char GetByte0x26c_02039d7c(char* obj);
int GetField0x3acValue_020100a8(GameState* battleStruct);
int GetFieldIfFlag4_020100f8(char* obj);
int GetField0x21c020a277c(void* obj);
void SetField0x21c_020a2770(void* obj, short value);
typedef void (*SetField0x21cIntFn)(void* obj, int value);
void StoreValidCombatantCount0202c3e0(void* obj);

struct Buf16_02191108 { int x[4]; };
extern "C" void func_ov017_02190884(int b, struct Buf16_02191108* outBuf, int* zero, int c, int d, int e);
extern "C" void* func_0202ae18(void* ctx);

extern "C" void func_020a2be8(void* obj);

// USA: func_ov017_02191108  (semantic: UpdateCombatantSlotAndFlags_02191108)
extern "C" ARM void func_ov017_02191108(void* unused, int c, int d, int e, int flag) {
    GameState* battle = GameState::GetInstance();
    if (battle->GetProtagonist() == 0) return;

    GameObject* combatant2 = battle->GetUnknownGameObject();
    if (combatant2 != 0 && GetByte0x26c_02039d7c((char*)combatant2) != 0) {
        SubBlock02038508* field = GetFieldPtrAt0x26c_020399a8(combatant2);
        field->unknown52 = 1;
        return;
    }

    int zero = 0;
    int fieldVal = GetField0x3acValue_020100a8(battle);
    struct Buf16_02191108 buf;
    func_ov017_02190884(fieldVal, &buf, &zero, c, d, e);
    int idx = buf.x[0];

    GameObject* combatant = battle->GetGameObjectByIndex(idx);
    if (combatant != 0) {
        ((Object3D*)((unsigned char*)combatant))->DisableFlag(0x80);
    }

    void* p2 = (void*)GetFieldIfFlag4_020100f8((char*)battle);
    if (p2 != 0) {
        int val = GetField0x21c020a277c(p2);
        if (val != 0xc9 && val != 0xca) {
            ((SetField0x21cIntFn)SetField0x21c_020a2770)(p2, idx);
            if (flag != 0 && val != idx) {
                func_020a2be8(p2);
            }
        }
    }

    unsigned char* ptr = (unsigned char*)GetPtrField0x2a04_02010828(battle);
    int i;
    for (i = 0; i < zero; i++) {
        unsigned char* dst = ptr + i;
        dst[0xf78] = (unsigned char)buf.x[i];
    }
    ptr[0xf7c] = (unsigned char)zero;
    StoreValidCombatantCount0202c3e0(func_0202ae18(ptr));
}
