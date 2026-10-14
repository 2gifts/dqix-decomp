#include <globaldefs.h>
#include "GameState/GameState.h"

int* GetWord0x0(int*);
struct GameResources;
void SetBrightness(GameResources*, int, int);
void SetSubBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);
int IsAnimationActive0209ca2c(void* obj);
struct Entry_0205d6a0;
void ResetEntryList0205d6a0(Entry_0205d6a0*, int);

struct ShortField0xb8_0209cae8;
short GetShortAt0xb8(struct ShortField0xb8_0209cae8* obj);

struct Actor0209c678;
void DispatchContextByState0209c678(struct Actor0209c678* actor, int arg);

extern int data_02109bf4;

struct Obj021868a8 {
    char pad0[0xb10];
    unsigned char b10;
    unsigned char b11;
    char pad1;
    unsigned char b13;
    char pad2[0xb24 - 0xb14];
    int b24;
};

// USA: func_ov008_021868a8
extern "C" ARM void func_ov008_021868a8(struct Obj021868a8* obj) {
    int* word = GetWord0x0((int*)GameState::GetInstance());
    unsigned char flag = obj->b11;
    if (flag == 0) {
        if (obj->b24 == 0) {
            SetBrightness((GameResources*)word, -16, 15);
            if (obj->b13 == 0) {
                if (GetShortAt0xb8((struct ShortField0xb8_0209cae8*)&data_02109bf4) != 0x29) {
                    DispatchContextByState0209c678((struct Actor0209c678*)&data_02109bf4, 15);
                }
            }
        } else {
            SetSubBrightness((GameResources*)word, -16, 15);
        }
        obj->b11 = obj->b11 + 1;
        return;
    }
    if (flag != 1) return;
    if (IsBrightnessTransitionActive((GameResources*)word) != 0) return;
    if (IsAnimationActive0209ca2c(&data_02109bf4) != 0) return;
    ResetEntryList0205d6a0((Entry_0205d6a0*)((char*)obj + 0x130), 1);
    obj->b10 = 0xe;
    obj->b11 = 0;
}
