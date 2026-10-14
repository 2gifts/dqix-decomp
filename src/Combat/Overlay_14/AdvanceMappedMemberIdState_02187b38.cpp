#include <globaldefs.h>
#if defined(jpn)
#define REGION_MEMBER_SHORT_OFFSET 0x2a
#define REGION_MENU_LEADING_SIZE 0x20
#define func_ov014_02188330 func_ov014_02189234
#else
#define REGION_MEMBER_SHORT_OFFSET 0x36
#define REGION_MENU_LEADING_SIZE 0x2c
#endif
#include "GameState/GameState.h"

int GetWord0x0(int* obj);
extern "C" void func_ov014_02188330(void* self);
short FindMappedMemberId02080468(void* obj, int id);
extern "C" void func_020813ec(void* obj, int key);
struct GameResources;
void SetBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);

// USA: func_ov014_02187b38  (semantic: AdvanceMappedMemberIdState_02187b38)
extern "C" ARM void func_ov014_02187b38(void* self) {
    int w = GetWord0x0((int*)GameState::GetInstance());
    unsigned char state = *((unsigned char*)self + 0x17b);
    if (state == 0) {
        *(void**)((char*)self + 0x5c) = (char*)self + 0xe0;
        func_ov014_02188330(self);
        *(short*)((char*)self + 0x170) = 1;
        if (*(short*)((char*)self + 0x172) < 0) {
            *(short*)((char*)self + 0x172) = FindMappedMemberId02080468(*(void**)((char*)self + 0xc0), *(short*)((char*)self + 0x170));
        }
        *(short*)((char*)*(void**)((char*)self + 0xc0) + REGION_MEMBER_SHORT_OFFSET) = *(short*)((char*)self + 0x172);
        func_020813ec(*(void**)((char*)self + 0xc0), *(short*)((char*)self + 0x170));
        (*((unsigned char*)self + 0x17b))++;
        return;
    }
    if (state == 1) {
        SetBrightness((GameResources*)w, 0, 8);
        (*((unsigned char*)self + 0x17b))++;
        return;
    }
    if (state != 2) return;
    if (!IsBrightnessTransitionActive((GameResources*)w)) {
        *((unsigned char*)self + 0x17a) = 2;
        *((unsigned char*)self + 0x17b) = 0;
    }
}
