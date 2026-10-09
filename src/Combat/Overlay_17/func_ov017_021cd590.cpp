#include <globaldefs.h>

void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Msg021cd590 {
    unsigned short id;
    unsigned short values[4];
    unsigned char highBytes[4];
    unsigned char field_e;
    unsigned char field_f;
};

// USA: func_ov017_021cd590
extern "C" ARM void func_ov017_021cd590(unsigned short id, unsigned int* list, unsigned char a2, unsigned char a3) {
    void* p = GetData02100044();
    unsigned char buf[0x14];
    Msg021cd590* m = (Msg021cd590*)(buf + 4);
    m->field_e = a2;
    buf[0] = 0x6a;
    m->id = id;
    for (int i = 0; i < 4; i++) {
        unsigned int v = list[i];
        unsigned int hi = v & 0xff0000;
        m->values[i] = v;
        hi >>= 16;
        m->highBytes[i] = hi;
    }
    m->field_f = a3;
    func_0205e330(p, buf, 0);
}
