#include <globaldefs.h>

struct Container020e0310;
struct Struct0205de24;

extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" const char* _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);
extern "C" int func_020420e8(const char* text, int large);
extern "C" void* memset(void* dst, int value, unsigned int length);
extern "C" void func_ov003_0215b6f0(char* base, char* dst, int flag);
extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);

struct Ctx0215b5c4 {
    char unk_0[0x64];
    char texts_[0x7c - 0x64];
    char* buffer_;
    char unk_80[0xf4 - 0x80];
    char window_[0x194 - 0xf4];
    short width_;
    short height_;
    short x_;
    short y_;
    short field_0x19c;
    short field_0x19e;
    short field_0x1a0;
    short field_0x1a2;
    char unk_1a4;
    unsigned char field_0x1a5;
    char unk_1a6[3];
    unsigned char field_0x1a9;
    char unk_1aa[0x584 - 0x1aa];
    unsigned char cursor_;
    char unk_585[0x589 - 0x585];
    unsigned char count_;
    signed char entries_[1];
};

// USA: func_ov003_0215b5c4
extern "C" ARM void func_ov003_0215b5c4(Ctx0215b5c4* self) {
    _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24*)self->window_, 0, 2);
    short height = (self->count_ * 14 + 0x12) / 8;
    int maxWidth = 0;
    for (int i = 0; i < self->count_; i++) {
        short w = func_020420e8(_Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)self->texts_, self->entries_[i]), 0);
        if (maxWidth < w) {
            maxWidth = w;
        }
    }
    short width = (maxWidth + 0x18) >> 3;
    self->width_ = width;
    self->height_ = height;
    self->x_ = 0x1f - width;
    self->y_ = 2;
    self->field_0x19c = 0xc;
    self->field_0x19e = 8;
    self->field_0x1a0 = 0xa;
    self->field_0x1a2 = 0xe;
    self->field_0x1a5 = 1;
    self->field_0x1a9 = 1;
    self->cursor_ = 0;
    memset(self->buffer_, 0, 0x960);
    func_ov003_0215b6f0((char*)self, self->buffer_, 0);
    func_0205d304(self->window_, self->buffer_, 0, 1, 0, 1, 0, 0);
}
