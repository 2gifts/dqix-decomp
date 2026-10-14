#include <globaldefs.h>

struct ArrayContainsByteStruct {
    char pad[0xf78];
    unsigned char arr[4];
    unsigned char count;
};

// USA: func_02086ef0
ARM int ArrayContainsByte_02086ef0(struct ArrayContainsByteStruct* s, int val) {
    int i;
    for (i = 0; i < s->count; i++) {
        if (val == s->arr[i]) {
            return 1;
        }
    }
    return 0;
}
