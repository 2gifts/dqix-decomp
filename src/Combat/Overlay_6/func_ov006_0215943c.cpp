#if defined(jpn)
#define R(j,u) (j)
#define data_ov006_0215ffb4 data_ov006_02161318
#define data_ov006_0215ffc0 data_ov006_0216131b
#define data_ov006_0215ffc4 data_ov006_02161328
#define data_ov006_0215ffca data_ov006_02161336
#define data_ov006_0215ffe2 data_ov006_0216132e
#define data_ov006_0215fff4 data_ov006_02161346
#define func_ov006_021547c8 func_ov006_02155f30
#define func_ov006_021570fc func_ov006_02158704
#define func_ov006_0215f4dc func_ov006_021608fc
#define func_ov006_0215f740 func_ov006_02160b08
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Obj2081 {
    char unk_0[R(0x2a, 0x36)];
    short cursor_;
};

struct Obj0208203c;
struct LookupByOffset0x362_021591ecStruct;

struct AlchemyMenu {
    char unk_0[R(0xc, 0x14)];
    Obj2081* menu_;
    char unk_18[0x2c];
    short* cursor_;
    char unk_48[0x54];
    char repeat_[0x64];
    char layout_[R(0x26c, 0x264)];
    short itemCursor_;
    char unk_366[0x8];
    short group_;
    short item_;
    char unk_372[0x19];
    unsigned char count_;
    char unk_38c[0x8];
    unsigned short flags_;
};

void ClearElementFlag0x20(Obj2081* menu, int flag);
extern "C" void _Z25ClearFlagsForIds_021573c8Pv(void* layout);
extern "C" unsigned short _Z32LookupByOffset_021591ec_021591ecP34LookupByOffset0x362_021591ecStruct(LookupByOffset0x362_021591ecStruct* self);
extern "C" short _Z26FindMappedMemberId02080468Pvi(void* menu, int group);
extern "C" void func_ov006_0215f4dc(AlchemyMenu* self);
extern "C" void func_ov006_0215f740(AlchemyMenu* self);
extern "C" void _Z20ResetWithSub0208203cP11Obj0208203c(Obj0208203c* repeat);
void SetElementFlag0x40(Obj2081* menu, int group, int flag);

// USA: func_ov006_0215943c
extern "C" ARM void func_ov006_0215943c(AlchemyMenu* self) {
    ClearElementFlag0x20(self->menu_, 0);
    self->flags_ |= 0x10;
    self->item_ = -1;
    self->count_ = 0;
    _Z25ClearFlagsForIds_021573c8Pv(self->layout_);
    unsigned short size = _Z32LookupByOffset_021591ec_021591ecP34LookupByOffset0x362_021591ecStruct((LookupByOffset0x362_021591ecStruct*)self);
    self->flags_ &= ~4;
    if (size > 8)
        self->flags_ |= 4;
    self->group_ = 0x11;
    self->itemCursor_ = -1;
    if (self->itemCursor_ < 0)
        self->itemCursor_ = _Z26FindMappedMemberId02080468Pvi(self->menu_, self->group_);
    self->menu_->cursor_ = self->itemCursor_;
    func_ov006_0215f4dc(self);
    func_ov006_0215f740(self);
    _Z20ResetWithSub0208203cP11Obj0208203c((Obj0208203c*)self->repeat_);
    self->cursor_ = 0;
    SetElementFlag0x40(self->menu_, self->group_, 0);
}
