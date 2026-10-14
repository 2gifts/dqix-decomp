#if defined(jpn)
enum {regionalOffset0=0x134, regionalOffset1=0x4e0, regionalOffset2=0x4e3, regionalOffset3=0x4e2, regionalOffset4=0xe2};
#else
enum {regionalOffset0=0x138, regionalOffset1=0x4e4, regionalOffset2=0x4e7, regionalOffset3=0x4e6, regionalOffset4=0xe6};
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

int GetWord0x0(int* obj);
struct GameResources;
void SetBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);
int IsAnimationActive0209ca2c(void* obj);
void SetField0x3b0Value(GameState* battleStruct, int value);
extern int data_02109bf4;

struct Obj021e3f34 { char pad[regionalOffset0]; int field138; char pad2[regionalOffset1 - regionalOffset0 - 4]; unsigned char field4e4; };

// USA: func_ov023_021e3f34  (semantic: RefreshCounterAndAdvanceState_021e3f34)
extern "C" ARM void func_ov023_021e3f34(struct Obj021e3f34* obj) {
    GameState* bs = GameState::GetInstance();
    int val = GetWord0x0((int*)bs);
    if (obj->field4e4 == 0) {
        SetBrightness((GameResources*)val, -16, 15);
        obj->field4e4++;
    }
    if (IsBrightnessTransitionActive((GameResources*)val)) return;
    if (IsAnimationActive0209ca2c(&data_02109bf4)) return;
    SetField0x3b0Value(bs, obj->field138);
    obj->field4e4 = 0;
    *(signed char*)((char*)obj + regionalOffset2) = *(signed char*)((char*)obj + 0x400 + regionalOffset4);
    *(signed char*)((char*)obj + regionalOffset3) = -1;
}
