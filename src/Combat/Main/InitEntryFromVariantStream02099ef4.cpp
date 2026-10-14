#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02099ef4 { int tag; union { int i; float f; } value; };

struct Variant02030b0c;

struct TaggedValue02030b44;
struct Vector3s;

struct Entry02099ef4 {
    unsigned char field0;
    unsigned char field1;
    short vec0[3];
    short vec1[3];
    unsigned char field0e;
    char pad;
    short vec2[3];
    short vec3[3];
};

extern struct Entry02099ef4 data_02109a54[];

// USA: func_02099ef4
ARM int InitEntryFromVariantStream02099ef4(struct Variant02099ef4* p) {
    int id;
    struct Entry02099ef4* entry;
    struct Variant02099ef4* cursor;

    id = ((Script::Parameter*)((struct Variant02030b0c*)p))->ToInt();
    entry = &data_02109a54[id];
    entry->field0 = (unsigned char)id;

    entry->field1 = (unsigned char)((Script::Parameter*)((struct Variant02030b0c*)(p + 1)))->ToInt();

    cursor = (struct Variant02099ef4*)(TaggedValue02030b44*)((Script::Parameter*)((struct TaggedValue02030b44*)(p + 2)))->ToVec3fix16((Vector3s*)entry->vec0);
    cursor = (struct Variant02099ef4*)(TaggedValue02030b44*)((Script::Parameter*)((struct TaggedValue02030b44*)cursor))->ToVec3fix16((Vector3s*)entry->vec1);

    entry->field0e = (unsigned char)((Script::Parameter*)((struct Variant02030b0c*)cursor))->ToInt();

    cursor = (struct Variant02099ef4*)(TaggedValue02030b44*)((Script::Parameter*)((struct TaggedValue02030b44*)(cursor + 1)))->ToVec3fix16((Vector3s*)entry->vec2);
    (TaggedValue02030b44*)((Script::Parameter*)((struct TaggedValue02030b44*)cursor))->ToVec3fix16((Vector3s*)entry->vec3);

    return 1;
}
