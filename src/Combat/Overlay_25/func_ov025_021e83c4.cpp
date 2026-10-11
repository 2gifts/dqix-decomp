// JPN: func_ov025_021e8864
#if defined(jpn)
enum { RegionOffset150 = 0x144, TargetFieldOffset = 0x4 };
#else
enum { RegionOffset150 = 0x150, TargetFieldOffset = 0xc };
#endif

#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"

void* GetArrayEntry_021e8a54_021e8a54(char* obj);
int FindTagAndCopy_021e24d0(char* s, char* out2, char* out1);

struct SearchObj0202ffd8;
struct SearchObj0202ff34;
int DispatchByIndex021820bc(void* obj, int unused, int index, int arg);
extern "C" void func_ov025_021e267c(int combatantId, int arg1, int arg2, int flag);
struct RemoveList021eb084;
void RemoveMatchingShort_021eb084(struct RemoveList021eb084* obj, int val);

struct Ctx021e83c4 { char pad[TargetFieldOffset]; void* target; };
extern struct Ctx021e83c4 data_ov025_021ef988;
extern char data_ov025_021ef87f;

struct Param021e83c4 {
    char pad[8];
    unsigned char field8;
};

struct Ctx1021e83c4 { char pad[0x10]; void* field0x10; };

struct Inner021e83c4 { char pad[0x49c]; unsigned char flag : 1; };

// USA: func_ov025_021e83c4
extern "C" ARM int func_ov025_021e83c4(struct Param021e83c4* p, struct Ctx1021e83c4* ctx, int unusedR2, void* dispatchObj) {
    GameState* bs = GameState::GetInstance();
    int handle = (int)BackgroundLoader::GetInstance();
    GetArrayEntry_021e8a54_021e8a54((char*)data_ov025_021ef988.target);

    int cid = *(unsigned short*)((char*)ctx->field0x10 + 0x20);
    GameObject* c = GetCombatantWithFlag0x100(bs, cid);
    struct Inner021e83c4* c2 = *(struct Inner021e83c4**)((char*)c + RegionOffset150);
    char ch = 'm';
    if (c2->flag == 1) {
        ch = 'w';
    }

    char buf[0x50];
    sprintf(buf, &data_ov025_021ef87f, ch);

    char name1[0x50];
    char name2[0x50];
    int out1 = 0;
    int out2;
    int id;
    if (FindTagAndCopy_021e24d0(buf, name1, name2)) {
        id = ((BackgroundLoader*)((struct SearchObj0202ffd8*)handle))->GetLoadedFileInArchive((const char*)(name1), (const char*)(name2), (void**)(&out1), (unsigned int*)(&out2));
    } else {
        id = ((BackgroundLoader*)((struct SearchObj0202ff34*)handle))->GetLoadedFileByName((const char*)(buf), (void**)(&out1), (unsigned int*)(&out2));
    }

    if (out1 != 0) {
        int ids[8];
        int count = DispatchByIndex021820bc(dispatchObj, (int)ctx, p->field8, (int)&ids[0]);
        if (count > 0) {
            for (int i = 0; i < count; i++) {
                func_ov025_021e267c(ids[i], out1, out2, 0);
            }
        }
    }

    ((BackgroundLoader*)(handle))->RemoveTask((int)(id));
    RemoveMatchingShort_021eb084((struct RemoveList021eb084*)data_ov025_021ef988.target, id);
    return 1;
}
