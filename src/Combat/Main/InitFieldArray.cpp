#include <globaldefs.h>

struct FieldArray {
    char pad[8];
    int arr[3];
};

// USA: func_020b033c
ARM void InitFieldArray_020b033c(struct FieldArray* obj) {
    int i = 0;
    do {
        obj->arr[i] = -1;
    } while (++i < 3);
}
