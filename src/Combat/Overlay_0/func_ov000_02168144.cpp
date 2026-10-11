#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/FormationPosition.h"

extern "C" int func_ov000_02153e40(void* obj, short* buf, int max, int start);
int GetSubstructByte0x1c(unsigned char* obj);
void SetSubstructFields0x10And0x18ClearFlag0x1(unsigned char* obj, int* src);

struct Words3_02168144 { unsigned int v[3]; };
extern struct Words3_02168144 data_ov000_021830f0;

static inline Vec2_0216f74c GetFormationPosition(const int& cell) {
    return func_ov000_0216f74c(const_cast<int*>(&cell));
}

// USA: func_ov000_02168144
extern "C" ARM void func_ov000_02168144(unsigned char* obj) {
    GameState* battle = GameState::GetInstance();
    short ids[12];
#if defined(jpn)
    enum { randomOffset = 0x218 };
#else
    enum { randomOffset = 0x29c };
#endif
    int count = func_ov000_02153e40(*(void**)(obj + randomOffset), ids, 0xc, 0);
    int i;
    for (i = 0; i < count; i++) {
        GameObject* c = battle->GetCombatantByIndex(ids[i]);
        if (c != 0) {
            Vec2_0216f74c pos = GetFormationPosition(GetSubstructByte0x1c((unsigned char*)c));
            struct Words3_02168144 fields = data_ov000_021830f0;
            fields.v[0] = pos.x;
            fields.v[2] = pos.y;
            SetSubstructFields0x10And0x18ClearFlag0x1((unsigned char*)c, (int*)&fields);
        }
    }
}
