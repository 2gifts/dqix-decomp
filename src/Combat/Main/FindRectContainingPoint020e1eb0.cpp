#include <globaldefs.h>

struct Origin020e1eb0 {
    char pad[0x38];
    unsigned char ox;
    unsigned char oy;
};

struct Rect020e1eb0 {
    short xmin;
    short ymin;
    short xmax;
    short ymax;
};

struct RectList020e1eb0 {
    char pad0[4];
    struct Origin020e1eb0* origin;
    signed char count;
    char pad9;
    struct Rect020e1eb0 rects[1];
};

// USA: func_020e1eb0
ARM int FindRectContainingPoint020e1eb0(struct RectList020e1eb0* list, int x, int y) {
    int i;
    for (i = 0; i < list->count; i++) {
        struct Origin020e1eb0* o = list->origin;
        int x0 = o->ox + list->rects[i].xmin;
        int y0 = o->oy + list->rects[i].ymin;
        int x1 = o->ox + list->rects[i].xmax;
        int y1 = o->oy + list->rects[i].ymax;
        if (x0 <= x && x <= x1 && y0 <= y && y <= y1) {
            return i;
        }
    }
    return -1;
}
