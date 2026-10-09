#include <globaldefs.h>
struct ZeroStruct { int pointer, value; unsigned char x, y, width, height; };
struct Struct02020520 { int pointer; short x, y, width, height; };
struct S_b20c { int pointer, layout; unsigned char mode; };
struct Image020e2018 { int pointer; char unknown4[6]; unsigned char width, height; };
struct Panel020e2018 {
    char unknown0[8];
    Image020e2018* image;
    char unknownC[0x24-0xc];
    ZeroStruct clipping;
    int offset, stride;
    char unknown38[2];
    unsigned char width, height;
};
struct Owner020e2018 { int buffer; Panel020e2018* panel; };
void ClearZeroStruct(ZeroStruct*);
extern "C" void _Z19ClearStruct02020520P14Struct02020520(Struct02020520*);
void ClearTwoWordsAndByte(S_b20c*);
extern "C" void _Z18SetField0_0205b220Pvi(void*, int);
extern "C" void _Z29SetFieldsAt0x4And0x8_0205b228Pvih(void*, int, unsigned char);
extern "C" void func_0205b734(S_b20c*, int, int, int, int, int);
// USA: func_020e2018
extern "C" ARM void func_020e2018(Owner020e2018* owner) {
    Panel020e2018* panel = owner->panel;
    Image020e2018* image = panel->image;
    ClearZeroStruct(&panel->clipping);
    panel->clipping.pointer = image->pointer;
    panel->clipping.value = 0;
    panel->clipping.x = 0;
    panel->clipping.y = 0;
    panel->clipping.width = image->width - 4;
    panel->clipping.height = image->height - 4;
    int width = owner->panel->width - 4;
    if (width <= panel->clipping.width) panel->clipping.width = width;
    int height = owner->panel->height - 4;
    if (height <= panel->clipping.height) panel->clipping.height = height;
    Struct02020520 layout;
    _Z19ClearStruct02020520P14Struct02020520(&layout);
    layout.width = image->width;
    layout.height = image->height;
    S_b20c destination;
    ClearTwoWordsAndByte(&destination);
    _Z18SetField0_0205b220Pvi(&destination, owner->buffer + (owner->panel->offset + owner->panel->stride));
    _Z29SetFieldsAt0x4And0x8_0205b228Pvih(&destination, (int)&layout, 1);
    func_0205b734(&destination, 0, 0, panel->clipping.width, panel->clipping.height, 1);
}
