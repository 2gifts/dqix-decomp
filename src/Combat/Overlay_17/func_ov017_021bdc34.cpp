#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

struct Foo0207df50 { unsigned char fields[0x70]; };
struct S021a11b4;
struct LoadEntry021bdc34 {
    unsigned char padding_0[4];
    SafeAllocator primary;
    unsigned char padding_18[0xcc - 0x18];
    Foo0207df50 primary_pairs;
    unsigned char padding_13c[0x1ac - 0x13c];
    Foo0207df50 secondary_pairs;
    unsigned char padding_21c[0x52c - 0x21c];
    SafeAllocator secondary;
};
struct LoadGlobals021bdc34 {
    unsigned char padding_0[0x4334];
    Object3D* first;
    Object3D* second;
    Object3D* third;
    Object3D* fourth;
};
struct LoadActor021bdc34 {
    Object3D object;
    unsigned char padding_ac[0x18c - 0xac];
    unsigned int flags;
};
struct LoadState021bdc34 {
    unsigned char tag;
    unsigned char done;
    unsigned char padding_2[6];
    short tasks[4];
    unsigned char stage;
    unsigned char mode;
};
extern "C" LoadEntry021bdc34* _Z26FindNegativeEntry_021a11b4P9S021a11b4(S021a11b4*);
extern "C" void _Z26CopyInternalFields0207df50P11Foo0207df50(Foo0207df50*);
extern "C" void _Z25RestorePairTables0207df90Pc(char*);
extern "C" void _Z24BackupPairTables0207dfacPc(char*);
extern "C" void _Z36SetFieldndDispatch_021bdb78_021bdb78i(int);
extern "C" void _Z32CallHelperIfCheckPasses_0218fcf8iii(int, int, int);
extern "C" void func_ov017_0218f5a4(void*, int, int, int, int);
extern const char data_ov017_021d7e14[], data_ov017_021d7e2e[], data_ov017_021d7e46[];
extern const char data_ov017_021d7e61[], data_ov017_021d7e6c[], data_ov017_021d7e75[], data_ov017_021d7e7b[];

// USA: func_ov017_021bdc34
extern "C" ARM void func_ov017_021bdc34(LoadState021bdc34* self) {
    GameState* game = GameState::GetInstance();
    LoadGlobals021bdc34* globals = (LoadGlobals021bdc34*)func_ov017_0218b5b0();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    LoadActor021bdc34* actor = (LoadActor021bdc34*)GetCombatantWithFlag0x100(game, 0);
    if (actor == 0) return;
    LoadEntry021bdc34* entry = _Z26FindNegativeEntry_021a11b4P9S021a11b4((S021a11b4*)globals);
    if (entry == 0) {
        self->done = 1;
        return;
    }
    SafeAllocator* allocators[4] = {&entry->primary, &entry->primary, &entry->secondary, &entry->primary};
    Foo0207df50* pairs[4] = {&entry->primary_pairs, &entry->primary_pairs, &entry->secondary_pairs, &entry->primary_pairs};
    if (self->stage == 0) {
        if (self->mode == 1 && globals->first != 0 && globals->second != 0) {
            if (actor->flags & 0x40) { self->done = 1; return; }
        }
        if (self->mode == 2 && globals->first != 0 && globals->second != 0) {
            if (!(actor->flags & 0x40)) { self->done = 1; return; }
        }
        if (self->mode == 0 && globals->first == 0 && globals->second == 0) {
            if (!(actor->flags & 0x40)) { self->done = 1; return; }
        }
        if (self->mode == 1 || self->mode == 2) {
            if (globals->first == 0) {
                self->tasks[0] = loader->QueueLoadFile(data_ov017_021d7e14, 0);
                self->tasks[1] = loader->QueueLoadFile(data_ov017_021d7e2e, 0);
                self->tasks[2] = loader->QueueLoadFileInGP2(data_ov017_021d7e46, data_ov017_021d7e61, 0);
                self->tasks[3] = loader->QueueLoadFileInGP2(data_ov017_021d7e46, data_ov017_021d7e6c, 0);
                for (int i = 0; i < 4; i++) {
                    allocators[i]->Reset();
                    _Z26CopyInternalFields0207df50P11Foo0207df50(pairs[i]);
                }
            } else {
                for (int i = 0; i < 4; i++) self->tasks[i] = -1;
            }
            if (self->mode == 1) actor->flags |= 0x40;
            else actor->flags &= ~0x40;
            func_ov017_0218f5a4(globals, 0, 1, 0, 0);
            self->stage = 1;
        } else {
            globals->first = 0;
            globals->second = 0;
            globals->third = 0;
            globals->fourth = 0;
            if (actor != 0) actor->flags &= ~0x40;
            func_ov017_0218f5a4(globals, 0, 1, 0, 0);
            self->stage = 2;
        }
    } else if (self->stage == 1) {
        int pending = 0;
        for (int i = 0; i < 4; i++) {
            if (self->tasks[i] < 0) continue;
            if (loader->GetTaskStatus(self->tasks[i]) != 0 && loader->GetDetailedTaskStatus(self->tasks[i]) == 2) {
                void* file;
                unsigned int length;
                loader->GetLoadedFileByID(self->tasks[i], &file, &length);
                SafeAllocator* allocator = allocators[i];
                Object3D* object = (Object3D*)allocator->Allocate(0xac);
                if (file != 0 && object != 0) {
                    ObjectArchiveLoadInfo info;
                    info.fileData = file;
                    info.unk_0 = 0;
                    info.unk_14 = 0;
                    info.unk_18 = 0;
                    info.packageID = 0;
                    info.unk_10 = 1;
                    info.allocator = allocator;
                    info.unk_8 = length;
                    Foo0207df50* pair = pairs[i];
                    _Z25RestorePairTables0207df90Pc((char*)pair);
                    object->Initialize();
                    object->LoadFromCCHROrCMOTArchive(&info, 0);
                    _Z24BackupPairTables0207dfacPc((char*)pair);
                    switch (i) {
                    case 0: globals->first = object; break;
                    case 1: globals->second = object; break;
                    case 2: globals->third = object; break;
                    case 3: globals->fourth = object; break;
                    }
                }
                loader->RemoveTask(self->tasks[i]);
                self->tasks[i] = -1;
            } else pending = 1;
        }
        if (!pending) self->stage = 2;
    } else if (self->stage == 2) {
        if (self->mode == 1) _Z36SetFieldndDispatch_021bdb78_021bdb78i(0);
        else {
            actor->object.unknown_9c_ = 0;
            _Z32CallHelperIfCheckPasses_0218fcf8iii((int)globals, 0, 0);
        }
        if (globals->first != 0) {
            if (self->mode == 1) globals->first->MaybeSetRegularAnimation(data_ov017_021d7e75, 0);
            else globals->first->MaybeSetRegularAnimation(data_ov017_021d7e7b, 0);
        }
        self->done = 1;
    }
}
