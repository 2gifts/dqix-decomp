#include <globaldefs.h>

struct Struct_0205c53c;
struct Struct_0205ba68;
struct Node0205bacc;
struct Struct_0205bcdc;

struct MenuList {
    int unk_0;
    int active_;
    char unk_8[0x50 - 0x8];
};

struct MenuWindow {
    int unk_0;
    MenuList listA_;
    MenuList listB_;
    char unk_a4[0xa8 - 0xa4];
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
    char unk_e14[0xee4 - 0xe14];
    MenuWindow window_;
    char unk_f9c[0x3dbb - 0xee4 - sizeof(MenuWindow)];
    signed char slot_;
    char unk_3dbc[0x3ddc - 0x3dbc];
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
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);

// USA: func_ov005_02159904
extern "C" ARM void func_ov005_02159904(EquipmentMenu* self) {
    MenuWindow* window = self->GetWindow();
    _Z23InitChannelPair0205c53cP15Struct_0205c53c((Struct_0205c53c*)window);
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
    window = self->GetWindow();
    window->x_ = 0xc;
    window->y_ = 8;
    window->width_ = 0xa;
    window->height_ = 0xe;
    window->unk_b7 = 0xa;
    window->visible_ = 1;
    window->unk_b5 = 0;
    window->unk_b6 = 0;
    memset(self->textBuffer_, 0, 0x960);
    func_ov005_02159a30(self, self->textBuffer_, 0);
    func_0205d304(window, self->textBuffer_, 0, 1, 0, 0, 0, 0);
}
