#include <globaldefs.h>
#include <std_library_functions.h>

// Six adjacent cells in a staggered grid. A missing neighbor is represented by 255.
// The odd rows have eight cells; even rows have nine. Caller purpose is untraced.
extern "C" ARM void func_ov000_0216f82c(unsigned char* output, const int* cell)
{
    int column = *cell % 9;
    int row = *cell / 9;
    unsigned char neighbors[6];
    if (row % 2 == 0) {
        if (column == 0) {
            if (row == 0) {
                neighbors[0] = 255;
                neighbors[1] = column + (row + 1) * 9;
                neighbors[2] = 255;
                neighbors[3] = column + 1 + row * 9;
                neighbors[4] = 255;
                neighbors[5] = 255;
            } else if (row == 8) {
                neighbors[0] = 255;
                neighbors[1] = 255;
                neighbors[2] = 255;
                neighbors[3] = column + 1 + row * 9;
                neighbors[4] = 255;
                neighbors[5] = column + (row - 1) * 9;
            } else {
                neighbors[0] = 255;
                neighbors[1] = column + (row + 1) * 9;
                neighbors[2] = 255;
                neighbors[3] = column + 1 + row * 9;
                neighbors[4] = 255;
                neighbors[5] = column + (row - 1) * 9;
            }
        } else if (column == 8) {
            if (row == 0) {
                neighbors[0] = column - 1 + (row + 1) * 9;
                neighbors[1] = 255;
                neighbors[2] = column - 1 + row * 9;
                neighbors[3] = 255;
                neighbors[4] = 255;
                neighbors[5] = 255;
            } else if (row == 8) {
                neighbors[0] = 255;
                neighbors[1] = 255;
                neighbors[2] = column - 1 + row * 9;
                neighbors[3] = 255;
                neighbors[4] = column - 1 + (row - 1) * 9;
                neighbors[5] = 255;
            } else {
                neighbors[0] = column - 1 + (row + 1) * 9;
                neighbors[1] = 255;
                neighbors[2] = column - 1 + row * 9;
                neighbors[3] = 255;
                neighbors[4] = column - 1 + (row - 1) * 9;
                neighbors[5] = 255;
            }
        } else {
            if (row == 0) {
                neighbors[0] = column - 1 + (row + 1) * 9;
                neighbors[1] = column + (row + 1) * 9;
                neighbors[2] = column - 1 + row * 9;
                neighbors[3] = column + 1 + row * 9;
                neighbors[4] = 255;
                neighbors[5] = 255;
            } else if (row == 8) {
                neighbors[0] = 255;
                neighbors[1] = 255;
                neighbors[2] = column - 1 + row * 9;
                neighbors[3] = column + 1 + row * 9;
                neighbors[4] = column - 1 + (row - 1) * 9;
                neighbors[5] = column + (row - 1) * 9;
            } else {
                neighbors[0] = column - 1 + (row + 1) * 9;
                neighbors[1] = column + (row + 1) * 9;
                neighbors[2] = column - 1 + row * 9;
                neighbors[3] = column + 1 + row * 9;
                neighbors[4] = column - 1 + (row - 1) * 9;
                neighbors[5] = column + (row - 1) * 9;
            }
        }
    } else {
        if (column == 0) {
            if (row == 8) {
                neighbors[0] = 255;
                neighbors[1] = 255;
                neighbors[2] = 255;
                neighbors[3] = column + 1 + row * 9;
                neighbors[4] = column + (row - 1) * 9;
                neighbors[5] = column + 1 + (row - 1) * 9;
            } else {
                neighbors[0] = column + (row + 1) * 9;
                neighbors[1] = column + 1 + (row + 1) * 9;
                neighbors[2] = 255;
                neighbors[3] = column + 1 + row * 9;
                neighbors[4] = column + (row - 1) * 9;
                neighbors[5] = column + 1 + (row - 1) * 9;
            }
        } else if (column == 7) {
            if (row == 8) {
                neighbors[0] = 255;
                neighbors[1] = 255;
                neighbors[2] = column - 1 + row * 9;
                neighbors[3] = 255;
                neighbors[4] = column + (row - 1) * 9;
                neighbors[5] = column + 1 + (row - 1) * 9;
            } else {
                neighbors[0] = column + (row + 1) * 9;
                neighbors[1] = column + 1 + (row + 1) * 9;
                neighbors[2] = column - 1 + row * 9;
                neighbors[3] = 255;
                neighbors[4] = column + (row - 1) * 9;
                neighbors[5] = column + 1 + (row - 1) * 9;
            }
        } else if (column < 7) {
            if (row == 8) {
                neighbors[0] = 255;
                neighbors[1] = 255;
                neighbors[2] = column - 1 + row * 9;
                neighbors[3] = column + 1 + row * 9;
                neighbors[4] = column + (row - 1) * 9;
                neighbors[5] = column + 1 + (row - 1) * 9;
            } else {
                neighbors[0] = column + (row + 1) * 9;
                neighbors[1] = column + 1 + (row + 1) * 9;
                neighbors[2] = column - 1 + row * 9;
                neighbors[3] = column + 1 + row * 9;
                neighbors[4] = column + (row - 1) * 9;
                neighbors[5] = column + 1 + (row - 1) * 9;
            }
        } else {
            neighbors[0] = 255;
            neighbors[1] = 255;
            neighbors[2] = 255;
            neighbors[3] = 255;
            neighbors[4] = 255;
            neighbors[5] = 255;
        }
    }
    INLINE_MEMCPY(output, neighbors, sizeof(neighbors));
}
