#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
void* GetField02163524(void* obj);
void* GetGlobalField0x1c020421a0(void);
extern "C" void func_ov000_0216dbf0(void* obj, int a, int b, int c);
extern "C" void func_ov000_021626a0(void* obj, int a, int b);
extern "C" void func_02043124(void* obj);
void* GetSlotPtr02160f20(void* obj);
struct S021d8a40;
void ProcessPairs_021d8a40(void* obj0, struct S021d8a40* obj1);
void IncrementCounterAndReset_021def30(unsigned char* obj);

struct Timer021ef974 {
    int f0;
    unsigned short timer;
    unsigned short timer2;
    int state;
    int fc;
    int count;
};
extern "C" struct Timer021ef974 _ZZ16GetTimer021ef974vE1s;

// USA: func_ov025_021dc880
extern "C" ARM void func_ov025_021dc880(unsigned char* obj) {
    func_ov017_0218b5b0();
    GetField02163524(obj);
    void* global = GetGlobalField0x1c020421a0();

    if (_ZZ16GetTimer021ef974vE1s.state == 0) {
#if defined(jpn)
        func_ov000_0216dbf0(obj + 0xb94, 0, 0, 0);
#else
        func_ov000_0216dbf0(obj + 0xc18, 0, 0, 0);
#endif
        func_ov000_021626a0(obj, 4, 1);
        func_02043124(global);
        _ZZ16GetTimer021ef974vE1s.state = 1;
    }

    if (_ZZ16GetTimer021ef974vE1s.state != 1) {
        return;
    }

    if (++_ZZ16GetTimer021ef974vE1s.count == 15) {
        ProcessPairs_021d8a40(obj, (struct S021d8a40*)GetSlotPtr02160f20(obj));
    }
    if (_ZZ16GetTimer021ef974vE1s.count == 60) {
        IncrementCounterAndReset_021def30(obj);
    }
}
