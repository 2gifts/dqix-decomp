#include <globaldefs.h>
#include "World/Object3D.h"

struct Entry_02164754 { int type; char pad[8]; void* field_c; };

// USA: func_ov001_02164754  (semantic: DispatchEntrySetShorts_02164754)
extern "C" ARM int func_ov001_02164754(Entry_02164754* table, int index, short arg2, short arg3, int arg4) {
    Entry_02164754* entry;
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
            ((Object3D*)member)->SetScale(arg2, arg3, arg4);
            return 1;
        case 6:
            member = entry->field_c;
            if (member == 0) return 0;
            member = *(void**)((char*)member + 0x18);
            if (member == 0) return 0;
            ((Object3D*)member)->SetScale(arg2, arg3, arg4);
            return 1;
        default:
            return 0;
    }
}
