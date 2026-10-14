#include <globaldefs.h>
#include <System/Matrix.h>

struct Vec3_020406f8 : Vector3i {};
struct Node020406f8;
void SelectVec3FromSources020406f8(Vec3_020406f8* dst, Node020406f8* n);

struct Entry_02164418 { int type; char pad[8]; void* field_c; };

// USA: func_ov001_02164418  (semantic: SetVec3FromEntryType_02164418)
extern "C" ARM int func_ov001_02164418(Entry_02164418* table, int index, Vector3i* dst) {
    Entry_02164418* entry;
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
            *dst = *(Vector3i*)((char*)member + 0x44);
            return 1;
        case 2:
        case 6: {
            Vec3_020406f8 tmp;
            member = entry->field_c;
            if (member == 0) return 0;
            SelectVec3FromSources020406f8(&tmp, (Node020406f8*)member);
            *dst = tmp;
            return 1;
        }
        default:
            return 0;
    }
}
