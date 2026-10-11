#include <globaldefs.h>

#if defined(jpn)
enum { fieldPadding = 0x13e };
#else
enum { fieldPadding = 0x14a };
#endif

extern "C" void _ZN9GameState11GetInstanceEv(void);
extern "C" void* func_ov017_0218b5b0(void);
extern "C" void func_ov017_02191aac(char* obj, int mode, int idx, unsigned char mask);
extern "C" unsigned long long _Z19GetCurrentTimestampv(void);
extern "C" void _Z26EnqueueEventTag17_021ce014ittt(int a, unsigned short b, unsigned short c, unsigned short d);

struct Obj020541a4 {
    unsigned char pad0[4];
    short field4;
    unsigned char pad6[fieldPadding];
    unsigned char* field150;
};

// USA: func_020541a4
// KEEP-NAME
extern "C" ARM void _Z17NotifySub020541a4P11Obj020541a4h(struct Obj020541a4* p, unsigned char b) {
    unsigned char* q = p->field150;
    if (q == 0) return;
    _ZN9GameState11GetInstanceEv();
    void* base = func_ov017_0218b5b0();
    q = p->field150;
    q[0x56c] = 1;
    q = p->field150;
    q[0x56d] = b;
    func_ov017_02191aac((char*)base, 1, p->field4, 2);
    unsigned long long ts = _Z19GetCurrentTimestampv();
    q = p->field150;
    *(unsigned int*)(q + 0x480) = (unsigned int)ts;
    *(unsigned int*)(q + 0x484) = (unsigned int)(ts >> 32);
    _Z26EnqueueEventTag17_021ce014ittt(0, 1, 1, (unsigned short)p->field4);
}