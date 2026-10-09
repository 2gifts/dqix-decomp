#include <globaldefs.h>

struct Border02043600 {
    char padding[0xae];
    short rowOffset;
};

struct Rectangle02043600 {
    short x, y, width, height;
};

extern "C" void _Z31InvokeTableEntryHandler020435a8iPvS_i(int, void*, void*, int);

inline short GetLeft02043600(const Rectangle02043600* rectangle) {
    short left = rectangle->x;
    return left;
}

// USA: func_02043600
extern "C" ARM void func_02043600(Border02043600* border, const Rectangle02043600* rectangle) {
    if (border == NULL || rectangle == NULL) return;
    short left = GetLeft02043600(rectangle);
    short top = rectangle->y;
    short right = left + rectangle->width;
    short bottom = top + rectangle->height;
    top -= border->rowOffset * 8;
    bottom -= border->rowOffset * 8;
    right -= 8;
    bottom -= 8;
    if (left < 0 || top < 0 || bottom < 0 || right < 0) return;
    for (short x = left + 8; x < right; x += 8)
        _Z31InvokeTableEntryHandler020435a8iPvS_i((int)border, (void*)x, (void*)top, 1);
    for (short x = left + 8; x < right; x += 8)
        _Z31InvokeTableEntryHandler020435a8iPvS_i((int)border, (void*)x, (void*)bottom, 6);
    for (short y = top + 8; y < bottom; y += 8)
        _Z31InvokeTableEntryHandler020435a8iPvS_i((int)border, (void*)left, (void*)y, 3);
    for (short y = top + 8; y < bottom; y += 8)
        _Z31InvokeTableEntryHandler020435a8iPvS_i((int)border, (void*)right, (void*)y, 4);
    _Z31InvokeTableEntryHandler020435a8iPvS_i((int)border, (void*)left, (void*)top, 0);
    _Z31InvokeTableEntryHandler020435a8iPvS_i((int)border, (void*)right, (void*)top, 2);
    _Z31InvokeTableEntryHandler020435a8iPvS_i((int)border, (void*)left, (void*)bottom, 5);
    _Z31InvokeTableEntryHandler020435a8iPvS_i((int)border, (void*)right, (void*)bottom, 7);
}
