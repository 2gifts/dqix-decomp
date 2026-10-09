#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/FormationPosition.h"

struct BattleCore_021676a8 {
    char pad0[0x8e20];
    int field_0x8e20;
};

struct Owner_021676a8 {
    char pad0[0x29c];
    BattleCore_021676a8* core;
};

int GetWord0x0(int* obj);
extern "C" int func_ov000_0215e9fc(void* obj, short* buf, int max, int start);
int ClassifyField0x81fe(char* self);
int GetSubstructByte0x1c(unsigned char* obj);
void SetSubstructByte0x1c(unsigned char* obj, unsigned char value);
void SetSubstructFields0x10And0x18ClearFlag0x1(unsigned char* obj, int* src);
void SetSubstructField0x14ClearFlag0x1(unsigned char* obj, int* src);

struct Words3_021676a8 { unsigned int v[3]; };
extern unsigned char data_ov000_02183108[][4];
extern struct Words3_021676a8 data_ov000_021830fc;
extern struct Words3_021676a8 data_ov000_021830c0;

static inline Vec2_0216f74c GetFormationPosition(const int& cell) {
    return func_ov000_0216f74c(const_cast<int*>(&cell));
}

// USA: func_ov000_021676a8
extern "C" ARM void func_ov000_021676a8(Owner_021676a8* obj) {
    GameState* battle = GameState::GetInstance();
    GetWord0x0((int*)battle);
    BattleCore_021676a8* core = obj->core;
    short ids[4];
    int count = func_ov000_0215e9fc(core, ids, 4, 0);
    if (ClassifyField0x81fe((char*)core) != 0) {
        count = 1;
    }
    int i;
    for (i = 0; i < count; i++) {
        GameObject* c = battle->GetCombatantByIndex(ids[i]);
        if (c != 0) {
            int cell = data_ov000_02183108[count - 1][i];
            if (GetSubstructByte0x1c((unsigned char*)c) != 0xff && obj->core->field_0x8e20 != 0) {
                cell = GetSubstructByte0x1c((unsigned char*)c);
            }
            Vec2_0216f74c pos = GetFormationPosition(cell);
            struct Words3_021676a8 fields = data_ov000_021830fc;
            struct Words3_021676a8 field14 = data_ov000_021830c0;
            fields.v[0] = pos.x;
            fields.v[2] = pos.y;
            SetSubstructByte0x1c((unsigned char*)c, (unsigned char)(cell & 0xff));
            SetSubstructFields0x10And0x18ClearFlag0x1((unsigned char*)c, (int*)&fields);
            SetSubstructField0x14ClearFlag0x1((unsigned char*)c, (int*)&field14);
        }
    }
}
