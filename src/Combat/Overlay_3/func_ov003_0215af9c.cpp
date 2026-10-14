#include <globaldefs.h>
#if defined(jpn)
enum { kRegion998 = 0x868 };
#else
enum { kRegion998 = 0x998 };
#endif
#include "GameState/GameState.h"

struct BattleMessageScene {
    char unk_0[0x64];
    char messages[0x580 - 0x64];
    unsigned char step;
    char unk_581[0x587 - 0x581];
    unsigned char actorSlot;
    unsigned char nextMode;
    char unk_589[0x59d - 0x589];
    unsigned char busy;
};

struct BattleGlobals {
    char unk_0[kRegion998];
    int messageActive;
};

extern "C" GameResources* func_ov017_0218b5b0(void);
BattleGlobals* GetGlobalField0x1c020421a0(void);
int IsBrightnessTransitionActive(GameResources*);
struct AxisFloats0203b57c;
int GetAxisIntValue(AxisFloats0203b57c*, int);
void SetMainBrightness(GameResources*, int, int);
int GetField0x397cValue_020100b0(GameState*);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState*, int);
extern "C" void func_02046380(BattleGlobals*);
struct Obj02046574;
void SetIndexedName02046574(Obj02046574*, int, char*);
struct Container020e0310;
void* GetFieldByKey020e0434(Container020e0310*, int);
extern "C" void func_ov003_02159250(BattleMessageScene*, void*);

// USA: func_ov003_0215af9c
extern "C" ARM void func_ov003_0215af9c(BattleMessageScene* self) {
    GameResources* res = func_ov017_0218b5b0();
    BattleGlobals* g = GetGlobalField0x1c020421a0();
    unsigned char step = self->step;

    if (step == 0) {
        if (!IsBrightnessTransitionActive(res) &&
            GetAxisIntValue((AxisFloats0203b57c*)res, 0) &&
            GetAxisIntValue((AxisFloats0203b57c*)res, 1)) {
            SetMainBrightness(res, 0, 0xf);
        }
        self->step++;
    }

    if (step == 1) {
        if (self->busy != 0) return;
        if (IsBrightnessTransitionActive(res)) return;
        if (GetAxisIntValue((AxisFloats0203b57c*)res, 0)) return;

        if (self->actorSlot == 1) {
            GameState* gs = GameState::GetInstance();
            GameObject* obj = GetCombatantWithFlag0x100_0200ff1c(gs, GetField0x397cValue_020100b0(gs));
            func_02046380(g);
            SetIndexedName02046574((Obj02046574*)g, 0, (char*)obj->baseStats_);
        }
        g->messageActive = 1;
        func_ov003_02159250(self, GetFieldByKey020e0434((Container020e0310*)self->messages, (short)(self->actorSlot + 0x438)));
        self->step++;
    }

    if (step == 2 && g->messageActive == 0) {
        self->nextMode = 0xb;
        self->step = 0;
    }
}
