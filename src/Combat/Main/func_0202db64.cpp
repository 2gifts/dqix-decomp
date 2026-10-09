#include <globaldefs.h>
struct State0202db64 {
    char padding_0x0[0x10];
    int state;
    char padding_0x14[0x18];
    int field_0x2c, field_0x30, field_0x34, field_0x38;
};
struct Command0202db64 {
    char padding_0x0[0xc];
    unsigned short field_0xc, field_0xe, field_0x10, field_0x12;
    unsigned short field_0x14, field_0x16, fortune;
    char padding_0x1a[0x18];
    unsigned short field_0x32, field_0x34, field_0x36;
};
struct Ctx020d507c;
extern State0202db64 data_021015a0;
extern Command0202db64 data_02101640;
int GetOwnerDataFortuneValue();
int IssueBattleCommandSlot7(int, Ctx020d507c*);
void SetField0x48UnlessState9Or10(int);
extern "C" void _Z36CheckField2ThenSubmitOrError0202c864Pt(unsigned short*);
// USA: func_0202db64
extern "C" ARM int func_0202db64(int mode, int first, int second) {
    data_021015a0.field_0x2c = 0x340;
    data_021015a0.field_0x38 = 0x1e0;
    data_021015a0.field_0x34 = mode;
    data_021015a0.state = 3;
    data_02101640.field_0xc = first;
    data_02101640.field_0x32 = second;
    data_02101640.fortune = GetOwnerDataFortuneValue();
    data_02101640.field_0x34 = 0x1d4;
    data_02101640.field_0x36 = 0x74;
    data_02101640.field_0x10 = 3;
    data_02101640.field_0x16 = 0;
    data_02101640.field_0x12 = 0;
    data_02101640.field_0xe = 1;
    data_02101640.field_0x14 = mode == 2;
    if (mode == 0 || mode == 2 || mode == 4) {
        data_021015a0.state = 3;
        int result = IssueBattleCommandSlot7((int)_Z36CheckField2ThenSubmitOrError0202c864Pt, (Ctx020d507c*)&data_02101640);
        if (result == 2) return 1;
        SetField0x48UnlessState9Or10(result);
        data_021015a0.state = 9;
        return 0;
    }
    return 0;
}
