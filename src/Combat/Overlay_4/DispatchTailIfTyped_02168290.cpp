#if defined(jpn)
#define R(j,u) (j)
#define _Z27ScaleStatsIfType12_021f6f10Pv func_ov023_021f6f10
#define data_ov004_0216fffa data_ov004_02170752
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void* a);
extern "C" void* func_ov023_021f6880(void* obj, int key);
#if defined(jpn)
#define ScaleStatsIfType12_021f6f10 func_ov023_021f6f10
extern "C" int ScaleStatsIfType12_021f6f10(void* self);
#else
int ScaleStatsIfType12_021f6f10(void* self);
#endif
extern "C" int func_ov023_021f9bc8(char* obj);
int TailCallOffset20_021fbdcc(void*, int, int, int);
extern "C" void func_ov011_021848a0(void* obj, int val);

extern char data_ov004_0216fffa;

// USA: func_ov004_02168290  (semantic: DispatchTailIfTyped_02168290)
extern "C" ARM int func_ov004_02168290(void* obj) {
    void* node1 = func_ov023_021f6880(func_ov011_021849c8(obj), 7);
    if (node1 && ScaleStatsIfType12_021f6f10(node1) == 0x10) {
        void* node2 = func_ov023_021f6880(func_ov011_021849c8(obj), 0xe);
        if (!node2) {
            return 0;
        }
        if (ScaleStatsIfType12_021f6f10(node2) != 7) {
            return 0;
        }
        int idx = func_ov023_021f9bc8((char*)node2);
        short val = *(short*)(&data_ov004_0216fffa + idx * 4);
        typedef int (*TailFn2)(void*, int);
        ((TailFn2)&TailCallOffset20_021fbdcc)(node1, val);
    }
    func_ov011_021848a0(obj, 0x68);
    return 0;
}
