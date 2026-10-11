#include <globaldefs.h>

struct SubStruct1c_02232d64 { unsigned char pad[0x1c]; unsigned char field1c; };
struct StateCC0_02232d64 { unsigned char field0; unsigned char pad[3]; SubStruct1c_02232d64* ptr4; };
extern StateCC0_02232d64 data_ov031_02290cc0;
extern "C" void func_ov031_02236878(int a);
extern "C" void func_ov031_02232ce8(void);

// USA: func_ov031_02232d64
// JPN: func_ov031_02233544
extern "C" ARM void func_ov031_02232d64(int code) {
    int cont = 1;

    switch (data_ov031_02290cc0.field0) {
    case 0:
        data_ov031_02290cc0.ptr4->field1c = 0;
        if (code == 0) data_ov031_02290cc0.field0 = 2;
        else if (code == 2) data_ov031_02290cc0.field0 = (unsigned char)cont;
        else if (code == 1) data_ov031_02290cc0.field0 = 3;
        else data_ov031_02290cc0.field0 = 4;
        break;
    case 1:
        data_ov031_02290cc0.ptr4->field1c = (unsigned char)cont;
        if (code == 0) data_ov031_02290cc0.field0 = 0;
        else if (code == 2) data_ov031_02290cc0.field0 = 2;
        else if (code == 1) data_ov031_02290cc0.field0 = 3;
        else data_ov031_02290cc0.field0 = 5;
        break;
    case 2:
        data_ov031_02290cc0.ptr4->field1c = 2;
        if (code == 0) data_ov031_02290cc0.field0 = (unsigned char)cont;
        else if (code == 2) data_ov031_02290cc0.field0 = 0;
        else if (code == 1) data_ov031_02290cc0.field0 = 3;
        else data_ov031_02290cc0.field0 = 6;
        break;
    case 3: {
        unsigned char v = data_ov031_02290cc0.ptr4->field1c;
        int v4 = v + 4;
        if (code == 1) data_ov031_02290cc0.field0 = v4;
        else if (code == 3) data_ov031_02290cc0.field0 = v;
        else cont = 0;
        break;
    }
    case 4:
        data_ov031_02290cc0.ptr4->field1c = 0;
        if (code == 0) data_ov031_02290cc0.field0 = 6;
        else if (code == 2) data_ov031_02290cc0.field0 = 5;
        else if (code == 1) data_ov031_02290cc0.field0 = 0;
        else data_ov031_02290cc0.field0 = 3;
        break;
    case 5:
        data_ov031_02290cc0.ptr4->field1c = (unsigned char)cont;
        if (code == 0) data_ov031_02290cc0.field0 = 4;
        else if (code == 2) data_ov031_02290cc0.field0 = 6;
        else if (code == 1) data_ov031_02290cc0.field0 = (unsigned char)cont;
        else data_ov031_02290cc0.field0 = 3;
        break;
    case 6:
        data_ov031_02290cc0.ptr4->field1c = 2;
        if (code == 0) data_ov031_02290cc0.field0 = 5;
        else if (code == 2) data_ov031_02290cc0.field0 = 4;
        else if (code == 1) data_ov031_02290cc0.field0 = 2;
        else data_ov031_02290cc0.field0 = 3;
        break;
    }

    if (!cont) return;
    func_ov031_02236878(8);
    func_ov031_02232ce8();
}
