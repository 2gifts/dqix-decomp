#include <globaldefs.h>
#if defined(jpn)
extern "C" void func_0208b610(void* obj);
#define InitFieldsIfHandleValid0208ad1c func_0208b610
#endif
void SetColoredEffectParam02070950(struct EffectParam02070950*, struct Rgb02070950*, int, int, int);

extern "C" void* func_020704fc(void*);

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern struct Obj0205eaa0 data_02108760;

// USA: func_0208ad1c
ARM void InitFieldsIfHandleValid0208ad1c(void* obj) {
    void* handle = func_020704fc(obj);
    if (handle != NULL) {
        SetColoredEffectParam02070950((struct EffectParam02070950*)handle, (struct Rgb02070950*)((char*)obj + 0xc), 0x14, 5, 0xf);
        DispatchWithShortB4_0205eaa0(&data_02108760, 0x78, 0);
    }
}
