#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f98e0(void*, void*);
extern unsigned char data_ov004_02171034[];

// USA: func_ov004_0216e984  (semantic: SetFlag10AndDispatch_0216e984)
extern "C" ARM int func_ov004_0216e984(void* a) {
#if defined(jpn)
    enum { fieldOffset = 0x8 };
#else
    enum { fieldOffset = 0xa };
#endif
    void* ret = func_ov011_021849c8(a);
    if (ret) {
        unsigned short key = *(unsigned short*)&data_ov004_02171034[fieldOffset];
        void* obj = func_ov023_021f6880(ret, key);
        if (obj) {
            ((unsigned char*)obj)[0xc] |= 0x10;
            func_ov023_021f98e0(obj, a);
        }
    }
    return 0;
}
