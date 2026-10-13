#include <globaldefs.h>

struct LightingManager {
    static LightingManager* GetInstance();
    void BeginFade(short a, unsigned short b);
};

struct CombatWork021e74f4 {
    char pad[0x6fd4];
    unsigned char fadeStarted;
};

struct Obj021e74f4 {
    char pad[0x8];
    short a;
    unsigned short b;
};

CombatWork021e74f4* GetActiveCombatWork(void);

// USA: func_ov025_021e74f4  (semantic: Trans_021e74f4)
extern "C" ARM int func_ov025_021e74f4(struct Obj021e74f4* obj) {
    LightingManager::GetInstance()->BeginFade(obj->a, obj->b);
    GetActiveCombatWork()->fadeStarted = 1;
    return 1;
}
