#include <globaldefs.h>
#include "std_library_functions.h"

struct EntryA68 { short key; void* value; };
struct TableA68 { struct EntryA68* entries; short count; };
void* FindEntryByKey(struct TableA68* table, int key);
int DispatchAdjustmentIfType4_02157018(void* a, int key);
int GetGlobalField0x1c020421a0();
extern "C" void func_02046380(void* global);
struct StoreStruct;
void StoreInArray0x8b0(struct StoreStruct* base, int index, int value);

// USA: func_ov004_02157374  (semantic: StoreEntryNameForKey_02157374)
extern "C" ARM void func_ov004_02157374(void* obj, int key, int cat, char* dst, unsigned char flag5) {
    if (key <= 0) return;

    struct TableA68* table = (struct TableA68*)DispatchAdjustmentIfType4_02157018(obj, 4);
    int usedFallback = 0;
    const char* name;

    if ((key >= 0x4e20 && key <= 0x4e84) ||
        (key >= 0x4e86 && key <= 0x4e8b) ||
        (key == 0x4e8d) ||
        (key >= 0x4e8f && key <= 0x5207) ||
        (key >= 0xcb24 && key <= 0xcb29) ||
        (key >= 0xcb2d && key < 0xcb84) ||
        (key >= 0xcb88 && key <= 0xcb8d) ||
        (key >= 0xcb91 && key < 0xcbe8) ||
        (key >= 0xcbec && key <= 0xcbf1) ||
        (key >= 0xcbf5 && key < 0xccb0) ||
        (key >= 0xcf08 && key < 0xd034)) {
        name = (const char*)FindEntryByKey(table, 0x64);
    } else if ((key == 0x4e85) || (key >= 0x59d8 && key < 0x5dc0)) {
        name = (const char*)FindEntryByKey(table, 0x65);
    } else if (key == 0x4e8c) {
        name = (const char*)FindEntryByKey(table, 0x66);
    } else if (key == 0x4e8e) {
        name = (const char*)FindEntryByKey(table, 0x67);
    } else if (key >= 0xc800 && key < 0xc864) {
        name = (const char*)FindEntryByKey(table, 0x68);
    } else if (key >= 0xc350 && key < 0xc3b4) {
        name = (const char*)FindEntryByKey(table, 0x69);
    } else if ((key >= 0xc738 && key <= 0xc79e) ||
               (key >= 0xc7a0 && key < 0xc800) ||
               (key >= 0xc864 && key < 0xc8c8)) {
        name = (const char*)FindEntryByKey(table, 0x6a);
    } else if (key == 0xc79f) {
#if defined(jpn)
        name = (const char*)FindEntryByKey(table, 0x6b);
#else
        name = (const char*)FindEntryByKey(table, 0x6a);
#endif
    } else if ((key >= 0xcb20 && key <= 0xcb23) ||
               (key >= 0xcb2a && key <= 0xcb2c) ||
               (key >= 0xcb84 && key <= 0xcb87) ||
               (key >= 0xcb8e && key <= 0xcb90) ||
               (key >= 0xcbe8 && key <= 0xcbeb) ||
               (key >= 0xcbf2 && key <= 0xcbf4) ||
               (key >= 0xccb0 && key <= 0xccb3) ||
               (key >= 0xccba && key <= 0xccbc) ||
               (key >= 0xcd14 && key <= 0xcd17) ||
               (key >= 0xcd1e && key <= 0xcd20) ||
               (key >= 0xcddc && key <= 0xcddf) ||
               (key >= 0xcde6 && key <= 0xcde8)) {
        name = (const char*)FindEntryByKey(table, 0x6c);
    } else {
        usedFallback = 1;
#if defined(jpn)
        if (cat == 1) {
            name = (const char*)FindEntryByKey(table, 0x6d);
        }
#endif
        if (cat == 2) {
            name = (const char*)FindEntryByKey(table, 0x70);
        } else if (key >= 0x7918 && key < 0x7d00) {
            name = (const char*)FindEntryByKey(table, 0x6f);
        } else {
            name = (const char*)FindEntryByKey(table, 0x6e);
        }
    }

    if (flag5 != 0) {
        if (usedFallback == 0) return;
    }
    if (name == 0) return;

    void* g = (void*)GetGlobalField0x1c020421a0();
    func_02046380(g);
    StoreInArray0x8b0((struct StoreStruct*)g, 0, key);
    memcpy(dst, (void*)name, strlen(name));
}
