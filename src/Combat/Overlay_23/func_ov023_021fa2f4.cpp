#include <globaldefs.h>

class MenuTexts_021fa2f4
{
public:
    unsigned short type_;
    unsigned short id_;
    unsigned short heap_;
    unsigned short vramState_;
    unsigned char flags_;
    char unk_d[3];
    const char* file_;
    void* prev_;
    void* next_;
    int state_;

    virtual void Update(void* script);
};

typedef int (MenuTexts_021fa2f4::*TextsState_021fa2f4)(void* script);

extern unsigned int data_ov023_021fff28;
extern TextsState_021fa2f4 data_020e6d5c;
extern TextsState_021fa2f4 data_ov023_021fea0c[4];
extern TextsState_021fa2f4 data_ov023_021fea0c_dup[4];

// USA: func_ov023_021fa2f4
extern "C" ARM void func_ov023_021fa2f4(MenuTexts_021fa2f4* self, void* script)
{
    if (!(data_ov023_021fff28 & 1))
    {
        data_ov023_021fea0c_dup[3] = data_020e6d5c;
        data_ov023_021fff28 |= 1;
    }
    self->state_ = (self->*data_ov023_021fea0c[self->state_])(script);
}
