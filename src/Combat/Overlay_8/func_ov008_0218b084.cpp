#if defined(jpn)
#define R(j,u) (j)
#define data_ov008_0218b594 data_ov008_0218c1aa
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "System/OverlayId.h"

struct S021b2ba0;
struct TailList020469b4;
struct TailNode020469b4;
struct SafeAllocator;

extern "C" void* func_ov017_0218b5b0();
extern "C" void _Z30SetByteB10AndClearB11_02184a3cPch(char* obj, unsigned char value);
extern "C" void func_ov008_02184754(void* obj);
extern "C" void func_ov008_021845ac(void* obj);
extern "C" void _Z29SetCombatModeFromCase020dc2d0i(int mode);
extern "C" void _Z21InitObjState_021b2174Ph(unsigned char* obj);
extern "C" void _Z23SetNameChecked_021b2ba0P9S021b2ba0Pc(S021b2ba0* obj, char* name);
extern "C" void _Z25SetFields30And34_021b2bd0Pvii(void* obj, int handler, int overlayId);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
extern "C" void _Z29AllocateAndCopyBuf76_0216aa70P13SafeAllocatorPv(SafeAllocator* allocator, void* arg);
extern char data_ov008_0218b594;

struct Manager0218b084 {
    char pad0[0x2a8];
    char f2a8[0xdb8 - 0x2a8];
    unsigned char db8;
    char pad1[R(0xe98,0xe9c) - 0xdb9];
    signed char e9c;
    char pad2[R(0xea8,0xeac) - R(0xe99,0xe9d)];
    int eac;
#if !defined(jpn)
    int eb0;
#endif
    char pad3[R(0xeb0,0xeb8) - R(0xeac,0xeb4)];
    unsigned char eb8;
    char pad4;
    unsigned char eba;
    char pad5[R(0xeb8,0xec0) - R(0xeb3,0xebb)];
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char rest : 6;
};

// USA: func_ov008_0218b084
extern "C" ARM void func_ov008_0218b084(Manager0218b084* self) {
    if (self->e9c == 0) {
        if (!self->bit1) {
            self->e9c = 2;
            return;
        }
        _Z30SetByteB10AndClearB11_02184a3cPch(self->f2a8, 0xd);
        self->e9c = self->e9c + 1;
        return;
    }
    if (self->e9c == 1) {
        func_ov008_02184754(self->f2a8);
        if (self->db8 != 0xe) {
            return;
        }
        func_ov008_021845ac(self->f2a8);
        self->e9c = self->e9c + 1;
        return;
    }
    if (self->e9c != 2) {
        return;
    }
    void* res = func_ov017_0218b5b0();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    loader->RemoveTask(self->eac);
#if !defined(jpn)
    loader->RemoveTask(self->eb0);
    self->eac = -1;
    self->eb0 = -1;
#endif
    unsigned short* bgcnt = (unsigned short*)0x4001008;
    bgcnt[0] = (bgcnt[0] & ~3) | 1;
    bgcnt[1] = (bgcnt[1] & ~3) | 2;
    bgcnt[2] = (bgcnt[2] & ~3);
    _Z29SetCombatModeFromCase020dc2d0i(0);
    if (self->eba != 0) {
        TailList020469b4* list;
        unsigned char* obj = *(unsigned char**)((char*)res + R(0x392c,0x3b4c));
        list = *(TailList020469b4**)((char*)res + R(0x34ec,0x36fc));
        _Z21InitObjState_021b2174Ph(obj);
        _Z23SetNameChecked_021b2ba0P9S021b2ba0Pc((S021b2ba0*)obj, &data_ov008_0218b594);
        _Z25SetFields30And34_021b2bd0Pvii(obj, (int)_Z29AllocateAndCopyBuf76_0216aa70P13SafeAllocatorPv, OVERLAY_ID(4));
        AppendNodeToTail(list, (TailNode020469b4*)obj);
    }
    self->eb8 = 1;
}
