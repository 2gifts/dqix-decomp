#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"

struct CombatNode021e66cc {
    char pad0[0x20];
    unsigned short id;
};

struct CombatSlot021e66cc {
    char pad0[0x10];
    struct CombatNode021e66cc* head;
};

struct ActiveSub021e66cc {
    char pad0[8];
    unsigned int flags0 : 4;
    unsigned int kind : 5;
};

struct Node021e8bac {
    unsigned char type;
    unsigned char priority;
    unsigned short id2;
    unsigned short id4;
    struct Node021e8bac* next;
};

struct Global021ef988 {
    char pad0[0xc];
    char* battle;
    char pad10[0x10];
    int state;
    int objectId;
    int taskId;
};

struct Reset021e3158 { int a; int b; int c; int d; int e; int f; };

struct Outer_02054000;
struct Obj021e8bac;
struct Struct_203dafc;

GameObject* GetCombatantWithFlag0x100(GameState* battleStruct, int id);
extern "C" ActiveSub021e66cc* _Z21GetActiveSub_02054000P14Outer_02054000(struct Outer_02054000* p);
extern "C" void _Z20ResetStruct_021e3158P13Reset021e3158(struct Reset021e3158* p);
extern "C" int _Z27SetFlagAndDispatch_021e2628ii(int a, int b);
extern "C" SafeAllocator* _Z31GetArrayEntry_021e8a54_021e8a54Pc(char* obj);
extern "C" void _Z19PushLogNode021e8bacP11Obj021e8bacP12Node021e8bac(struct Obj021e8bac* obj, struct Node021e8bac* node);
void ClearEightWords(struct Struct_203dafc* obj);

extern struct Global021ef988 data_ov025_021ef988;
extern struct Reset021e3158 data_ov025_021ef9a8;
extern char data_ov025_021ef7be[];
extern char data_ov025_021ef811[];
extern char data_ov025_021ef81e[];

// USA: func_ov025_021e66cc
extern "C" ARM int func_ov025_021e66cc(void* unused, struct CombatSlot021e66cc* slot) {
    GameState* gs = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    if (data_ov025_021ef988.state == 0) {
        GameObject* c = GetCombatantWithFlag0x100(gs, slot->head->id);
        if (c == NULL) {
            _Z20ResetStruct_021e3158P13Reset021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        ActiveSub021e66cc* sub = _Z21GetActiveSub_02054000P14Outer_02054000((struct Outer_02054000*)c);
        if (sub == NULL) {
            _Z20ResetStruct_021e3158P13Reset021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        if (sub->kind == 4) {
            data_ov025_021ef988.taskId = _Z27SetFlagAndDispatch_021e2628ii((int)data_ov025_021ef7be, (int)data_ov025_021ef811);
        } else if (sub->kind == 0xb) {
            data_ov025_021ef988.taskId = _Z27SetFlagAndDispatch_021e2628ii((int)data_ov025_021ef7be, (int)data_ov025_021ef81e);
        } else {
            _Z20ResetStruct_021e3158P13Reset021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        data_ov025_021ef988.state++;
        return 0;
    }

    if (data_ov025_021ef988.state == 1) {
        int taskId = data_ov025_021ef988.taskId;
        if (loader->GetTaskStatus(taskId) == 0) {
            return 0;
        }
        if (loader->GetDetailedTaskStatus(taskId) != 2) {
            loader->RemoveTask(taskId);
            _Z20ResetStruct_021e3158P13Reset021e3158(&data_ov025_021ef9a8);
            return 1;
        }

        unsigned int length;
        void* fileData;
        loader->GetLoadedFileByID(taskId, &fileData, &length);

        GameObject* holder = gs->GetGameObjectByIndex(200);
        if (holder == NULL) {
            loader->RemoveTask(taskId);
            _Z20ResetStruct_021e3158P13Reset021e3158(&data_ov025_021ef9a8);
            return 1;
        }

        SafeAllocator* allocator = _Z31GetArrayEntry_021e8a54_021e8a54Pc(data_ov025_021ef988.battle);
        Node021e8bac* node = (Node021e8bac*)allocator->Allocate(sizeof(Node021e8bac));
        if (node == NULL) {
            loader->RemoveTask(taskId);
            _Z20ResetStruct_021e3158P13Reset021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        node->type = 0;
        node->id2 = 200;
        node->id4 = 0;
        _Z19PushLogNode021e8bacP11Obj021e8bacP12Node021e8bac((struct Obj021e8bac*)data_ov025_021ef988.battle, node);

        ObjectArchiveLoadInfo info;
        ClearEightWords((struct Struct_203dafc*)&info);
        info.fileData = fileData;
        info.unk_8 = length;
        info.unk_10 = 1;
        info.allocator = allocator;
        holder->obj3D_.LoadFromCCHROrCMOTArchive(&info, NULL);
        loader->RemoveTask(taskId);
        _Z20ResetStruct_021e3158P13Reset021e3158(&data_ov025_021ef9a8);
        return 1;
    }

    return 0;
}
