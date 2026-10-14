#include <globaldefs.h>

struct Struct_0205bb84 {
    int count;
    int pages;
    int columns;
    int rows;
    int field_0x10;
    int page;
    int column;
    int row;
    int field_0x20;
    int* baseColumns;
    int* baseRows;
    int* baseSelection;
};
struct Struct_0205c4a8 : Struct_0205bb84 {};
struct Struct_0205bf3c : Struct_0205c4a8 {
    int step;
    unsigned short key;
    unsigned char rowRepeat;
    unsigned char columnRepeat;
    unsigned char countdown;
    unsigned char initialDelay;
    unsigned char repeatDelay;
    unsigned char padding3b;
    unsigned char wrapColumns;
    unsigned char wrapRows;
};
struct NavigationSteps { int values[4]; };
struct NavigationKeys { unsigned short values[5]; };
struct NavigationRepeatDirections { unsigned char values[4]; };
int TestFlag0SetAndFlag1Clear(unsigned short*, int);
int TestFlagMask(unsigned short*, int);
int TestFlagInSecondWord(unsigned short*, unsigned int);
void ResetState0205bf3c(Struct_0205bf3c*);
int ComputeScaledSum0205bb84(Struct_0205bb84*);
void AdvanceWrappedAccumulator0205c4a8(Struct_0205c4a8*, int);
extern "C" void func_0205bb04(Struct_0205bf3c*, int);
extern const NavigationKeys data_020e7db8;
extern const NavigationSteps data_020e7dc4;
extern const NavigationRepeatDirections data_020e7db0, data_020e7db4;
extern unsigned short data_02114e30;

// USA: func_0205bf58
extern "C" ARM int func_0205bf58(Struct_0205bf3c* navigation, unsigned int ticks) {
    if (navigation->count == 0) return 0;
    if (navigation->columns <= 0) return 0;
    if (navigation->rows <= 0) return 0;
    unsigned char initialDelay = navigation->initialDelay;
    unsigned char repeatDelay = navigation->repeatDelay;
    NavigationKeys keys = data_020e7db8;
    int index = 0;
    while (keys.values[index] != 0xffff && navigation->key == 0) {
        unsigned short key = keys.values[index];
        if (TestFlag0SetAndFlag1Clear(&data_02114e30, key)) {
            if (navigation->rowRepeat | navigation->columnRepeat) {
                ResetState0205bf3c(navigation);
                break;
            }
            NavigationSteps steps = data_020e7dc4;
            NavigationRepeatDirections rowRepeats = data_020e7db0;
            NavigationRepeatDirections columnRepeats = data_020e7db4;
            navigation->key = key;
            navigation->countdown = initialDelay;
            navigation->step = steps.values[index];
            navigation->rowRepeat = rowRepeats.values[index];
            navigation->columnRepeat = columnRepeats.values[index];
            if (navigation->key == 0x40 || navigation->key == 0x80) {
                int previous = navigation->row;
                navigation->row += navigation->step;
                if (navigation->wrapRows) {
                    if (navigation->rows <= navigation->row) navigation->row = 0;
                    else if (navigation->row < 0) navigation->row = navigation->rows - 1;
                    if (navigation->key == 0x40) {
                        int total = navigation->count;
                        if (total <= ComputeScaledSum0205bb84(navigation))
                            func_0205bb04(navigation, total - 1);
                    } else if (navigation->key == 0x80) {
                        if (navigation->count <= ComputeScaledSum0205bb84(navigation))
                            navigation->row = 0;
                    }
                } else {
                    if (navigation->rows <= navigation->row) navigation->row = previous;
                    else if (navigation->row < 0) navigation->row = previous;
                    if (ComputeScaledSum0205bb84(navigation) >= navigation->count)
                        navigation->row = previous;
                }
            } else if (navigation->key == 0x20 || navigation->key == 0x10) {
                int previous = navigation->column;
                navigation->column += navigation->step;
                if (navigation->columns <= navigation->column) {
                    if (navigation->wrapColumns) {
                        navigation->column = 0;
                        if (navigation->pages > 1) AdvanceWrappedAccumulator0205c4a8(navigation, 1);
                    } else {
                        if (navigation->pages == 1) navigation->column = previous;
                        else {
                            navigation->column = 0;
                            AdvanceWrappedAccumulator0205c4a8(navigation, 1);
                        }
                    }
                } else if (navigation->column < 0) {
                    if (navigation->wrapColumns) {
                        navigation->column = navigation->columns - 1;
                        if (navigation->pages > 1) AdvanceWrappedAccumulator0205c4a8(navigation, -1);
                    } else {
                        if (navigation->pages == 1) navigation->column = previous;
                        else {
                            navigation->column = navigation->columns - 1;
                            AdvanceWrappedAccumulator0205c4a8(navigation, -1);
                        }
                    }
                }
                if (ComputeScaledSum0205bb84(navigation) >= navigation->count) {
                    if (navigation->pages == 1) navigation->column = previous;
                    else {
                        navigation->column = 0;
                        AdvanceWrappedAccumulator0205c4a8(navigation, 1);
                    }
                }
            }
            return 1;
        }
        ++index;
    }
    if (navigation->rowRepeat) {
        if (TestFlagMask(&data_02114e30, 0xf0)) {
            unsigned char elapsed = ticks;
            if (elapsed < navigation->countdown) navigation->countdown -= elapsed;
            else {
                navigation->countdown = repeatDelay;
                navigation->rowRepeat = 1;
                navigation->columnRepeat = 0;
                navigation->row += navigation->step;
                if (navigation->rows <= navigation->row) navigation->row = navigation->rows - 1;
                else if (navigation->row < 0) navigation->row = 0;
                int total = navigation->count;
                if (total <= ComputeScaledSum0205bb84(navigation))
                    func_0205bb04(navigation, total - 1);
                if (navigation->key == 0x40 || navigation->key == 0x20) {
                    int total = navigation->count;
                    if (total <= ComputeScaledSum0205bb84(navigation))
                        func_0205bb04(navigation, total - 1);
                } else if (navigation->key == 0x80 || navigation->key == 0x10) {
                    if (navigation->count <= ComputeScaledSum0205bb84(navigation))
                        navigation->row = 0;
                }
            }
        }
        if (TestFlagInSecondWord(&data_02114e30, 0xf0)) ResetState0205bf3c(navigation);
        return 1;
    } else if (navigation->columnRepeat) {
        if (TestFlagMask(&data_02114e30, 0xf0)) {
            unsigned char elapsed = ticks;
            if (elapsed < navigation->countdown) navigation->countdown -= elapsed;
            else {
                navigation->countdown = repeatDelay;
                navigation->rowRepeat = 0;
                navigation->columnRepeat = 1;
                navigation->column += navigation->step;
                if (navigation->columns <= navigation->column) {
                    navigation->column = navigation->columns - 1;
                    AdvanceWrappedAccumulator0205c4a8(navigation, 1);
                } else if (navigation->column < 0) {
                    navigation->column = 0;
                    AdvanceWrappedAccumulator0205c4a8(navigation, -1);
                }
                if (ComputeScaledSum0205bb84(navigation) >= navigation->count) {
                    if (navigation->pages == 1) navigation->column = 0;
                    else {
                        navigation->column = 0;
                        AdvanceWrappedAccumulator0205c4a8(navigation, 1);
                    }
                }
            }
        }
        if (TestFlagInSecondWord(&data_02114e30, 0xf0)) ResetState0205bf3c(navigation);
        return 1;
    }
    return 0;
}
