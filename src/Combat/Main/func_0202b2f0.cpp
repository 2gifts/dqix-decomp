#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

union SearchFlags0202b2f0 {
    unsigned short raw;
    struct {
        unsigned short selected:3;
        unsigned short padding:13;
    };
};
struct SearchEntry0202b2f0 {
    SearchFlags0202b2f0 flags;
    unsigned short padding:5;
    unsigned short selector1:2;
    unsigned short selector2:2;
    unsigned short selector3:2;
    unsigned short padding2:5;
    unsigned short mask;
};
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
struct Container0202c478;
struct SearchRecord0202b2f0 {
    unsigned char bytes[0x30];
};
struct SearchContext0202b2f0 {
    unsigned char padding[0x435c];
    SearchRecord0202b2f0 records[4];
};
unsigned short GetGlobalHalf0x0();
SearchEntry0202b2f0* GetEntryBySignedByteIndex(SearchStruct*, int);
extern "C" FlagWord02046708* _Z27GetDataPtr02114e04_020d6c00v();
extern "C" int _Z17TestFlags02046708P16FlagWord02046708j(FlagWord02046708*, unsigned int);
int GetGlobalField0x10();
extern "C" int func_0202d8e8();
extern "C" void func_0202db64(int, int, int);
extern "C" void func_0202bc00(SearchStruct*, int);
extern "C" void _Z20ShiftRecords0202c478P17Container0202c478(Container0202c478*);
extern "C" void func_0202bf40(SearchStruct*);
extern "C" void func_0202c04c(SearchStruct*);
extern "C" int func_0202c508(SearchStruct*);
extern "C" unsigned short _Z32GetEntryField0x4OrFieldA0202bc8cP12SearchStruct(SearchStruct*);
signed char FindSignedByteIndex(SearchStruct*, int);
int TestMaskBitBySignedByteIndex(SearchStruct*, int);
extern "C" void _Z25RemoveSearchEntry0202c21cP12SearchStructi(SearchStruct*, int);
int TestBitBySignedByteIndex(SearchStruct*, int);
void SetFlagBitAt0xe(SearchStruct*, int);
void SetSearchFlagBitAt0xc(SearchStruct*, int);
extern "C" void _Z24SetSearchFlagBit0202c660P12SearchStructi(SearchStruct*, int);
int GetGlobalField0x48();

// USA: func_0202b2f0
extern "C" ARM void func_0202b2f0(SearchStruct* object) {
    SearchStruct::Selection* selection;
    unsigned short savedFlags[4];
    unsigned short savedMask[4];
    for (int i = 0; i < 4; i++) {
        if (i == object->selectors[GetGlobalHalf0x0()]) {
            continue;
        }
        SearchEntry0202b2f0* entry = GetEntryBySignedByteIndex(object, i);
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
    if (_Z17TestFlags02046708P16FlagWord02046708j(_Z27GetDataPtr02114e04_020d6c00v(), 0x1000000)) {
        object->state = -1;
        return;
    }
    switch (GetGlobalField0x10()) {
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
        _Z20ShiftRecords0202c478P17Container0202c478((Container0202c478*)object);
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
            if (i == object->selectors[GetGlobalHalf0x0()]) {
                continue;
            }
            SearchEntry0202b2f0* entry = GetEntryBySignedByteIndex(object, i);
            if (!entry) {
                continue;
            }
            entry->flags.selected = savedFlags[i];
            entry->mask = (entry->mask & ~0xffff) | savedMask[i];
        }
    } else if (func_0202c508(object)) {
        if (object->refill) {
            unsigned int mask = _Z32GetEntryField0x4OrFieldA0202bc8cP12SearchStruct(object);
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
        int index = FindSignedByteIndex(object, 0);
        if (!(object->activeMask & (1 << index))) {
            selection = &object->selection;
            for (int i = 1; i < 4; i++) {
                int index = FindSignedByteIndex(object, i);
                if ((object->activeMask & (1 << index)) && !(selection->excluded & (1 << i))) {
                    if (!TestMaskBitBySignedByteIndex(object, i)) {
                        _Z25RemoveSearchEntry0202c21cP12SearchStructi(object, i);
                    }
                } else if (TestBitBySignedByteIndex(object, i)) {
                    if (!TestMaskBitBySignedByteIndex(object, i)) {
                        SetFlagBitAt0xe(object, i);
                    }
                } else if (TestMaskBitBySignedByteIndex(object, i)) {
                    SetSearchFlagBitAt0xc(object, i);
                    _Z24SetSearchFlagBit0202c660P12SearchStructi(object, i);
                    if (object->IsActive()) {
                        memset(&((SearchContext0202b2f0*)func_ov017_0218b5b0())->records[i], 0, sizeof(SearchRecord0202b2f0));
                    }
                }
            }
        } else {
            for (int i = 1; i < 4; i++) {
                if (TestBitBySignedByteIndex(object, i) && !TestMaskBitBySignedByteIndex(object, i)) {
                    _Z25RemoveSearchEntry0202c21cP12SearchStructi(object, i);
                }
            }
        }
    } else {
        SearchEntry0202b2f0* entry = GetEntryBySignedByteIndex(object, 0);
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
    if (object->selectors[GetGlobalHalf0x0()] != 0 && GetGlobalField0x48() == 20) {
        SetFlagBitAt0xe(object, 0);
    }
}
