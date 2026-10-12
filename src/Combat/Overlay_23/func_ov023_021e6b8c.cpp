#include <globaldefs.h>
#include "System/Cache.h"

struct S_b20c {
    int field_0;
    int field_4;
    unsigned char field_8;
};
struct WeightedEntry021e6b8c {
    int field_0;
    short offset;
    short field_6;
    short width;
    short height;
};
struct SpriteFlags021e6b8c {
    unsigned int field_0;
    unsigned short flags;
};
struct SpriteHeader021e6b8c {
    void* data;
    SpriteFlags021e6b8c* flags;
};
struct SpriteEntry021e6b8c : SpriteHeader021e6b8c {
    unsigned char padding_8[0x20];
};
struct Label021e6b8c {
    short field_0;
    short field_2;
    const char* text;
    const char* alternate;
    unsigned char field_c;
    unsigned char mode;
    unsigned char index;
};
struct LabelOwner021e6b8c {
    Label021e6b8c* selected;
    unsigned char padding_4[0x1a];
    unsigned char flags;
    unsigned char padding_1f;
    unsigned char mode;
};
struct LabelState021e6b8c {
    LabelOwner021e6b8c* owner;
    unsigned char padding_4[0x1364 - 4];
    SpriteEntry021e6b8c* sprites;
    unsigned char padding_1368[8];
    unsigned char index;
    unsigned char mode;
    unsigned char padding_1372[10];
    void* buffer;
};
void ClearTwoWordsAndByte(S_b20c*);
extern "C" void _Z18SetField0_0205b220Pvi(void*, int);
extern "C" void _Z29SetFieldsAt0x4And0x8_0205b228Pvih(void*, int, unsigned char);
extern "C" {
void func_ov003_0215ec68(int, short*, short*);
void func_0205b890(WeightedEntry021e6b8c*, int, SpriteEntry021e6b8c*);
void* memcpy(void*, const void*, unsigned int);
int func_020420e8(const char*, int);
void func_0205b734(void*, short, short, short, short, short);
int func_0205b234(void*, short, short, const char*, unsigned char, unsigned char);
void LoadToMainObjVRAM(const void*, unsigned int, unsigned int);
}

// USA: func_ov023_021e6b8c
extern "C" ARM void func_ov023_021e6b8c(LabelState021e6b8c* self, unsigned short address, Label021e6b8c* label, int size) {
    if (self->mode != 14 || self->index <= 1 || self->index >= 10) return;
    label = self->owner->selected;
    if (label == 0 || label->index == 3) return;
    SpriteEntry021e6b8c* sprite = &self->sprites[label->index + 15];
    short x;
    short y;
    func_ov003_0215ec68(label->index, &x, &y);
    WeightedEntry021e6b8c entries[3];
    for (int i = 0; i < 3; i++) {
        entries[i].field_0 = 0;
        entries[i].offset = 0;
        entries[i].field_6 = 0;
        entries[i].width = 0;
        entries[i].height = 0;
    }
    func_0205b890(entries, 3, sprite);
    int offset = 0;
    size = 0;
    for (int i = 0; i < 3; i++) {
        entries[i].offset = offset;
        offset += entries[i].width;
        size += (entries[i].width * entries[i].height) >> 1;
    }
    SpriteHeader021e6b8c copy = *sprite;
    address = (unsigned short)(copy.flags->flags & 0x3ff) << 5;
    memcpy(self->buffer, (const void*)(0x6400000 + address), size);
    unsigned char flags = self->owner->flags;
    unsigned char mode = self->owner->mode;
    const char* text = label->text;
    if (label->mode == 0 && (mode != 0 || (flags & 2) != 0)) text = label->alternate;
    int center = (x - func_020420e8(text, 1)) >> 1;
    S_b20c destination;
    ClearTwoWordsAndByte(&destination);
    _Z18SetField0_0205b220Pvi(&destination, (int)self->buffer);
    _Z29SetFieldsAt0x4And0x8_0205b228Pvih(&destination, (int)entries, 3);
    func_0205b734(&destination, 9, 9, (short)(x + 7), (short)(y + 7), 9);
    func_0205b234(&destination, (short)(center + 8), 10, text, 2, 1);
    CleanInvalidateCacheRange(self->buffer, size);
    LoadToMainObjVRAM(self->buffer, address, size);
    CleanCacheRange(self->buffer, size);
}
