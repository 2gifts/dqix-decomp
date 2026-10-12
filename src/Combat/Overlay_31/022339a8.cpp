#include <globaldefs.h>

extern unsigned char data_ov031_02249114[4];
extern unsigned char data_ov031_02290cc8[];
extern "C" void func_ov031_02234ff8(int, int, int);

// USA: func_ov031_022339a8
extern "C" ARM void func_ov031_022339a8(void) {
    unsigned char* cursor;
    unsigned char values[4];
    cursor = values;
    ++cursor;
    unsigned char firstValue = data_ov031_02249114[0];
    unsigned char secondValue = data_ov031_02249114[1];
    unsigned char thirdValue = data_ov031_02249114[2];
    unsigned char fourthValue = data_ov031_02249114[3];
    values[0] = firstValue;
    values[1] = secondValue;
    values[2] = thirdValue;
    values[3] = fourthValue;
    signed char index = *(signed char*)(data_ov031_02290cc8 + 1);
    unsigned char selected = (cursor - 1)[index];
    int destination = *(int*)(data_ov031_02290cc8 + 4);
    func_ov031_02234ff8(destination, selected, selected);
}
