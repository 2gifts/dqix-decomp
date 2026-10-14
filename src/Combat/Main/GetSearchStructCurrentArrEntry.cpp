#include <globaldefs.h>

struct SearchStruct0202c1a4 {
    char pad[0x1038];
    signed char arr[16];
};

extern unsigned short GetGlobalHalf0x0_0202df58(void);

// USA: func_0202c1a4
ARM signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj) {
    return obj->arr[GetGlobalHalf0x0_0202df58()];
}
