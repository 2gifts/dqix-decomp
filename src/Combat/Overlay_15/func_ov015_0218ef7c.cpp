#include <globaldefs.h>

#include "Combat/Overlay15ViewerContext.h"

struct SrcState0218ef7c { char pad[0x1a4]; int state; };
struct P0218ef7c { char pad[8]; unsigned short flag; };
struct Obj0218ef7c { void* src; char pad[0x18]; unsigned char status; };

// USA: func_ov015_0218ef7c
extern "C" ARM int func_ov015_0218ef7c(Obj0218ef7c* obj, SrcState0218ef7c* src, P0218ef7c* p) {
    obj->src = src;
    int status = src->state - 4;
    switch (status) {
    case 0:
        if (p->flag == 0) {
            status = 0;
            obj->status = 0;
        } else {
            status = 1;
            obj->status = 1;
        }
        break;
    case 7:
        status = 2;
        obj->status = status;
        break;
    case 8:
        status = 2;
        obj->status = status;
        break;
    case 2:
        status = 3;
        obj->status = status;
        break;
    case 3:
        status = 4;
        obj->status = status;
        break;
    case 9:
        status = 5;
        obj->status = status;
        break;
    case 10:
        status = 6;
        obj->status = status;
        break;
    }
    return func_ov015_0218bcb0(obj);
}
