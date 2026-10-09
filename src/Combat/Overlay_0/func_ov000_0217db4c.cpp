#include <globaldefs.h>

struct Struct_0205d81c;
struct Struct_0205c570;
struct Entry_0205d6a0;
struct Obj0205eaa0;
struct TableEntry0217f8c0;
struct Struct0217f8c0;
void SetElementFieldC2(struct Struct_0205d81c* s, int key, int value);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570* s);
extern "C" int func_ov000_0217c594(void* obj, int limit);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0* obj, int a, int b);
extern "C" void* _Z32FindElementByComputedKey021815e4Pc(char* obj);
int GetAdjustedByteField0x1d6b(void* obj);
extern "C" int func_020dd4c4(int id, void* node);
extern "C" struct TableEntry0217f8c0* _Z30FindMatchingTableEntry0217f8c0P14Struct0217f8c0(struct Struct0217f8c0* s);
extern "C" void func_ov000_02176634(void* obj, struct TableEntry0217f8c0* entry, int val, int arg1, int arg2);
extern "C" int _Z35CheckFlagsOrField_0217c5f4_0217c5f4Pv(void* obj);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(struct Entry_0205d6a0* a, int flag);
extern "C" void func_ov000_0217c638(void* obj, int arg1, int arg2);
extern "C" void func_ov000_02176e3c(void* obj, struct TableEntry0217f8c0* entry, int val, int arg1, int arg2, int one);

extern struct Obj0205eaa0 data_02108760;

struct Menu0217db4c {
    char pad_0[0x188];
    char list[0x240 - 0x188];
    unsigned char mode;
    char pad_241[0x956 - 0x241];
    unsigned char field_0x956;
    char pad_957[0x1d60 - 0x957];
    signed char stack[8];
    signed char depth;
    char pad_1d69[0x1d6f - 0x1d69];
    signed char activeSum;
    char pad_1d70[2];
    unsigned short flags;
};

// USA: func_ov000_0217db4c
extern "C" ARM void func_ov000_0217db4c(struct Menu0217db4c* menu, int arg1, int arg2) {
    menu->flags |= 0x100;
    SetElementFieldC2((struct Struct_0205d81c*)menu->list, 0x21, 0);
    signed char prev = menu->activeSum;
    int sum = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570*)menu->list);
    menu->activeSum = sum;
    if (prev != sum) {
        return;
    }
    if (func_ov000_0217c594(menu, 5)) {
        menu->field_0x956 = 0;
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
        menu->mode = 7;
        void* element = _Z32FindElementByComputedKey021815e4Pc((char*)menu);
        func_020dd4c4(GetAdjustedByteField0x1d6b(menu), element);
        menu->depth++;
        menu->stack[menu->depth] = 0x20;
        func_ov000_02176634(menu, _Z30FindMatchingTableEntry0217f8c0P14Struct0217f8c0((struct Struct0217f8c0*)menu), menu->stack[menu->depth], arg1, arg2);
    } else if (_Z35CheckFlagsOrField_0217c5f4_0217c5f4Pv(menu)) {
        menu->field_0x956 = 0;
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((struct Entry_0205d6a0*)menu->list, 0);
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((struct Entry_0205d6a0*)menu->list, 0);
        menu->stack[menu->depth] = 0;
        menu->depth--;
        func_ov000_0217c638(menu, arg1, arg2);
        func_ov000_02176e3c(menu, _Z30FindMatchingTableEntry0217f8c0P14Struct0217f8c0((struct Struct0217f8c0*)menu), menu->stack[menu->depth], arg1, arg2, 0);
    }
}
