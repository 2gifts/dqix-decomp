#include <globaldefs.h>
#include "GameState/GameState.h"

struct InitStruct02078484Struct {
    unsigned char f00;
    unsigned char pad01[0xf];
    unsigned char f10;
    unsigned char flags11;
    short f12;
    short objectId;
    short f16;
    short f18;
    short f1a;
    short f1c;
    short pad1e;
    int f20;
    int f24;
    int f28;
    int pad2c[6];
    int scale[3];
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

struct SlotNode021e9778 {
    char pad00[0x20];
    unsigned short id;
};

struct Holder021e9778 {
    char pad00[0x18];
    unsigned int pad18_0 : 12;
    unsigned int mode : 4;
    unsigned int pad18_16 : 16;
};

struct Sub500021e9778 {
    char pad00[0x7c];
    unsigned short f7c;
    char pad7e[0xce - 0x7e];
    unsigned short fce;
};

struct Obj021e9778 {
    char pad000[4];
    struct Node021e9778* head;
    struct Holder021e9778* f8;
    int fc;
    char pad010[0x224 - 0x10];
    int f224;
    char pad228[4];
    void* f22c;
    char pad230[0x500 - 0x230];
    struct Sub500021e9778 sub;
    char pad5d0[0x839 - 0x5d0];
    unsigned char f839;
};

typedef int (*Handler021e9778)(struct Node021e9778*, struct Slot021e9778*, void*, int);

void* GetActiveCombatWork(void);
extern "C" void* _Z20GetOffsetPtr02160f00Pv(void* obj);
extern "C" void* _Z18GetSlotPtr02160f20Pv(void* obj);
extern "C" struct SlotNode021e9778* _Z22GetNodeAtIndex02160094P12List02160094i(void* list, int index);
extern "C" void _Z18InitStruct02078484P24InitStruct02078484Struct(struct InitStruct02078484Struct* p);
extern "C" void* func_ov000_02160f14(void* obj);
extern "C" void _Z33StoreFields0x1e4And0x1e8IfNonZeroPhii(unsigned char* obj, int a, int b);
extern "C" short _Z24ClampScaledStat_0216352ciff(int id, float a, float b);
extern "C" void _Z26FindNodeAndProcess02057fb4Pvii(void* list, int id, void* a3);
extern "C" void* func_02057924(void);
extern "C" GameObject* _Z25GetCombatantWithFlag0x400P9GameStatei(GameState* battleStruct, int combatantId);
extern "C" void func_ov025_021eb6fc(struct Obj021e9778* self, int force);
extern "C" int func_ov025_021eb46c(struct Obj021e9778* self);
extern "C" int func_ov025_021eb204(struct Obj021e9778* self);
extern "C" void func_ov025_021e9b2c(struct Obj021e9778* self);
extern "C" void func_ov025_021ebb90(void* obj);
extern "C" void _Z26UpdateCombatFlags_021e9a94P10In021e9a94(void* obj);
extern "C" char* strcpy(char* d, const char* s);

extern struct Obj021e9778* data_ov025_021ef994;
extern Handler021e9778 data_ov025_021ef538[];
extern unsigned int data_ov025_021ef9a4;
extern char data_ov025_021ef8de[];

// USA: func_ov025_021e9778
extern "C" ARM void func_ov025_021e9778(struct Obj021e9778* self) {
    GameState* gs = GameState::GetInstance();
    void* work = GetActiveCombatWork();
    void* r8 = _Z20GetOffsetPtr02160f00Pv(work);
    struct Slot021e9778* slot = (struct Slot021e9778*)_Z18GetSlotPtr02160f20Pv(work);
    data_ov025_021ef994 = self;
    if (self->sub.fce != 0) {
        unsigned int dt = gs->GetEffectiveDeltaTime();
        if (dt < (unsigned int)self->sub.fce) {
            self->sub.fce = (unsigned short)(self->sub.fce - dt);
            return;
        }
        self->sub.fce = 0;
        func_ov025_021eb6fc(self, 0);
    }
    if (self->f839 == 0) {
        return;
    }
    if (func_ov025_021eb46c(self) != 0) {
        return;
    }
    if (func_ov025_021eb204(self) != 0) {
        return;
    }
    while (self->head != 0) {
        int ret;
        if (self->sub.f7c != 0) {
            if (self->head->code == 0xa) {
                ret = data_ov025_021ef538[self->head->code](self->head, slot, r8, self->fc);
            } else {
                ret = 1;
            }
        } else {
            if (self->head->code == 0xb) {
                ret = 0;
                self->head = 0;
            } else {
                ret = data_ov025_021ef538[self->head->code](self->head, slot, r8, self->fc);
            }
        }
        if (ret == 0) {
            break;
        }
        if (ret == -1) {
            self->head = self->head->next;
            break;
        }
        self->head = self->head->next;
    }
    func_ov025_021e9b2c(self);
    func_ov025_021ebb90((char*)self + 0x22c);
    data_ov025_021ef9a4 &= ~4;
    if (self->f224 != 0) {
        _Z26UpdateCombatFlags_021e9a94P10In021e9a94(self);
    }
    if (self->f8 != 0 && self->f8->mode == 2) {
        int id = _Z22GetNodeAtIndex02160094P12List02160094i(slot, 0)->id;
        int flag = 0;
        GameState* gs2 = GameState::GetInstance();
        int isParty = (id >= 0xc0 && id <= 0xc7);
        if (isParty != 0) {
            GameObject* c = _Z25GetCombatantWithFlag0x400P9GameStatei(gs2, id);
            if (c != 0) {
                short v = *(short*)((char*)c + 2);
                int K = 0 - 0x289;
                if (v == 0x200 || (unsigned int)(v + K) <= 4) {
                    flag = 1;
                } else {
                    if (v == 0xb9 && slot->id == K + 0x4d0) {
                        flag = 1;
                    }
                }
            }
        }
        if (flag == 0 && (data_ov025_021ef9a4 & 0x200) && !(data_ov025_021ef9a4 & 0x400)) {
            void* list = func_02057924();
            struct InitStruct02078484Struct s;
            _Z18InitStruct02078484P24InitStruct02078484Struct(&s);
            s.objectId = _Z22GetNodeAtIndex02160094P12List02160094i(slot, 0)->id;
            if (slot->kind & 1) {
                strcpy((char*)&s, data_ov025_021ef8de);
                unsigned char* p = (unsigned char*)func_ov000_02160f14(work);
                _Z33StoreFields0x1e4And0x1e8IfNonZeroPhii(p, 0x199, 0x3e8);
            }
            int inParty = (id >= 0xc0 && id <= 0xc7);
            if (inParty != 0) {
                short t = _Z24ClampScaledStat_0216352ciff(id, 1.0f, 0.5f);
                s.scale[0] = t;
                s.scale[1] = t;
                s.scale[2] = t;
            }
            _Z26FindNodeAndProcess02057fb4Pvii(list, 4, &s);
            data_ov025_021ef9a4 |= 0x400;
        }
    }
    data_ov025_021ef9a4 &= ~8;
}
