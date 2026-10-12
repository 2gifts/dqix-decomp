#include <globaldefs.h>

struct Struct_0205c53c;
#if defined(jpn)
extern "C" void func_0205d8c4(Struct_0205c53c*);
#define ForwardInitChannelPair0205c564 func_0205d8c4
#endif
void InitChannelPair0205c53c(struct Struct_0205c53c* s);

// USA: func_0205c564
ARM void ForwardInitChannelPair0205c564(struct Struct_0205c53c* s) {
    InitChannelPair0205c53c(s);
}
