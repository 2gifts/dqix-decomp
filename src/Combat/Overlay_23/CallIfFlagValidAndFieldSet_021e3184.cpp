#include <globaldefs.h>
#if defined(jpn)
#define func_ov023_021e3184 func_ov023_021e34dc
#endif

void RunTurnStartHooks02155108(void* obj);

struct Obj021e3184 {
    void* field0;
#if defined(jpn)
    char pad[0x4de];
#else
    char pad[0x4e2];
#endif
    signed char field4e6;
};

// USA: func_ov023_021e3184  (semantic: CallIfFlagValidAndFieldSet_021e3184)
extern "C" ARM void func_ov023_021e3184(struct Obj021e3184* obj) {
    signed char c = obj->field4e6;
    if (c == 0) return;
    if (c == -1) return;
    void* v = obj->field0;
    if (v == NULL) return;
    RunTurnStartHooks02155108(v);
}
