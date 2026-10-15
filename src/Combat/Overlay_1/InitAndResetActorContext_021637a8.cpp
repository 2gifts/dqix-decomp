#include <globaldefs.h>

extern "C" short func_ov017_021d60f4(void* obj);
struct Actor0209c20c;
void InitActorContext0209c20c(struct Actor0209c20c* actor);
void ResetAndDispatchActorContext0209c6d8(void* actor, int arg);
extern struct Actor0209c20c data_02109bf4;

// USA: func_ov001_021637a8
ARM int InitAndResetActorContext_021637a8(void* obj) {
    short v = func_ov017_021d60f4(obj);
    InitActorContext0209c20c(&data_02109bf4);
    ResetAndDispatchActorContext0209c6d8(&data_02109bf4, v);
    return 1;
}
