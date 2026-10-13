#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "System/Graphics.h"
#include "Resource/MessageSystem.h"

#if defined(jpn)
#define data_ov017_021d6aec data_ov017_021d6ee4
#endif

struct CombatStepObj;
typedef unsigned char (*CombatStepFn)(CombatStepObj* obj);

struct CombatStepTable {
    CombatStepFn fn[13];
};

struct CombatStepObj {
    unsigned char unk0;
    unsigned char finished;
    unsigned char unk2[6];
    unsigned char requestFinish;
    unsigned char mode;
    unsigned char state;
    unsigned char unkB;
    unsigned char searchIndex;
    unsigned char unkD;
    unsigned char unkE[0x1b - 0xe];
    unsigned char slots[0x38 - 0x1b];
    unsigned int field4Bits;
    int mainBrightness;
    unsigned short clearColor;
    unsigned char restoreDisplay;
    unsigned char unk43[5];
#if defined(jpn)
    unsigned char dispatcher[0x210 - 0x48];
#else
    unsigned char dispatcher[0x280 - 0x48];
#endif
    int bgMode;
    int unk284;
    void* allocation;
};

struct CombatMenuNode {
    unsigned char unk0[2];
    unsigned char active;
#if defined(jpn)
    unsigned char unk3[0xc8 - 3];
#else
    unsigned char unk3[0xcc - 3];
#endif
    unsigned char kind;
    unsigned char value397c;
    unsigned char flagBit;
    unsigned char phase;
};

struct CombatantFlags {
    unsigned char unk0[0x49c];
    unsigned char bit0 : 1;
};

struct GrottoInfo02012fe4 {
    unsigned short type;
    unsigned char unk2[6];
    int param;
};

struct SearchStruct;
struct Obj020397cc;
struct TailList020469b4;
struct TailNode020469b4;
struct ClearList02046968;
struct FlagWord020466f4;
struct AllocatorUnion;

extern "C" void* func_0202ae18();
extern "C" void func_ov017_021c37a4();
extern "C" GrottoInfo02012fe4* func_02012fe4();
extern "C" void func_ov017_021baedc(CombatMenuNode* node, int v);
extern "C" void func_ov017_021bbae4(CombatMenuNode* node, int param, int v);
extern "C" void func_ov017_0219577c(int a, int b, int c);
extern "C" int func_ov017_02195658(GameResources* res);
extern "C" void* func_ov017_021b8468(CombatMenuNode* node);
extern "C" void func_ov017_021afb8c(CombatStepObj* obj, unsigned char* p);
extern "C" void func_ov017_0218b5c0(int a, int b);

void* GetDataPtr02114e04_020d6c00();
void* GetGlobal02109030();
void CancelPendingAction020397cc(Obj020397cc* obj, int v);
void SetupAndDispatch0205c904(unsigned char* obj, int v);
int TestMaskBitBySignedByteIndex(SearchStruct* obj, int index);
unsigned char GetField0x397cValue(GameState* gs);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
void ClearBitsInWord(unsigned int* obj, unsigned int mask);
void ResetEightRegionsAndFlags(char* obj);
void SetCombatModeFromCase020dc2d0(int v);
void InvokeIfInputLogBIs3_021dbd1c(void* p, void* q);
void InvokeIfInputLogBIs3_021dbe44(void* p);
void Set3DClearColor(int a, int b, int c, int d, int e);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);
void SetBitsInField4(unsigned int* obj, unsigned int mask);
void ClearListUntilFlagZero(ClearList02046968* list);
void SetByteField0x253(void* obj);
void CopyByteField0x253To0x252(void* obj);
void ResetGlobalObjAndInitSelfPointer0205ce94(unsigned char* obj);
void ClearFlags020466f4(FlagWord020466f4* obj, unsigned int mask);
void DispatchWithGlobalContext020daf9c(int a, int b, int c, int d);
void TailForward02012da4(AllocatorUnion* alloc, void* p);
char* GetGlobalField0x1c020421a0();

extern CombatStepTable data_ov017_021d6aec;
extern AllocatorUnion data_02114e20;

struct CombatantView {
    char unk0[0xb2];
    unsigned short pendingAction;
#if defined(jpn)
    char unkB4[0x144 - 0xb4];
#else
    char unkB4[0x150 - 0xb4];
#endif
    CombatantFlags* flags;
};

// JPN: func_ov017_021afd7c
// USA: func_ov017_021af66c
extern "C" ARM void func_ov017_021af66c(CombatStepObj* obj, void* list) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = func_ov017_0218b5b0();
    SearchStruct* search = (SearchStruct*)func_0202ae18();
    CombatantView* combatant = (CombatantView*)gs->GetUnknownGameObject();
    FlagWord020466f4* flags = (FlagWord020466f4*)GetDataPtr02114e04_020d6c00();
    char* global = (char*)GetGlobal02109030();
    CombatMenuNode* menu = static_cast<CombatMenuNode*>(res->unknown_ptr_3718);
    CancelPendingAction020397cc((Obj020397cc*)combatant, 0);
    combatant->pendingAction = 0;
    CombatStepTable table = data_ov017_021d6aec;
    if (table.fn[obj->state] != 0) {
        int tick = gs->GetTickCount();
        if (tick == 0) {
            tick = 1;
        }
        SetupAndDispatch0205c904(obj->dispatcher, tick);
        obj->state = table.fn[obj->state](obj);
    }
    if (obj->requestFinish != 0) {
        obj->finished = 1;
    }
    if (obj->mode != 2 && *reinterpret_cast<int*>(reinterpret_cast<char*>(search) + 0xfc0) == 0) {
        if (TestMaskBitBySignedByteIndex(search, obj->searchIndex) == 0) {
            obj->finished = 1;
        }
    }
    if (res->unknown_flag_42e2 != 0) {
        if (obj->mode == 2) {
            func_ov017_021c37a4();
            res->unknown_42e3[0] = 1;
            GrottoInfo02012fe4* info = func_02012fe4();
            if (info->type == 1) {
                SetBrightness((GameResources*)res, 0, 30);
                UnlockAndSetBrightness((GameResources*)res, 0, 30);
            }
            CombatMenuNode* node = static_cast<CombatMenuNode*>(res->unknown_ptr_array_371c[6]);
            if (node->active == 0) {
                func_ov017_021baedc(node, 1);
                func_ov017_021bbae4(node, info->param, 2);
                node->value397c = GetField0x397cValue(gs);
                node->flagBit = combatant->flags->bit0;
                node->kind = 1;
                node->phase = 3;
                AppendNodeToTail((TailList020469b4*)list, (TailNode020469b4*)node);
            }
            ClearBitsInWord((unsigned int*)res, 0x40);
        } else {
            func_ov017_0219577c(0, 0, 0);
            CombatMenuNode* node = static_cast<CombatMenuNode*>(res->unknown_ptr_array_371c[6]);
            if (node->active != 0 && node->phase == 2) {
                ResetEightRegionsAndFlags(global);
                SetCombatModeFromCase020dc2d0(0);
            }
        }
        obj->finished = 1;
    }
    int slot = func_ov017_02195658((GameResources*)res);
    if (slot > 0) {
        obj->slots[slot] = 0;
        if (menu->active != 0) {
            void* p = func_ov017_021b8468(menu);
            if (p != 0) {
                InvokeIfInputLogBIs3_021dbd1c(p, (void*)slot);
                func_ov017_021afb8c(obj, obj->unkE);
            }
        }
    }
    if (menu->active != 0) {
        void* p = func_ov017_021b8468(menu);
        if (p != 0) {
            InvokeIfInputLogBIs3_021dbe44(p);
        }
    }
    if (obj->finished == 0) {
        return;
    }
    if (obj->restoreDisplay != 0) {
        SetMainBrightness((GameResources*)res, obj->mainBrightness, 0);
        Set3DClearColor(obj->clearColor, 0, 0x7fff, 0, 0);
        ClearBitsInField4((unsigned int*)res, 0xffffffff);
        SetBitsInField4((unsigned int*)res, obj->field4Bits);
    }
    obj->unkB = 0;
    ClearListUntilFlagZero((ClearList02046968*)list);
    CombatMenuNode* node = static_cast<CombatMenuNode*>(res->unknown_ptr_array_371c[6]);
    int restore = 1;
    if (node->active != 0 && node->phase == 2) {
        restore = 0;
    }
    if (restore) {
        GameObject* c = gs->GetUnknownGameObject();
        if (c != 0) {
            SetByteField0x253(c);
            CopyByteField0x253To0x252(c);
        }
    }
    ResetGlobalObjAndInitSelfPointer0205ce94(obj->dispatcher);
    ClearFlags020466f4((FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0x800000);
    func_ov017_0218b5c0(1, -1);
    DispatchWithGlobalContext020daf9c(0, 1, 0, 1);
    DISPCNT = (DISPCNT & ~0x1f00) | (obj->bgMode << 8);
    ClearBitsInField4((unsigned int*)res, 0x40);
    if (obj->allocation != 0) {
        TailForward02012da4(&data_02114e20, obj->allocation);
        obj->allocation = 0;
    }
    MessageSystem* messages = reinterpret_cast<MessageSystem*>(GetGlobalField0x1c020421a0());
#if defined(jpn)
    messages->flags17ff.flag2 = 0;
#else
    messages->pad19d0[0] = 0;
#endif
    if (static_cast<CombatMenuNode*>(res->unknown_ptr_3718)->active == 0) {
        ClearFlags020466f4(flags, 0x40000);
    }
}
