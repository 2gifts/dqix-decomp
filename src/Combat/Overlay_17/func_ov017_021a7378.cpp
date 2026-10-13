#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Memory/AllocatorUnion.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "System/Matrix.h"
#include "System/Graphics.h"
#include "Combat/Main/CopyRecord0200fbb4.h"

struct MessageWindow {
    char pad0[0x998];
    int active;
    char pad99c[0x9a0 - 0x99c];
    int busy;
    char pad9a4[0x19ae - 0x9a4];
    unsigned char flag19ae;
    char pad19af[0x19b2 - 0x19af];
    unsigned char flag19b2;
};

struct FieldGlobals {
    char pad0[0x27b8];
    Vector3i cameraTarget;
    char pad27c4[0x27d0 - 0x27c4];
    unsigned char battleCount;
};

struct CameraState {
    char pad0[0x44];
    Vector3i position;
    char pad50[0x13c - 0x50];
    int mode;
};

struct CameraParams {
    unsigned short angle;
    unsigned char flag2;
    unsigned char pad3[2];
    unsigned char flag5;
    unsigned char pad6;
    unsigned char flag7;
    unsigned char pad8[0x10 - 0x8];
    int distance;
    int height;
    int offset;
    unsigned short tilt;
    unsigned char pad1e[0x61 - 0x1e];
    unsigned char flag61;
};

struct TailList020469b4;
struct TailNode020469b4;

struct EntryCounter {
    char pad0[4];
    unsigned short count;
};

struct Container020e0310;
struct PointerField330_ffd0;
struct Obj020d7aa0;
struct ColorHolder0204bef4;
struct FindEntryById02096134Table;

struct BattleIntro {
    unsigned char field0;
    unsigned char done;
    char pad2[0x8 - 0x2];
    int state;
    int mode;
    int counter;
    int pad14;
    int kind;
    unsigned int savedLayers;
    int taskId;
    unsigned char controls[0x25c - 0x24];
    SafeAllocator allocator;
    char container[0x10];
};

unsigned char* GetFieldIfFlag4(char* obj);
MessageWindow* GetGlobalField0x1c020421a0();
extern "C" FieldGlobals* func_02012fe4(void);
CameraState* GetPointerAt0x330(PointerField330_ffd0* obj);
void SetupAndDispatch0205c904(unsigned char* obj, int value);
void* GetGlobalResetObj020d7a50(void);
void TeardownAndResetState020d7aa0(Obj020d7aa0* obj);
extern "C" void func_020a0cc4(unsigned int size);
void ClearByteFlagAt0x19c(unsigned char* obj);
void SetByteFlagAt0x19c(unsigned char* obj);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern "C" void func_020dfec0(void* dest, SafeAllocator* allocator, void* fileData, unsigned int size);
int GetFieldByKey020e0434(Container020e0310* c, int key);
extern "C" void func_0204500c(MessageWindow* window, int entry, int a, int b);
void SetFlagsAt0x244(unsigned char* obj, unsigned char mask);
void ClearFlagBits(unsigned char* obj, int mask);
extern "C" int func_020457e0(MessageWindow* window);
CameraParams* GetField0x3f8Address(GameState* gs);
void InitStruct02070378(char* obj);
void* GetPtrField0x114(void* obj);
int CheckBits5To9NonZero0204bedc(unsigned short* obj);
int ConvertColorToDecimalOffset20000(ColorHolder0204bef4* obj);
void InitAndResetHeader_0219e310(unsigned char* obj, int flag);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
void InitAndAppendState61_021a65c4(void* scene, unsigned char kind, int arg);
extern "C" void func_ov017_021baedc(TailNode020469b4* node, int flag);
void SetHalfFieldsAndEnqueueIfActive_021d1c2c(unsigned short a, unsigned short b);
extern "C" void _Z26EnqueueEventTagB5_021d1dc0ssPisi(unsigned short id, int a, int* buf, int b, int c);
void* GetGlobal02109418(void);
EntryCounter* FindEntryById02096134(FindEntryById02096134Table* table, int id);
void ReinitController02043204(char* obj);
void SetupGlobalObjType3AndInitSelfPointer(unsigned char* obj);
extern "C" void func_ov017_021a79f0(BattleIntro* self);

extern AllocatorUnion data_02114e20;
extern const char data_ov017_021d7798[];
extern const char data_ov017_021d77b2[];

// USA: func_ov017_021a7378
extern "C" ARM void func_ov017_021a7378(BattleIntro* self, int arg) {
    GameState* gs = GameState::GetInstance();
    unsigned char* flags = GetFieldIfFlag4((char*)gs);
    MessageWindow* window = GetGlobalField0x1c020421a0();
    FieldGlobals* globals = func_02012fe4();
    CameraState* camera = GetPointerAt0x330((PointerField330_ffd0*)gs);
    SetupAndDispatch0205c904(self->controls, gs->GetTickCount());

    if (self->state == 0) {
        TeardownAndResetState020d7aa0((Obj020d7aa0*)GetGlobalResetObj020d7a50());
        self->savedLayers = (DISPCNT & 0x1f00) >> 8;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1100;
        func_020a0cc4(0x1400);
        ClearByteFlagAt0x19c((unsigned char*)GetPointerAt0x330((PointerField330_ffd0*)gs));
        FontBankLoader* g = GetGlobal02109400();
        BlankFunction02094b30(g, 0x205, 0);
        if (AlwaysTrue02094b4c(g)) {
            self->taskId = BackgroundLoader::GetInstance()->QueueLoadFileInGP2(data_ov017_021d7798, data_ov017_021d77b2, NULL);
            self->allocator.CreateTypeA(AllocateAligned4(&data_02114e20, 0x1400), 0x1400);
            self->state = 1;
        }
    } else if (self->state == 1) {
        BackgroundLoader* bl = BackgroundLoader::GetInstance();
        if (bl->GetTaskStatus(self->taskId)) {
            void* fileData;
            unsigned int size;
            bl->GetLoadedFileByID(self->taskId, &fileData, &size);
            self->allocator.Reset();
            func_020dfec0(self->container, &self->allocator, fileData, size);
            bl->RemoveTask(self->taskId);
            self->taskId = -1;
            if (self->mode == 0) {
                func_0204500c(window, GetFieldByKey020e0434((Container020e0310*)self->container, 0x23), 0, 0xe3);
                self->state = 0xc8;
            } else {
                func_0204500c(window, GetFieldByKey020e0434((Container020e0310*)self->container, 0x24), 0, 0xe3);
                self->state = 0x12c;
            }
            window->flag19b2 = 0;
            window->active = 1;
            SetFlagsAt0x244(flags, 2);
        }
    } else if (self->state == 0xc8) {
        if (window->busy == 0) {
            ClearFlagBits(flags, 2);
            if (func_020457e0(window) == 0) {
                CameraParams* params = GetField0x3f8Address(gs);
                InitStruct02070378((char*)params);
                params->flag2 = 1;
                params->flag7 = 1;
                params->flag5 = 1;
                params->angle = 0x1901;
                params->tilt = 0x25c2;
                params->distance = 0x3800;
                params->height = 0x999;
                params->offset = -0x3800;
                self->state = 0x64;
                func_ov017_021a7378(self, arg);
            } else {
                self->state = 0x64;
                func_ov017_021a7378(self, arg);
            }
        }
    } else if (self->state == 0x12c) {
        if (window->busy == 0) {
            ClearFlagBits(flags, 2);
            if (func_020457e0(window) == 0) {
                void* color = GetPtrField0x114(camera);
                if (color != NULL && CheckBits5To9NonZero0204bedc((unsigned short*)color)) {
                    self->kind = 0;
                    self->state = 0x62;
                    camera->mode = 1;
                    func_ov017_021a7378(self, arg);
                } else {
                    window->active = 1;
                    func_0204500c(window, GetFieldByKey020e0434((Container020e0310*)self->container, 0x26), 0, 0xe3);
                    self->state = 0x12d;
                    SetFlagsAt0x244(flags, 2);
                }
            } else {
                window->active = 1;
                func_0204500c(window, GetFieldByKey020e0434((Container020e0310*)self->container, 0x25), 0, 0xe3);
                self->state = 0x12d;
                SetFlagsAt0x244(flags, 2);
            }
        }
    } else if (self->state == 0x12d) {
        if (window->busy == 0) {
            ClearFlagBits(flags, 2);
            if (func_020457e0(window) == 0) {
                self->kind = 3;
                camera->mode = 2;
                self->state = 0x63;
            } else {
                self->state = 0x64;
                func_ov017_021a7378(self, arg);
            }
        }
    } else if (self->state == 0x62) {
        if (++self->counter > 0xf) {
            self->state = 0x63;
        }
    } else if (self->state == 0x63) {
        GameResources* res = func_ov017_0218b5b0();
        CameraParams* params;
        TailList020469b4* list = (TailList020469b4*)res->unknown_ptr_array_36fc[0];
        TailNode020469b4* resultNode = (TailNode020469b4*)res->unknown_ptr_array_371c[6];
        params = GetField0x3f8Address(gs);
        InitStruct02070378((char*)params);
        params->flag7 = 1;
        void* color = GetPtrField0x114(camera);
        switch (self->kind) {
        case 0: {
            params->flag61 = 1;
            params->angle = ConvertColorToDecimalOffset20000((ColorHolder0204bef4*)color);
            params->tilt = 0;
            params->distance = 0x100000;
            params->height = 0;
            params->offset = 0x100000;
            globals->cameraTarget = camera->position;
            CallFunc0200fbb4AtField0x3f8(gs, params);
            TailNode020469b4* node = (TailNode020469b4*)res->unknown_ptr_array_36fc[4];
            InitAndResetHeader_0219e310((unsigned char*)node, 0);
            AppendNodeToTail(list, node);
            InitAndAppendState61_021a65c4(res, 1, 0);
            break;
        }
        case 3:
            camera->mode = 2;
            func_ov017_021baedc(resultNode, 1);
            *(unsigned short*)((char*)resultNode + 8) = 0x7346;
            AppendNodeToTail(list, resultNode);
            break;
        }
        Vector3i pos;
        if (self->kind == 3) {
            SetHalfFieldsAndEnqueueIfActive_021d1c2c(3, 0);
            _Z26EnqueueEventTagB5_021d1dc0ssPisi(3, 0, (int*)&pos, 0x7346, 0);
        } else {
            pos = camera->position;
            SetHalfFieldsAndEnqueueIfActive_021d1c2c(0, 0);
            _Z26EnqueueEventTagB5_021d1dc0ssPisi(0, params->angle, (int*)&pos, 0, 0);
        }
        if (globals->battleCount < 0xff) {
            globals->battleCount++;
        }
        EntryCounter* entry = FindEntryById02096134((FindEntryById02096134Table*)GetGlobal02109418(), 0xbc);
        if (entry != NULL && entry->count < 10) {
            entry->count++;
        }
        self->state = 0x64;
        ReinitController02043204((char*)window);
    } else if (self->state == 0x64) {
        window->flag19ae = 0;
        if (window->busy == 0) {
            ReinitController02043204((char*)window);
            SetupGlobalObjType3AndInitSelfPointer(self->controls);
            SetByteFlagAt0x19c((unsigned char*)GetPointerAt0x330((PointerField330_ffd0*)gs));
            func_ov017_021a79f0(self);
            self->done = 1;
        }
    }
}
