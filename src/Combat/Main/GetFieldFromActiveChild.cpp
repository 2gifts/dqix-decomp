#include <globaldefs.h>

struct Struct_203ce00;
struct Obj020415c4;
struct Obj02041654;

int GetField0x60Or0x64ByFlag0x2_0203ce00(struct Struct_203ce00* obj);
int GetFieldByFlagBit020415c4(struct Obj020415c4* obj);
int GetFieldByFlagBit02041654(struct Obj02041654* obj);

struct Owner02040a90 {
    char pad[0x14];
    struct Struct_203ce00* child14;
    struct Obj020415c4* child18;
    struct Obj02041654* child1c;
};

// USA: func_02040a90
ARM int GetFieldFromActiveChild(struct Owner02040a90* obj) {
    if (obj->child14 != NULL) return GetField0x60Or0x64ByFlag0x2_0203ce00(obj->child14);
    if (obj->child18 != NULL) return GetFieldByFlagBit020415c4(obj->child18);
    if (obj->child1c != NULL) return GetFieldByFlagBit02041654(obj->child1c);
    return 0;
}
