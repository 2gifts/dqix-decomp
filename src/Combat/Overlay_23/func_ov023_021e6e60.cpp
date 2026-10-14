#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct0205cf1c;
struct Struct_0205ba68;
struct Node0205bacc;
struct Struct_0205bcdc {
    int count_; int pages_; char pad8[0x40 - 8];
    unsigned char firstFlag_; unsigned char secondFlag_; char pad42[0x50 - 0x42];
};
struct Struct_0205c53c {
    int field0_;
    Struct_0205bcdc selection_;
    Struct_0205bcdc scrolling_;
};
struct SelectionScreen {
#if defined(jpn)
    char pad0[0x90]; Struct_0205c53c channels_;
#else
    char pad0[0xac]; Struct_0205c53c channels_;
#endif

#if defined(jpn)
    char pad150[0x1341 - 0x134]; unsigned char mode_;
#else
    char pad150[0x1371 - 0x150]; unsigned char mode_;
#endif

#if defined(jpn)
    char pad1372[0x1368 - 0x1342]; unsigned char dirty_;
#else
    char pad1372[0x13a0 - 0x1372]; unsigned char dirty_;
#endif

#if defined(jpn)
    char pad13A1[0x141c - 0x1369];
#else
    char pad13A1[0x13c4 - 0x13a1];
#endif

    unsigned short shortCount_ : 5; unsigned short longCount_ : 11;
#if defined(jpn)
    char pad13C6[0x142c - 0x141e];
#else
    char pad13C6[0x13d4 - 0x13c6];
#endif

    int selected1_; int selected2_; int selected3_; int selected4_; int selected5_;
    int selected10_; int selected11_; int selected12_; int selected13_; int selected6_;
};
void ClearChannelAFlag0205cf10(void*);
void ClearFlagByte0205cf1c(Struct0205cf1c*);
void InitChannelPair0205c53c(Struct_0205c53c*);
void SetupPointerTable0205ba68(Struct_0205ba68*, int, int, int);
void SetField0AndPropagate0205bacc(Node0205bacc*, int);
void SetIndexIfValid0205bcdc(Struct_0205bcdc*, int);
extern "C" void func_0205bb04(Struct_0205bcdc*, int);

// USA: func_ov023_021e6e60
extern "C" ARM void func_ov023_021e6e60(SelectionScreen* self) {
    GameState::GetInstance();
    int columns;
    int rows;
    int pages;
    int wrap = 0;
    unsigned int count;
    int selected;
    switch (self->mode_) {
    case 1: pages = 1; count = 6; columns = 1; rows = 6; selected = self->selected1_; break;
    case 2: pages = 1; count = 4; columns = 1; rows = 4; selected = self->selected2_; break;
#if defined(jpn)
    case 3: pages = 3; columns = 2; rows = 8; count = 47; selected = self->selected3_; break;
#else
    case 3: columns = 2; rows = 8; pages = 12; count = 192; selected = self->selected3_; break;
#endif

    case 4: pages = 1; rows = 8; columns = 1; count = 8; selected = self->selected4_; break;
    case 5:
        columns = 1; count = self->shortCount_; pages = ((int)count - 1) / 9 + 1;
        rows = 9;
        if (count < 9) rows = count;
        selected = self->selected5_; break;
    case 6: pages = 1; count = 2; columns = 1; rows = 2; selected = self->selected6_; break;
    case 10: pages = 1; count = 2; columns = 1; rows = 2; selected = self->selected10_; break;
    case 11: pages = 6; columns = 1; rows = 10; count = 60; selected = self->selected11_; break;
    case 12:
        columns = 2; wrap = 1; count = self->longCount_;
        pages = ((int)count - 1) / 16 + 1;
        rows = ((int)count - 1) / 2 + 1;
        if (rows > 8) rows = 8;
        selected = self->selected12_; break;
    case 13: columns = 1; rows = 8; pages = 1; count = 8; selected = self->selected13_; break;
    default:
        ClearChannelAFlag0205cf10(&self->channels_);
        ClearFlagByte0205cf1c((Struct0205cf1c*)&self->channels_);
        return;
    }
    InitChannelPair0205c53c(&self->channels_);
    SetupPointerTable0205ba68((Struct_0205ba68*)&self->channels_.selection_, columns, rows, wrap);
    SetupPointerTable0205ba68((Struct_0205ba68*)&self->channels_.scrolling_, columns, rows, wrap);
    SetField0AndPropagate0205bacc((Node0205bacc*)&self->channels_.selection_, count);
    SetField0AndPropagate0205bacc((Node0205bacc*)&self->channels_.scrolling_, count);
    self->channels_.selection_.pages_ = pages;
    self->channels_.scrolling_.pages_ = pages;
    SetIndexIfValid0205bcdc(&self->channels_.selection_, selected);
    func_0205bb04(&self->channels_.scrolling_, selected);
    self->channels_.scrolling_.firstFlag_ = 1;
    self->channels_.scrolling_.secondFlag_ = 1;
    self->dirty_ = 0;
}
