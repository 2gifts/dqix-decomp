#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "Resource/GameResources.h"
#include "World/LootableContainer.h"

struct Obj020397cc;
struct Obj02033834;
struct Obj02033b68;
struct Obj02086aec;
struct Obj020d7aa0;
struct BitFlags020d805c;
struct Struct0218d618;
struct Obj0205eaa0;
struct Obj02046574;
struct Obj021c2744;
struct TailList020469b4;
struct TailNode020469b4;
struct List02046a3c;
struct Node02046a3c;
struct GetElement02094d5cList;
struct Container020dedd0;

typedef LootableContainerManager::Container Container;

struct Element021adcb0 {
    char pad0[0x16];
    unsigned char active;
    unsigned char kind;
    char pad18[4];
    unsigned short containerId;
};

struct Notice021adcb0 {
    char pad0[2];
    unsigned char busy;
    char pad3[0xe];
    unsigned char ready;
    char pad12[2];
    int memberId;
    int itemId;
};

struct LootTextContext {
    SafeAllocator allocator; char list[0x18]; Container020dedd0* containerData;
    int field30; int field34;
};

struct Chest021adcb0 {
    char pad0[8];
    unsigned char member;
    unsigned char state;
    unsigned char slot;
    unsigned char special;
    signed char delay;
    char padD;
    unsigned short timer;
    short mode;
    char pad12[0xe];
    unsigned char useList;
    unsigned char ambush;
    unsigned short itemId;
    char pad24[8];
    SafeAllocator allocator;
};

void* GetGlobalField0x1c020421a0(void);
extern "C" unsigned char* func_02012fe4(void);
void* GetGlobalResetObj020d7a50(void);
extern "C" void func_ov017_021ae760(Chest021adcb0* self);
void CallIfField498_0218d5ac(void* res);
void* GetFieldIfFlag4(char* gs);
void SetField0x238False(void* obj);
void SetField0x238True(void* obj);
void SetBitsInField4(unsigned int* obj, unsigned int mask);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);
void SetVecYByMode02033834(Obj02033834* obj, int arg);
extern "C" int* func_0202ae18(void);
unsigned char* GetElementStride0x24(unsigned char* p, int i);
Container* GetElement02094d5c(GetElement02094d5cList* list, int id);
void* GetPtrField0x2a04(GameState* gs);
int CheckField0NonZero(int* p);
extern "C" int func_0202c540(void* p);
void InitObjFromCombatantId020e4bf4(void* obj, int combatantId);
int CallFunc020e0434With02153694(int key);
extern "C" void func_02046608(void* g, int mode, int fmt, char* out, int size, int a, int b);
extern "C" void func_020d7e10(void* receiver, void* input, int style, int flag, int a, int b);
void CancelPendingAction020397cc(Obj020397cc* obj, int arg);
int GetByte0x150Bit6(BitFlags020d805c* obj);
void TeardownAndResetState020d7aa0(Obj020d7aa0* obj);
short SumCombatantKeyMatches02086aec(Obj02086aec* obj, int key);
extern "C" int sprintf(char* dst, const char* fmt, ...);
void SetBitInArray(void* arr, int bit, int value);
void SetByteIfChanged02033b68(Obj02033b68* obj, int v);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern "C" void func_ov017_0218d510(GameResources* res, SafeAllocator* alloc);
void SetByteField0x253(void* obj);
extern "C" void _Z21UpdateActivationStateP17UpdateStateStructhii(void* p, int id, int a, int b);
void EnqueueEventTag164_021cfd5c(unsigned char a, unsigned short b, unsigned short c);
int IsField10Eq2_0218d618(Struct0218d618* obj);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" void* func_0205ec34(void);
extern "C" void func_ov017_021a9bc4(void* node, int flag);
extern "C" void func_ov017_021a9a9c(void* node, int a, int b, int c, int d);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
void* ZeroInitReturn020de824(void*);
void InitStruct0207cbe8(char*);
extern "C" int func_0207d538(void*, int, int, char*, int);
extern "C" void func_ov017_0218d644(GameResources*, Vector3fix*, int);
void ForwardField0xc0_0205eb80(void* obj);
void SetForwardAndStore0205eb54(void* obj, int arg1, int arg2);
void DispatchIfField0xc4NonNeg_0205eb90(void* obj, int a, int b);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0* obj, int a, int b);
void SetOrClearBitInArray(void* unused, unsigned char* array, int bit, int value);
extern "C" void func_ov017_021cdb00(int, int, int, int);
int HasNonZeroByteAtOfField498_0218d75c_0218d75c(void* obj);
void SetIndexedName02046574(Obj02046574* obj, int index, char* str);
void InitState69_021c2744(Obj021c2744* p);
void InsertNodeAfterHead(List02046a3c* list, Node02046a3c* node);

extern char data_ov017_021d799c[];
extern char data_ov017_021d79a2[];
extern AllocatorUnion data_02114e20;
extern char data_02108760;
extern short data_ov017_021d6ac4[];
extern unsigned char data_ov017_021d6ac0[];

// USA: func_ov017_021adcb0
extern "C" ARM void func_ov017_021adcb0(Chest021adcb0* self) {
    GameState* gs = GameState::GetInstance();
    void* g = GetGlobalField0x1c020421a0();
    unsigned char* save = func_02012fe4();
    LootableContainerManager* mgr = LootableContainerManager::GetMainInstance();
    GetElement02094d5cList* list = (GetElement02094d5cList*)(save + 0x2724);
    void* reset = GetGlobalResetObj020d7a50();
    GameObject* member = gs->GetPartyMemberByIndex(self->member);
    GameResources* res = func_ov017_0218b5b0();
    TailList020469b4* tail = (TailList020469b4*)res->unknown_ptr_array_36fc[0];

    if (member == NULL) {
        func_ov017_021ae760(self);
        return;
    }
    if (res) {
        CallIfField498_0218d5ac(res);
    }

    if (self->state == 0) {
        GameState* gs2 = GameState::GetInstance();
        void* camera = GetFieldIfFlag4((char*)gs2);
        if (camera) {
            SetField0x238False(camera);
        }
        if (res) {
            SetBitsInField4((unsigned int*)res, 0x80);
        }
        *(unsigned short*)((char*)member + 0xb2) = 0;
        SetVecYByMode02033834((Obj02033834*)member, self->mode);
        int* search = func_0202ae18();
        Element021adcb0* elem = (Element021adcb0*)GetElementStride0x24(save, self->slot);
        Container* container = NULL;
        if (elem) {
            if (self->useList) {
                container = GetElement02094d5c(list, elem->containerId);
            } else {
                container = mgr->GetContainerByID(elem->containerId, NULL);
            }
        }
        Obj02086aec* party = (Obj02086aec*)GetPtrField0x2a04(gs2);
        if (CheckField0NonZero(search) && func_0202c540(search) && container && container->containerType == 0) {
            char who[0xc];
            char text[0x50];
            InitObjFromCombatantId020e4bf4(who, self->member);
            *(char**)g = who;
            func_02046608(g, 0xc, CallFunc020e0434With02153694(0x28), text, 0xe3, 0, 1);
            func_020d7e10(GetGlobalResetObj020d7a50(), text, 0, 0, 1, 1);
            func_ov017_021ae760(self);
        } else if (container && container->unk_4_0 != 0) {
            CancelPendingAction020397cc((Obj020397cc*)member, 1);
            void* r = GetGlobalResetObj020d7a50();
            if (GetByte0x150Bit6((BitFlags020d805c*)r)) {
                TeardownAndResetState020d7aa0((Obj020d7aa0*)r);
            }
            int found = 0;
            int keyA = SumCombatantKeyMatches02086aec(party, 0x561c);
            int keyB = SumCombatantKeyMatches02086aec(party, 0x561a);
            int keyC = SumCombatantKeyMatches02086aec(party, 0x561b);
            if (keyA > 0) {
                found = 1;
            } else if (container->unk_4_0 == 1 && (keyB > 0 || keyC > 0)) {
                found = 1;
            } else if (container->unk_4_0 == 2 && keyC > 0) {
                found = 1;
            }
            if (found) {
                char text[0x100];
                char who[0xc];
                char fmt[0x100];
                int name = CallFunc020e0434With02153694(0x29);
                sprintf(fmt, data_ov017_021d799c, name, CallFunc020e0434With02153694(0x2b));
                InitObjFromCombatantId020e4bf4(who, self->member);
                *(char**)g = who;
                func_02046608(g, 0xc, (int)fmt, text, 0xe3, 0, 1);
                func_020d7e10(GetGlobalResetObj020d7a50(), text, 0, 0, 1, 1);
                self->delay = 0xf;
                self->state = 9;
            } else {
                char text[0x100];
                if (keyB > 0 || keyC > 0) {
                    int name = CallFunc020e0434With02153694(0x29);
                    sprintf(text, data_ov017_021d799c, name, CallFunc020e0434With02153694(0x2c));
                } else {
                    sprintf(text, data_ov017_021d79a2, CallFunc020e0434With02153694(0x29));
                }
                func_020d7e10(GetGlobalResetObj020d7a50(), text, 0, 0, 1, 1);
                self->timer = 0;
                self->state = 8;
            }
        } else {
            CancelPendingAction020397cc((Obj020397cc*)member, 1);
            if (self->useList) {
                SetBitInArray(gs2, *(unsigned short*)save % 20, self->slot);
            }
            SetByteIfChanged02033b68((Obj02033b68*)member, 7);
            self->state = 1;
        }
        if ((self->state == 1 || self->state == 9) && container && container->itemIDOrRank == 0x5617) {
            self->special = 1;
            self->allocator.ResetAllocatorPointer();
            self->allocator.CreateTypeA(AllocateAligned4(&data_02114e20, 0x4000), 0x4000);
            self->allocator.Reset();
            func_ov017_0218d510(func_ov017_0218b5b0(), &self->allocator);
        }
    } else if (self->state == 8) {
        self->timer += gs->GetEffectiveDeltaTime();
        if (self->timer > 0x2ee) {
            GameObject* leader = gs->GetUnknownGameObject();
            if (leader) {
                SetByteField0x253(leader);
            }
            func_ov017_021ae760(self);
        }
    } else if (self->state == 9) {
        self->delay--;
        if (self->delay <= 0) {
            SetByteIfChanged02033b68((Obj02033b68*)member, 7);
            self->state = 1;
        }
    } else if (self->state == 1) {
        if (*(int*)((char*)member + 0x24) >= 0x666) {
            Element021adcb0* elem = (Element021adcb0*)GetElementStride0x24(save, self->slot);
            if (elem) {
                if (elem->kind == 2 || elem->kind == 1) {
                    _Z21UpdateActivationStateP17UpdateStateStructhii(elem, *(short*)((char*)member + 4), 1, 1);
                } else {
                    _Z21UpdateActivationStateP17UpdateStateStructhii(elem, *(short*)((char*)member + 4), 1, 0);
                }
            }
            EnqueueEventTag164_021cfd5c(*(short*)((char*)member + 4), *(unsigned short*)save, self->slot);
            self->state = 2;
        }
    } else if (self->state == 2) {
        if (*(int*)((char*)member + 0x24) >= 0xb33) {
            if (self->special && !IsField10Eq2_0218d618((Struct0218d618*)func_ov017_0218b5b0())) {
                return;
            }
            if (!self->ambush && !self->special) {
                GameObject* leader = gs->GetUnknownGameObject();
                if (leader) {
                    SetByteField0x253(leader);
                }
                void* camera = GetFieldIfFlag4((char*)GameState::GetInstance());
                if (camera) {
                    SetField0x238True(camera);
                }
                if (res) {
                    ClearBitsInField4((unsigned int*)res, 0x80);
                }
            }
            self->state = 4;
        }
    } else if (self->state == 4) {
        save = func_02012fe4();
        Element021adcb0* elem = (Element021adcb0*)GetElementStride0x24(save, self->slot);
        if (elem) {
            char* text = *(char**)((char*)g + 0x60);
            memset(text, 0, 0x960);
            int done = 0;
            if (elem) {
                func_0205ec34();
                unsigned short pos = 0;
                Container* container;
                if (self->useList) {
                    container = GetElement02094d5c(list, elem->containerId);
                } else {
                    container = mgr->GetContainerByID(elem->containerId, &pos);
                }
                if (container) {
                    if (container->lootType == 4) {
                        void* node = res->unknown_ptr_array_3afc[0x1b];
                        func_ov017_021a9bc4(node, 0);
                        func_ov017_021a9a9c(node, 1, 0, 0, 0);
                        AppendNodeToTail(tail, (TailNode020469b4*)node);
                        done = 1;
                    } else if (container->lootType == 3) {
                        done = 1;
                        self->ambush = done;
                        self->itemId = container->itemIDOrRank;
                    } else {
                        LootTextContext context;
                        context.allocator.ResetAllocatorPointer();
                        ZeroInitReturn020de824(context.list);
                        InitStruct0207cbe8((char*)&context);
                        char item[0x80] = {};
                        InitStruct0207cbe8((char*)&context);
                        context.containerData = (Container020dedd0*)(save + 0x2754);
                        if (func_0207d538(&context, container->lootType, container->itemIDOrRank, item, 1)) {
                            sprintf(text, data_ov017_021d79a2, item);
                            done = 1;
                        }
                    }
                }
            }
            if (!done) {
                sprintf(text, (char*)CallFunc020e0434With02153694(0x2d));
            }
        }
        Element021adcb0* elem2 = (Element021adcb0*)GetElementStride0x24(save, self->slot);
        if (elem2) {
            LootableContainerManager* mgr2 = LootableContainerManager::GetMainInstance();
            unsigned short pos2 = 0;
            Container* chest;
            if (self->useList) {
                chest = GetElement02094d5c(list, elem2->containerId);
            } else {
                chest = mgr2->GetContainerByID(elem2->containerId, &pos2);
            }
            if (chest) {
                GameResources* res2 = func_ov017_0218b5b0();
                if (self->special) {
                    func_ov017_0218d644(res2, &chest->position, 0);
                }
                int type = chest->lootType;
                if (type != 4) {
                    func_020d7e10(reset, *(char**)((char*)g + 0x60), type == 2, chest->lootType == 2, 0, 0);
                    if (self->ambush) {
                        ForwardField0xc0_0205eb80(&data_02108760);
                        SetForwardAndStore0205eb54(&data_02108760, 0x15e, 0x15e);
                        DispatchIfField0xc4NonNeg_0205eb90(&data_02108760, 0, 0);
                    } else if (chest->lootType != 0 && chest->itemIDOrRank != 0x5617) {
                        DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 0xe, 0);
                    }
                }
                int id = chest->uniqueID;
                unsigned char* flags = (unsigned char*)func_0205ec34();
                if (chest->containerType == 0) {
                    SetOrClearBitInArray(flags, flags + 0x8c, id + 0x212, 1);
                    func_ov017_021cdb00(1, id, 1, -1);
                } else if (!self->useList) {
                    SetOrClearBitInArray(flags, flags + 0x8c, id + 0x79e, 1);
                }
                chest->unk_4_0 = 0;
                chest->lootType = 0;
            }
        }
        self->state = 5;
    } else if (self->state == 5) {
        if (self->special) {
            if (!HasNonZeroByteAtOfField498_0218d75c_0218d75c(func_ov017_0218b5b0())) {
                GameObject* leader = gs->GetUnknownGameObject();
                if (leader) {
                    SetByteField0x253(leader);
                }
                func_ov017_021ae760(self);
            }
        } else if (self->ambush) {
            self->state = 6;
        } else {
            func_ov017_021ae760(self);
        }
    } else if (self->state == 6) {
        Notice021adcb0* notice = (Notice021adcb0*)res->unknown_ptr_array_3afc[0x2c];
        if (notice->busy == 0) {
            Element021adcb0* elem = (Element021adcb0*)GetElementStride0x24(save, self->slot);
            if (elem) {
                elem->active = 0;
            }
            char text[0x78];
            text[0] = 0;
            const short* msgs = data_ov017_021d6ac4;
            const unsigned char* ids = data_ov017_021d6ac0;
            for (int i = 0; i < 3; i++) {
                unsigned char id = ids[i];
                if (id == self->itemId) {
                    SetIndexedName02046574((Obj02046574*)g, 0, (char*)CallFunc020e0434With02153694(msgs[i]));
                    func_02046608(g, 0xc, CallFunc020e0434With02153694(0x2a), text, 0xe3, 0, 1);
                }
            }
            func_020d7e10(GetGlobalResetObj020d7a50(), text, 0, 0, 1, 1);
            InitState69_021c2744((Obj021c2744*)notice);
            notice->memberId = *(short*)((char*)member + 4);
            notice->ready = 1;
            notice->itemId = self->itemId;
            InsertNodeAfterHead((List02046a3c*)tail, (Node02046a3c*)notice);
        }
        func_ov017_021ae760(self);
    }
}
