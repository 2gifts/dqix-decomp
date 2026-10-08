#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"

struct Container020e0310;
struct Struct0205a198;
struct ActiveEntry02046900;
struct Rec020467f0;

struct Sprite
{
    char unk_0[0x28];
};

struct SpriteRenderer
{
    char unk_0[0x3c];
    void* animations_;
    Sprite* sprites_;
    char unk_44[4];
    unsigned int unk_48;
    short numSprites_;
    unsigned short capacity_;
    unsigned char unk_50;
    char unk_51[3];

    void SetSprites(Sprite* sprites, short numSprites)
    {
        sprites_ = sprites;
        numSprites_ = numSprites;
    }
};

extern "C" const char* _Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310* texts, int id);
extern "C" void _Z18InitStruct0205a444Pc(char* renderer);
extern "C" void _Z12Init0205a198P14Struct0205a198(Struct0205a198* sprite);
int CountActiveEntries(ActiveEntry02046900* archive);
void* FindRecordByIndex(Rec020467f0* archive, int index, void** name, int* size);
extern "C" void func_0205a528(SpriteRenderer* renderer, void* file, unsigned int size, SafeAllocator* allocator);

struct BattleRecords
{
    char unk_0[0x50];
    SafeAllocator iconAllocator_;
    char unk_64[0xa0 - 0x50 - sizeof(SafeAllocator)];
    char texts_[0x18];
    char unk_b8[0x73c - 0xb8];
    SpriteRenderer* iconRenderer_;
    Sprite* iconSprite_;
    char unk_744[0xb12 - 0x744];
    unsigned char loadStep_;
    char unk_b13[0xb20 - 0xb13];
    int task_;
};

// USA: func_ov008_02188d74
extern "C" ARM int func_ov008_02188d74(BattleRecords* self)
{
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    unsigned char step = self->loadStep_;
    if (step == 0)
    {
        self->iconRenderer_ = NULL;
        self->iconSprite_ = NULL;
        self->iconAllocator_.Reset();
        self->iconRenderer_ = (SpriteRenderer*)self->iconAllocator_.Allocate(sizeof(SpriteRenderer));
        self->iconSprite_ = (Sprite*)self->iconAllocator_.Allocate(sizeof(Sprite));
        _Z18InitStruct0205a444Pc((char*)self->iconRenderer_);
        self->iconRenderer_->unk_50 = 1;
        SpriteRenderer* renderer = self->iconRenderer_;
        renderer->SetSprites(self->iconSprite_, 1);
        for (int i = 0; i < 1; i++)
            _Z12Init0205a198P14Struct0205a198((Struct0205a198*)&self->iconSprite_[i]);
        self->task_ = loader->QueueLoadFile(_Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)&self->texts_, 7), NULL);
        self->loadStep_++;
    }
    if (step == 1 && loader->GetTaskStatus(self->task_))
    {
        char name[4];
        void* archive;
        unsigned int archiveSize;
        loader->GetLoadedFileByID(self->task_, &archive, &archiveSize);
        int count = CountActiveEntries((ActiveEntry02046900*)archive);
        for (int i = 0; i < count; i++)
        {
            unsigned int size;
            void* file = FindRecordByIndex((Rec020467f0*)archive, i, (void**)name, (int*)&size);
            if (file != NULL)
                func_0205a528(self->iconRenderer_, file, size, &self->iconAllocator_);
        }
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        self->loadStep_ = 0;
        return 1;
    }
    return 0;
}
