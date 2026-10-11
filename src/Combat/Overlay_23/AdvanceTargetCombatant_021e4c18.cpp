#include <globaldefs.h>
#include "GameState/GameState.h"

int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern "C" int func_ov023_021e29d0(char* obj);
extern "C" void func_ov023_021e2ce8(int combatantId, void* p1);
struct EntryList0204af14;
void* GetEntryByIndexStride0x10(struct EntryList0204af14* list, unsigned int index);
extern "C" void func_020dc7e8(int a, int b);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern struct Obj0205eaa0 data_02108760;
extern "C" void func_ov005_021551d4(void* p);
void DispatchByIdxAndCond021551fc(char* base, unsigned char byteVal, int cond);
typedef void (*DispatchFn021551fc)(char*, int, int);

extern unsigned char data_02114e54;
extern unsigned short data_02114e30;

struct Obj021e4c18 {
    void* f0;
    char pad1[0xc8 - 0x4];
    void* fc8;
    char pad2[0xd4 - 0xcc];
    char fd4[1];
#if defined(jpn)
    char pad3[0x130 - 0xd5];
#else
    char pad3[0x134 - 0xd5];
#endif

    int f134;
    char pad4[0x4e5 - 0x138];
    signed char f4e5;
    char pad5[0x4e8 - 0x4e6];
    int f4e8;
    int arr4ec[4];
    int f4fc;
#if defined(jpn)
    char pad6[0x56c - 0x4fc];
#else
    char pad6[0x634 - 0x500];
#endif

    unsigned short f634;
};

// JPN: func_ov023_021e4e20
// USA: func_ov023_021e4c18  (semantic: AdvanceTargetCombatant_021e4c18)  (semantic: AdvanceTargetCombatant_021e4c18)
extern "C" ARM void func_ov023_021e4c18(struct Obj021e4c18* obj) {
#if defined(jpn)
 enum {regionalOffset0=0xe80, regionalOffset1=0x3d44};
#else
 enum {regionalOffset0=0xe84, regionalOffset1=0x3dcc};
#endif
    unsigned short flags = obj->f634;
    if (flags & 0x40) return;
    if (!(flags & 0x80)) return;

    GameState* battleStruct = GameState::GetInstance();

    int index = -1;
    int i;
    for (i = 0; i < 4; i++) {
        if (obj->f4fc == obj->arr4ec[i]) {
            index = i;
            break;
        }
    }

    int five = 0;
    if (*((unsigned char*)&data_02114e54 + 0x55) != 0) {
        if (func_ov023_021e29d0((char*)obj + 0xd4) == 0x21) five = 1;
    }
    if (!five) {
        if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x800) != 0) five = 1;
    }
    if (!five) return;

    GameObject* combatant;
    for (;;) {
        index = index + five;
        if (index < 0) index = obj->f4e8 - 1;
        if (index > obj->f4e8 - 1) index = 0;
        combatant = battleStruct->GetGameObjectByIndex(obj->arr4ec[index]);
        if (combatant != 0) break;
    }

    if (obj->f4fc == obj->arr4ec[index]) return;

    obj->f634 |= 0x400;

    if (obj->f0 != 0) {
        int rawId = obj->arr4ec[index];
        signed char sid = (signed char)rawId;
        struct EntryList0204af14* list = (struct EntryList0204af14*)((char*)obj->f0 + regionalOffset0);
        if (list != 0) {
            if (GetEntryByIndexStride0x10(list, 1) != 0) {
                func_020dc7e8(5, sid);
            }
        }
    }

#if defined(jpn)

#else
    func_ov023_021e2ce8(obj->arr4ec[index], obj->fc8);
#endif


    combatant = battleStruct->GetGameObjectByIndex(obj->arr4ec[index]);
    unsigned short cflags = combatant->obj3D_.unknown_0_;
    if ((cflags & 0x1000) || (cflags & 0x800) || (cflags & 0x200)) {
        if (obj->f134 > 0) return;

        obj->f4fc = obj->arr4ec[index];
        obj->f634 = obj->f634 | 0x54;

        DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);

        if (obj->f4e5 != 3) return;
        if (obj->f0 == 0) return;

        func_ov005_021551d4(obj->f0);
        *(int*)((char*)obj->f0 + regionalOffset1) |= 0x200;
        ((DispatchFn021551fc)(void*)&DispatchByIdxAndCond021551fc)((char*)obj->f0, obj->f4fc, 1);
    }
}
