#include <globaldefs.h>

extern "C" unsigned int func_ov027_021dcee8(unsigned int r0);
int CallFunc020d4fa4Zero_020d4f7c(int a, int b, int c);
void* SetBattleContextField0xc8IfIdle_020d472c(void* p);
void IssueIdleBattleCommand_021db490(void);

struct Ctx021dc96c {
    unsigned short field0;
    unsigned char pad0[4 - 2];
    unsigned int field4;
    char* field8;
    char* fieldc;
};

extern Ctx021dc96c data_ov027_021e33e0;

// USA: func_ov027_021dc96c  (semantic: PollBattleCommandState_021dc96c)
extern "C" ARM int func_ov027_021dc96c(void) {
    *(unsigned short*)(data_ov027_021e33e0.field8 + 0x500 + 0x28) = 0;
    *(unsigned short*)(data_ov027_021e33e0.field8 + 0x500 + 0x2a) = 0;
    *(unsigned short*)(data_ov027_021e33e0.field8 + 0x500 + 0x26) = 0;
    *(unsigned short*)(data_ov027_021e33e0.field8 + 0x500 + 0x48) = 0;
    func_ov027_021dcee8(0xa);

    if (*(int*)(data_ov027_021e33e0.fieldc + 0x1000 + 0x320) == 0) {
        int r;
        do {
            r = CallFunc020d4fa4Zero_020d4f7c(data_ov027_021e33e0.field4, *(int*)(data_ov027_021e33e0.field8 + 0x508), data_ov027_021e33e0.field0);
        } while (r == 4);
        if (r != 2) return 8;
        void* p = *(void**)(data_ov027_021e33e0.field8 + 0x508);
        SetBattleContextField0xc8IfIdle_020d472c(p);
        data_ov027_021e33e0.field8[0x50d] = 1;
        return 0;
    }

    void* p = *(void**)(data_ov027_021e33e0.field8 + 0x508);
    SetBattleContextField0xc8IfIdle_020d472c(p);
    data_ov027_021e33e0.field8[0x50d] = 1;
    IssueIdleBattleCommand_021db490();
    return 0;
}
