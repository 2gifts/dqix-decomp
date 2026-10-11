// JPN: func_ov017_021c2cf0
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Resource/TextQueue.h"

#if defined(jpn)
extern "C" int sprintf(char* out, const char* format, ...);
extern "C" void func_020d7e10(void* receiver, void* input, int style, int flag, unsigned char option);
extern "C" char data_ov017_021d70e0[];
extern "C" char data_ov017_021d7108[];
enum { ResourceFlag = 0x40c8, GrottoReset = 0x27d4 };
#else
enum { ResourceFlag = 0x42e8, GrottoReset = 0x2794 };
#endif

struct SearchStruct;
extern "C" struct SearchStruct* func_0202ae18(void);
extern "C" int func_0202c508(struct SearchStruct* obj);
extern "C" unsigned short* func_02012fe4(void);
extern "C" void func_02046608(void* a, int b, int c, void* d, int e, int f, int g);
extern "C" int func_ov017_021959b4(void);
extern "C" int func_ov017_021a23e4(char* c, int a0, unsigned int f8, unsigned int fc);

void* GetGlobalResetObj020d7a50(void);
unsigned char GetField0x397cValue(GameState* battleStruct);
void* GetGlobalField0x1c020421a0(void);
void InitObjFromCombatantId020e4bf4(void* obj, int combatantId);
int CallFunc020e0434With02153694(int a);
void SetForwardAndStore0205ebc0(void* obj, int arg1, int arg2);
void DispatchIfField0xc4NonNeg_0205ebfc(void* obj, int a, int b);
void InitContext020e1154(void* obj);
struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);
struct Obj020d7aa0;
void TeardownAndResetState020d7aa0(struct Obj020d7aa0* obj);
struct BitFlags02037170;
extern "C" int _ZNK8Object3D19HasAnimationStoppedEv(struct BitFlags02037170* obj);
struct BitFlags02037180;
extern "C" int _ZNK8Object3D22HasAnimationReachedEndEv(struct BitFlags02037180* obj);
void ForwardField0xc0_0205ebec(void* obj);
void SetByteField0x253(void* obj);
int GetBitflagForCombatantColor_021a26e8(int unused0, int combatantId);
void EnqueueEventTag139_021d09cc(int a, int b, int c, int d);
GameObject* FindCombatantByField0x16a(GameState* battleStruct, int id);

extern int data_02108760;

struct Obj_021c2784 {
    unsigned char pad0[0x1];
    unsigned char field1;
    unsigned char pad2[0x6];
    unsigned short field8;
    unsigned char pad3[0x2];
    int fieldc;
    unsigned char state;
    unsigned char field11;
    unsigned short field12;
    int field14;
    int field18;
};

// USA: func_ov017_021c2784
extern "C" ARM void func_ov017_021c2784(Obj_021c2784* obj) {
    GameState* battleStruct = GameState::GetInstance();
    GameResources* ov = func_ov017_0218b5b0();
    struct SearchStruct* search = func_0202ae18();
    void* reset = GetGlobalResetObj020d7a50();

    GameObject* a = battleStruct->GetPartyMemberByIndex(obj->field14);
    int fieldVal = GetField0x397cValue(battleStruct);
    GameObject* c = battleStruct->GetPartyMemberByIndex(fieldVal);
    if (!a || !c) {
        obj->field1 = 1;
    }
    if (func_ov017_021959b4()) {
        obj->field1 = 1;
        return;
    }

    if (obj->state == 0) {
        *(unsigned char*)((char*)ov + ResourceFlag) = 1;
        CancelPendingAction020397cc((struct Obj020397cc*)c, 1);
        *(unsigned short*)((char*)c + 0xb2) = 0;
        if (obj->field11 != 0) {
            obj->field8 = 0;
        } else {
#if defined(jpn)
            char buf2[0x50];
            sprintf(buf2, data_ov017_021d70e0, *(char**)((char*)a + 0x134));
            func_020d7e10(reset, buf2, 0, 0, 1);
#else
            void* g = GetGlobalField0x1c020421a0();
            char buf1[0xc];
            char buf2[0x50];
            InitObjFromCombatantId020e4bf4(buf1, obj->field14);
            *(void**)g = buf1;
            int ret = CallFunc020e0434With02153694(0x26);
            func_02046608(g, 0xc, ret, buf2, 0xe3, 0, 1);
            func_020d7e10(reset, buf2, 0, 0, 1, 1);
#endif
            SetForwardAndStore0205ebc0(&data_02108760, 0x79, 0x79);
            DispatchIfField0xc4NonNeg_0205ebfc(&data_02108760, 0, 0);
            obj->field8 = 0x3e8;
        }
        obj->state = 1;
        return;
    } else if (obj->state == 1) {
        unsigned int v = (unsigned int)battleStruct->GetEffectiveDeltaTime();
        if (v < obj->field8) {
            obj->field8 -= v;
            return;
        }
        obj->field8 = (obj->field11 != 0) ? 0x64 : 0x384;

        unsigned short* p = func_02012fe4();
        if (*p == 0x2710) {
            *(int*)((char*)p + GrottoReset) = 0;
            InitContext020e1154((void*)0x7d0);
            obj->state = 5;
            return;
        }
        if (func_0202c508(search)) {
            int fv2 = GetField0x397cValue(battleStruct);
            int ret = func_ov017_021a23e4((char*)ov, fv2, 0, obj->field18);
            obj->field12 = (unsigned short)ret;
            if (obj->field12 != 0) {
                *(volatile unsigned char*)&obj->state = 5;
            } else {
                *(volatile unsigned char*)&obj->state = 2;
            }
            return;
        }
        int fv3 = GetField0x397cValue(battleStruct);
        int bitflag = GetBitflagForCombatantColor_021a26e8((int)ov, fv3);
        EnqueueEventTag139_021d09cc(0, 0, bitflag, obj->field18);
        obj->state = 4;
        return;
    } else if (obj->state == 2) {
        int val;
        if (obj->field11 != 0) {
            val = 0;
        } else {
            TeardownAndResetState020d7aa0((struct Obj020d7aa0*)reset);
#if defined(jpn)
            func_020d7e10(reset, data_ov017_021d7108, 0, 0, 1);
#else
            int cbv = CallFunc020e0434With02153694(0x27);
            func_020d7e10(reset, (void*)cbv, 0, 0, 1, 1);
#endif
            val = 0xbb8;
        }
        obj->field8 = val;
        obj->state = 3;
        return;
    } else if (obj->state == 3) {
        unsigned int v = (unsigned int)battleStruct->GetEffectiveDeltaTime();
        if (v < obj->field8) {
            obj->field8 -= v;
            return;
        }
        GameObject* combatant = battleStruct->GetMaybeFieldMonsterByIndex(obj->fieldc);
        if (obj->fieldc > 0 && combatant != NULL) {
            if (_ZNK8Object3D19HasAnimationStoppedEv((struct BitFlags02037170*)combatant) == 0) {
                if (_ZNK8Object3D22HasAnimationReachedEndEv((struct BitFlags02037180*)combatant) == 0) {
                    return;
                }
            }
        }
        ForwardField0xc0_0205ebec(&data_02108760);
        SetByteField0x253(c);
        obj->field1 = 1;
        return;
    } else if (obj->state == 4) {
        unsigned int v = (unsigned int)battleStruct->GetEffectiveDeltaTime();
        unsigned short f8 = obj->field8;
        if (v < f8) {
            *(volatile unsigned short*)&obj->field8 = f8 - v;
        } else {
            *(volatile unsigned short*)&obj->field8 = 0;
        }
        return;
    } else if (obj->state == 5) {
        GameObject* found = FindCombatantByField0x16a(battleStruct, obj->field12);
        if (obj->field12 != 0) {
            if (found == NULL) {
                return;
            }
            obj->fieldc = *(short*)((char*)found + 4);
        }
        *(unsigned char*)((char*)c + 0xc3) = 0;
        obj->state = 3;
    }
}
