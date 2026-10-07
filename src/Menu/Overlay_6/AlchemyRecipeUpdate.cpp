// External entry names follow the fork's symbols.txt at b399f53.
// Local argument views remain provisional; see contribution interface notes.
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"

struct AlchemyEntryUpdateView {
    short item;
    unsigned short selected : 1;
    unsigned short updated : 1;
    unsigned short unknownFlags : 14;
};
struct AlchemyCatalogFlagsView {
    char unknown00[0x10];
    unsigned int flags;
};
struct AlchemyUpdateWorkView {
    char unknown00[0x68];
    char updateData[0x48];
};
extern "C" {
void _Z18ResetFlags02153e54P24ResetFlags02153e54Struct(AlchemyEntryUpdateView*);
void func_ov006_02153e8c(void*, AlchemyEntryUpdateView*);
void func_ov006_02154138(void*);
bool func_020ac2d4(int, short*, AlchemyEntryUpdateView*, int);
void func_020ac104(void*, AlchemyEntryUpdateView*, int);
AlchemyCatalogFlagsView* _Z22FindEntryByKey02071d60P12List02071d60i(void*, short);
bool _Z24CopyOutBattleField0x7ac0Pv(unsigned int*);
void _Z24CopyInBattleRegion0x7ac0Pv(unsigned int*);
void _Z23LoadBattleBlock020ac4c0Pv(AlchemyUpdateWorkView*);
void _Z30AddClamped16BitFieldHighAt0x18P7S_a0228j(void*, int);
void _Z23CopyInBattleField0x7540Pv(AlchemyUpdateWorkView*);
}
extern "C" ARM void func_ov006_02153cbc(void* state, short selectedItem, short addedItem, void* catalog)
{
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    AlchemyEntryUpdateView entry;
    _Z18ResetFlags02153e54P24ResetFlags02153e54Struct(&entry);
    if (func_020ac2d4(0, &selectedItem, &entry, 1)) {
        entry.selected = 1;
        entry.updated = 1;
        func_020ac104(data_0211e33c, &entry, 1);
        func_ov006_02153e8c(state, &entry);
        if (catalog) {
            AlchemyCatalogFlagsView* record = _Z22FindEntryByKey02071d60P12List02071d60i(catalog, selectedItem);
            if (record) record->flags |= 0x400000;
        }
    }
    if (addedItem > 0) {
        _Z18ResetFlags02153e54P24ResetFlags02153e54Struct(&entry);
        if (func_020ac2d4(0, &addedItem, &entry, 1)) {
            entry.item = addedItem;
            entry.updated = 1;
            func_020ac104(data_0211e33c, &entry, 1);
            func_ov006_02153e8c(state, &entry);
            if (catalog) {
                AlchemyCatalogFlagsView* record = _Z22FindEntryByKey02071d60P12List02071d60i(catalog, addedItem);
                if (record) record->flags |= 0x400000;
            }
            func_ov006_02154138(state);
        }
    }
    unsigned int count = 0;
    if (_Z24CopyOutBattleField0x7ac0Pv(&count)) {
        count++;
        if (count > 99999) count = 99999;
        _Z24CopyInBattleRegion0x7ac0Pv(&count);
        AlchemyUpdateWorkView work;
        _Z23LoadBattleBlock020ac4c0Pv(&work);
        _Z30AddClamped16BitFieldHighAt0x18P7S_a0228j(work.updateData, 1);
        _Z23CopyInBattleField0x7540Pv(&work);
    }
    BackgroundLoader::RemoveLockGlobal();
}
