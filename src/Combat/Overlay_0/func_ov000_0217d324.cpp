#include <globaldefs.h>

struct Struct_0205c570;
struct Obj0205eaa0;
struct Entry_0205d6a0;
struct Struct0217f8c0;
struct TableEntry0217f8c0;

extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570* s);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0* obj, int a, int b);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(struct Entry_0205d6a0* a, int flag);
extern "C" struct TableEntry0217f8c0* _Z30FindMatchingTableEntry0217f8c0P14Struct0217f8c0(struct Struct0217f8c0* s);
extern "C" int _Z35CheckFlagsOrField_0217c5f4_0217c5f4Pv(void* objRaw);
extern "C" int func_ov000_0217c594(void* objRaw, int limit);
extern "C" void func_ov000_02176634(void* obj, struct TableEntry0217f8c0* entry, int mode, int arg1, int arg2);
extern "C" void func_ov000_0217c638(void* obj, int arg1, int arg2);
extern struct Obj0205eaa0 data_02108760;

// USA: func_ov000_0217d324
extern "C" ARM void func_ov000_0217d324(char* obj, int arg1, int arg2) {
    *(unsigned short*)(obj + 0x1d72) |= 0x100;
    int sum = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570*)(obj + 0x188));
    if (sum < 0) {
        sum = 0;
    }
    *(signed char*)(obj + 0x1d6b) = sum;
    if (func_ov000_0217c594(obj, 0) != 0) {
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
        *(signed char*)(obj + 0x1d68) = *(signed char*)(obj + 0x1d68) + 1;
        *(unsigned char*)(obj + *(signed char*)(obj + 0x1d68) + 0x1d60) = 4;
        struct TableEntry0217f8c0* e = _Z30FindMatchingTableEntry0217f8c0P14Struct0217f8c0((struct Struct0217f8c0*)obj);
        func_ov000_02176634(obj, e, 4, arg1, arg2);
    } else if (_Z35CheckFlagsOrField_0217c5f4_0217c5f4Pv(obj) != 0) {
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((struct Entry_0205d6a0*)(obj + 0x188), 0);
        *(unsigned char*)(obj + *(signed char*)(obj + 0x1d68) + 0x1d60) = 0;
        *(signed char*)(obj + 0x1d68) = *(signed char*)(obj + 0x1d68) - 1;
        *(signed char*)(obj + 0x1d6b) = -1;
        func_ov000_0217c638(obj, arg1, arg2);
    }
}
