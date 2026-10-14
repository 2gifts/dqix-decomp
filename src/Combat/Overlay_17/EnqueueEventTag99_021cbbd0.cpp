#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Src021cbbd0 { unsigned char pad[0x8]; unsigned short val; };
struct LocalEvt021cbbd0 {
    unsigned char tag;
    unsigned char pad[3];
    unsigned short val;
    unsigned char pad2[14];
};

// USA: func_ov017_021cbbd0
ARM void EnqueueEventTag99_021cbbd0(unsigned char* obj) {
    LocalEvt021cbbd0 buf;
    void* p = GetData02100044_0202ae24();
    buf.tag = 0x63;
    Src021cbbd0* src = *(Src021cbbd0**)(obj + 0x8e18);
    buf.val = src->val;
    func_0205e330(p, &buf, 1);
}
