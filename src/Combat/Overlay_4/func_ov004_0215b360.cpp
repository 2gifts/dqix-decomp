#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define func_ov004_0215b360 func_ov004_0215c394
#endif

struct Container020dedd0;
struct TableA68;
struct Grid021f9b30;
struct Element0215b360 { int id; char* text; };
struct Node0215b360 {
    void** vtable;
    char pad4[8];
    unsigned char flags;
    char padd[0x13];
    char* text;
};
struct Number0215b360 {
    void** vtable;
    void Set(int value) { ((void (*)(Number0215b360*, int))vtable[56])(this, value); }
};
struct Page0215b360 { char pad[0x5c]; short current; short maximum; };
struct Selection0215b360 { char pad[0x7c]; unsigned char values[8]; };
struct Holder0215b360 { char pad[8]; Selection0215b360* data; };
extern Holder0215b360 data_ov004_021707d8;
extern "C" Container020dedd0* func_ov004_02156fd4(void*, int);
TableA68* DispatchAdjustmentIfType4_02157018(void*, int);
int DispatchNodeIfType7_02156e2c(void*, int);
extern "C" Node0215b360* func_ov004_02156f04(void*, int);
char* FindEntryByKey(TableA68*, int);
void ClearNodeMaskById_021f6600(void*, int, int);
void* GetPointerFromArray0xbd0(unsigned char*, unsigned int);
void* GetPointerAt0xbf0(void*, unsigned int);
int CountPositiveEntries0207c638(void*, unsigned int);
extern "C" void func_ov023_021f65d4(void*, int, int);
extern "C" Page0215b360* func_ov004_02156ed0(void*, int);
extern "C" Number0215b360* func_ov004_02156f38(void*, int);
Element0215b360* FindElementByKey020dedd0(Container020dedd0*, int);
extern "C" int _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(Grid021f9b30*, unsigned short, unsigned int, unsigned int);
extern "C" void* func_ov004_02156f6c(void*, int);
extern "C" void func_ov023_021f809c(void*, void*);
extern "C" void* _Z24CheckThenNotify_02157088v(void*, int);
extern "C" void func_ov023_021dcae0(void*, short);

// USA: func_ov004_0215b360
extern "C" ARM int func_ov004_0215b360(void* self) {
    short* items = 0;
    signed char* counts = 0;
    int count = 0;
    Container020dedd0* container = func_ov004_02156fd4(self, 5);
    TableA68* strings = DispatchAdjustmentIfType4_02157018(self, 3);
    int selected = DispatchNodeIfType7_02156e2c(self, 0x65);
    if (selected < 0) return 0;
    unsigned char* player = (unsigned char*)GetPtrField0x2a04(GameState::GetInstance());
    if (!player) return 0;
    for (int i = 0; i < 8; ++i) {
        if (i == selected) {
            Node0215b360* node = func_ov004_02156f04(self, 0x454);
            if (node) node->text = FindEntryByKey(strings, (short)(i + 0x1b));
            ClearNodeMaskById_021f6600(self, i + 0x38c, 8);
            items = (short*)GetPointerFromArray0xbd0(player + 0x1d4, data_ov004_021707d8.data->values[selected]);
            counts = (signed char*)GetPointerAt0xbf0(player + 0x1d4, data_ov004_021707d8.data->values[selected]);
            count = CountPositiveEntries0207c638(player + 0x1d4, data_ov004_021707d8.data->values[selected]);
        } else {
            func_ov023_021f65d4(self, i + 0x38c, 8);
        }
    }
    Page0215b360* page = func_ov004_02156ed0(self, 0x63);
    if (!page) return 0;
    short pages = (count - 1) / 8 + 1;
    if (pages < 1) pages = 1;
    page->current = 0;
    page->maximum = pages;
    func_ov004_02156f38(self, 0x456)->Set(1);
    func_ov004_02156f38(self, 0x457)->Set(pages);
    for (int i = 0; i < 8; ++i) {
        Number0215b360* number = func_ov004_02156f38(self, i + 0x461);
        number->Set(counts[i]);
    }
    for (int i = 0; i < 8; ++i) {
        Element0215b360* element = FindElementByKey020dedd0(container, items[i]);
        Node0215b360* node = func_ov004_02156f04(self, i + 0x44c);
        if (!element) {
            node->flags |= 8;
            func_ov023_021f65d4(self, i + 0x459, 8);
            func_ov023_021f65d4(self, i + 0x461, 8);
            _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj((Grid021f9b30*)page, 0, (unsigned short)i, 0);
        } else {
            char* text = element->text;
            if (!text) text = 0;
            if (node) {
                node->flags &= ~8;
                node->text = text;
                ClearNodeMaskById_021f6600(self, i + 0x459, 8);
                ClearNodeMaskById_021f6600(self, i + 0x461, 8);
                _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj((Grid021f9b30*)page, (unsigned short)(i + 0x44c), (unsigned short)i, 0);
            }
        }
    }
    void* node = func_ov004_02156f6c(self, 0x17);
    if (node) func_ov023_021f809c(node, self);
    node = _Z24CheckThenNotify_02157088v(self, 7);
    if (node) func_ov023_021dcae0(node, -1);
    return 0;
}
