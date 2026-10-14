#include <globaldefs.h>
void ClearListEntryIfMatch020be3f4(int, void*, unsigned int);

void PostEvent0x1E_020d2084(int a, int b);

// USA: func_020be44c
ARM void PrepareAndPostEvent1E020be44c(int a0, int a1, int a2, int a3) {
    ClearListEntryIfMatch020be3f4((int)(a0), (void*)(a2), (unsigned int)(a3));
    PostEvent0x1E_020d2084(a0, a0 + a1);
}
