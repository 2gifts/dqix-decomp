#include <globaldefs.h>

struct Obj2081;

struct Elem02080d54 {
    char pad[0xa8];
    short width;
    short height;
    short x;
    short y;
};

extern struct Elem02080d54* FindElementByByte0xc4_02081da8(struct Obj2081* obj, int key);

// USA: func_02080d54
ARM int IsPointInsideElement02080d54(struct Obj2081* obj, int key, int px, int py) {
    struct Elem02080d54* elem = FindElementByByte0xc4_02081da8(obj, key);
    short x1, y1;
    if (elem == NULL) {
        return 0;
    }
    x1 = elem->x + elem->width;
    y1 = elem->y + elem->height;
    if (px >= (short)(elem->x * 8)) {
        if (px < (short)(x1 * 8)) {
            if (py >= (short)(elem->y * 8)) {
                if (py < (short)(y1 * 8)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
