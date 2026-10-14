#include <globaldefs.h>

struct Elem_0205d81c {
    char pad0[0xc4];
    unsigned char fieldC4;
    char pad1[0xd8 - 0xc5];
    unsigned char fieldD8_bit0 : 1;
    unsigned char fieldD8_rest : 7;
    unsigned char fieldD9;
    unsigned char fieldDA;
    char pad2[0xe0 - 0xdb];
};

struct Struct_0205d81c {
    char pad0[0x98];
    int field98;
    struct Elem_0205d81c* field9C;
    char pad1[0xb0 - 0xa0];
    unsigned char fieldB0;
    char pad2[0xb3 - 0xb1];
    unsigned char fieldB3;
    char pad3[0xb8 - 0xb4];
    unsigned char fieldB8;
};

struct Struct0205d888;
void* GetLastEntry0205d888(struct Struct0205d888* p);

extern "C" int func_0205c5b0(void* selfPtr, int p1);
unsigned int SelectField0x18Or0x68ByFlags_0205c710(unsigned char* obj);
void SetByte0xd9AndFlag0x2_0205042c(unsigned char* obj, unsigned char value);
unsigned int SelectField0x8Or0x58ByFlags_0205c6e4(unsigned char* obj);
void SetByte0xdaAndFlag0x2_02050440(unsigned char* obj, int val);
extern "C" void func_0204c87c(void* entry, int arg);
struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
struct Obj0204ffc0;
void ProcessRefAndDispatch0204ffc0(struct Obj0204ffc0* a, int b);

// USA: func_0205d0e0
extern "C" ARM int func_0205d0e0(void* objPtr, int val) {
    struct Struct_0205d81c* obj = (struct Struct_0205d81c*)objPtr;
    int ret;
    struct Elem_0205d81c* entry;
    unsigned char i;

    if (obj->field98 == 0) return 0;
    if (obj->field9C == 0) return 0;

    ret = 0;
    entry = (struct Elem_0205d81c*)GetLastEntry0205d888((struct Struct0205d888*)objPtr);
    if (entry != 0) {
        ret = func_0205c5b0(objPtr, val);
        if (obj->fieldB0 == entry->fieldC4) {
            if (entry->fieldD8_bit0) {
                SetByte0xd9AndFlag0x2_0205042c((unsigned char*)entry, SelectField0x18Or0x68ByFlags_0205c710((unsigned char*)objPtr));
                SetByte0xdaAndFlag0x2_02050440((unsigned char*)entry, (unsigned char)SelectField0x8Or0x58ByFlags_0205c6e4((unsigned char*)objPtr));
            }
        }
    }

    for (i = 0; i < obj->fieldB3; i++) {
        func_0204c87c((void*)&obj->field9C[i], val);
    }

    if (obj->fieldB8 != 0xff) {
        entry = FindElementByC40205d81c(obj, obj->fieldB8);
        if (entry != 0) {
            ProcessRefAndDispatch0204ffc0((struct Obj0204ffc0*)entry, -1);
        }
        obj->fieldB8 = 0xff;
    }

    return ret;
}
