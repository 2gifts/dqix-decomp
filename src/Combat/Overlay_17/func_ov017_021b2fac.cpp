#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "World/Object3D.h"

struct Task021b2fac {
    char pad0[1];
    unsigned char done;
    char pad2[6];
    short combatantId;
    signed char state;
    unsigned char flagsB;
    char padC[4];
    int taskId;
};

struct Stats021b2fac {
    char pad0[0x56b];
    unsigned char kind : 4;
    unsigned char : 4;
};

struct Alloc021b2fac {
    char pad0[0xcc];
    char tables[1];
};

struct Combatant021b2fac {
    char pad0[4];
    short field4;
    char pad6[0x9c - 6];
    unsigned short field9c;
    char padA0[0x150 - 0x9e];
    struct Stats021b2fac* stats;
    struct Alloc021b2fac* alloc;
    char pad158[0x1c4 - 0x158];
    unsigned char* entry;
};

void ResetEntriesAndNotify_021b33d8(void* p);
extern "C" int func_ov017_021b3444(struct Task021b2fac* t);
extern "C" int func_ov017_021b38c8(struct Task021b2fac* t);
extern "C" void func_02083e28(void* p, int v);
extern "C" int func_ov017_021b3560(struct Task021b2fac* t);
extern "C" void func_ov017_021b3678(struct Task021b2fac* t);
extern "C" int func_ov017_021b3780(struct Task021b2fac* t);
extern "C" int func_ov017_021b3e14(struct Task021b2fac* t);
void CallHelperIfCheckPasses_0218fcf8(int, int, int);
void ResetStruct020d3c08(char* p);
struct HandlerSlotArray020d3c84;
struct StreamHeader;
void InitHandlerArrayAndRunScript020d3c84(HandlerSlotArray020d3c84*, StreamHeader*, int);
struct FindEntryByKindContainer020d3d90;
void* FindEntryByKind(FindEntryByKindContainer020d3d90*, int);
extern "C" void func_ov017_02191508(int id, void* e);
struct Struct_203dafc;
void ClearEightWords_0203dafc(Struct_203dafc*);
void RestorePairTables0207df90(char* p);
void BackupPairTables0207dfac(char* p);
struct Bytes02033b88;
void SetByte0xbeShiftPrev(Bytes02033b88*, int);
void SetFlag0x1ceBit0x4_02039d48(unsigned char*);
extern "C" void func_ov017_02191fec(void* p, int v);

extern char data_ov017_021d7a78[];
extern char data_ov017_021d7a8c[];
extern char data_ov017_021d7a9c[];

// USA: func_ov017_021b2fac
extern "C" ARM void func_ov017_021b2fac(struct Task021b2fac* task) {
    struct Alloc021b2fac* a5;
    void* m;
    void* src;
    BackgroundLoader* loader;
    Combatant021b2fac* c2;
    struct Alloc021b2fac* a0;
    unsigned char* ent;
    GameState* gs;
    void* mgr;
    Combatant021b2fac* c;
    SafeAllocator* alloc4;
    void* e;
    struct Alloc021b2fac* a4;
    int kind;
    void* file4;
    unsigned int size4;
    char handlers[0xb8];
    char name[0x50];
    void* file5;
    unsigned int size5;
    ObjectArchiveLoadInfo info;
    gs = GameState::GetInstance();
    loader = BackgroundLoader::GetInstance();
    mgr = func_ov017_0218b5b0();
    c = (Combatant021b2fac*)GetCombatantWithFlag0x100_0200ff1c(gs, task->combatantId);
    if (c == 0) {
        ResetEntriesAndNotify_021b33d8(task);
        task->done = 1;
        return;
    }
    if (task->state == 0) {
        int has;
        if (c->stats != 0) {
            has = c->stats->kind != 0;
        } else {
            has = 0;
        }
        if (has != 0) {
            ((Object3D*)c)->Destroy();
            a0 = c->alloc;
            ((SafeAllocator*)((char*)a0 + 4))->Reset();
            ((SafeAllocator*)((char*)a0 + 0x18))->Reset();
            task->taskId = loader->QueueLoadFileInGP2(data_ov017_021d7a78, data_ov017_021d7a8c, 0);
            task->state = 4;
        } else if (func_ov017_021b3444(task) != 0) {
            task->state = 1;
        } else if (func_ov017_021b38c8(task) != 0) {
            func_02083e28(c->stats, 0);
            task->state = 3;
        } else {
            task->done = 1;
            return;
        }
        ((Object3D*)c)->EnableFlag(0x200);
        return;
    }
    if (task->state == 1) {
        if (func_ov017_021b3560(task) != 0) {
            task->state = 2;
            func_ov017_021b3678(task);
        }
        return;
    }
    if (task->state == 2) {
        if (func_ov017_021b3780(task) != 0) {
            func_ov017_021b38c8(task);
            task->state = 3;
        }
        return;
    }
    if (task->state == 3) {
        if (func_ov017_021b3e14(task) != 0) {
            c2 = (Combatant021b2fac*)GetCombatantWithFlag0x100_0200ff1c(gs, task->combatantId);
            if (c2->field9c != 0) {
                m = func_ov017_0218b5b0();
                CallHelperIfCheckPasses_0218fcf8((int)m, task->combatantId, c2->field9c);
            }
            ((Object3D*)c2)->DisableFlag(0x200);
            if (task->flagsB & 8) {
                ((Object3D*)c2)->MakeHidden();
                task->flagsB &= ~8;
            }
            task->combatantId = -1;
            task->done = 1;
        }
        return;
    }
    if (task->state == 4) {
        if (loader->GetTaskStatus(task->taskId) != 0) {
            if (loader->GetDetailedTaskStatus(task->taskId) == 2) {
                loader->GetLoadedFileByID(task->taskId, &file4, &size4);
                if (file4 != 0) {
                    ResetStruct020d3c08(handlers);
                    InitHandlerArrayAndRunScript020d3c84((HandlerSlotArray020d3c84*)handlers, (StreamHeader*)file4, size4);
                    kind = c->stats != 0 ? c->stats->kind : 0;
                    src = FindEntryByKind((FindEntryByKindContainer020d3d90*)handlers, kind);
                    e = ((SafeAllocator*)((char*)c->alloc + 0x18))->Allocate(0x24);
                    if (e != 0) {
                        memcpy(e, src, 0x24);
                        c->entry = (unsigned char*)e;
                        func_ov017_02191508(task->combatantId, e);
                    }
                }
            }
            loader->RemoveTask(task->taskId);
            task->taskId = -1;
            ent = c->entry;
            a4 = c->alloc;
            if (ent != 0) {
                sprintf(name, data_ov017_021d7a9c, ent[0x11]);
                task->taskId = loader->QueueLoadFile(name, (SafeAllocator*)((char*)a4 + 4));
            }
            task->state = 5;
        }
        return;
    }
    if (task->state == 5) {
        if (loader->GetTaskStatus(task->taskId) != 0) {
            a5 = c->alloc;
            alloc4 = (SafeAllocator*)((char*)a5 + 4);
            if (loader->GetDetailedTaskStatus(task->taskId) == 2) {
                loader->GetLoadedFileByID(task->taskId, &file5, &size5);
                if (file5 != 0) {
                    ClearEightWords_0203dafc((Struct_203dafc*)&info);
                    info.fileData = file5;
                    info.unk_8 = size5;
                    info.allocator = alloc4;
                    RestorePairTables0207df90(a5->tables);
                    ((Object3D*)c)->LoadFromCCHROrCMOTArchive(&info, 0);
                    BackupPairTables0207dfac(a5->tables);
                }
            }
            ((Object3D*)c)->SetScale(0x10a, 0x10a, 0x10a);
            SetByte0xbeShiftPrev((Bytes02033b88*)c, 0);
            ((Object3D*)c)->DisableFlag(0x200);
            ((Object3D*)c)->SetInheritedAlpha(0);
            SetFlag0x1ceBit0x4_02039d48((unsigned char*)c);
            func_ov017_02191fec(mgr, c->field4);
            loader->RemoveTask(task->taskId);
            task->taskId = -1;
            task->combatantId = -1;
            task->done = 1;
        }
    }
}
