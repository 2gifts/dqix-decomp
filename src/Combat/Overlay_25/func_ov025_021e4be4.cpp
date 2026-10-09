#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "std_library_functions.h"

extern "C" SafeAllocator* _Z31GetArrayEntry_021e8a54_021e8a54Pc(char* obj);
struct RemoveList021eb084;
extern "C" void _Z28RemoveMatchingShort_021eb084P18RemoveList021eb084i(struct RemoveList021eb084* obj, int val);
struct Struct_203dafc;
void ClearEightWords(struct Struct_203dafc* obj);
void SetField0x3b0Value(GameState* battleStruct, int value);

struct Obj0204a120;
extern "C" void _Z17InitState0204a120P11Obj0204a120(struct Obj0204a120* obj);
struct Owner0204a3f0;
struct Holder0204a3f0;
extern "C" void _Z28SetHolderAndMarkNode0204a3f0P13Owner0204a3f0P14Holder0204a3f0(struct Owner0204a3f0* owner, struct Holder0204a3f0* h);
extern "C" void _Z15SetName0204a440PcPKc(char* obj, const char* src);
void SetStringField0234(char* obj, const char* src);

struct Node021e8bac {
    unsigned char type;
    unsigned char priority;
    unsigned short id2;
    unsigned short id4;
    struct Node021e8bac* next;
};
struct Obj021e8bac;
extern "C" void _Z19PushLogNode021e8bacP11Obj021e8bacP12Node021e8bac(struct Obj021e8bac* obj, struct Node021e8bac* node);

struct Global021ef988 {
    char pad0[0xc];
    char* battle;
};

struct Param021e4be4 {
    char pad0[8];
    char* fileName;
};

extern struct Global021ef988 data_ov025_021ef988;
extern char data_ov025_021eef78[];
extern const char data_ov025_021ef7f7[];
extern const char data_ov025_021ef7fb[];

// USA: func_ov025_021e4be4
extern "C" ARM int func_ov025_021e4be4(struct Param021e4be4* p) {
    GameState* gs = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    SafeAllocator* allocator = _Z31GetArrayEntry_021e8a54_021e8a54Pc(data_ov025_021ef988.battle);

    char path[0x28];
    int n = 0x28;
    unsigned char* d = (unsigned char*)path;
    unsigned char* s = (unsigned char*)data_ov025_021eef78;
    do {
        *d = *s;
        d++;
        s++;
    } while (--n);
    strcat(path, p->fileName);

    void* fileData;
    unsigned int length;
    int taskId = loader->GetLoadedFileByName(path, &fileData, &length);
    if (fileData == NULL) {
        if (taskId >= 0) {
            loader->RemoveTask(taskId);
            _Z28RemoveMatchingShort_021eb084P18RemoveList021eb084i((struct RemoveList021eb084*)data_ov025_021ef988.battle, taskId);
        }
        return 1;
    }

    Object3D* model = (Object3D*)allocator->Allocate(sizeof(Object3D));
    if (model == NULL) {
        loader->RemoveTask(taskId);
        _Z28RemoveMatchingShort_021eb084P18RemoveList021eb084i((struct RemoveList021eb084*)data_ov025_021ef988.battle, taskId);
        return 1;
    }

    Node021e8bac* node = (Node021e8bac*)allocator->Allocate(sizeof(Node021e8bac));
    if (node == NULL) {
        loader->RemoveTask(taskId);
        _Z28RemoveMatchingShort_021eb084P18RemoveList021eb084i((struct RemoveList021eb084*)data_ov025_021ef988.battle, taskId);
        return 1;
    }

    model->Initialize();
    ObjectArchiveLoadInfo info;
    ClearEightWords((struct Struct_203dafc*)&info);
    info.fileData = fileData;
    info.unk_8 = length;
    info.allocator = allocator;
    info.unk_10 = 1;
    if (!model->LoadFromCHRArchive(&info)) {
        loader->RemoveTask(taskId);
        _Z28RemoveMatchingShort_021eb084P18RemoveList021eb084i((struct RemoveList021eb084*)data_ov025_021ef988.battle, taskId);
        return 1;
    }
    loader->RemoveTask(taskId);
    _Z28RemoveMatchingShort_021eb084P18RemoveList021eb084i((struct RemoveList021eb084*)data_ov025_021ef988.battle, taskId);

    char* state = (char*)allocator->Allocate(0x268);
    if (state == NULL) {
        loader->RemoveTask(taskId);
        _Z28RemoveMatchingShort_021eb084P18RemoveList021eb084i((struct RemoveList021eb084*)data_ov025_021ef988.battle, taskId);
        return 1;
    }

    _Z17InitState0204a120P11Obj0204a120((struct Obj0204a120*)state);
    _Z28SetHolderAndMarkNode0204a3f0P13Owner0204a3f0P14Holder0204a3f0((struct Owner0204a3f0*)state, (struct Holder0204a3f0*)model);
    _Z15SetName0204a440PcPKc(state, data_ov025_021ef7f7);
    SetStringField0234(state, data_ov025_021ef7fb);
    SetField0x3b0Value(gs, (int)state);
    node->type = 3;
    _Z19PushLogNode021e8bacP11Obj021e8bacP12Node021e8bac((struct Obj021e8bac*)data_ov025_021ef988.battle, node);
    return 1;
}
