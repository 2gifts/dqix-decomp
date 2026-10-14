#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
#include "Combat/SearchEntry.h"
struct SearchStruct {
    int state;
    unsigned short counter;
    unsigned char padding6[0x7ba];
    struct Selection {
        unsigned short padding;
        unsigned short unused:1;
        unsigned short excluded:4;
        unsigned short unused2:11;
    } selection;
    unsigned char padding7c4[0x7fc];
    int preserveEntries;
    unsigned char paddingfc4[0x4a];
    unsigned char pendingMask;
    unsigned char activeMask;
    unsigned char padding1010;
    unsigned char refill;
    unsigned char padding1012[0x26];
    signed char selectors[16];
    signed char previousSelectors[16];
    int IsActive() const {
        return state != 0;
    }
};
struct FlagWord02046708;
#if defined(jpn)
#define func_0202c04c func_0202bbfc
#endif
unsigned short GetGlobalHalf0x0_0202df58();
void* GetDataPtr02114e04_020d6c00();
int TestFlags02046708(FlagWord02046708*, unsigned int);
int GetGlobalField0x10_0202d6a8();
extern "C" int func_0202d8e8();
extern "C" void func_0202db64(int, int, int);
extern "C" void func_0202bc00(SearchStruct*, int);
extern "C" void func_0202bf40(SearchStruct*);
extern "C" void func_0202c04c(SearchStruct*);
extern "C" int func_0202c508(SearchStruct*);
unsigned short GetEntryField0x4OrFieldA0202bc8c(SearchStruct*);
signed char FindSignedByteIndex_0202bcbc(SearchStruct*, int);
int TestMaskBitBySignedByteIndex_0202bd34(SearchStruct*, int);
void RemoveSearchEntry0202c21c(SearchStruct*, int);
int TestBitBySignedByteIndex_0202c1c0(SearchStruct*, int);
void SetFlagBitAt0xe_0202c5bc(SearchStruct*, int);
void SetSearchFlagBitAt0xc_0202c1e8(SearchStruct*, int);
void SetSearchFlagBit0202c660(SearchStruct*, int);
int GetGlobalField0x48_0202d6b8();

// USA: func_0202b2f0
extern "C" ARM void func_0202b2f0(SearchStruct* object) {
    SearchStruct::Selection* selection;
    unsigned short savedFlags[4];
    unsigned short savedMask[4];
    for (int i = 0; i < 4; i++) {
        if (i == object->selectors[GetGlobalHalf0x0_0202df58()]) {
            continue;
        }
        SearchEntry0202c178* entry = GetEntryBySignedByteIndex_0202c178(object, i);
        if (!entry) {
            continue;
        }
        unsigned int flags = entry->flags.selected;
        entry->flags.selected = 0;
        unsigned short mask = entry->mask;
        savedFlags[i] = flags;
        savedMask[i] = entry->mask;
        entry->mask = mask & ~0xffff;
    }
    GameState::GetInstance();
    if (TestFlags02046708((FlagWord02046708*)GetDataPtr02114e04_020d6c00(), 0x1000000)) {
        object->state = -1;
        return;
    }
    switch (GetGlobalField0x10_0202d6a8()) {
    case 7: {
        int value = func_0202d8e8();
        object->counter++;
        func_0202db64(4, object->counter, value);
        break;
    }
    case 9:
        object->state = -1;
        break;
    }
    switch (object->state) {
    case 2:
        func_0202bc00(object, 1);
        break;
    case 3:
        ShiftRecords0202c478(object);
        break;
    case 5:
        func_0202bc00(object, 1);
        func_0202bf40(object);
        func_0202c04c(object);
        break;
    case 6:
        func_0202bf40(object);
        func_0202c04c(object);
        break;
    }
    if (object->preserveEntries) {
        for (int i = 0; i < 4; i++) {
            if (i == object->selectors[GetGlobalHalf0x0_0202df58()]) {
                continue;
            }
            SearchEntry0202c178* entry = GetEntryBySignedByteIndex_0202c178(object, i);
            if (!entry) {
                continue;
            }
            entry->flags.selected = savedFlags[i];
            entry->mask = (entry->mask & ~0xffff) | savedMask[i];
        }
    } else if (func_0202c508(object)) {
        if (object->refill) {
            unsigned int mask = GetEntryField0x4OrFieldA0202bc8c(object);
            selection = &object->selection;
            unsigned int excluded = selection->excluded;
            for (int i = 1; i < 4; i++) {
                if (!(mask & (1 << i)) || object->selectors[i] != 0) {
                    continue;
                }
                for (int candidate = 1; candidate < 4; candidate++) {
                    if (excluded & (1 << candidate)) {
                        continue;
                    }
                    int found;
                    for (int j = 1; j < 4; j++) {
                        if ((signed char)candidate == object->selectors[j]) {
                            found = 1;
                            goto selectorFound;
                        }
                    }
                    found = 0;
selectorFound:
                    if (!found) {
                        object->selectors[i] = candidate;
                        break;
                    }
                }
            }
        }
        object->pendingMask = 0;
        int index = FindSignedByteIndex_0202bcbc(object, 0);
        if (!(object->activeMask & (1 << index))) {
            selection = &object->selection;
            for (int i = 1; i < 4; i++) {
                int index = FindSignedByteIndex_0202bcbc(object, i);
                if ((object->activeMask & (1 << index)) && !(selection->excluded & (1 << i))) {
                    if (!TestMaskBitBySignedByteIndex_0202bd34(object, i)) {
                        RemoveSearchEntry0202c21c(object, i);
                    }
                } else if (TestBitBySignedByteIndex_0202c1c0(object, i)) {
                    if (!TestMaskBitBySignedByteIndex_0202bd34(object, i)) {
                        SetFlagBitAt0xe_0202c5bc(object, i);
                    }
                } else if (TestMaskBitBySignedByteIndex_0202bd34(object, i)) {
                    SetSearchFlagBitAt0xc_0202c1e8(object, i);
                    SetSearchFlagBit0202c660(object, i);
                    if (object->IsActive()) {
                        GameResources* resources = func_ov017_0218b5b0();
                        memset(resources->partyNames[i], 0, sizeof(resources->partyNames[i]));
                    }
                }
            }
        } else {
            for (int i = 1; i < 4; i++) {
                if (TestBitBySignedByteIndex_0202c1c0(object, i) && !TestMaskBitBySignedByteIndex_0202bd34(object, i)) {
                    RemoveSearchEntry0202c21c(object, i);
                }
            }
        }
    } else {
        SearchEntry0202c178* entry = GetEntryBySignedByteIndex_0202c178(object, 0);
        object->selectors[1] = entry->selector1;
        object->selectors[2] = entry->selector2;
        object->selectors[3] = entry->selector3;
        if (entry->selector1) {
            object->previousSelectors[1] = entry->selector1;
        }
        if (entry->selector2) {
            object->previousSelectors[2] = entry->selector2;
        }
        if (entry->selector3) {
            object->previousSelectors[3] = entry->selector3;
        }
    }
    if (object->selectors[GetGlobalHalf0x0_0202df58()] != 0 && GetGlobalField0x48_0202d6b8() == 20) {
        SetFlagBitAt0xe_0202c5bc(object, 0);
    }
}
