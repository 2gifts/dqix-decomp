#include <globaldefs.h>

struct GameObject {
    unsigned short flags;
};

class GameState {
public:
    static GameState* GetInstance();
    GameObject* GetGameObjectByIndex(int idx);
};

extern "C" int* func_0202ae18(GameState* gs);
int CheckField0NonZero(int* p);
int GetField0x3acValue(GameState* gs);
void* GetCombatantWithFlag0x1000(GameState* gs, int idx);
int GetSignedByte0x2d0(void* p);

// USA: func_ov005_02157ae8
extern "C" ARM int func_ov005_02157ae8(void* self, int member) {
    GameState* gameState = GameState::GetInstance();
    if (CheckField0NonZero(func_0202ae18(gameState))) {
        GameObject* object = gameState->GetGameObjectByIndex(member);
        if (object == NULL)
            return 0;
        unsigned short flags = object->flags;
        int leader = GetField0x3acValue(gameState);
        if (flags & 0x200) {
            if (member != leader)
                return 0;
        } else if (flags & 0x1000) {
            if (leader != GetSignedByte0x2d0(GetCombatantWithFlag0x1000(gameState, member)))
                return 0;
        }
    }
    return 1;
}
