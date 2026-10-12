#include <globaldefs.h>

#if defined(jpn)
enum { kResourceWorkOffset = 0x3508, kWorkByteOffset = 0x7938 };
#else
enum { kResourceWorkOffset = 0x3718, kWorkByteOffset = 0x7748 };
#endif


#if defined(jpn)
#define ApplyEventTag_021cf024 func_ov017_021cf4cc
#endif

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" int func_ov017_021b8468(void* obj);
void SetByteFieldOffset5950_02163338(unsigned char* obj, unsigned char val);

struct LocalEvt021cf024 {
    unsigned char pad0[4];
    unsigned short field4;
    unsigned char field6;
    unsigned char field7;
};

// USA: func_ov017_021cf024
#if defined(jpn)
extern "C"
#endif
ARM void ApplyEventTag_021cf024(int unused0, LocalEvt021cf024* evt, int unused2, unsigned char* base) {
    void* table = *(void**)(base + kResourceWorkOffset);
    void* a = func_ov017_021b8478(table);
    int b = func_ov017_021b8468(table);
    if (b == 0) {
        return;
    }
    if (*(unsigned short*)((char*)a + 8) != evt->field4) {
        return;
    }
    SetByteFieldOffset5950_02163338((unsigned char*)b, evt->field6);
    *((unsigned char*)b + kWorkByteOffset) = evt->field7;
}
