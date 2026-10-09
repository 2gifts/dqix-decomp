#include <globaldefs.h>

struct Entry020429e4 {
    unsigned char k0;
    unsigned char k1;
};

struct Table020429e4 {
    unsigned short stride;
    char pad2[4];
    short count;
    struct Entry020429e4* entries;
    char* data;
};

extern "C" int _Z18GetField0x10IfArg8i(int);
extern "C" char* _Z26FindEntryByKeyPair020429e4P13Table020429e4Ph(struct Table020429e4*, char*);
extern "C" void* _Z17GetGlobal02109400v(void);
extern "C" void* _Z19AlwaysFalse02094b44v(void*, void*);

// USA: func_02042a50
extern "C" ARM char* func_02042a50(struct Table020429e4* t, char* key) {
    struct Table020429e4* tb;
    char* k;
    char* e;
    tb = t;
    k = key;
    if (k == NULL) {
        return NULL;
    }
    e = _Z26FindEntryByKeyPair020429e4P13Table020429e4Ph(
            (struct Table020429e4*)_Z18GetField0x10IfArg8i((int)tb), k);
    if (e != NULL) {
        return e;
    }
    return _Z26FindEntryByKeyPair020429e4P13Table020429e4Ph(
        (struct Table020429e4*)_Z19AlwaysFalse02094b44v(_Z17GetGlobal02109400v(), tb), k);
}