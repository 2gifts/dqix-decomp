#include <globaldefs.h>

extern "C" int func_ov004_021666bc(void* a1, int* out);
#if defined(jpn)
struct RegionalContextPointer { unsigned int reserved; char* value; };
extern RegionalContextPointer data_ov004_0217101c;
#define CONTEXT_VALUE data_ov004_0217101c.value
#else
extern char* data_ov004_0217101c;
#define CONTEXT_VALUE data_ov004_0217101c
#endif
void DispatchStateTransitions_02166608(void* a);
extern "C" void func_ov004_021660f4(void);
extern "C" void func_ov004_02165f2c(void);
extern "C" void func_ov004_02166730(void* a1, int a2);
extern "C" void func_ov004_02166bd8(void* a1);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern struct Obj0205eaa0 data_02108760;

struct BitField02166fe4 {
    char pad[0x50];
    unsigned char loBits : 7;
    unsigned char bit7 : 1;
};

// USA: func_ov004_02166fe4
ARM int ToggleStateAndDispatchAll_02166fe4(void* a1) {
    int local;
    int r4 = func_ov004_021666bc(a1, &local);

    struct BitField02166fe4* r3 = (struct BitField02166fe4*)CONTEXT_VALUE;
    r3->bit7 = r3->bit7 + 1;

    DispatchStateTransitions_02166608(a1);
    func_ov004_021660f4();
    func_ov004_02165f2c();
    func_ov004_02166730(a1, r4);
    func_ov004_02166bd8(a1);
    DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
    return 0;
}
