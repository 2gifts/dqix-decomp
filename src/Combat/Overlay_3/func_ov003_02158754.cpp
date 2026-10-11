#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "World/Object3D.h"
#include <globaldefs.h>

extern "C" {
void _Z17CopyState0207dfc8P13State0207dfc8S0_(void *, void *);
void _ZN13SafeAllocator5ResetEv(void *);
void _Z26CopyInternalFields0207df50P11Foo0207df50(void *);
void _Z25RestorePairTables0207df90Pc(void *);
void _Z24BackupPairTables0207dfacPc(void *);
int _Z15GetBitsInField4Pjj(void *, unsigned int);
void _Z19CopyVec3ToField0x44P14Target02059f38P13Vec3_02059f38(void *, void *);
void _Z13SetFields0x44P14Fields020407b4iii(void *, int, int, int);
int _Z17IsIdInSet02098210ii(int, int);
unsigned short *func_02012fe4(void);
}

extern const char data_ov003_0217fdfa[];
extern const char data_ov003_0217fe16[];

struct GO02158754 {
    char pad0[2];
    short f2;
};

struct PM02158754 {
    char pad0[4];
    short f4;
};

struct Ctrl02158754 {
    void *alloc;
    char pad4[0x100 - 4];
    char pad100[0xf7];
    signed char f1f7;
    char pad1f8[0x208 - 0x1f8];
    unsigned char state;
    char pad209[3];
    int task;
    char st210[0x280 - 0x210];
    char obj280[0x32c - 0x280];
    int f32c;
};

// USA: func_ov003_02158754
extern "C" ARM int func_ov003_02158754(struct Ctrl02158754 *self) {
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    if (self->state == 0) {
        loader->AddFence();
        self->task  = loader->QueueLoadFile(data_ov003_0217fdfa, 0);
        self->state = self->state + 1;
    } else if (self->state == 1) {
        if (loader->GetTaskStatus(self->task) == 0) {
            return 0;
        }
        void *file        = 0;
        unsigned int size = 0;
        loader->GetLoadedFileByID(self->task, &file, &size);
        char *res = (char *) func_ov017_0218b5b0();
        _Z17CopyState0207dfc8P13State0207dfc8S0_(res + 0x2cc, self->st210);
        _ZN13SafeAllocator5ResetEv((char *) self->alloc + 0x8c);
        _Z26CopyInternalFields0207df50P11Foo0207df50(self->st210);
        _Z25RestorePairTables0207df90Pc(self->st210);
        Object3D *obj = (Object3D *) self->obj280;
        obj->Initialize();
        ObjectArchiveLoadInfo info;
        info.fileData  = file;
        info.unk_8     = size;
        info.allocator = (SafeAllocator *) ((char *) self->alloc + 0x8c);
        info.unk_10    = 1;
        obj->LoadFromCHRArchive(&info);
        GameState *gs         = GameState::GetInstance();
        Object3D *pm          = (Object3D *) gs->GetPartyMemberByIndex(self->f1f7);
        struct GO02158754 *go = (struct GO02158754 *) gs->GetGameObjectByIndex(self->f1f7 * 0xc + 0x14);
        unsigned short *d     = func_02012fe4();
        unsigned int id       = d[0];
        if (pm->IsVisible() && pm->GetInheritedAlpha() != 0 && id != 10000) {
            if (_Z15GetBitsInField4Pjj(res, 4) == 0 || ((struct PM02158754 *) pm)->f4 == 0) {
                _Z19CopyVec3ToField0x44P14Target02059f38P13Vec3_02059f38(obj, (char *) pm + 0x44);
                const Vector3fix &sc2 = pm->GetScale();
                obj->SetScale(&sc2);
                obj->MaybeSetRegularAnimation(data_ov003_0217fe16, 9);
                obj->EnableFlag(0x40000);
            } else {
                if (go != 0 && _Z17IsIdInSet02098210ii((int) ((char *) d + 0x840), id) != 0) {
                    if (go->f2 == 0x2347 || go->f2 == 0x2348 || go->f2 == 0x2349) {
                        if (go->f2 == 0x2347) {
                            _Z13SetFields0x44P14Fields020407b4iii(obj, 0x2347 - 0x2200, 0x266, -13230);
                        } else if (go->f2 == 0x2348) {
                            _Z13SetFields0x44P14Fields020407b4iii(obj, -7823, 0x266, -13230);
                        } else if (go->f2 == 0x2349) {
                            _Z13SetFields0x44P14Fields020407b4iii(obj, 0x2d70, 0x266, -13230);
                        }
                        const Vector3fix &sc = pm->GetScale();
                        obj->SetScale(&sc);
                        obj->MaybeSetRegularAnimation(data_ov003_0217fe16, 9);
                        obj->EnableFlag(0x40000);
                    }
                }
            }
        } else {
            obj->EnableFlag(1);
        }
        _Z24BackupPairTables0207dfacPc(self->st210);
        self->f32c = 1;
        loader->RemoveTask(self->task);
        self->task  = -1;
        self->state = 0;
        return 1;
    }
    return 0;
}
