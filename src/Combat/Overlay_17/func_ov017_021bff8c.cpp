#include <globaldefs.h>
#include "GameState/GameState.h"

struct ArrayContainsByteStruct;
int ArrayContainsByte(ArrayContainsByteStruct* s, int val);
extern "C" void* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void* func_ov017_021b8478(void* obj);
struct ListHead02046b60;
int ListContainsId(ListHead02046b60* list, int id);
int IsField0Null(void** p);
int CheckSubstructByte0x7cPositive(signed char* p);
int GetByteField0x252(void* obj);
int GetByte0x26c(char* p);
extern "C" void _Z32EnqueueEventTag57WithAB_021cf4b0ii(int a, int b);
void ClearSubstructBytes(void* obj);
int* GetGlobal02109030(void);
extern "C" void func_02094030(int*, short, short, int);
struct Obj021c0124;
extern "C" void _Z20InitState32_021c0124P11Obj021c0124h(Obj021c0124* p, unsigned char flag);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);

struct Ctx021bff8c {
    char pad[0x36fc];
    TailList020469b4* list;
    char pad3700[0x3718 - 0x3700];
    void* table;
    char pad371c[0x3b1c - 0x371c];
    Obj021c0124* state;
};

// USA: func_ov017_021bff8c
extern "C" ARM void func_ov017_021bff8c(Ctx021bff8c* ctx, unsigned char flag) {
    if (ArrayContainsByte((ArrayContainsByteStruct*)GetPtrField0x2a04(GameState::GetInstance()), 0) == 0) {
        int match = 0;
        int blocked = 0;
        GameState* gs = GameState::GetInstance();
        GameObject* leader = gs->GetPartyMemberByIndex(0);
        GameObject* hero = gs->GetProtagonist();
        char* g = (char*)_Z26GetGlobalField0x1c020421a0v();
        Ctx021bff8c* base = (Ctx021bff8c*)func_ov017_0218b5b0();
        void* table = NULL;
        if (base != NULL) {
            table = base->table;
        }
        if (table != NULL) {
            func_ov017_021b8478(table);
        }
        unsigned short heroId = *(unsigned short*)((char*)hero + 0x1b2);
        if (heroId != 0) {
            if (*(unsigned short*)((char*)leader + 0x1b2) == heroId) {
                match = 1;
            } else {
                blocked = 1;
            }
        } else if (ListContainsId((ListHead02046b60*)ctx->list, 3)) {
            blocked = 1;
        }
        if (IsField0Null((void**)ctx->list) == 0) {
            blocked = 1;
        } else if (CheckSubstructByte0x7cPositive((signed char*)hero) != 0) {
            blocked = 1;
        } else if (GetByteField0x252(hero) == 0) {
            blocked = 1;
        } else if (*(int*)(g + 0x998) != 0) {
            blocked = 1;
        } else if (GetByte0x26c((char*)hero) != 0) {
            blocked = 1;
        }
        unsigned char heroIndex = hero->obj3D_.unknown_4_;
        if (match) {
            _Z32EnqueueEventTag57WithAB_021cf4b0ii(heroIndex, 5);
            ClearSubstructBytes(gs);
            return;
        }
        if (blocked) {
            _Z32EnqueueEventTag57WithAB_021cf4b0ii(heroIndex, 4);
            ClearSubstructBytes(gs);
            return;
        }
        _Z32EnqueueEventTag57WithAB_021cf4b0ii(heroIndex, 1);
        func_02094030(GetGlobal02109030(), 0x2712, -1, flag);
    }
    _Z20InitState32_021c0124P11Obj021c0124h(ctx->state, flag);
    AppendNodeToTail(ctx->list, (TailNode020469b4*)ctx->state);
}
