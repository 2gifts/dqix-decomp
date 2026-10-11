#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct5e00;
struct Container02070e60;
struct BinarySearchByComparatorStruct;
struct Obj02048850;
struct Param02048850;
struct Bytes02033b88;

extern "C" GameObject* _Z25GetCombatantWithFlag0x400P9GameStatei(GameState* gameState, int combatantId);
extern "C" void _Z24FindOrAssignSlot02167c28Phi(unsigned char* obj, int id);
extern "C" unsigned char* _Z33SearchWithLow15Comparator02070fd0P17Container02070e60i(struct Container02070e60* table, int key);
extern "C" struct Param02048850* _Z28SearchWithComparator0206f4f0P30BinarySearchByComparatorStructi(struct BinarySearchByComparatorStruct* table, int key);
extern "C" void _Z22ResetNameState02048614Ph(unsigned char* obj);
extern "C" void func_02049c88(unsigned char* obj, int v);
extern "C" void _Z28SetupFieldsFromParam02048850P11Obj02048850P13Param02048850(struct Obj02048850* obj, struct Param02048850* param);
extern "C" void _Z24CopyObjectFields02048588PhS_(unsigned char* dst, unsigned char* src);
void SetByte0xbeShiftPrev(struct Bytes02033b88* obj, int v);
extern "C" void _Z17CopyBlob_02161dfcPhS_(unsigned char* dst, unsigned char* src);
extern "C" void _Z17BuildName020488ecPc(char* obj);
extern "C" void _Z21SyncNameFlag_02161274P10GameObject(GameObject* obj);
extern "C" void _Z37AllocateSlotAndConfigureField02166784P10Struct5e00PhS1_(struct Struct5e00* obj1, unsigned char* obj2, unsigned char* obj3);
extern "C" void _Z18ClearCombatantSlotP9GameStatei(GameState* gameState, int id);

struct Node02161c0c {
    char pad0[2];
    short key;
};

struct PartyEntry02161c0c {
    char pad0[0x11];
    signed char ids[8];
    unsigned char count;
};

// USA: func_ov000_02161c0c
extern "C" ARM void func_ov000_02161c0c(unsigned char* obj, int id) {
    GameState* gs = GameState::GetInstance();
    unsigned char* c = (unsigned char*)_Z25GetCombatantWithFlag0x400P9GameStatei(gs, id);
    unsigned char* data = *(unsigned char**)(obj + 0x2a0);
    struct Container02070e60* entries = (struct Container02070e60*)(data + 0x684);
    struct BinarySearchByComparatorStruct* infos = (struct BinarySearchByComparatorStruct*)(data + 0x678);
    struct Node02161c0c* found = 0;
    unsigned short key = *(unsigned short*)(c + 0x186);
    for (int i = 0; i < 4; i++) {
        struct Node02161c0c* node = *(struct Node02161c0c**)(obj + i * 4 + 0xeb8);
        if (node == 0) continue;
        if (key == node->key) {
            found = node;
            break;
        }
    }
    if (found == 0) return;

    _Z24FindOrAssignSlot02167c28Phi(obj, id);
    unsigned short kind = *(unsigned short*)(c + 0x186);
    unsigned char slot = c[0x18c];
    unsigned char mode = c[0x18d];
    int param = *(int*)(c + 0x13c);
    unsigned char* entry = _Z33SearchWithLow15Comparator02070fd0P17Container02070e60i(entries, kind);
    struct Param02048850* info = _Z28SearchWithComparator0206f4f0P30BinarySearchByComparatorStructi(infos, (short)kind);
    unsigned char* blob = *(unsigned char**)(obj + 0x2a0) + 0x158 + (id - 0xc0) * 0xa4;

    _Z22ResetNameState02048614Ph(c);
    *(short*)(c + 4) = id;
    func_02049c88(c, param);
    *(unsigned char**)(c + 0x148) = entry;
    _Z28SetupFieldsFromParam02048850P11Obj02048850P13Param02048850((struct Obj02048850*)c, info);
    _Z24CopyObjectFields02048588PhS_((unsigned char*)found, c);
    ((Object3D*)c)->SetField06(*(unsigned short*)(obj + 0xec8));
    c[0x17c] = slot;
    SetByte0xbeShiftPrev((struct Bytes02033b88*)c, 0);
    *(unsigned char**)(c + 0x138) = blob;
    _Z17CopyBlob_02161dfcPhS_(blob, entry + 0x6c);
    (*(unsigned char**)(c + 0x138))[0x25] = mode;
    _Z17BuildName020488ecPc((char*)c);
    c[0xc2] |= 0x20;
    c[0x18d] = mode;
    if (mode == 2) {
        _Z21SyncNameFlag_02161274P10GameObject((GameObject*)c);
    }
    _Z37AllocateSlotAndConfigureField02166784P10Struct5e00PhS1_((struct Struct5e00*)obj, (unsigned char*)found, c);

    int group = slot;
    obj = *(unsigned char**)(obj + 0x29c) + 0x81b0;
    for (id = 0; id < ((struct PartyEntry02161c0c*)(obj + group * 0x18))->count; id++) {
        _Z18ClearCombatantSlotP9GameStatei(gs, (short)(((struct PartyEntry02161c0c*)(obj + group * 0x18))->ids[id] + 0xc0));
    }
    memset(obj + 0x11 + slot * 0x18, 0, 8);
    (obj + slot * 0x18)[0x19] = 0;
}
