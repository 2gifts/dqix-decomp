#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay15ViewerContext.h"

struct Container020dedd0;
struct Element020de650;
extern "C" struct Element020de650* _Z24FindElementByKey020dedd0P17Container020dedd0i(struct Container020dedd0* c, int key);
extern "C" void* __clear(void* dst, int count);

struct Sub0218c274 {
    unsigned int f0;
    unsigned int pad0 : 12;
    unsigned int byteVal : 8;
    unsigned int pad1 : 12;
};

extern char data_ov015_0219400a[3];
extern char data_ov015_0219400d[3];
extern char data_ov015_02194010[3];
extern char data_ov015_02194013[13];

// USA: func_ov015_0218c274  (semantic: BuildStatusMessage_0218c274)
extern "C" ARM void func_ov015_0218c274(struct Obj0218c274* obj, char* outBuf, int flag) {
    short key1 = (short)obj->parts_[8];
    struct Element020de650* e1 = _Z24FindElementByKey020dedd0P17Container020dedd0i((struct Container020dedd0*)((char*)obj->viewer_ + 0x4c), key1);
    short key2 = (short)obj->parts_[0];
    struct Element020de650* e2 = _Z24FindElementByKey020dedd0P17Container020dedd0i((struct Container020dedd0*)((char*)obj->viewer_ + 0x4c), key2);

    int val2 = 0;
    int val1 = val2;
    if (e2 != 0) {
        struct Sub0218c274* s = *(struct Sub0218c274**)e2;
        val2 = s->byteVal;
    }
    if (e1 != 0) {
        struct Sub0218c274* s = *(struct Sub0218c274**)e1;
        val1 = s->byteVal;
    }

    char buf[4];
    __clear(buf, 4);

    char code;
    if (obj->kind_ == 1) {
        strcpy(buf, data_ov015_0219400a);
        code = (obj->flag3b_ == 0) ? 'm' : 'w';
    } else {
        strcpy(buf, data_ov015_0219400d);
        code = (obj->field48_ == 0) ? 'n' : 'b';
        if (flag != 0) {
            code = 'f';
        }
    }
    if (code == 'n' || code == 'f') {
        if (obj->flag3b_ == 1) {
            strcpy(buf, data_ov015_02194010);
        }
    }

    sprintf(outBuf, data_ov015_02194013, buf, val2, val1, code);
}
