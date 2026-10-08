#include <globaldefs.h>

extern "C" void __clear(void* buf, int count);

struct Elem02071da4 {
    short f0;
    short f2;
    short f4;
    short f6;
    short f8;
    unsigned short div0 : 4;
    unsigned short div1 : 4;
    unsigned short div2 : 4;
    unsigned short div3 : 4;
    char padc[0x14];
};

struct List02071da4 {
    char pad0[4];
    struct Elem02071da4* entries;
    unsigned short capacity;
    unsigned short count;
};

// USA: func_02071da4
extern "C" ARM struct Elem02071da4* func_02071da4(struct List02071da4* list, short* vals, unsigned char* chars, unsigned char* out) {
    unsigned char total;
    unsigned char k;
    struct Elem02071da4* arr;
    unsigned int n;
    struct Elem02071da4* e;
    unsigned short i;
    unsigned char cnt;
    unsigned char nz;
    unsigned char j;
    unsigned char diff;
    unsigned char t;
    unsigned char t2;
    unsigned char buf[3];
    unsigned char c;
    int d0;
    int d1;
    int d2;

    if (vals == NULL || chars == NULL) {
        return NULL;
    }
    total = 0;
    for (k = 0; k < 3; k++) {
        if (vals[k] > 0) {
            total = total + 1;
        }
    }

    arr = list->entries;
    n = list->count;
    for (i = 0; i < n; i++) {
        e = &arr[i];
        cnt = 0;
        cnt += (e->f4 > 0);
        cnt += (e->f6 > 0);
        cnt += (e->f8 > 0);
        if (cnt == total) {
            __clear(buf, 3);
            for (j = 0; j < cnt; j++) {
                short v = vals[j];
                c = chars[j];
                if (v == e->f4) {
                    d0 = e->div0;
                    if (c % d0 == 0) {
                        buf[0] = c / d0;
                    } else {
                        break;
                    }
                } else if (v == e->f6) {
                    d1 = e->div1;
                    if (c % d1 == 0) {
                        buf[1] = c / d1;
                    } else {
                        break;
                    }
                } else if (v == e->f8) {
                    d2 = e->div2;
                    if (c % d2 == 0) {
                        buf[2] = c / d2;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }

            nz = 0;
            for (t = 0; t < 3; t++) {
                if (buf[t] != 0) {
                    nz = nz + 1;
                }
            }

            if (cnt == nz) {
                diff = 0;
                for (t2 = 1; t2 < cnt; t2++) {
                    if (buf[0] != buf[t2]) {
                        diff = 1;
                        break;
                    }
                }
                if (diff == 0) {
                    *out = buf[0];
                    return e;
                }
            }
        }
    }
    return NULL;
}
