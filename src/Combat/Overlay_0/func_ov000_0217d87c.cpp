#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

#if defined(jpn)
extern "C" void* func_020e08f0(int index, unsigned int* size);
#endif

struct Struct_0205c570;
struct Obj0205eaa0;
struct Entry_0205d6a0;
struct Struct_0205d81c;
struct Struct_0205def8;
struct TableEntry0217f8c0;
struct Struct0217f8c0;

struct ElemNode {
    char pad0[0x10];
    unsigned char marks[8];
    signed char markIndex;
    char pad19[0x24 - 0x19];
    unsigned char flags;
#if defined(jpn)
    char pad25[0xc7 - 0x25];
#else
    char pad25[0x87 - 0x25];
#endif
    unsigned char field87;
};

struct MenuState {
    char pad0[0x26];
    char field26[0x66 - 0x26];
    short field66;
    char pad68[0x70 - 0x68];
    signed char members[0x17c - 0x70];
    int currentId;
    char pad180[0x188 - 0x180];
    char elements[0x240 - 0x188];
    unsigned char mode;
    char pad241[0x956 - 0x241];
    unsigned char field956;
#if defined(jpn)
    char pad957[0x1f98 - 0x957];
#else
    char pad957[0x1d60 - 0x957];
#endif
    unsigned char modeStack[8];
    signed char depth;
    char pad1d69[2];
    signed char selection;
    char pad1d6c[2];
    signed char activeSum;
    unsigned char field1d6f;
    char pad1d70[2];
    unsigned short flags;
};

extern struct Obj0205eaa0 data_02108760;
extern const char* data_020f2a34;
extern const char* data_020f2a2c;

int GetActiveScaledSum0205d794(Struct_0205c570*);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
void ResetEntryList0205d6a0(Entry_0205d6a0*, int);
struct TableEntry0217f8c0* FindMatchingTableEntry0217f8c0(Struct0217f8c0*);
int CheckFlagsOrField_0217c5f4_0217c5f4(void*);
void SetElementStateIfLess0217a9d0(int, int, int, Struct_0205d81c*);
void SetElementFlag0x20ByKey0205def8(Struct_0205def8*, int, int);
int HasAnyFlags_021719f8_021719f8(int*);
int GetNthSetBit0218158c(void* menu, int index);
void ZeroInit020de848(void* obj);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
extern "C" int func_020de9a4(void* list, void* alloc, void* data, unsigned int size, void* entries, unsigned short count);
extern "C" int func_0207c984(void* party, int id, int bits, void* a, void* b);
extern "C" int func_ov000_0217c594(MenuState* menu, int limit);
extern "C" ElemNode* func_ov000_02161318(MenuState* menu, int id);
extern "C" void func_ov000_02175258(MenuState* menu);
extern "C" void func_ov000_02176634(MenuState* menu, void* entry, int mode, int arg1, int arg2);
extern "C" void func_ov000_0217c638(MenuState* menu, int arg1, int arg2);

// USA: func_ov000_0217d87c
extern "C" ARM void func_ov000_0217d87c(MenuState* menu, int arg1, int arg2) {
    menu->flags |= 0x100;
    signed char prev = menu->activeSum;
    int sum = GetActiveScaledSum0205d794((Struct_0205c570*)menu->elements);
    menu->activeSum = sum;
    int id = menu->members[menu->selection];
    if (prev != sum) {
        return;
    }
    if (func_ov000_0217c594(menu, 5) != 0) {
        menu->field956 = 0;
        GameState* gs = GameState::GetInstance();
        unsigned char* party = (unsigned char*)GetPtrField0x2a04(gs);
        int bits = GetNthSetBit0218158c(menu, menu->activeSum);
        if (func_0207c984(party + 0x1d4, id, bits & 0xff, menu->field26, &menu->field66) != 0) {
            return;
        }
        menu->mode = 6;
        DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
        BackgroundLoader::AddLockGlobal();
#if defined(jpn)
        ((SafeAllocator*)((char*)menu + 0x1bf8))->Reset();
#else
        ((SafeAllocator*)((char*)menu + 0x1af8))->Reset();
#endif
        ZeroInit020de848((char*)menu + 0x100);
        unsigned int size;
#if defined(jpn)
        void* data = func_020e08f0(0, &size);
#else
        void* data = ExtractFileFromGP2(data_020f2a34, data_020f2a2c, &size);
#endif
        if (data != NULL) {
#if defined(jpn)
            func_020de9a4((char*)menu + 0x100, menu->field26 + 0x1bd2, data, size, menu->field26, menu->field66);
#else
            func_020de9a4((char*)menu + 0x100, menu->field26 + 0x1ad2, data, size, menu->field26, menu->field66);
#endif
        }
        BackgroundLoader::RemoveLockGlobal();
        menu->field1d6f = 0;
        menu->depth = menu->depth + 1;
        menu->modeStack[menu->depth] = 7;
        func_ov000_02176634(menu, FindMatchingTableEntry0217f8c0((Struct0217f8c0*)menu), 7, arg1, arg2);
        SetElementStateIfLess0217a9d0(7, menu->field66, 4, (Struct_0205d81c*)menu->elements);
    } else if (CheckFlagsOrField_0217c5f4_0217c5f4(menu) != 0) {
        menu->field956 = 0;
        ElemNode* node = func_ov000_02161318(menu, id);
        if (node == NULL) {
            return;
        }
        if (HasAnyFlags_021719f8_021719f8((int*)node) != 0) {
            node->marks[node->markIndex] = 100;
            node->flags &= ~4;
        }
        GameState* gs = GameState::GetInstance();
        unsigned char count = ((unsigned char*)GetPtrField0x2a04(gs))[0xf7c];
        for (unsigned char i = 0; i < count; i++) {
            int memberId = menu->members[i];
            ElemNode* other = func_ov000_02161318(menu, memberId);
            if (other == NULL) {
                continue;
            }
            if (HasAnyFlags_021719f8_021719f8((int*)other) != 0) {
                continue;
            }
            if (other->field87 != 0) {
                menu->currentId = memberId;
                break;
            }
        }
        func_ov000_02175258(menu);
        ResetEntryList0205d6a0((Entry_0205d6a0*)menu->elements, 0);
        menu->modeStack[menu->depth] = 0;
        menu->depth = menu->depth - 1;
        func_ov000_0217c638(menu, arg1, arg2);
        SetElementFlag0x20ByKey0205def8((Struct_0205def8*)menu->elements, 1, 1);
        SetElementFlag0x20ByKey0205def8((Struct_0205def8*)menu->elements, 1, 2);
        SetElementFlag0x20ByKey0205def8((Struct_0205def8*)menu->elements, 1, 5);
    }
}
