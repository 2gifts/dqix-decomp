#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"

#if defined(jpn)
extern "C" void func_0204500c(void*, const char*, int);
extern char data_020f29cc;
#endif

extern "C" int func_ov017_021959b4(void);
void* GetGlobalField0x1c020421a0(void);
extern "C" void* func_0202ae18(void);
char* GetFieldIfFlag4_020100f8(char*);
extern "C" unsigned short* func_02012fe4(void);
void InitBattleIfListHasId0x1c_020d9a58(void* self);
int CheckField0NonZero_0202b7d8(int* p);
extern "C" int func_0202c508(void* obj);
extern "C" void func_ov017_021cf730(int a, int b);
void ClearIntAt0x23c_020a27b8(unsigned char* obj);
extern "C" void func_020531f0(void* obj);
struct Obj020397cc;
void CancelPendingAction020397cc(Obj020397cc*, int);
void ResetElapsedState020e11a4(void);
extern "C" void func_02046380(void* global);
int CallFunc020e0434With02153694_020e51cc(int value);
#if !defined(jpn)
extern "C" void func_0204500c(void* global, void* entry, int a, int b);
#endif
extern "C" int func_020457e0(void* global);
extern "C" void func_ov017_021ab860(short value, int flag);
void InitContext020e1154(void* obj);
void ReinitController02043204(char* obj);
void SetByteField0x253_020397c0(void* obj);
void InitBattleAndControllerState_020d9ab0(void* self);
int IsValueInRange0201b5d8(int x);

struct Obj020d9870 {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char pad2[0x8 - 0x2];
    unsigned char state;
};

// USA: func_020d9870
extern "C" ARM void func_020d9870(struct Obj020d9870* self) {
#if defined(jpn)
    enum { choiceOffset = 0x17e2, pendingOffset = 0x868 };
#else
    enum { choiceOffset = 0x19b2, pendingOffset = 0x998 };
#endif
    GameState* gs = GameState::GetInstance();
    func_ov017_0218b5b0();
    void* unkObj = gs->GetUnknownGameObject();
    void* g1c = GetGlobalField0x1c020421a0();
    FontBankLoader* g = GetGlobal02109400_02094a00();
    void* t = func_0202ae18();
    char* f4 = GetFieldIfFlag4_020100f8((char*)gs);
    unsigned short* p = func_02012fe4();

    if (func_ov017_021959b4() != 0) {
        InitBattleIfListHasId0x1c_020d9a58(self);
        return;
    }

    if (self->state == 0) {
        if (CheckField0NonZero_0202b7d8((int*)t) != 0 && func_0202c508(t) != 0) {
            func_ov017_021cf730(-1, 0);
        }
        ClearIntAt0x23c_020a27b8((unsigned char*)f4);
        self->state = 1;
    } else if (self->state == 1) {
        BlankFunction02094b30(g, 0x20e, 0);
        self->state = 2;
    } else if (self->state == 2) {
        if (AlwaysTrue02094b4c(g) != 0) {
            self->state = 3;
        }
    } else if (self->state == 3) {
        if (unkObj != NULL) {
            func_020531f0(unkObj);
            CancelPendingAction020397cc((Obj020397cc*)unkObj, 1);
        }
        ResetElapsedState020e11a4();
        func_02046380(g1c);
#if defined(jpn)
        func_0204500c(g1c, &data_020f29cc, 0);
#else
        func_0204500c(g1c, (void*)CallFunc020e0434With02153694_020e51cc(0x3e), 0, 0xe3);
#endif
        *(unsigned char*)((char*)g1c + choiceOffset) = 0;
        *(int*)((char*)g1c + pendingOffset) = 1;
        self->state = 4;
    } else if (self->state == 4) {
        if (*(int*)((char*)g1c + pendingOffset) == 0) {
            if (func_020457e0(g1c) == 0) {
                func_ov017_021ab860(*(short*)((char*)unkObj + 4), 1);
                InitContext020e1154((void*)0xbb8);
            }
            ReinitController02043204((char*)g1c);
            self->state = 5;
        }
    } else if (self->state == 5) {
        SetByteField0x253_020397c0(unkObj);
        InitBattleAndControllerState_020d9ab0(self);
    }

    if (IsValueInRange0201b5d8(*p) != 0) {
        return;
    }
    InitBattleAndControllerState_020d9ab0(self);
}
