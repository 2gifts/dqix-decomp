#include <globaldefs.h>
#include "GameState/GameState.h"

struct FieldFlagBlock;

extern "C" void func_02012fe4();
extern "C" int func_020457e0(char* g);
extern "C" void func_020531f0(GameObject* c);
extern "C" void func_02043124(char* g);
extern "C" void func_020945ac();
void ClearSubstructBytes(void* obj);
extern "C" void _Z24ReinitController02043204Pc(char* obj);
void ResetAndEnableFieldFlag(struct FieldFlagBlock* obj);
void ClearFieldKeepBit0x10(void* obj);
extern "C" void _Z26InitAndInsertNode_021acd30Pchhh(char* self, unsigned char a, unsigned char b, unsigned char c);
extern "C" void _Z32EnqueueEventTag57WithAB_021cf4b0ii(int a, int b);
extern "C" void _Z27EnqueueEventTag173_021d1810tth(int a, int b, signed char c);
int GetField0x3acValue(GameState* gs);
int GetWord0x0(int* obj);
int* GetGlobal02109030(void);
extern "C" char* _Z26GetGlobalField0x1c020421a0v(void);
int CheckSubstructByte0x7cPositive(signed char* p);

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
    char unk0[0x998];
    int field998;
    char unk99c[0x9a0 - 0x99c];
    int field9a0;
};

struct GameStateFlags02093428 {
    char unk0[0x7f74];
    unsigned char field7f74;
    unsigned char field7f75;
};

struct CombatantFields02093428 {
    char unk0[0xbe];
    unsigned char fieldbe;
    char unkbf[0x1b2 - 0xbf];
    unsigned short field1b2;
};

// USA: func_02093428
extern "C" ARM void func_02093428(struct BattlePhaseState02093428* s) {
    GameState* bs = GameState::GetInstance();
    char* gf = _Z26GetGlobalField0x1c020421a0v();
    func_02012fe4();
    unsigned char v = GetField0x3acValue(bs);
    unsigned char state = s->field35;

    if (state == 0) {
        struct CombatantIndexList02093428* list = (struct CombatantIndexList02093428*)GetPtrField0x2a04(bs);
        unsigned char count = list->count;
        for (unsigned char i = 0; i < count; i++) {
            GameObject* c = GetCombatantWithFlag0x100(bs, list->entries[i]);
            if (c != 0 && CheckSubstructByte0x7cPositive((signed char*)c) != 0) {
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
        _Z32EnqueueEventTag57WithAB_021cf4b0ii(v, 3);
        _Z27EnqueueEventTag173_021d1810tth(10000, -1, (signed char)GetField0x3acValue(bs));
        return;
    }

    if (state == 2) {
        if (((struct GameStateFlags02093428*)bs)->field7f74 == 0) {
            s->field30 = 11;
            s->field35 = 4;
            return;
        }
        _Z32EnqueueEventTag57WithAB_021cf4b0ii(v, 2);
        unsigned char flag = 0;
        GameObject* c = GetCombatantWithFlag0x100(bs, 0);
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
        _Z26InitAndInsertNode_021acd30Pchhh((char*)GetWord0x0((int*)bs), 1, flag, 0);
        ClearFieldKeepBit0x10(bs);
        if (((struct GameStateFlags02093428*)bs)->field7f75 != 0) {
            ResetAndEnableFieldFlag((struct FieldFlagBlock*)bs);
        }
        GetGlobal02109030();
        func_020945ac();
        s->field34 = 4;
        s->field35 = 0;
        return;
    }

    if (state == 3) {
        _Z24ReinitController02043204Pc(gf);
        func_02043124(gf);
        GetGlobal02109030();
        func_020945ac();
        s->field34 = 4;
        s->field35 = 0;
        ClearSubstructBytes(bs);
        return;
    }

    if (state == 4) {
        if (((struct GlobalBlock02093428*)gf)->field998 == 0) {
            s->field35 = 3;
        }
    }
}
