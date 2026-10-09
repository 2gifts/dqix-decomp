#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0205c570;
struct Entry_0205d6a0;
struct Obj0205eaa0;

extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570* s);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0* obj, int a, int b);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(struct Entry_0205d6a0* a, int flag);
extern "C" int _Z35CheckFlagsOrField_0217c5f4_0217c5f4Pv(void* obj);
extern "C" int func_ov000_0217c594(void* obj, int limit);
extern "C" void func_ov000_02176e3c(void* obj, int zero, int val, int arg1, int arg2, int one);
extern "C" void func_ov000_0217c638(void* obj, int arg1, int arg2);
extern "C" void func_ov017_021c847c(void);

extern char data_02108760[];

struct MemberInfo0217dcf0 {
    char pad0[0x3c];
    unsigned int pad3c_0 : 30;
    unsigned int flag30 : 1;
    unsigned int pad3c_31 : 1;
};

struct Entry0217dcf0 {
    char pad0[0x4c];
    int field4c;
    char pad1[0x448 - 0x50];
};

// USA: func_ov000_0217dcf0
extern "C" ARM void func_ov000_0217dcf0(char* obj, int arg1, int arg2) {
    *(unsigned short*)(obj + 0x1d72) |= 0x100;
    *(unsigned char*)(obj + 0x1d6b) = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570*)(obj + 0x188));
    if (func_ov000_0217c594(obj, 0)) {
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0*)data_02108760, 1, 0);
        GameState* gs = GameState::GetInstance();
        unsigned char* field2a04 = (unsigned char*)GetPtrField0x2a04(gs);
        signed char cursor = *(signed char*)(obj + 0x1d6b);
        if (cursor < field2a04[0xf7c]) {
            struct Entry0217dcf0* entry = &((struct Entry0217dcf0*)(obj + 0x958))[*(signed char*)(obj + cursor + 0x70)];
            GameObject* member = gs->GetPartyMemberByIndex((signed char)entry->field4c);
            if (member != NULL) {
                struct MemberInfo0217dcf0* info = (struct MemberInfo0217dcf0*)member->baseStats_;
                unsigned short v = info->flag30;
                v++;
                v %= 2;
                info->flag30 = v;
                func_ov000_02176e3c(obj, 0, *(signed char*)(obj + *(signed char*)(obj + 0x1d68) + 0x1d60), arg1, arg2, 0);
                func_ov017_021c847c();
            }
        }
    } else if (_Z35CheckFlagsOrField_0217c5f4_0217c5f4Pv(obj)) {
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((struct Entry_0205d6a0*)(obj + 0x188), 0);
        *(unsigned char*)(obj + *(signed char*)(obj + 0x1d68) + 0x1d60) = 0;
        *(signed char*)(obj + 0x1d68) = *(signed char*)(obj + 0x1d68) - 1;
        func_ov000_0217c638(obj, arg1, arg2);
    }
}
