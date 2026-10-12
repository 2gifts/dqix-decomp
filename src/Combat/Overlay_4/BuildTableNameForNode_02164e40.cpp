#include <globaldefs.h>
#if defined(jpn)
#define func_ov004_02164e40 func_ov004_02165570
extern char data_ov004_02170e42;
extern char data_ov004_02170598;
void* GetField0x649eForValidIndex(char*, unsigned int);
#endif
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "System/Memory.h"

int GetGlobalField0x1c020421a0();
extern "C" void func_02046380(void* obj);
int GetField0x3acValue(GameState* battleStruct);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void*);

struct Obj021f9bb0 {
    char pad[0x28];
    unsigned short field28;
};
unsigned int GetShort28_021f9bb0(struct Obj021f9bb0* obj);

struct NameBuf02046574 { char c[0x40]; };
struct Obj02046574 {
    char pad[0x4ac];
    struct NameBuf02046574 names[16];
};
void SetIndexedName02046574(struct Obj02046574* obj, int index, char* str);
void CopyStringToIndexedField0x2ec(char* base, int index, char* src);

extern unsigned char* data_ov004_02171010;

// USA: func_ov004_02164e40  (semantic: BuildTableNameForNode_02164e40)
extern "C" ARM int func_ov004_02164e40(void* obj) {
    void* g = (void*)GetGlobalField0x1c020421a0();
    func_02046380(g);

    GameState* battle = GameState::GetInstance();
    GetField0x3acValue(battle);
    GameObject* combatant = battle->GetUnknownGameObject();

    void* node = func_ov023_021f6880(func_ov011_021849c8(obj), 0xa);
    if (!node) return 0;
    if (func_ov023_021f6f10(node) != 7) return 0;

    unsigned int idx = GetShort28_021f9bb0((struct Obj021f9bb0*)node);

#if defined(jpn)
    char prefix[32];
    char suffix[32];
    char mapKind[32];
    char level[32];
    VectorizedMemset(prefix, 0, 32);
    VectorizedMemset(suffix, 0, 32);
    VectorizedMemset(mapKind, 0, 32);
    VectorizedMemset(level, 0, 32);

    unsigned int off = idx * 0x1e4;
    unsigned char* base = data_ov004_02171010;
    unsigned char* kindRow = base + 0xad5;
    kindRow = kindRow + off;
    unsigned char kind = *kindRow;
    if (kind == 1) {
        char* row = (char*)base + 0xb20 + off;
        strcpy(prefix, row + 0x3b);
        char* suffixRow = (char*)data_ov004_02171010 + 0xb20;
        suffixRow = suffixRow + off;
        strcpy(suffix, suffixRow + 0x5b);
        strcpy(mapKind, &data_ov004_02170e42);
        char* levelRow = (char*)data_ov004_02171010 + 0xb20;
        levelRow = levelRow + off;
        strcpy(level, levelRow + 0x9b);
    } else if (kind == 2) {
        char* row = (char*)base + 0xb20 + off;
        strcpy(prefix, row + 0x90);
        char* suffixRow = (char*)data_ov004_02171010 + 0xb20;
        suffixRow = suffixRow + off;
        strcpy(suffix, suffixRow + 0xb0);
        strcpy(mapKind, &data_ov004_02170598);
        char* levelRow = (char*)data_ov004_02171010 + 0xb20;
        levelRow = levelRow + off;
        strcpy(level, levelRow + 0xd0);
    }
    if (combatant) {
        SetIndexedName02046574((Obj02046574*)g, 0, (char*)combatant->baseStats_);
    }
    SetIndexedName02046574((Obj02046574*)g, 1, prefix);
    SetIndexedName02046574((Obj02046574*)g, 2, suffix);
    SetIndexedName02046574((Obj02046574*)g, 3, mapKind);
    SetIndexedName02046574((Obj02046574*)g, 4, level);
    SetIndexedName02046574((Obj02046574*)g, 5, (char*)GetField0x649eForValidIndex((char*)battle, 0));
    SetIndexedName02046574((Obj02046574*)g, 6, (char*)GetField0x649eForValidIndex((char*)battle, 1));
    SetIndexedName02046574((Obj02046574*)g, 7, (char*)GetField0x649eForValidIndex((char*)battle, 2));
    SetIndexedName02046574((Obj02046574*)g, 8, (char*)GetField0x649eForValidIndex((char*)battle, 3));
#else
    char buf[0x40];
    VectorizedMemset(buf, 0, 0x40);

    unsigned char* base = data_ov004_02171010;
    unsigned int off = idx * 0x1c4;
    unsigned char* krow = base + 0xad5;
    krow = krow + off;
    unsigned char kind = *krow;
    if (kind == 1) {
        char* row = (char*)base + 0xb20;
        row = row + off;
        strcpy(buf, row + 0x63);
    } else if (kind == 2) {
        char* row = (char*)base + 0xb20;
        row = row + off;
        strcpy(buf, row + 0xf8);
    }

    if (combatant) {
        char* name = (char*)combatant->baseStats_;
        SetIndexedName02046574((struct Obj02046574*)g, 0, name);
    }
    CopyStringToIndexedField0x2ec((char*)g, 0, buf);
#endif
    return 0;
}
