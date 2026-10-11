#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct Struct_020401e4;
extern "C" struct Struct_020401e4* _Z20ResetElement0203ef60P15Struct_020401e4(struct Struct_020401e4* obj);

struct Data_020efd8c {
    float f0;
    float f4;
    float f8;
    int unk_c;
    int unk_10;
    float f14;
};

struct Data_021075d8 {
    float f0;
    int unk_4;
    float f8;
    float fc;
    int unk_10;
    float f14;
    float f18;
};

extern struct Data_020efd8c data_020efd8c;
extern struct Data_021075d8 data_021075d8;
extern struct Struct_020401e4 data_021075f4;

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020e5c58
extern "C" __declspec(initcode) ARM void __sinit_020e5c58(void) {
    data_021075d8.f8 = data_020efd8c.f0 + data_020efd8c.f4 + data_020efd8c.f8 + data_020efd8c.f14;
    data_021075d8.f0 = data_021075d8.fc + data_020efd8c.f0;
    float partial = data_021075d8.f0 + data_020efd8c.f4;
    float addend = data_020efd8c.f8;
    data_021075d8.f18 = partial;
    data_021075d8.f14 = partial + addend;
    _Z20ResetElement0203ef60P15Struct_020401e4(&data_021075f4);
}
