#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

struct CloneSource { unsigned char padding0[0x20]; unsigned short id; };
struct CloneTargets { unsigned char padding0[0x10]; CloneSource* head; };
struct CloneGlobals {
#if defined(jpn)
    unsigned char padding0[4];
    char* context;
    unsigned char padding8[4];
    unsigned int flags;
    unsigned char padding10[0x10];
#else
    unsigned char padding0[0xc];
    char* context;
    unsigned char padding10[0xc];
    unsigned int flags;
#endif
    int state;
    int field24;
    int task;
};
struct Reset021e3158;
struct Outer_02054000;
struct Obj021e8bac;
struct Node021e8bac {
    unsigned char kind;
    unsigned char field1;
    unsigned short id;
    unsigned int field4;
    Node021e8bac* next;
};
#if defined(jpn)
struct CloneWork { unsigned char padding0[0x71c6]; unsigned short source; };
#else
struct CloneWork { unsigned char padding0[0x6fd6]; unsigned short source; };
#endif
struct CloneStats { unsigned char padding0[0x14]; unsigned int flags; };
extern CloneGlobals data_ov025_021ef988;
extern Reset021e3158 data_ov025_021ef9a8;
extern char data_ov025_021ef809[];
extern char data_ov025_021ef791[];
void ResetStruct_021e3158(Reset021e3158*);
void* GetActiveSub_02054000(Outer_02054000*);
extern "C" void func_02072e94(char*, int, int, void*, int);
int SetFlagAndDispatch_021e2628(int, int);
SafeAllocator* GetArrayEntry_021e8a54_021e8a54(char*);
char* GetArrayEntry_021e8a64_021e8a64(char*);
void PushLogNode021e8bac(Obj021e8bac*, Node021e8bac*);
void RestorePairTables0207df90(char*);
void BackupPairTables0207dfac(char*);
void RegisterCombatantSlot_0200fd38(GameState*, int, GameObject*);
CloneWork* GetActiveCombatWork_ov000_02160130();
extern "C" void func_ov017_02191aac(GameResources*, int, int, int);

// USA: func_ov025_021e63b0
extern "C" ARM int func_ov025_021e63b0(void* unused, CloneTargets* targets) {
    GameState* game = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (data_ov025_021ef988.state == 0) {
        if (!targets->head) return 1;
        int id = targets->head->id;
        GameObject* source = GetCombatantWithFlag0x100_0200ff1c(game, id);
        if (!source) {
            ResetStruct_021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        void* model = GetActiveSub_02054000((Outer_02054000*)source);
        if (!model) {
            ResetStruct_021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        char path[0x50];
        func_02072e94(path, id, 8, model, 0);
        char* extension = strrchr(path, '.');
        if (extension) sprintf(extension, data_ov025_021ef809);
        if (!(data_ov025_021ef988.flags & 0x2000)) {
            loader->AddFence();
            data_ov025_021ef988.flags |= 0x2000;
        }
        data_ov025_021ef988.task = SetFlagAndDispatch_021e2628((int)data_ov025_021ef791, (int)path);
        data_ov025_021ef988.state++;
    } else if (data_ov025_021ef988.state == 1) {
        int task = data_ov025_021ef988.task;
        if (!loader->GetTaskStatus(task)) return 0;
        if (loader->GetDetailedTaskStatus(task) != 2) {
            loader->RemoveTask(task);
            ResetStruct_021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        unsigned int size;
        void* file;
        loader->GetLoadedFileByID(task, &file, &size);
        SafeAllocator* allocator = GetArrayEntry_021e8a54_021e8a54(data_ov025_021ef988.context);
        char* tables = GetArrayEntry_021e8a64_021e8a64(data_ov025_021ef988.context);
        Object3D* clone = (Object3D*)allocator->Allocate(sizeof(Object3D));
        if (!clone) {
            loader->RemoveTask(task);
            ResetStruct_021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        Node021e8bac* node = (Node021e8bac*)allocator->Allocate(sizeof(Node021e8bac));
        if (!node) {
            loader->RemoveTask(task);
            ResetStruct_021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        node->kind = 4;
        node->id = 0xc8;
        PushLogNode021e8bac((Obj021e8bac*)data_ov025_021ef988.context, node);
        clone->Initialize();
        RestorePairTables0207df90(tables);
        clone->SetModelFromFileCopy(allocator, file, size, Model3D::TextureStagingMode_Normal);
        BackupPairTables0207dfac(tables);
        RegisterCombatantSlot_0200fd38(game, 0xc8, (GameObject*)clone);
        clone->MakeHidden();
        int sourceId = targets->head->id;
        CloneWork* work = GetActiveCombatWork_ov000_02160130();
        if (work) work->source = sourceId;
        GameObject* source = GetCombatantWithFlag0x100_0200ff1c(game, sourceId);
        if (source) {
            clone->position_ = source->obj3D_.position_;
            clone->rotation_ = source->obj3D_.rotation_;
            clone->SetScale(&source->obj3D_.GetScale());
            clone->unknown_2_ = sourceId;
            if (((CloneStats*)source->currentStats_)->flags & 0x8000000) {
                GameResources* resources = func_ov017_0218b5b0();
                clone->SetAlphaScaleFactor(0);
                func_ov017_02191aac(resources, 1, sourceId, 2);
            }
        }
        loader->RemoveTask(task);
        ResetStruct_021e3158(&data_ov025_021ef9a8);
        return 1;
    }
    return 0;
}
