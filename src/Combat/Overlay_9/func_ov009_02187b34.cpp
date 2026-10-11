#if defined(jpn)
#define R(j,u) (j)
#define _Z20SetStatValue021855dcPhi func_ov009_021867bc
#define data_ov009_0218aa28 data_ov009_0218ba04
#define data_ov009_0218aa34 data_ov009_0218ba10
#define data_ov009_0218aa98 data_ov009_0218ba4c
#define data_ov009_0218acd9 data_ov009_0218bc3e
#define data_ov009_0218ad41 data_ov009_0218bc71
#define func_ov009_0218a930 func_ov009_0218b908
#define func_ov023_021dac40 func_ov023_021db4b4
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <std_library_functions.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "System/ColorEffects.h"

#define REG_BLDCNT 0x04000050
#define REG_BLDCNT_SUB 0x04001050
#define REG_MASTER_BRIGHT ((short*)0x0400006c)
#define REG_MASTER_BRIGHT_SUB ((short*)0x0400106c)
#define FX32_FROM_FLOAT(x) ((int)((x) > 0.0f ? 0.5f + 4096.0f * (x) : 4096.0f * (x) - 0.5f))

struct PartyMemberAppearance {
    short models_[10];
    unsigned char unk_14[4];
    short width_;
    short height_;
};

struct PartyMemberData {
    char unk_0[0x488];
    PartyMemberAppearance appearance_;
};

struct ModelFile {
    SafeAllocator* allocator_;
    const char* name_;
    unsigned char model_;
};

struct ModelFiles {
    ModelFile files[4];
};

struct Actor0209c678;
struct Container020e0310;
struct Foo0207df50;
struct FlagWord020466f4;

extern "C" Object3D* func_ov023_021e6194(void* character);
GameResources* GetWord0x0(int* gameState);
unsigned int* GetDataPtr02114e04_020d6c00();
extern "C" void func_ov023_021dac40(void* self, unsigned int ticks);
extern "C" int func_ov009_0218a930(void* self, unsigned int ticks);
void CallFunc020a0db8AtField0x16c(char* camera, int position, int duration);
void CallFunc020a0db8AtField0x194AndClearFlag2(char* camera, int target, int duration);
void DispatchContextByState0209c678(Actor0209c678* actor, int state);
int AnySubObjectField0NonZero(char* camera);
void SetForwardAndStore0205ebc0(void* sound, int a, int b);
const char* GetFieldByKey020e0434(Container020e0310* texts, int id);
void CopyInternalFields0207df50(Foo0207df50* a);
void RestorePairTables0207df90(char* a);
void BackupPairTables0207dfac(char* a);
void DispatchIfField0xc4NonNeg_0205ebfc(void* sound, int a, int b);
void OrBitsIntoField0(unsigned int* field, unsigned int bits);
void ClearFlags020466f4(FlagWord020466f4* field, unsigned int bits);
void EncodeSignFlaggedHalfword(short* reg, int brightness);
void ForwardField0xc0_0205ebec(void* sound);
#if defined(jpn)
#define SetStatValue021855dc func_ov009_021867bc
extern "C" void SetStatValue021855dc(unsigned char* self, int state);
#else
void SetStatValue021855dc(unsigned char* self, int state);
#endif

struct Vec3 {
    int x;
    int y;
    int z;
};

extern const Vec3 data_ov009_0218aa28;
extern const Vec3 data_ov009_0218aa34;
extern const ModelFiles data_ov009_0218aa98;
extern char data_ov009_0218acd9[];
extern char data_ov009_0218ad41[];
extern char data_02109bf4[];
extern char data_02108760[];

struct CharacterCreation {
    char unk_0[R(0xa0,0xb4)];
    SafeAllocator* modelAllocator_;
    SafeAllocator* previewAllocators_;
    char unk_bc[R(0xc0-0xa8,0xe0-0xbc)];
    char texts_[0x18];
    char unk_f8[R(0x7bc-0xd8,0x7f8-0xf8)];
    void* character_;
    void* nextCharacter_;
    int unk_800;
    int targetAngle_;
    char unk_808[0x70];
    Object3D object_;
    char camera_[0x2c8];
    char unk_bec[0xc58 - 0xbec];
    signed char state_;
    unsigned char step_;
    char unk_c5a[2];
    int modelTasks_[3];
    char unk_c68[0x70];
    Object3D object2_;
    unsigned char selection_;
    unsigned char unk_d85;
    char unk_d86[2];
    PartyMemberData* member_;
    char unk_d8c[0xd96 - 0xd8c];
    short timer_;
    short unk_d98;
    char unk_d9a[2];
    unsigned int flags_;
    signed char lastStates_[2];
    unsigned char vocation_;
    unsigned char sex_;
};

// USA: func_ov009_02187b34
extern "C" ARM void func_ov009_02187b34(CharacterCreation* self)
{
    GameState* gameState = GameState::GetInstance();
    GameResources* resources = GetWord0x0((int*)gameState);
    Object3D* preview = func_ov023_021e6194(self->character_);
    unsigned int* unknown = GetDataPtr02114e04_020d6c00();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (loader == NULL)
        return;
    unsigned int ticks = gameState->GetTickCount();
    if (ticks == 0)
        ticks = 1;
    func_ov023_021dac40(self, ticks);
    if (func_ov009_0218a930(self, ticks) > 0)
        return;

    switch (self->step_)
    {
    case 0:
    {
        self->flags_ &= ~1;
        self->targetAngle_ = 0x7a;
        self->flags_ |= 8;
        Vec3 position = data_ov009_0218aa28;
        Vec3 target = data_ov009_0218aa34;
        CallFunc020a0db8AtField0x16c(self->camera_, (int)&position, 0x1e000);
        CallFunc020a0db8AtField0x194AndClearFlag2(self->camera_, (int)&target, 0x1e000);
        self->unk_d98 = 90;
        self->flags_ |= 0x10000;
        DispatchContextByState0209c678((Actor0209c678*)data_02109bf4, 120);
        self->step_ = 1;
        int* task = self->modelTasks_;
        for (unsigned char i = 0; i < 3; i++)
            *task++ = -1;
        SafeAllocator* allocator = self->previewAllocators_;
        for (unsigned char i = 0; i < 2; i++, allocator++)
            allocator->Reset();
        break;
    }
    case 1:
        if (self->flags_ & 8)
            break;
        if (AnySubObjectField0NonZero(self->camera_) != 0)
            break;
        self->flags_ |= 0x800000;
        if (func_ov023_021e6194(self->character_)->normalizedAnimationTime_ >= 0xccc)
        {
            SetForwardAndStore0205ebc0(data_02108760, 0x6f, 0x6f);
            self->step_ = 2;
        }
        break;
    case 2:
    {
        short bodyID = self->sex_ * 100 + 2001;
        short headID = self->sex_ * 100 + 2002;
        ModelFiles files = data_ov009_0218aa98;
        files.files[0].allocator_ = self->previewAllocators_;
        files.files[0].name_ = GetFieldByKey020e0434((Container020e0310*)self->texts_, headID);
        files.files[1].allocator_ = &self->previewAllocators_[1];
        files.files[1].name_ = GetFieldByKey020e0434((Container020e0310*)self->texts_, bodyID);
        files.files[2].allocator_ = self->modelAllocator_;
        files.files[2].name_ = GetFieldByKey020e0434((Container020e0310*)self->texts_, 0x898);
        ModelFile* file = files.files;
        const char* archive = data_ov009_0218acd9;
        for (; file->allocator_ != NULL; file++)
        {
            int task;
            if (file->model_ == 2)
                task = loader->QueueLoadFile(file->name_, file->allocator_);
            else
                task = loader->QueueLoadFileInGP2(archive, file->name_, file->allocator_);
            self->modelTasks_[file->model_] = task;
        }
        self->step_ = 3;
        break;
    }
    case 3:
    {
        int done = 1;
        int* task = self->modelTasks_;
        for (unsigned char i = 0; i < 3; i++, task++)
        {
            if (*task != -1 && loader->GetTaskStatus(*task) == 0)
                done = 0;
        }
        if (done)
            self->step_ = 4;
        break;
    }
    case 4:
    {
        int* task = self->modelTasks_;
        for (unsigned char i = 0; i < 3; i++, task++)
        {
            if (*task == -1)
                continue;
            if (loader->GetTaskStatus(*task) == 1)
            {
                unsigned int size = 0;
                void* file = NULL;
                loader->GetLoadedFileByID(*task, &file, &size);
                ObjectArchiveLoadInfo info;
                info.unk_0 = 0;
                info.allocator = NULL;
                info.unk_14 = 0;
                info.unk_18 = 0;
                info.unk_10 = 0;
                info.packageID = 0;
                info.fileData = file;
                info.unk_8 = size;
                switch (i)
                {
                case 0:
                    info.allocator = self->previewAllocators_;
                    info.packageID = 1;
                    preview->LoadFromCHRArchive(&info);
                    break;
                case 1:
                    info.allocator = &self->previewAllocators_[1];
                    self->object_.LoadFromCHRArchive(&info);
                    break;
                case 2:
                    info.allocator = self->modelAllocator_;
                    CopyInternalFields0207df50((Foo0207df50*)self->unk_c68);
                    RestorePairTables0207df90(self->unk_c68);
                    self->object2_.LoadFromCHRArchive(&info);
                    BackupPairTables0207dfac(self->unk_c68);
                    break;
                }
            }
            loader->RemoveTask(*task);
            *task = -1;
        }
        self->step_ = 5;
        preview->StopCurrentAnimation();
        preview->MaybeSetRegularAnimation(GetFieldByKey020e0434((Container020e0310*)self->texts_, 2500), 0);
        Vector3fix rotation;
        memset(&rotation, 0, sizeof(rotation));
        rotation = preview->rotation_;
        PartyMemberAppearance* appearance = &self->member_->appearance_;
        int scaleX;
        int scaleY;
        short width = appearance->width_;
        scaleX = FX32_FROM_FLOAT(width / 4096.0f);
        scaleY = FX32_FROM_FLOAT(appearance->height_ / 4096.0f);
        int scaleZ = FX32_FROM_FLOAT(width / 4096.0f);
#if defined(jpn)
        self->object_.SetScale(scaleX, scaleY, scaleZ);
        self->object_.rotation_ = rotation;
        self->object_.StopCurrentAnimation();
        self->object_.MaybeSetRegularAnimation(GetFieldByKey020e0434((Container020e0310*)self->texts_, 2500), 0);
        Vector3fix position;
        position = ((Object3D*)((char*)preview + 0x408))->position_;
        self->object2_.rotation_ = rotation;
        self->object2_.position_ = position;
        self->object2_.StopCurrentAnimation();
        self->object2_.MaybeSetRegularAnimation(data_ov009_0218ad41, 0);
#else
        Object3D* object = &self->object_;
        object->SetScale(scaleX, scaleY, scaleZ);
        object->rotation_ = rotation;
        object->StopCurrentAnimation();
        object->MaybeSetRegularAnimation(GetFieldByKey020e0434((Container020e0310*)self->texts_, 2500), 0);
        Vector3fix position;
        position = ((Object3D*)((char*)preview + 0x408))->position_;
        Object3D* object2 = &self->object2_;
        object2->rotation_ = rotation;
        object2->position_ = position;
        object2->StopCurrentAnimation();
        object2->MaybeSetRegularAnimation(data_ov009_0218ad41, 0);
#endif
        self->flags_ |= 0x200;
        self->timer_ = 30;
        self->step_ = 6;
        break;
    }
    case 6:
        DispatchIfField0xc4NonNeg_0205ebfc(data_02108760, 0, 0);
        self->timer_ = 150;
        self->step_ = 7;
        break;
    case 7:
        OrBitsIntoField0(unknown, 0x100);
        SetBrightness(resources, 16, 40);
        DispatchIfField0xc4NonNeg_0205ebfc(data_02108760, 1, 0);
        self->step_ = 8;
        break;
    case 8:
        if (IsBrightnessTransitionActive(resources))
            break;
        ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT, 0x1f, -16);
        ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT_SUB, 0x1f, -16);
        self->timer_ = 120;
        self->step_ = 9;
        break;
    case 9:
        if (self->timer_ > 0)
        {
            unsigned int elapsed = gameState->GetTickCount();
            if (elapsed == 0)
                elapsed = 1;
            self->timer_ -= elapsed;
            break;
        }
        SetBrightness(resources, -16, 120);
        self->step_ = 10;
        break;
    case 10:
        if (IsBrightnessTransitionActive(resources))
            break;
        EncodeSignFlaggedHalfword(REG_MASTER_BRIGHT, -16);
        EncodeSignFlaggedHalfword(REG_MASTER_BRIGHT_SUB, -16);
        ClearFlags020466f4((FlagWord020466f4*)unknown, 0x100);
        ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT, 0x1f, 0);
        ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT_SUB, 0x1f, 0);
        ForwardField0xc0_0205ebec(data_02108760);
        self->step_ = 11;
        break;
    case 11:
        self->step_ = 0xff;
        SetStatValue021855dc((unsigned char*)self, 11);
        break;
    }
}
