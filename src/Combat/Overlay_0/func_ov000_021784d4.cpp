#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"
#include "GameState/GameState.h"

#if defined(jpn)
#define func_ov000_021784d4 func_ov000_021799a0
#endif

struct Panel_021784d4 {
    char pad_0x0[0xa0];
    short width;
    short height;
    short tileX;
    short tileY;
    short field_0xa8;
    short field_0xaa;
    short field_0xac;
    short field_0xae;
    char pad_0xb0;
    unsigned char field_0xb1;
};

struct Owner_021784d4 {
    char pad_0x0[0x79];
    unsigned char mode;
    char pad_0x7a[0x10e];
    struct Panel_021784d4 panel;
};

struct InStruct_021784d4 {
    char pad[0x44];
    int x;
    int y;
};

extern "C" int _Z26GetGlobalField0x1c020421a0v();

extern "C" void func_ov000_0217c638(struct Owner_021784d4* obj, int a, int b);
extern "C" void func_ov000_02178648(struct Owner_021784d4* obj, void* buf);
#if defined(jpn)
extern "C" void func_0205d304(struct Panel_021784d4* panel, void* buf, int a, int b, int c, int d, int e);
#else
extern "C" void func_0205d304(struct Panel_021784d4* panel, void* buf, int a, int b, int c, int d, int e, int f);
#endif

// USA: func_ov000_021784d4
extern "C" ARM void func_ov000_021784d4(struct Owner_021784d4* obj, struct InStruct_021784d4* in, int arg2, int arg3) {
    if (in == 0) {
        return;
    }
    int x = in->x;
    int y = in->y;
    GetPtrField0x2a04(GameState::GetInstance());
    unsigned char mode = obj->mode;
    func_ov000_0217c638(obj, arg2, arg3);
    struct Panel_021784d4* panel = &obj->panel;
#if defined(jpn)
    panel->width = 0xa;
#else
    panel->width = 0x10;
#endif
    panel->height = 1;
    panel->tileX = (x >> 3) + 9;
    panel->tileY = (y >> 3) + 1;
    panel->field_0xa8 = 0xc;
    panel->field_0xaa = 0xa;
    panel->field_0xac = 0xa;
    panel->field_0xae = 0xd;
    if (mode == 2) {
        panel->field_0xa8 = 0xc;
        panel->field_0xaa = 0xa;
    }
    if (mode == 3) {
        panel->field_0xa8 = 0xc;
        panel->field_0xaa = 8;
    }
    if (mode == 4) {
        panel->field_0xa8 = 0xc;
        panel->field_0xaa = 4;
        panel->field_0xac = 0xa;
        panel->field_0xae = 0xb;
    }
    panel->field_0xb1 = 8;
#if defined(jpn)
    void* buf = *(void**)((char*)_Z26GetGlobalField0x1c020421a0v() + 0x28);
#else
    void* buf = *(void**)((char*)_Z26GetGlobalField0x1c020421a0v() + 0x5c);
#endif
#if defined(jpn)
    memset(buf, 0, 0x800);
#else
    memset(buf, 0, 0x960);
#endif
    func_ov000_02178648(obj, buf);
#if defined(jpn)
    func_0205d304(&obj->panel, buf, 0, 1, 0, 1, 0);
#else
    func_0205d304(panel, buf, 0, 1, 0, 1, 0, 0);
#endif
}
