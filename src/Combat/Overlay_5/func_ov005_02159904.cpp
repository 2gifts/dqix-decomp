#if defined(jpn)
#define func_ov005_02159904 func_ov005_0215ade0
#define func_ov005_02159a30 func_ov005_0215af84
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

struct Struct_0205c53c;
struct Struct_0205ba68;
struct Node0205bacc;
struct Struct_0205bcdc;

struct MenuList {
    int unk_0;
    int active_;
    char unk_8[0x30 - 0x8];
};

struct MenuChannelA : MenuList {
    char unknown30[0x50 - 0x30];
};

struct MenuChannelB : MenuList {
    char unknown30[0x40 - 0x30];
};

struct MenuWindow {
    int unk_0;
    MenuChannelA listA_;
    MenuChannelB listB_;
    char unknown94[0xa0 - 0x94];
    short widthTiles;
    short heightTiles;
    short tileX;
    short tileY;
    short x_;
    short y_;
    short width_;
    short height_;
    char unk_b0;
    unsigned char visible_;
    char unk_b2[0xb5 - 0xb2];
    unsigned char unk_b5;
    unsigned char unk_b6;
    unsigned char unk_b7;
};

struct EquipmentMenu {
    char unk_0[0xe10];
    char* textBuffer_;
    char unk_e14[LOW_REGION(0xee0, 0xee4) - 0xe14];
    MenuWindow window_;
    char unk_f9c[LOW_REGION(0x3d33, 0x3dbb) - LOW_REGION(0xee0, 0xee4) - sizeof(MenuWindow)];
    signed char slot_;
    char unk_3dbc[LOW_REGION(0x3d54, 0x3ddc) - LOW_REGION(0x3d34, 0x3dbc)];
    unsigned char menuStep_;
    unsigned char menuResult_;
    signed char menuChoice_;
    unsigned char menuState_;

    MenuWindow* GetWindow() { return &window_; }
};

extern "C" void _Z23InitChannelPair0205c53cP15Struct_0205c53c(Struct_0205c53c* s);
extern "C" void _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii(Struct_0205ba68* s, int a, int count, int mode);
extern "C" void _Z29SetField0AndPropagate0205baccP12Node0205bacci(Node0205bacc* s, int val);
extern "C" void _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci(Struct_0205bcdc* s, int index);
extern "C" void func_0205bb04(void* s, int index);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" void func_ov005_02159a30(EquipmentMenu* self, char* buffer, int arg);
#if defined(jpn)
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g);
#else
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif

// USA: func_ov005_02159904
extern "C" ARM void func_ov005_02159904(EquipmentMenu* self) {
    MenuWindow* window = self->GetWindow();
    _Z23InitChannelPair0205c53cP15Struct_0205c53c((Struct_0205c53c*)window);
#if defined(jpn)
    if (self->slot_ >= 0 && self->slot_ < 8) {
    _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii((Struct_0205ba68*)&window->listA_, 1, 3, 0);
    _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii((Struct_0205ba68*)&window->listB_, 1, 3, 0);
    _Z29SetField0AndPropagate0205baccP12Node0205bacci((Node0205bacc*)&window->listA_, 3);
    _Z29SetField0AndPropagate0205baccP12Node0205bacci((Node0205bacc*)&window->listB_, 3);
    window->listA_.active_ = 1;
    window->listB_.active_ = 1;
    int choice = self->menuChoice_;
    _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci((Struct_0205bcdc*)&window->listA_, choice);
    func_0205bb04(&window->listB_, choice);
    } else {
    _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii((Struct_0205ba68*)&window->listA_, 1, 4, 0);
    _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii((Struct_0205ba68*)&window->listB_, 1, 4, 0);
    _Z29SetField0AndPropagate0205baccP12Node0205bacci((Node0205bacc*)&window->listA_, 4);
    _Z29SetField0AndPropagate0205baccP12Node0205bacci((Node0205bacc*)&window->listB_, 4);
    window->listA_.active_ = 1;
    window->listB_.active_ = 1;
    int choice = self->menuChoice_;
    _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci((Struct_0205bcdc*)&window->listA_, choice);
    func_0205bb04(&window->listB_, choice);
    }
#else
    int count = 4;
    if (self->slot_ >= 0 && self->slot_ < 8)
        count = 3;
    _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii((Struct_0205ba68*)&window->listA_, 1, count, 0);
    _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii((Struct_0205ba68*)&window->listB_, 1, count, 0);
    _Z29SetField0AndPropagate0205baccP12Node0205bacci((Node0205bacc*)&window->listA_, count);
    _Z29SetField0AndPropagate0205baccP12Node0205bacci((Node0205bacc*)&window->listB_, count);
    window->listA_.active_ = 1;
    window->listB_.active_ = 1;
    int choice = self->menuChoice_;
    _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci((Struct_0205bcdc*)&window->listA_, choice);
    func_0205bb04(&window->listB_, choice);
#endif
#if defined(jpn)
    self->window_.widthTiles = 8;
    self->window_.heightTiles = 7;
    self->window_.tileX = 0xc;
    self->window_.tileY = 9;
    self->window_.x_ = 0xc;
    self->window_.y_ = 8;
    self->window_.width_ = 0xa;
    self->window_.height_ = 0xe;
    self->GetWindow()->unk_b7 = 0xa;
    self->GetWindow()->visible_ = 1;
    self->GetWindow()->unk_b5 = 0;
    self->GetWindow()->unk_b6 = 0;
#else
    window = self->GetWindow();
    window->x_ = 0xc;
    window->y_ = 8;
    window->width_ = 0xa;
    window->height_ = 0xe;
    window->unk_b7 = 0xa;
    window->visible_ = 1;
    window->unk_b5 = 0;
    window->unk_b6 = 0;
#endif
    memset(self->textBuffer_, 0, LOW_REGION(0x800, 0x960));
    func_ov005_02159a30(self, self->textBuffer_, 0);
#if defined(jpn)
    func_0205d304(self->GetWindow(), self->textBuffer_, 0, 1, 0, 0, 0);
#else
    func_0205d304(window, self->textBuffer_, 0, 1, 0, 0, 0, 0);
#endif
}
