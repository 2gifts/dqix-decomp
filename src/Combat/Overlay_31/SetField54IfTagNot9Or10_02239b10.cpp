#include <globaldefs.h>

extern "C" void func_ov031_02239368(int val);
ARM void SetField54IfTagNot9Or10_ov031_022393e4(int v);

struct Arg02239b10 { unsigned char pad[2]; unsigned short field2; };

// USA: func_ov031_02239b10  (semantic: DispatchByField2_02239b10)
extern "C" ARM void func_ov031_02239b10(Arg02239b10* obj) {
    unsigned short v = obj->field2;
    if (v != 0) {
        SetField54IfTagNot9Or10_ov031_022393e4(v);
        return;
    }
    func_ov031_02239368(1);
}
