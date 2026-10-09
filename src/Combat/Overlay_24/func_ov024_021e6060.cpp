#include <globaldefs.h>

struct Rec_021e6060 {
    char pad0[0x2c];
    unsigned int f2c_lo : 10;
    unsigned int kind : 4;
    unsigned int f2c_hi : 18;
};

struct Act_021e6060 {
    virtual void Vtbl0();
};

typedef void (Act_021e6060::*Handler_021e6060)(int id, Rec_021e6060* rec, int amount);

extern unsigned int data_ov024_02200144[];
extern Handler_021e6060 data_020e6d5c;
extern Handler_021e6060 data_ov024_021ff3f8[0xb];

// USA: func_ov024_021e6060
extern "C" ARM void func_ov024_021e6060(Act_021e6060* self, int id, Rec_021e6060* rec, int amount) {
    if (!(data_ov024_02200144[1] & 1)) {
        data_ov024_021ff3f8[0] = data_020e6d5c;
        data_ov024_021ff3f8[7] = data_020e6d5c;
        data_ov024_02200144[1] |= 1;
    }
    if (rec->kind >= 0xb) return;
    if (data_ov024_021ff3f8[rec->kind] == 0) return;
    (self->*data_ov024_021ff3f8[rec->kind])(id, rec, amount);
}
