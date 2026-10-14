#include <globaldefs.h>

struct PackedFields {
    char unk[0x10];
    unsigned int low : 10;
    unsigned int fieldB : 10;
    unsigned int fieldA : 8;
};

// USA: func_020de3ac
ARM int MatchesPackedFields_020de3ac(struct PackedFields* obj, int a, int unused, int b) {
    return obj->fieldA == a && obj->fieldB == b;
}
