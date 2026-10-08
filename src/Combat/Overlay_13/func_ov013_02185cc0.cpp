#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct0205de24;
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" void func_ov013_02185e40(void* self, char* text);
extern "C" void func_0205d304(void* window, char* text, int c, int d, int e, int f, void* g, int h);

struct Sprite02185cc0 {
    char unk_0[8];
    unsigned short* unk_8;
};
extern "C" Sprite02185cc0* _Z23GetArrayElement02184338Pvj(void* renderer, unsigned int index);
extern "C" void* _Z21GetTableEntry020421b0i(int index);
void CleanInvalidateCacheRange(const void* start, unsigned int size);
void CleanCacheRange(const void* start, unsigned int size);
extern "C" void LoadToSubObjVRAM(const void* src, unsigned int offset, unsigned int size);
extern "C" void LoadToMainObjVRAM(const void* src, unsigned int offset, unsigned int size);

extern const int data_ov013_02187d9c[2];
extern const int data_ov013_02187da4[2];

struct TextWindow02185cc0 {
    char unk_0[0xa0];
    short width_;
    short height_;
    short unk_a4;
    short unk_a6;
    short unk_a8;
    short unk_aa;
    short unk_ac;
    short unk_ae;
    unsigned char unk_b0;
    unsigned char unk_b1;
    unsigned char unk_b2;
    unsigned char unk_b3;
    unsigned char unk_b4;
    unsigned char unk_b5;
};

struct SkillPointMenu02185cc0 {
    char unk_0[0x18];
    void* spriteRenderer_;
    char unk_1c[0x38 - 0x1c];
    TextWindow02185cc0 window_;
    char unk_ee[0x640 - 0xee];
    bool subScreen_;
    char unk_641[0x654 - 0x641];
    void* canvasPixels_;
    char* text_;
    char unk_65c[0x6a8 - 0x65c];
    unsigned char vocation_;
};

// USA: func_ov013_02185cc0
extern "C" ARM void func_ov013_02185cc0(SkillPointMenu02185cc0* self) {
    bool subScreen;
    void* renderer;
    void* pixels;
    unsigned char vocation;
    _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24*)&self->window_, 0, 2);
    self->window_.width_ = 0xf;
    self->window_.height_ = 0xb;
    self->window_.unk_a4 = 1;
    self->window_.unk_a6 = 0xd;
    self->window_.unk_a8 = 6;
    self->window_.unk_aa = 5;
    self->window_.unk_ac = 0xa;
    self->window_.unk_ae = 0xd;
    self->window_.unk_b1 = 4;
    self->window_.unk_b5 = self->subScreen_ ? 0 : 1;
    memset(self->text_, 0, 0x960);
    func_ov013_02185e40(self, self->text_);
    func_0205d304(&self->window_, self->text_, 0, 0, 0, 1, NULL, 0);
    renderer = self->spriteRenderer_;
    pixels = self->canvasPixels_;
    vocation = self->vocation_;
    subScreen = self->subScreen_;
    if (renderer != NULL && pixels != NULL)
    {
        const int* icon = data_ov013_02187da4;
        if (subScreen)
            icon = data_ov013_02187d9c;
        Sprite02185cc0* sprite = _Z23GetArrayElement02184338Pvj(renderer, (unsigned short)icon[0]);
        unsigned short* oam;
        if (sprite != NULL && (oam = sprite->unk_8) != NULL)
        {
            memcpy(pixels, _Z21GetTableEntry020421b0i((unsigned char)(vocation * 4 + 0x28)), 0x80);
            unsigned int offset = (unsigned short)(oam[2] & 0x3ff) << icon[1];
            CleanInvalidateCacheRange(pixels, 0x80);
            if (subScreen)
                LoadToSubObjVRAM(pixels, offset, 0x80);
            else
                LoadToMainObjVRAM(pixels, offset, 0x80);
            CleanCacheRange(pixels, 0x80);
        }
    }
}
