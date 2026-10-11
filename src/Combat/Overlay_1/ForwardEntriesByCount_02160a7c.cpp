#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
extern "C" void func_ov017_021d6134(void* p, int flag);

struct S734 { 
#if defined(jpn)
    char pad[0xc8];
#else
    char pad[0xcc];
#endif
 unsigned char f_cc, f_cd, f_ce, f_cf; };

// USA: func_ov001_02160a7c  (semantic: ForwardEntriesByCount_02160a7c)
extern "C" ARM int func_ov001_02160a7c(char* obj, int count) {
#if defined(jpn)
    enum { queueOffset = 0x3524 };
#else
    enum { queueOffset = 0x3734 };
#endif
    int flag;
    void* ov17 = func_ov017_0218b5b0();
    struct S734* s = *(struct S734**)((char*)ov17 + queueOffset);
    func_ov017_021d6134(obj, s->f_cd);
    obj += 8;
    if (count >= 2) {
        func_ov017_021d6134(obj, s->f_cf);
        obj += 8;
    }
    if (count >= 3) {
        func_ov017_021d6134(obj, s->f_ce);
        obj += 8;
    }
    if (count >= 4) {
        unsigned char v = s->f_cc;
        if (v == 2) {
            flag = 0;
        } else if (v == 1) {
            flag = 1;
        }
        func_ov017_021d6134(obj, flag);
    }
    return 1;
}
