#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void func_0203ac40(void*, int, int, int);
extern int data_02108760;
extern int data_ov001_0216587c;

// USA: func_ov001_02159990
ARM int DispatchFieldB4Zero_02159990(void* self) {
    func_0203ac40(&data_02108760, *(int*)((char*)self + 0x10), 0, (int)&data_ov001_0216587c);
    return 0;
}
