#include <globaldefs.h>
#include "Resource/Script.h"

struct Data_ov017_021d8438 {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char pad3;
    int fields[];
};
extern struct Data_ov017_021d8438 data_ov017_021d8438;

struct Data_ov017_021d7c54 {
    signed char byte0;
    signed char byte1;
};
extern struct Data_ov017_021d7c54 data_ov017_021d7c54;

extern "C" Script::OpcodeLookupEntry data_ov017_021d7c58[];

// USA: func_ov017_021ba810
extern "C" ARM int func_ov017_021ba810(const void* code, unsigned int length, int id, int a3, int a4, int a5, int a6) {
    if (id < 0 || id > 999) {
        return 0;
    }
    data_ov017_021d8438.fields[0] = a3;
    data_ov017_021d8438.fields[6] = id;
    data_ov017_021d8438.fields[1] = a4;
    data_ov017_021d8438.fields[3] = 0;
    data_ov017_021d8438.fields[4] = 0;
    data_ov017_021d8438.fields[5] = a5;
    data_ov017_021d8438.fields[7] = a6;
    data_ov017_021d8438.byte2 = 0;
    data_ov017_021d7c54.byte0 = -1;
    data_ov017_021d8438.byte0 = 0;
    data_ov017_021d8438.byte1 = 0;
    data_ov017_021d8438.fields[2] = 0;
    data_ov017_021d7c54.byte1 = -1;
    Script script;
    script.Initialize();
    script.SetOpcodeLookup(data_ov017_021d7c58);
    script.Load(code, length);
    script.Execute();
    if (data_ov017_021d8438.fields[3] != 0) {
        return data_ov017_021d8438.fields[3];
    }
    return data_ov017_021d8438.fields[4];
}
