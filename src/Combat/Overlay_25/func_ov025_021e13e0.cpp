#include <globaldefs.h>

struct Sub148_021e13e0 {
    char pad[0x10];
    unsigned int flags;
};

struct Combatant021e13e0 {
    unsigned short flags;
    char pad[0x146];
    Sub148_021e13e0* sub148;
};

struct Ent021e13e0 {
    unsigned char id;
    unsigned char val;
    char pad[6];
    Combatant021e13e0* obj;
};

unsigned int GetSubstructByte0x1c(unsigned char*);
unsigned int GetSubstructByte0x1e(unsigned char*);
extern "C" void func_ov025_021e12f8(unsigned char* seen, int pos, int val, unsigned char kind, int a, int b);

static inline void SetCell021e13e0(unsigned char* seen, unsigned int pos, unsigned char val) {
    if (pos < 0x51) {
        seen[pos] = val;
    }
}

// USA: func_ov025_021e13e0
extern "C" ARM void func_ov025_021e13e0(unsigned char* seen, Ent021e13e0* ent) {
    if (ent == 0 || ent->obj == 0) {
        return;
    }
    unsigned int pos = GetSubstructByte0x1c((unsigned char*)ent->obj);
    if (pos < 0x51) {
        SetCell021e13e0(seen, pos, ent->val);
    }
    pos = GetSubstructByte0x1e((unsigned char*)ent->obj);
    if (pos < 0x51) {
        SetCell021e13e0(seen, pos, ent->val);
    }
    Combatant021e13e0* obj = ent->obj;
    if (!(obj->flags & 0x400) || obj->sub148 == 0) {
        return;
    }
    unsigned int kind = (obj->sub148->flags << 1) >> 30;
    if (kind == 0) {
        return;
    }
    func_ov025_021e12f8(seen, pos, ent->val, kind, 0, 0);
}
