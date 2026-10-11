#include <globaldefs.h>

struct Obj0220528c;
struct Inner022067f0 {
    char padding[0x10c];
    Obj0220528c* callback;
};
struct Context022067f0 {
    char padding[0x68];
    Inner022067f0* inner;
    char padding6c[4];
    volatile short flags;
    signed char tag;
};
int IsNotInList0224e22c_02207180(void*);
void* SetLookupFields_02205134(void*, void*, int);
int TailCall0220520cField68_0220528c(Obj0220528c*, void*);
int MaybeCallIfState0Or4_0220689c(void*);

// USA: func_ov031_022067f0
extern "C" ARM int func_ov031_022067f0(void* argument) {
    Context022067f0* context = (Context022067f0*)argument;
    if (IsNotInList0224e22c_02207180(argument)) return -28;
    int eligible = 0;
    if (context != NULL) eligible = (context->flags & 1) != 0;
    if (!eligible) return -39;
    if (!(context->flags & 4) || (context->flags & 8)) return -56;
    context->flags |= 8;
    Inner022067f0* inner = context->inner;
    if (inner != NULL && inner->callback != NULL) {
        void* record = SetLookupFields_02205134((void*)MaybeCallIfState0Or4_0220689c,
            inner->callback, context->tag);
        if (record == NULL) return -33;
        return TailCall0220520cField68_0220528c(inner->callback, record);
    }
    return 0;
}
