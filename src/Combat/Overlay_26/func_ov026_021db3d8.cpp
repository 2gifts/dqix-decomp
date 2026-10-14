#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "System/Matrix.h"

struct Foo0207df50 {
    unsigned int a[10];
    unsigned int b[10];
    unsigned int c;
    unsigned int d;
    unsigned int p1[2];
    unsigned int p2[2];
};

struct BattleState {
    char pad0[0x8e49];
    unsigned char kind;
};

struct MessageWork {
#if defined(jpn)
    char pad0[0x870];
#else
    char pad0[0x9a0];
#endif

    int phase;
};

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
    short objectId;
    short f16;
    short f18;
    short f1a;
    short f1c;
    short pad1e;
    int f20;
    int f24;
    int f28;
    Vector3fix offset;
    Vector3fix rotation;
    Vector3fix scale;
};

struct BattleWork {
#if defined(jpn)
    char pad0[0x218];
#else
    char pad0[0x29c];
#endif

    BattleState* battle;
#if defined(jpn)
    char pad2a0[0x76fc];
#else
    char pad2a0[0x7488];
#endif

    signed char effectLoadState;
    char pad7729[0x1];
    short effectTaskId;
    short effectNodeId;
    signed char effectTrigger;
    char pad772f[0x1d];
    SafeAllocator cmdAlloc;
    Foo0207df50 stateB;
};

MessageWork* GetGlobalField0x1c020421a0();
void CopyInternalFields0207df50(Foo0207df50* p);
void InitStruct02078484(InitStruct02078484Struct* req);
int FindNodeAndProcess02057fb4(void* list, int id, int req);

extern "C" {
void* func_02057924();
int func_02057e6c(void* list, int kind, SafeAllocator* alloc, void* data, unsigned int size, Foo0207df50* state);
}

extern char data_ov026_021dedf0[];

// USA: func_ov026_021db3d8
extern "C" ARM void func_ov026_021db3d8(BattleWork* self) {
    if (self->battle->kind == 2) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        void* list = func_02057924();

        if (self->effectTrigger == 0) {
            if (GetGlobalField0x1c020421a0()->phase == 4) {
                self->effectTrigger = 1;
            }
        } else if (self->effectTrigger == 1) {
            if (GetGlobalField0x1c020421a0()->phase == 5) {
                self->effectTrigger = 2;
            }
        }

        if (self->effectLoadState == 0) {
            self->cmdAlloc.Reset();
            CopyInternalFields0207df50(&self->stateB);
            self->effectTaskId = loader->QueueLoadFile(data_ov026_021dedf0, &self->cmdAlloc);
            self->effectLoadState = 1;
        } else if (self->effectLoadState == 1) {
            if (loader->GetTaskStatus(self->effectTaskId)) {
                void* data;
                unsigned int size;
                loader->GetLoadedFileByID(self->effectTaskId, &data, &size);
                func_02057e6c(list, 0x13, &self->cmdAlloc, data, size, &self->stateB);
                loader->RemoveTask(self->effectTaskId);
                self->effectLoadState = 2;
            }
        } else if (self->effectLoadState == 2 && self->effectTrigger == 2) {
            InitStruct02078484Struct req;
            InitStruct02078484(&req);
            req.b1 = 1;
            req.f10 = 0;
            req.offset.z = -0x3000;
            req.scale.x = 0x10a;
            req.scale.y = 0x10a;
            req.scale.z = 0x10a;
            self->effectNodeId = FindNodeAndProcess02057fb4(list, 0x13, (int)&req);
            self->effectTrigger = -1;
            self->effectLoadState = -1;
        }
    }
}
