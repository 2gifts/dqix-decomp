#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { fieldPadding = 0x13e };
#else
enum { fieldPadding = 0x14a };
#endif

extern "C" void func_ov017_02191aac(char* obj, int mode, int idx, unsigned char mask);
unsigned long long GetCurrentTimestamp(void);
void EnqueueEventTag17_021ce014(int a, unsigned short b, unsigned short c, unsigned short d);

struct Obj020541a4 {
    unsigned char pad0[4];
    short field4;
    unsigned char pad6[fieldPadding];
    unsigned char* field150;
};

// USA: func_020541a4
// KEEP-NAME
ARM void NotifySub020541a4(struct Obj020541a4* p, unsigned char b) {
    unsigned char* q = p->field150;
    if (q == 0) return;
    GameState::GetInstance();
    void* base = func_ov017_0218b5b0();
    q = p->field150;
    q[0x56c] = 1;
    q = p->field150;
    q[0x56d] = b;
    func_ov017_02191aac((char*)base, 1, p->field4, 2);
    unsigned long long ts = GetCurrentTimestamp();
    q = p->field150;
    *(unsigned int*)(q + 0x480) = (unsigned int)ts;
    *(unsigned int*)(q + 0x484) = (unsigned int)(ts >> 32);
    EnqueueEventTag17_021ce014(0, 1, 1, (unsigned short)p->field4);
}
