#include <globaldefs.h>

int CallFunc020e0434With021536ac_020e51e4(int value);
extern "C" void* func_020e462c(void*, int, void*, int);

struct StateStruct020e4750 {
    void* field0;
    int unk4;
    unsigned int pad0 : 12;
    unsigned int val : 6;
    unsigned int pad1 : 14;
};

// USA: func_020e4750
ARM void* UpdateObjectFromStateFlags(void* obj, struct StateStruct020e4750* state) {
    if (state->field0 != NULL) {
        int v = CallFunc020e0434With021536ac_020e51e4(state->val);
        obj = func_020e462c(obj, v, state->field0, 0);
    }
    return obj;
}
