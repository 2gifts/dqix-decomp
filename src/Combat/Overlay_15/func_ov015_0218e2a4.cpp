#include <globaldefs.h>
#include "World/Object3D.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Graphics/NSBXX/Animation.h"

extern "C" void __clear(void*, unsigned long);
struct Foo0207df50;
extern "C" void _Z26CopyInternalFields0207df50P11Foo0207df50(Foo0207df50*);
extern "C" void _Z25RestorePairTables0207df90Pc(char*);
extern "C" void _Z24BackupPairTables0207dfacPc(char*);
struct Struct_203dafc;
void ClearEightWords(Struct_203dafc*);
struct Struct020A2CF0;
struct S020a3568;
Struct020A2CF0* GetFieldIfFlag2(char*);
extern "C" void _Z18ResetState020a2cf0P14Struct020A2CF0(Struct020A2CF0*);
void SetField0x218(S020a3568*, int);
ModelRenderContext* GetModel3DContext(Model3D*);
extern "C" void func_ov015_0218bb3c(RenderCommandHandler*);
extern char data_ov015_02194078[];
extern char data_ov015_02194052[];
extern char data_ov015_0219415c[];
extern char data_ov015_02194160[];
extern char data_ov015_02194167[];
extern Vector3i data_ov015_02193d20;
struct CameraBones { unsigned char third; unsigned char first; unsigned char second; };
extern CameraBones data_ov015_02193fe0;
struct ModelManager { Foo0207df50* palette; };
struct BattleModelLoader {
    int field0;
    ModelManager* manager;
    SafeAllocator* allocator;
    int id;
    char pad10[0xc];
    unsigned char mode;
    char pad1d[7];
    Object3D* object;
    char pad28[0x1c];
    int animationFlags;
};
struct ModelDescription { int id; int archive; };

// USA: func_ov015_0218e2a4
extern "C" ARM int func_ov015_0218e2a4(BattleModelLoader* self, ModelDescription* description) {
    if (!description->archive) return 0;
    char path[0x20];
    __clear(path, 0x20);
    self->allocator->Reset();
    int loaded = 1;
    Foo0207df50* palette = self->manager->palette;
    _Z26CopyInternalFields0207df50P11Foo0207df50(palette);
    _Z25RestorePairTables0207df90Pc((char*)palette);
    if (self->mode == 5) sprintf(path, data_ov015_02194078, description->archive);
    else sprintf(path, data_ov015_02194052, description->archive);
    BackgroundLoader::AddLockGlobal();
    unsigned int length = 0;
    if (!LoadFileIntoMemory(path, data_0211e33c, &length)) loaded = 0;
    else {
        ObjectArchiveLoadInfo info;
        ClearEightWords((Struct_203dafc*)&info);
        SafeAllocator* allocator = self->allocator;
        unsigned int archiveLength = length;
        const void* data = data_0211e33c;
        int one = 1;
        info.allocator = allocator;
        info.fileData = data;
        info.unk_8 = archiveLength;
        info.unk_10 = one;
        self->object->LoadFromCHRArchive(&info);
        Model3D* model = self->object->pModel_;
        data_ov015_02193fe0.first = model->GetBoneIndex(data_ov015_0219415c);
        data_ov015_02193fe0.second = model->GetBoneIndex(data_ov015_02194160);
        data_ov015_02193fe0.third = model->GetBoneIndex(data_ov015_02194167);
        ModelRenderContext* context = GetModel3DContext(model);
        SetModelRenderContextRenderCommandHook(context, func_ov015_0218bb3c, 0, 6, 3);
        context->flags_ |= 4;
        Vector3i scale = data_ov015_02193d20;
        self->object->SetScale(&scale);
        self->object->MaybeSetBCFGAnimation(0, self->animationFlags);
    }
    BackgroundLoader::RemoveLockGlobal();
    _Z24BackupPairTables0207dfacPc((char*)palette);
    if (!loaded) return 0;
    GameState* game = GameState::GetInstance();
    if (!game) return 0;
    Struct020A2CF0* camera = GetFieldIfFlag2((char*)game);
    if (!camera) return 0;
    _Z18ResetState020a2cf0P14Struct020A2CF0(camera);
    SetField0x218((S020a3568*)camera, 0);
    self->id = description->id;
    return 1;
}
