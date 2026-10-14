#include <globaldefs.h>

struct StoreCellWordHalfSource { unsigned int w; unsigned short h; };
struct StoreCellWordHalfCell { unsigned int w; unsigned short h; unsigned short pad; };
struct StoreCellWordHalfRow { unsigned int hdr; struct StoreCellWordHalfCell cells[9]; };

// USA: func_0209b988
ARM void StoreCellWordHalf_0209b988(struct StoreCellWordHalfRow *base, int i, int j, struct StoreCellWordHalfSource *src) {
    base[i].cells[j].w = src->w;
    base[i].cells[j].h = src->h;
}
