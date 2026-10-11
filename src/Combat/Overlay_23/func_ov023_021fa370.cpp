#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" void* func_ov011_021849c8(void* obj);

struct Struct_021f6bb8 { int unk0; int field4; };
extern "C" int func_ov023_021f6bb8(struct Struct_021f6bb8* obj);
extern "C" void func_ov023_021f6bb0(void* obj, int v);


extern int GetField0x3acValue(GameState* battleStruct);


extern "C" void* __clear(void* dst, int count);

extern char data_ov023_021feb30[];

struct Inner021fa370 {
    char pad[0x49c];
    unsigned char flagBit : 1;
};

struct Obj021fa370 {
    char pad0[0x10];
    char* fmt10;
    char pad1[0x28 - 0x14];
#if defined(jpn)

#else
    char* fmt28;
#endif

    char pad2[0x2c - 0x2c];
    unsigned char kind;
};

struct ObjTail021fa370 {
    char pad[0x1c];
    int field1c;
};

struct Combatant021fa370 {
#if defined(jpn)
    char pad[0x144];
#else
    char pad[0x150];
#endif

    struct Inner021fa370* inner;
};

// JPN: func_ov023_021f97f4
// USA: func_ov023_021fa370
extern "C" ARM int func_ov023_021fa370(struct Obj021fa370* obj, void* param1) {
    void* handleObj;
    int query;
    int handle;
    int zeroPad;
    char buf40[0x20];
    char buf0[0x40];

    handleObj = func_ov011_021849c8(param1);
    query = func_ov023_021f6bb8((struct Struct_021f6bb8*)handleObj);
    if (query >= 0) goto earlyOut;

    handle = (int)BackgroundLoader::GetInstance();
    zeroPad = 0;
    if (obj->kind == 1) {
        GameState* bs = GameState::GetInstance();
        int id = GetField0x3acValue(bs);
        struct Combatant021fa370* combatant = (struct Combatant021fa370*)bs->GetPartyMemberByIndex(id);
        if (combatant != 0) {
            zeroPad = combatant->inner->flagBit;
        }
    } else if (obj->kind == 2) {
        /* zeroPad stays 0 */
    } else if (obj->kind == 3) {
        zeroPad = 1;
    }

#if defined(jpn)
    sprintf(buf40, obj->fmt10, zeroPad);

#else
    if (obj->fmt28 != 0) {
        sprintf(buf40, obj->fmt28, zeroPad);
    } else {
        sprintf(buf40, obj->fmt10, zeroPad);
    }


#endif
    __clear(buf0, 0x40);
    if (strncmp(buf0, data_ov023_021feb30, 5) != 0) {
        strcpy(buf0, data_ov023_021feb30);
    }
    strcat(buf0, buf40);

    {
        int result;
#if defined(jpn)
        result = ((BackgroundLoader*)(handle))->QueueLoadFile(buf0, (SafeAllocator*)0);

#else
        if (obj->fmt28 != 0) {
            memset(buf40, 0, 0x20);
            sprintf(buf40, obj->fmt10, zeroPad);
            result = ((BackgroundLoader*)(handle))->QueueLoadFileInGP2((const char*)((int)buf0), (const char*)((int)buf40), (SafeAllocator*)(0));
        } else {
            result = ((BackgroundLoader*)(handle))->QueueLoadFile((const char*)((int)buf0), (SafeAllocator*)(0));
        }

#endif
        func_ov023_021f6bb0(handleObj, result);
    }
    return 1;

earlyOut:
    return ((struct ObjTail021fa370*)obj)->field1c;
}
