#include <globaldefs.h>

struct Container02080f8c;
struct Container02080fa8;

struct AlchemyMenu {
    int textPosition_;
    char** texts_;
    char padding_0x08[0xc];
    void* menu_;
    char padding_0x18[0x30];
    short** items_;
    unsigned char** counts_;
    unsigned short* sizes_;
    char padding_0x54[0x11c];
    char itemNames_[0xc];
    char padding_0x17c[0x1e6];
    short categoryCursor_;
    char padding_0x364[0xc];
    short item_;
    char padding_0x372[0x16];
    unsigned char page_;
    unsigned char pages_;
    unsigned char category_;
    unsigned char count_;
    char padding_0x38c[8];
    unsigned short flags_;
};

void SetSublistEntriesFlag1_02080b54(void*, int);
void SetSublistEntriesFlag2_02080608(void*, int);
void ClearSublistEntryFlag2_020806c4(void*, int);
void SetEntryFlagById02080b40(void*, int);
void* CallFunc020e52a0_020e5294(void*, int);
void SetEntryFirstField02080f8c(Container02080f8c*, int, int);
void SetEntryFirstField02080fa8(Container02080fa8*, int, int);
void Forward0207f7acObjPlus4Size0x40_020805f4(void*, int);
void SetOrClearEntryFlag0x102081130(void*, int, int);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void func_020e4864(const char*, char*, int, int, int, int);
extern "C" void func_020813ec(void*, int);

// USA: func_ov006_0215f4dc
extern "C" ARM void func_ov006_0215f4dc(AlchemyMenu* self) {
    short category;
    unsigned char* counts;
    unsigned short count;
    short iconEntry;
    void* menu;
    short* items;
    int nameEntry;
    int countEntry;
    unsigned short position;
    unsigned char row;
    category = self->categoryCursor_ - 0x5b;
    position = self->page_ * 8;
    counts = self->counts_[category];
    items = self->items_[category];
    menu = self->menu_;
    count = self->sizes_[category];
    nameEntry = 0x64;
    iconEntry = 0x6c;
    countEntry = 0x74;
    SetSublistEntriesFlag1_02080b54(menu, 0x11);
    SetSublistEntriesFlag2_02080608(menu, 0x11);
    self->flags_ &= ~4;
    if (count > 8) self->flags_ |= 4;
    for (row = 0; row < 8; row++) {
        if (count > position && items[position] > 0) {
            ClearSublistEntryFlag2_020806c4(menu, nameEntry);
            SetEntryFlagById02080b40(menu, nameEntry);
            SetEntryFlagById02080b40(menu, iconEntry);
            SetEntryFlagById02080b40(menu, countEntry);
            const char** name = (const char**)CallFunc020e52a0_020e5294(self->itemNames_, items[position]);
            if (name != NULL) {
                memset(self->texts_[row], 0, 4);
                func_020e4864(*name, self->texts_[row], 1, 0, 0, 0);
                SetEntryFirstField02080f8c((Container02080f8c*)self->menu_, nameEntry, (int)self->texts_[row]);
            }
            Forward0207f7acObjPlus4Size0x40_020805f4(menu, nameEntry);
            unsigned char amount = counts[position];
            if (self->item_ == items[position]) amount -= self->count_;
            SetEntryFirstField02080fa8((Container02080fa8*)menu, countEntry, amount);
        }
        nameEntry = (short)(nameEntry + 1);
        iconEntry++;
        countEntry = (short)(countEntry + 1);
        position++;
    }
    SetEntryFlagById02080b40(menu, 0x7c);
    SetEntryFlagById02080b40(menu, 0x7d);
    SetEntryFlagById02080b40(menu, 0x7e);
    SetEntryFirstField02080fa8((Container02080fa8*)menu, 0x7c, self->page_ + 1);
    SetEntryFirstField02080fa8((Container02080fa8*)menu, 0x7d, self->pages_);
    SetOrClearEntryFlag0x102081130(menu, 0x11, (self->flags_ & 4) ? 1 : 0);
    func_020813ec(menu, 0x11);
}
