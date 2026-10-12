#include <globaldefs.h>

struct GlyphMetrics02066a6c { char pad[4]; signed char width; };
struct SetIntIntShortAt0xcStruct {
    char pad[12]; int x; int y; short mode; short reserved; GlyphMetrics02066a6c* metrics;
};
struct Transform02066a6c { short x; short y; int field4; int mode; int fieldc; int scaleX; int scaleY; int field18; };
struct Holder02042c24 { char pad[0x440]; Transform02066a6c* transform; };
struct Field440XYObj;
struct Display02066a6c {
    char pad0[0x34]; void* context;
    char pad38[0x8dc]; Transform02066a6c backup; Transform02066a6c active;
    char pad94c[0x6c]; SetIntIntShortAt0xcStruct glyphs[80];
    char pad1278[0x604]; unsigned short font;
    char pad187e[4]; unsigned short text[96];
    unsigned short length; short width;
    char pad1946[0x7d]; unsigned char hasText; unsigned char visible;
    char pad19c5[0x17]; unsigned char table;
    char pad19dd[3]; Holder02042c24 holder;
};
extern "C" void _Z25LoadStateBytePair0206b804PcPiS0_(char*, int*, int*);
void GetField440XY(Field440XYObj*, short*, short*);
extern "C" void _Z22SetSubstructXY02042c24P14Holder02042c24ii(Holder02042c24*, int, int);
void EmitScaledField0x440(void*, int, int);
extern "C" int _Z24GetWordFromTable02042648i(int);
void SetIntIntShortAt0xc(SetIntIntShortAt0xcStruct*, int, int, short);
extern "C" void func_020417b0(SetIntIntShortAt0xcStruct*, int, int, int);
extern "C" void func_020654b8(Display02066a6c*, void*, SetIntIntShortAt0xcStruct*, int, int, int);

// USA: func_02066a6c
extern "C" ARM void func_02066a6c(Display02066a6c* obj, int absolute) {
    if (!obj->visible) return;
    Holder02042c24* holder = &obj->holder;
    int count;
    unsigned short* text;
    SetIntIntShortAt0xcStruct* glyph;
    int i;
    int spacing;
    count = 0;
    text = NULL;
    if (obj->hasText) {
        text = obj->text;
        count = obj->length & 255;
    }
    if (text) {
        int offsetX, offsetY;
        short x, y;
        _Z25LoadStateBytePair0206b804PcPiS0_((char*)obj, &offsetX, &offsetY);
        GetField440XY((Field440XYObj*)holder, &x, &y);
        y -= 19;
        holder->transform = &obj->active;
        if (holder->transform) {
            holder->transform->scaleX = 4096;
            holder->transform->scaleY = 4096;
        }
        if (holder->transform) holder->transform->mode = 2;
        if (absolute) _Z22SetSubstructXY02042c24P14Holder02042c24ii(holder, x, y);
        else {
            _Z22SetSubstructXY02042c24P14Holder02042c24ii(holder, (short)(x + offsetX), (short)(y + offsetY));
            EmitScaledField0x440(holder, 1, 0);
        }
        short remainder = 8 - (obj->width & 7);
        x += (remainder + 18) >> 1;
        y += 5;
        unsigned char fontWidth = _Z24GetWordFromTable02042648i(obj->table);
        for (i = 0; i < count; i++) {
            spacing = fontWidth + 1;
            unsigned short code = text[i];
            if ((code & 0xff00) == 0xff00) {
                if (code == 0xff01) break;
                if (code == 0xff19) { x += spacing; continue; }
            }
            glyph = &obj->glyphs[code];
            if (absolute) func_020654b8(obj, obj->context, glyph, x, y, 15);
            else {
                SetIntIntShortAt0xc(glyph, x, y, 0);
                func_020417b0(glyph, obj->font, 0, 31);
            }
            if (glyph->metrics) x += glyph->metrics->width + 1;
        }
    }
    holder->transform = &obj->backup;
}
