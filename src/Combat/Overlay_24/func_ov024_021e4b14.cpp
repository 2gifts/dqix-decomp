#include <globaldefs.h>

struct Rec_021e4b14 {
    char pad0[0x18];
    unsigned int effectType : 5;
    unsigned int rest : 27;
};

struct Act_021e4b14 {
    virtual void Vtbl0();
    char pad4[8];
    int fc;
};

typedef unsigned long long (Act_021e4b14::*Handler_021e4b14)(int a, int b, Rec_021e4b14* rec, int d);

extern "C" void _Z28SetFirstEmptySlot48_021eb4e4P24SlotArrayStruct_021eb4e4i(Act_021e4b14* self, int val);

extern unsigned int data_ov024_02200144[];
extern Handler_021e4b14 data_020e6d5c;
extern Handler_021e4b14 data_ov024_021ff450[0x17];

// USA: func_ov024_021e4b14
extern "C" ARM unsigned long long func_ov024_021e4b14(Act_021e4b14* self, int a, int b, Rec_021e4b14* rec, int d) {
    if (!(data_ov024_02200144[2] & 1)) {
        data_ov024_021ff450[0] = data_020e6d5c;
        data_ov024_021ff450[3] = data_020e6d5c;
        data_ov024_02200144[2] |= 1;
    }
    if (rec->effectType >= 0x17) return 0;
    if (data_ov024_021ff450[rec->effectType] == 0) return 0;
    _Z28SetFirstEmptySlot48_021eb4e4P24SlotArrayStruct_021eb4e4i(self, self->fc);
    return (self->*data_ov024_021ff450[rec->effectType])(a, b, rec, d);
}
