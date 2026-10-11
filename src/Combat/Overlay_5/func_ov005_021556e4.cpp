#if defined(jpn)
#define R(j,u) (j)
#define func_ov005_02158560 func_ov005_02159b58
#define func_ov005_021585fc func_ov005_02159bf4
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <Filesystem/FileIO.h>
#include <std_library_functions.h>

struct Container020dedd0;
struct StructDE234_020de234;
struct Container020e0310;
struct Vec3Target0203a46c;
struct Obj02155d38;

struct PartEntry {
    void* model_;
    int unk_4;
    unsigned int unk_8;
    unsigned int unk_c;
    unsigned int unk_10_0 : 20;
    unsigned int letter_ : 8;
    unsigned int unk_10_28 : 4;
};

extern "C" void __clear(void* buffer, unsigned long size);
extern "C" PartEntry* _Z24FindElementByKey020dedd0P17Container020dedd0i(Container020dedd0* items, int id);
extern "C" int _Z31GetPreferredPackedField020de234P20StructDE234_020de234i(StructDE234_020de234* item, int a);
extern "C" const char* _Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310* texts, int id);
void SetVec3At0x1c(Vec3Target0203a46c* model, int x, int y, int z);
extern "C" void _Z31RunTwoCallbacksAndReset02155d38P11Obj02155d38(Obj02155d38* slot);

struct EquipmentSlot {
    short item_;
    signed char count_;
    unsigned char equipped_;
    void* vramState_;
    void* model_;
    int x_;
    int y_;
    int offset_;
    short loadedItem_;
};

struct EquipmentMenu {
    char unk_0[0xdf4];
    Container020dedd0* items_;
    char texts_[R(0x2d08, 0x2d90) - 0xdf8];
    EquipmentSlot slots_[24];
    char slotModels_[0x3cf0 - 0x3030];
    char dragModel_[0x88];
    short dragged_;
    char unk_3d7a[0x3d88 - 0x3d7a];
    char* pageFiles_;
    char* dragFile_;
    char* equippedFiles_;
    char* itemFile_;
    short itemCounts_[8];
    unsigned char unk_3da8;
    unsigned char equippedStep_;
    unsigned char pageStep_;
    unsigned char dragStep_;
    unsigned short unk_3dac;
    unsigned short equippedStart_;
    unsigned short equippedEnd_;
    unsigned short pageStart_;
    unsigned short pageEnd_;
    char unk_3db6;
    unsigned char loading_;
    char unk_3db8[0x3dcc - 0x3db8];
    unsigned int flags_;
};

extern "C" void func_ov005_021553b4(EquipmentMenu* self, int slot, int* x, int* y);

// USA: func_ov005_021556e4
extern "C" ARM void func_ov005_021556e4(EquipmentMenu* self) {
    if (self->flags_ & 0x80) {
        if (self->dragStep_ == 0) {
            memset(self->dragFile_, 0, 0x200);
            EquipmentSlot* slot = &self->slots_[self->dragged_];
            slot->offset_ = -1;
            PartEntry* item = _Z24FindElementByKey020dedd0P17Container020dedd0i(self->items_, slot->item_);
            if (item != NULL) {
                char path[0x80];
                __clear(path, sizeof(path));
                int number = _Z31GetPreferredPackedField020de234P20StructDE234_020de234i((StructDE234_020de234*)item, 0);
                sprintf(path, _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)self->texts_, 0x7d1), (char)item->letter_, number);
                if (LoadFileIntoMemory(path, self->dragFile_, NULL))
                    slot->offset_ = 0;
                int x;
                int y;
                func_ov005_021553b4(self, self->dragged_, &x, &y);
                SetVec3At0x1c((Vec3Target0203a46c*)self->dragModel_, x << 12, y << 12, 0x2000);
                self->dragStep_++;
                self->loading_++;
            }
            self->flags_ &= ~0x80;
        }
    } else if (self->flags_ & 0x10) {
        if (self->unk_3da8 == 0) {
            memset(self->itemFile_, 0, 0x200);
            EquipmentSlot* slot = &self->slots_[self->unk_3dac];
            slot->offset_ = -1;
            PartEntry* item = _Z24FindElementByKey020dedd0P17Container020dedd0i(self->items_, slot->item_);
            if (item != NULL) {
                char path[0x80];
                __clear(path, sizeof(path));
                int number = _Z31GetPreferredPackedField020de234P20StructDE234_020de234i((StructDE234_020de234*)item, 0);
                sprintf(path, _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)self->texts_, 0x7d1), (char)item->letter_, number);
                if (LoadFileIntoMemory(path, self->itemFile_, NULL))
                    slot->offset_ = 0;
                self->unk_3da8++;
                self->loading_++;
            }
            self->flags_ &= ~0x10;
        }
    } else if (self->flags_ & 0x20) {
        if (self->equippedStep_ == 0) {
            for (int i = 0; i < 8; i++) {
                _Z31RunTwoCallbacksAndReset02155d38P11Obj02155d38((Obj02155d38*)&self->slots_[i]);
                self->slots_[i].offset_ = -1;
            }
            self->equippedStart_ = 0;
            self->equippedEnd_ = 8;
            self->equippedStep_++;
            self->loading_++;
        } else if (self->equippedStep_ == 2) {
            memset(self->equippedFiles_, 0, 0x800);
            int offset = 0;
            signed char count = 0;
            for (int i = self->equippedStart_; i < self->equippedEnd_; i++) {
                EquipmentSlot* slot = &self->slots_[i];
                slot->offset_ = -1;
                PartEntry* item = _Z24FindElementByKey020dedd0P17Container020dedd0i(self->items_, slot->item_);
                if (item != NULL) {
                    unsigned int size = 0;
                    char path[0x80];
                    __clear(path, sizeof(path));
                    int number = _Z31GetPreferredPackedField020de234P20StructDE234_020de234i((StructDE234_020de234*)item, 0);
                    sprintf(path, _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)self->texts_, 0x7d1), (char)item->letter_, number);
                    if (LoadFileIntoMemory(path, self->equippedFiles_ + offset, &size)) {
                        slot->offset_ = offset;
                        size = (size + 3) & ~3;
                        offset += size;
                    }
                }
                if (++count == 4)
                    break;
            }
            if (self->equippedStart_ == self->equippedEnd_) {
                self->equippedStep_++;
                self->flags_ &= ~0x20;
            }
        }
    } else if (self->flags_ & 0x40) {
        if (self->pageStep_ == 0) {
            for (int i = 8; i < 24; i++) {
                EquipmentSlot* slot = &self->slots_[i];
                if (slot->equipped_ == 0) {
                    _Z31RunTwoCallbacksAndReset02155d38P11Obj02155d38((Obj02155d38*)slot);
                    slot->offset_ = -1;
                }
            }
            self->pageStart_ = 8;
            self->pageEnd_ = 24;
            self->pageStep_++;
            self->loading_++;
        } else if (self->pageStep_ == 2) {
            memset(self->pageFiles_, 0, 0x800);
            int offset = 0;
            signed char count = 0;
            for (int i = self->pageStart_; i < self->pageEnd_; i++) {
                EquipmentSlot* slot = &self->slots_[i];
                slot->offset_ = -1;
                if (slot->equipped_ != 0)
                    continue;
                PartEntry* item = _Z24FindElementByKey020dedd0P17Container020dedd0i(self->items_, slot->item_);
                if (item != NULL) {
                    unsigned int size = 0;
                    char path[0x80];
                    __clear(path, sizeof(path));
                    int number = _Z31GetPreferredPackedField020de234P20StructDE234_020de234i((StructDE234_020de234*)item, 0);
                    sprintf(path, _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)self->texts_, 0x7d1), (char)item->letter_, number);
                    if (LoadFileIntoMemory(path, self->pageFiles_ + offset, &size)) {
                        slot->offset_ = offset;
                        size = (size + 3) & ~3;
                        offset += size;
                    }
                }
                if (++count == 4)
                    break;
            }
            self->pageStep_++;
            if (self->pageStart_ == self->pageEnd_) {
                for (int i = 8; i < 24; i++)
                    self->slots_[i].equipped_ = 0;
                self->pageStep_ = 4;
                self->flags_ &= ~0x40;
            }
        }
    }
}
