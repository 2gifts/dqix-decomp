#include <globaldefs.h>

struct Selection022339a8 {
    unsigned char field0;
    signed char selected;
    short field2;
    void* target;
};
extern Selection022339a8 data_ov031_02290cc8;
extern unsigned char data_ov031_02249114[4] __attribute__((aligned(4)));
extern "C" void func_ov031_02234ff8(void*, int, int);

// USA: func_ov031_022339a8
extern "C" ARM void func_ov031_022339a8() {
    unsigned char values[4];
    unsigned char* lookup = values;
    values[0] = data_ov031_02249114[0];
    values[1] = data_ov031_02249114[1];
    values[2] = data_ov031_02249114[2];
    values[3] = data_ov031_02249114[3];
    int value = lookup[data_ov031_02290cc8.selected];
    func_ov031_02234ff8(data_ov031_02290cc8.target, value, value);
}
