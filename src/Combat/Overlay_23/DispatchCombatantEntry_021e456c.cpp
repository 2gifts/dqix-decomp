#if defined(jpn)
enum {regionalOffset0=0x56c, regionalOffset1=0x4f8, regionalOffset2=0x124, regionalOffset3=0x128, regionalOffset4=0x130};
#else
enum {regionalOffset0=0x634, regionalOffset1=0x4fc, regionalOffset2=0x128, regionalOffset3=0x12c, regionalOffset4=0x134};
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov023_021e6194(int arg);
extern "C" void _ZN8Object3D24MaybeSetRegularAnimationEPKci(void* self, int a, int b);

struct S1a0;
extern "C" void _ZN8Object3D23SetCurrentAnimationTimeEi(struct S1a0* obj, unsigned int v);

int GetFieldAt0x150(unsigned char* obj);

extern "C" int func_ov023_021e5974(int a, int b, int c, int d, int e);

// JPN: func_ov023_021e4790
// USA: func_ov023_021e456c  (semantic: DispatchCombatantEntry_021e456c)
extern "C" ARM void func_ov023_021e456c(void* objRaw) {
    char* obj = (char*)objRaw;
    if (!(*(unsigned short*)(obj + regionalOffset0) & 4)) return;
    GameState* bs = GameState::GetInstance();
    GameObject* combatant = GetCombatantWithFlag0x100(bs, *(int*)(obj + regionalOffset1));
    if (!combatant) return;
    int flag = 0;
    if (*(unsigned short*)(obj + regionalOffset0) & 0x10) flag = 1;
    char* six4 = (char*)func_ov023_021e6194(*(int*)(obj + regionalOffset2));
    char* five = (char*)func_ov023_021e6194(*(int*)(obj + regionalOffset3));
    _ZN8Object3D24MaybeSetRegularAnimationEPKci(five, *(int*)(six4 + 0x14), 0);
    _ZN8Object3D23SetCurrentAnimationTimeEi((struct S1a0*)five, *(unsigned int*)(six4 + 0x1c));
    int fieldVal = GetFieldAt0x150((unsigned char*)combatant);
    func_ov023_021e5974(*(int*)(obj + regionalOffset3), fieldVal, *(int*)(obj + regionalOffset1), flag, 1);
    *(unsigned short*)(obj + regionalOffset0) &= ~4;
    *(unsigned short*)(obj + regionalOffset0) &= ~0x10;
    *(int*)(obj + regionalOffset4) = 0;
    *(unsigned short*)(obj + regionalOffset0) |= 8;
}
