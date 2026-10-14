#include <globaldefs.h>

struct BattleState0223a0fc {
    unsigned char field_0x0[0xc];
    unsigned short field_0xc;
    unsigned short enabled;
    unsigned short field_0x10;
    unsigned short field_0x12;
    unsigned short alternate;
    unsigned short field_0x16;
    unsigned short fortune;
    unsigned char field_0x1a[0x18];
    unsigned short field_0x32;
    unsigned short width;
    unsigned short height;
    unsigned char field_0x38[8];
    int mode;
    int selection;
    unsigned char field_0x48[0x1258];
    int field_0x12a0;
    int field_0x12a4;
};
struct BattleGlobals0223a0fc { void (*report)(int, const char*, ...); BattleState0223a0fc* state; };
extern BattleGlobals0223a0fc data_ov031_02290d18 __attribute__((aligned(4)));
extern const char data_ov031_0224c41c[];
extern const char data_ov031_0224c434[];
extern const char data_ov031_0224c47c[];
extern "C" void func_020c9be0(void);
extern "C" void func_ov031_02239368(int);
extern "C" int func_ov031_02239404(void);
unsigned short GetOwnerDataFortuneValue_020d4b58(void);

// USA: func_ov031_0223a0fc
extern "C" ARM int func_ov031_0223a0fc(int selection, int first, int second) {
    (data_ov031_02290d18.state->mode == 1) || (func_020c9be0(), 0);
    data_ov031_02290d18.state->field_0x12a4 = 0x180;
    data_ov031_02290d18.state->field_0x12a0 = 0xe0;
    if (data_ov031_02290d18.report) data_ov031_02290d18.report(0x8000000, data_ov031_0224c41c, data_ov031_02290d18.state->field_0x12a4);
    if (data_ov031_02290d18.report) data_ov031_02290d18.report(0x8000000, data_ov031_0224c434, data_ov031_02290d18.state->field_0x12a0);
    data_ov031_02290d18.state->selection = selection;
    func_ov031_02239368(3);
    data_ov031_02290d18.state->field_0xc = first;
    data_ov031_02290d18.state->field_0x32 = second;
    data_ov031_02290d18.state->fortune = GetOwnerDataFortuneValue_020d4b58();
    data_ov031_02290d18.state->width = 0xd0;
    data_ov031_02290d18.state->height = 0x44;
    data_ov031_02290d18.state->field_0x10 = 2;
    data_ov031_02290d18.state->field_0x16 = 0;
    data_ov031_02290d18.state->field_0x12 = 0;
    data_ov031_02290d18.state->enabled = 1;
    data_ov031_02290d18.state->alternate = selection == 2;
    if (selection == 0 || selection == 2 || selection == 4) return func_ov031_02239404();
    if (data_ov031_02290d18.report) data_ov031_02290d18.report(0x8000000, data_ov031_0224c47c, selection);
    return 0;
}
