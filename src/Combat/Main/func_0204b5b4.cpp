#include <globaldefs.h>

extern int (*data_020f01d8[][4])(int);

struct Obj0204b5b4 {
    char pad[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
};

static inline int (*tbl_at(int lo, int hi))(int) {
    return data_020f01d8[lo][hi];
}

// USA: func_0204b5b4
extern "C" ARM void func_0204b5b4(struct Obj0204b5b4* obj, int a) {
    tbl_at(obj->lo, obj->hi)(a & 3);
}
