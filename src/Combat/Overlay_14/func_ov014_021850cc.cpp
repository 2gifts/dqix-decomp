#include <globaldefs.h>
#include <std_library_functions.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "World/Object3D.h"

struct MonsterListEntry {
    MonsterListEntry* next_;
    const char* modelName_;
    const char* name_;
    short monsterID_;
    char unk_e[4];
    signed char familyTextID_;
    unsigned char unk_13_0_ : 1;
    unsigned char known_ : 1;
    unsigned char unk_13_2_ : 6;
    char unk_14[6];
    short number_;
    char unk_1c[4];
};

struct MonsterRecord {
    unsigned int defeatCount_ : 10;
    unsigned int complete_ : 1;
    unsigned int dropCount0_ : 7;
    unsigned int dropCount1_ : 7;
    unsigned int unk_0_25_ : 7;
};

struct MonsterInfo {
    char unk_0[8];
    short dropItemIDs_[2];
    unsigned char numAnimations_;
    char unk_d[3];
    float position_[3];
    float rotationY_;
    float scale_[3];
    const char** animations_;
};

struct MonsterRecordCount {
    unsigned int value_;
    char unk_4[2];
    unsigned short count_;
};

struct MonsterInfoTable {
    char unk_0[0x10];
};

struct MonsterBest {
    unsigned int value_;
    short monsterID_;
    unsigned short count_;
};

struct HabitatTable {
    char unk_0[0x20];
};

struct GameResources {
    char unk_0[0x2cc];
    char unknown_2cc[0xe70];
};

struct MonsterInfoScreen {
    void** buffers_;
    void* spriteRenderer_;
    void* sprites_;
    MonsterInfoTable infos_;
    HabitatTable habitats_;
    SafeAllocator* allocators_;
    Object3D* model_;
    void* camera_;
    MonsterListEntry* monster_;
    MonsterListEntry* prevMonster_;
    MonsterRecord* record_;
    MonsterRecord* prevRecord_;
    void* layout_;
    void* texts_;
    char* dropNames_[2];
    char* description_;
    int taskID_;
    int backgroundTaskID_;
    int animationIndex_;
    int unk_78;
    unsigned char state_;
    unsigned char initStep_;
    unsigned char backgroundStep_;
    unsigned char loadStep_;
    unsigned char page_;
    unsigned char flags_;
    unsigned char rotating_ : 1;
    unsigned char unk_82_1_ : 1;
    unsigned char loadModel_ : 1;
    unsigned char unk_82_3_ : 1;
    unsigned char unk_82_4_ : 4;
    short unk_84;
    short taskIDs_[5];
    unsigned char buttonPressed_[3];
    unsigned char unk_93;
    unsigned char unk_94;
    short* variants_;
    MonsterBest best_;
};

struct ResetFieldsStruct021845d4;
struct HandleField8_02097238;
struct BinarySearch020971a8Container;
struct Struct020dfc40;
struct Foo0207df50;
struct Struct_203dafc;

extern char data_ov014_021895d5[];
extern char data_ov014_021895ed[];
extern char data_ov014_02189603[];
extern char data_ov014_02189615[];
extern char data_ov014_0218962c[];
extern char data_ov014_0218963f[];
extern char data_ov014_02189652[];
extern char data_ov014_02189661[];
extern char data_ov014_02189668[];
extern char data_ov014_02189680[];
extern char data_ov014_02189686[];
extern char data_ov014_0218968c[];

extern "C" bool func_ov014_02188bfc(HabitatTable* habitats, SafeAllocator* allocator, short monsterID);
extern "C" bool func_ov014_02188c34(HabitatTable* habitats);
void ResetFields_021845d4(ResetFieldsStruct021845d4* best);
void Clear0x10Bytes02096fb0(void* table);
extern "C" void func_02097054(MonsterInfoTable* table, SafeAllocator* allocator, void* file, unsigned int size, short monsterID);
MonsterRecordCount* GetHandleField8(HandleField8_02097238* table);
MonsterInfo* BinarySearchByField4_02097224(BinarySearch020971a8Container* table, int monsterID);
void Zero4Bytes(void* reader);
void TryInvoke020e53bc(void* reader, int file, int size);
const char** CallFunc020e52a0(void* reader, int id);
extern "C" void func_020e4864(const char* input, char* output, int, int, int, int);
void* ResetAndReturnSelf020dfc2c(void* text);
void ResetStruct020dfc40(Struct020dfc40* text);
extern "C" void func_020e046c(char* output, void* file, unsigned int size, short infoID);
extern "C" GameResources* func_ov017_0218b5b0();
void CopyInternalFields0207df50(Foo0207df50* p);
void RestorePairTables0207df90(char* p);
void BackupPairTables0207dfac(char* p);
void ClearEightWords(Struct_203dafc* info);
void ComputeAndStoreVecs02184c08(unsigned char* screen);

// USA: func_ov014_021850cc
extern "C" ARM void func_ov014_021850cc(MonsterInfoScreen* self) {
    if (!(self->flags_ & 1))
        return;

    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->loadStep_ == 0) {
        char archive[0x40] = {};
        char file[0x40] = {};
        if (self->loadModel_)
            self->taskIDs_[0] = loader->QueueLoadFile(data_ov014_021895d5, NULL);
        self->allocators_[1].Reset();
        func_ov014_02188bfc(&self->habitats_, &self->allocators_[1], self->monster_->number_);
        self->taskIDs_[1] = loader->QueueLoadFileInGP2(data_ov014_021895ed, data_ov014_02189603, NULL);
        sprintf(archive, data_ov014_02189615, self->page_ + 1);
        sprintf(file, data_ov014_0218962c, self->page_ + 1);
        self->taskIDs_[2] = loader->QueueLoadFileInGP2(archive, file, NULL);
        self->taskIDs_[3] = loader->QueueLoadFileInGP2(data_ov014_0218963f, data_ov014_02189652, NULL);
        if (self->loadModel_ && self->monster_ != NULL && self->record_ != NULL && self->monster_->known_ && self->monster_->modelName_ != NULL) {
            sprintf(file, data_ov014_02189661, self->monster_->modelName_);
            self->taskIDs_[4] = loader->QueueLoadFileInGP2(data_ov014_02189668, file, NULL);
        }
        self->loadStep_++;
    } else if (self->loadStep_ == 1) {
        if (self->loadModel_) {
            if (loader->GetTaskStatus(self->taskIDs_[0])) {
                void* file;
                unsigned int size;
                loader->GetLoadedFileByID(self->taskIDs_[0], &file, &size);
                if (file != NULL) {
                    short* variant = self->variants_;
                    ResetFields_021845d4((ResetFieldsStruct021845d4*)&self->best_);
                    SafeAllocator* allocator = &self->allocators_[0];
                    for (; *variant != 0; variant++) {
                        allocator->Reset();
                        short monsterID = *variant;
                        Clear0x10Bytes02096fb0(&self->infos_);
                        func_02097054(&self->infos_, allocator, file, size, monsterID);
                        MonsterRecordCount* count = GetHandleField8((HandleField8_02097238*)&self->infos_);
                        if (self->best_.monsterID_ < 0
                            || (count != NULL && (count->value_ > self->best_.value_ || count->count_ > self->best_.count_))) {
                            self->best_.monsterID_ = monsterID;
                            self->best_.value_ = count->value_;
                            self->best_.count_ = count->count_;
                        }
                    }
                    allocator->Reset();
                    short monsterID = self->monster_->monsterID_;
                    Clear0x10Bytes02096fb0(&self->infos_);
                    func_02097054(&self->infos_, allocator, file, size, monsterID);
                    GetHandleField8((HandleField8_02097238*)&self->infos_);
                }
                loader->RemoveTask(self->taskIDs_[0]);
                self->taskIDs_[0] = -1;
                self->loadStep_++;
            }
        } else {
            self->loadStep_++;
        }
    }

    if (self->loadStep_ == 2) {
        if (func_ov014_02188c34(&self->habitats_))
            self->loadStep_++;
    }

    if (self->loadStep_ == 3 && loader->GetTaskStatus(self->taskIDs_[1])) {
        void* file;
        unsigned int size;
        loader->GetLoadedFileByID(self->taskIDs_[1], &file, &size);
        if (file != NULL) {
            MonsterInfo* info = BinarySearchByField4_02097224((BinarySearch020971a8Container*)&self->infos_, self->monster_->monsterID_);
            if (info != NULL) {
                char reader[0xc];
                Zero4Bytes(reader);
                TryInvoke020e53bc(reader, (int)file, size);
                const char** name = CallFunc020e52a0(reader, info->dropItemIDs_[0]);
                if (name != NULL) {
                    memset(self->dropNames_[0], 0, 0x48);
                    func_020e4864(*name, self->dropNames_[0], 1, 0, 0, 0);
                }
                name = CallFunc020e52a0(reader, info->dropItemIDs_[1]);
                if (name != NULL) {
                    memset(self->dropNames_[1], 0, 0x48);
                    func_020e4864(*name, self->dropNames_[1], 1, 0, 0, 0);
                }
            }
        }
        loader->RemoveTask(self->taskIDs_[1]);
        self->taskIDs_[1] = -1;
        self->loadStep_++;
    }

    if (self->loadStep_ == 4 && loader->GetTaskStatus(self->taskIDs_[2])) {
        void* file;
        unsigned int size;
        loader->GetLoadedFileByID(self->taskIDs_[2], &file, &size);
        if (file != NULL) {
            char text[0x18];
            ResetAndReturnSelf020dfc2c(text);
            ResetStruct020dfc40((Struct020dfc40*)text);
            func_020e046c(self->description_, file, size, self->monster_->number_);
        }
        loader->RemoveTask(self->taskIDs_[2]);
        self->taskIDs_[2] = -1;
        self->loadStep_++;
    }

    if (self->loadStep_ == 6) {
        if (!(self->flags_ & 8) && self->taskIDs_[4] == -1) {
            self->loadStep_ = 0;
            self->flags_ &= ~9;
        }
        self->loadStep_++;
    }

    if (self->loadStep_ == 7) {
        if (self->loadModel_) {
            if (loader->GetTaskStatus(self->taskIDs_[4])) {
                self->flags_ &= ~4;
                self->loadStep_++;
            }
        } else {
            self->loadStep_++;
        }
    } else if (self->loadStep_ == 8) {
        if (self->loadModel_) {
            SafeAllocator* allocator = &self->allocators_[2];
            allocator->Reset();
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->taskIDs_[4], &file, &size);
            if (file != NULL) {
                GameResources* resources = func_ov017_0218b5b0();
                const void* found;
                unsigned int foundSize;
                if (FindFilesInNarcBySubstring(file, data_ov014_02189680, &found, &foundSize, 1)) {
                    unsigned int characterSize;
                    void* character = DecompressLZ77FileIntoAllocatedSpace(*allocator, found, characterSize);
                    if (FindFilesInNarcBySubstring(file, data_ov014_02189686, &found, &foundSize, 1)) {
                        unsigned int motionSize;
                        void* motion = DecompressLZ77FileIntoAllocatedSpace(*allocator, found, motionSize);
                        const void* actions;
                        unsigned int actionsSize;
                        if (FindFilesInNarcBySubstring(file, data_ov014_0218968c, &actions, &actionsSize, 1)) {
                            self->model_->Initialize();
                            self->model_->unknown_2_ = self->monster_->monsterID_;
                            self->model_->EnableFlag(4);
                            CopyInternalFields0207df50((Foo0207df50*)resources->unknown_2cc);
                            RestorePairTables0207df90(resources->unknown_2cc);
                            ObjectArchiveLoadInfo loadInfo;
                            ClearEightWords((Struct_203dafc*)&loadInfo);
                            loadInfo.fileData = character;
                            loadInfo.allocator = allocator;
                            loadInfo.unk_8 = characterSize;
                            self->model_->LoadFromCCHROrCMOTArchive(&loadInfo, NULL);
                            BackupPairTables0207dfac(resources->unknown_2cc);
                            ClearEightWords((Struct_203dafc*)&loadInfo);
                            loadInfo.allocator = allocator;
                            loadInfo.fileData = motion;
                            loadInfo.unk_8 = motionSize;
                            self->model_->LoadFromCCHROrCMOTArchive(&loadInfo, NULL);
                            ComputeAndStoreVecs02184c08((unsigned char*)self);
                            self->animationIndex_ = 0;
                            MonsterInfo* info = BinarySearchByField4_02097224((BinarySearch020971a8Container*)&self->infos_, self->monster_->monsterID_);
                            if (info != NULL)
                                self->model_->MaybeSetRegularAnimation(info->animations_[0], 0);
                            self->flags_ |= 4;
                        }
                    }
                }
            }
            loader->RemoveTask(self->taskIDs_[4]);
            self->taskIDs_[4] = -1;
        }
        self->loadStep_ = 0;
        self->flags_ &= ~9;
        if (self->unk_82_3_)
            self->unk_82_3_ = false;
        self->unk_94 = self->unk_93;
        self->unk_93 = false;
    }
}
