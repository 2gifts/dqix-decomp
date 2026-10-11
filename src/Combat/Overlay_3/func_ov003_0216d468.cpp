#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue2C0_150 = 0x150 };
enum { kRegionValue410_428 = 0x428 };
#else
enum { kRegionValue2C0_150 = 0x2c0 };
enum { kRegionValue410_428 = 0x410 };
#endif


struct Cont0205d1e0;
struct Cont0205d228;
struct Cont0205d274;
void ClearBuffers0204b010OverList0x98(Cont0205d1e0*);
void CallFunc0204c8f0OverList0x9c(Cont0205d228*);
extern "C" void func_0205da88(void*, int, int, int);
void CallFunc0204b04cOverList0x98(Cont0205d274*);
extern "C" void func_ov003_0216d990(void* obj);
#if defined(jpn)
extern "C" void func_ov003_0216dcf0(void* obj);
#else
extern "C" void func_ov004_0216dcf0(void* obj);
#endif
extern "C" void func_ov003_0216ddfc(void* obj);
extern "C" void func_ov003_0217019c(void* obj);
extern "C" void func_ov003_0215ca1c(void* obj);
void ProcessCombatState_02173ea8(unsigned char* obj);

// USA: func_ov003_0216d468
// JPN: func_ov003_0216cf3c
extern "C" ARM void func_ov003_0216d468(void* p) {
    char* obj = (char*)p;
    if (*(void**)(obj + 0x1000 + kRegionValue2C0_150) != 0) {
        short f6 = *(short*)(obj + 6);
        if (f6 == 0 || f6 == 1 || *(short*)(obj + 4) == 2) {
            ClearBuffers0204b010OverList0x98((Cont0205d1e0*)*(void**)(obj + 0x1000 + kRegionValue2C0_150));
            CallFunc0204c8f0OverList0x9c((Cont0205d228*)*(void**)(obj + 0x1000 + kRegionValue2C0_150));
            func_0205da88(*(void**)(obj + 0x1000 + kRegionValue2C0_150), 2, 1, 1);
            CallFunc0204b04cOverList0x98((Cont0205d274*)*(void**)(obj + 0x1000 + kRegionValue2C0_150));
        }
    }
    func_ov003_0216d990(obj);
#if defined(jpn)
    func_ov003_0216dcf0(obj);
#else
    func_ov004_0216dcf0(obj);
#endif
    func_ov003_0216ddfc(obj);

    short f4 = *(short*)(obj + 4);
    if (f4 == 4) {
        func_ov003_0217019c(obj + kRegionValue410_428);
        return;
    }
    if (f4 == 3) {
        if (*(short*)(obj + 6) == 1) {
            func_ov003_0215ca1c(obj + 0x14);
        }
        return;
    }
    if (f4 == 5 && *(short*)(obj + 6) == 6) {
#if defined(jpn)
        ProcessCombatState_02173ea8((unsigned char*)(obj + 0xda0));
#else
        ProcessCombatState_02173ea8((unsigned char*)(obj + 0x31c + 0xc00));
#endif
    }
}
