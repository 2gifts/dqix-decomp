#include <globaldefs.h>

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);
int CallFunc021f6788ForIndexUnder3_021f6eb8(void* list, int index);
extern "C" void* func_ov011_021849c8(void* p);
extern "C" void* func_ov017_021b2164(void);

// USA: func_ov011_02188384  (semantic: Trans_02188384)
extern "C" ARM int func_ov011_02188384(struct TaggedNumber02184c30* params, int count) {
    int index = GetTaggedValueAsInt_02184c30(&params[0]);
    CallFunc021f6788ForIndexUnder3_021f6eb8(func_ov011_021849c8(func_ov017_021b2164()), index);
    return 1;
}
