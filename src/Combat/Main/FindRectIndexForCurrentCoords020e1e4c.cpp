#include <globaldefs.h>

extern char data_02114e54;

void SelectCoordsByFlag0x24(unsigned char* obj, int* out1, int* out2);
struct RectList020e1eb0;
ARM int FindRectContainingPoint020e1eb0(struct RectList020e1eb0* list, int x, int y);

// USA: func_020e1e4c
ARM int FindRectIndexForCurrentCoords020e1e4c(struct RectList020e1eb0* list) {
    if (!*(unsigned char*)(&data_02114e54 + 0x55)) {
        goto no_flag;
    }
    {
        int x, y;
        SelectCoordsByFlag0x24((unsigned char*)&data_02114e54, &x, &y);
        int idx = FindRectContainingPoint020e1eb0(list, (short)x, (short)y);
        return (idx < 0) ? -2 : idx;
    }
no_flag:
    return -1;
}
