#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct BattleNode021eb46c {
    char pad0[0x20];
    unsigned short combatantId;
};

struct Slot021eb46c {
    char pad0[8];
    unsigned char kind;
};

struct Appearance021eb46c {
    char pad0[0x56b];
    unsigned char look : 4;
};

struct Combatant021eb46c {
#if defined(jpn)
    char pad0[0x144];
#else
    char pad0[0x150];
#endif
    Appearance021eb46c* appearance;
};

struct LogNode021eb46c {
    unsigned char type;
    unsigned char field1;
    unsigned short combatantId;
    unsigned short packageID;
    char pad6[2];
    LogNode021eb46c* next;
};

struct Ctx021eb46c {
    char pad0[0x10];
    SafeAllocator* allocators[8];
    unsigned char allocatorIndex;
    char pad31[0x1c4 - 0x31];
    unsigned int flags;
    int state;
    int taskID;
    int unk1d0;
    int unk1d4;
    LogNode021eb46c* logHead;
};

void* GetActiveCombatWork(void);
extern "C" void* _Z18GetSlotPtr02160f20Pv(void* obj);
extern "C" void _Z25FormatEffectStats02072c9ciPc(int id, char* out);
extern "C" BattleNode021eb46c* _Z22GetNodeAtIndex02160094P12List02160094i(void* list, int index);
extern "C" void _Z19PushLogNode021e8bacP11Obj021e8bacP12Node021e8bac(Ctx021eb46c* ctx, LogNode021eb46c* node);

extern char data_ov025_021ef8fc[];
extern char data_ov025_021ef916[];
extern char data_ov025_021ef91f[];
extern Ctx021eb46c* data_ov025_021ef994;

// JPN: func_ov025_021eb8f4
// USA: func_ov025_021eb46c
extern "C" ARM int func_ov025_021eb46c(Ctx021eb46c* ctx) {
    char stats[20];
    char path[20];
    ObjectArchiveLoadInfo info;
    void* fileData;
    unsigned int fileLength;

    if (ctx->flags & 2) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        int loadedId;
        SafeAllocator* alloc = ctx->allocators[ctx->allocatorIndex];

        if (ctx->state == 0) {
            Slot021eb46c* slot = (Slot021eb46c*)_Z18GetSlotPtr02160f20Pv(GetActiveCombatWork());
            ctx->taskID = -1;
            if (slot->kind == 1 && _Z22GetNodeAtIndex02160094P12List02160094i(slot, 0) != NULL) {
                int id = _Z22GetNodeAtIndex02160094P12List02160094i(slot, 0)->combatantId;
                Combatant021eb46c* c = (Combatant021eb46c*)GetCombatantWithFlag0x100(GameState::GetInstance(), id);
                bool isParty;
                if (id >= 0 && id <= 3) {
                    isParty = true;
                } else {
                    isParty = false;
                }
                if (isParty && c != NULL) {
                    int look = c->appearance != NULL ? c->appearance->look : 0;
                    if (look == 1) {
                        sprintf(path, data_ov025_021ef8fc);
                        ctx->taskID = loader->QueueLoadFile(path, alloc);
                    } else {
                        _Z25FormatEffectStats02072c9ciPc(id, stats);
                        sprintf(path, data_ov025_021ef916, stats);
                        ctx->taskID = loader->QueueLoadFileInGP2(data_ov025_021ef91f, path, alloc);
                    }
                }
            }
            if (ctx->taskID < 0) {
                ctx->flags &= ~2;
                return 0;
            }
            ctx->state++;
        } else if (loader->GetTaskStatus(ctx->taskID) != 0) {
            loader->GetLoadedFileByID(ctx->taskID, &fileData, &fileLength);
            if (fileData != NULL) {
                void* slot = _Z18GetSlotPtr02160f20Pv(GetActiveCombatWork());
                if (_Z22GetNodeAtIndex02160094P12List02160094i(slot, 0) != NULL) {
                    loadedId = _Z22GetNodeAtIndex02160094P12List02160094i(slot, 0)->combatantId;
                    GameObject* c = GetCombatantWithFlag0x100(GameState::GetInstance(), loadedId);
                    if (c != NULL) {
                        LogNode021eb46c* node = (LogNode021eb46c*)alloc->Allocate(sizeof(LogNode021eb46c));
                        if (node != NULL) {
                            info.unk_0 = 0;
                            info.fileData = fileData;
                            info.unk_8 = fileLength;
                            info.unk_10 = 0;
                            info.unk_14 = 0;
                            info.unk_18 = 0;
                            info.packageID = 0;
                            info.allocator = alloc;
                            info.packageID = data_ov025_021ef994->allocatorIndex + 4;
                            c->obj3D_.LoadFromCCHROrCMOTArchive(&info, NULL);
                            node->type = 0;
                            node->combatantId = loadedId;
                            node->packageID = info.packageID;
                            _Z19PushLogNode021e8bacP11Obj021e8bacP12Node021e8bac(ctx, node);
                        }
                    }
                }
            }
            loader->RemoveTask(ctx->taskID);
            memset(&ctx->state, 0, 0x10);
            ctx->flags &= ~2;
            return 0;
        }
        return 1;
    }
    return 0;
}
