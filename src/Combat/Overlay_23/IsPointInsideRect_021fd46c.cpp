#include <globaldefs.h>

struct Obj021fd420;
void ComputeExtents_021fd420(struct Obj021fd420*, unsigned short*, unsigned short*, unsigned short*, unsigned short*);

extern unsigned char data_02114e54;
void SelectCoordsByFlag0x24_02012a84(unsigned char*, int*, int*);

// USA: func_ov023_021fd46c  (semantic: IsPointInsideRect_021fd46c)
extern "C" ARM int func_ov023_021fd46c(struct Obj021fd420* obj) {
    if (*((unsigned char*)obj + 0xc) & 0x10) return 0;
    unsigned short x1, y1, x2, y2;
    ComputeExtents_021fd420(obj, &x1, &y1, &x2, &y2);
    int px, py;
    SelectCoordsByFlag0x24_02012a84(&data_02114e54, &px, &py);
    if (x1 <= px && px < x2 && y1 <= py && py < y2) return 1;
    return 0;
}
