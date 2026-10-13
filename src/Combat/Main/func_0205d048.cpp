#include <globaldefs.h>

struct Struct_0205c53c;
void ForwardInitChannelPair0205c564(struct Struct_0205c53c* s);
struct Obj0204c754;
void ResetObject0204c754(struct Obj0204c754* obj);
struct List0204afb4;
void ResetRecordList0204afb4(struct List0204afb4* obj);

struct Obj0205d048 {
    char pad0[0x98];
    char* field98;
    char* field9c;
    char pad1[0xb2 - 0xa0];
    unsigned char fieldb2;
    unsigned char fieldb3;
    unsigned char fieldb4;
};

// USA: func_0205d048
extern "C" ARM void func_0205d048(struct Obj0205d048* obj) {
    ForwardInitChannelPair0205c564((struct Struct_0205c53c*)obj);
    if (obj->field9c != 0 && obj->fieldb3 != 0) {
        unsigned char i;
        for (i = 0; i < obj->fieldb3; i++) {
            ResetObject0204c754((struct Obj0204c754*)(obj->field9c + i * 0xe0));
        }
    }
    if (obj->field98 != 0) {
        unsigned char i;
        for (i = 0; i < obj->fieldb2; i++) {
            ResetRecordList0204afb4((struct List0204afb4*)(obj->field98 + i * 0x20));
        }
    }
    obj->field98 = 0;
    obj->field9c = 0;
    obj->fieldb3 = 0;
    obj->fieldb4 = 0;
}
