#include <globaldefs.h>
#if defined(jpn)
enum { kRegion3c9 = 0x139 };
enum { kRegion390 = 0x278 };
enum { kRegiond0 = 0x10 };
#else
enum { kRegion3c9 = 0x3c9 };
enum { kRegion390 = 0x390 };
enum { kRegiond0 = 0xd0 };
#endif
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct FlagWord02046708;
struct Obj020e25e8;

struct Global02109030 {
    unsigned char pad_0x0[kRegion3c9];
    unsigned char flag3c9 : 1;
};

extern "C" GameResources* func_ov017_0218b5b0(void);
extern "C" void* _Z27GetDataPtr02114e04_020d6c00v(void);
Global02109030* GetGlobal02109030(void);
extern "C" int _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void _Z24ReinitController02043204Pc(char* obj);
extern "C" int _Z17TestFlags02046708P16FlagWord02046708j(struct FlagWord02046708* word, unsigned int mask);
extern "C" void _Z27ResetSelectionState020e25e8P11Obj020e25e8(struct Obj020e25e8* obj);

struct PartyList2a04 {
    unsigned char pad_0x0[0xf78];
    unsigned char members[4];
    unsigned char count;
};

struct BattleView02165730 {
    unsigned char pad_0x0[kRegion390];
    struct Obj020e25e8* selection;
    unsigned char pad_0x394[kRegiond0];
    unsigned int flags;
    unsigned char pad_0x468[0x1c];
    short field_0x484;
    short field_0x486;
    unsigned char pad_0x488[0x1b];
    unsigned char state;
    unsigned char step;
    unsigned char field_0x4a5;
};

// JPN: func_ov003_0216570c
// USA: func_ov003_02165730
extern "C" ARM void func_ov003_02165730(BattleView02165730* view) {
    GameResources* resources = func_ov017_0218b5b0();
    void* flagData = _Z27GetDataPtr02114e04_020d6c00v();

    if (view->step == 0) {
        GetGlobal02109030()->flag3c9 = 1;
        _Z24ReinitController02043204Pc((char*)_Z26GetGlobalField0x1c020421a0v());
        view->field_0x484 = view->field_0x486 = -1;
        view->field_0x4a5 = 0;

        GameState* gs = GameState::GetInstance();
        PartyList2a04* party = (PartyList2a04*)GetPtrField0x2a04(gs);
        for (int i = 0; i < party->count; i++) {
            GameObject* member = GetCombatantWithFlag0x100(gs, party->members[i]);
            if (member != NULL) {
                member->obj3D_.MakeVisible();
            }
        }

        if (IsBrightnessTransitionActive(resources) != 0) return;
        UnlockAndSetBrightness(resources, 0, 0xf);
        view->step = 1;
        if (view->selection == NULL) return;
        _Z27ResetSelectionState020e25e8P11Obj020e25e8(view->selection);
    } else if (view->step == 1) {
        if (IsBrightnessTransitionActive(resources) != 0) return;
        if (_Z17TestFlags02046708P16FlagWord02046708j((struct FlagWord02046708*)flagData, 0x41) != 0) {
            view->flags |= 0x800;
        }
        view->step = 2;
    } else if (view->step == 2) {
        _Z24ReinitController02043204Pc((char*)_Z26GetGlobalField0x1c020421a0v());
        view->field_0x484 = view->field_0x486 = -1;
        view->field_0x4a5 = 0;
        view->state = 0x10;
        view->step = 0;
    }
}
