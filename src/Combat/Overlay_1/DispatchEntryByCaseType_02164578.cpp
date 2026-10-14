#include <globaldefs.h>
#include "World/Object3D.h"

struct Entry_02164578 { int type; char pad[8]; void* field_c; };

// USA: func_ov001_02164578  (semantic: DispatchEntryByCaseType_02164578)
extern "C" ARM int func_ov001_02164578(Entry_02164578* table, int index, void* arg2, int arg3) {
    Entry_02164578* entry;
    void* member;
    if (index < 0 || index >= 0x20) return 0;
    entry = &table[index];
    switch (entry->type) {
        case 0:
        case 1:
        case 4:
        case 5:
            member = entry->field_c;
            if (member == 0) return 0;
            ((Object3D*)member)->MaybeSetRegularAnimation((char const*)arg2, arg3);
            return 1;
        case 6:
            member = entry->field_c;
            if (member == 0) return 0;
            member = *(void**)((char*)member + 0x18);
            if (member == 0) return 0;
            ((Object3D*)member)->MaybeSetRegularAnimation((char const*)arg2, arg3);
            return 1;
        default:
            return 0;
    }
}
