#include <globaldefs.h>

struct Obj020dfe88;
struct Struct020dfc40 {
    unsigned char pad[0xc];
    short field_c;
    short field_e;
    int field_10;
    void* field_14;
};

extern "C" int _Z24ResetHandleState020dfe88P11Obj020dfe88(struct Obj020dfe88* obj);
extern "C" void _Z19ResetStruct020dfc40P14Struct020dfc40(struct Struct020dfc40* p);
extern "C" int _Z34ReplaceBinExtensionWithNat020e05f8PcPKc(char* dst, const char* fmt, short n);
extern "C" int func_020dfd40(void* self, char* a, char* b);

// USA: func_020dfc84
extern "C" ARM int func_020dfc84(void* self, void* field_14, char* fmt, char* ext, short n, short field_c) {
    char buf[0x60];
    struct Struct020dfc40* p;

    p = (struct Struct020dfc40*)self;
    _Z24ResetHandleState020dfe88P11Obj020dfe88((struct Obj020dfe88*)self);
    _Z19ResetStruct020dfc40P14Struct020dfc40(p);
    p->field_14 = field_14;
    p->field_c = field_c;
    p->field_e = 1;

    if (n >= 0) {
        _Z34ReplaceBinExtensionWithNat020e05f8PcPKc(buf + 0x20, fmt, n);
        if (ext != 0) {
            _Z34ReplaceBinExtensionWithNat020e05f8PcPKc(buf, ext, n);
            func_020dfd40(self, buf + 0x20, buf);
        } else {
            func_020dfd40(self, buf + 0x20, 0);
        }
        return;
    }

    if (ext != 0) {
        func_020dfd40(self, fmt, ext);
    } else {
        func_020dfd40(self, fmt, 0);
    }
}