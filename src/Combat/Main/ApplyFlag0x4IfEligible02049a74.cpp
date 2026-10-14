#include <globaldefs.h>

int CheckSubstructFlag0x80_02048bd0(unsigned char* obj);
int CheckSubstructFlag0x100_02048c68(unsigned char* obj);
struct S_10088;
int IsFlag10088Set_02010088(struct S_10088* obj);
int GetSubstructByte0x56_02049ee8(unsigned char* obj);

struct Sub02049a74 {
    unsigned char pad1[0x20];
    unsigned int flags;
    unsigned char pad2[0x56 - 0x24];
    unsigned char byte56;
};

struct Obj02049a74 {
    unsigned char pad[0x13c];
    struct Sub02049a74* sub;
};

// USA: func_02049a74
ARM void ApplyFlag0x4IfEligible02049a74(struct Obj02049a74* obj) {
    if (obj->sub == NULL) return;
    if (CheckSubstructFlag0x80_02048bd0((unsigned char*)obj)) return;
    if (CheckSubstructFlag0x100_02048c68((unsigned char*)obj)) return;
    if (obj->sub->byte56 == 0) return;
    if (IsFlag10088Set_02010088((struct S_10088*)obj)) return;
    if (GetSubstructByte0x56_02049ee8((unsigned char*)obj)) {
        obj->sub->flags |= 4;
    }
}
