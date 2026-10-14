#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct SlotEntry020da244 {
    unsigned char pad0[8];
    int field8;
};

struct BattleManagerCtx020da244 {
    void* f0;
    int f4;
    unsigned char pad8[0xc - 0x8];
    unsigned char fc;
    unsigned char fd;
    unsigned char fe;
    unsigned char ff;
    unsigned char pad10[0x14 - 0x10];
    SlotEntry020da244 slots[4];
};

void RunCombatFlagStateAction(void* ctx);
void ResetFields020da2e4(unsigned char* entry);
extern "C" void _ZN13SafeAllocator7DestroyEv(void* self);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void* self);

// USA: func_020da244  (semantic: ResetBattleManagerState_020da244)
extern "C" ARM void func_020da244(BattleManagerCtx020da244* sb) {
    RunCombatFlagStateAction(sb);
    SlotEntry020da244* entry = sb->slots;
    int commandId = (int)BackgroundLoader::GetInstance();
    if (commandId != 0) {
        for (unsigned char i = 0; i < 4; i++, entry++) {
            if (entry->field8 != -1) {
                ((BackgroundLoader*)(commandId))->RemoveTask((int)(entry->field8 != -1));
                ResetFields020da2e4((unsigned char*)entry);
            }
        }
    }
    if (sb->f0 != 0) {
        _ZN13SafeAllocator7DestroyEv(sb->f0);
        _ZN13SafeAllocator21ResetAllocatorPointerEv(sb->f0);
    }
    sb->f0 = 0;
    sb->f4 = 0;
    sb->fc = 0;
    sb->fd = 0;
    sb->fe = 0;
    sb->ff = 0;
}
