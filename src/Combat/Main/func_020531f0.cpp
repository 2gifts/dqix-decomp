#include <globaldefs.h>
#include <std_library_functions.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

int GetIndexedEntryField0x178(signed char* obj);
extern "C" void _Z32ForwardToTargetOrDefault0205eabcPvS_i(void* target, void* param, int arg);
int GetByte0x26c(char* obj);
int GetField0x397cValue(GameState* battleStruct);
int GetFieldIfFlag4(char* obj);
int TestFlagMask(unsigned short* word, int mask);
void SetByte0x2c4To2IfByte0x2c5Set(unsigned char* p);
extern "C" void* _Z26GetGlobalField0x1c020421a0v(void);

struct Bytes02033b88;
void SetByte0xbeShiftPrev(struct Bytes02033b88* obj, int value);

extern "C" void _ZN8Object3D26RemoveAnimationPackageByIDEi(void* obj, int packageId);
extern "C" void func_ov017_021cc1f8(int id, const char* src, int len, int extra);

extern char data_02108760;
extern unsigned short data_02114e30;

struct EntryFlags020531f0 {
    unsigned char mode : 2;
    unsigned char rest : 6;
};

struct Obj020531f0 {
    unsigned short flags;
    char pad2[0x4 - 0x2];
    short charId;
    char pad6[0xb2 - 0x6];
    unsigned short fieldB2;
    char padB4[0xc1 - 0xb4];
    struct EntryFlags020531f0 entryFlags;
    char padC2[0x178 - 0xc2];
    signed char animEntries[4];
    signed char count;
    signed char cursor;
    signed char state;
    signed char animReady;
    int taskId;
    signed char delay;
    signed char pendingRefresh;
    signed char pendingAdvance;
    char pad187[0x190 - 0x187];
    int field190;
    int taskId2;
};

// USA: func_020531f0
extern "C" ARM void func_020531f0(struct Obj020531f0* obj) {
    BackgroundLoader* loader;
    GameState* battleStruct;
    signed char eventBuf[4];
    int target;
    int cid;

    loader = BackgroundLoader::GetInstance();
    if (obj->taskId > -1) {
        loader->RemoveTask(obj->taskId);
        obj->taskId = -1;
    }

    if (GetIndexedEntryField0x178((signed char*)obj) == 0x19) {
        _Z32ForwardToTargetOrDefault0205eabcPvS_i((void*)&data_02108760, (char*)obj + 0x198, 0);
    }

    memset(obj->animEntries, 0, 4);
    obj->count = 0;
    obj->cursor = 0;
    obj->taskId = -1;
    obj->state = 0;
    obj->animReady = 0;
    obj->delay = 0;

    if (obj->taskId2 > -1) {
        loader->RemoveTask(obj->taskId2);
        obj->taskId2 = -1;
    }

    obj->field190 = 0;
    obj->taskId2 = -1;
    obj->pendingRefresh = 0;
    obj->pendingAdvance = 0;

    if ((obj->flags & 0x200) != 0) {
        if (GetByte0x26c((char*)obj) != 0) {
            return;
        }
    }

    obj->entryFlags.mode &= ~2;
    _ZN8Object3D26RemoveAnimationPackageByIDEi((void*)obj, 2);
    obj->fieldB2 = 0;
    SetByte0xbeShiftPrev((struct Bytes02033b88*)obj, 0);

    battleStruct = GameState::GetInstance();
    cid = obj->charId;
    int activeId = GetField0x397cValue(battleStruct);
    if (activeId == cid) {
        target = GetFieldIfFlag4((char*)battleStruct);
        if (target != 0) {
            if (TestFlagMask(&data_02114e30, 2) == 0
                || ((unsigned char*)_Z26GetGlobalField0x1c020421a0v())[0x19b1] != 0) {
                SetByte0x2c4To2IfByte0x2c5Set((unsigned char*)target);
            }
        }
    }

    func_ov017_021cc1f8(obj->charId, (const char*)eventBuf, 0, 1);
}
