#include <globaldefs.h>
#if defined(jpn)
enum { kRegione4 = 0xe0 };
enum { kRegione8 = 0xe4 };
enum { kRegion4ea = 0x4e6 };
#else
enum { kRegione4 = 0xe4 };
enum { kRegione8 = 0xe8 };
enum { kRegion4ea = 0x4ea };
#endif


struct Struct_0205d81c {
    char pad0[0x98];
    int field98;
    void* field9C;
    char pad1[0x14];
    unsigned char fieldB4;
};

struct Struct_0205d81c* FindElementForFieldB0(struct Struct_0205d81c*);
int IsField0x9cEqual3(unsigned char* obj);
void SetFieldAt0x30(void* obj, int value);
extern "C" int func_0205d0e0(void*, int);

// JPN: func_ov003_021692e0
// USA: func_ov003_021694b8
ARM void UpdateEntryAndField4ea_021694b8(void* obj, int id) {
    struct Struct_0205d81c* entry = FindElementForFieldB0((struct Struct_0205d81c*)((char*)obj + kRegione4));
    if (entry != 0) {
        if (IsField0x9cEqual3((unsigned char*)entry)) {
            if (!(((unsigned char*)entry)[0xc5] & 0x2)) {
                SetFieldAt0x30((char*)obj + kRegione8, -1);
            }
        }
    }
    *((unsigned char*)obj + kRegion4ea) = (unsigned char)func_0205d0e0((char*)obj + kRegione4, id);
}
