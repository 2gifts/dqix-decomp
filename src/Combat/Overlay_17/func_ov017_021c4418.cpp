// JPN: func_ov017_021cc9a0
#include <globaldefs.h>

#if defined(jpn)
enum { kSlotFieldOffset = 0x8b8 };
#else
enum { kSlotFieldOffset = 0x950 };
#endif

#include "GameState/GameState.h"

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
GameObject* GetCombatantWithFlag0x100(GameState* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);

extern "C" void func_ov017_021c41fc(int combatantId, signed char flag10);
extern "C" ARM void func_ov017_021c4418(int combatantId, signed char flag10);
ARM void EnqueueNameTag3_021c45b4(int combatantId);
extern "C" void func_ov017_021ce704(int combatantId);
extern "C" ARM void func_ov017_021cf078(int combatantId, unsigned short slot, unsigned char flag);
extern "C" void func_ov017_021c3fb4(int combatantId, int flag);
extern "C" void func_ov017_021cc730(int combatantId, int b, int c, int d);
extern "C" ARM void func_ov017_021ccc34(int combatantId);
extern "C" void func_ov017_021ce524(short combatantId);
extern "C" void func_ov017_021ccdac(int combatantId);
extern "C" void func_ov017_021ccfd0(int combatantId);
ARM void EnqueueEventTag38_021ce32c(int id);
ARM void EnqueueEventTag20_021cee78(int id, unsigned char b);
extern "C" void func_ov017_021cff8c(int combatantId, int b);
ARM void EnqueueEventTag22_021cfed0(unsigned char a, unsigned char b);
extern "C" void func_ov017_021c9e00(int combatantId, int b, int c, int d);

struct DispatchArgs021cc4f8 {
    unsigned char pad0[4];
    unsigned char id;
    unsigned char tag;
    unsigned char pad1[2];
    unsigned int flags;
};

// USA: func_ov017_021cc4f8  (semantic: DispatchPendingEventFlags_021cc4f8)
extern "C" ARM void func_ov017_021cc4f8(signed char flag, struct DispatchArgs021cc4f8* args, GameState* bs, int unused, struct SearchStruct0202c1a4* search) {
    int id = args->id;
    signed char cur = GetSearchStructCurrentArrEntry(search);
    if (args->tag != cur) return;

    int needsFinalize = 0;
    unsigned int flags = args->flags;

    if (flags & 0x2) {
        func_ov017_021c41fc(id, flag);
        func_ov017_021c4418(id, flag);
    }
    if (flags & 0x4) {
        EnqueueNameTag3_021c45b4(id);
    }
    if (flags & 0x8) {
        func_ov017_021ce704(id);
        GameObject* c = GetCombatantWithFlag0x100(bs, id);
        if (c) {
            int f150 = GetFieldAt0x150((unsigned char*)c);
            unsigned char slot = *(int*)((char*)f150 + kSlotFieldOffset) & 0xff;
            func_ov017_021cf078(id, slot, 1);
        }
        needsFinalize = 1;
    }
    if (flags & 0x1) {
        func_ov017_021c3fb4(id, 1);
        needsFinalize = 1;
    }
    if (flags & 0x10) {
        func_ov017_021cc730(id, 0, 0, 1);
        func_ov017_021ccc34(id);
        func_ov017_021ce524((short)id);
    }
    if (flags & 0x40) {
        func_ov017_021ccdac(id);
    }
    if (flags & 0x20) {
        func_ov017_021ccfd0(id);
        needsFinalize = 1;
    }
    if (flags & 0x80) {
        EnqueueEventTag38_021ce32c(id);
    }
    if (flags & 0x100) {
        EnqueueEventTag20_021cee78(id, 0);
    }
    if (flags & 0x800) {
        func_ov017_021cff8c(id, 0);
    }
    if (flags & 0x200) {
        EnqueueEventTag22_021cfed0((unsigned char)flag, (unsigned char)id);
    }
    if (needsFinalize) {
        func_ov017_021c9e00(id, 1, 0, 1);
    }
    if (!(flags & 0x1000)) return;
    func_ov017_021c9e00(id, 1, 0, 1);
}
