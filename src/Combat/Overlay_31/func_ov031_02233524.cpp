#include <globaldefs.h>

struct MenuRange02233524 { unsigned short left; unsigned short top; unsigned short right; unsigned short bottom; };
struct MenuRangeTable02233524 { union { MenuRange02233524 ranges[4]; unsigned char rangeBytes[32]; }; };
struct MenuValue02233524 { unsigned short value; unsigned short field_0x2[3]; };
struct MenuValueTable02233524 { MenuValue02233524 entries[4]; };
struct MenuSelection02233524 { unsigned char field_0x0; signed char selected; unsigned char field_0x2; unsigned char field_0x3; int field_0x4; };
extern MenuRangeTable02233524 data_ov031_02249158[];
extern MenuValueTable02233524 data_ov031_02249198[];
extern MenuValueTable02233524 data_ov031_0224919a[];
extern MenuValueTable02233524 data_ov031_0224919c[];
extern MenuValueTable02233524 data_ov031_0224919e[];
extern MenuSelection02233524 data_ov031_02290cc8;
int TestFieldRestBits_02227570(unsigned int);
void SetField16IfMinusOne_02222e20(int);
int CheckMaskAgainstField32_0223d354(int);
extern "C" int func_ov031_0223d49c(MenuRange02233524*);
extern "C" void func_ov031_022237dc(unsigned short, unsigned short, unsigned short, unsigned short);
extern "C" int func_ov031_0223d394(int);
extern "C" void func_ov031_022338b4(int);

// USA: func_ov031_02233524
extern "C" ARM void func_ov031_02233524(void) {
    unsigned int rangeIndex = 0;
    unsigned int rangeOffset = 0;
    do {
        MenuRange02233524* range = (MenuRange02233524*)&data_ov031_02249158[TestFieldRestBits_02227570(1)].rangeBytes[rangeOffset];
        if (func_ov031_0223d49c(range)) {
            SetField16IfMinusOne_02222e20(1);
            data_ov031_02290cc8.selected = rangeIndex;
            func_ov031_022237dc(
                data_ov031_02249198[TestFieldRestBits_02227570(1)].entries[data_ov031_02290cc8.selected].value,
                data_ov031_0224919c[TestFieldRestBits_02227570(1)].entries[data_ov031_02290cc8.selected].value,
                data_ov031_0224919a[TestFieldRestBits_02227570(1)].entries[data_ov031_02290cc8.selected].value,
                data_ov031_0224919e[TestFieldRestBits_02227570(1)].entries[data_ov031_02290cc8.selected].value);
            return;
        }
        ++rangeIndex;
        rangeOffset += sizeof(MenuRange02233524);
    } while (rangeIndex < 4);
    if (CheckMaskAgainstField32_0223d354(1)) {
        SetField16IfMinusOne_02222e20(1);
        return;
    }
    if (CheckMaskAgainstField32_0223d354(2)) {
        SetField16IfMinusOne_02222e20(0);
        return;
    }
    if (func_ov031_0223d394(0x40)) { func_ov031_022338b4(1); return; }
    if (func_ov031_0223d394(0x80)) { func_ov031_022338b4(3); return; }
    if (func_ov031_0223d394(0x20)) { func_ov031_022338b4(0); return; }
    if (func_ov031_0223d394(0x10)) func_ov031_022338b4(2);
}
