#include <globaldefs.h>
#include "std_library_functions.h"

void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);
extern "C" int func_ov017_0218b5b0(void);
extern "C" void __clear(void* buf, int size);
extern "C" void func_02042764(char* name, void* buf, int flag);

struct Sub021d0b30 {
    unsigned short a;
    unsigned short b;
    char name[12];
};
struct LocalEvt021d0b30 {
    unsigned char tag;
    unsigned char pad0[3];
    struct Sub021d0b30 sub;
};

// JPN: func_ov017_021d0fe0
// USA: func_ov017_021d0b30  (semantic: EnqueueTag2aAndMaybeFormatName_021d0b30)
extern "C" ARM void func_ov017_021d0b30(unsigned short a, unsigned short b, char* c) {
#if defined(jpn)
 enum {regionalOffset0=0x13c, regionalOffset1=0xc};
#else
 enum {regionalOffset0=0x35c, regionalOffset1=0x30};
#endif
    void* data = GetData02100044();
    struct LocalEvt021d0b30 buf;
    struct Sub021d0b30* s = &buf.sub;

    buf.tag = 0x2a;
    s->a = a;
    s->b = b;
    if (c != 0) {
        strcpy(s->name, c);
    }
    func_0205e330(data, &buf, 0);

    if (a != 0) return;

    unsigned char* base = (unsigned char*)func_ov017_0218b5b0();
    unsigned char* entry = base + regionalOffset0 + 0x4000 + b * regionalOffset1;
    if (entry == 0) return;

#if defined(jpn)
    strcpy((char*)entry, c);

#else
    char nameBuf[regionalOffset1];
    __clear(nameBuf, regionalOffset1);
    func_02042764(c, nameBuf, 1);
    strcpy((char*)entry, nameBuf);

#endif
}
