#include <globaldefs.h>

#if defined(jpn)
enum { kEntries = 0xc, kMeter = 0x6c, kTextAdjustment = 2 };
#else
enum { kEntries = 0x14, kMeter = 0x74, kTextAdjustment = 4 };
#endif

struct Container02080fa8;
struct StatusOwner02081164;
struct BattleMeter {
    char pad0[kEntries];
    Container02080fa8* entries;
    char pad18[kMeter-kEntries-4];
    int meter;
    char pad78[0x366-kMeter-4];
    short command;
    char pad368[0x38f-0x368];
    unsigned char mode;
};
void SetSublistEntriesFlag1(void*, int);
void SetEntryFlagById02080b40(void*, int);
void SetEntryHalfword0xe(void*, int, int);
void SetEntryFirstField02080fa8(Container02080fa8*, int, int);
void SetEntryFlag0x2ByShortId(StatusOwner02081164*, int, int);
extern "C" void func_020806d8(void*, int, int, int, int);
extern "C" int func_ov006_02154138(int*);
extern "C" void func_020813ec(void*, int);

// USA: func_ov006_0215fa1c
extern "C" ARM void func_ov006_0215fa1c(BattleMeter* self, int showValue) {
    Container02080fa8* entries = self->entries;
    SetSublistEntriesFlag1(entries, 0xd);
    SetEntryFlagById02080b40(entries, 0x56);
    SetEntryHalfword0xe(self->entries, 0x56, 0x2b);
    if (self->mode != 10 && self->mode != 3) {
        int text = 0x2c;
        if (!showValue) {
            switch (self->command) {
            case 0x25: text = 0x12; break;
            case 0x26: text = 0x13; break;
            }
        }
        SetEntryHalfword0xe(entries, 0x57, text);
        SetEntryFlagById02080b40(entries, 0x57);
        func_020806d8(entries, 0xd, 0x57, 1, kTextAdjustment);
        if (showValue) {
            unsigned int meter = (unsigned short)func_ov006_02154138(&self->meter);
            float fraction = (float)meter / 448.0f;
            fraction *= 10000.0f;
            int scaled = (int)fraction;
            int value = (scaled - scaled % 100) / 100;
            if (meter && value <= 0) value = 1;
            if (value > 100) value = 100;
            SetEntryFirstField02080fa8(entries, 0x58, value);
            SetEntryFlagById02080b40(entries, 0x58);
            SetEntryHalfword0xe(self->entries, 0x56, 0x2e);
        }
    }
    SetEntryFlag0x2ByShortId((StatusOwner02081164*)entries, 0xd, 1);
    func_020813ec(entries, 0xd);
}
