#include <globaldefs.h>
#include "System/RequestSubmission.h"

#if defined(jpn)
#define data_021023c0 data_02102100
#define data_020ef7a8 data_020ef698
#endif

struct Input0202d3e0 { unsigned short field_0x00, status, command; };
struct State0202d3e0 {
    char reserved[0x10];
    int state;
    int field_0x14;
    void (*callback)(Input0202d3e0*);
    char reserved_0x1c[0x34 - 0x1c];
    int mode;
};
extern State0202d3e0 data_021015a0 __attribute__((aligned(4)));
struct BattleEffectContext;
extern BattleEffectContext data_021023c0, data_02102be0;
extern int data_020ef7a8;
void SetField0x48UnlessState9Or10(int);
extern "C" void func_0202dd98();

// USA: func_0202d3e0
extern "C" ARM void func_0202d3e0(Input0202d3e0* input) {
    if (input->status != 0) {
        if (input->status != 15 && input->status != 9 && input->status != 13) {
            SetField0x48UnlessState9Or10(input->status);
            data_021015a0.state = 9;
        }
    } else {
        switch (input->command) {
        case 10:
            if (data_021015a0.mode == 3) {
                if (data_021015a0.state == 6) break;
                if (data_021015a0.state == 4) {
                    int submitted;
                    if (data_021015a0.state == 6) submitted = 1;
                    else if (data_021015a0.state != 4) submitted = 0;
                    else {
                        data_021015a0.state = 6;
                        int result = InvokeWithFullMaskType2(&data_021023c0, 13);
                        if (result == 0) submitted = 1;
                        else { SetField0x48UnlessState9Or10(result); submitted = 0; }
                    }
                    if (!submitted) func_0202dd98();
                    break;
                }
            } else if (data_021015a0.mode == 5) {
                int mask = 15;
                int result = func_020d5d34(&data_02102be0, 13, mask, 0x74, data_020ef7a8);
                if (result) {
                    SetField0x48UnlessState9Or10(result);
                    func_0202dd98();
                } else {
                    data_021015a0.state = 5;
                    if (data_021015a0.callback) data_021015a0.callback(input);
                }
                break;
            }
            data_021015a0.state = 4;
            if (data_021015a0.callback) data_021015a0.callback(input);
            break;
        case 11:
        case 12:
        case 13:
            break;
        }
    }
}
