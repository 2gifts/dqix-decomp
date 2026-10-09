#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>

struct Foo02048004;
struct Foo0207df50;
struct Vec3Target0203a46c;
struct Obj02155d38;

struct MenuModel {
    char unk_0[0x80];
    short alpha_;
    short unk_82;
    char unk_84[4];
};

struct VRAMManagerState {
    char unk_0[0x70];
};

void MaybeInvoke0204719c(Foo02048004* model);
void CopyInternalFields0207df50(Foo0207df50* state);
void RestorePairTables0207df90(char* state);
extern "C" void func_02047b40(MenuModel* model, void* file, SafeAllocator* allocator);
void BackupPairTables0207dfac(char* state);
void SetVec3At0x1c(Vec3Target0203a46c* model, int x, int y, int z);
void RunTwoCallbacksAndReset02155d38(Obj02155d38* slot);

struct EquipmentSlot {
    short item_;
    signed char count_;
    unsigned char equipped_;
    VRAMManagerState* vramState_;
    MenuModel* model_;
    int x_;
    int y_;
    int offset_;
    short loadedItem_;
};

struct EquipmentMenu {
    SafeAllocator allocator_;
    SafeAllocator modelAllocator_;
    SafeAllocator equippedAllocators_[8];
    SafeAllocator itemAllocators_[16];
    SafeAllocator dragAllocator_;
    char unk_21c[0xd84 - 0x21c];
    VRAMManagerState dragVramState_;
    char unk_df4[0x2d90 - 0xdf4];
    EquipmentSlot slots_[24];
    MenuModel slotModels_[24];
    MenuModel dragModel_;
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

// USA: func_ov005_02155d6c
extern "C" ARM void func_ov005_02155d6c(EquipmentMenu* self) {
    unsigned char loading = self->loading_;
    if (loading != 0) {
        if (self->dragStep_ == 1) {
            EquipmentSlot* slot = &self->slots_[self->dragged_];
            if (slot->offset_ == 0) {
                MaybeInvoke0204719c((Foo02048004*)&self->dragModel_);
                CopyInternalFields0207df50((Foo0207df50*)&self->dragVramState_);
                RestorePairTables0207df90((char*)&self->dragVramState_);
                self->dragAllocator_.Reset();
                func_02047b40(&self->dragModel_, self->dragFile_, &self->dragAllocator_);
                BackupPairTables0207dfac((char*)&self->dragVramState_);
            }
            slot->offset_ = -1;
            slot->equipped_ = 0;
            memset(self->dragFile_, 0, 0x200);
            self->loading_--;
            self->dragStep_ = 0;
        } else if (self->unk_3da8 == 1) {
            EquipmentSlot* slot = &self->slots_[self->unk_3dac];
            VRAMManagerState* vramState = slot->vramState_;
            MenuModel* model = slot->model_;
            if (slot->offset_ == 0) {
                RunTwoCallbacksAndReset02155d38((Obj02155d38*)slot);
                RestorePairTables0207df90((char*)vramState);
                self->equippedAllocators_[self->unk_3dac].Reset();
                func_02047b40(model, self->itemFile_, &self->equippedAllocators_[self->unk_3dac]);
                slot->loadedItem_ = slot->item_;
                BackupPairTables0207dfac((char*)vramState);
            }
            model->unk_82 = 0x1f;
            model->alpha_ = 0x7fff;
            SetVec3At0x1c((Vec3Target0203a46c*)model, slot->x_, slot->y_, 0);
            slot->offset_ = -1;
            slot->equipped_ = 0;
            memset(self->itemFile_, 0, 0x200);
            self->loading_--;
            self->unk_3da8 = 0;
        } else if (self->equippedStep_ == 1) {
            for (int i = 0; i < 8; i++)
                self->equippedAllocators_[i].Reset();
            self->equippedStep_++;
        } else if (self->equippedStep_ == 2) {
            signed char count = 0;
            int i = self->equippedStart_;
            for (; i < self->equippedEnd_; i++) {
                if (count == 4)
                    break;
                EquipmentSlot* slot = &self->slots_[i];
                VRAMManagerState* vramState = slot->vramState_;
                int offset = slot->offset_;
                MenuModel* model = slot->model_;
                if (offset >= 0) {
                    RunTwoCallbacksAndReset02155d38((Obj02155d38*)slot);
                    RestorePairTables0207df90((char*)vramState);
                    self->equippedAllocators_[i].Reset();
                    func_02047b40(model, self->equippedFiles_ + offset, &self->equippedAllocators_[i]);
                    slot->loadedItem_ = slot->item_;
                    BackupPairTables0207dfac((char*)vramState);
                }
                model->unk_82 = 0x1f;
                model->alpha_ = 0x7fff;
                SetVec3At0x1c((Vec3Target0203a46c*)model, slot->x_, slot->y_, 0);
                slot->offset_ = -1;
                slot->equipped_ = 0;
                count++;
            }
            memset(self->equippedFiles_, 0, 0x800);
            self->equippedStart_ += count;
        } else if (self->equippedStep_ == 3) {
            self->loading_ = loading - 1;
            self->equippedStep_ = 0;
        } else if (self->pageStep_ == 1) {
            for (int i = 0; i < 16; i++) {
                if (self->slots_[i + 8].equipped_ == 0)
                    self->itemAllocators_[i].Reset();
            }
            self->pageStep_++;
        } else if (self->pageStep_ == 3) {
            signed char count = 0;
            int i = self->pageStart_;
            for (; i < self->pageEnd_; i++) {
                if (count == 4)
                    break;
                EquipmentSlot* slot = &self->slots_[i];
                VRAMManagerState* vramState = slot->vramState_;
                MenuModel* model = slot->model_;
                if (slot->equipped_ != 0) {
                    count++;
                    continue;
                }
                int offset = slot->offset_;
                if (offset >= 0) {
                    RunTwoCallbacksAndReset02155d38((Obj02155d38*)slot);
                    RestorePairTables0207df90((char*)vramState);
                    self->itemAllocators_[i - 8].Reset();
                    func_02047b40(model, self->pageFiles_ + offset, &self->itemAllocators_[i - 8]);
                    slot->loadedItem_ = slot->item_;
                    BackupPairTables0207dfac((char*)vramState);
                }
                model->unk_82 = 0x1f;
                model->alpha_ = 0x7fff;
                SetVec3At0x1c((Vec3Target0203a46c*)model, slot->x_, slot->y_, 0);
                slot->offset_ = -1;
                slot->equipped_ = 0;
                count++;
            }
            memset(self->pageFiles_, 0, 0x800);
            self->pageStart_ += count;
            self->pageStep_ = 2;
        } else if (self->pageStep_ == 4) {
            self->loading_ = loading - 1;
            self->pageStep_ = 0;
        }
        self->flags_ |= 2;
        return;
    }
    self->flags_ &= ~2;
}
