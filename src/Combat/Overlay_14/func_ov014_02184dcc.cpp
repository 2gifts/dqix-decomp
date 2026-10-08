#include <globaldefs.h>

struct MonsterListEntry;

struct MonsterRecord {
    unsigned int defeatCount_ : 10;
    unsigned int complete_ : 1;
    unsigned int dropCount0_ : 7;
    unsigned int dropCount1_ : 7;
    unsigned int unk_0_25_ : 7;
};

struct MonsterInfoScreen {
    char unk_0[0x48];
    MonsterListEntry* monster_;
    MonsterListEntry* prevMonster_;
    MonsterRecord* record_;
    char unk_54[0x80 - 0x54];
    unsigned char page_;
    unsigned char flags_;
    char unk_82[0x90 - 0x82];
    unsigned char buttonPressed_[3];
    unsigned char unk_93;
};

extern "C" void func_ov014_02184f78(MonsterInfoScreen* self, MonsterListEntry* monster, MonsterRecord* record, bool loadModel);

// USA: func_ov014_02184dcc
extern "C" ARM void func_ov014_02184dcc(MonsterInfoScreen* self) {
    if (self->flags_ & 1)
        return;
    if (self->flags_ & 8)
        return;
    if (self->record_ == NULL || !self->record_->complete_)
        return;
    unsigned char page = self->page_;
    func_ov014_02184f78(self, self->monster_, self->record_, false);
    self->page_ = page + 1;
    self->page_ %= 2;
    self->buttonPressed_[2] = true;
    self->flags_ |= 8;
}
