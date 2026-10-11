#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/TextQueue.h"
#if defined(jpn)
extern "C" int sprintf(char*, const char*, ...);
extern char* data_ov017_021d87f4;
#endif

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
#if defined(jpn)
    char buf2[0x40];
#else
    char buf2[0x80];
#endif
#if defined(jpn)
    GameState* game = GameState::GetInstance();
#else
    GameState::GetInstance();
#endif
    void* g = GetGlobalField0x1c020421a0();
#if defined(jpn)
    GameObject* member = game->GetPartyMemberByIndex(self[0x95]);
    sprintf(buf2, data_ov017_021d87f4, *(char**)((char*)member + 0x134));
#else
    InitObjFromCombatantId020e4bf4(buf1, self[0x95]);
    *(void**)g = buf1;
    int r = CallFunc020e0434With02153694(0x31);
    func_02046608(g, 0xc, r, buf2, 0xe3, 0, 1);
#endif
    void* reset = GetGlobalResetObj020d7a50();
#if defined(jpn)
    func_020d7e10(reset, buf2, 0, 0, 1);
#else
    func_020d7e10(reset, buf2, 0, 0, 1, 1);
#endif
    Obj0208b494* data = GetData02108f0c();
    CaptureValueOnce0208b494(data);
    self[0x8c] = 3;
}
