#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

struct Obj020397cc {
    char pad0[0xb2];
    short fieldB2;
};

struct SearchStruct;
struct Container020dedd0;
struct Container020e0310;
struct Struct020dfc40;

struct StoreStruct {
    void* nameText;
    char pad4[0x14];
    void* listText;
    char pad1c[0xc];
    void* actorText;
    char pad2c[0x30];
    char* message;
    char pad60[0x998 - 0x60];
    int busy;
    char pad99c[4];
    int windowState;
    char pad9a4[0x19ae - 0x9a4];
    unsigned char pending;
};

struct ParamTable021a7e14 {
    char pad0[0x950];
    int nameId;
};

struct Combatant021a7e14 {
    char pad0[0x150];
    ParamTable021a7e14* params;
};

struct MessageBuffers021a7e14 {
    char* first;
    char* second;
    int unk8;
};

struct Element021a7e14 {
    char pad0[8];
    unsigned int kind : 4;
};

struct LootTextContext {
    SafeAllocator allocator;
    char list[0x18];
    Container020dedd0* containerData;
    int field30;
    int field34;
};

struct Obj021a7e14 {
    unsigned char byte0;
    unsigned char finished;
    unsigned char pad2[6];
    SafeAllocator alloc;
    Container020e0310* strings;
    char* message;
    int state;
    int taskId;
    Container020dedd0* container;
    short key;
    short pad32;
    int combatantId;
    short timer;
    unsigned short flags;
    MessageBuffers021a7e14* buffers;
    void* actorText;
    void* listText;
    char* firstBuffer;
    char* secondBuffer;
};

StoreStruct* GetGlobalField0x1c020421a0();
void GetGlobal02109400();
extern "C" SearchStruct* func_0202ae18();
int GetField0x3acValue(GameState* gs);
void CancelPendingAction020397cc(Obj020397cc* obj, int arg);
extern "C" void func_020a0cc4(unsigned int size);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern "C" void func_020a0c0c();
extern "C" void func_ov017_021a7dd8(Obj021a7e14* self);
void ResetStruct020dfc40(Struct020dfc40* p);
extern "C" void func_020dfec0(void* dest, SafeAllocator* alloc, void* data, unsigned int size);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
void ZeroInit020de848(void* p);
void BuildDescriptorFlag1_020de980(void* dest, void* alloc, void* data, int size, int key);
void Clear12Bytes020e46c4(void* p);
extern "C" void* memset(void* dst, int c, unsigned int n);
void DispatchIfCountPositive020dcf7c(int key, void* p);
Element021a7e14* FindElementByKey020dedd0(Container020dedd0* c, int key);
void EnqueueEventTag170_021d0198(int a, int b, int c, int d);
void InitObjFromCombatantId020e4bf4(void* obj, int combatantId);
char* CallFunc020e0434With02153694(int value);
extern "C" void func_020e4b34(void* obj, char* name, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
extern "C" void func_02046380(StoreStruct* g);
void StoreInArray0x8b0(StoreStruct* g, int a, int b);
void SetByteInRange(unsigned char* p, int a, unsigned char b);
char* GetFieldByKey020e0434(Container020e0310* c, int key);
void AppendString02042058(char* dst, const char* src);
int SumKeyedLookups02086bf4(char* p, int key);
extern "C" void func_0204500c(StoreStruct* g, char* text, int a, int b);
extern "C" int func_020457e0(StoreStruct* g);
int TestFlagBitAt0xe(SearchStruct* s, int id);
int DecrementField38Clamped_021a85e8(unsigned char* obj, int amount);
void* ZeroInitReturn020de824(void* p);
void InitStruct0207cbe8(char* p);
extern "C" void func_0207cf30(void* ctx, int key, int amount, int arg);
void ReinitController02043204(char* g);
void SetByteField0x253(void* obj);

extern AllocatorUnion data_02114e20;
extern const char data_ov017_021d77c4[];
extern const char data_ov017_021d77de[];
extern const char* data_020f2a18;
extern const char* data_020f2a0c;

// USA: func_ov017_021a7e14
extern "C" ARM void func_ov017_021a7e14(Obj021a7e14* self) {
    GameState* gs = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    StoreStruct* g = GetGlobalField0x1c020421a0();
    GetGlobal02109400();
    func_ov017_0218b5b0();
    SearchStruct* search = func_0202ae18();
    Obj020397cc* obj = (Obj020397cc*)gs->GetUnknownGameObject();
    int val = GetField0x3acValue(gs);
    CancelPendingAction020397cc(obj, 1);
    int done = 0;
    obj->fieldB2 = 0;

    if (self->state == 0) {
        func_020a0cc4(0x2000);
        void* heap = AllocateAligned4(&data_02114e20, 0x2000);
        if (heap == NULL) {
            func_020a0c0c();
            self->finished = 1;
            return;
        }
        self->alloc.CreateTypeA(heap, 0x2000);
        self->alloc.Reset();
        self->strings = (Container020e0310*)self->alloc.Allocate(0x18);
        if (self->strings == NULL) {
            func_ov017_021a7dd8(self);
            func_020a0c0c();
            self->finished = 1;
            return;
        }
        self->taskId = loader->QueueLoadFileInGP2(data_ov017_021d77c4, data_ov017_021d77de, NULL);
        self->state = 1;
    } else if (self->state == 1) {
        if (loader->GetTaskStatus(self->taskId) != 0) {
            void* data;
            unsigned int length;
            loader->GetLoadedFileByID(self->taskId, &data, &length);
            self->strings = (Container020e0310*)self->alloc.Allocate(0x18);
            ResetStruct020dfc40((Struct020dfc40*)self->strings);
            func_020dfec0(self->strings, &self->alloc, data, length);
            loader->RemoveTask(self->taskId);
            self->taskId = -1;
            self->message = g->message;
            self->state = 2;
        }
    } else if (self->state == 2) {
        BackgroundLoader::AddLockGlobal();
        unsigned int size;
        void* file = ExtractFileFromGP2(data_020f2a18, data_020f2a0c, &size);
        self->container = (Container020dedd0*)self->alloc.Allocate(0x18);
        ZeroInit020de848(self->container);
        if (file != NULL) {
            BuildDescriptorFlag1_020de980(self->container, &self->alloc, file, size, self->key);
        }
        self->buffers = (MessageBuffers021a7e14*)self->alloc.Allocate(0xc);
        self->firstBuffer = (char*)self->alloc.Allocate(0x40);
        self->secondBuffer = (char*)self->alloc.Allocate(0x40);
        if (self->buffers != NULL && self->firstBuffer != NULL && self->secondBuffer != NULL) {
            Clear12Bytes020e46c4(self->buffers);
            memset(self->firstBuffer, 0, 0x40);
            memset(self->secondBuffer, 0, 0x40);
            self->buffers->first = self->firstBuffer;
            self->buffers->second = self->secondBuffer;
            DispatchIfCountPositive020dcf7c(self->key, self->buffers);
        }
        BackgroundLoader::RemoveLockGlobal();
        self->actorText = self->alloc.Allocate(0xc);
        self->listText = self->alloc.Allocate(0xc);
        Combatant021a7e14* combatant = (Combatant021a7e14*)GetCombatantWithFlag0x100(gs, self->combatantId);
        if (FindElementByKey020dedd0(self->container, self->key) == NULL || combatant == NULL ||
            self->buffers == NULL || self->firstBuffer == NULL || self->secondBuffer == NULL ||
            self->actorText == NULL || self->listText == NULL) {
            EnqueueEventTag170_021d0198(5, self->combatantId, val, self->key);
            self->state = 7;
            return;
        }
        Clear12Bytes020e46c4(self->actorText);
        InitObjFromCombatantId020e4bf4(self->actorText, self->combatantId);
        Clear12Bytes020e46c4(self->listText);
        char* name = CallFunc020e0434With02153694((short)combatant->params->nameId);
        func_020e4b34(self->listText, name, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        func_02046380(g);
        StoreInArray0x8b0(g, 0, 1);
        SetByteInRange((unsigned char*)g, 0, 1);
        g->nameText = self->actorText;
        g->listText = self->buffers;
        g->actorText = self->listText;
        char* message = g->message;
        memset(message, 0, 0x960);
        AppendString02042058(message, GetFieldByKey020e0434(self->strings, 0x64));
        AppendString02042058(message, GetFieldByKey020e0434(self->strings, 0x78));
        if (SumKeyedLookups02086bf4((char*)GetPtrField0x2a04(gs), self->key) == 0x63) {
            AppendString02042058(message, GetFieldByKey020e0434(self->strings, 0x70));
            self->flags |= 1;
        } else {
            AppendString02042058(message, GetFieldByKey020e0434(self->strings, 0x6e));
        }
        g->busy = 1;
        func_0204500c(g, message, 0, 0xe3);
        self->state = 3;
    } else if (self->state == 3) {
        if (g->windowState == 3 || g->windowState == 0) {
            g->pending = 0;
            int result = func_020457e0(g);
            if (result == 0) {
                if (self->flags & 1) {
                    EnqueueEventTag170_021d0198(8, self->combatantId, val, self->key);
                    self->flags &= ~1;
                    self->state = 7;
                } else {
                    EnqueueEventTag170_021d0198(6, self->combatantId, val, self->key);
                    self->state = 4;
                    self->timer = 0xe10;
                }
            } else if (result == 1) {
                EnqueueEventTag170_021d0198(7, self->combatantId, val, self->key);
                self->state = 7;
            }
        }
    } else if (self->state == 4) {
        g->pending = 0;
        if (TestFlagBitAt0xe(search, 0) || TestFlagBitAt0xe(search, self->combatantId)) {
            done = 1;
        }
        int ticks = gs->GetTickCount();
        if (ticks == 0) {
            ticks = 1;
        }
        if (DecrementField38Clamped_021a85e8((unsigned char*)self, ticks) == 0) {
            done = 1;
        }
        if (done) {
            func_0204500c(g, GetFieldByKey020e0434(self->strings, 0x71), 0, 0xe3);
            self->state = 7;
        }
    } else if (self->state == 5) {
        g->pending = 0;
        int ticks = gs->GetTickCount();
        if (ticks == 0) {
            ticks = 1;
        }
        if (DecrementField38Clamped_021a85e8((unsigned char*)self, ticks) == 0 && g->windowState == 3) {
            if (TestFlagBitAt0xe(search, 0) || TestFlagBitAt0xe(search, self->combatantId)) {
                func_0204500c(g, GetFieldByKey020e0434(self->strings, 0x71), 0, 0xe3);
                self->state = 7;
            } else {
                Element021a7e14* element = FindElementByKey020dedd0(self->container, self->key);
                LootTextContext context;
                context.allocator.ResetAllocatorPointer();
                ZeroInitReturn020de824(context.list);
                InitStruct0207cbe8((char*)&context);
                InitStruct0207cbe8((char*)&context);
                context.containerData = self->container;
                if ((unsigned char)element->kind == 8) {
                    func_0207cf30(&context, self->key, 1, 0);
                }
                func_02046380(g);
                StoreInArray0x8b0(g, 0, 1);
                SetByteInRange((unsigned char*)g, 0, 1);
                g->nameText = self->actorText;
                g->listText = self->buffers;
                g->actorText = self->listText;
                func_0204500c(g, GetFieldByKey020e0434(self->strings, 0x6f), 0, 0xe3);
                self->state = 7;
            }
        }
    } else if (self->state == 6) {
        ReinitController02043204((char*)g);
        g->busy = 1;
        func_0204500c(g, GetFieldByKey020e0434(self->strings, 0x65), done, 0xe3);
        self->state = 7;
    } else if (self->state == 7) {
        if (g->busy == 0) {
            done = 1;
        }
        if (done) {
            ReinitController02043204((char*)g);
            SetByteField0x253(obj);
            func_ov017_021a7dd8(self);
            func_020a0c0c();
            self->finished = 1;
        }
    }
}
