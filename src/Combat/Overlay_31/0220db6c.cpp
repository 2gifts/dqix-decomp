#include <globaldefs.h>

struct StructE53C_0220d330 {
    char pad[0x2260];
    int state;
    char pad2[0x226b - 0x2264];
    unsigned char flag226b;
    char pad3[0x2280 - 0x226c];
    short field2280;
};

extern StructE53C_0220d330* data_ov031_0224e53c;
int IssueBattleCommandSlot1_020d5004(int);
extern "C" void func_ov031_0220e7b0(void);
extern "C" void func_ov031_0220da1c(int);
extern "C" void func_ov031_0220d984(int, int, int, int);

// USA: func_ov031_0220db6c
extern "C" ARM void func_ov031_0220db6c(void) {
    StructE53C_0220d330* context = data_ov031_0224e53c;
    if (context->flag226b != 0) return;
    context->flag226b = 1;
    if (IssueBattleCommandSlot1_020d5004((int)func_ov031_0220e7b0) == 2) return;
    func_ov031_0220da1c(11);
    func_ov031_0220d984(7, 0, 0, 0x610);
}
