#include <globaldefs.h>
#include "GameState/GameState.h"

struct BattleStruct021b9bcc;
int GetField5cb8Value_02010804(char* obj);

struct Data_ov017_021d8438 {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char pad3;
    int field4;
    int field8;
    int fieldC;
    int field10;
    void* field14;
    int field18;
    char pad1c[4];
    int field20;
};
extern struct Data_ov017_021d8438 data_ov017_021d8438;

// USA: func_ov017_021b9bcc
extern "C" ARM int func_ov017_021b9bcc(int a, void* b) {
    struct BattleStruct021b9bcc* battleStruct = (struct BattleStruct021b9bcc*)GameState::GetInstance();
    int rem = a % 80;
    int day = rem / 16;
    int pos = rem % 16;
    int q = a / 80;
    int ref = data_ov017_021d8438.field8;
    if (q != ref / 80) return 0;

    if (day == 0) {
        if (pos <= data_ov017_021d8438.field18) {
            data_ov017_021d8438.field14 = b;
        } else {
            return 0;
        }
    } else if (day == 1) {
        if (pos <= data_ov017_021d8438.field20) {
            data_ov017_021d8438.field14 = b;
        } else {
            return 0;
        }
    } else if (day == 2) {
        if (a == ref) {
            data_ov017_021d8438.field14 = b;
        } else {
            return 0;
        }
    } else if (day == 3) {
        if (a == ref) {
            data_ov017_021d8438.field14 = b;
        } else {
            return 0;
        }
    } else if (day == 4) {
        int v = GetField5cb8Value_02010804((char*)battleStruct);
        if (pos <= v && pos >= data_ov017_021d8438.fieldC) {
            data_ov017_021d8438.field14 = b;
            data_ov017_021d8438.fieldC = pos;
        } else {
            return 0;
        }
    }
    return 1;
}
