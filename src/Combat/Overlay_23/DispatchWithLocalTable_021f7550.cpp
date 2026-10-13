#include <globaldefs.h>

struct FileDispatchState {
    char unknown0[0x1c];
    int state;
};
typedef int (FileDispatchState::*FileStateHandler)(void*);
extern FileStateHandler data_020e6d5c;
struct FileStateHandlers { FileStateHandler handlers[4]; };
extern FileStateHandlers data_ov023_021fd8fc;

// USA: func_ov023_021f7550  (semantic: DispatchWithLocalTable_021f7550)
extern "C" ARM int func_ov023_021f7550(FileDispatchState* obj, void* param2) {
    FileStateHandlers table = data_ov023_021fd8fc;
    table.handlers[3] = data_020e6d5c;
    int result = (obj->*table.handlers[obj->state])(param2);
    obj->state = result;
    return result;
}
