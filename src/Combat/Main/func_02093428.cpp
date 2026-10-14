#include <globaldefs.h>
#include "GameState/GameState.h"

struct FieldFlagBlock;
struct Ctx0209459c;

extern "C" void func_02012fe4();
extern "C" int func_020457e0(char* g);
extern "C" void func_020531f0(GameObject* c);
extern "C" void func_02043124(char* g);
extern "C" void func_020945ac(struct Ctx0209459c* ctx);
void ClearSubstructBytes_0200fb40(void* obj);
void ReinitController02043204(char* obj);
void ResetAndEnableFieldFlag_02011b24(struct FieldFlagBlock* obj);
void ClearFieldKeepBit0x10_02011af0(void* obj);
void InitAndInsertNode_021acd30(char* self, unsigned char a, unsigned char b, unsigned char c);
void EnqueueEventTag57WithAB_021cf4b0(int a, int b);
void EnqueueEventTag173_021d1810(int, int, signed char);
int GetField0x3acValue_020100a8(GameState* gs);
int GetWord0x0_0200fb8c(int* obj);
int* GetGlobal02109030_020936f8(void);
char* GetGlobalField0x1c020421a0(void);
int CheckSubstructByte0x7cPositive_020535c8(signed char* p);

struct BattlePhaseState02093428 {
    char unk0[0x30];
    short field30;
    char unk32[0x34 - 0x32];
    unsigned char field34;
    unsigned char field35;
};

struct CombatantIndexList02093428 {
    char unk0[0xf78];
    unsigned char entries[4];
    unsigned char count;
};

struct GlobalBlock02093428 {
#if defined(jpn)
    char unk0[0x868];
#else
    char unk0[0x998];
#endif
    int field998;
    char unk99c[0x9a0 - 0x99c];
    int field9a0;
};

struct GameStateFlags02093428 {
#if defined(jpn)
    char unk0[0x7ca0];
#else
    char unk0[0x7f74];
#endif
    unsigned char field7f74;
    unsigned char field7f75;
};

struct CombatantFields02093428 {
    char unk0[0xbe];
    unsigned char fieldbe;
#if defined(jpn)
    char unkbf[0x1a6 - 0xbf];
#else
    char unkbf[0x1b2 - 0xbf];
#endif
    unsigned short field1b2;
};

// USA: func_02093428
extern "C" ARM void func_02093428(struct BattlePhaseState02093428* s) {
    GameState* bs = GameState::GetInstance();
    char* gf = GetGlobalField0x1c020421a0();
    func_02012fe4();
    unsigned char v = GetField0x3acValue_020100a8(bs);
    unsigned char state = s->field35;

    if (state == 0) {
        struct CombatantIndexList02093428* list = (struct CombatantIndexList02093428*)GetPtrField0x2a04_02010828(bs);
        unsigned char count = list->count;
        for (unsigned char i = 0; i < count; i++) {
            GameObject* c = GetCombatantWithFlag0x100_0200ff1c(bs, list->entries[i]);
            if (c != 0 && CheckSubstructByte0x7cPositive_020535c8((signed char*)c) != 0) {
                func_020531f0(c);
            }
        }
        s->field30 = 10;
        s->field35++;
        return;
    }

    if (state == 1) {
        if (((struct GameStateFlags02093428*)bs)->field7f74 == 0) {
            s->field35 = 3;
            return;
        }
        if (((struct GlobalBlock02093428*)gf)->field9a0 != 0) return;
        int r = func_020457e0(gf);
        if (r == 0) {
            s->field35++;
            return;
        }
        if (r != 1) return;
        s->field30 = 3;
        s->field35 = 4;
        EnqueueEventTag57WithAB_021cf4b0(v, 3);
        EnqueueEventTag173_021d1810(10000, -1, (signed char)GetField0x3acValue_020100a8(bs));
        return;
    }

    if (state == 2) {
        if (((struct GameStateFlags02093428*)bs)->field7f74 == 0) {
            s->field30 = 11;
            s->field35 = 4;
            return;
        }
        EnqueueEventTag57WithAB_021cf4b0(v, 2);
        unsigned char flag = 0;
        GameObject* c = GetCombatantWithFlag0x100_0200ff1c(bs, 0);
        if (c != 0) {
            if (((struct CombatantFields02093428*)c)->fieldbe == 2 || c->obj3D_.GetField06() == 0x170c) {
                unsigned short t = ((struct CombatantFields02093428*)c)->field1b2;
                if (t != 0) {
                    if (t >= 1 && t <= 0x7fff) {
                        flag = 1;
                    } else if (t >= 0x8005 && t <= 0x83ed) {
                        flag = 1;
                    }
                }
            }
        }
        InitAndInsertNode_021acd30((char*)GetWord0x0_0200fb8c((int*)bs), 1, flag, 0);
        ClearFieldKeepBit0x10_02011af0(bs);
        if (((struct GameStateFlags02093428*)bs)->field7f75 != 0) {
            ResetAndEnableFieldFlag_02011b24((struct FieldFlagBlock*)bs);
        }
        func_020945ac((struct Ctx0209459c*)GetGlobal02109030_020936f8());
        s->field34 = 4;
        s->field35 = 0;
        return;
    }

    if (state == 3) {
        ReinitController02043204(gf);
        func_02043124(gf);
        func_020945ac((struct Ctx0209459c*)GetGlobal02109030_020936f8());
        s->field34 = 4;
        s->field35 = 0;
        ClearSubstructBytes_0200fb40(bs);
        return;
    }

    if (state == 4) {
        if (((struct GlobalBlock02093428*)gf)->field998 == 0) {
            s->field35 = 3;
        }
    }
}
