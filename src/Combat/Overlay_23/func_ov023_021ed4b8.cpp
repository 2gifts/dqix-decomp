#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);

int GetField0x3acValue(GameState* battleStruct);
int GetGlobalField0x1c020421a0(void);
void InitObjFromCombatantId020e4bf4(void* obj, int combatantId);

struct Obj02046574;
void SetIndexedName02046574(struct Obj02046574* obj, int index, char* str);

extern "C" void func_02046380(void* global);
extern "C" void func_02046608(int a, int b, void* c, void* d, int e, int f, int g);
#if defined(jpn)
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g);
void AppendString02042058(char*, const char*);
#else
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif


struct Bits0205de24_021ed4b8 { unsigned char low4 : 4; unsigned char high4 : 4; };

// JPN: func_ov023_021ed3f0
// USA: func_ov023_021ed4b8  (semantic: InitAndDispatchElementEntry_021ed4b8)
extern "C" ARM void func_ov023_021ed4b8(char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x15c, regionalOffset1=0x800};
#else
 enum {regionalOffset0=0x244, regionalOffset1=0x960};
#endif
    unsigned char keyLow = ((struct Bits0205de24_021ed4b8*)(obj + 0xc0))->low4;
    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(obj + 0xc4), keyLow, 3);

    *(unsigned short*)(obj + 0x164) = 0x1e;
#if defined(jpn)
    *(unsigned short*)(obj + 0x166) = 6;
#else
    *(unsigned short*)(obj + 0x166) = 0x7;
#endif

    *(unsigned short*)(obj + 0x168) = 0x1;
    *(unsigned short*)(obj + 0x16a) = 0x9;
#if defined(jpn)
    *(unsigned short*)(obj + 0x16c) = 0xa;
#else
    *(unsigned short*)(obj + 0x16c) = 0x7;
#endif

    *(unsigned short*)(obj + 0x16e) = 0xa;
    *(unsigned short*)(obj + 0x170) = 0xc;
#if defined(jpn)
    *(unsigned short*)(obj + 0x172) = 0x14;
#else
    *(unsigned short*)(obj + 0x172) = 0xc;
#endif

    *(unsigned char*)(obj + 0x17b) = 0xc;
    *(unsigned char*)(obj + 0x175) = 2;
    unsigned char zero = 0;
    *(unsigned char*)(obj + 0x179) = zero;
    *(unsigned char*)(obj + 0x17a) = zero;

    unsigned char idx = *(unsigned char*)(obj + 0x28);
    char* base = *(char**)(obj + 0x20);
    char* elem = base + idx * regionalOffset0;

    memset(*(void**)(obj + 0x1c), zero, regionalOffset1);

#if defined(jpn)
    int key = GetFieldByKey020e0434((struct Container020e0310*)(obj + 4), 0x64);
    AppendString02042058(*(char**)(obj + 0x1c), (char*)key);
    GameState* bs = GameState::GetInstance();
#else
    GameState* bs = GameState::GetInstance();
#endif

    int id = GetField0x3acValue(bs);
    GameObject* combatant = GetCombatantWithFlag0x100(bs, id);
    if (combatant == NULL) return;

    int g = GetGlobalField0x1c020421a0();
    func_02046380((void*)g);

#if defined(jpn)
    SetIndexedName02046574((struct Obj02046574*)g, 0, *(char**)((char*)combatant + 0x134));
    SetIndexedName02046574((struct Obj02046574*)g, 1, elem + 0xc);

#else
    char localbuf[0xc];
    int combatantId = *(short*)((char*)combatant + 0x4);
    InitObjFromCombatantId020e4bf4(localbuf, combatantId);

    *(void**)((char*)g + 0x0) = localbuf;
    SetIndexedName02046574((struct Obj02046574*)g, 1, elem + 0xc);

    int key = GetFieldByKey020e0434((struct Container020e0310*)(obj + 0x4), 0x64);
    func_02046608(g, 1, (void*)(long)key, *(void**)(obj + 0x1c), 0xe3, 0, 1);


#endif
#if defined(jpn)
    func_0205d304(obj + 0xc4, *(void**)(obj + 0x1c), 0, 0, 0, 0, 0);
#else
    func_0205d304(obj + 0xc4, *(void**)(obj + 0x1c), 0, 0, 0, 0, 0, 1);
#endif

}
