#include <globaldefs.h>

struct Get28ByteElementAt0x334Elem {
    unsigned int v[7];
};

struct Get28ByteElementAt0x334Struct {
    char pad[0x334];
    struct Get28ByteElementAt0x334Elem arr[1];
};

// USA: func_0206ea7c
ARM struct Get28ByteElementAt0x334Elem* Get28ByteElementAt0x334_0206ea7c(struct Get28ByteElementAt0x334Struct* s, int i) {
    return &s->arr[i];
}
