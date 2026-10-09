#include <globaldefs.h>
#include "GameState/GameState.h"

#define REG_MATRIX_PUSH (*(volatile unsigned int*)0x04000444)
#define REG_MATRIX_POP (*(volatile unsigned int*)0x04000448)
#define REG_MATRIX_SCALE (*(volatile unsigned int*)0x04000470)
#define REG_POLYGON_ATTR (*(volatile unsigned int*)0x04000500)
#define REG_TEXTURE_PARAM (*(volatile unsigned int*)0x04000504)

struct StatusHealth { unsigned char padding0[4]; unsigned short hp; };
struct StatusCharacter {
    unsigned char padding0[0x16c];
    short values[0x198];
    unsigned char gender : 1;
    unsigned char flags : 7;
    unsigned char padding49d[0x4b3];
    int index;
};
struct StatusCombatant {
    unsigned char padding0[0x130];
    StatusHealth* health;
    unsigned char padding134[0x1c];
    StatusCharacter* character;
    int GetHP() const { return health->hp; }
    StatusCharacter* GetCharacter() const { return character; }
};
struct StatusSprite {
    unsigned char padding0[0x14];
    int x;
    int y;
    unsigned char padding1c[6];
    unsigned char depth;
    unsigned char padding23[3];
    unsigned char mode;
    unsigned char padding27;
};
struct StatusSprites {
    unsigned char padding0[0x258];
    StatusSprite marker;
};
struct NameText { char text[0x20]; };
struct ConditionText { char text[0x14]; };
struct ValueText { char text[0x10]; };
struct StatusPanel {
    void* context;
    unsigned char padding4[0xc4];
    void* renderer;
    StatusSprites* sprites;
    unsigned char paddingd0[0x42c];
    int selected;
    NameText names[4];
    int positions[4];
    ConditionText conditions[4];
    char label[0x10];
    ValueText values[4];
    unsigned char padding630[0x10];
    char* conditionNames[2];
};
struct Struct0200fb08;
void* GetGlobalField0x1c020421a0();
extern "C" void func_02045f3c(void*, void*, int, int, int, int, int, int, int, int);
extern "C" int func_020420e8(const char*, int);
extern "C" void func_0205ac40(void*, void*);
unsigned char GetByteViaFieldIndirectOffset_021e4250_021e4250(char*);
char* CallFunc020e0434With02153694(int);
unsigned char NormalizeField5_0200fb08(Struct0200fb08*);
extern "C" void func_ov005_02155258(void*, int, int, int, int);

// USA: func_ov023_021e3fc0
extern "C" ARM void func_ov023_021e3fc0(StatusPanel* panel) {
    int textColor;
    GameState* game = GameState::GetInstance();
    void* renderer = GetGlobalField0x1c020421a0();
    int drawValue = 0x7fff;
    StatusCombatant* combatant = (StatusCombatant*)GetCombatantWithFlag0x100(game, panel->selected);
    if (combatant->GetHP() <= 0) drawValue = 0x1f;
    REG_MATRIX_PUSH = 0;
    REG_POLYGON_ATTR = 1;
    REG_MATRIX_SCALE = 0;
    REG_MATRIX_SCALE = 0;
    REG_MATRIX_SCALE = 0xffc01000;
    func_02045f3c(renderer, &panel->names[panel->selected], panel->positions[panel->selected], 0xa1, drawValue, 10, 0, 0, 0, 0x11);
    if (combatant->GetHP() <= 0) {
        short width = func_020420e8(panel->conditionNames[combatant->character->gender], 0);
        short x = ((0x3b - width) >> 1) + 0x40;
        func_02045f3c(renderer, &panel->conditions[panel->selected], x, 0xa1, drawValue, 10, 0, 0, 0, 0x11);
    } else {
        StatusSprites* sprites = panel->sprites;
        sprites->marker.x = 0x44000;
        sprites->marker.y = 0xa2000;
        sprites->marker.depth = 0x70;
        sprites->marker.mode = 2;
        func_0205ac40(panel->renderer, &sprites->marker);
        if (GetByteViaFieldIndirectOffset_021e4250_021e4250((char*)combatant)) {
            unsigned short valueColor = 0xf0a;
            if (GetByteViaFieldIndirectOffset_021e4250_021e4250((char*)combatant) >= 10)
                valueColor = 0x31f;
            func_02045f3c(renderer, &panel->values[panel->selected], 0x50, 0xa1, valueColor, 10, 0, 0, 0, 0x11);
        }
        func_02045f3c(renderer, panel->label, 0x5c, 0xa1, drawValue, 10, 0, 0, 0, 0x11);
        short x = func_020420e8(CallFunc020e0434With02153694(0x3f3), 0) + 0x5e;
        if (NormalizeField5_0200fb08((Struct0200fb08*)game) == 1) x += 2;
        StatusCharacter* character = combatant->GetCharacter();
        textColor = drawValue;
        drawValue = character->values[character->index];
        func_ov005_02155258(panel->context, drawValue, x, 0xa1, textColor);
    }
    REG_TEXTURE_PARAM = 0;
    REG_MATRIX_POP = 1;
}
