#include <globaldefs.h>

#include "GameState/GameState.h"

struct SearchStruct;

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c508(void);
int TestFlagBitAt0xe(struct SearchStruct* obj, int value);
extern "C" void func_0207dcf0(int a);
extern "C" int func_02001aec(void* a, void* b, int c);
extern "C" void func_ov017_021c9c64(int a, int b);

struct Init0207d7c0 {
    unsigned short h0;
    short pad2;
    signed char b4;
    char pad5;
    unsigned short h6;
    signed char arr8[4];
};
extern "C" void _Z18InitStruct0207d7c0P12Init0207d7c0(struct Init0207d7c0* o);

extern int data_020e8a4c;

// USA: func_0207dba8
extern "C" ARM void func_0207dba8(struct Init0207d7c0* list) {
    GameState* g = GameState::GetInstance();
    struct Init0207d7c0* e = list;
    int i = 0;
    int falseVal = i;
    int trueVal = 1;
    int resetVal = i;
    int negOne = -1;
    for (; i < 4; i++, e++) {
        unsigned short h0 = e->h0;
        if (h0 != 0 && e->b4 < 0) {
            if (e->h6 < 0x3e8) {
                e->h6 = e->h6 + g->GetEffectiveDeltaTime();
            } else {
                int found = (func_02001aec(e->arr8, &data_020e8a4c, 4) == 0);
                if (found) {
                    func_ov017_021c9c64(h0, 0);
                    _Z18InitStruct0207d7c0P12Init0207d7c0(e);
                }
            }
        } else {
            e->h6 = (unsigned short)falseVal;
        }
    }
    struct SearchStruct* search = (struct SearchStruct*)func_0202ae18();
    if (func_0202c508() == 0) return;
    int j;
    for (j = trueVal; j < 4; j++) {
        if (!TestFlagBitAt0xe(search, j)) continue;
        struct Init0207d7c0* p = list;
        int k;
        for (k = resetVal; k < 4; p++, k++) {
            signed char* a = p->arr8;
            if (p->h0 == 0) continue;
            if (a[j] != negOne) continue;
            a[j] = (signed char)resetVal;
            func_0207dcf0(p->h0);
        }
    }
}