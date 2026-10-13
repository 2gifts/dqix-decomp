#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define data_ov025_021ef538 data_ov025_021ef818
#define data_ov025_021ef8de data_ov025_021efba0
#endif

struct InitStruct02078484Struct {
    unsigned char f00;
    unsigned char pad01[0xf];
    unsigned char f10;
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
    short f12;
    short f14;
    short f16;
    short f18;
    short f1a;
    short f1c;
    short pad1e;
    int f20; int f24; int f28; int f2c; int f30;
    int f34; int f38; int f3c; int f40;
    int f44; int f48; int f4c;
};

struct Node021e9778 {
    int code;
    struct Node021e9778* next;
};

struct Slot021e9778 {
    unsigned short id;
    unsigned char pad02[8];
    unsigned char kind;
};

struct List02160094;
struct ListNode02160094;
struct Obj021eb6fc;
struct Ctx021eb46c;
struct Loader021eb204;
struct Obj021e9b2c;
struct Container021ebb90;
struct In021e9a94;
struct ActionModeWord {
    unsigned int unknown00 : 12;
    unsigned int mode : 4;
    unsigned int unknown16 : 16;
};

typedef int (*Handler021e9778)(struct Node021e9778*, struct Slot021e9778*, void*, int);

void* GetActiveCombatWork(void);
void* GetOffsetPtr02160f00(void* obj);
void* GetSlotPtr02160f20(void* obj);
ListNode02160094* GetNodeAtIndex02160094(List02160094* list, int index);
void InitStruct02078484(InitStruct02078484Struct* p);
extern "C" void* func_ov000_02160f14(void* obj);
void StoreFields0x1e4And0x1e8IfNonZero(unsigned char* obj, int a, int b);
short ClampScaledStat_0216352c(int id, float a, float b);
void FindNodeAndProcess02057fb4(void* list, int id, int argument);
extern "C" void* func_02057924(void);
GameObject* GetCombatantWithFlag0x400(GameState* battleStruct, int combatantId);
extern "C" void func_ov025_021eb6fc(Obj021eb6fc* self, int force);
extern "C" int func_ov025_021eb46c(Ctx021eb46c* self);
extern "C" int func_ov025_021eb204(Loader021eb204* self);
extern "C" void func_ov025_021e9b2c(Obj021e9b2c* self);
extern "C" void func_ov025_021ebb90(Container021ebb90* obj);
void UpdateCombatFlags_021e9a94(In021e9a94* obj);
extern "C" char* strcpy(char* d, const char* s);

extern void* data_ov025_021ef994;
extern Handler021e9778 data_ov025_021ef538[];
extern unsigned int data_ov025_021ef9a4;
extern char data_ov025_021ef8de[];

// USA: func_ov025_021e9778
extern "C" ARM void func_ov025_021e9778(void* self) {
    unsigned char* object = (unsigned char*)self;
    GameState* gs = GameState::GetInstance();
    void* work = GetActiveCombatWork();
    void* workData = GetOffsetPtr02160f00(work);
    struct Slot021e9778* slot = (struct Slot021e9778*)GetSlotPtr02160f20(work);
    data_ov025_021ef994 = self;
    if ((*(unsigned short*)(object + 0x5ce)) != 0) {
        unsigned int dt = gs->GetEffectiveDeltaTime();
        if (dt < (unsigned int)(*(unsigned short*)(object + 0x5ce))) {
            (*(unsigned short*)(object + 0x5ce)) = (unsigned short)((*(unsigned short*)(object + 0x5ce)) - dt);
            return;
        }
        (*(unsigned short*)(object + 0x5ce)) = 0;
        func_ov025_021eb6fc((Obj021eb6fc*)self, 0);
    }
    if ((*(unsigned char*)(object + 0x839)) == 0) {
        return;
    }
    if (func_ov025_021eb46c((Ctx021eb46c*)self) != 0) {
        return;
    }
    if (func_ov025_021eb204((Loader021eb204*)self) != 0) {
        return;
    }
    while ((*(Node021e9778**)(object + 0x4)) != 0) {
        int ret;
        if ((*(unsigned short*)(object + 0x57c)) != 0) {
            if ((*(Node021e9778**)(object + 0x4))->code == 0xa) {
                ret = data_ov025_021ef538[(*(Node021e9778**)(object + 0x4))->code]((*(Node021e9778**)(object + 0x4)), slot, workData, (*(int*)(object + 0xc)));
            } else {
                ret = 1;
            }
        } else {
            if ((*(Node021e9778**)(object + 0x4))->code == 0xb) {
                ret = 0;
                (*(Node021e9778**)(object + 0x4)) = 0;
            } else {
                ret = data_ov025_021ef538[(*(Node021e9778**)(object + 0x4))->code]((*(Node021e9778**)(object + 0x4)), slot, workData, (*(int*)(object + 0xc)));
            }
        }
        if (ret == 0) {
            break;
        }
        if (ret == -1) {
            (*(Node021e9778**)(object + 0x4)) = (*(Node021e9778**)(object + 0x4))->next;
            break;
        }
        (*(Node021e9778**)(object + 0x4)) = (*(Node021e9778**)(object + 0x4))->next;
    }
    func_ov025_021e9b2c((Obj021e9b2c*)self);
    func_ov025_021ebb90((Container021ebb90*)(object + 0x22c));
    data_ov025_021ef9a4 &= ~4;
    if ((*(int*)(object + 0x224)) != 0) {
        UpdateCombatFlags_021e9a94((In021e9a94*)self);
    }
    if (*(void**)(object + 8) != NULL && ((ActionModeWord*)((char*)*(void**)(object + 8) + 0x18))->mode == 2) {
        int id = *(unsigned short*)((char*)GetNodeAtIndex02160094((List02160094*)slot, 0) + 0x20);
        int flag = 0;
        GameState* gs2 = GameState::GetInstance();
        int isParty = (id >= 0xc0 && id <= 0xc7);
        if (isParty != 0) {
            GameObject* c = GetCombatantWithFlag0x400(gs2, id);
            if (c != 0) {
                short v = *(short*)((char*)c + 2);
                if (v == 0x200 || (unsigned int)(v - 0x289) <= 4) {
                    flag = 1;
                } else {
                    if (v == 0xb9 && slot->id == 0x247) {
                        flag = 1;
                    }
                }
            }
        }
        if (flag == 0 && (data_ov025_021ef9a4 & 0x200) && !(data_ov025_021ef9a4 & 0x400)) {
            void* list = func_02057924();
            struct InitStruct02078484Struct s;
            InitStruct02078484(&s);
            s.f14 = *(unsigned short*)((char*)GetNodeAtIndex02160094((List02160094*)slot, 0) + 0x20);
            if (slot->kind & 1) {
                strcpy((char*)&s, data_ov025_021ef8de);
                unsigned char* p = (unsigned char*)func_ov000_02160f14(work);
                StoreFields0x1e4And0x1e8IfNonZero(p, 0x199, 0x3e8);
            }
            int inParty = (id >= 0xc0 && id <= 0xc7);
            if (inParty != 0) {
                short t = ClampScaledStat_0216352c(id, 1.0f, 0.5f);
                s.f44 = t;
                s.f48 = t;
                s.f4c = t;
            }
            FindNodeAndProcess02057fb4(list, 4, (int)&s);
            data_ov025_021ef9a4 |= 0x400;
        }
    }
    data_ov025_021ef9a4 &= ~8;
}
