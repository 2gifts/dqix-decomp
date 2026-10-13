#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
#define func_ov000_021787b8 func_ov000_02179c68
#endif

struct Struct_0205ba68;
struct Node0205bacc;

struct TextWorkspace {
#if defined(jpn)
    char unknown0[0x28];
#else
    char unknown0[0x5c];
#endif
    char* textBuffer;
};
struct BattleMenuPanel {
    char unknown0[0xa0];
    short width;
    short height;
    short tileX;
    short tileY;
    short fieldA8;
    short fieldAA;
    short fieldAC;
    short fieldAE;
    unsigned char unknownB0;
    unsigned char elementId;
    char unknownB2[0xa];
};
struct GroupSelection {
    int count;
    int pages;
    char unknown8[0x48];
};
struct BattleTargetMenu {
    char unknown0[0x188];
    BattleMenuPanel panel;
    GroupSelection groups;
};

extern "C" TextWorkspace* _Z26GetGlobalField0x1c020421a0v();
extern "C" void _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii(struct Struct_0205ba68* s, int a, int b, int mode);
extern "C" void _Z29SetField0AndPropagate0205baccP12Node0205bacci(struct Node0205bacc* s, int val);
extern "C" void func_0205bb04(void* s, int n);
extern "C" int func_ov000_0217538c(void* objRaw);
extern "C" int func_ov000_021753d8(void* objRaw, int targetIndex);
extern "C" void func_ov000_0217ab8c(void* obj, int a, int b);
extern "C" void func_ov000_02178938(void* obj, void* in, int b, void* buf);
#if defined(jpn)
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g);
#else
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif

struct InStruct_021787b8 {
    char pad0[0x1d];
    signed char position;
    char pad1e[0x44 - 0x1e];
    int x;
    int y;
};

// USA: func_ov000_021787b8
extern "C" ARM void func_ov000_021787b8(BattleTargetMenu* menu, struct InStruct_021787b8* in, int mode, int arg3) {
    if (in == 0) {
        return;
    }
    int x = in->x;
    int y = in->y;
    int groupCount = func_ov000_0217538c(menu);
    int group = func_ov000_021753d8(menu, in->position);
    func_ov000_0217ab8c(in, mode, arg3);
    BattleMenuPanel* panel = &menu->panel;
#if defined(jpn)
    panel->width = 1;
#else
    panel->width = 0x10;
#endif
    panel->height = 1;
    panel->tileX = (x >> 3) + 0xe;
#if defined(jpn)
    panel->tileY = (y >> 3) + 1;
#else
    panel->tileY = y >> 3;
#endif
    panel->fieldA8 = 0xc;
    panel->fieldAA = 6;
    panel->fieldAC = 0xa;
    panel->fieldAE = 0x10;
    panel->elementId = 0xe;
    _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii((struct Struct_0205ba68*)&menu->groups, 1, groupCount, 0);
    menu->groups.pages = 1;
    _Z29SetField0AndPropagate0205baccP12Node0205bacci((struct Node0205bacc*)&menu->groups, groupCount);
    func_0205bb04(&menu->groups, group);
    char* text = _Z26GetGlobalField0x1c020421a0v()->textBuffer;
#if defined(jpn)
    memset(text, 0, 0x800);
#else
    memset(text, 0, 0x960);
#endif
    func_ov000_02178938(menu, in, arg3, text);
#if defined(jpn)
    func_0205d304(panel, text, 0, 1, 0, 1, 0);
#else
    func_0205d304(panel, text, 0, 1, 0, 1, 0, 0);
#endif
}
