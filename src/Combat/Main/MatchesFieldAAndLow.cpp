#include <globaldefs.h>

struct MatchPackedFields {
    char unk[0x10];
    unsigned int low : 10;
    unsigned int fieldB : 10;
    unsigned int fieldA : 8;
};

// USA: func_020de38c
ARM int MatchesFieldAAndLow_020de38c(struct MatchPackedFields* obj, int a, int b) {
    return obj->fieldA == a && obj->low == b;
}
