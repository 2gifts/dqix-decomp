#include <globaldefs.h>

struct Bar {
    char unk[0x34];
    unsigned short type;
    unsigned short pad;
    unsigned short param1;
    unsigned short param2;
};

struct Foo {
    struct Bar* ptr;
};

// USA: func_020bc210
ARM void SetActionParams_020bc210(struct Foo* obj, short param1, short param2) {
    if (*(int*)obj == 0) {
        return;
    }
    obj->ptr->type = 2;
    obj->ptr->param1 = param1;
    obj->ptr->param2 = param2;
}
