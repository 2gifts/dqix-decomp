#include <globaldefs.h>
#include <std_library_functions.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

int GetIndexedEntryField0x178_02053604(signed char* obj);
void ForwardToTargetOrDefault0205eabc(void* target, void* param, int arg);
int GetByte0x26c_02039d7c(char* obj);
int GetField0x397cValue_020100b0(GameState* battleStruct);
int GetFieldIfFlag4_020100f8(char* obj);
int TestFlagMask_02012430(unsigned short* word, int mask);
void SetByte0x2c4To2IfByte0x2c5Set_020a2c8c(unsigned char* p);
void* GetGlobalField0x1c020421a0(void);

struct Bytes02033b88;
void SetByte0xbeShiftPrev(struct Bytes02033b88* obj, int value);

extern "C" void func_ov017_021cc1f8(int id, const char* src, int len, int extra);

extern char data_02108760;
extern unsigned short data_02114e30;

struct EntryFlags020531f0 {
    unsigned char mode : 2;
    unsigned char rest : 6;
};

struct Obj020531f0 {
    Object3D object;
    char unknown_ac[0xb2 - 0xac];
    unsigned short fieldB2;
    char padB4[0xc1 - 0xb4];
    struct EntryFlags020531f0 entryFlags;
#if defined(jpn)
    char padC2[0x16c - 0xc2];
#else
    char padC2[0x178 - 0xc2];
#endif
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
#if defined(jpn)
    enum { targetOffset = 0x18c, globalByteOffset = 0x17e1 };
#else
    enum { targetOffset = 0x198, globalByteOffset = 0x19b1 };
#endif
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

    if (GetIndexedEntryField0x178_02053604((signed char*)obj) == 0x19) {
        ForwardToTargetOrDefault0205eabc((void*)&data_02108760, (char*)obj + targetOffset, 0);
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

    if ((obj->object.unknown_0_ & 0x200) != 0) {
        if (GetByte0x26c_02039d7c((char*)obj) != 0) {
            return;
        }
    }

    obj->entryFlags.mode &= ~2;
    obj->object.RemoveAnimationPackageByID(2);
    obj->fieldB2 = 0;
    SetByte0xbeShiftPrev((struct Bytes02033b88*)obj, 0);

    battleStruct = GameState::GetInstance();
    cid = obj->object.unknown_4_;
    int activeId = GetField0x397cValue_020100b0(battleStruct);
    if (activeId == cid) {
        target = GetFieldIfFlag4_020100f8((char*)battleStruct);
        if (target != 0) {
            if (TestFlagMask_02012430(&data_02114e30, 2) == 0
                || ((unsigned char*)GetGlobalField0x1c020421a0())[globalByteOffset] != 0) {
                SetByte0x2c4To2IfByte0x2c5Set_020a2c8c((unsigned char*)target);
            }
        }
    }

    func_ov017_021cc1f8(obj->object.unknown_4_, (const char*)eventBuf, 0, 1);
}
