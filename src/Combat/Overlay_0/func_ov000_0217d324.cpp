#include <globaldefs.h>

#if defined(jpn)
enum { kFlagsOffset = 0x1faa, kSumOffset = 0x1fa3, kCountOffset = 0x1fa0, kArrayOffset = 0x1f98 };
#else
enum { kFlagsOffset = 0x1d72, kSumOffset = 0x1d6b, kCountOffset = 0x1d68, kArrayOffset = 0x1d60 };
#endif

struct Struct_0205c570;
struct Obj0205eaa0;
struct Entry_0205d6a0;
struct Struct0217f8c0;
struct TableEntry0217f8c0;

int GetActiveScaledSum0205d794(struct Struct_0205c570* s);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
void ResetEntryList0205d6a0(struct Entry_0205d6a0* a, int flag);
struct TableEntry0217f8c0* FindMatchingTableEntry0217f8c0(struct Struct0217f8c0* s);
int CheckFlagsOrField_0217c5f4_0217c5f4(void* objRaw);
extern "C" int func_ov000_0217c594(void* objRaw, int limit);
extern "C" void func_ov000_02176634(void* obj, struct TableEntry0217f8c0* entry, int mode, int arg1, int arg2);
extern "C" void func_ov000_0217c638(void* obj, int arg1, int arg2);
extern struct Obj0205eaa0 data_02108760;

// USA: func_ov000_0217d324
extern "C" ARM void func_ov000_0217d324(char* obj, int arg1, int arg2) {
    *(unsigned short*)(obj + kFlagsOffset) |= 0x100;
    int sum = GetActiveScaledSum0205d794((struct Struct_0205c570*)(obj + 0x188));
    if (sum < 0) {
        sum = 0;
    }
    *(signed char*)(obj + kSumOffset) = sum;
    if (func_ov000_0217c594(obj, 0) != 0) {
        DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
        *(signed char*)(obj + kCountOffset) = *(signed char*)(obj + kCountOffset) + 1;
        *(unsigned char*)(obj + *(signed char*)(obj + kCountOffset) + kArrayOffset) = 4;
        struct TableEntry0217f8c0* e = FindMatchingTableEntry0217f8c0((struct Struct0217f8c0*)obj);
        func_ov000_02176634(obj, e, 4, arg1, arg2);
    } else if (CheckFlagsOrField_0217c5f4_0217c5f4(obj) != 0) {
        ResetEntryList0205d6a0((struct Entry_0205d6a0*)(obj + 0x188), 0);
        *(unsigned char*)(obj + *(signed char*)(obj + kCountOffset) + kArrayOffset) = 0;
        *(signed char*)(obj + kCountOffset) = *(signed char*)(obj + kCountOffset) - 1;
        *(signed char*)(obj + kSumOffset) = -1;
        func_ov000_0217c638(obj, arg1, arg2);
    }
}
