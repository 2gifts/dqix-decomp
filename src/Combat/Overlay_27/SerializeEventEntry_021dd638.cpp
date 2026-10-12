#include <globaldefs.h>

struct EventEntry021dd638 {
    unsigned char type;
    unsigned char pad1;
    unsigned short f2;
    unsigned short f4;
};

// USA: func_ov027_021dd638  (semantic: SerializeEventEntry_021dd638)
extern "C" ARM int func_ov027_021dd638(EventEntry021dd638* obj, unsigned char* dst) {
    unsigned char* p = dst;
    *p++ = obj->type;
    switch (obj->type) {
    case 1:
    case 2:
    case 3:
    case 5:
    case 6:
        break;
    case 4:
        p[0] = (unsigned char)obj->f2;
        p[1] = (unsigned char)((obj->f2 & 0xff00) >> 8);
        p[2] = (unsigned char)obj->f4;
        p[3] = (unsigned char)((obj->f4 & 0xff00) >> 8);
        p += 4;
        break;
    case 0:
    default:
        return 0;
    }
    return (int)p;
}
