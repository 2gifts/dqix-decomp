#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/TextQueue.h"

void* GetGlobalField0x1c020421a0(void);
void InitObjFromCombatantId020e4bf4(void* obj, int combatantId);
int CallFunc020e0434With02153694(int a);
void* GetGlobalResetObj020d7a50(void);
struct Obj0208b494;
Obj0208b494* GetData02108f0c(void);
void CaptureValueOnce0208b494(struct Obj0208b494* obj);

extern "C" ARM void func_02046608(void* a, int b, int c, void* d, int e, int f, int g);

// USA: func_ov017_021c2ea4
ARM void InitAndDispatchCombatant_021c2ea4(unsigned char* self) {
    char buf1[0xc];
    char buf2[0x80];
    GameState::GetInstance();
    void* g = GetGlobalField0x1c020421a0();
    InitObjFromCombatantId020e4bf4(buf1, self[0x95]);
    *(void**)g = buf1;
    int r = CallFunc020e0434With02153694(0x31);
    func_02046608(g, 0xc, r, buf2, 0xe3, 0, 1);
    void* reset = GetGlobalResetObj020d7a50();
    func_020d7e10(reset, buf2, 0, 0, 1, 1);
    Obj0208b494* data = GetData02108f0c();
    CaptureValueOnce0208b494(data);
    self[0x8c] = 3;
}
