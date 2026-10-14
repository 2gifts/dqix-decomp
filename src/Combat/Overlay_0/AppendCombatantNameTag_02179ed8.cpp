#include <globaldefs.h>
#include "GameState/GameState.h"

struct UnkStruct0205c508;
void ComputeProductSums0205c508(struct UnkStruct0205c508* s, int* out1, int* out2);

int IsField0x118Equal2_ov000_0217542c(void* obj);
int GetFieldAt0x150_02053c6c(unsigned char* obj);

int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char* dst, int cursor);
struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
int AppendNameTag_02041b70(char* dst, int n, const char* name);

struct Entry02179ed8 {
    char pad[0x23];
    signed char field23;
    char pad2[0x4c - 0x24];
    int field4c;
};

// USA: func_ov000_02179ed8  (semantic: AppendCombatantNameTag_02179ed8)
extern "C" ARM void func_ov000_02179ed8(char* obj, struct Entry02179ed8* entry, char* dst) {
    if (entry != NULL && dst != NULL) {
        int a, b;
        ComputeProductSums0205c508((struct UnkStruct0205c508*)(obj + 0x1dc), &a, &b);
        int aShifted = a << 24;
        GameObject* combatant = GameState::GetInstance()->GetPartyMemberByIndex(entry->field4c);
        if (combatant != NULL) {
#if defined(jpn)
            int field950 = *(int*)((char*)GetFieldAt0x150_02053c6c((unsigned char*)combatant) + 0x8b8);
#else
            int field950 = *(int*)((char*)GetFieldAt0x150_02053c6c((unsigned char*)combatant) + 0x950);
#endif
            signed char byteVal = entry->field23;
            if (IsField0x118Equal2_ov000_0217542c(obj)) {
                AppendFrameTag02041c08(dst, byteVal - (aShifted >> 24), 8, 5, 5, 5);
            }
            AppendCursorTag_02041ea4(dst, byteVal - (aShifted >> 24));
            AppendNameTag_02041b70(dst, byteVal - (aShifted >> 24), (const char*)GetFieldByKey020e0434((struct Container020e0310*)(obj + 0xb8), (short)(field950 + 0x63)));
        }
    }
}
