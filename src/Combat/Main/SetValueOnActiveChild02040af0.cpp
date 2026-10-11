#include <globaldefs.h>

struct Struct_203cdd8;
void SetField0x64RoundedTo256(struct Struct_203cdd8*, int);

struct Child02040af0 {
    char pad_00[0x14];
    struct Struct_203cdd8* child_14;
    void* child_18;
    void* child_1c;
};

// USA: func_02040af0
ARM void SetValueOnActiveChild02040af0(struct Child02040af0* obj, int value) {
    if (obj->child_14) {
        SetField0x64RoundedTo256(obj->child_14, value);
        return;
    }
    if (obj->child_18) {
        *(int*)((char*)obj->child_18 + 0xb0) = value;
        return;
    }
    if (obj->child_1c) {
#if defined(jpn)
        *(int*)((char*)obj->child_1c + 0x2c8) = value;
#else
        *(int*)((char*)obj->child_1c + 0x2d4) = value;
#endif
    }
}
