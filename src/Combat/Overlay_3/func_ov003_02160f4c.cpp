#include "GameState/GameState.h"

struct StoreStruct;
struct Obj02046574;
struct Container020e0310;
struct Struct020444bc;

struct Flag174_02160f4c {
    unsigned char bit0 : 1;
};

void *GetGlobalField0x1c020421a0(void);
extern "C" void func_02046380(void *messages);
void *GetPtrField0x2a04(GameState *gameState);
void StoreInArray0x8b0(StoreStruct *base, int index, int value);
extern "C" void *__clear(void *destination, int count);
void SetIndexedName02046574(Obj02046574 *obj, int index, char *str);
void *GetFieldByKey020e0434(Container020e0310 *c, int key);
void InitObjFromCombatantId020e4bf4(void *obj, int combatantId);
extern "C" void *func_ov003_02160bf8(void *obj, int key);
extern "C" void func_02042764(void *src, void *dst, int flag);
extern "C" void func_020e4b34(void *, const char *, void *, unsigned int, unsigned char, unsigned char, unsigned char,
                              unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
extern "C" void func_0204500c(void *obj, void *buffer, int a, int b);
void SetField9a0AndIncrementField78(Struct020444bc *s);
void ReinitController02043204(char *obj);
extern "C" void func_02043124(char *obj);
void SetOrClearFlag40_02166f80(void *self, int key, int set);

// USA: func_ov003_02160f4c
extern "C" ARM void func_ov003_02160f4c(unsigned char *self) {
    unsigned char *ctl = (unsigned char *) GetGlobalField0x1c020421a0();
    char nameBuf[0x30];
    char objBuf[0xc];

    if (self[0x4a5] == 0) {
        func_02046380(ctl);
        GameState *gs    = GameState::GetInstance();
        unsigned char *p = (unsigned char *) GetPtrField0x2a04(gs);
        StoreInArray0x8b0((StoreStruct *) ctl, 0, p[0xf7c] - 1);
        __clear(nameBuf, 0x30);
        if (*(unsigned int *) (self + 0x464) & 4) {
            unsigned char *e = self + *(short *) (self + 0x400 + 0x98) * 0x37;
            if ((signed char) e[1] != 0) {
                SetIndexedName02046574((Obj02046574 *) ctl, 0, (char *) (e + 1));
            } else {
                SetIndexedName02046574(
                    (Obj02046574 *) ctl, 0,
                    (char *) GetFieldByKey020e0434((Container020e0310 *) (self + 0x2dc), 0x7530));
            }
            *(unsigned int *) (self + 0x464) &= ~4u;
        }
        if (*(unsigned int *) (self + 0x464) & 0x10) {
            InitObjFromCombatantId020e4bf4(objBuf, *(short *) (self + 0x400 + 0x82));
            *(void **) (ctl + 0x10) = objBuf;
            *(unsigned int *) (self + 0x464) &= ~0x10u;
            if (*(short *) (self + 0x400 + 0x84) == 0x54 || *(short *) (self + 0x400 + 0x84) == 0x55) {
                *(unsigned int *) (self + 0x464) |= 0x10;
            }
        } else if ((*(unsigned int *) (self + 0x464) & 0x28) || *(short *) (self + 0x400 + 0x84) == 0xe) {
            unsigned char *r5 = (unsigned char *) func_ov003_02160bf8(self, *(short *) (self + 0x400 + 0x80));
            if (r5 != 0) {
                func_02042764(r5 + 0x140, nameBuf, 1);
                func_020e4b34(objBuf, nameBuf, 0, 0, 0, 0, 0, ((Flag174_02160f4c *) (r5 + 0x174))->bit0, 0, 1, 0, 1);
                *(void **) (ctl + 0x10) = objBuf;
            }
            *(unsigned int *) (self + 0x464) &= ~0x28u;
        }
        short v            = *(short *) (self + 0x400 + 0x84);
        unsigned char flag = 1;
        if (v == 8 || v == 0x3d) flag = 0;
        void *key = GetFieldByKey020e0434((Container020e0310 *) (self + 0x2dc), v);
        if (key == 0) {
            *(short *) (self + 0x400 + 0x84) = *(short *) (self + 0x400 + 0x86);
            *(short *) (self + 0x400 + 0x86) = -1;
            key = GetFieldByKey020e0434((Container020e0310 *) (self + 0x2dc),
                                                                 *(short *) (self + 0x400 + 0x84));
        }
        func_0204500c(ctl, key, 0, 0xe3);
        *(int *) (ctl + 0x998) = 1;
        *(int *) (ctl + 0x99c) = 2;
        ctl[0x1000 + 0x9ca]    = flag;
        self[0x4a5]++;
        if (*(unsigned int *) (self + 0x464) & 0x4000) {
            self[0x4a6] = 0;
        }
        if (*(unsigned int *) (self + 0x464) & 0x4000000) {
            ctl[0x1000 + 0x9ca] = 0;
            *(unsigned int *) (self + 0x464) &= ~0x4000000u;
        }
        if (*(unsigned int *) (self + 0x464) & 0x8000000) {
            ctl[0x1000 + 0x9d3] = 1;
            *(unsigned int *) (self + 0x464) &= ~0x8000000u;
        }
    } else if (self[0x4a5] == 1) {
        if (*(int *) (ctl + 0x9a0) == 2 && (*(unsigned int *) (self + 0x464) & 0x4000) && ++self[0x4a6] > 0x3c) {
            SetField9a0AndIncrementField78((Struct020444bc *) ctl);
        }
        if (*(int *) (ctl + 0x998) == 0) {
            *(short *) (self + 0x400 + 0x84) = *(short *) (self + 0x400 + 0x86);
            *(short *) (self + 0x400 + 0x86) = -1;
            self[0x4a3]                      = 0x10;
            self[0x4a5]                      = 0;
        } else if (*(int *) (ctl + 0x9a0) == 3) {
            *(short *) (self + 0x400 + 0x84) = *(short *) (self + 0x400 + 0x86);
            *(short *) (self + 0x400 + 0x86) = -1;
            if (*(short *) (self + 0x400 + 0x84) < 0) {
                if (*(unsigned int *) (self + 0x464) & 2) {
                    ReinitController02043204((char *) ctl);
                    func_02043124((char *) ctl);
                    *(unsigned int *) (self + 0x464) &= ~2u;
                }
                if (*(unsigned int *) (self + 0x464) & 0x2000) {
                    *(unsigned int *) (self + 0x464) &= ~0x2000u;
                    SetOrClearFlag40_02166f80(self, *(short *) (self + 0x400 + 0x88), 0);
                }
            }
            self[0x4a5] = 0;
        }
    }
}
