#include <globaldefs.h>

#if defined(jpn)
enum { displayFieldOffset = 0x2c8 };
#else
enum { displayFieldOffset = 0x2d4 };
#endif
int GetField0x64(struct StructF0x64_0203cdf8*);


struct Struct_020409e0 {
    char pad[0x14];
    void* field14;
    void* field18;
    void* field1c;
};

// USA: func_020409e0
ARM int GetDisplayValue020409e0(struct Struct_020409e0* obj) {
    if (obj->field14) {
        return GetField0x64((struct StructF0x64_0203cdf8*)(obj->field14));
    }
    if (obj->field18) {
        return *(int*)((char*)obj->field18 + 0xb0);
    }
    if (obj->field1c) {
        return *(int*)((char*)obj->field1c + displayFieldOffset);
    }
    return 0;
}
