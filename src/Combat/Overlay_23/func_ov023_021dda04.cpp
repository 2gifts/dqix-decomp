#include <globaldefs.h>
#include "GameState/GameState.h"

int GetWord0x0(int* obj);
extern "C" void func_ov023_021dc520(void* obj);
extern "C" void func_ov023_021dd404(void* obj);
int DispatchByMode77c_021ddbb8(void* obj, int a, int b);
struct Obj021ddbf8;
int Check_021ddbf8(struct Obj021ddbf8* arg);
extern "C" void func_ov023_021dc354(void* obj);
void SetCombatModeFromCase020dc2d0(int mode);

struct Obj021dda04 {
#if defined(jpn)
    char pad0[0x6f0];
#else
    char pad0[0x774];
#endif
    unsigned short field774;
    unsigned char field776;
    unsigned char field777;
    char pad778[0x77b - 0x778];
    signed char field77b;
};

// USA: func_ov023_021dda04  (semantic: AdvanceCombatStageState_021dda04)
extern "C" ARM void func_ov023_021dda04(struct Obj021dda04* obj) {
    GetWord0x0((int*)GameState::GetInstance());

    if (obj->field777 == 0) {
        func_ov023_021dc520(obj);
        func_ov023_021dd404(obj);
        if (!(obj->field774 & 0x40)) {
            obj->field776 = 3;
            return;
        }
        DispatchByMode77c_021ddbb8(obj, ~0xf, 8);
        obj->field777 = obj->field777 + 1;
    }

    if (obj->field777 == 1) {
        func_ov023_021dc520(obj);
        func_ov023_021dd404(obj);
        if (Check_021ddbf8((struct Obj021ddbf8*)obj) == 0) {
            obj->field777 = obj->field777 + 1;
        }
    }

    if (obj->field777 != 2) return;

    func_ov023_021dc354(obj);
    if (obj->field774 & 0x200) {
        obj->field776 = 3;
        return;
    }
    if (obj->field77b != 1) {
        SetCombatModeFromCase020dc2d0(0);
    }
    obj->field776 = 3;
}
