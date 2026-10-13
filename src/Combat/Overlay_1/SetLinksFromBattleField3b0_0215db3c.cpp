#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"

struct Node021d6148;
void SetLinkIfType3_021d6148(Node021d6148* o, unsigned int v);
extern "C" unsigned int _fflt(int);
extern "C" unsigned int _fdiv(unsigned int, unsigned int);

struct Vec3Int_0215db3c { int a, b, c; };

// USA: func_ov001_0215db3c  (semantic: SetLinksFromBattleField3b0_0215db3c)
extern "C" ARM int func_ov001_0215db3c(void* self) {
    int* base = (int*)GetField0x3b0Value(GameState::GetInstance());
    if (base == NULL) return 0;
    Vec3Int_0215db3c v = *(Vec3Int_0215db3c*)((char*)base + 0x70);
    SetLinkIfType3_021d6148((Node021d6148*)self, _fdiv(_fflt(v.a), 0x45800000u));
    SetLinkIfType3_021d6148((Node021d6148*)((char*)self + 0x8), _fdiv(_fflt(v.b), 0x45800000u));
    SetLinkIfType3_021d6148((Node021d6148*)((char*)self + 0x10), _fdiv(_fflt(v.c), 0x45800000u));
    return 1;
}
