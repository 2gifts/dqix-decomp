#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

void* GetData02100044(void);
GameObject* GetCombatantWithFlag0x100(GameState* battleStruct, int combatantId);
void* ResetBuffer02052a10(char* obj);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021c45b4 {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned char field4;
    char name[15];
};

// USA: func_ov017_021c45b4
ARM void EnqueueNameTag3_021c45b4(int combatantId) {
    GameState* bs = GameState::GetInstance();
    void* p = GetData02100044();
    GameObject* c = GetCombatantWithFlag0x100(bs, combatantId);
    if (!c) return;

    struct LocalEvt021c45b4 buf;
    buf.tag = 3;
    buf.field4 = (unsigned char)combatantId;
#if defined(jpn)
    char* rb = *(char**)((char*)c + 0x134);
#else
    char* rb = (char*)ResetBuffer02052a10((char*)c);
#endif
    strcpy(buf.name, rb);
    func_0205e330(p, &buf, 0);
}
