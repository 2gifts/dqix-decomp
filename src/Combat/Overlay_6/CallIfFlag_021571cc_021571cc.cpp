#include <globaldefs.h>

#if defined(jpn)
#define CallIfFlag_021571cc_021571cc func_ov006_021587d4
enum { kFlags = 0x1054, kInner = 0x164 };
#else
enum { kFlags = 0x1258, kInner = 0x2e4 };
#endif



extern "C" void func_ov023_021dd344(void* p);

struct CallIfFlag0x800_021571ccStruct {
    unsigned char pad[kFlags];
    unsigned short flags;
};

// USA: func_ov006_021571cc
#if defined(jpn)
extern "C"
#endif
ARM void CallIfFlag_021571cc_021571cc(struct CallIfFlag0x800_021571ccStruct* s) {
    int flagSet = (s->flags & 0x800) != 0;
    if (flagSet) {
        func_ov023_021dd344((char*)s + kInner + 0x800);
    }
}
