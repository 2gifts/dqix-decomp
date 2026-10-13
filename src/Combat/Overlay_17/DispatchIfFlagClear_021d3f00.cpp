#include <globaldefs.h>
#include "Combat/ActorAction.h"
#include "GameState/GameState.h"

extern "C" void* func_0202ae18(void);
struct SearchStruct;
int TestFlagBitAt0xe(struct SearchStruct* s, int idx);
void* GetData02100044(void);
unsigned char GetField0x397cValue(GameState* bs);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021d3f00 {
    unsigned char fA;
    unsigned char fB;
    unsigned char nibLo : 4;
    unsigned char nibHi : 4;
    unsigned char fResult;
    int fWord;
};

struct Msg021d3f00 {
    unsigned char tag;
    unsigned char pad1[3];
    struct Sub021d3f00 sub;
    unsigned char pad2[8];
};

// USA: func_ov017_021d3f00  (semantic: DispatchIfFlagClear_021d3f00)
extern "C" ARM void func_ov017_021d3f00(SubBlock02038508* obj, unsigned char b, unsigned char c) {
    if (!obj) return;
    GameState* bs = GameState::GetInstance();
    void* search = func_0202ae18();
    if (TestFlagBitAt0xe((struct SearchStruct*)search, 0)) return;
    void* p = GetData02100044();

    struct Msg021d3f00 msg;
    struct Sub021d3f00* sub = &msg.sub;
    msg.tag = 0x3b;
    sub->fA = obj->command;
    sub->fB = obj->reversed;
    sub->nibLo = b;
    sub->nibHi = c;
    sub->fWord = obj->unknown48;
    sub->fResult = GetField0x397cValue(bs);
    func_0205e330(p, &msg, 0);
}
