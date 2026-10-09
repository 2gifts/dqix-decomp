#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
extern "C" void* _Z16GetField02163524Pv(void* obj);
extern "C" void* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void func_ov000_0216dbf0(void* obj, int a, int b, int c);
extern "C" void func_ov000_021626a0(void* obj, int a, int b);
extern "C" void func_02043124(void* obj);
extern "C" void* _Z18GetSlotPtr02160f20Pv(void* obj);
struct S021d8a40;
extern "C" void _Z21ProcessPairs_021d8a40PvP9S021d8a40(void* obj0, struct S021d8a40* obj1);
extern "C" void _Z33IncrementCounterAndReset_021def30Ph(unsigned char* obj);

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
    _Z16GetField02163524Pv(obj);
    void* global = _Z26GetGlobalField0x1c020421a0v();

    if (_ZZ16GetTimer021ef974vE1s.state == 0) {
        func_ov000_0216dbf0(obj + 0xc18, 0, 0, 0);
        func_ov000_021626a0(obj, 4, 1);
        func_02043124(global);
        _ZZ16GetTimer021ef974vE1s.state = 1;
    }

    if (_ZZ16GetTimer021ef974vE1s.state != 1) {
        return;
    }

    if (++_ZZ16GetTimer021ef974vE1s.count == 15) {
        _Z21ProcessPairs_021d8a40PvP9S021d8a40(obj, (struct S021d8a40*)_Z18GetSlotPtr02160f20Pv(obj));
    }
    if (_ZZ16GetTimer021ef974vE1s.count == 60) {
        _Z33IncrementCounterAndReset_021def30Ph(obj);
    }
}
