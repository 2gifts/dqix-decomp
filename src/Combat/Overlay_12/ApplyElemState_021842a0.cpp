#include <globaldefs.h>

struct Struct_0205d81c;
struct Elem_0205d81c;
Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
struct Elem_0205e00c;
Elem_0205e00c* GetElementByB4IfAbsent_0205e00c(struct Struct_0205d81c* s, int key);
void SetField0xd8State_02050400(unsigned char* obj, int value);
void SetByte0xd9AndFlag0x2_0205042c(unsigned char* obj, unsigned char value);
void SetByte0xdaAndFlag0x2_02050440(unsigned char* obj, int val);

// USA: func_ov012_021842a0  (semantic: ApplyElemState_021842a0)
extern "C" ARM void func_ov012_021842a0(void* obj, int key, int p3, int p4) {
    void* e = FindElementByC40205d81c((struct Struct_0205d81c*)((char*)obj + 0xac), key);
    if (e == 0) {
        e = GetElementByB4IfAbsent_0205e00c((struct Struct_0205d81c*)((char*)obj + 0xac), key);
        if (e == 0) return;
    }
    if (p4 != 0) {
        SetField0xd8State_02050400((unsigned char*)e, 1);
        SetByte0xd9AndFlag0x2_0205042c((unsigned char*)e, (unsigned char)p3);
        SetByte0xdaAndFlag0x2_02050440((unsigned char*)e, (unsigned char)p4);
    } else {
        SetField0xd8State_02050400((unsigned char*)e, 0);
        SetByte0xd9AndFlag0x2_0205042c((unsigned char*)e, 0);
        SetByte0xdaAndFlag0x2_02050440((unsigned char*)e, 0);
    }
}
