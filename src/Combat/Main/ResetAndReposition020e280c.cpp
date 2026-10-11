#include <globaldefs.h>

#if defined(jpn)
#define func_020e1cdc func_020e38d4
#endif

void ResetBytes020e25cc(signed char* p);
extern "C" void func_020e1cdc(void* a, void* b);
struct AdjustedPosObj020e2604;
void ComputeAdjustedElementPosition(struct AdjustedPosObj020e2604* self);

struct Obj020e280c {
    unsigned char pad0[0x10];
    void* field_10;   // 0x10
};

// USA: func_020e280c
ARM void ResetAndReposition020e280c(struct Obj020e280c* self, void* b) {
    ResetBytes020e25cc((signed char*)self);
    func_020e1cdc(self->field_10, b);
    ComputeAdjustedElementPosition((struct AdjustedPosObj020e2604*)self);
}
