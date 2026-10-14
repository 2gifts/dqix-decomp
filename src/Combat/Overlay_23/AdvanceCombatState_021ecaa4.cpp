#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
struct GameResources;
void SetMainBrightness(GameResources*, int, int);
void SetSubBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);
int IsAnimationActive0209ca2c(void* obj);
extern "C" void ColorEffect_ConfigureBrightnessAdjust(unsigned short*, int, int);
struct Entry_0205d6a0;
void ResetEntryList0205d6a0(struct Entry_0205d6a0* a, int flag);
struct FlagWord020466f4;
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);
void* GetDataPtr02114e04_020d6c00(void);
extern int data_02109bf4;

struct Obj021ecaa4 {
    char pad0[0x60];
    unsigned char f60 : 4;
    unsigned char f60_hi : 4;
    char pad1[0xc0 - 0x61];
    unsigned char fc0 : 4;
    unsigned char fc0_hi : 4;
    char pad2[0x430 - 0xc1];
    unsigned char f430;
    char pad3[0x432 - 0x431];
    unsigned char f432;
    char pad4[0x438 - 0x433];
    unsigned short f438;
    char pad5[0x44a - 0x43a];
    unsigned char f44a;
};

// USA: func_ov023_021ecaa4  (semantic: AdvanceCombatState_021ecaa4)
extern "C" ARM void func_ov023_021ecaa4(Obj021ecaa4* obj) {
    void* result = (void*)func_ov017_0218b5b0();
    unsigned char state = obj->f432;
    if (state == 0) {
        if (obj->f60 == 0)
            SetMainBrightness((GameResources*)result, -16, 15);
        else
            SetSubBrightness((GameResources*)result, -16, 15);
        obj->f432++;
    }
    if (state != 1) return;
    if (IsBrightnessTransitionActive((GameResources*)result)) return;
    if (obj->f44a != 0) {
        if (!(obj->f430 == 0 || obj->f430 == 1)) {
            if (IsAnimationActive0209ca2c((void*)&data_02109bf4)) return;
        }
        if (!(obj->f438 & 0x20)) {
            if (obj->fc0 == 0)
                ColorEffect_ConfigureBrightnessAdjust((unsigned short*)0x4000050, 0x17, 0);
            else
                ColorEffect_ConfigureBrightnessAdjust((unsigned short*)0x4001050, 0x17, 0);
        }
    }
    ResetEntryList0205d6a0((struct Entry_0205d6a0*)((char*)obj + 0xc4), 1);
    obj->f438 |= 4;
    if (obj->f438 & 0x10)
        ClearFlags020466f4((struct FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 1);
    obj->f432++;
}
