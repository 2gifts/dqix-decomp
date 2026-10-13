#include <globaldefs.h>

struct NetworkRecord {
    unsigned int field_0;
    unsigned char address_[6];
    unsigned short nameLength_;
    char name_[32];
    unsigned short mode_;
    unsigned short selected_;
    unsigned short available_;
    unsigned short value_;
    unsigned short field_34;
    unsigned short addressLength_;
};
struct NetworkSummary {
    unsigned int nameLength_;
    char name_[32];
    unsigned int addressLength_;
    char unknown_28[8];
    unsigned char address_[6];
    char unknown_36[2];
    int count_;
    unsigned char items_[16];
    unsigned int value_;
    int mode_;
};
struct FlagItem { unsigned short flag_; unsigned char value_; unsigned char unknown_; };
extern FlagItem data_ov031_0224b0e4[12] __attribute__((aligned(4)));
extern "C" void func_020ca3b8(const void*, void*, unsigned int);

// USA: func_ov031_0221e6e8
extern "C" THUMB void func_ov031_0221e6e8(NetworkRecord* record, NetworkSummary* summary) {
    summary->nameLength_ = record->nameLength_;
    func_020ca3b8(record->name_, summary->name_, 32);
    summary->addressLength_ = record->addressLength_;
    func_020ca3b8(record->address_, summary->address_, 6);
    int i;
    int count = 0;
    FlagItem* item = data_ov031_0224b0e4;
    i = 0;
    do {
        if (record->available_ & item->flag_) {
            summary->items_[count] = item->value_;
            if (record->selected_ & item->flag_)
                summary->items_[count] = summary->items_[count] | 0x80;
            count++;
        }
        i++;
        item++;
    } while (i < 12);
    summary->count_ = count;
    summary->value_ = record->value_;
    int mode = record->mode_ & 3;
    if (mode == 1) summary->mode_ = 1;
    else if (mode == 2) summary->mode_ = 2;
    else summary->mode_ = 0;
}
