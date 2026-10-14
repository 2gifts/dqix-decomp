#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c { int tag; union { int i; float f; } u; };

struct TaggedValue02030b44 { int type; union { int i; float f; } value; };

struct EntryTable0209bd94;
struct SubEntry0209be44 { unsigned short a; short b; };
void AppendSubEntry0209be44(struct EntryTable0209bd94* table, int key, struct SubEntry0209be44* src);

struct Recorder0209bb0 {
    struct EntryTable0209bd94* table;
    unsigned char pad[0x10];
    int active;
    int key;
};
extern struct Recorder0209bb0* data_02109bb0;

struct DualVariant0209ba70 {
    struct Variant02030b0c primary;
    struct Variant02030b0c secondary;
};

// USA: func_0209ba70
ARM int AppendSubEntryFromDualVariant0209ba70(struct DualVariant0209ba70* v) {
    struct SubEntry0209be44 sub;
    if (data_02109bb0->active == 0) {
        return 1;
    }
    *(int*)&sub = ((Script::Parameter*)&v->primary)->ToInt();
    if (v->secondary.tag == 2) {
        sub.b = (short)(int)(((Script::Parameter*)((struct TaggedValue02030b44*)&v->secondary))->ToFloat() * 4096.0f);
    } else if (v->secondary.tag == 1) {
        sub.b = (short)(((Script::Parameter*)&v->secondary)->ToInt() << 12);
    }
    if (sub.b == 0) {
        sub.b = 0x1000;
    }
    AppendSubEntry0209be44(data_02109bb0->table, data_02109bb0->key, &sub);
    return 1;
}
