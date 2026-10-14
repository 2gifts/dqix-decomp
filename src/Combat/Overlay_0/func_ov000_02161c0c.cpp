#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct5e00;
struct Container02070e60;
struct BinarySearchByComparatorStruct;
struct Obj02048850;
struct Param02048850;
struct Bytes02033b88;

GameObject* GetCombatantWithFlag0x400_0200fea4(GameState* gameState, int combatantId);
void FindOrAssignSlot02167c28(unsigned char* obj, int id);
unsigned char* SearchWithLow15Comparator02070fd0(struct Container02070e60* table, int key);
struct Param02048850* SearchWithComparator0206f4f0(struct BinarySearchByComparatorStruct* table, int key);
void ResetNameState02048614(unsigned char* obj);
extern "C" void func_02049c88(unsigned char* obj, int v);
void SetupFieldsFromParam02048850(struct Obj02048850* obj, struct Param02048850* param);
void CopyObjectFields02048588(unsigned char* dst, unsigned char* src);
void SetByte0xbeShiftPrev(struct Bytes02033b88* obj, int v);
void CopyBlob_02161dfc(unsigned char* dst, unsigned char* src);
void BuildName020488ec(char* obj);
void SyncNameFlag_02161274(GameObject* obj);
void AllocateSlotAndConfigureField02166784(struct Struct5e00* obj1, unsigned char* obj2, unsigned char* obj3);
void ClearCombatantSlot_0200fd48(GameState* gameState, int id);

struct Node02161c0c {
    char pad0[2];
    short key;
};

struct PartyEntry02161c0c {
    char pad0[0x11];
    signed char ids[8];
    unsigned char count;
};

#if defined(jpn)
enum { kCombatData = 0x21c, kNodes = 0xe34, kField06 = 0xe44, kPartyData = 0x218 };
#else
enum { kCombatData = 0x2a0, kNodes = 0xeb8, kField06 = 0xec8, kPartyData = 0x29c };
#endif

// USA: func_ov000_02161c0c
extern "C" ARM void func_ov000_02161c0c(unsigned char* obj, int id) {
    GameState* gs = GameState::GetInstance();
    unsigned char* c = (unsigned char*)GetCombatantWithFlag0x400_0200fea4(gs, id);
    unsigned char* data = *(unsigned char**)(obj + kCombatData);
    struct Container02070e60* entries = (struct Container02070e60*)(data + 0x684);
    struct BinarySearchByComparatorStruct* infos = (struct BinarySearchByComparatorStruct*)(data + 0x678);
    struct Node02161c0c* found = 0;
    unsigned short key = *(unsigned short*)(c + 0x186);
    for (int i = 0; i < 4; i++) {
        struct Node02161c0c* node = *(struct Node02161c0c**)(obj + i * 4 + kNodes);
        if (node == 0) continue;
        if (key == node->key) {
            found = node;
            break;
        }
    }
    if (found == 0) return;

    FindOrAssignSlot02167c28(obj, id);
    unsigned short kind = *(unsigned short*)(c + 0x186);
    unsigned char slot = c[0x18c];
    unsigned char mode = c[0x18d];
    int param = *(int*)(c + 0x13c);
    unsigned char* entry = SearchWithLow15Comparator02070fd0(entries, kind);
    struct Param02048850* info = SearchWithComparator0206f4f0(infos, (short)kind);
    unsigned char* blob = *(unsigned char**)(obj + kCombatData) + 0x158 + (id - 0xc0) * 0xa4;

    ResetNameState02048614(c);
    *(short*)(c + 4) = id;
    func_02049c88(c, param);
    *(unsigned char**)(c + 0x148) = entry;
    SetupFieldsFromParam02048850((struct Obj02048850*)c, info);
    CopyObjectFields02048588((unsigned char*)found, c);
    ((Object3D*)c)->SetField06(*(unsigned short*)(obj + kField06));
    c[0x17c] = slot;
    SetByte0xbeShiftPrev((struct Bytes02033b88*)c, 0);
    *(unsigned char**)(c + 0x138) = blob;
    CopyBlob_02161dfc(blob, entry + 0x6c);
    (*(unsigned char**)(c + 0x138))[0x25] = mode;
    BuildName020488ec((char*)c);
    c[0xc2] |= 0x20;
    c[0x18d] = mode;
    if (mode == 2) {
        SyncNameFlag_02161274((GameObject*)c);
    }
    AllocateSlotAndConfigureField02166784((struct Struct5e00*)obj, (unsigned char*)found, c);

    int group = slot;
    obj = *(unsigned char**)(obj + kPartyData) + 0x81b0;
    for (id = 0; id < ((struct PartyEntry02161c0c*)(obj + group * 0x18))->count; id++) {
        ClearCombatantSlot_0200fd48(gs, (short)(((struct PartyEntry02161c0c*)(obj + group * 0x18))->ids[id] + 0xc0));
    }
    memset(obj + 0x11 + slot * 0x18, 0, 8);
    (obj + slot * 0x18)[0x19] = 0;
}
