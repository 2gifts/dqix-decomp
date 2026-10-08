#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

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

struct HandleState_02188d10 {
    char unk_0[0x20];
};

struct MonsterInfoScreen {
    char unk_0[0x1c];
    HandleState_02188d10 habitats_;
    char unk_3c[0x48 - 0x3c];
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
};

extern "C" bool _Z20ResetHandle_02188d10P20HandleState_02188d10(HandleState_02188d10* s);

// USA: func_ov014_02184f78
extern "C" ARM void func_ov014_02184f78(MonsterInfoScreen* self, MonsterListEntry* monster, MonsterRecord* record, bool loadModel) {
    if (self->state_ == 0)
        return;
    if (monster == NULL || record == NULL) {
        self->monster_ = monster;
        return;
    }

    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->taskID_ >= 0) {
        loader->RemoveTask(self->taskID_);
        self->taskID_ = -1;
    }
    for (int i = 0; i < 5; i++) {
        short taskID = self->taskIDs_[i];
        if (taskID >= 0) {
            BackgroundLoader::GetInstance()->RemoveTask(taskID);
            self->taskIDs_[i] = -1;
        }
    }
    _Z20ResetHandle_02188d10P20HandleState_02188d10(&self->habitats_);
    self->loadStep_ = 0;
    self->page_ = 0;
    self->monster_ = monster;
    self->record_ = record;
    self->dropNames_[0][0] = '\0';
    self->dropNames_[1][0] = '\0';
    self->description_[0] = '\0';
    self->flags_ |= 1;
    self->flags_ &= ~8;
    self->loadModel_ = loadModel;
    if (!self->monster_->known_) {
        self->flags_ &= ~1;
        self->flags_ |= 0x10;
        self->flags_ &= ~4;
        self->unk_93 = false;
        return;
    }

    self->flags_ &= ~0x10;
    if (self->backgroundTaskID_ >= 0) {
        loader->RemoveTask(self->backgroundTaskID_);
        self->backgroundTaskID_ = -1;
    }
    self->backgroundStep_ = 0;
    self->unk_93 = true;
}
