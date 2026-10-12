#include <globaldefs.h>

struct SelectionModeState {
    unsigned char padding[0x11d];
    unsigned char mode;
};
struct SelectionModeCoordinate {
    unsigned short x;
    unsigned short y;
};
extern SelectionModeState* data_ov031_02250bfc;
extern const SelectionModeCoordinate data_ov031_02248a0c[];
static inline const SelectionModeCoordinate* SelectionCoordinate(int index) {
    return &data_ov031_02248a0c[index];
}
extern "C" void func_ov031_02224ca4(int, int, int);
extern "C" void func_ov031_02224fa4(int, int);

// USA: func_ov031_02224f20
extern "C" ARM void func_ov031_02224f20(int mode) {
    int index;
    int first = 0;
    int second = 0;
    index = 0;
    int offset = 0;
    data_ov031_02250bfc->mode = mode;
    do {
        func_ov031_02224ca4(mode, index, SelectionCoordinate(offset)->y);
        ++index;
        offset += 12;
    } while (index < 4);
    if (mode == 2) first = 1;
    else if (mode == 1) second = 1;
    func_ov031_02224fa4(47, first);
    func_ov031_02224fa4(48, second);
}
