#include <globaldefs.h>

extern unsigned char data_02114e54;
void SelectCoordsByFlag0x24_02012a84(unsigned char*, int*, int*);

struct RectObj021f8970 {
    char pad0[0xc8];
    short width;
    short height;
    short x;
    short y;
};

// USA: func_ov023_021f8970  (semantic: IsPointInScaledRect_021f8970)
extern "C" ARM int func_ov023_021f8970(struct RectObj021f8970* obj) {
    short x = obj->x;
    short y = obj->y;
    short width = obj->width;
    short height = obj->height;
    int px, py;
    SelectCoordsByFlag0x24_02012a84(&data_02114e54, &px, &py);
    if ((short)(x << 3) > px) goto fail;
    short xScaled = (short)(x << 3);
    short widthScaled = (short)(width << 3);
    int xMax = xScaled + widthScaled;
    if (px >= xMax) goto fail;
    if ((short)(y << 3) > py) goto fail;
    short yScaled = (short)(y << 3);
    short heightScaled = (short)(height << 3);
    int yMax = yScaled + heightScaled;
    if (py < yMax) return 1;
fail:
    return 0;
}
