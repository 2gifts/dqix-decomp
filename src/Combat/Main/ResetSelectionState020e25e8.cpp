#include <globaldefs.h>

struct FlagOwner;

void ClearFlag0x1SetFlag0x2_020e1cb8(struct FlagOwner* obj);
void ResetBytes020e25cc(signed char* p);

struct Obj020e25e8 {
    char pad[0x10];
    struct FlagOwner* owner;
};

// USA: func_020e25e8
ARM void ResetSelectionState020e25e8(struct Obj020e25e8* obj) {
    ClearFlag0x1SetFlag0x2_020e1cb8(obj->owner);
    ResetBytes020e25cc((signed char*)obj);
}
