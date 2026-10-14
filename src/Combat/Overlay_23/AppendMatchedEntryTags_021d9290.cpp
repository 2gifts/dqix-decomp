struct Container020e0310;
struct BattleResultMemberName {
    unsigned char id;
    unsigned char vocation;
    unsigned char level;
    unsigned char dead;
    int experience;
#if defined(jpn)
    char name[0xc];
#else
    char name[0x30];
#endif
};

struct BattleResultTagWindow {
    Container020e0310* texts;
    char unknown004[0xc0 - 4];
    short width;
    short height;
    char unknown0c4[0xdc - 0xc4];
    int resultCounts[4];
    char unknown0ec[0x119 - 0xec];
    unsigned char rows;
    char unknown11a[0x120 - 0x11a];
    BattleResultMemberName* members;
    unsigned char memberIds[4];
    unsigned char memberCount;
};

#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

typedef char ResultCountOffsetCheck[offsetof(BattleResultTagWindow, resultCounts) == 0xdc ? 1 : -1];
typedef char ResultMembersOffsetCheck[offsetof(BattleResultTagWindow, members) == 0x120 ? 1 : -1];
typedef char ResultIdsOffsetCheck[offsetof(BattleResultTagWindow, memberIds) == 0x124 ? 1 : -1];
typedef char ResultCountByteOffsetCheck[offsetof(BattleResultTagWindow, memberCount) == 0x128 ? 1 : -1];
typedef char ResultNameOffsetCheck[offsetof(BattleResultMemberName, name) == 8 ? 1 : -1];

struct Container020e0310;
int GetFieldByKey020e0434(Container020e0310*, int);
int GetGlobalField0x1c020421a0(void);
extern "C" int func_020420e8(void*, int);
int AppendXTag(char*, int);
int AppendHeightTag(char*, int);
int AppendFormatted02041fac(char*, int, int);
extern "C" void __clear(void*, int);
void* Find_021d994c(void*, int);
int AppendString02042058(char*, const char*);
extern "C" void func_02046380(int);
ARM void InitObjFromCombatantId020e4bf4(void*, int);
int ApplyEqual12Flag020426a4(int, int);
struct StoreStruct;
void StoreInArray0x8b0(struct StoreStruct*, int, int);
extern "C" void func_02046608(int, int, void*, void*, int, int, int);
int AppendXYTag(char*, int, int);
extern "C" int sprintf(char*, const char*, ...);

struct EntryLocal_021d9290 {
    void* f0;
    void* f4;
    int f8;
};

// USA: func_ov023_021d9290  (semantic: AppendMatchedEntryTags_021d9290)
extern "C" ARM void func_ov023_021d9290(char* obj, char* buf, unsigned char count) {
    BattleResultTagWindow* window = (BattleResultTagWindow*)obj;
    if (!buf) return;

    GameState::GetInstance();
    int g = GetGlobalField0x1c020421a0();

    char* fieldStr = (char*)GetFieldByKey020e0434(window->texts, 0x75f8);
    int len = func_020420e8(fieldStr, 0);
    AppendXTag(buf, (0xc0 - len) >> 1);
    AppendHeightTag(buf, 1);
    AppendFormatted02041fac(buf, (int)fieldStr, 0x10);

    unsigned char* idArr = window->memberIds;
    int a2 = window->height;
    int b = window->rows;
    int loopCount = window->memberCount;
    int found = 0;
    signed char adj = (signed char)(((a2 << 3) - (b * 10 + 0x1d)) / (b - 1));
    int total8 = a2 << 3;

    if (window->members == NULL) return;

    char* fieldStr2 = (char*)GetFieldByKey020e0434(window->texts, 0x75f9);
    int i;
    for (i = 0; i < loopCount; i++) {
        if (window->resultCounts[i] != 0 && count != 0) {
            int id = idArr[i];
            BattleResultMemberName* entry = (BattleResultMemberName*)Find_021d994c(obj, id);
            if (entry != NULL) {
                char buf1[0x100];
                char buf2[0x100];
                __clear(buf1, 0x100);
                __clear(buf2, 0x100);
                if (found != 0) {
                    char* fieldStr0 = (char*)GetFieldByKey020e0434(window->texts, 0);
                    AppendString02042058(buf, fieldStr0);
                    AppendHeightTag(buf, adj);
                }
                func_02046380(g);
                struct EntryLocal_021d9290 local;
                InitObjFromCombatantId020e4bf4(&local, id);
                void* val = entry->name;
                local.f0 = val;
                local.f4 = val;
                *(void**)(g + 0x10) = &local;
                int applyResult = ApplyEqual12Flag020426a4(8, window->resultCounts[i]);
                sprintf(buf2, fieldStr2, 0x94 - applyResult);
                StoreInArray0x8b0((struct StoreStruct*)g, 1, window->resultCounts[i]);
                func_02046608(g, 0xa, buf2, buf1, 0x100, 0, 0);
                AppendString02042058(buf, buf1);
                found = 1;
                count = count - 1;
            }
        }
    }

    if (found == 0) {
        char* fieldStr3 = (char*)GetFieldByKey020e0434(window->texts, 0x75fa);
        int len3 = func_020420e8(fieldStr3, 0);
        len3 = 0xc0 - len3;
        AppendXYTag(buf, len3 >> 1, (total8 - 0x1a) / 2 + 0x10);
        AppendString02042058(buf, fieldStr3);
    }
}
