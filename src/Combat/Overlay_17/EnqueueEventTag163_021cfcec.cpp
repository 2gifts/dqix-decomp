#include <globaldefs.h>

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* p);
void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021cfcec {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned char id;
    unsigned char pad1[14];
};

// USA: func_ov017_021cfcec
ARM void EnqueueEventTag163_021cfcec(unsigned char id) {
    if (func_0202c540(func_0202ae18())) return;
    LocalEvt021cfcec buf;
    void* p = GetData02100044_0202ae24();
    buf.tag = 0xa3;
    buf.id = id;
    func_0205e330(p, &buf, 0);
}
