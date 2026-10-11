#include <globaldefs.h>

extern "C" void* _Z28GetElementIfInRange_02173bb0P11Obj02173bb0j(void*, unsigned int);
extern "C" void func_0205ac40(void*, void*);
extern signed char data_ov003_0217fa14[];

// USA: func_ov003_02173bd8  (semantic: SetElementFieldsFromTable_02173bd8)
extern "C" ARM void func_ov003_02173bd8(void* obj) {
    unsigned char* o = (unsigned char*)obj;
    unsigned int index;
    void* elem;
#if defined(jpn)
    enum { stateOffset = 0xe8, countOffset = 0xea, choiceOffset = 0xd0, entriesOffset = 0x13c, x = 0xa2000 };
#else
    enum { stateOffset = 0xec, countOffset = 0xee, choiceOffset = 0xd4, entriesOffset = 0x130, x = 0xb8000 };
#endif
    if (o[stateOffset] == 0) {
        return;
    }
    if (o[stateOffset] == 1) {
        if (o[countOffset] < 2) {
            return;
        }
    }
#if defined(jpn)
    switch (o[choiceOffset]) {
        case 0: elem = _Z28GetElementIfInRange_02173bb0P11Obj02173bb0j((char*)obj + entriesOffset, 5); break;
        case 1: elem = _Z28GetElementIfInRange_02173bb0P11Obj02173bb0j((char*)obj + entriesOffset, 4); break;
        case 2: elem = _Z28GetElementIfInRange_02173bb0P11Obj02173bb0j((char*)obj + entriesOffset, 3); break;
        case 3: elem = _Z28GetElementIfInRange_02173bb0P11Obj02173bb0j((char*)obj + entriesOffset, 2); break;
        default: elem = NULL;
    }
    if (elem == NULL) return;
#else
    if (o[choiceOffset] > 3) {
        return;
    }
    index = data_ov003_0217fa14[o[choiceOffset]];
    elem = _Z28GetElementIfInRange_02173bb0P11Obj02173bb0j((char*)obj + entriesOffset, index);
#endif
    *(int*)((char*)elem + 0x14) = x;
    *(int*)((char*)elem + 0x18) = 0x2f000;
    func_0205ac40((char*)obj + entriesOffset, elem);
}
