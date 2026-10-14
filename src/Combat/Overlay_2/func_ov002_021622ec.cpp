#include "GameState/GameState.h"
#include <globaldefs.h>
#include <Resource/ResourceNodeInsertion.h>

struct Struct0205de24;
struct Struct_0205c570;
struct Obj_0205da38;
struct Obj0205eaa0;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
int GetActiveScaledSum0205d794(struct Struct_0205c570 *s);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short *p, int n);
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0 *o, int a, int b);
int CheckFlagOrThreshold_02161b48(char *base, int a);
void InitBattleTag0215bf34(char *base);
int GetWord0x0_0200fb8c(int *p);
int GetField0x3acValue_020100a8(GameState *gs);
int TestBitInByteArray_0206dfb0(int unused, unsigned char *arr, int index);
extern "C" char *func_0205ec34(void);
extern "C" void func_ov002_02161cf0(void *base);
extern "C" void func_ov002_0215c0f8(void *base);
extern "C" void func_ov002_02161a8c(int w);
extern "C" void func_ov017_021c05f4(int a, int b, int c, int d);
extern "C" void func_ov023_021dca88(void *p);
extern "C" void func_02012fe4(void);
extern "C" void func_02017c58(void);
extern "C" unsigned short data_02114e30[];
extern "C" char data_02108760[];

static inline int AnyConfirm021622ec(char *base) {
    int a = TestFlag0SetAndFlag1Clear_02012444(data_02114e30, 0x601);
    int b = IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)(base + 0x2c8 + 0xc00), 0x14);
    return (a | b) ? 1 : 0;
}

// USA: func_ov002_021622ec
extern "C" ARM void func_ov002_021622ec(char *base) {
    int state = *(int *) (base + 0x1000 + 0xbc0);
    if (state == 0) {
        *(unsigned char *) (base + 0x1000 + 0xc2f) = 0;
        *(short *) (base + 0x1b00 + 0xe0)          = 0;
        FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) (base + 0x2c8 + 0xc00), 0, 2);
        InitBattleTag0215bf34(base);
        func_ov002_02161cf0(base);
        func_ov002_0215c0f8(base);
        *(int *) (base + 0x1000 + 0xbc0) += 1;
    } else if (state == 1) {
        *(unsigned int *) (base + 0x2000 + 0x47c) |= 4;
        short old = *(short *) (base + 0x1b00 + 0xe0);
        *(short *) (base + 0x1b00 + 0xe0) =
            GetActiveScaledSum0205d794((struct Struct_0205c570 *) (base + 0x2c8 + 0xc00));
        if (old != *(short *) (base + 0x1b00 + 0xe0)) return;
        if (AnyConfirm021622ec(base) || *(unsigned char *) (base + 0x1000 + 0xc2f) == 1) {
            GameState *gs                              = GameState::GetInstance();
            int w                                      = GetWord0x0_0200fb8c((int *) gs);
            *(unsigned char *) (base + 0x1000 + 0xc2f) = 0;
            switch (*(short *) (base + 0x1b00 + 0xe0)) {
                case 0:
                    *(int *) (base + 0x1000 + 0xbb8) = 3;
                    *(int *) (base + 0x1000 + 0xbc0) = 0;
                    break;
                case 1:
                    if (*(signed char *) (base + 0x1c00 + 0x73) != 1) {
                        *(int *) (base + 0x1000 + 0xbb8) = 2;
                        *(int *) (base + 0x1000 + 0xbc0) = 0;
                    } else {
                        SetNodeFieldsAndInsert_021a120c((GameResources*)w, 3, GetField0x3acValue_020100a8(gs));
                        *(int *) (base + 0x1000 + 0xbb8) = 0x2b;
                        *(int *) (base + 0x1000 + 0xbc0) = 0;
                        func_02012fe4();
                        func_02017c58();
                    }
                    break;
                case 2:
                    *(int *) (base + 0x1000 + 0xbb8)  = 0xe;
                    *(short *) (base + 0x1b00 + 0xf6) = 0;
                    *(int *) (base + 0x1000 + 0xbc0)  = 0;
                    break;
                case 3:
                    if (!(*(unsigned int *) (base + 0x2000 + 0x47c) & 0x20)) return;
                    *(int *) (base + 0x1000 + 0xbb8) = 0x10;
                    *(int *) (base + 0x1000 + 0xbc0) = 0;
                    break;
                case 4: {
                    char *save = func_0205ec34();
                    if (!TestBitInByteArray_0206dfb0((int) save, (unsigned char *) save + 0x8c, 0x119a)) return;
                    func_ov017_021c05f4(w, 1, 0, 0);
                    *(int *) (base + 0x1000 + 0xbb8) = 0x2b;
                    *(int *) (base + 0x1000 + 0xbc0) = 0;
                    break;
                }
                case 5:
                    func_ov002_02161a8c(w);
                    *(int *) (base + 0x1000 + 0xbb8) = 0x15;
                    *(int *) (base + 0x1000 + 0xbc0) = 0;
                    break;
            }
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0 *) data_02108760, 1, 0);
        } else if (CheckFlagOrThreshold_02161b48(base, 1)) {
            *(unsigned char *) (base + 0x1000 + 0xc2f) = 0;
            if (*(unsigned int *) (base + 0x2000 + 0x47c) & 1) {
                func_ov023_021dca88(base + 0x50);
            }
            *(int *) (base + 0x1000 + 0xbb8) = 0x2b;
        }
    }
}
