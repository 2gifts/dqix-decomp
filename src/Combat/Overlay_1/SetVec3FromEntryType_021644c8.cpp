#include <globaldefs.h>
#include "System/Matrix.h"

struct Vec3_020407c4 { unsigned int v[3]; };
struct Self020407c4;
void FillVec3Default020407c4(Vec3_020407c4* dst, Self020407c4* n);

struct Entry_021644c8 { int type; char pad[8]; void* field_c; };

// USA: func_ov001_021644c8  (semantic: SetVec3FromEntryType_021644c8)
extern "C" ARM int func_ov001_021644c8(Entry_021644c8* table, int index, Vector3i* dst) {
    Entry_021644c8* entry;
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
            *dst = *(Vector3i*)((char*)member + 0x50);
            return 1;
        case 2:
        case 6: {
            Vec3_020407c4 tmp;
            member = entry->field_c;
            if (member == 0) return 0;
            FillVec3Default020407c4(&tmp, (Self020407c4*)member);
            *dst = *(Vector3i*)&tmp;
            return 1;
        }
        default:
            return 0;
    }
}
