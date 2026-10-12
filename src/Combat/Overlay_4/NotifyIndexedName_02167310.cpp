#include <globaldefs.h>

#if defined(jpn)
#define func_ov004_02167310 func_ov004_0216791c
#endif


struct Elem0208d994;
struct List0208d994;
struct Obj02046574;

int GetGlobalField0x1c020421a0(void);
extern "C" void func_02046380(void* g);
extern "C" int func_ov004_021666bc(void*, int*);
Elem0208d994* FindElementByKey0208d994(List0208d994*, int);
void SetIndexedName02046574(Obj02046574*, int, char*);

#if defined(jpn)
extern void* data_ov004_0217101c[2];
#define CurrentBase0217101c data_ov004_0217101c[1]
#else
extern void* data_ov004_0217101c;
#define CurrentBase0217101c data_ov004_0217101c
#endif

// USA: func_ov004_02167310  (semantic: NotifyIndexedName_02167310)
extern "C" ARM int func_ov004_02167310(void* a) {
    void* list = CurrentBase0217101c;
    int g = GetGlobalField0x1c020421a0();
    func_02046380((void*)g);
    int local;
    int key = func_ov004_021666bc(a, &local);
    Elem0208d994* e = FindElementByKey0208d994((List0208d994*)((char*)list + 0xc), key);
    if (e) {
        SetIndexedName02046574((Obj02046574*)g, 0, *(char**)((char*)e + 0x4));
    }
    return 0;
}
