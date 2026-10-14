#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Graphics/Model3D.h"
#include "World/Object3D.h"

struct Foo0207df50;
struct Words021e60c4;
struct Container020dedd0;

void CopyInternalFields0207df50(struct Foo0207df50* state);
void RestorePairTables0207df90(char* state);
void BackupPairTables0207dfac(char* state);
void SetWords_021e60c4_021e60c4(void* object, struct Words021e60c4* rotation);
void CopyAndClampShorts_021e5fdc(void* vocation, short* models, short* appearance);
extern "C" void __clear(void* buffer, unsigned long size);

struct PartyMemberAppearance_021e5020
{
    short models_[10];
    unsigned char female_ : 1;
    unsigned char eyeColor_ : 3;
    unsigned char skinColor_ : 4;
    unsigned char hairColor_ : 4;
    unsigned char unk_15_4 : 4;
    short unk_16;
    short width_;
    short height_;
};

struct PartyMemberData_021e5020
{
    char pad0[0x488];
    PartyMemberAppearance_021e5020 appearance_;
};

struct PartEntry_021e5020
{
    void* model_;
    int unk_4;
    unsigned int category_ : 4;
    unsigned int type_ : 5;
    unsigned int rank_ : 3;
};

PartEntry_021e5020* FindElementByKey020dedd0(struct Container020dedd0* names, int id);

struct VRAMManagerState_021e5020
{
    char data[0x70];
};

struct Rotation_021e5020
{
    int x;
    int y;
    int z;
};

struct CharacterModel_021e5020
{
    Object3D parts_[10];
    SafeAllocator allocators_[10];
    SafeAllocator animationAllocator_;
    VRAMManagerState_021e5020 vramStates_[10];
    short tasks_[12];
    struct Container020dedd0* names_;
    unsigned char holdsWithArms_;
    unsigned char unk_c11;
    unsigned char loading_;
    unsigned char bodyChanged_;
    unsigned char visible_;
    unsigned char vocation_;
    char unk_c16[2];
    PartyMemberData_021e5020* member_;
    short angle_;
    unsigned char colored_;
    char unk_c1f;
};

extern "C" void func_ov023_021e540c(CharacterModel_021e5020* self);
extern "C" void func_ov023_021e5e68(CharacterModel_021e5020* self, int width, int height);

extern "C" const char data_ov023_021fdce0[];
extern "C" const char data_ov023_021fdce9[];

// USA: func_ov023_021e5020
extern "C" ARM void func_ov023_021e5020(CharacterModel_021e5020* self)
{
    void* file;
    unsigned int size;

    if (self->loading_)
    {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        self->loading_ = 0;
        for (int i = 0; i < 10; i++)
        {
            if (self->tasks_[i] > -1)
            {
                if (loader->GetTaskStatus(self->tasks_[i]))
                {
                    self->parts_[i].Destroy();
                    self->allocators_[i].Reset();
                    loader->GetLoadedFileByID(self->tasks_[i], &file, &size);
                    if (size != 0)
                    {
                        CopyInternalFields0207df50((Foo0207df50*)&self->vramStates_[i]);
                        RestorePairTables0207df90((char*)&self->vramStates_[i]);
                        self->parts_[i].SetModelFromFileCopy(&self->allocators_[i], file, size, Model3D::TextureStagingMode_Normal);
                        BackupPairTables0207dfac((char*)&self->vramStates_[i]);
                        if (i == 4 && self->parts_[3].pModel_ != NULL)
                            self->parts_[3].pModel_->ApplyTexturesFromModel(self->parts_[i].pModel_);
                    }
                    loader->RemoveTask(self->tasks_[i]);
                    self->tasks_[i] = -1;
                }
                else
                {
                    self->loading_ = 1;
                }
            }
        }

        short task = self->tasks_[10];
        if (task > -1)
        {
            if (loader->GetTaskStatus(task))
            {
                loader->GetLoadedFileByID(task, &file, &size);
                if (size != 0)
                {
                    loader->GetLoadedFileByID(task, &file, &size);
                    if (size != 0)
                        self->parts_[0].LoadType0AnimationFromFileInMemory(0, &self->animationAllocator_, file, size);
                }
                loader->RemoveTask(task);
                self->tasks_[10] = -1;
            }
            else
            {
                self->loading_ = 1;
            }
        }

        task = self->tasks_[11];
        if (task > -1)
        {
            if (loader->GetTaskStatus(task))
            {
                loader->GetLoadedFileByID(task, &file, &size);
                if (size != 0)
                {
                    loader->GetLoadedFileByID(task, &file, &size);
                    if (size != 0)
                        self->parts_[0].LoadType0AnimationPackageFromBCFGScript(&self->animationAllocator_, file, size);
                }
                loader->RemoveTask(task);
                self->tasks_[11] = -1;
            }
            else
            {
                self->loading_ = 1;
            }
        }

        if (!self->loading_ && !self->colored_)
        {
            func_ov023_021e540c(self);
            self->colored_ = 1;
            self->loading_ = 1;
        }

        if (!self->loading_)
        {
            PartyMemberAppearance_021e5020* appearance = &self->member_->appearance_;
            if (self->bodyChanged_)
            {
                if (appearance->female_ == 1 && self->unk_c11 == 0)
                {
                    if (self->parts_[0].unknown_2_ >= 0)
                    {
                        self->parts_[0].StopCurrentAnimation();
                        self->parts_[0].MaybeSetRegularAnimation(data_ov023_021fdce0, 0);
                    }
                }
                else if (self->parts_[0].unknown_2_ >= 0)
                {
                    self->parts_[0].StopCurrentAnimation();
                    self->parts_[0].MaybeSetRegularAnimation(data_ov023_021fdce9, 0);
                }
                Rotation_021e5020 rotation = {0};
                rotation.y = self->angle_;
                SetWords_021e60c4_021e60c4(&self->parts_[0], (Words021e60c4*)&rotation);
                SetWords_021e60c4_021e60c4(&self->parts_[6], (Words021e60c4*)&rotation);
                SetWords_021e60c4_021e60c4(&self->parts_[1], (Words021e60c4*)&rotation);
                SetWords_021e60c4_021e60c4(&self->parts_[5], (Words021e60c4*)&rotation);
                func_ov023_021e5e68(self, appearance->width_, appearance->height_);
            }

            short models[10];
            CopyAndClampShorts_021e5fdc((void*)self->vocation_, models, (short*)appearance);
            PartEntry_021e5020* entry = FindElementByKey020dedd0(self->names_, models[8]);
            if (entry != NULL && entry->type_ == 6)
                self->holdsWithArms_ = 1;
            else
                self->holdsWithArms_ = 0;
        }
    }
}
