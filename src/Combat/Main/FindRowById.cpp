#include <globaldefs.h>

struct FindRowByIdRow { unsigned short id; char pad[0x4a]; };

// USA: func_0209b9e4
ARM struct FindRowByIdRow* FindRowById_0209b9e4(struct FindRowByIdRow *base, int key) {
    int i;
    for (i = 0; i < 6; i++) {
        if (key == base[i].id) return &base[i];
    }
    return NULL;
}
