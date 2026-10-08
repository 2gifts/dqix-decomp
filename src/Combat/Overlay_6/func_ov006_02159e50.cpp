#include <globaldefs.h>

struct Obj2081;
struct Obj0208203c;
struct Obj0205eaa0;
struct Obj020e25e8;

struct AlchemyMenu {
    char unk_0[0x14];
    Obj2081* menu_;
    Obj020e25e8* choice_;
    char unk_1c[0x28];
    short* cursor_;
    char unk_48[0x54];
    char repeat_[0x2d0];
    short choiceCursor_;
    short group_;
    char unk_370[0xbc];
    signed char arrowTimer_;
};

extern "C" unsigned char func_ov006_02158a28(AlchemyMenu* self);
extern "C" unsigned char func_ov006_02158b78(AlchemyMenu* self);
int TestFlag0SetAndFlag1Clear(unsigned short* pad, int buttons);
unsigned char DispatchWithShortB4_0205eaa0(Obj0205eaa0* sound, int effect, int unk);
void CallFunc0204c804OnMatchingKey(Obj2081* menu, int group);
void ResetWithSub0208203c(Obj0208203c* repeat);
void ResetSelectionState020e25e8(Obj020e25e8* choice);

extern "C" unsigned short data_02114e30[];
extern "C" char data_02108760[];

// USA: func_ov006_02159e50
extern "C" ARM signed char func_ov006_02159e50(AlchemyMenu* self) {
    signed char result = 0;
    self->arrowTimer_ = 0;
    self->cursor_ = &self->choiceCursor_;
    if (func_ov006_02158a28(self) || TestFlag0SetAndFlag1Clear(data_02114e30, 0x200)) {
        DispatchWithShortB4_0205eaa0((Obj0205eaa0*)data_02108760, 1, 0);
        result = -1;
        if (self->choiceCursor_ == 0x22)
            result = 1;
    } else if (func_ov006_02158b78(self)) {
        result = -1;
    }
    if (result != 0) {
        CallFunc0204c804OnMatchingKey(self->menu_, self->group_);
        ResetWithSub0208203c((Obj0208203c*)self->repeat_);
        self->cursor_ = 0;
    }
    if (self->choice_ != 0 && result != 0)
        ResetSelectionState020e25e8(self->choice_);
    return result;
}
