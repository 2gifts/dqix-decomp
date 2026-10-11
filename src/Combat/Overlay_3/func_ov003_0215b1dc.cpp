#include <globaldefs.h>
#if defined(jpn)
enum { kRegion998 = 0x868 };
enum { kRegion99c = 0x86c };
enum { kRegion9a0 = 0x870 };
enum { kRegion9a4 = 0x874 };
enum { kRegion19ae = 0x17de };
#else
enum { kRegion998 = 0x998 };
enum { kRegion99c = 0x99c };
enum { kRegion9a0 = 0x9a0 };
enum { kRegion9a4 = 0x9a4 };
enum { kRegion19ae = 0x19ae };
#endif
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

struct BattleMessageScene {
    char unk_0[0x64];
    char messages[0x580 - 0x64];
    unsigned char step;
};

struct BattleGlobals {
    char unk_0[kRegion998];
    int messageActive;
    char unk_99c[kRegion9a0 - kRegion99c];
    int linkState;
    char unk_9a4[kRegion19ae - kRegion9a4];
    unsigned char linkPending;
};

extern "C" BattleGlobals* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" GameResources* _Z10GetWord0x0Pi(GameState*);
extern "C" void _Z30DispatchContextByState0209c678P13Actor0209c678i(void*, int);
extern "C" void _Z13SetBrightnessP13GameResourcesii(GameResources*, int, int);
extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(GameResources*);
extern "C" int _Z32IsMainBrightnessTransitionActiveP13GameResources(GameResources*);
extern "C" void _Z17SetMainBrightnessP13GameResourcesii(GameResources*, int, int);
extern "C" void func_02043124(BattleGlobals*);
extern "C" void _Z24ReinitController02043204Pc(BattleGlobals*);
extern "C" void func_ov003_0215c270(BattleMessageScene*, unsigned int, unsigned int);
extern "C" void* _Z21GetFieldByKey020e0434P17Container020e0310i(void*, int);
extern "C" void func_ov003_02159250(BattleMessageScene*, void*);
extern "C" int* func_0202ae18(void);
extern "C" int _Z18CheckField0NonZeroPi(int*);
extern "C" void func_ov017_021c37a4(void);

extern unsigned char data_02109bf4;

// JPN: func_ov003_0215c61c
// USA: func_ov003_0215b1dc
extern "C" ARM void func_ov003_0215b1dc(BattleMessageScene* self) {
    BattleGlobals* g = _Z26GetGlobalField0x1c020421a0v();
    GameResources* res = _Z10GetWord0x0Pi(GameState::GetInstance());

    if (g->linkState == 3) {
        g->linkPending = 0;
    }

    unsigned char step = self->step;

    if (step == 0) {
        if (g->linkState != 3) return;
        _Z30DispatchContextByState0209c678P13Actor0209c678i(&data_02109bf4, 0xb4);
        _Z13SetBrightnessP13GameResourcesii(res, -16, 0xb4);
        self->step++;
    }

    if (step == 1) {
        if (_Z28IsBrightnessTransitionActiveP13GameResources(res)) return;
        func_02043124(g);
        _Z24ReinitController02043204Pc(g);
        _Z17SetMainBrightnessP13GameResourcesii(res, 0, 0x3c);
        self->step++;
    }

    if (step == 2) {
        func_ov003_0215c270(self, 0, 0x1f);
        if (_Z32IsMainBrightnessTransitionActiveP13GameResources(res)) return;
        if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() > 0) return;
        g->messageActive = 1;
        func_ov003_02159250(self, _Z21GetFieldByKey020e0434P17Container020e0310i(self->messages, 0x6e));
        if (_Z18CheckField0NonZeroPi(func_0202ae18())) {
            func_ov017_021c37a4();
        }
        self->step++;
    }

    if (step == 3) {
        func_ov003_0215c270(self, 0, 0x1f);
    }
}
