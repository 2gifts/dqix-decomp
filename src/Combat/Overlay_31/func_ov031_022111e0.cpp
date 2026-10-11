#include <globaldefs.h>

void SetGlobal0224e598IfNotNine_02211864(int a, int b);
extern "C" int func_ov031_022113c0(void);
void MarkGlobal0224e580ContextReady_0220f4a0(void);
void MarkGlobal0224e588ContextReady_022101c4(void);

struct StateObj022111e0 {
    int field0;
    void* field4;
    char pad[0x34];
    void* field3c;
};
extern StateObj022111e0* data_ov031_0224e590;

// USA: func_ov031_022111e0  (semantic: ActivateStateIfReady_022111e0)
extern "C" ARM int func_ov031_022111e0(void) {
    if (data_ov031_0224e590 == NULL) {
        SetGlobal0224e598IfNotNine_02211864(9, 9 - 0xb);
        return 0;
    }
    if (func_ov031_022113c0() != 0) return 0;
    if (data_ov031_0224e590->field4 == 0 && data_ov031_0224e590->field3c == 0) {
        SetGlobal0224e598IfNotNine_02211864(9, 9 - 0xb);
        return 0;
    }
    MarkGlobal0224e580ContextReady_0220f4a0();
    MarkGlobal0224e588ContextReady_022101c4();
    data_ov031_0224e590->field0 = 2;
    return 1;
}
