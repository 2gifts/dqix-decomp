#include <globaldefs.h>

struct Entry021e7cec { unsigned char id; unsigned char f1; unsigned char f2; signed char f3; signed char f4; unsigned char f5; unsigned char f6; };
extern Entry021e7cec data_ov023_021fd7fc[];

struct Obj021e7cec {
    char pad[0x118];
    unsigned short field118;
    unsigned short field11a;
    unsigned short field11c;
    unsigned short field11e;
    unsigned short field120;
    unsigned short field122;
    unsigned short field124;
    unsigned short field126;
    char pad2[0x129 - 0x128];
    unsigned char field129;
    char pad3[0x12d - 0x12a];
    unsigned char field12d;
    unsigned char field12e;
};

// USA: func_ov023_021e7cec  (semantic: FindEntryAndApply_021e7cec)
extern "C" ARM void func_ov023_021e7cec(struct Obj021e7cec* obj, unsigned char key, unsigned short p2, unsigned short p3) {
    int i = 0;
    struct Entry021e7cec* entry;
    while ((entry = &data_ov023_021fd7fc[i])->id != 0xff) {
        unsigned char idVal = *(unsigned char*)&entry->id;
        if (idVal == key) {
            obj->field129 = idVal;
            obj->field11c = p2;
            obj->field11e = p3;
            unsigned char t2 = entry->f2;
            unsigned char t1 = entry->f1;
            obj->field120 = t1;
            obj->field122 = t2;
            signed char t4 = entry->f4;
            signed char t3 = entry->f3;
            obj->field118 = t3;
            obj->field11a = t4;
            unsigned char t6 = entry->f6;
            unsigned char t5 = entry->f5;
            obj->field124 = t5;
            obj->field126 = t6;
            obj->field12d = 0;
            obj->field12e = 0;
            if (entry->id == 0x10) {
                obj->field12d = 1;
                obj->field12e = 1;
            }
            return;
        }
        i++;
    }
}
