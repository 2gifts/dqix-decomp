#include <globaldefs.h>
#include "GameState/GameState.h"

int GetWord0x0(int* obj);
int IsSubBrightnessTransitionActive(GameResources*);

struct Struct02074bf4;
void ClearFlag0x11IfSet(struct Struct02074bf4*);

struct StructAllocGroup0208ba54;
void DestroyStructAllocGroup0208ba54(struct StructAllocGroup0208ba54*);

void ClearBitsInWord(unsigned int* obj, unsigned int mask);

struct GameResources;
void SetSubBrightness(GameResources*, int, int);
void SetCombatModeFromCase020dc2d0(int);

struct Obj0208d340 {
    char pad0[0xb8];
    int fb8;
    char pad2[0xd5 - 0xbc];
    unsigned char fd5;
    char pad3[0xda - 0xd6];
    unsigned short fda;
};

// USA: func_0208d340
ARM void AdvanceState0208d340(struct Obj0208d340* obj) {
    int val = GetWord0x0((int*)GameState::GetInstance());

    if (obj->fd5 == 0) {
        if (!(obj->fda & 0x10)) {
            SetSubBrightness((GameResources*)val, -16, 8);
        }
        obj->fd5 = obj->fd5 + 1;
        return;
    }
    if (obj->fd5 == 1) {
        if (IsSubBrightnessTransitionActive((GameResources*)val) == 0) {
            obj->fd5 = obj->fd5 + 1;
        }
        return;
    }
    if (obj->fd5 == 2) {
        obj->fda = obj->fda & ~4;
        ClearFlag0x11IfSet((struct Struct02074bf4*)((char*)obj + 0x2c));
        SetCombatModeFromCase020dc2d0(0);
        obj->fd5 = obj->fd5 + 1;
        return;
    }
    if (obj->fd5 != 3) return;

    int* reg = (int*)0x4001000;
    *reg = (*reg & ~0x1f00) | (obj->fb8 << 8);
    *(short*)((char*)reg + 0x50) = 0;
    obj->fd5 = obj->fd5 + 1;
    DestroyStructAllocGroup0208ba54((struct StructAllocGroup0208ba54*)obj);
    ClearBitsInWord((unsigned int*)GetWord0x0((int*)GameState::GetInstance()), 0x6000);
}
