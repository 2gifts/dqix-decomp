#include <globaldefs.h>

struct Wnd0204ecb4 {
    char pad0[0xa8];
    short cols;
    short rows;
};

extern "C" int func_0204fd00(Wnd0204ecb4* wnd, int mask);
void* GetTableEntry020421b0(int idx);
extern "C" void func_0204e1c8(Wnd0204ecb4* wnd, void* entry, short x, short y, int w, int h, int color, int font);

static inline short TileToPx(short t) {
    return t << 3;
}

// USA: func_0204ecb4
extern "C" ARM void func_0204ecb4(Wnd0204ecb4* wnd, int x, int y, short w, short h, signed char* margins) {
    if (w < 0 || h < 0) {
        return;
    }
    short edge;
    int top = 0;
    int bottom = 0;
    int left = 0;
    int right = 0;
    if (margins) {
        top = margins[0];
        bottom = margins[1];
        left = margins[2];
        right = margins[3];
    }

    int ret = func_0204fd00(wnd, 1);
    int idx = 0;
    if (ret == 1) {
        idx = 8;
    } else if (ret == 2) {
        idx = 12;
    }
    void* entry = GetTableEntry020421b0(idx);
    if (entry) {
        func_0204e1c8(wnd, entry, left, top, 8, 8, 0xf0, 0xf);
    }

    void* topEdge = GetTableEntry020421b0(1);
    if (topEdge) {
        for (short i = 1; i < wnd->cols - 1; i++) {
            func_0204e1c8(wnd, topEdge, TileToPx(i), top, 8, 8, 0xf0, 0xf);
        }
    }

    short cols = wnd->cols;
    ret = func_0204fd00(wnd, 2);
    idx = 2;
    if (ret == 3) {
        idx = 9;
    } else if (ret == 2) {
        idx = 13;
    }
    entry = GetTableEntry020421b0(idx);
    if (entry) {
        func_0204e1c8(wnd, entry, TileToPx(cols - 1) - right, top, 8, 8, 0xf0, 0xf);
    }

    entry = GetTableEntry020421b0(3);
    if (entry) {
        for (short i = 1; i < wnd->rows - 1; i++) {
            func_0204e1c8(wnd, entry, left, TileToPx(i), 8, 8, 0xf0, 0xf);
        }
    }

    entry = GetTableEntry020421b0(4);
    edge = TileToPx(wnd->cols - 1);
    if (entry) {
        for (short i = 1; i < wnd->rows - 1; i++) {
            func_0204e1c8(wnd, entry, edge - right, TileToPx(i), 8, 8, 0xf0, 0xf);
        }
    }

    short rows = wnd->rows;
    ret = func_0204fd00(wnd, 4);
    idx = 5;
    if (ret == 1) {
        idx = 10;
    } else if (ret == 4) {
        idx = 14;
    }
    entry = GetTableEntry020421b0(idx);
    if (entry) {
        func_0204e1c8(wnd, entry, left, TileToPx(rows - 1) - bottom, 8, 8, 0xf0, 0xf);
    }

    void* bottomEdge = GetTableEntry020421b0(6);
    edge = TileToPx(wnd->rows - 1);
    if (bottomEdge) {
        for (short i = 1; i < wnd->cols - 1; i++) {
            func_0204e1c8(wnd, bottomEdge, TileToPx(i), edge - bottom, 8, 8, 0xf0, 0xf);
        }
    }

    cols = wnd->cols;
    rows = wnd->rows;
    ret = func_0204fd00(wnd, 8);
    idx = 7;
    if (ret == 3) {
        idx = 11;
    } else if (ret == 4) {
        idx = 15;
    }
    entry = GetTableEntry020421b0(idx);
    if (entry) {
        func_0204e1c8(wnd, entry, TileToPx(cols - 1) - right, TileToPx(rows - 1) - bottom, 8, 8, 0xf0, 0xf);
    }
}
