#include <globaldefs.h>

struct ResourceDispatchState {
    char unknown0[0x1c];
    int state;
};
typedef int (ResourceDispatchState::*ResourceStateHandler)(void*);
extern ResourceStateHandler data_020e6d5c;
struct ResourceStateHandlers { ResourceStateHandler handlers[4]; };
extern ResourceStateHandlers data_ov023_021fd964;

// USA: func_ov023_021fb680  (semantic: DispatchWithLocalTable_021fb680)
extern "C" ARM int func_ov023_021fb680(ResourceDispatchState* obj, void* param2) {
    ResourceStateHandlers table = data_ov023_021fd964;
    table.handlers[3] = data_020e6d5c;
    int result = (obj->*table.handlers[obj->state])(param2);
    obj->state = result;
    return result;
}
