#include <globaldefs.h>

struct PointerField330_ffd0 {
    char unk[0x330];
    void* field;
};

// USA: func_0200ffd0
ARM void* GetPointerAt0x330_0200ffd0(struct PointerField330_ffd0* obj) {
    return obj->field ? obj->field : 0;
}
