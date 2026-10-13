#include <globaldefs.h>
#include "World/Zone3D.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "Resource/GameResources.h"
#include "World/Object3D.h"
#include "std_library_functions.h"

struct Struct0205a198;
struct ClearTarget0205a234;
struct Obj0208b8c4;
struct Pool020401fc;
struct ActiveEntry02046900;
struct Rec020467f0;
struct Foo0207df50;
struct SetFlagStruct;

struct List021552a8 {
    char pad0[0x3c];
    void* slots;
    Struct0205a198* entries;
    char pad44[8];
    unsigned short count;
    char pad4e[2];
    unsigned char active;
};

struct Params021552a8 {
    int field0;
    char pad4[3];
    unsigned char hide;
    char pad8[0x38];
    unsigned short nextId;
    unsigned short field42;
    unsigned short flags;
    char pad46[0x22];
};

struct Self021552a8 {
    unsigned char field0;
    unsigned char done;
    char pad2[8];
    unsigned short state;
    Params021552a8 params;
    int taskA;
    int taskB;
    SafeAllocator allocator;
    char pad90[4];
    int field94;
    char pad98[4];
    unsigned char field9c;
    char pad9d[0x107 - 0x9d];
    unsigned char field107;
    char pad108[8];
    int taskC;
    char pad114[0xc];
    void* timer;
    SafeAllocator childAllocator;
    char pad138[0x30];
    List021552a8* list;
    void* slots;
    Struct0205a198* entries;
};

struct Events021552a8 {
    char pad0[0x45b];
    unsigned char bits[0x20];
};

char* GetFieldIfFlag4(char* obj);
extern "C" void _Z19TailForward02012da4P14AllocatorUnionPv(AllocatorUnion* alloc, void* data);
extern "C" void func_0209c2e0(void* obj, int a, int b);
extern "C" void func_ov017_021bb27c(void* obj);
extern "C" void func_0208b9a0(void* obj, unsigned char flag);
extern "C" char* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void _Z32InitAllocatorsAndBuffers0208b8c4P11Obj0208b8c4P13SafeAllocator(Obj0208b8c4* obj, SafeAllocator* alloc);
void* GetGlobalPtr021075f4(void);
void* EmptyStub0203d004(void* p);
extern "C" void _Z16InitPool020401fcP12Pool020401fcjP13SafeAllocator(Pool020401fc* pool, unsigned int count, SafeAllocator* alloc);
extern "C" void _Z12Init0205a198P14Struct0205a198(Struct0205a198* p);
extern "C" void _Z23ClearField0And40205a234P19ClearTarget0205a234(ClearTarget0205a234* p);
extern "C" void _Z18InitStruct0205a444Pc(char* p);
int CountActiveEntries(ActiveEntry02046900* entry);
void* FindRecordByIndex(Rec020467f0* rec, int index, void** out, int* out44);
extern "C" int func_0205a528(void* obj, void* data, int arg2, void* arg3);
extern "C" void func_ov001_0215a850(SafeAllocator* alloc);
extern "C" void func_ov001_0215a8dc(void);
extern "C" void _Z30InitOrClearAllocState_021538d4iPvP13SafeAllocator(int p0, void* unused1, SafeAllocator* alloc);
extern "C" void _Z32ClearAllocSlotsAndStore_0215aa14P13SafeAllocator(SafeAllocator* alloc);
extern "C" void _Z17SetArrVal0215aaa8ii(int idx, int val);
extern "C" void _Z34ForwardArgsAndClearFlag8c_0215acf8ii(int a, int b);
extern "C" void _Z26CopyInternalFields0207df50P11Foo0207df50(Foo0207df50* p);
extern "C" int _Z26StoreArgIfMatched_02153948t(unsigned short arg);
extern "C" Events021552a8* func_0205ec34(void);
extern "C" void* func_02012fe4(void);
void SetOrClearBitInArray(void* unused, unsigned char* array, int bit, int value);
extern "C" void* func_0202ae18(void);
void* GetPtrField0x2a04(GameState* gs);
extern "C" void* _Z27GetDataPtr02114e04_020d6c00v(void);
extern "C" void _Z29ProcessBattlerEffects02019568Pvi(void* area, int arg);
extern "C" Object3D* _Z21GetField4334_021bdbc0Ph(unsigned char* base);
void SetField0x238False(void* obj);
void ClearIntAt0x23c(unsigned char* obj);
void SetFlag0x9c6(SetFlagStruct* p, int value);

extern AllocatorUnion data_02114e20;
extern char data_02109bf4;

static inline void SetListEntries(List021552a8* list, Struct0205a198* entries, unsigned short count) {
    list->entries = entries;
    list->count = count;
}

// USA: func_ov001_021552a8
extern "C" ARM int func_ov001_021552a8(Self021552a8* self) {
    char* sub;
    GameState* gs = GameState::GetInstance();
    GameResources* res = func_ov017_0218b5b0();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    char* hud = GetFieldIfFlag4((char*)gs);
    GameObject* leader = gs->GetUnknownGameObject();
    sub = res->unknown_2cc;

    if (loader->GetTaskStatus(self->taskA) == 0) {
        return self->state;
    }
    if (loader->GetTaskStatus(self->taskB) == 0) {
        return self->state;
    }
    if (self->params.flags & 0x200) {
        if (loader->GetTaskStatus(self->taskC) == 0) {
            return self->state;
        }
    }
    if (loader->GetDetailedTaskStatus(self->taskA) != 2 || loader->GetDetailedTaskStatus(self->taskB) != 2) {
        SignedAllocatorHeader* header = self->allocator.GetSignedAllocator();
        self->allocator.Destroy();
        _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, header);
        loader->RemoveTask(self->taskA);
        loader->RemoveTask(self->taskB);
        loader->RemoveTask(self->taskC);
        func_0209c2e0(&data_02109bf4, self->field94, 0);
        func_ov017_021bb27c(self);
        self->done = 1;
        return self->state;
    }

    void* dataA;
    void* dataB;
    unsigned int lengthA;
    unsigned int lengthB;
    loader->GetLoadedFileByID(self->taskA, &dataA, &lengthA);
    loader->GetLoadedFileByID(self->taskB, &dataB, &lengthB);

    if (self->params.flags & 2) {
        self->timer = self->allocator.Allocate(0xe4);
        func_0208b9a0(self->timer, 0);
        char* msg = _Z26GetGlobalField0x1c020421a0v();
        self->childAllocator.CreateTypeA(self->allocator.Allocate(0xa000), 0xa000);
        self->childAllocator.Reset();
        _Z32InitAllocatorsAndBuffers0208b8c4P11Obj0208b8c4P13SafeAllocator((Obj0208b8c4*)self->timer, &self->childAllocator);
        *(void**)(msg + 0x8c) = self->timer;
    }
    if ((self->params.flags & 1) || (self->params.flags & 4)) {
        _Z16InitPool020401fcP12Pool020401fcjP13SafeAllocator((Pool020401fc*)EmptyStub0203d004(GetGlobalPtr021075f4()), 0xc, &self->allocator);
    }
    if (self->params.flags & 0x200) {
        self->allocator.GetMaxPossibleAllocation();
        self->entries = (Struct0205a198*)self->allocator.Allocate(0x230);
        self->list = (List021552a8*)self->allocator.Allocate(0x54);
        self->slots = self->allocator.Allocate(8);
        for (int i = 0; i < 0xe; i++) {
            _Z12Init0205a198P14Struct0205a198((Struct0205a198*)((char*)self->entries + i * 0x28));
        }
        _Z23ClearField0And40205a234P19ClearTarget0205a234((ClearTarget0205a234*)self->slots);
        _Z18InitStruct0205a444Pc((char*)self->list);
        self->list->active = 0;
        SetListEntries(self->list, self->entries, 0xe);
        self->list->slots = self->slots;

        void* out;
        void* dataC;
        unsigned int lengthC;
        int size;
        loader->GetLoadedFileByID(self->taskC, &dataC, &lengthC);
        int count = CountActiveEntries((ActiveEntry02046900*)dataC);
        for (int j = 0; j < count; j++) {
            void* rec = FindRecordByIndex((Rec020467f0*)dataC, j, &out, &size);
            func_0205a528(self->list, rec, size, &self->allocator);
        }
        loader->RemoveTask(self->taskC);
        self->taskC = -1;
    }

    func_ov001_0215a850(&self->allocator);
    func_ov001_0215a8dc();
    _Z30InitOrClearAllocState_021538d4iPvP13SafeAllocator((int)dataA, 0, &self->allocator);
    _Z32ClearAllocSlotsAndStore_0215aa14P13SafeAllocator(&self->allocator);
    if (self->params.flags & 4) {
        _Z17SetArrVal0215aaa8ii(1, (int)&res->allocator_array_38[7]);
    }
    _Z34ForwardArgsAndClearFlag8c_0215acf8ii((int)dataB, lengthB);
    GameObject* member = gs->GetPartyMemberByIndex(0);
    if (member != NULL && (**(unsigned int**)((char*)member + 0x130) & 1)) {
        self->field107 = 1;
    }
    loader->RemoveTask(self->taskA);
    loader->RemoveTask(self->taskB);
    _Z26CopyInternalFields0207df50P11Foo0207df50((Foo0207df50*)(sub + 0xbd0));

    if (_Z26StoreArgIfMatched_02153948t(self->params.nextId) == 0) {
        SignedAllocatorHeader* buffer = self->childAllocator.GetSignedAllocator();
        if (buffer != NULL) {
            self->childAllocator.Destroy();
            self->allocator.Free(buffer);
        }
        SignedAllocatorHeader* header = self->allocator.GetSignedAllocator();
        self->allocator.Destroy();
        _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, header);
        func_ov017_021bb27c(self);
        self->done = 1;
        return self->state;
    }

    int i;
    int total;
    BmdjScriptNode* node;
    Events021552a8* events = func_0205ec34();
    node = GetNodeAtDepth020196fc((Zone3D*)func_02012fe4(), 0);
    total = node->scriptState.elementCount;
    if (node != NULL) {
        memset(events->bits, 0, sizeof(events->bits));
        for (i = 0; i < total; i++) {
            BmdjSceneElement* e = &node->elements[i];
            if (e != NULL && !(e->flags & 4)) {
                SetOrClearBitInArray(events, events->bits, (unsigned char)i, 1);
            }
        }
    }

    unsigned char arg = self->field9c;
    Params021552a8 params = self->params;
    GameState* state = GameState::GetInstance();
    GameResources* resources = func_ov017_0218b5b0();
    void* area = (Zone3D*)func_02012fe4();
    func_0202ae18();
    GetPtrField0x2a04(state);
    _Z27GetDataPtr02114e04_020d6c00v();
    if (!(params.flags & 0x400)) {
        _Z29ProcessBattlerEffects02019568Pvi(area, arg);
    }
    *((char*)func_0205ec34() + 0x490) = -1;
    if (params.hide != 0) {
        Object3D* obj = _Z21GetField4334_021bdbc0Ph((unsigned char*)resources);
        if (obj != NULL) {
            obj->MakeHidden();
        }
    }

    SetField0x238False(hud);
    ClearIntAt0x23c((unsigned char*)hud);
    *(short*)((char*)leader + 0xb2) = 0;
    SetFlag0x9c6((SetFlagStruct*)res->unknown_ptr_36d0, 0);
    return 3;
}
