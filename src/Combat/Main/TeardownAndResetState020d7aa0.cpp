#include <globaldefs.h>

extern "C" void func_02094ab0(int a);
extern "C" void func_ov017_0218b5c0(int a, int b);
extern "C" void func_ov017_0218b5f8(int a);

int GetGlobal02109400(void);
int GetGlobalField0x1c020421a0(void);
void ReinitController02043204(char* obj);

struct ResetObj020d7a5c;
void ResetAndClearFlags020d7a5c(struct ResetObj020d7a5c* o);

struct Flags020d7aa0 {
    unsigned char lo : 6;
    unsigned char bit6 : 1;
    unsigned char bit7 : 1;
};

struct Obj020d7aa0 {
    #if defined(jpn)
    unsigned char pad[0xf0];
#else
    unsigned char pad[0x150];
#endif
    struct Flags020d7aa0 flags;
};

// USA: func_020d7aa0
ARM void TeardownAndResetState020d7aa0(struct Obj020d7aa0* obj) {
    int g = GetGlobal02109400();
    if (obj->flags.bit7) {
        func_02094ab0(g);
    }
    if (obj->flags.bit6) {
        ReinitController02043204((char*)GetGlobalField0x1c020421a0());
        obj->flags.bit6 = 0;
    }
    func_ov017_0218b5c0(1, -1);
    func_ov017_0218b5f8(-1);
    ResetAndClearFlags020d7a5c((struct ResetObj020d7a5c*)obj);
}

// JPN: 0x020d94a4
